#include <vector>
#include <iostream>

using namespace std;

int levels = 4;

int main(){
	vector<int> difference(levels), ans(levels - 1);
	for(int i = 0; i < levels; ++i){
		int bef, aft;
		cin >> bef >> aft;
		difference[i] = aft - bef;
		//cout << i << " " << difference[i] << endl;
	}
	
	for(int i = 0; i < levels; ++i){
		if(i < levels - 1){
			if(difference[i] < 0){
				ans[i] = - difference[i];
				//cout << "before " << difference[i + 1];
				difference[i + 1] += difference[i];
				difference[i] = 0;
				//cout << "after " << difference[i + 1] << endl;
			}
		}
	}
	
	for(int i = 0; i < levels; ++i){
		for(int j = 0; j < i; ++j){
			//cout << "iterate " << i << " " << j << endl;
			ans[j] += difference[i];
		}
	}
	
	for(int i = 0; i < levels - 1; ++i){
		cout << ans[i] << endl;
	}
}
