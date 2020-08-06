#include<iostream>
using namespace std;
int subsetSum(int arr[ ], int sum, int n)
{
	
	int t[sum+1][n+1];
	// i->sum & j->n
	for(int i=0; i<sum+1; i++)
	{
		for(int j=0; j<n+1; j++)
		{
			if(j==0) //n = 0
			{
				t[i][j] = 0;
			}
			if(i==0) //sum = 0
			{
				t[i][j] = 1;
			}
		}
	}
	for(int i=1; i<sum+1; i++)
	{
		for(int j=1; j<n+1; j++)
		{
			if(i - arr[j-1] < 0)
			{
				t[i][j] = t[i][j-1];
			}
			else
			{
				t[i][j] = (t[i - arr[j-1]][j-1] || t[i][j-1]);
			}
		}
	}
	return t[sum][n];
}

int main()
{
	int arr[ ] = {1, 2, 5};
	int n = sizeof(arr) / sizeof(int);
	int sum = 0;
	for(int i = 0; i<n; i++)
	{
		sum+= arr[i];
	}
	if(sum%2 != 0)
	{
		cout<<0;
	}
	else
	{
		cout<<subsetSum(arr, sum/2, n);
	}
}