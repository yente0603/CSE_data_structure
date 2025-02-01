#include <iostream>
int fib(int n, int *count)
{
    (*count)++;
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;
    else
        return fib(n - 1, count) + fib(n - 2, count);
}
int main()
{
    int n, count = 0;
    std::cout << "Please input a number for fibonacci number: ";
    std::cin >> n;
    std::cout << "the number of Fin(n) is " << fib(n, &count) << " and it calls " << count << " times." << std::endl;
}