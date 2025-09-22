#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void abc(vector<int> nums){
	sort(nums.begin(), nums.end());
	int a = nums[0];
	int b = nums[1];
	int c = nums[6] - a - b;
	cout << a << " " << b << " " << c << endl;
}

int main(){
	vector<int> nums;
	nums.resize(7);
	for(int i = 0; i < 7; ++i){
		cin >> nums[i];
	}
	abc(nums);
	return 0;
}
