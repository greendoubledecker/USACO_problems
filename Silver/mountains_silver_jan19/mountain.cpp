/*                                            /\
 *             /\                            /  \  /\
 *            /  \                          /    \/  \
 *           /    \                        /          \
 *          /      \                      /            \
 *     /\  /        \              /\    /              \
 *    /  \/          \            /  \  /                \
 *   /                \      /\  /    \/                  \
 *  /                  \    /  \/                          \
 * /                    \  /                                \
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool comp(pair<ll, ll> a, pair<ll, ll> b){
	if(a.first - a.second == b.first - b.second){
		return a.first + a.second > b.first + b.second;
	}
	return a.first - a.second < b.first - b.second;
}
int main(){
	freopen("mountains.in","r",stdin);
	freopen("mountains.out","w",stdout);
	ll n;
	cin >> n;
	vector<pair<ll, ll>> mountains(n);
	for(pair<ll, ll> &p : mountains){
		cin >> p.first >> p.second;
	}
	if(n==1){
		cout << 1 << endl;
	}
	sort(mountains.begin(), mountains.end(), comp);
	ll count = 0;
	ll maxx = -1;
	for(pair<ll, ll> p : mountains){
		if(p.first + p.second > maxx){
			maxx = p.first + p.second;
			++count;
		}
	}
	cout << count << endl;
}
