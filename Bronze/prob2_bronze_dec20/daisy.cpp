#include <iostream>
#include <vector>
#include <cmath>
//#include <cstdlib>

using namespace std;

int daisies (){
	int numflowers;
	cin >> numflowers;
	vector <int> flowers(numflowers);
	for (int i = 0; i < numflowers; ++i){
		cin >> flowers[i];
	}
	int avgCount = numflowers;
	for (int i = 0; i < numflowers; ++i){
		for (int j = i + 1; j < numflowers; ++j){
			int sum = 0;
			for (int k = i; k <= j; ++k){
				sum += flowers[k];
			}
			//cout << "i " << i << " j " << j << " sum " << sum << endl;
			if (sum % (j-i+1) != 0){
				continue;
			}else{
				int avg = sum / (j - i + 1);
				for (int k = i; k <= j; ++k){
					if (flowers[k] == avg){
						++avgCount;
						//cout << avgCount << endl;
						break;
					}
				}
			}
		}
	}
	return avgCount;
}

int main(){
	cout << daisies() << endl;
	return 0;
}
