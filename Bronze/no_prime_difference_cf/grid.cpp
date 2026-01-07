#include <iostream>
#include <vector>

using namespace std;

void tc(){
	int r, c;
	cin >> r >> c;
	if(r == 4){
		for(int i = 0; i < r; ++i){
			for(int j = 0; j < c; ++j){
				cout << j * 4 + 1 + i << " ";
			}
			cout << endl;
		}
		return;
	}
	vector<int> beforeShift;
	for(int i = 0; i < r; ++i){
		beforeShift.push_back(i * c + 1);
	}
	vector<int> odd, even;
	for(int i = 0; i < r; ++i){
		if(i % 2 == 0){
			odd.push_back(beforeShift[i]);
		}else{
			even.push_back(beforeShift[i]);
		}
	}
	vector<int> rowStarters = odd;
	rowStarters.insert(rowStarters.end(), even.begin(), even.end());
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			cout << rowStarters[i] + j << " ";
		}
		cout << endl;
	}
}

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		tc();
	}
}
