#include <iostream>
#include <vector>

using namespace std;

vector<long long> getAns(long long a, vector<long long> sums){
	vector<long long> ans(1, a);
	for(long long s : sums){
		ans.push_back(s - ans[ans.size() - 1]);
	}
	return ans;
}

long long findA(long long sumAB, long long sumBC, long long sumCA){
	return (sumAB - sumBC + sumCA) / 2;
}

int main(){
	long long n;
	cin >> n;
	long long sumCA;
	cout << "? 3 1" << endl;
	cin >> sumCA;
	vector<long long> sums;
	for(long long i = 0; i < n - 1; ++i){
		long long input;
		cout << "? " << i + 1 << " " << i + 2 << endl;
		cin >> input;
		sums.push_back(input);
	}
	vector<long long> ans = getAns(findA(sums[0], sums[1], sumCA), sums);
	cout << "!";
	for(long long m : ans){
		cout << " " << m;
	}
	cout << endl;
}
