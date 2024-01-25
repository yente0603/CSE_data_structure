// Author: 李彥德 Lee Yen Te B096060041
// Date: 2023.09.08
// Purpose: Test if a knight can visit each positon of a chess board
#include <iostream>
// #include <stack>
#include <vector>
using namespace std;

class node
{
public:
    int i, j, k;
    node(int i, int j, int k) // i-axis, y-axis, direction
    {
        this->i = i;
        this->j = j;
        this->k = k;
    }
};

class Stack // implementation of stack
{
public:
    Stack()
    {
        this->_stack.clear();
    }
    void push(const node &_newnode)
    {
        this->_stack.push_back(_newnode);
    }
    void pop()
    {
        this->_stack.pop_back();
    }
    bool empty()
    {
        return (this->_stack.size() == 0);
    }
    int size()
    {
        return this->_stack.size();
    }
    const node top()
    {
        return this->_stack.back();
    }

private:
    vector<node> _stack;
};

Stack stk; // to record the stk of the knight

int dir[8][2] = {
    {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}}; // 8 direction

bool check(int i, int j, int n)
{
    if (i < 0 || i >= n)
        return false;
    if (j < 0 || j >= n)
        return false;
    return true;
}
void knight(int n)
{

    int step = 0;
    int isback = 0;
    int grid[n][n];
    /*initialization*/
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            grid[i][j] = 0;

    stk.push(node(0, 0, 0)); // start
    grid[0][0] = ++step;     // the first grid have been pathed

    while (step < n * n)
    {
        if (stk.empty())
        {
            cout << "n = " << n << endl
                 << "no solution!" << endl
                 << endl;
            return;
        }
        node top = stk.top(); // last step
        bool nextpath = false;
        for (int k = top.k + isback; k < 8; k++)
        {
            // search for path
            int nexti = dir[k][0] + top.i;
            int nextj = dir[k][1] + top.j;
            if (check(nexti, nextj, n) && grid[nexti][nextj] == 0)
            {
                nextpath = true;
                // update the old top
                top.k = k;
                stk.pop();
                stk.push(top);
                // insert new node
                grid[nexti][nextj] = ++step;
                stk.push(node(nexti, nextj, 0));
                isback = 0;
                break;
            }
        }
        if (nextpath == false) // backtracing method
        {
            isback = 1;
            stk.pop();
            grid[top.i][top.j] = 0;
            step--;
        }
    }

    // outcome
    cout << "n = " << n << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3u", grid[i][j]);
        }
        cout << endl;
    }
    cout << endl;
    return;
}

int main()
{
    // size of matrix
    for (int i = 1; i < 7; i++)
        knight(i);
    return 0;
}