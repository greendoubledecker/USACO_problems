#include <iostream>
#include <utility>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>// yes, i really needed that many includes

using namespace std;

pair<int, int> intersect(pair<int, int> range1, pair<int, int> range2){
	return {max(range1.first, range2.first), min(range1.second, range2.second)};
}

pair<int, int> calcNext(int type, pair<int, int> range1, pair<int, int> range2){
	if(type == 0){ //none
		return intersect(range1, range2);
	}
	if(type == 1){ //on for working down, off for working up
		return {range1.first + range2.first, range1.second + range2.second};
	}
	if(type == 2){ //off for working down, on for working up
		return {max(range1.first - range2.second, 0), range1.second - range2.first};
	}
}

pair<int, int> workUp(vector<int> types, vector<pair<int, int>> ranges){
	//cout << "working up" << endl;
	pair<int, int> range = {0, 1000000};
	for(int i = types.size() - 1; i >= 0; --i){
		if(types[i] == 0){
			range = calcNext(0, range, ranges[i]);
		}
		if(types[i] == 1){
			range = calcNext(2, range, ranges[i]);
		}
		if(types[i] == 2){
			range = calcNext(1, range, ranges[i]);
		}
		//cout << "range " << range.first << ", " << range.second << endl;
	}
	return range;
}

pair<int, int> workDown(vector<int> types, vector<pair<int, int>> ranges){
	//cout << "working down" << endl;
	pair<int, int> range = {0, 1000000};
	for(int i = 0; i < types.size(); ++i){
		range = calcNext(types[i], range, ranges[i]);
		//cout << "range " << range.first << ", " << range.second << endl;
	}
	return range;
}

int main(){
	int n;
	vector<int> types;
	vector<pair<int, int>> ranges;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string type;
		cin >> type;
		int lower, higher;
		cin >> lower >> higher;
		if(type == "none"){
			types.push_back(0);
		}
		if(type == "on"){
			types.push_back(1);
		}
		if(type == "off"){
			types.push_back(2);
		}
		ranges.push_back({lower, higher});
	}
	pair<int, int> start, end;
	start = workUp(types, ranges);
	end = workDown(types, ranges);
	cout << start.first << " " << start.second << endl << end.first << " " << end.second << endl; 
}
