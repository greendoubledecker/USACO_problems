#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> manager;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int m;
		cin >> m;
		manager.push_back(m);
	}
	int max = 0;
	for(int i = 0; i < n; ++i){
		int curr = i;
		int num = 1;
		while(manager[curr] != -1){
			curr = manager[curr] - 1;
			num ++;
		}
		if(num > max){
			max = num;
		}
	}
	cout << max << endl;
	return 0;
}
