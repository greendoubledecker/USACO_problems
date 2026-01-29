#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll convertBase(ll a, ll b, ll c, ll base){ // abc is the number
	return a * base * base  +  b * base  +  c;
}

// My solution:
pair<double, double> solveQuadratic(ll a, ll b, ll c){ //solve the quadratic equation for y based on what x is
	//    -b +- sqrt(b^2 - 4ac)
	//y = ---------------------
	//             2a
	
	double root = sqrt(b * b - 4 * a * c);
	double y1 = (-b + root) / (2 * a);
	double y2 = (-b - root) / (2 * a);
	return {y1, y2};
}

ll integerSolution(ll a, ll b, ll c){ //select the integer solution >= 10
	pair<double, double> y = solveQuadratic(a, b, c);
	if(y.first == floor(y.first) && y.first >= 10.0){
		return y.first;
	}else if(y.second == floor(y.second) && y.second >= 10.0){
		return y.second;
	}else{
		return -1;
	}
}

ll findY(ll x, ll a1, ll b1, ll c1, ll a2, ll b2, ll c2){ //a_1b_1c_1 and a_2b_2c_2 are the two numbers
	ll val = convertBase(a1, b1, c1, x);
	//Equation: a_2y^2 + b_2y + c_2 = val
	ll y = integerSolution(a2, b2, c2 - val);
	return y;
}

pair<ll, ll> mySolution(ll a1, ll b1, ll c1, ll a2, ll b2, ll c2){
	for(ll x = 10; x <= 15000; ++x){
		ll y = findY(x, a1, b1, c1, a2, b2, c2);
		if(y != -1){
			return {x, y};
		}
	}
	return {-1, -1};
}

// Official solution:
pair<ll, ll> official(ll a1, ll b1, ll c1, ll a2, ll b2, ll c2){
	ll x = 10;
	ll y = 10;
	while(x <= 15000 && y <= 15000){
		ll valX = convertBase(a1, b1, c1, x);
		ll valY = convertBase(a2, b2, c2, y);
		if(valX < valY){
			++x;
		}else if(valX > valY){
			++y;
		}else{
			return {x, y};
		}
	}
}


int main(){
	freopen("whatbase.in", "r", stdin);
	freopen("whatbase.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		string a, b;
		cin >> a >> b;
		pair<ll, ll> ans = mySolution(a[0] - '0', a[1] - '0', a[2] - '0',		b[0] - '0', b[1] - '0', b[2] - '0');
		cout << ans.first << " " << ans.second << endl;
	}
}
