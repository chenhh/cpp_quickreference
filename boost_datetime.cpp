#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>

int main() {
    boost::gregorian::date d(2010, 1, 30);
    std::cout << d.year() << std::endl;     //2010
    std::cout << d.month() << std::endl;    //Jan
    std::cout << d.day() << std::endl;      //30
    std::cout << d.day_of_week() << std::endl;  //Sat
    std::cout << d.end_of_month() << std::endl; //2010-Jan-31
    return 0;
} 