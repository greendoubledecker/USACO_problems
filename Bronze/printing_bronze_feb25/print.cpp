#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> repeats(vector<int> v){
	bool allSame = true;
	for(int i = 1; i < v.size(); ++i){
		if(v[i] != v[i - 1]){
			allSame = false;
			break;
		}
	}
	if(allSame){
		return {v[0]};
	}
	for(int i = v.size() / 2; i >= 2; --i){
		if(v.size() % i == 0){
			vector<vector<int>> parts;
			for(int j = 0; j < i; ++j){
				vector<int> cur;
				int l = j * (v.size()/i);
				int r = (j + 1) * (v.size()/i);
				for(int k = l; k < r; ++k){
					cur.push_back(v[k]);
				}
				parts.push_back(cur);
			}
			bool canSplit = true;
			for(int j = 1; j < parts.size(); ++j){
				if(parts[j] != parts[j - 1]){
					canSplit = false;
				}
			}
			if(canSplit){
				return parts[0];
			}
		}
	}
	return {-1};
}

int recurse(vector<int> v){
	if(v.size() == 1){
		return 1;
	}
	int ans1 = 0;
	int lp = 0;
	while(lp < v.size()){
		int rp = v.size();
		while(rp > lp){
			vector<int> sv;
			for(int i = lp; i < rp; ++i){
				sv.push_back(v[i]);
			}
			vector<int> rep = repeats(sv);
			if(rep[0] != -1){
				ans1 += recurse(rep);
				lp = rp;
				break;
			}
			--rp;
		}
	}
	
	int ans2 = 0;
	int rp = v.size();
	while(rp > 0){
		int lp = 0;
		while(lp < rp){
			vector<int> sv;
			for(int i = lp; i < rp; ++i){
				sv.push_back(v[i]);
			}
			vector<int> rep = repeats(sv);
			if(rep[0] != -1){
				ans2 += recurse(rep);
				rp = lp;
				break;
			}
			++lp;
		}
	}
	return min(ans1, ans2);
}

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n, k;
		cin >> n >> k;
		vector<int> v;
		for(int j = 0; j < n; ++j){
			int d;
			cin >> d;
			v.push_back(d);
		}
		int ans = recurse(v);
		if(ans <= k){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	return 0;
}
