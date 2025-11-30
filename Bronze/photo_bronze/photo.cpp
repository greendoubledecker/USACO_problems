#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> photos(5);

bool cmp(int c1, int c2){
	int count = 0;
	for(vector<int> p : photos){
		if(p[c1 - 1] < p[c2 - 1]) ++count;
		if(count > 2){
			return true;
		}
	}
	return false;
}

int main(){
	int cows; cin >> cows;
	vector<int> ids(cows);
	for(int i = 0; i < 5; ++i){
		vector<int> pos(cows);
		for(int j = 0; j < cows; ++j){
			int c;
			cin >> c;
			pos[c - 1] = j;
			ids[j] = c;
		}
		photos[i] = pos;
	}
	sort(ids.begin(), ids.end(), cmp);
	for(int c : ids){
		cout << c << endl;
	}
	return 0;
}
