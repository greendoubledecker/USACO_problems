#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void tc(){
	int rows, cols, grass, bombs;
	cin >> rows >> cols >> grass >> bombs;
	if(bombs > rows || bombs > cols || bombs > grass || grass / (double) bombs > max(rows, cols)){
		cout << "NO" << endl;
		return;
	}else{
		cout << "YES" << endl;
	}
	vector<vector<bool>> isGrass(rows, vector<bool>(cols, false));
	for(int i = 0; i < bombs; ++i){
		isGrass[i][i] = true;
	}
	//cout << "1" << endl;
	if(rows > cols){
		//cout << "if" << endl;
		int row = 0;
		int col = 0;
		for(int i = bombs; i < grass; ++i){
			if(row == col){
				++col;
			}
			if(col >= bombs){
				++row;
				col = 0;
			}
			isGrass[row][col] = true;
			++col;
		}
	}else{
		//cout << "else" << endl;
		int row = 0;
		int col = 0;
		for(int i = bombs; i < grass; ++i){
			if(row == col){
				++row;
			}
			if(row >= bombs){
				++col;
				row = 0;
			}
			//cout << row << ", " << col << endl;
			isGrass[row][col] = true;
			++row;
		}
	}
	//cout << "2" << endl;
	for(int i = 0; i < rows; ++i){
		for(int j = 0; j < cols; ++j){
			if(isGrass[i][j]){
				cout << "#";
			}else{
				cout << ".";
			}
		}
		cout << endl;
	}
}

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		tc();
	}
}
