#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, m;
		cin >> n >> m;
		vector<ll> a(n);
		for(ll i = 0; i < n; ++i){
			cin >> a[i];
		}
		ll k;
		cin >> k;
		vector<ll> b(n);
		for(ll i = 0; i < k; ++i){
			cin >> b[i];
		}
		bool ean = true;
		while(ean){
			//cout << "in loop" << endl;
			ean = false;
			vector<ll> next;
			cout << "a" << endl;
			for(ll num : a){
				cout << num << " ";
				if(num % m) continue;
				ean = true;
				for(int i = 0; i < m; ++i){
					next.push_back(num / m);
				}
			}
			cout << endl;
			a = next;
		}
		//cout << "aoswiguyhehhoaiuwsknhhoihqaphakspiq8h9q3w480h0awso,e0a8iqhwe8ohikp8oaqi8khlser4hogi8n59hhoi8kw94askhoe7yigKOIYU&(W8s4rde35aTHOGYIK&U(*S$Ekaoyiugtahjkuoiyw7e4hyujo9ik78" << endl;
		ean = true;
		while(ean){
			ean = false;
			vector<ll> next;
			for(ll num : b){
				if(num % m) continue;
				ean = true;
				for(int i = 0; i < m; ++i){
					next.push_back(num / m);
				}
			}
			b = next;
		}
		cout << (a == b ? "YES" : "NO") << endl;
	}
}
