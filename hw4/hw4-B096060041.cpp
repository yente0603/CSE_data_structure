// Author: 李彥德 Lee Yen Te B096060041
// Date: 2023.09.13
// Purpose: Test if a knight can visit each positon of a chess board by recursive
// compiler standard: g++11
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int, int>> dir = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

/*initialization*/
int **makeMap(int n)
{
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[n]();
    return arr;
}

/*clean the map*/
void deleteMap(int **arr, int size)
{
    for (int i = 0; i < size; i++)
        delete[] arr[i];
}

/*print the outcome of knight path*/
void printMap(int **arr, int size)
{
    for (int j = 0; j < size; j++)
    {
        for (int k = 0; k < size; k++)
            cout << arr[j][k] << " ";
        cout << endl;
    }
}

bool canAccess(int **arr, int size, pair<int, int> coordinate)
{
    return !(coordinate.first >= size || coordinate.first < 0 ||
             coordinate.second >= size || coordinate.second < 0 ||
             arr[coordinate.first][coordinate.second]);
}

bool traversal(int **arr, int size, pair<int, int> current, int steps)
{
    arr[current.first][current.second] = steps;
    if (steps == size * size)
        return true;

    for (auto idx : dir)
    {
        auto next = make_pair(current.first + idx.first, current.second + idx.second);
        if (canAccess(arr, size, next))
        {
            auto isDone = traversal(arr, size, next, ++steps);
            if (isDone == false)
                --steps;
            else
                return isDone;
        }
    }
    arr[current.first][current.second] = 0;
    return false;
}

int main()
{
    for (auto i : {1, 2, 3, 4, 5, 6})
    {
        // the 9 is impossible, because the complacity is O(8^(n^2)).
        auto arr = makeMap(i);
        auto current = make_pair(0, 0);

        auto isDone = traversal(arr, i, current, 1); // recursive method of knight
        if (isDone)
            printMap(arr, i);
        else
            cout << "no solution" << endl;
        cout << endl;
        deleteMap(arr, i);
    }
    return 0;
}