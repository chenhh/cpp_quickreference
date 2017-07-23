#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <memory>

using namespace std;

class Observer {
public:
    virtual void update(string message) = 0;
    virtual string getName() = 0;
};

class Subject {
public:
    virtual void registerObserver(const shared_ptr<Observer> &) = 0;

    virtual void removeObserver(const shared_ptr<Observer> &) = 0;

    virtual void notifyObservers(string message) = 0;
};

class NewsOffice : public Subject {
private:
    list<shared_ptr<Observer>> m_observesList;
public:
    void registerObserver(const shared_ptr<Observer> &);

    void removeObserver(const shared_ptr<Observer> &);

    void notifyObservers(string message);
};

void NewsOffice::registerObserver(const shared_ptr<Observer> &observer) {
    m_observesList.push_back(observer);
}


void NewsOffice::removeObserver(const shared_ptr<Observer> &observer) {
    auto itr = find(m_observesList.begin(), m_observesList
                            .end(),
                    observer);
    if (itr != m_observesList.end()) {
        m_observesList.remove(*itr);
    }
}

void NewsOffice::notifyObservers(string message) {
    auto listBegin = m_observesList.begin();
    auto listEnd = m_observesList.end();
    while (listBegin != listEnd) {
        (*listBegin)->update(message);
        listBegin++;
    }
}


class Customer : public Observer {
private:
    string m_name;
public:
    Customer(string name) { m_name = name; }

    string getName(){return m_name;}
    void update(string message);
};


void Customer::update(string message) {
    cout << m_name << " update: " << message << endl;
}

int main() {
    NewsOffice office;
//    auto bill = make_shared<Customer>("Bill");
    shared_ptr<Customer> bill(new Customer("Bill"));
    shared_ptr<Customer> mike(new Customer("Mike"));

    office.registerObserver(bill);
    office.registerObserver(mike);
    office.notifyObservers("register");

    office.removeObserver(bill);
    office.notifyObservers("remove");

    return 0;
}