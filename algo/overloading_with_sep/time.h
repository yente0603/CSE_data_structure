#ifndef mytime
#define mytime
class Time
{
private:
    int hours, minutes;

public:
    Time();
    Time(int h, int m = 0);
    void addmin(int m);
    void addhr(int h);
    void reset(int h = 0, int m = 0);
    Time operator+(const Time &t) const;
    Time operator-(const Time &t) const;
    Time operator*(double n) const;
    void show() const;
    friend Time operator*(double m, const Time &t);
    friend std::ostream &operator<<(std::ostream &os, const Time &t);
};

#endif
