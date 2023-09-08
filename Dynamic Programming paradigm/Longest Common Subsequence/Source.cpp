//-- Problem description --//
// 
// Given:      Two sequences x[1 . . m] and y[1 . . n]
// Required:   Find a longest subsequence that’s common to both of them.
// Case:       X = "ABCB" and Y = "BDCAB";
// Soloution:  BCB

#include<iostream>
#include <vector>
using namespace std;

int getMax(int x, int y)
{
    if (x >= y)
        return x;
    return y;
}

string LCS(const string& X, const string& Y) 
{
    int m = X.length();
    int n = Y.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) 
        {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = getMax(dp[i - 1][j], dp[i][j - 1]);
        }

    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) 
    {
        if (X[i - 1] == Y[j - 1]) 
        {
            lcs = X[i - 1] + lcs;
            i--;
            j--;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1])
            i--;
        else
            j--;
    }

    return lcs;
}

int main() 
{
    string X = "ABCB", Y = "BDCAB";
    cout << "Longest Common Subsequence: " << LCS(X, Y) << endl;
    return 0;
}