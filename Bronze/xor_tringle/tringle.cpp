#include <bits/stdc++.h> // I can just find the first one and zero in X,
using namespace std;     // then Y will have only those two bits as 1,
using ll = long long;    // and Y ^ X will be between X - Y and X + Y.
int main(){              // because it adds to X when it flips the first 0 bit to 1
	ll t;                // and subtracts from X when it flips the first 1 bit to 0.
	cin >> t;            // They don't have to be the first 1 bit and the first 0 bit,
	while(t--){          // but this is the easiest way to make sure that Y < X.
		ll x;
		cin >> x;
		bitset<64> bs(x); // bs[0] is LSB, bs[63] is MSB
		ll firstZero, firstOne; // if x = 0000 0000 0000 1011 (11), firstZero and firstOne are here:
		for(ll i = 63; i >= 0; --i){ //                   ^ ^
			if(bs[i]){
				firstOne = i;
			}else{
				firstZero = i;
			}
		}
		ll y = 0;
		y ^= 1 << firstZero; // set bit to 1
		y ^= 1 << firstOne;  // same
		if(y < x){
			cout << y << endl;
		}else{
			cout << -1 << endl;
		}
	}
}
