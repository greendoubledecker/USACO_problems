#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

vector<string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
vector<int> currentOrder;
vector<int> ans;
bool found = false;

pair<int, int> parseConstraint(string constraint){
	stringstream ss(constraint);
	pair<int, int> ans;
	string firstToken, lastToken, tempToken;
	ss >> firstToken;
	ans.first = distance(cows.begin(), find(cows.begin(), cows.end(), firstToken));
	while (ss >> tempToken){
		lastToken = tempToken;
	}
	ans.second = distance(cows.begin(), find(cows.begin(), cows.end(), lastToken));
	return ans;
}

void recurse(vector<pair<int, int>> constraints, int level){
	if(level == cows.size()){
		if(!found){
			/*
			cout << "order: " << endl;
			for(int cow : currentOrder){
				cout << cows[cow] << endl;
			}
			*/
			int curr, prev, next;
			found = true;
			for(int i = 0; i < cows.size(); ++i){
				curr = currentOrder[i];
				if(i != 0){
					prev = currentOrder[i - 1];
				}else{
					prev = currentOrder[i];
				}
				if(i != cows.size() - 1){
					next = currentOrder[i + 1];
				}else{
					next = currentOrder[i];
				}
				bool works = true;
				for(pair<int, int> constraint : constraints){
					if(constraint.first == curr){
						//cout << "first: " << constraint.first << "second: " << constraint.second << "prev: " << prev << "next: " << next << endl;
						if(constraint.second != prev && constraint.second != next){
							//cout << "broken constraint: " << constraint.first << ", " << constraint.second << endl;
							works = false;
							break;
						}
					}
				}
				if(!works){
					found = false;
					break;
				}
			}
			if(found){
				//cout << "works" << endl;
				ans = currentOrder;
			}
		}
	}else{
		for(int i = 0; i < cows.size(); ++i){
			//cout << "next: " << cows[i] << endl;
			if(find(currentOrder.begin(), currentOrder.end(), i) == currentOrder.end()){
				currentOrder.push_back(i);
				recurse(constraints, level + 1);
				currentOrder.pop_back();
			}
		}
	}
}

int main(){
	vector<pair<int, int>> constraints;
	int num;
	cin >> num;
	for(int i = 0; i < num; ++i){
		//cout << "looping" << endl;
		string cow1, must, be, milked, beside, cow2;
		cin >> cow1 >> must >> be >> milked >> beside >> cow2;
		constraints.push_back(pair<int, int>{distance(cows.begin(), find(cows.begin(), cows.end(), cow1)), distance(cows.begin(), find(cows.begin(), cows.end(), cow2))});
	}
	recurse(constraints, 0);
	for(int cow : ans){
		cout << cows[cow] << endl;
	}
	return 0;
}
