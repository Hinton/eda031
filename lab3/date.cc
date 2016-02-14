#include <ctime>  // time and localtime
#include "date.h"

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
    time_t timer = time(0); // time in seconds since 1970-01-01
    tm *locTime = localtime(&timer); // broken-down time
    year = 1900 + locTime->tm_year;
    month = 1 + locTime->tm_mon;
    day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
}

int Date::getYear() const {
    return year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

void Date::next() {
    day++;
    if (day > daysPerMonth[month]) {
        day = 1;
        month++;
    }
    if (month > 12) {
        month = 1;
        year++;
    }
}

std::ostream& operator<<(std::ostream& os, const Date& d)
{
    os << d.year << '-' << d.month << '-' << d.day;
    // write obj to stream
    return os;
}
std::istream& operator>>(std::istream& is, Date& d)
{
    int day, month, year;
    char ch1, ch2;
    if (is >> year >> ch1 >> month >> ch2 >> day)
    {
        if (ch1 == '-' && ch2 == '-') {
            d.year = year;
            d.month = month;
            d.day = day;
        } else {
            is.setstate(std::ios::failbit);
        }
    }
    return is;
}