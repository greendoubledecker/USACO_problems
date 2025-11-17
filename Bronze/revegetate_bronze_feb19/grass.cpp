#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int lowestOutside(unordered_set<int> vec){
	for(int num = 1; ; ++num){
		if(!vec.count(num)) return num;
	}
}

int main(){
	freopen("revegetate.out", "w", stdout);
	freopen("revegetate.in" , "r", stdin );
	int pastures, cows; cin >> pastures >> cows;
	vector<unordered_set<int>> adjacency(pastures);
	vector<int> values(pastures, -1);
	for(int i = 0; i < cows; ++i){
		int p1,p2; cin >> p1 >> p2;
		adjacency[p1 - 1].insert(p2 - 1);
		adjacency[p2 - 1].insert(p1 - 1);
	}
	for(int i = 0; i < pastures; ++i){
		unordered_set<int> neighbors;
		for(int j : adjacency[i]){
			neighbors.insert(values[j]);
		}
		int type = lowestOutside(neighbors);
		values[i] = type;
		cout << type;
	}
	return 0;
}
