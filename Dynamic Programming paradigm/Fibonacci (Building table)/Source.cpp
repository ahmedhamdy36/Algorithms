//-- Problem description --//
// 
// Given:      Integer number
// Required:   Get the Fibnacci for this number 
// Case:       F(5)
// Soloution:  8

#include<iostream>
#include <vector>
using namespace std;

vector<long long> table;

long long fibonacci(int n) 
{
    table.resize(n + 1);
    table[0] = 1;
    table[1] = 1;

    for (int i = 2; i <= n; i++)
        table[i] = table[i - 1] + table[i - 2];

    return table[n];
}

int main() 
{
    int number = 8;
    cout << "The Fibnacci of " << number << " = " << fibonacci(number) << endl;
    return 0;
}