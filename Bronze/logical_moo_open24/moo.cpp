#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

const int INF = 2'000'000'000;

int main(){
	string exp;
	int a, q;
	cin >> a >> q;
	vector<int> groupNo(a);
	int group = 0;
	for(int i = 0; i < a; ++i){
		string s;
		cin >> s;
		if(s == "or"){
			++group;
		}else if(i % 2 == 0){
			groupNo[i] = group;
		}
		exp.push_back(s[0]);
	}
	
	++group;
	vector<int> firstFalse(group, INF), lastFalse(group, -1);
	for(int i = 0; i < a; i += 2){
		int g = groupNo[i];
		if(exp[i] == 'f'){
			if(firstFalse[g] == INF){
				firstFalse[g] = i;
			}
			lastFalse[g] = i;
		}
	}
	
	int firstTrue = INF,  lastTrue = -1;
	for(int i = 0; i < group; ++i){
		if(firstFalse[i] == INF){
			if(firstTrue == INF){
				firstTrue = i;
			}
			lastTrue = i;
		}
	}
	/*
	cout << "The first block evaluating to true is " << firstTrue << " and the last is " << lastTrue << endl;
	for(int i = 0; i < group; ++i){
		cout << "The first false in group" << i << "is " << firstFalse[i] << " and the last is " << lastFalse[i] << endl;
	}
	*/
	for(int i = 0; i < q; ++i){
		int L, R;
		cin >> L >> R;
		--L;
		--R;
		string s;
		cin >> s;
		int lgroup = groupNo[L];
		int rgroup = groupNo[R];
		if(firstTrue < lgroup || lastTrue > rgroup){
			if(s == "true"){
				cout << 'Y';
			}else{
				cout << 'N';
			}
		}else if(s == "true"){
			if(firstFalse[lgroup] < L || lastFalse[rgroup] > R){
				cout << 'N';
			}else{
				cout << 'Y';
			}
		}else{
			cout << 'Y';
		}
	}
}
