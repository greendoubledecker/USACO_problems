#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<vector<int>> xyfix(n, vector<int>(n, 0)), xzfix(n, vector<int>(n, 0)), yzfix(n, vector<int>(n, 0));
	int q;
	cin >> q;
	int total = 0;
	for(int i = 0; i < q; ++i){
		int x, y, z;
		cin >> x >> y >> z;
		++xyfix[x][y];
		++xzfix[x][z];
		++yzfix[y][z];
		int count = 0;
		if(xyfix[x][y] == n) ++count;
		if(xzfix[x][z] == n) ++count;
		if(yzfix[y][z] == n) ++count;
		total += count;
		cout << total << endl;
	}
	return 0;
}
