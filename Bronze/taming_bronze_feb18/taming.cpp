//This file contains C++.
#include <iostream>
#include <vector>

using namespace std;

int main(){
	freopen("taming.in", "r", stdin);
	freopen("taming.out", "w", stdout);
	int num;
	cin >> num;
	vector<int> nums(num);
	cin >> nums[0];
	nums[0] = 0;
	for(int i = 1; i < num; ++i){
		cin >> nums[i];
	}
	
	//check for validity
	for(int i = num - 1; i > 0; --i){
		if(nums[i] > 0){
			if(nums[i] > i){
				cout << -1 << endl;
				return 0;
			}
			for(int j = 0; j < nums[i]; ++j){
				if(nums[i - j] != -1 && nums[i - j] != nums[i] - j){
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}
	
	//find min
	int C = 0; //count
	int T = num - 1; //day #
	while(T > -1){
		if(nums[T] >= 0){
			T -= nums[T];
			C++; //see what I did there?
		}
		--T;
	}
	cout << C << " ";
	
	//find max
	C = 0;
	T = num - 1;
	while(T > -1){
		if(nums[T] >= 0){
			T -= nums[T];
		}
		--T;
		C++; //again!
	}
	cout << C << endl;
}
