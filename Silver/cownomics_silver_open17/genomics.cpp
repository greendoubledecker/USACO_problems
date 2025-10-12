#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>

using namespace std;

int genome(vector<vector<int>> spotty, vector<vector<int>> plain){ //[cow][base] = base
	int determiners = 0;
	for(int b1 = 0; b1 < spotty[0].size(); ++b1){
		for(int b2 = b1+1; b2 < spotty[0].size(); ++b2){
			for(int b3 = b2+1; b3 < spotty[0].size(); ++b3){
				unordered_set<int> spottyGenes; 
				bool success = true;
				for(int spottyCow = 0; spottyCow < spotty.size(); ++spottyCow){
					int genes = (spotty[spottyCow][b1] << 4) + (spotty[spottyCow][b2] << 2) + spotty[spottyCow][b3];
					spottyGenes.insert(genes);
				}
				for(int plainCow = 0; plainCow < plain.size(); ++plainCow){
					int genes = (plain[plainCow][b1] << 4) + (plain[plainCow][b2] << 2) + plain[plainCow][b3];
					if(spottyGenes.count(genes)){
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

int convert(char letter){
	if(letter == 'A'){
		return 0;
	}
	else if(letter == 'T'){
		return 1;
	}
	else if(letter == 'C'){
		return 2;
	}
	else {
		return 3;
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> spotty(n, vector<int>(m));
	vector<vector<int>> plain(n, vector<int>(m));
	for(int i = 0; i < n; ++i){
		//vector<char> cow;
		for(int j = 0; j < m; ++j){
			char base;
			cin >> base;
			spotty[i][j] = convert(base);
		}
	}
	for(int i = 0; i < n; ++i){
		//vector<char> cow;
		for(int j = 0; j < m; ++j){
			char base;
			cin >> base;
			plain[i][j] = convert(base);
		}
	}
	cout << genome(spotty, plain) << endl;
}
