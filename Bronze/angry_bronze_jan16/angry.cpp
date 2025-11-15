#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int num;
	cin >> num;
	vector<int> bales(num);
	for(int i = 0; i < num; ++i){
		cin >> bales[i];
	}
	sort(bales.begin(), bales.end());
	
	int left, right, prevLeft, prevRight, finLeft = -1, finRight = -1;
	int max = 0;
	for(int pos : bales){
		left = pos; right = pos;
		finLeft = -1; finRight = -1;
		int t = 1;
		while (true){
			prevLeft = left; prevRight = right;
			if(finLeft < 0){
				left -= t;
				for(int i = left; i <= prevLeft; ++i){
					if(binary_search(bales.begin(), bales.end(), i)){
						left = i;
						break;
					}
				}
			}
			if(finRight < 0){
				right += t;
				for(int i = right; i >= prevRight; --i){
					if(binary_search(bales.begin(), bales.end(), i)){
						right = i;
						break;
					}
				}
			}
			if(left == prevLeft && finLeft == -1){
				finLeft = left;
			}
			if(right == prevRight && finRight == -1){
				finRight = right;
			}
			if(finRight >= 0 && finLeft >= 0){
				break;
			}
			++t;
		}
		auto start = lower_bound(bales.begin(), bales.end(), finLeft);
		auto end = upper_bound(bales.begin(), bales.end(), finRight);
		if(end - start > max){
			max = end - start;
		}
	}
	cout << max << endl;
	return 0;
}
