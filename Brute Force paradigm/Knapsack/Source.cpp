//-- Problem description --//
//
// There are N different items in a store.
// Each item has only one instance.
// The item i weighs wi pounds and is worth $vi.
// A thief breaks in.
// He can carry up to W pounds in his knapsack.
// What should he take to maximize his benefit ?
// Case:     [(item1: 7 lbs, $42),
//            (item2: 3 lbs, $12),
//            (item3: 4 lbs, $40),
//            (item4: 5 lbs, $25),
//            (bag W = 10) ]
// Soloution: (item3 & item4 = $65)


#include<iostream>
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