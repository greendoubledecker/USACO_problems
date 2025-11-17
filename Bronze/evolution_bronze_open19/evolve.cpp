#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main(){
	freopen("evolution.out", "w", stdout);
	freopen("evolution.in" , "r", stdin );
	int num;
	cin >> num;
	vector<vector<string>> cows;
	unordered_set<string> traits;
	for(int i = 0; i < num; ++i){
		int n;
		cin >> n;
		vector<string> cow(n);
		for(int i = 0; i < n; ++i){
			string s;
			cin >> s;
			cow[i] = s;
			traits.insert(s);
		}
		cows.push_back(cow);
	}
	for(auto i = traits.begin(); i != traits.end(); ++i){
		for(auto j = next(i); j != traits.end(); ++j){
			bool a = false, b = false, both = false;
			for(vector<string> cow : cows){
				bool hasA = find(cow.begin(), cow.end(), *i) != cow.end(), hasB = find(cow.begin(), cow.end(), *j) != cow.end();
				if(hasA && !hasB){
					a = true;
				}else if(hasB && !hasA){
					b = true;
				}else if(hasB && hasA){
					both = true;
				}
			}
			if(a && b && both){
				cout << "no" << endl; 
				return 0;
			}
		}
	}
	cout << "yes" << endl;
	return 0;
}
