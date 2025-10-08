#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

int genome(vector<vector<char>> spotty, vector<vector<char>> plain){ //[base][cow]
	int determiners = 0;
	for(int base = 0; base < spotty.size(); ++base){
		vector<char> spottyGenes;
		for(int cow = 0; cow < spotty[0].size(); ++cow){
			if(find(spottyGenes.begin(), spottyGenes.end(), spotty[base][cow]) == spottyGenes.end()){
				spottyGenes.push_back(spotty[base][cow]);
			}
		}
		bool success = true;
		for(int cow = 0; cow < plain[0].size(); ++cow){
			if(find(spottyGenes.begin(), spottyGenes.end(), plain[base][cow]) != spottyGenes.end()){
				success = false;
				break;
			}
		}
		if(success){
			determiners++;
		}
	}
	return determiners;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<char>>spotty(m, vector<char>(n));
	vector<vector<char>> plain(m, vector<char>(n));
	for(int i = 0; i < n; ++i){
		//vector<char> cow;
		for(int j = 0; j < m; ++j){
			char base;
			cin >> base;
			spotty[j][i] = base;
		}
	}
	for(int i = 0; i < n; ++i){
		//vector<char> cow;
		for(int j = 0; j < m; ++j){
			char base;
			cin >> base;
			plain[j][i] = base;
		}
	}
	cout << genome(spotty, plain) << endl;
}
