#include <iostream>
#include <unordered_map>
#include <utility>

using namespace std;

int main(){
	int num;
	cin >> num;
	unordered_map<int, int> paths;
	for(int i = 0; i < num - 1; ++i){
		int a, b;
		cin >> a >> b;
		paths[a] = b;
	}
	for(int i = 1; i < num + 1; ++i){
		if(paths[i] == 0){
			for(int j = 1; j < num + 1; ++j){
				int val = j;
				while(paths[val] != 0){
					val = paths[val];
				}
				if(val != i){
					cout << -1 << endl;
					return 0;
				}
			}
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
