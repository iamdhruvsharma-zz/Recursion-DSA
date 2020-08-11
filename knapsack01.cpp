#include<iostream>
#include<vector>
using namespace std;

//Very Very Important
/* Jab bhi aap koi cheez & (reference) ke sath bhejte ho tabh uss cheez mei globally change aata hai, and iss problem mei w, val ko (&) ke sath nahi bhejna warna saare case purre nahi ho paayenge */


void solveKnap(vector<int> w, vector<int> val, int cap, int currentSize, int currentProfit, vector<int> &sol)
{
	if(w.size() == 0 || cap == 0)
	{
		sol.push_back(currentProfit);
	}
	else if(currentSize+w[0] > cap)
	{
		w.erase(w.begin()+0);
		val.erase(val.begin()+0);
		solveKnap(w, val, cap, currentSize, currentProfit, sol);
	}
	else
	{
		int nP = val[0];
		int nW = w[0];
		w.erase(w.begin()+0);
		val.erase(val.begin()+0);
		solveKnap(w, val, cap, currentSize+nW, currentProfit+nP, sol);
		solveKnap(w, val, cap, currentSize, currentProfit, sol);
	}
}


int main()
{
	vector<int> w = {10, 20, 30};
	vector<int> val = {60, 100, 120};
	int cap = 50;
	int currentSize = 0;
	int currentProfit = 0;
	vector<int> sol;
	solveKnap(w, val, cap, currentSize, currentProfit, sol);
	cout<<*max_element(sol.begin(), sol.end());
}