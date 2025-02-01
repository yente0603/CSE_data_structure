#include <iostream>
#include "template.h"

int main()
{
    int arr1[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    float arr2[] = {10.1f, 11.2f, 12.3f, 13.4f, 14.5f, 15.6f, 16.7f, 17.8f, 18.9f, 19.0f};

    std::cout << binary_search(arr1, 13, 0, 9) << std::endl;
    std::cout << binary_search(arr2, 17.8f, 0, 9) << std::endl;

    return 0;
}
