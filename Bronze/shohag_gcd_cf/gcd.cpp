#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

vector<ll> divisors(ll num){
	ll rt = sqrt(num);
	vector<ll> factors;
	for(ll i = 1; i <= rt; ++i){
		if(num % i == 0){
			factors.push_back(i);
			factors.push_back(num / i);
		}
	}
	return factors;
}

void tc(){
	ll n;
	ll m;
	cin >> n >> m;
	vector<ll> S(m);
	for(ll i = 0; i < m; ++i){
		cin >> S[i];
	}
	vector<ll> ans;
	for(ll i = 0; i < n; ++i){
		ll minInd = m - 1;
		vector<ll> divs = divisors(i + 1);
		//cout << i + 1 << " has " << divs.size() << " divisors" << endl;
		for(ll j = 0; j < divs.size(); ++j){
			//cout << "i = " << i + 1 << ", doing factor " << divs[j] << endl;
			if(divs[j] == i + 1){
				continue;
			}
			while(S[minInd] >= ans[divs[j] - 1]){
				--minInd;
				if(minInd == -1){
					cout << -1 << endl;
					return;
				}
			}
		}
		ans.push_back(S[minInd]);
	}
	for(ll i = 0; i < n; ++i){
		cout << ans[i];
		if(i != n - 1){
			cout << ' ';
		}else{
			cout << endl;
		}
	}
}

int main(){
	ll n;
	cin >> n;
	while(n--){
		tc();
	}
}
