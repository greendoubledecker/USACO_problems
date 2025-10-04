#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int tc(){
	int n, k;
	cin >> n >> k;
	vector<int> nums;
	for(int i = 0; i < n; ++i){
		int num;
		cin >> num;
		nums.push_back(num);
	}
	map<int, int> amts;
	for(int i = 0; i < nums.size(); ++i){
		amts[nums[i]]++;
	}
	vector<int> validVals;
	for (const auto& pair : amts)
	{
		if (pair.second >= k)
		{
			validVals.push_back(pair.first);
		}
	}
	sort(validVals.begin(), validVals.end());
	vector<vector<int>> splitArrays;
	vector<int> temp = {};
	for (int i = 0; i<validVals.size(); i++)
	{
		if (i==0)
		{
			temp.push_back(validVals[i]);
		}
		else
		{
			if (validVals[i] - 1 != validVals[i-1])
			{
				splitArrays.push_back(temp);
				temp = {};
			}
			temp.push_back(validVals[i]);
		}
	}
	if (temp.size() > 0)
	{
		splitArrays.push_back(temp);
	}
	int maxLength = 0;
	int left, right;
	for(vector<int> split : splitArrays){
		if(split.size() > maxLength){
			maxLength = split.size();
			left = split[0];
			right = split[split.size()-1];
		}
	}
	if(maxLength == 0){
		cout << -1 << endl;
	}else{
		cout << left << " " << right << endl;
	}
	return 0;
}

int main(){
	int tests;
	cin >> tests;
	for(int i = 0; i < tests; ++i){
		tc();
	}
	return 0;
}
