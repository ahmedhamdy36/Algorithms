//-- Problem description --//
// 
// Given:      A length n and table of prices pi, for i = 1, 2, …, n.
// Required:   Find the maximum revenue obtainable for rods whose lengths sum to n,
//             computed as the sum of the prices for the individual rods. 
// Case:       lenght of Rod = 10,lengths[i]: {1,2,3,4,5,6,7,8,9,10}, prices[i]: {0,1,5,8,9,10,17,17,20,24,30}
// Soloution:  Best Revenue is: 30, Best Split is: 10 & 0

#include <iostream>
#include <vector>
using namespace std;

vector<int> rodCutting(int length, const vector<int>& prices)
{
    vector<int> r(length + 1, 0);
    vector<int> s(length + 1, 0);

    for (int i = 1; i <= length; i++) 
    {
        int maxRevenue = INT_MIN;
        for (int j = 1; j <= i; j++)
            if (prices[j] + r[i - j] > maxRevenue) 
            {
                maxRevenue = prices[j] + r[i - j];
                s[i] = j;
            }
        r[i] = maxRevenue;
    }

    vector<int> result(2);
    result[0] = r[length];
    result[1] = length;

    while (length > 0) 
    {
        int cutLength = s[length];
        result.push_back(cutLength);
        length -= cutLength;
    }

    return result;
}

int main() 
{
    int rodLength = 10;
    vector<int> prices = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
    vector<int> cuttingSolution = rodCutting(rodLength, prices);

    int bestRevenue = cuttingSolution[0];
    cout << "Best Revenue: " << bestRevenue << endl;

    cout << "Cutting Solution: ";
    for (int i = 2; i < cuttingSolution.size(); i++)
        cout << cuttingSolution[i] << " ";

    return 0;
}