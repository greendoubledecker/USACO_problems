#include <iostream>
#include <vector>
#include <string>

using namespace std;

using ll = long long;

void tc(){
	ll n;
	cin >> n;
	string s = to_string(n);
	ll len = s.size();
	string copied = s+s+s+s+s+s+s+s;
	ll num = 0;
	vector<ll> as, bs;
	for(ll a = 1; a <= 10000; ++a){
		for(ll b = len * a - 8; b < len * a; ++b){
			if(b < 1){
				continue;
			}
			string ss = copied.substr(0, len * a - b);
			ll wrong = stoll(ss);
			ll correct = n * a - b;
			if(wrong == correct){
				++num;
				as.push_back(a);
				bs.push_back(b);
			}
		}
	}
	cout << num << endl;
	for(int i = 0; i < num; ++i){
		cout << as[i] << " " << bs[i] << endl;
	}
}

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		tc();
	}
}
