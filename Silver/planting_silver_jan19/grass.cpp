#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	freopen("planting.out", "w", stdout);
	freopen("planting.in", "r", stdin);
	int num;
	cin >> num;
	vector<int> amts(num, 0);
	for(int i = 0; i < num - 1; ++i){
		int a, b;
		cin >> a >> b;
		++amts[a - 1];
		++amts[b - 1];
	}
	cout << *max_element(amts.begin(), amts.end()) + 1 << endl;
	return 0;
}
