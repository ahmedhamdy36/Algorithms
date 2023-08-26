#include<iostream>
#include<vector>
using namespace std;

int SelectItems(int w, int* sizes, int* profit, int n)
{
	if (n == 0 || w == 0)
		return 0;

	if (sizes[n - 1] > w)
		return SelectItems(w, profit, sizes, n - 1);
	else
		return max(profit[n - 1] + SelectItems(w - profit[n - 1], sizes, profit, n - 1),
			SelectItems(w, profit, sizes, n - 1));
};

int main()
{
	int* sizes;
	int* profit;
	int arrsize;
	int bagW;

	cout << "Number of items: ";
	cin >> arrsize;
	sizes = new int[arrsize];
	profit = new int[arrsize];
	
	int val;
	cout << "weight of items: " << endl;
	for (int i = 0; i < arrsize; i++)
	{
		cin >> val;
		sizes[i] = val;
	}

	cout << "profit of items: " << endl;
	for (int i = 0; i < arrsize; i++)
	{
		cin >> val;
		profit[i] = val;
	}

	cout << "weight of bag: ";
	cin >> bagW;

	cout << "please wait.. . " << endl << endl;

	cout << SelectItems(bagW, sizes, profit, arrsize) << endl;

}