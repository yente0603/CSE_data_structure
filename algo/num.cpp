#include <iostream>
int main()
{
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    std::cout << "The number in binary is: ";
    for (int i = 15; i >= 0; i--)
    {
        std::cout << ((num >> i) & 1); // Bitwise AND with 1 to get the last bit
        if (i % 4 == 0)
            std::cout << " ";
    }
    std::cout << std::endl;

    std::cout << "The number in hexadecimal is: ";
    std::cout << std::hex << num << std::endl;

    std::cout << "The number in ASCII is: ";
    std::cout << "\'" << (char)num << "\'" << std::endl;

    std::cout << "The number in BCD is: ";

    std::cout << std::endl;

    return 0;
}