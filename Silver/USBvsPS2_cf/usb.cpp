//Problem: there's USB A, B, and C, and Ethernet, and HDMI, and Thunderbolt, and that one weird port that looks like
//     ______   ______
//    /      \_/      \
//   /                 \
//   |       ____      |
//   |      |    |     |
//   |   () \    / ()  |
//   \       \__/      /
//    \_______________/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll a,b,c;
	cin >> a >> b >> c;
	ll n;
	cin >> n;
	vector<pair<ll, bool>> mouse(n);
	for(ll i = 0; i < n; ++i){
		cin >> mouse[i].first;
		string s;
		cin >> s;
		mouse[i].second = s[0] == 'U';
	}
	sort(mouse.begin(), mouse.end());
	ll usbNum = 0;
	ll ps2Num = 0;
	ll both = 0;
	ll cost = 0;
	for(auto i : mouse){
		bool neither = true;
		if(i.second){
			if(usbNum != a){
				++usbNum;
				neither = false;
				cost += i.first;
			}
		}else{
			if(ps2Num != b){
				++ps2Num;
				neither = false;
				cost += i.first;
			}
		}
		if(neither && both != c){
			++both;
			cost += i.first;
		}
	}
	cout << usbNum + ps2Num + both << ' ';
	cout << cost;
}
