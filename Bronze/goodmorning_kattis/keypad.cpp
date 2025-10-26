#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

vector<vector<int>> keypad = {
{1, 2, 3},
{4, 5, 6},
{7, 8, 9}};
//  0

int recurse(int target, vector<pair<int, int>>current, int level){
	/*
	cout << "recursing at level " << level << endl;
	for(pair<int, int> dgt : current){
		cout << keypad[dgt.first][dgt.second] << " ";
	}
	cout << endl;
	*/
    if(level < 3){
		int closest = INT_MIN;
		if(level != 0){
			for(int y = current[current.size() - 1].first; y <= 2; ++y){
				for(int x = current[current.size() - 1].second; x <= 2; ++x){
					//cout << "inner loop" << endl;
					current.push_back({y, x});
					int nxtLvl = recurse(target, current, level + 1);
					if(abs(nxtLvl - target) < abs(closest - target)){
						closest = nxtLvl;
					}
					current.pop_back();
				}
			}
		}else{
			for(int y = 0; y <= 2; ++y){
				for(int x = 0; x <= 2; ++x){
					//cout << "inner loop" << endl;
					current.push_back({y, x});
					int nxtLvl = recurse(target, current, level + 1);
					if(abs(nxtLvl - target) < abs(closest - target)){
						closest = nxtLvl;
					}
					current.pop_back();
				}
			}
		}
        if(level != 0){
			int pow10 = 1;
			int curr = 0;
			for(int i = current.size() - 1; i >= 0; --i){
				int dgt = keypad[current[i].first][current[i].second] * pow10;
				curr += dgt;
				pow10 *= 10;
			}
			if(abs(curr - target) < abs(closest - target)){
				closest = curr;
			}
			if(current[current.size() - 1].second != 2){
				int currx10 = curr * 10;
				int currx100 = curr * 100;
				if(abs(currx10 - target) < abs(closest - target)){
					closest = currx10;
				}
				if(abs(currx100 - target) < abs(closest - target)){
					closest = currx100;
				}
			}
		}
        return closest;
    }else{
        int curr = 0;
        int pow10 = 1;
        for(int i = current.size() - 1; i >= 0; --i){
			//cout << "current y: " << current[i].first << ", currnet x: " << current[i].second << endl;
            int dgt = keypad[current[i].first][current[i].second] * pow10;
            curr += dgt;
            pow10 *= 10;
        }
        return curr;
    }
}

void tc(){
    int tgt;
    cin >> tgt;
    cout << recurse(tgt, {}, 0) << endl;
}

int main(){
    int tests;
    cin >> tests;
    for(int i = 0; i < tests; ++i){
        tc();
    }
    return 0;
}
