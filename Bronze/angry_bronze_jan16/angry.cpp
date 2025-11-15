#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	//freopen("angry.in", "r", stdin);   // Redirect cin to read from file
    //freopen("angry.out", "w", stdout); // Redirect cout to write to file
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
		int t = 1;
		while (true){
			finLeft = -1; finRight = -1;
			prevLeft = left; prevRight = right;
			//shrink range and count bales 💥'ed
			// if there's a mess of characters it was a explode emoj
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
			cout << "range " << finLeft << " to " << finRight << endl;
			if(left == prevLeft && finLeft == -1){
				cout << "stop left" << endl;
				finLeft = left;
			}
			if(right == prevRight && finRight == -1){
				cout << "stop right" << endl;
				finRight = right;
			}
			if(finRight >= 0 && finLeft >= 0){
				break;
			}
			++t;
		}
		cout << "range " << left << " to " << right << endl;
		auto start = lower_bound(bales.begin(), bales.end(), finLeft);
		auto end = upper_bound(bales.begin(), bales.end(), finRight);
		if(end - start > max){
			max = end - start;
		}
		cout << "pos " << pos << " exploded " << end - start << " bales" << endl;
	}
	cout << max << endl;
	return 0;
}
