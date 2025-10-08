#include <iostream>//slow. very slow.
#include <vector>
#include <algorithm>

using namespace std;

int genome(vector<vector<char>> spotty, vector<vector<char>> plain){ //[base][cow]
	int determiners = 0;
	for(int b1 = 0; b1 < spotty.size(); ++b1){
		for(int b2 = b1+1; b2 < spotty.size(); ++b2){
			for(int b3 = b2+1; b3 < spotty.size(); ++b3){
				vector<int> bases = {b1, b2, b3};
				vector<vector<char>> spottyGenes; //[char][gene]
				bool success = true;
				for(int spottyCow = 0; spottyCow < spotty[0].size(); ++spottyCow){
					vector<char> genes = {spotty[b1][spottyCow], spotty[b2][spottyCow], spotty[b3][spottyCow]};
					spottyGenes.push_back(genes);
				}
				for(int plainCow = 0; plainCow <  plain[0].size(); ++plainCow){
					if(find(spottyGenes.begin(), spottyGenes.end(), vector<char>{plain[b1][plainCow], plain[b2][plainCow], plain[b3][plainCow]}) != spottyGenes.end()){
						success = false;
						break;
					}
				}
				if(success){
					determiners++;
				}
			}
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
