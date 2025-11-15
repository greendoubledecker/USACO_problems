#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int cards = 4;

bool checkIfInt(int num, int den){
	if(den == 0){
		return false;
	}
	return num % den == 0;
}

int add(int a, int b, vector<int> nums);
int sub(int a, int b, vector<int> nums);
int mul(int a, int b, vector<int> nums);
int div(int a, int b, vector<int> nums);

int recurse(vector<int> nums){
	/*
	cout << "recursing on vector: ";
	for(int num : nums){
		cout << num << " ";
	}
	cout << endl;
	*/
	if(nums.size() == 1){
		if(nums[0] <= 24){
			return nums[0];
		}
		return INT_MIN;
	}
	int maxAns = INT_MIN;
	for(int a = 0; a < nums.size(); ++a){
		for(int b = a + 1; b < nums.size(); ++b){
			int curr = max({
			add(a, b, nums),
			sub(a, b, nums),
			mul(a, b, nums),
			div(a, b, nums)
			});
			if(curr > maxAns){
				maxAns = curr;
			}
		}
	}
	return maxAns;
}

int add(int a, int b, vector<int> nums){
	int temp = a;
	a = max(a, b);
	b = min(temp, b);
	vector<int> res = nums;
	res.erase(res.begin() + a);
	res.erase(res.begin() + b);
	res.push_back(nums[a] + nums[b]);
	return recurse(res);
}
int sub(int a, int b, vector<int> nums){
	int temp = a;
	a = max(a, b);
	b = min(temp, b);
	vector<int> res = nums;
	int ASubB, BSubA;
	res.erase(res.begin() + a);
	res.erase(res.begin() + b);
	res.push_back(nums[a] - nums[b]);
	ASubB = recurse(res);
	res.pop_back();
	res.push_back(nums[b] - nums[a]);
	BSubA = recurse(res);
	return max(ASubB, BSubA);
}
int mul(int a, int b, vector<int> nums){
	int temp = a;
	a = max(a, b);
	b = min(temp, b);
	vector<int> res = nums;
	res.erase(res.begin() + a);
	res.erase(res.begin() + b);
	res.push_back(nums[a] * nums[b]);
	return recurse(res);
}
int div(int a, int b, vector<int> nums){
	int temp = a;
	a = max(a, b);
	b = min(temp, b);
	vector<int> res = nums;
	int ADivB, BDivA;
	res.erase(res.begin() + a);
	res.erase(res.begin() + b);
	if(checkIfInt(nums[a], nums[b])){
		res.push_back(nums[a] / nums[b]);
		ADivB = recurse(res);
		res.pop_back();
	}else{
		ADivB = INT_MIN;
	}
	if(checkIfInt(nums[b], nums[a])){
		res.push_back(nums[b] / nums[a]);
		BDivA = recurse(res);
	}else{
		BDivA = INT_MIN;
	}
	return max(ADivB, BDivA);
}

void tc(){
	vector<int> hand;
	for(int i = 0; i < cards; ++i){
		int card;
		cin >> card;
		hand.push_back(card);
	}
	cout << recurse(hand) << endl;
}

int main(){
	int hands;
	cin >> hands;
	for(int i = 0; i < hands; ++i){
		tc();
	}
	return 0;
}
