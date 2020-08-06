#include<iostream>
using namespace std;


//return use karna bahot zaroori hai

int subsetSum(int arr[ ], int sum, int n)
{
	if(n==0 || sum == 0)
	{
		if(sum == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if(sum - arr[n-1] < 0)
	{
		return subsetSum(arr, sum, n-1);
	}
	else
	{
		return subsetSum(arr, sum - arr[n-1], n-1);
		return subsetSum(arr, sum, n-1);
	}
}
	
int main()
{
	int arr[ ] = {2, 3, 7, 8};
	int n = sizeof(arr) / sizeof(int);
	int sum = 16;
	cout<<subsetSum(arr, sum, n);
}