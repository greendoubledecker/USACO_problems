#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<bool> passTo; // false for left, true for right
	vector<int> locs;
	int num; cin >> num;
	for(int i = 0; i < num; ++i){
		int cow; cin >> cow; locs.push_back(cow);
	}
	sort(locs.begin(), locs.end());
	for(int i = 0; i < num; ++i){
		if(i == 0) passTo.push_back(true);
		else if(i == num - 1) passTo.push_back(false);
		else{
			if(locs[i] - locs[i - 1] <= locs[i + 1] - locs[i]) passTo.push_back(false);
			else passTo.push_back(true);
		}
	}
	int count = 0;
	for(int i = 0; i < num - 1; ++i){
		if(passTo[i] == true && passTo[i + 1] == false){
			++count;
			if(i != 0 && i != num - 2 && passTo[i - 1] == true && passTo[i + 2] == false) ++count;
		}
	}
	cout << count << endl;
	return 0;
}
