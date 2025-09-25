#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int minCost(int val, int h, int c0, int c1){
	if(val == 0){
		return min(c0, h + c1);
	}else{
		return min(c1, h + c0);
	}
}

int buy(string str, int h, int c0, int c1){
	int cost0 = minCost(0, h, c0, c1);
	int cost1 = minCost(1, h, c0, c1);
	int cost = 0;
	for(char c : str){
		if(c == '0'){
			cost += cost0;
		}else{
			cost += cost1;
		}
	}
	return cost;
}

int tc(){
	int n, c0, c1, h;
	cin >> n >> c0 >> c1 >> h;
	string str = "";
	char bin;
	for(int i = 0; i < n; ++i){
		cin >> bin;
		str.push_back(bin);
	}
	return buy(str, h, c0, c1);
}

int main(){
	int tests;
	cin >> tests;
	vector<int> outs;
	for(int i = 0; i < tests; ++i){
		outs.push_back(tc());
	}
	for(int out : outs){
		cout << out << endl;
	}
}
