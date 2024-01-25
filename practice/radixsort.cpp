#include <iostream>
#include <vector>
using namespace std;
// A function to do counting sort of array[] according to the digit represented by exp.
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n); // Output array
    vector<int> count(10, 0); // Count array

    // Count occurrence in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Update count[] so that count[i] now contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[ (arr[i]/exp) %10 ] - 1] = arr[i];
        count[ (arr[i]/exp) %10 ]--;
    }

    // Copy the output array to arr[], so that arr[] contains sorted numbers
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort
void radixsort(vector<int>& arr) {
    // Find the maximum number to know the number of digits
    int max = *max_element(arr.begin(), arr.end());

    // Do counting sort for every digit
    for (int exp = 1; max/exp > 0; exp *= 10)
        countingSort(arr, exp);
}

void PrintArray(vector<int>& arr){
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    //vector<int> arr = {73, 22, 93, 43, 55, 14, 28, 65, 39, 81};
    vector<int> arr = {179, 208, 306, 93, 859, 984, 55, 9, 271, 33};
    std::cout << "original:\n";
    PrintArray(arr);

    radixsort(arr);

    std::cout << "sorted:\n";
    PrintArray(arr);

    
    return 0;
}