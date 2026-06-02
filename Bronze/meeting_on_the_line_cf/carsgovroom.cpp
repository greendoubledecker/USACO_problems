#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vector<ll> x(n),t(n);
		for(ll& m : x) cin >> m;
		for(ll& m : t) cin >> m;
		ll maxx = LLONG_MIN;
		ll minn = LLONG_MAX;
		for(ll i = 0; i < n; ++i){
			maxx = max(maxx, x[i] + t[i]);
			minn = min(minn, x[i] - t[i]);
		}
		double ans = (maxx+minn)/2.000;
		cout << fixed << setprecision(1) << ans << endl;
	}
}
/*Each person can be represented by a V-shaped graph with the vertex at [xi, ti].
 *For the 5th sample the graph looks like:
 *time
 *5|\ /
 *4| V
 *3|\ \ /
 *2| \ V
 *1|  V
 *0|
 * |_____ location
 *  01234
 *
 * The optimal x0 is where the maximum value of all the lines is least.
 * This maximum value is just the max of the rightmost downward-sloping line and the leftmost upward-sloping line.
 * The equation of a downward-sloping line is xi+ti-x and the equation of an upward-sloping line is ti-xi+x.
 * So, the rightmost downward-sloping line is max(xi+ti)-x and the leftmost upward-sloping line is max(ti-xi)+x.
 * x0 is at the intersection of these lines, so, we create an equation to solve:
 * max(xi+ti)-x0 = max(ti-xi)+x0
 * max(xi+ti)-max(ti-xi) = 2x0
 * max(xi+ti)+min(xi-ti) = 2x0
 * x0 = [max(xi+ti)+min(xi-ti)]/2
 */
