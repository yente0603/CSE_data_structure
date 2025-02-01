#include <iostream>
int foo(int m, int n)
{
    if (m == 0)
        return n + 1;
    if (n == 0)
        return foo(m - 1, 1);
    else
        return foo(m - 1, foo(m, n - 1));
}
int main()
{
    int m, n;
    std::cout << "please input (m, n) in Ackerman's function: ";
    std::cin >> m >> n;
    std::cout << foo(m, n) << std::endl;
    return 0;
}
