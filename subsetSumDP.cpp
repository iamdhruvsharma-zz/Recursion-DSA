#include<iostream>
using namespace std;


//return use karna bahot zaroori hai


	
int main()
{
	int arr[ ] = {2, 3, 7, 8};
	int n = sizeof(arr) / sizeof(int);
	int sum = 20;
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
	cout<<t[sum][n];
}