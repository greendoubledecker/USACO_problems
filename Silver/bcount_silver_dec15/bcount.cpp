#include <iostream>
#include <vector>

using namespace std;

int numBreeds = 3;

int main(){
	freopen("bcount.in" , "r", stdin);
	freopen("bcount.out", "w", stdout);
	vector<vector<int>> breeds(numBreeds, vector<int>(1, 0));
	int n, q;
	cin >> n >> q;
	for(int i = 1; i < n + 1; ++i){
		int b;
		cin >> b;
		for(int j = 0; j < numBreeds; ++j) breeds[j].push_back(breeds[j][i - 1]);
		++breeds[b - 1][i];
	}
	for(int i = 0; i < q; ++i){
		int l, r;
		cin >> l >> r;
		for(int i = 0; i < numBreeds; ++i){
			if(i == numBreeds - 1){
				cout << breeds[i][r] - breeds[i][l - 1];
				break;
			}
			cout << breeds[i][r] - breeds[i][l - 1] << " ";
		}
		if(i == q - 1) return 0;
		cout << endl;
	}
}
