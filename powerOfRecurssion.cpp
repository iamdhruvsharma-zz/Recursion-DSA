#include<iostream>
#include<vector>
using namespace std;

void insert(vector <int> &test, int val)
{
	if(test.size() == 0 || val >= test[test.size()-1])
	{
		test.push_back(val);
		return;
	}
	else
	{
		int temp = test[test.size()-1];
		test.pop_back();
		insert(test, val);
		test.push_back(temp);
	}
}


void sortThis(vector <int> &test)
{
	if(test.size() <= 1)
	{
		return;
	}
	else
	{
		int temp = test[test.size() - 1];
		test.pop_back();
		sortThis(test);
		insert(test, temp);
	}
}

int main()
{
	vector<int> vec;
	for(int i=0; i<5; i++)
	{
		int x;
		cin>>x;
		vec.push_back(x);
	}
	cout<<endl;
	sortThis(vec);
	for(auto i = vec.begin(); i != vec.end(); i++)
	{
		cout<<*i<<" ";
	}
}