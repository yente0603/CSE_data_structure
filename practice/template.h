#ifndef TEMPLATE_P
#define TEMPLATE_P
template <class T, class num>
T binary_search(T *arr, num x, const num left, const num right)
{
    if (left <= right)
    {
        num middle = (left + right) / 2;
        if (x < arr[middle])
            return binary_search(arr, x, left, middle - 1);
        else if (x > arr[middle])
            return binary_search(arr, x, middle + 1, right);
        else
            return x;
    }
    else
        return -1;
}
#endif