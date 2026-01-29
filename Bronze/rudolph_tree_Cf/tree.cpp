/*I want to find overlap of two branches
 *          /\
 *         /| \
 *        / |x \
 *       /  |   \
 *      /   /\   \
 *     /   /  \   \
 *    /   /    \   \
 *   ----/------\----
 *      /        \  |
 *     /          \ | x
 *    /            \|
 *   ----------------
 * 
 * height of overlap = h - x
 * The overlap is similar to the triangles, so the base is b(h - x) / h
 *                                                       = bh / h - bx / h
 *                                                       = b - bx / h
 * area of overlap = (h - x)(b - bx / h) / 2
 *                 = (bh - bx - bx + bx^2 / h) / 2
 *                 = (bh - 2bx + bx^2 / h) / 2
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ld calcOverlap(ld b, ld h, ld x){
	if(x >= h) return 0;
	return (b*h - 2*b*x + (b*x*x)/h) / 2;
}

int main(){
	cout << fixed << setprecision(15);
	ll t;
	cin >> t;
	while(t--){
		ld n, b, h;
		cin >> n >> b >> h;
		vector<ld> positions(n);
		for(ll i = 0; i < n; ++i){
			cin >> positions[i];
		}
		ld totalArea = b * h * n / 2;
		ld overlap = 0;
		for(ll i = 1; i < n; ++i){
			overlap += calcOverlap(b, h, positions[i] - positions[i - 1]);
		}
		cout << totalArea - overlap << '\n';
	}
}
