#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Number{
	int data;
	int index;
};

bool cmp(Number a, Number b){
	return a.data < b.data;
}

vector<Number> order(vector<Number> v){
	sort(v.begin(), v.end(), cmp);
	return v;
}

int main(){
	int n, k;
	cin >> n >> k;
	vector<Number> nums;
	for(int i = 0; i < n; ++i){
		Number num;
		cin >> num.data;
		num.index = i;
		nums.push_back(num);
	}
	nums = order(nums);
	vector<Number> ans;
	int lp = 0;
	int rp = n - 1;
	for(int i = 0; i < n; ++i){
		if(i % k == 0){
			ans.push_back(nums[rp]);
			--rp;
		}else{
			ans.push_back(nums[lp]);
			++lp;
		}
	}
	for(int i = 0; i < n; ++i){
		cout << ans[i].index + 1;
		if(i != n - 1){
			cout << " ";
		}
	}
}
