#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> a(N);
	vector<int> has(N + 1);
	for(int i = 0; i < N; ++i){
		cin >> a[i];
		++has[a[i]];
	}
	sort(a.begin(), a.end());
	vector<int> gaps(1, 0);
	for(int i = 0; i < N; ++i){
		if(!has[i]){
			gaps.push_back(gaps[i] + 1);
		}else{
			gaps.push_back(gaps[i]);
		}
	}
	for(int i = 0; i <= N; ++i){
		int unwanted = has[i];
		cout << max(gaps[i], unwanted) << endl;
	}
	return 0;
}
