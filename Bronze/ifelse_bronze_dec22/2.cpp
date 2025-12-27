#include <iostream>
#include <vector>

using namespace std;

bool works(vector<vector<bool>> ins, vector<bool> outs){
	vector<bool> valid(ins.size(), false);
	int validNum = 0;
	int prevNum = -1;
	while(validNum != prevNum){
		prevNum = validNum;
		for(int col = 0; col < ins[0].size(); ++col){
			vector<int> ones, zeroes;
			int onesResult = -1;
			int zeroesResult = -1;
			bool onesValid = true, zeroesValid = true;
			for(int row = 0; row < ins.size() && (onesValid || zeroesValid); ++row){
				if(valid[row]) continue;
				if(onesValid && ins[row][col]){
					ones.push_back(row);
					if(onesResult == -1) onesResult = outs[row];
					onesValid = onesResult == outs[row];
					//cout << "onesValid:" << onesValid << endl;
				}
				if(zeroesValid && !ins[row][col]){
					zeroes.push_back(row);
					if(zeroesResult == -1) zeroesResult = outs[row];
					zeroesValid = zeroesResult == outs[row];
					//cout << "zeroesValid:" << zeroesValid << endl;
				}
			}
			if(onesValid){
				for(auto row : ones){
					valid[row] = true;
					//validNum += ones.size();
				}
				validNum += ones.size();
			}
			if(zeroesValid){
				for(auto row : zeroes){
					valid[row] = true;
					//validNum += zeroes.size();
				}
				validNum += zeroes.size();
			}
			//cout << validNum << " are valid out of " << ins.size() << " rows." << endl;
			if(validNum == ins.size()) return true;
		}
	}
	return false;
}

int main(){
	int tc;
	cin >> tc;
	for(int test = 0; test < tc; ++test){
		int n, m;
		cin >> n >> m;
		vector<vector<bool>> ins(m, vector<bool>(n));
		vector<bool> outs(m);
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < n; ++j){
				char c;
				cin >> c;
				if(c == '1') ins[i][j] = true;
				if(c == '0') ins[i][j] = false;
			}
			int c;
			cin >> c;
			outs[i] = c;
		}
		bool truth = works(ins, outs);
		if(truth) cout << "OK" << endl;
		else cout << "LIE" << endl;
	}
}
