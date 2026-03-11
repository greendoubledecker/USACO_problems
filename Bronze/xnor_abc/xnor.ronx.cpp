#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<long long> odd(n + 1);
	vector<long long> even(n + 1);
	string s;
	cin >> s;
	for(int i = 1; i <= n; ++i){
		if(s[i - 1] == '0'){
			even[i] = odd[i - 1];
			odd[i] = even[i - 1] + 1;
		}else{
			even[i] = even[i - 1] + 1;
			odd[i] = odd[i - 1];
		}
	}
	long long sum = 0;
	for(int i = 0; i <= n; ++i){
		sum += even[i];
	}
	cout << sum << endl;
}
