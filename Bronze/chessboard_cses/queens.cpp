#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> findAttacked(int x, int y){
	vector<vector<int>> attacked;
	for(int i = 0; i < 8; ++i){
		attacked.push_back(vector<int>{i, x+y-i});
		attacked.push_back(vector<int>{i, y-x+i});
	}
	return attacked;
}

int recurse(int level, vector<vector<int>> reserved, vector<int> usedRows){
	if(level == 8){
		return 1;
	}else{
		int sum = 0;
		for (int j = 0; j < 8; ++j){
			if (find(reserved.begin(), reserved.end(), vector<int>{level, j}) == reserved.end() && find(usedRows.begin(), usedRows.end(), j) == usedRows.end()){
				vector<vector<int>> newRes = findAttacked(level, j);
				vector<vector<int>> nextLayerRes;
				vector<int> nextRow = usedRows;
				nextRow.push_back(j);
				nextLayerRes.reserve(reserved.size() + newRes.size());
				nextLayerRes.insert(nextLayerRes.end(), newRes.begin(), newRes.end());
				nextLayerRes.insert(nextLayerRes.end(), reserved.begin(), reserved.end());
				sum += recurse(level + 1, nextLayerRes, nextRow);
			}
		}
		return sum;
	}
}

int main(){
	vector<vector<int>> reserved = {};
	string row;
	for(int i = 0; i < 8; ++i){
		cin >> row;
		for(int j = 0; j < 8; ++j){
			if (row[j] == '*') {
				reserved.push_back(vector<int>{i, j});
			}
		}
	}
	int possibilities = recurse(0, reserved, vector<int>{});
	cout << possibilities << endl;
}
