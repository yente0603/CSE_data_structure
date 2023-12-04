// Author: 李彥德 Lee Yen Te B096060041
// Date: 2023.09.08
// Purpose: Use C++ to implement a set class, which provides union, intersection, difference, containment and belonging, as basic operations.
#include <iostream>
#include <cstring>
#define MAX 256
using namespace std;

class set
{
private:
    bool test[MAX]; // array for check

public:
    set();              // constructor
    bool get(char idx); // in
    void create(string str);
    set operator+(const set &s);   // union
    set operator*(const set &s);   // intersection
    set operator-(const set &s);   // difference
    bool operator>=(const set &s); // contaim
    friend ostream &operator<<(ostream &, const set &);
    //~set();
};
set::set()
{
    for (int i = 0; i < MAX; i++)
        this->test[i] = false;
}
bool set::get(char idx)
{
    return test[idx];
}
void set::create(string str)
{
    for (int i = 0; i < MAX; i++) // set all elements are false
        test[i] = false;
    for (int i = 0; i < str.length(); i++) // set the element in test are true, for sorting
        test[str[i]] = true;
    return;
}
set set::operator+(const set &s)
{
    set buffer;
    for (int i = 0; i < MAX; i++)
        if (this->test[i] || s.test[i]) // to store the elements for union
            buffer.test[i] = true;
    return buffer;
}
set set::operator*(const set &s)
{
    set buffer;
    for (int i = 0; i < MAX; i++)
        if (this->test[i] && s.test[i]) // to store the elements for intersection
            buffer.test[i] = true;
    return buffer;
}
set set::operator-(const set &s)
{
    set buffer;
    for (int i = 0; i < MAX; i++)
        if (this->test[i] && !s.test[i]) // to store the elements for difference
            buffer.test[i] = true;
    return buffer;
}
bool set::operator>=(const set &s)
{
    for (int i = 0; i < MAX; i++)
        if (s.test[i] && !this->test[i]) // to store the elements for contain
            return false;
    return true;
}
ostream &operator<<(ostream &output, const set &s)
{
    for (int i = 0; i < MAX; i++)
        if (s.test[i])
            putchar(i);
    return output;
}
int main()
{
    int number, count = 1;
    cin >> number;
    while (number > 0)
    {
        set setA, setB, setC;
        string str;
        char c;
        cin.ignore();
        // cin >> str;
        getline(cin, str);
        setA.create(str);
        // cin >> str;
        getline(cin, str);
        setB.create(str);
        c = cin.get();
        cout << "Test Case " << count++ << ":\n";
        cout << "A: {" << setA << "}\n";
        cout << "B: {" << setB << "}\n";
        cout << "A+B: {" << setA + setB << "}\n";
        cout << "A*B: {" << setA * setB << "}\n";
        cout << "A-B: {" << setA - setB << "}\n";
        cout << "B-A: {" << setB - setA << "}\n";

        if (setA >= setB)
            cout << "A contains B" << endl;
        else
            cout << "A does not contain B" << endl;

        if (setB >= setA)
            cout << "B contains A" << endl;
        else
            cout << "B does not contain A" << endl;

        if (setA.get(c))
            cout << c << " is in A" << endl;
        else
            cout << c << " is not in A" << endl;

        if (setB.get(c))
            cout << c << " is in B" << endl;
        else
            cout << c << " is not in B" << endl;
        cout << endl;
        number--;
    }
    return 0;
}