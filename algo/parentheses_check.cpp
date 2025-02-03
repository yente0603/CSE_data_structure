#include <iostream>
#include <cstring>
int main(int argc, char **argv)
{
    std::string x = argv[1];
    // std::string x = "((A+B)))((";
    int count = 0;
    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] == '(')
            std::cout << ++count << " ";
        else if (x[i] == ')')
            std::cout << --count << " ";
    }
    if (count < 0)
        std::cout << "Invalid string! missing \'(\'" << std::endl;
    else if (count > 0)
        std::cout << "Invalid string! missing \')\'" << std::endl;
    else
        std::cout << "Valid string!" << std::endl;
    return 0;
}