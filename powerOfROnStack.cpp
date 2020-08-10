#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void insert(stack <int> &test, int val)
{
	if(test.size() == 0 || val >= test.top())
	{
		test.push(val);
		return;
	}
	else
	{
		int temp = test.top();
		test.pop();
		insert(test, val);
		test.push(temp);
	}
}

void sortThis(stack <int> &test)
{
	if(test.size() <= 1)
	{
		return;
	}
	else
	{
		int temp = test.top();
		test.pop();
		sortThis(test);
		insert(test, temp);
	}
}

int main()
{
	stack<int> sta;
	for(int i=0; i<5; i++)
	{
		int x;
		cin>>x;
		sta.push(x);
	}
	cout<<endl;
	sortThis(sta);
	while(!sta.empty())
	{
		cout<<sta.top()<<" ";
		sta.pop();
	}
}