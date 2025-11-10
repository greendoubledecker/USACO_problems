/*            ___    ___  __
 * |\    /|  /   \  /   \ ||
 * | \  / |  |   |  |   | ||
 * |  \/  |  \___/  \___/ O
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
	freopen("cowtip.in", "r", stdin);
	freopen("cowtip.out", "write", stdout);
	vector<vector<bool>> grid;
	int size;
	cin >> size;
	for(int i = 0; i < size; ++i){
		vector<bool> current;
		for(int j = 0; j < size; ++j){
			char cow;
			cin >> cow;
			current.push_back(cow == '1');
		}
		grid.push_back(current);
	}
	int y = size - 1, x = size - 1, count = 0;
	while(x >= 0 && y >= 0){
		//cout << "x" << x << "y" << y << endl;
		if(grid[y][x] == true){
			//cout << "in if" << endl;
			++count;
			for(int i = 0; i <= y; ++i){
				for(int j = 0; j <= x; ++j){
					//cout << "before: " << grid[i][j] << endl;
					grid[i][j] = !grid[i][j];
					//cout << "after: " << grid[i][j] << endl;
				}
			}
		}
		--y;
		++x;
		if(y < 0){
			y = x - 2;
			x = 0;
		}
		if(x >= size){
			x = y;
			y = size - 1;
		}
	}
	cout << count << endl;
	return 0;
}
