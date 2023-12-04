#include <iostream>
#include "template.h"
int main()
{
    int arr1[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    float arr2[10] = {10.1, 11.2, 12.3, 13.4, 14.5, 15.6, 16.7, 17.8, 18.9, 19.0};
    std::cout << binary_search(arr1, 13, 0, 9) << std::endl;
    std::cout << binary_search(arr2, 17.8, 0, 9) << std::endl;
    return 0;
}