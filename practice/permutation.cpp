#include <iostream>
using namespace std;
void permutation(char *arr, const int k, const int m)
{
    if (k == m)
    {
        for (int i = 0; i <= m; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    else
    {
        for (int i = k; i <= m; i++)
        {
            char temp;
            temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp; // exchange
            permutation(arr, k + 1, m);
            temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp; // return
        }
    }
}
int main()
{
    char arr[] = {'a', 'b', 'c', 'd'};
    permutation(arr, 0, 3);
    return 0;
}
