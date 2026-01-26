#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		
		//calculate positions of a's and b's
		vector<int> aPos, bPos;
		for(int i = 0; i < n; ++i){
			char c;
			cin >> c; //input the character
			if(c == 'a'){ //it is a
				aPos.push_back(i);
			}else{        //it is b
				bPos.push_back(i);
			}
		}
		
		//if there are no a's or b's it is already done
		if(aPos.size() == 0 || bPos.size() == 0){
			cout << 0 << endl;
			continue;
		}
		
		//find median positions
		int middleA = aPos.size() / 2; //integer division is fine here, because it is still in between or equal to the same two a's
		int middleB = bPos.size() / 2; //same for b's
		
		//calculate sum of new positions for a's before median
		int aSumLess = 0;
		int pos = aPos[middleA] - 1; //just before the median
		for(int i = 0; i < middleA; ++i){
			aSumLess += pos;
			--pos; 
		}
		
		//and for b's
		int bSumLess = 0;
		pos = bPos[middleB] - 1; //just before the median
		for(int i = 0; i < middleB; ++i){
			bSumLess += pos;
			--pos;
		}
		
		//calculate sum of new positions for a's after median
		int aSumGreater = 0;
		pos = aPos[middleA]; //at the median
		for(int i = middleA; i < aPos.size(); ++i){
			aSumGreater += pos;
			++pos;
		}
		
		//and for b's
		int bSumGreater = 0;
		pos = bPos[middleB]; //at the median
		for(int i = middleB; i < bPos.size(); ++i){
			bSumGreater += pos;
			++pos;
		}
		
		//calculate sum of current positions for a's before median
		int aCurrLess = 0;
		for(int i = 0; i < middleA; ++i){
			aCurrLess += aPos[i];
		}
		
		//and for b's
		int bCurrLess = 0;
		for(int i = 0; i < middleB; ++i){
			bCurrLess += bPos[i];
		}
		
		//calculate sum of current positions for a's after median
		int aCurrGreater = 0;
		for(int i = middleA; i < aPos.size(); ++i){
			aCurrGreater += aPos[i];
		}
		
		//and for b's
		int bCurrGreater = 0;
		for(int i = middleB; i < bPos.size(); ++i){
			bCurrGreater += bPos[i];
		}
		
		//calculate steps needed to move all a's together
		int aSteps = (aSumLess - aCurrLess) + (aCurrGreater - aSumGreater);
		
		//and for b's
		int bSteps = (bSumLess - bCurrLess) + (bCurrGreater - bSumGreater);
		
		//output min steps
		cout << min(aSteps, bSteps) << endl;
	}
}
