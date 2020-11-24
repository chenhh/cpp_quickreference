#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>
// https://www.boost.org/doc/libs/1_74_0/doc/html/date_time.html

void Gregorian_date() {
    // https://www.boost.org/doc/libs/1_74_0/doc/html/date_time/gregorian.html
    using namespace boost::gregorian;
    date d(2010, 1, 30);
    std::cout << d.year() << std::endl;     //2010
    std::cout << d.month() << std::endl;    //Jan
    std::cout << d.day() << std::endl;      //30
    std::cout << d.day_of_week() << std::endl;  //Sat
    std::cout << d.end_of_month() << std::endl; //2010-Jan-31
    std::cout << std::string(50, '*') << std::endl;

    date weekstart(2002, Feb, 1);
    date weekend = weekstart + weeks(1);
    std::cout << "weekend: " << weekend << std::endl;
    std::cout << std::string(50, '*') << std::endl;

    date d1(2020, 11, 1);
    date d2 = d1 + days(5);
    date today = day_clock::local_day();
    if (d2 >= today) {} //date comparison operators
    std::cout << "d2: " << d2 << std::endl;
    std::cout << "today: " << today << std::endl;
    std::cout << std::string(50, '*') << std::endl;


    date_period thisWeek(d1, d2);
    if (thisWeek.contains(today)) {}//do something

    //iterate and print the week
    day_iterator itr(weekstart);
    while (itr <= weekend) {
        std::cout << (*itr) << std::endl;
        ++itr;
    }
    //input streaming
    date d3(not_a_date_time);
    std::stringstream ss("2004-1-1");
    ss >> d3;
    std::cout << "from sstream: " << d3 << std::endl;
    std::cout << std::string(50, '*') << std::endl;


    //date generator functions
    date d4(2020, 1, 10);
//    date d5 = next_weekday(d4, Sunday); //calculate Sunday following d4

    //US labor day is first Monday in Sept
    typedef nth_day_of_the_week_in_month nth_dow;
    nth_dow labor_day(nth_dow::first, Monday, Sep);
    //calculate a specific date for 2004 from functor
    date d6 = labor_day.get_date(2004);
}

void date_as_strings() {
    https://www.boost.org/doc/libs/1_74_0/doc/html/date_time/examples.html#date_time.examples.dates_as_strings
    using namespace boost::gregorian;

    try {
        // The following date is in ISO 8601 extended format (CCYY-MM-DD)
        std::string s("2001-10-9"); //2001-October-09
        date d(from_simple_string(s));
        std::cout << to_simple_string(d) << std::endl;

        //Read ISO Standard(CCYYMMDD) and output ISO Extended
        std::string ud("20011009"); //2001-Oct-09
        date d1(from_undelimited_string(ud));
        std::cout << to_iso_extended_string(d1) << std::endl;

        //Output the parts of the date - Tuesday October 9, 2001
        date::ymd_type ymd = d1.year_month_day();
        greg_weekday wd = d1.day_of_week();
        std::cout << wd.as_long_string() << " "
                  << ymd.month.as_long_string() << " "
                  << ymd.day << ", " << ymd.year
                  << std::endl;

        //Let's send in month 25 by accident and create an exception
        std::string bad_date("20012509"); //2001-??-09
        std::cout << "An expected exception is next: " << std::endl;
        date wont_construct(from_undelimited_string(bad_date));
        //use wont_construct so compiler doesn't complain, but you wont get here!
        std::cout << "oh oh, you shouldn't reach this line: "
                  << to_iso_string(wont_construct) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "  Exception: " << e.what() << std::endl;
    }
}

void days_alive() {
    using namespace boost::gregorian;
    std::string s("1982-11-16");
    try {
        date birthday(from_simple_string(s));
        date today = day_clock::local_day();
        days days_alive = today - birthday;
        days one_day(1);
        if (days_alive == one_day) {
            std::cout << "Born yesterday, very funny" << std::endl;
        } else if (days_alive < days(0)) {
            std::cout << "Not born yet, hmm: " << days_alive.days()
                      << " days" << std::endl;
        } else {
            std::cout << "Days alive: " << days_alive.days() << std::endl;
        }

    }
    catch (...) {
        std::cout << "Bad date entered: " << s << std::endl;
    }
}

int main() {
    Gregorian_date();
    date_as_strings();
    days_alive();
    return 0;
} 