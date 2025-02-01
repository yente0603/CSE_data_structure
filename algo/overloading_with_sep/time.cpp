#include <iostream>
#include "time.h"
Time::Time()
{
    hours = minutes = 0;
}
Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}
void Time::addmin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}
void Time::addhr(int h)
{
    hours += h;
}
void Time::reset(int h, int m)
{
    hours = h;
    minutes = m;
}
Time Time::operator+(const Time &t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}
Time Time::operator-(const Time &t) const
{
    Time diff;
    int tol1, tol2;
    tol1 = t.minutes + 60 * t.hours;
    tol2 = minutes + 60 * hours;
    diff.minutes = (tol2 - tol1) % 60;
    diff.hours = (tol2 - tol1) / 60;
    return diff;
}
Time Time::operator*(double mult) const
{
    Time result;
    long totalminutes = hours * mult * 60 + minutes * mult;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}
void Time::show() const
{
    std::cout << hours << " hours, " << minutes << " minutes";
}

// non-member function to friend function
Time operator*(double m, const Time &t)
{
    Time result;
    long totalminutes = t.hours * m * 60 + t.minutes * m;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}
std::ostream &operator<<(std::ostream &os, const Time &t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}
