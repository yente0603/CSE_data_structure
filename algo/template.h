#ifndef TEMPLATE_P
#define TEMPLATE_P

template <typename T>
T binary_search(const T *arr, T x, int left, int right)
{
    if (left <= right)
    {
        int middle = left + (right - left) / 2; // avoid overflow
        if (arr[middle] == x)
            return arr[middle];
        else if (x < arr[middle])
            return binary_search(arr, x, left, middle - 1);
        else
            return binary_search(arr, x, middle + 1, right);
    }
    return T(); // return type (e,g,. int is 0, float is 0.0)
}

#endif
