#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	freopen("breedflip.in", "r", stdin);
	freopen("breedflip.out", "w",stdout);
	string original;
	int num;
	cin >> num;
	string ideal;
	cin >> original >> ideal;
	vector<bool> needsFlip;
	for(int i = 0; i < num; ++i){
		if(original[i] != ideal[i]){
			needsFlip.push_back(true);
		}else{
			needsFlip.push_back(false);
		}
	}
	needsFlip.push_back(false);
	int ans = 0;
	for(int i = 0; i < num; ++i){
		if(needsFlip[i] == true && needsFlip[i + 1] == false){
			++ans;
		}
	}
	cout << ans;
	return 0;
}
