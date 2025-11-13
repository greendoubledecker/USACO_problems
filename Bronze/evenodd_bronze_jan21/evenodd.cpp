#include <iostream>

using namespace std;

int main(){
	int num, odd = 0, even = 0;
	cin >> num;
	for(int i = 0; i < num; ++i){
		int cow;
		cin >> cow;
		if(cow % 2 == 0){
			++even;
		}else{
			++odd;
		}
	}
	if(even == odd){
		cout << 2 * even << endl;
		return 0;
	}
	if(even > odd){
		cout << odd * 2 + 1 << endl;
		return 0;
	}
	if(odd > even){
		while(odd != even + 1 && even != odd + 1 && even != odd){
			odd -= 2;
			even ++;
		}
		if(odd == even + 1){
			cout << 2 * even - 1 << endl;
			return 0;
		}
		if(even == odd + 1){
			cout << odd * 2 + 1 << endl;
			return 0;
		}
		if(even == odd){
			cout << odd * 2 << endl;
			return 0;
		}
	}
}
