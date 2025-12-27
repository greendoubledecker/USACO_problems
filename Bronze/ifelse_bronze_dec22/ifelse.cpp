#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int decides(int ind, vector<vector<bool>> ins, vector<bool> outs){ // return 0 if doesn't decide the answer, 1 if it being 0 decides, 2 if it being 1 decides, 3 if it decides all the time
	//cout << "decides-ind: " << ind << endl;
	int map0 = -1, map1 = -1;
	bool dec0 = false, dec1 = false;
	for(int i = 0; i < ins.size(); ++i){
		if(ins[i][ind] == 0) dec0 = true;
		if(ins[i][ind] == 1) dec1 = true;
	}
	//cout << "dec0: " << dec0 << ", dec1: " << dec1 << endl;
	for(int i = 0; i < ins.size(); ++i){
		//cout << "i: " << i << endl;
		if(ins[i][ind] == 0){
			//cout << map0 << " map0" << endl;
			if(outs[i]){
				if(map0 == 0) {
					dec0 = false; 
					//cout << "1" << endl;
				}else {
					map0 = 1;
				}
			}else{
				if(map0 == 1) {
					dec0 = false; 
					//cout << "2";
				}else {
					map0 = 0; 
					//cout << "3";
				}
			}
		}else{
			if(outs[i]){
				if(map1 == 0) dec1 = false;
				else map1 = 1;
			}else{
				if(map1 == 1) dec1 = false;
				else map1 = 0;
			}
		}
		if(!dec0 && !dec1) return 0;
	}
	if(dec0 &&!dec1) return 1;
	if(!dec0&& dec1) return 2;
	if(dec0 && dec1) return 3;
	return 0;
}

pair<bool, vector<int>> round(vector<vector<bool>> ins, vector<bool> outs){ //lying, still-included rows of ins
	bool lying = true;
	vector<int> rows;
	for(int i = 0; i < ins.size(); ++i){
		rows.push_back(i);
	}
	for(int i = 0; i < ins[0].size(); ++i){
		//cout << "ins[0][" << i << "]" << endl;
		vector<vector<bool>> newIns;
		for(int j : rows){
			newIns.push_back(ins[j]);
		}
		vector<bool> newOuts;
		for(int j : rows){
			newOuts.push_back(outs[j]);
		}
		int ans = decides(i, newIns, newOuts);
		//cout << "ans: " << ans << endl;
		if(ans == 0) return {true, {}};
		if(ans != 0) lying = false;
		vector<int> newRows;
		if(ans == 1){
			for(int j : rows){
				if(ins[j][i] != 0){
					newRows.push_back(j);
				}
			}
		}
		if(ans == 2){
			for(int j : rows){
				if(ins[j][i] != 1){
					newRows.push_back(j);
				}
			}
		}
		rows = newRows;
		if(rows.empty()) break;
		/*
		cout << "rows" << endl;
		for(int j : rows){
			cout << j << " ";
		}
		cout << endl;
		*/
	}
	//cout << "just before return" << endl;
	return {lying, rows};
}

void tc(){
	int vars, tests;
	cin >> vars >> tests;
	vector<vector<bool>> ins(tests, vector<bool>(vars));
	vector<bool> outs(tests);
	for(int i = 0; i < tests; ++i){
		for(int j = 0; j < vars; ++j){
			char c;
			cin >> c;
			ins[i][j] = c - '0';
		}
		char o;
		cin >> o;
		outs[i] = o - '0';
	}
	
	auto ans = round(ins, outs);
	/*
	cout << ans.first << endl;
	for(int i : ans.second){
		cout << i << endl;
	}
	*/
	//cout << "befroe" << endl;
	while(true){
		//cout << "inside" << endl;
		vector<vector<bool>> newIns;
		vector<bool> newOuts;
		for(int i : ans.second){
			//cout << "i is " << i << endl;
			newIns.push_back(ins[i]);
			newOuts.push_back(outs[i]);
		}
		ins = newIns;
		outs = newOuts;
		if(ans.second.empty()){
			if(ans.first){
				cout << "LIE" << endl;
				return;
			}else{
				cout << "OK" << endl;
				return;
			}
		}
		/*
		else {
			cout << "shouldnt come here" << endl;
		}
		*/
		ans = round(ins, outs);
	}
}

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		tc();
	}
	return 0;
}
