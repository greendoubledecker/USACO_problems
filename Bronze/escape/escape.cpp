#include <iostream>
#include <vector>
#include <string>

using namespace std;
int digs = 9;
vector<vector<int>> nums;  //backwards digit-by-digit (13278 becomes 872310000)
int cows;
int maxCows = 0;

vector<int> addVec(vector<int> v1, vector<int> v2){
	vector<int> ans = v1;
	for(int i = 0; i < ans.size(); ++i){
		ans[i] += v2[i];
	}
	return ans;
}

void recurse(vector<bool> included, int level, int numInc){ // level start at 0, included is all false at start, numInc = 0;
	if(level == cows - 1){
		if(numInc <= maxCows) return;
		vector<int> sum(digs, 0);
		for(int i = 0; i < cows; ++i){
			if(included[i]){
				sum = addVec(sum, nums[i]);
			}
		}
		/*
		cout << "sum is" << endl;
		for(int n : sum){
			cout << n << ", ";
		}
		cout << endl;
		*/
		for(int n : sum){
			if(n > 9) return;
		}
		maxCows = numInc;
		/*
		cout << "included is" << endl;
		for(bool i : included){
			cout << i << endl;
		}
		*/
		return;
	}else{
		vector<bool> yes = included, no = included;
		yes[level + 1] = true;
		recurse(yes, level + 1, numInc + 1);
		recurse(no, level + 1, numInc);
		return;
	}
}

int main(){
	cin >> cows;
	for(int cow = 0; cow < cows; ++cow){
		string weight;
		vector<int> backwards(digs, 0);
		cin >> weight;
		weight.insert(0, digs - weight.size(), '0');
		for(int i = 0; i < weight.size(); ++i){
			//cout << "huh" << endl;
			backwards[digs - i - 1] = weight[i] - '0';
		}
		nums.push_back(backwards);
	}
	vector<bool> empty(cows, false);
	recurse(empty, 0, 0);
	empty[0] = true;
	recurse(empty, 0, 1);
	cout << maxCows << endl;
}
