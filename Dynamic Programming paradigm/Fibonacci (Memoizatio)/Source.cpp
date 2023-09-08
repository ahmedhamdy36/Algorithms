//-- Problem description --//
// 
// Given:      Integer number
// Required:   Get the Fibnacci for this number 
// Case:       F(5)
// Soloution:  8

#include<iostream>
#include <vector>
using namespace std;

vector<long long> memo;

long long fibonacci(int n) 
{
    if (n == 0 || n == 1) 
        return 1;

    if (memo[n] != -1)
        return memo[n];

    return (memo[n] = fibonacci(n - 1) + fibonacci(n - 2));
}

int main()
{
    int number = 10;
    memo.resize(number + 1, -1);
    cout << "The Fibnacci of " << number << " = " << fibonacci(number) <<endl;
}