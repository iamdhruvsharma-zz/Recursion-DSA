#include<iostream>
using namespace std;
void solve(int n, int s, int a, int d)
{
	if(n==1)
	{
		cout<<"Moving Disk No. "<<n<<" to "<<d<<" from "<<s<<endl;
	}
	else
	{
		solve(n-1, s, d, a);
		cout<<"Moving Disk No. "<<n<<" to "<<d<<" from "<<s<<endl;
		solve(n-1, a, s, d);
	}
}
		
int main()
{
	int n;
	cin>>n;
	int s = 1;
	int a = 2;
	int d = 3;
	solve(n, s, a, d);
}