#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct tcValue{
	ll val;
	ll tc = -1;
};

ll p, q;
map<ll, tcValue> a, b;
ll tcNum = 0;

void tc(){
	cin >> p >> q;
	for(ll i = 0; i < p; ++i){
		ll x;
		cin >> x;
		if(a[x].tc != tcNum){
			a[x].tc = tcNum;
			a[x].val = 1;
		}else{
			++a[x].val;
		}
	}
	for(ll i = 0; i < q; ++i){
		ll x;
		cin >> x;
		if(b[x].tc != tcNum){
			b[x].tc = tcNum;
			b[x].val = 1;
		}else{
			++b[x].val;
		}
	}
	vector<ll> numDivs(p + q + 1);
	for(pair<ll, tcValue> pairr : a){
		if(pairr.second.tc != tcNum){
			continue;
		}
		//cout << "pair: " << pairr.first << " " << pairr.second << endl;
		for(ll j = pairr.first; j <= p + q; j += pairr.first){
			numDivs[j] += pairr.second.val;
		}
	}
	//cout << "calculated numDivs\n";
	/*
	cout << "div:\n";
	for(ll i : numDivs){
		cout << i << ' ';
	}
	cout << '\n';
	*/
	ll divCount = 0;
	ll indivCount = 0;
	ll overlap = 0;
	for(pair<ll, tcValue> pairr : b){
		//cout << "b: " << i << endl;
		//cout << "mod lcmVal = " << i % lcmVal << endl;
		if(pairr.second.tc != tcNum){
			continue;
		}
		if(numDivs[pairr.first] == p){
			divCount += pairr.second.val;
		}else if(numDivs[pairr.first] == 0){
			indivCount += pairr.second.val;
		}else{
			overlap += pairr.second.val;
		}
	}
	//cout << "calculated 3 numbers\n";
	//cout << "d o i: " << divCount << ' ' << overlap << ' ' << indivCount << endl;
	divCount += (overlap & 1);
	//cout << "d o i: " << divCount << ' ' << overlap << ' ' << indivCount << endl;
	if(divCount > indivCount){
		cout << "Alice\n";
	}else{
		cout << "Bob\n";
	}
	++tcNum;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	while(t--) tc();
}
