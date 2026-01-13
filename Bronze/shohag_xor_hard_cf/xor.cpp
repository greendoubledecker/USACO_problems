#include <iostream>

using namespace std;

void tc(){
	long long x, m;
	cin >> x >> m;
	long long p = m - m % x;
	long long ans = p / x - (x < p);
	//cout << "ans = " << ans << endl;
	if((x ^ p) > 0 && (x ^ p) <= m){
		++ans;
	}
	p += x;
	if((x ^ p) > 0 && (x ^ p) <= m){
		++ans;
	}
	
	for(int y = 1; y <= x && y <= m; ++y){
		if((x ^ y) % y == 0){
			//cout << "y = " << y << endl;
			++ans;
		}
	}
	
	if(x <= m){
		--ans;
	}
	cout << ans << endl;
}

int main(){
	long long t;
	cin >> t;
	while(t--){
		tc();
	}
}
