#include <iostream>
#include <vector>

using namespace std;

int maxmax = 10;

int beats(vector<int> d1, vector<int> d2){
	int c1 = 0, c2 = 0;
	for(int r1 : d1){
		for(int r2 : d2){
			if(r1 > r2){
				++c1;
			}
			if(r2 > r1){
				++c2;
			}
		}
	}
	//cout << "1 has " << c1 << " and 2 has " << c2 << "." << endl;
	if(c1 > c2) return 1;
	if(c2 > c1) return 0;
	return -1;
}

void tc(){
	vector<int> d1(4);
	vector<int> d2(4);
	for(int j = 0; j < 4; ++j){
		cin >> d1[j];
	}
	for(int j = 0; j < 4; ++j){
		cin >> d2[j];
	}
	int b12 = beats(d1, d2);
	if(b12 == -1){
		cout << "no" << endl;
		return;
	}
	for(int j = 1; j <= maxmax; ++j){
		for(int k = j; k <= maxmax; ++k){
			for(int l = k; l <= maxmax; ++l){
				for(int m = l; m <= maxmax; ++m){
					vector<int> d3 = {j, k, l, m};
					//cout << j << " " << k << " " << l << " " << m << endl;
					int b23 = beats(d2, d3);
					int b31 = beats(d3, d1);
					if(b23 == -1 || b31 == -1){
						continue;
					}
					//cout << b12 << " " << b23 << " " << b31 << endl;
					if(b12 == b23 && b23 == b31){
						cout << "yes" << endl;
						return;
					}
				}
			}
		}
	}
	cout << "no" << endl;
	return;
}

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		tc();
	}
	return 0;
}
