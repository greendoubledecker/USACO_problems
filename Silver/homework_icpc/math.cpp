#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <climits>
#define lli long long

using namespace std;

vector<vector<lli>> tokenizeForward(string s){ // 0 is '+' and -1 is '*'
	//cout << "tokenizing " << s << endl;
	vector<vector<lli>> ans;
	for(lli start = 0; start < s.size(); ++start){
		//cout << "loop" << endl;
		vector<lli> current;
		bool lastType; //true = op, false = digit;
		if(s[start] == '+'){
			continue;
		}else if(s[start] == '*'){
			continue;
		}else{
			current.push_back(s[start] - '0');
			lastType = false;
		}
		/*
		if(countSingles){
			ans.push_back(current);
		}
		*/
		//cout << "push_back " << current[current.size() - 1] << endl;
		for(lli end = start + 1; end < s.size(); ++end){
			//cout << "inner, " << end << endl;
			if(s[end] == '+'){
				if(lastType == true){ //the bug was here
					break;
				}
				current.push_back(0);
				lastType = true;
			}else if(s[end] == '*'){
				if(lastType == true){ //the bug was here
					break;
				}
				current.push_back(-1);
				lastType = true;
			}else{
				if(lastType == true){
					current.push_back(s[end] - '0');
				}else{
					current[current.size() - 1] *= 10;
					current[current.size() - 1] += s[end] - '0';
					if(current[current.size() - 1] > 1000000){
						break;
					}
				}
				lastType = false;
			}
			if(lastType == true){
				continue;
			}
			ans.push_back(current);
			//cout << "push_back " << current[current.size() - 1] << endl;
		}
	}
	return ans;
}

vector<vector<lli>> tokenize(string s){
	vector<vector<lli>> ans1 = tokenizeForward(s);
	reverse(s.begin(), s.end());
	vector<vector<lli>> ans2 = tokenizeForward(s);
	copy(ans1.begin(), ans1.end(), back_inserter(ans2));
	return ans2;
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
	unordered_map<lli, lli> counts;
	vector<string> strings = findStrings(input);
	for(string s : strings){
		vector<vector<lli>> nums = tokenize(s);
		//cout << "parsing " << s << endl;
		for(vector<lli> v : nums){
			/*
			for(int n : v){
				cout << n << " ";
			}
			
			cout << "= " << calculate(v) << endl;
			*/
			lli ans = calculate(v);
			/*
			if(ans == 3){
				cout << "found in " << s << endl;
			}
			*/
			++counts[ans];
		}
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
