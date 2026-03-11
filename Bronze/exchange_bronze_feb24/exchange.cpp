#include <bits/stdc++.h>
#define int long long

using namespace std;
signed main(){
	int n, k;
	cin >> n >> k;
	vector<bool> right(n);
	vector<int> a(n);
	int total = 0;
	for(int i = 0; i < n; ++i){
		char c;
		cin >> c;
		right[i] = c == 'R';
	}
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		total += a[i];
	}
	vector<pair<bool, vector<int>>> groups;
	pair<bool, vector<int>> cur = {right[0], {a[0]}};
	for(int i = 1; i < n; ++i){
		if(right[i] == right[i - 1]){
			cur.second.push_back(a[i]);
		}else{
			groups.push_back(cur);
			//cout << "size " << cur.second.size() << endl;
			cur = {right[i], {a[i]}};
		}
	}
	groups.push_back(cur);
	if(groups.size() == 1){
		cout << total << endl;
		return 0;
	}
	if(groups[groups.size() - 1].first == groups[0].first){
		//cout << "OVERFLOW Sizes are " << groups[0].second.size() << groups[groups.size() - 1].second.size() << endl;
		groups[0].second.insert(groups[0].second.begin(), groups[groups.size() - 1].second.begin(), groups[groups.size() - 1].second.end());
		groups.pop_back();
		//cout << "size is " << groups[0].second.size() << endl;
	}
	vector<int> sums(groups.size());
	for(int i = 0; i < groups.size(); ++i){
		if(groups[i].first){
			for(int j = 0; j < groups[i].second.size() - 1; ++j){
				sums[i] += groups[i].second[j];
			}
		}else{
			for(int j = 1; j < groups[i].second.size(); ++j){
				sums[i] += groups[i].second[j];
			}
		}
	}
	int loss = 0;
	for(int i = 0; i < sums.size(); ++i){
		loss += min(sums[i], k);
	}
	cout << total - loss << endl;
}
