#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> prefixMex(1, 0);
		vector<int> v(n);
		vector<int> reverse(n);
		vector<bool> appears(n + 1);
		int stopped = 0;
		for(int i = 0; i < n; ++i){
			cin >> v[i];
			reverse[n - i - 1] = v[i];
			if(v[i] == prefixMex[i]){
				//calculate new mex
				//cout << "i = " << i << endl;
				for(int j = stopped; j <= i; ++j){
					if(v[j] <= n){
						//cout << v[j] << " appeared" << endl;
						appears[v[j]] = true;
					}
				}
				int mex = 0;
				for(int j = prefixMex[i]; j <= i + 1; ++j){
					if(!appears[j]){
						mex = j;
						break;
					}
				}
				//cout << "mex is " << mex << endl;
				prefixMex.push_back(mex);
				stopped = i + 1;
			}else{
				prefixMex.push_back(prefixMex[i]);	
			}
		}
		vector<int> suffixMex(1, 0);
		//cout << "SUFFIX" << endl;
		for(int i = 0; i <= n; ++i){
			appears[i] = false;
		}
		stopped = 0;
		for(int i = 0; i < n; ++i){
			if(reverse[i] == suffixMex[i]){
				//calculate new mex
				//cout << "i = " << i << endl;
				for(int j = stopped; j <= i; ++j){
					if(reverse[j] <= n){
						//cout << reverse[j] << " appeared" << endl;
						appears[reverse[j]] = true;
					}
				}
				int mex = 0;
				for(int j = prefixMex[i]; j <= i + 1; ++j){
					if(!appears[j]){
						mex = j;
						break;
					}
				}
				//cout << "mex is " << mex << endl;
				suffixMex.push_back(mex);
				stopped = i + 1;
			}else{
				suffixMex.push_back(suffixMex[i]);
			}
		}
		/*
		cout << "prefix mex" << endl;
		for(int i = 0; i <= n; ++i){
			cout << prefixMex[i] << " ";
		}
		cout << endl << "suffix mex" << endl;
		for(int i = 0; i <= n; ++i){
			cout << suffixMex[i] << " ";
		}
		cout << endl;
		*/
		bool done = false;
		for(int i = 1; i < n; ++i){
			//cout << "prefixMex = " << prefixMex[i] << " suffixMex = " << suffixMex[n - i] << endl;
			if(prefixMex[i] == suffixMex[n - i]){
				cout << "2" << endl << "1 " << i << endl << i + 1 << " " << n << endl;
				done = true;
				break;
			}
		}
		if(!done){
			cout << "-1" << endl;
		}
	}
}
