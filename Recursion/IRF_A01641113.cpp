#include <iostream>
using namespace std;

// Author: Diego Partida Romero A01641113
// Date: 11/08/2022

// Iterative function
int sumIterative(int n)
{
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

// Recursive form
int recursiveSum(int i)
{
    if (i == 1)
        return 1;

    else if (i <= 0)
        return 0;

    return i + recursiveSum(i - 1);
}

// Direct function (works with a mathematical function)
int directSum(int i)
{
    if (i <= 0)
        return 0;
    return (i * (i + 1)) / 2;
}

int main()
{
    int n = 1;
    for (int i = 3; i < 10; i += 2)
    {

        cout << "- - - - - - - - - -" << endl;
        cout << "Case " << n << endl;
        cout << "Number to evaluate: " << i << endl
             << endl;
        cout << "Iterative Sum: " << sumIterative(i) << endl;
        cout << "recursiveSum: " << recursiveSum(i) << endl;
        cout << "Direct Sum: " << directSum(i) << endl;
        n++;
    }
    return 0;
}