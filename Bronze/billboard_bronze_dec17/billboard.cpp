#include <iostream>
#include <vector>

using namespace std;

int billboard(int b1l, int b1d, int b1r, int b1u, int b2l, int b2d, int b2r, int b2u, int tl, int td, int tr, int tu){ // add 1000 to all parameters
	int count = 0;
	for(int i = 0; i < 2000; ++i){
		for(int j = 0; j < 2000; ++j){
			if(!(i >= tl && i < tr && j >= td && j < tu)){
				if(i >= b1l && i < b1r && j >= b1d && j < b1u){
					count ++;
				}
				if(i >= b2l && i < b2r && j >= b2d && j < b2u){
					count ++;
				}
			}
		}
	}
	return count;
}

int main(){
	int b1l, b1d, b1r, b1u, b2l, b2d, b2r, b2u, tl, td, tr, tu;
	cin >> b1l >> b1d >> b1r >> b1u >> b2l >> b2d >> b2r >> b2u >> tl >> td >> tr >> tu;
	cout << billboard(b1l + 1000, b1d + 1000, b1r + 1000, b1u + 1000, b2l + 1000, b2d + 1000, b2r + 1000, b2u + 1000, tl + 1000, td + 1000, tr + 1000, tu + 1000) << endl;
	return 0;
}
