#include <iostream>
#include <vector>

using namespace std;

int main(){
	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);
	int n;
	cin >> n;
	int k;
	cin >> k;
	int b;
	cin >> b;
	vector<bool> works(n, true);
	for(int i = 0; i < b; ++i){
		int l;
		cin >> l;
		works[l - 1] = false;
	}
	vector<int> ps(1, 0);
	for(int i = 1; i <= n; ++i){
		ps.push_back(ps[i - 1]);
		if(works[i - 1]){
			++ps[i];
		}
	}
	int max = 0;
	for(int i = k; i <= n; ++i){
		int works = ps[i] - ps[i - k];
		if(works > max) max = works;
	}
	cout << k - max << endl;
	return 0;
}
