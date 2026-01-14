#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <climits>
using lli = long long;

using namespace std;

lli MAX = 1000010; //just over the boundary
vector<lli> counts(1000010);

void findNums(string s){
	if(s[0] == '+' || s[0] == '*'){
		return;
	}
	lli current = 0, lastNum = 0;
	bool lastOp = false;
	lli prevSum = 0;
	lli multBy = 1;
	lli thisNum = s[0] - '0';
	
	for(lli i = 1; i < s.size(); ++i){
		char c = s[i];
		if(c == '+'){
			if(lastOp){
				return;
			}
			prevSum += multBy * thisNum;
			multBy = 1;
			thisNum = 0;
			lastOp = true;
		}else if(c == '*'){
			if(lastOp){
				return;
			}
			multBy *= thisNum;
			thisNum = 0;
			lastOp = true;
		}else{
			thisNum *= 10;
			thisNum += c - '0';
			if(prevSum + multBy * thisNum > MAX){
				return;
			}
			++counts[prevSum + multBy * thisNum];
			//cout << s.substr(0, i + 1) << " = " << prevSum + multBy * thisNum << endl;
			lastOp = false;
		}
	}
}

void solve(string s){
	for(int i = 0; i < s.size(); ++i){
		string ss = s.substr(i);
		findNums(ss);
	}
	reverse(s.begin(), s.end());
	for(int i = 0; i < s.size(); ++i){
		string ss = s.substr(i);
		findNums(ss);
	}
}

vector<string> findStrings(vector<string> input){
	vector<string> hor;
	for(lli row = 0; row < input.size(); ++row){
		hor.push_back(input[row]);
	}
	vector<string> ver;
	for(lli col = 0; col < input[0].size(); ++col){
		string cur;
		for(lli row = 0; row < input.size(); ++row){
			cur.push_back(input[row][col]);
		}
		ver.push_back(cur);
	}
	vector<string> diag;
	for(lli i = 0; i < input.size(); ++i){
		lli x = 0;
		lli y = i;
		string cur;
		while(x < input[0].size() && y < input.size()){
			cur.push_back(input[y][x]);
			++x;
			++y;
		}
		diag.push_back(cur);
	}
	for(lli i = 1; i < input[0].size(); ++i){
		lli x = i;
		lli y = 0;
		string cur;
		while(x < input[0].size() && y < input.size()){
			cur.push_back(input[y][x]);
			++x;
			++y;
		}
		diag.push_back(cur);
	}
	for(lli i = 0; i < input.size(); ++i){
		lli x = input[0].size() - 1;
		lli y = i;
		string cur;
		while(x >= 0 && y < input.size()){
			cur.push_back(input[y][x]);
			--x;
			++y;
		}
		diag.push_back(cur);
	}
	for(lli i = 0; i < input[0].size() - 1; ++i){
		lli x = i;
		lli y = 0;
		string cur;
		while(x >= 0 && y < input.size()){
			cur.push_back(input[y][x]);
			--x;
			++y;
		}
		diag.push_back(cur);
	}
	
	vector<string> ans;
	copy(hor.begin(), hor.end(), back_inserter(ans));
	copy(ver.begin(), ver.end(), back_inserter(ans));
	copy(diag.begin(), diag.end(), back_inserter(ans));
	return ans;
}
/*
lli calculate(vector<lli> nums){
	//do times first
	for(lli i = nums.size() - 2; i > 0; i -= 2){ //OPTIMIZATION: EVERY OTHER ENTRY IS AN OPERATION.
		//cout << "mult, i = " << i << endl;
		if(nums[i] == -1){
			auto start = nums.begin() + (i - 1);
			auto end = nums.begin() + (i + 2);
			lli product = nums[i - 1] * nums[i + 1];
			if(product > 1000000){
				return -1;
			}
			auto it = nums.erase(start, end);
			nums.insert(it, product);
		}
	}
	//next do plus
	for(lli i = nums.size() - 2; i > 0; i -= 2){ //NOT REALLY AN OPTIMIZATION: NOW ALL OPERATIONS ARE +.
		auto start = nums.begin() + (i - 1);
		auto end = nums.begin() + (i + 2);
		lli sum = nums[i - 1] + nums[i + 1];
		if(sum > 1000000){
			return -1;
		}
		auto it = nums.erase(start, end);
		nums.insert(it, sum);
	}
	//now it's done!
	return nums[0];
}
*/
int main(){
	vector<string> input/* = {
		"2+5",
		"+*3",
		"423"
	}*/;
	lli r, c, num;
	cin >> r >> c >> num;
	vector<lli> find(num);
	for(lli i = 0; i < r; ++i){
		string s;
		cin >> s;
		input.push_back(s);
	}
	for(lli i = 0; i < num; ++i){
		cin >> find[i];
	}
	vector<string> strings = findStrings(input);
	for(string s : strings){
		solve(s);
	}
	for(lli i = 0; i < r; ++i){
		for(lli j = 0; j < c; ++j){
			if(input[i][j] != '*' && input[i][j] != '+'){
				counts[input[i][j] - '0'] ++;
			}
		}
	}
	for(lli n : find){
		cout << counts[n] << endl;
	}
}
