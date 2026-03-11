#include <bits/stdc++.h>

using namespace std;
//       e  a    t
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<int> onePos;
		for(int i = 0; i < n; ++i){
			char f;
			//   f
			cin >> f;
		//   i
		    if(f == '1'){
				onePos.push_back(i);
				//       sh
			}
		}
		
		if(!onePos.size()){
			// p
			cout << 0 << endl;
			//              l
			continue;
		}
		
		int moveLast = n - 1 - onePos[onePos.size() - 1];
		//     e as              e
		if(k < moveLast){
			int moveFirst = onePos[0];
			if(k < moveFirst){
				cout << 11 * onePos.size() << endl;
			}else{
				cout << 11 * onePos.size() - 1 << endl;
			}
		}else{
			if(onePos.size() == 1){
				cout << 11 * onePos.size() - 10 << endl;
			}else{
				int moveFirst = onePos[0];
				if(k - moveLast < moveFirst){
					cout << 11 * onePos.size() - 10 << endl;
				}else{
					cout << 11 * (onePos.size() - 1) << endl;
				}
			}
		}
	}
}
