#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> findAttacked(int x, int y){
	vector<vector<int>> attacked;
	for(int i = 0; i < 8; ++i){
		//attacked.push_back(vector<int>{i, y});
		//attacked.push_back(vector<int>{x, i});
		attacked.push_back(vector<int>{i, x+y-i});
		attacked.push_back(vector<int>{i, y-x+i});
		//cout << attacked.size() << endl;
	}
	return attacked;
}

int recurse(int level, vector<vector<int>> reserved, vector<int> usedColumns){
	if(level == 8){
		return 1;
	}else{
		int sum = 0;
		//for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			if (find(reserved.begin(), reserved.end(), vector<int>{level, j}) == reserved.end() && find(usedColumns.begin(), usedColumns.end(), j) == usedColumns.end()){
				vector<vector<int>> newRes = findAttacked(level, j);
				vector<vector<int>> nextLayerRes;
				vector<int> nextCol = usedColumns;
				nextCol.push_back(j);
				nextLayerRes.reserve(reserved.size() + newRes.size());
				nextLayerRes.insert(nextLayerRes.end(), newRes.begin(), newRes.end());
				nextLayerRes.insert(nextLayerRes.end(), reserved.begin(), reserved.end());
				sum += recurse(level + 1, nextLayerRes, nextCol);
			}
		}
		//}
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
