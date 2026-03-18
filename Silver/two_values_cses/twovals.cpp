#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
	int n, tgt;
	cin >> n >> tgt;
	unordered_map<int, vector<int>> vec;
	for(int i = 0; i < n; ++i){
		int e;
		cin >> e;
		if(e < tgt){
			vec[e].push_back(i);
		}
	}
	for(const auto& pair : vec){
		int remaining = tgt - pair.first;
		if(pair.second == vector<int>{}){
			continue;
		}
		if(vec[remaining] != vector<int>{}){
			if(pair.first == remaining){
				if(pair.second.size() > 1){
					cout << pair.second[0] + 1 << " " << pair.second[1] + 1 << endl;
					return 0;
				}
			}else{
				cout << pair.second[0] + 1 << " " << vec[remaining][0] + 1 << endl;
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}
