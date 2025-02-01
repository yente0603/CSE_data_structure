#include <iostream>
#include "time.cpp"
using namespace std;
int main()
{
    Time planning;
    Time coding(4, 35);
    Time fixing(2, 47);
    Time total;
    Time diff;
    Time adjusted;

    cout << "planning time= ";
    planning.show();
    cout << endl;

    cout << "coding time= ";
    coding.show();
    cout << endl;

    cout << "fixing time= ";
    fixing.show();
    cout << endl;

    //    total = coding.operator+(fixing); //由coding.sum呼叫 引數為fixing為第二個time物件
    total = coding + fixing; // 運算子左邊表呼叫物件，運算子右邊為引數 //operator+
    cout << "coding+fixing= ";
    total.show();
    cout << endl;

    diff = coding - fixing; // operator-
    cout << "coding-fixing= ";
    diff.show();
    cout << endl;

    Time morefixing(3, 28);
    cout << "more fixing time= ";
    morefixing.show();
    cout << endl;
    // as a member function use xxx.operator+, nom member funciton use operator+(xxx,yyy)
    total = morefixing.operator+(total);
    cout << "morefixing.operator+(total)= ";
    total.show();
    cout << endl;

    adjusted = total * 1.5; // adjusted = total.operator*(1.5); //operator*
    cout << "adjusted work time= ";
    adjusted.show();
    cout << endl;

    adjusted = 1.5 * total; // friend funtion
    cout << "adjusted work time use friend mode= ";
    adjusted.show();
    cout << endl;

    cout << "adjusted work time with overloading \'<<\'= " << adjusted;

    return 0;
}
