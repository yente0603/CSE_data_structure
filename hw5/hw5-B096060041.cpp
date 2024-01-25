// Author: 李彥德 Lee Yen Te B096060041
// Date: 2023.09.13
// Purpose: Implement the addition and multiplication of two polynomials
#include <iostream>
using namespace std;

/*implementation of linked list*/
class poly
{
private:
    int coef, exp;
    poly *link;

public:
    poly() : coef(0), exp(0), link(NULL){};
    poly(int x, int y) : coef(x), exp(y), link(NULL){};
    friend class polynomial;
};
class polynomial
{
private:
    poly *first;

public:
    polynomial() : first(0){};
    polynomial operator+(const polynomial &p);
    polynomial operator*(const polynomial &p);
    void push(int x, int y);
    void clear();
    void print();
};
void polynomial::push(int x, int y)
{
    poly *current = first;
    poly *previous = 0;
    bool check = true;
    if (first)
    {
        while (current)
        {
            if (current->exp == y) // if the same exp
            {
                current->coef += x;
                check = false;
                break;
            }
            else if (current->exp < y)
            {
                poly *newNode = new poly(x, y);
                if (previous == 0)
                {
                    newNode->link = current;
                    first = newNode;
                    check = false;
                    break;
                }
                else
                {
                    newNode->link = current;
                    previous->link = newNode;
                    check = false;
                    break;
                }
            }
            else
            {
                previous = current;
                current = current->link;
            }
        }
        if (check) // insert into the last
        {
            poly *newNode = new poly(x, y);
            current->link = newNode;
        }
    }
    else
    {
        poly *newNode = new poly(x, y);
        first = newNode;
    }
}
void polynomial::clear()
{
    if (first)
    {
        poly *current = first;
        first = first->link;
        delete current;
        current = 0;
    }
}
void polynomial::print()
{
    if (!first)
        cout << "0" << endl;
    else
    {
        poly *current = first;
        while (current)
        {
            cout << current->coef << "x^" << current->exp;
            current = current->link;
            if (current)
                cout << "+";
        }
        cout << endl;
    }
}
polynomial polynomial::operator+(const polynomial &p) // overploading of operator+
{
    poly *currentA = this->first;
    poly *currentB = p.first;
    if (currentA == NULL)
        return p;
    if (currentB == NULL)
        return *this;

    polynomial *c = new polynomial;
    *c = *this;
    while (currentB)
    {
        c->push(currentB->coef, currentB->exp);
        currentB = currentB->link;
    }
    poly *currentC = c->first;
    cout << "ADD" << endl;
    while (currentC)
    {
        cout << currentC->coef << " " << currentC->exp << endl;
        currentC = currentC->link;
    }
}
polynomial polynomial::operator*(const polynomial &p) // overloading of operator*
{
    // polynomial *d = new polynomial;
    // poly *currentA = this->first;
    // poly *currentB = p.first;
    // while (currentA)
    // {
    //     while (currentB)
    //     {
    //         d->push(currentA->coef * currentB->coef, currentA->exp * currentB->exp);
    //         currentB = currentB->link;
    //     }
    //     cout << "success!" << endl;
    //     currentB = p.first;
    //     currentA = currentA->link;
    // }
    polynomial *d = new polynomial;
    for (poly *currentA = this->first; currentA != nullptr; currentA = currentA->link)
    {
        for (poly *currentB = p.first; currentB != nullptr; currentB = currentB->link)
        {
            cout << "success1" << endl;
            d->push(currentA->coef * currentB->coef, currentA->exp * currentB->exp);
        }
        cout << "success2" << endl;
    }

    cout << "MULTIPLY" << endl;
    poly *currentD = d->first;
    while (currentD)
    {
        cout << currentD->coef << " " << currentD->exp << endl;
        currentD = currentD->link;
    }
}
void output(polynomial a, polynomial b)
{
    a.print();
    b.print();
    polynomial c, d;
    c = a + b;
    d = a * b;
    a.clear();
    b.clear();
}
int main()
{
    polynomial a, b;   // declearation
    int p, q;          // how many elements in polynomial
    int x, y;          // coefficient and exponent
    bool check = true; // check whether it is the teriminal or not
    while (check)
    {
        cin >> p;
        for (int i = 0; i < p; i++)
        {
            cin >> x >> y;
            a.push(x, y);
        }
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            cin >> x >> y;
            b.push(x, y);
        }
        if (p == 0 && q == 0) // break
            break;

        if (p == 0)
            a.push(0, 0); // 0 polynomial
        else if (q == 0)
            b.push(0, 0); // 0 polynomial
        output(a, b);
    }
}