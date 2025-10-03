#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

int main(){
	vector<string> names = {"Bessie", "Elsie", "Mildred"};
	int startMilk = 7;
	int entries;
	cin >> entries;
	vector<pair<int, int>> milks(100, {0, 0});
	for(int entry = 0; entry < entries; ++entry){
		int day;
		cin >> day;
		string cow;
		cin >> cow;
		int amt;
		cin >> amt;
		for(int i = 0; i < names.size(); ++i){
			if(cow == names[i]){
				milks[day] = {i, amt};
			}
		}
	}
	vector<int> milkOuts(names.size(), startMilk);
	vector<int> greatest;
	for(int i = 0; i < names.size(); ++i){
		greatest.push_back(i);
	}
	vector<int> prevGreatest;
	int switches = 0;
	for(int i = 0; i < 100; ++i){
		prevGreatest = greatest;
		greatest = {};
		pair<int, int> entry = milks[i];
		milkOuts[entry.first] += entry.second;
		int mostMilk = 0;
		for(int i = 0; i < milkOuts.size(); ++i){
			if(milkOuts[i] > mostMilk){
				mostMilk = milkOuts[i];
			}
		}
		for(int i = 0; i < milkOuts.size(); ++i){
			if(milkOuts[i] == mostMilk){
				greatest.push_back(i);
				cout << "greatest" << i << endl;
			}
		}
		if(greatest != prevGreatest){
			switches++;
			cout << "switches" << switches; 
		}
	}
	cout << switches;
	return 0;
}
