// Author: 李彥德 Lee Yen Te B096060041
// Date: 2023.11.21
// Purpose: To compare the efficiency of five different sorting algorithms.
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <algorithm>

using namespace std;

int *generateArraySize(int size) { return new int[size]; }

void getArrData(vector<pair<int*, int>> &arraySets) { 
    //push input.txt numbers into array
    ifstream file("input.txt", ifstream::in);
    int n;
    while (file >> n) {
        int *getArr = generateArraySize(n);
        for(int i = 0; i < n; i++)
            file >> getArr[i];
        arraySets.push_back(make_pair(getArr, n));
    }
    file.close();
}

void output(string algorithms, int *arr, int size, float timeset){
    // output the result
    chdir("output");
    ofstream outputFile(algorithms + "_" + to_string(size) + ".txt", ofstream::out);
    outputFile << algorithms << endl
               << "The total time is " << timeset << " seconds\n";
    for (auto i = 0; i < size; i++)
        outputFile << arr[i] << "\n";
    outputFile.close();
}

void insertionSort(int *arr, int n){
    int i, j;
    for (i = 1; i < n; i++)
    {
        int temp = arr[i];
        j = i - 1;
        while (arr[j] > temp && j >= 0 )
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge(int*, int, int, int);
void mergeSort(int *arr, int front, int tail){
    if (front < tail){
        int middle = (front + tail) / 2;
        mergeSort(arr, front, middle); // divide
        mergeSort(arr, middle+1, tail);
        merge(arr, front, tail, middle); // conquer
    }
}
void merge(int *arr, int front, int tail, int middle){
    int leftSize = middle - front + 1,
        rightSize = tail - middle;
    int *leftSub = new int[leftSize], *rightSub = new int[rightSize];

    memcpy(leftSub, arr + front, leftSize * sizeof(int));
    memcpy(rightSub, arr + middle + 1, rightSize * sizeof(int));

    int leftIndex = 0, rightIndex = 0, mergedIndex = front;
    while(leftIndex < leftSize && rightIndex < rightSize){
        if(leftSub[leftIndex] <= rightSub[rightIndex])
            arr[mergedIndex++] = leftSub[leftIndex++];
        else
            arr[mergedIndex++] = rightSub[rightIndex++];
    }
    while(leftIndex < leftSize) // remaining
        arr[mergedIndex++] = leftSub[leftIndex++];
    while(rightIndex < rightSize)
        arr[mergedIndex++] = rightSub[rightIndex++];

    delete [] leftSub;
    delete [] rightSub;
}




int partition(int*, int, int);
void quickSort(int *arr, const int front, const int tail){
    if (front<tail){
        int pivot = partition(arr, front, tail);
        quickSort(arr, front, pivot - 1);
        quickSort(arr, pivot + 1, tail);
    }
}
int partition(int *arr, int front, int tail){
    int pivot = arr[tail];
    int i = front - 1; // maybe all numbers are bigger than pivot
    for (auto j=front; j<tail; j++){ // triversal
        if(arr[j] < pivot)
            swap(arr[++i],arr[j]);
    }
    swap(arr[++i],arr[tail]); // swap pivot into middle of arr
    return i;
}

int compareqSort(const void *a, const void *b) { return (*(long int *)a - *(long int *)b); }

int main()
{
    vector<pair<int *, int>> arraySets;
    int mode=0;
    clock_t timeset;
    getArrData(arraySets);
    cout << "enter 1-5 to choose different sorting: ";

    cin >> mode;
    switch (mode){
        case 1:
            cout << "insertion sort" << endl;
            for (auto i : arraySets) {
                timeset = clock();
                insertionSort(i.first, i.second-1);
                timeset = clock() - timeset;
                output(string("insertion sort"), i.first, i.second,
                      ((float)timeset)/CLOCKS_PER_SEC);
                cout << "the total time is " << ((float)timeset)/CLOCKS_PER_SEC
                     << " seconds" <<endl;
            }
            break;

        case 2:
            cout << "merge sort" << endl;
            for (auto i : arraySets) {
                timeset = clock();
                mergeSort(i.first, 0, i.second-1);
                timeset = clock() - timeset;
                output(string("merge sort"), i.first, i.second,
                      ((float)timeset)/CLOCKS_PER_SEC);
                cout << "the total time is " << ((float)timeset)/CLOCKS_PER_SEC
                     << " seconds" <<endl;
            }
            break;

        case 3:
            cout << "quick sort" << endl;
            for (auto i : arraySets) {
                timeset = clock();
                quickSort(i.first,0 , i.second-1);
                timeset = clock() - timeset;
                output(string("quick sort"), i.first, i.second,
                      ((float)timeset)/CLOCKS_PER_SEC);
                cout << "the total time is " << ((float)timeset)/CLOCKS_PER_SEC
                     << " seconds" <<endl;
            }
            break;
        
        case 4:
            cout << "cstdlb sort" << endl;
            for (auto i : arraySets) {
                timeset = clock();
                qsort(i.first, i.second-1, sizeof(int), compareqSort);
                timeset = clock() - timeset;
                output(string("cstdlb sort"), i.first, i.second,
                      ((float)timeset)/CLOCKS_PER_SEC);
                cout << "the total time is " << ((float)timeset)/CLOCKS_PER_SEC
                     << " seconds" <<endl;
            }
            break;

        case 5:
            cout << "STL sort" << endl;
            for (auto i : arraySets) {
                timeset = clock();
                sort(i.first, i.first + i.second);
                timeset = clock() - timeset;
                output(string("STL sort"), i.first, i.second,
                      ((float)timeset)/CLOCKS_PER_SEC);
                cout << "the total time is " << ((float)timeset)/CLOCKS_PER_SEC
                     << " seconds" <<endl;
            }
            break;
        default:
            break;
    }

    return 0;
}