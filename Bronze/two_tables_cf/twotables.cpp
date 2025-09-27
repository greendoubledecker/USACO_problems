#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int moveTable(int W, int H, int left, int bot, int right, int top, int w, int h){
	int moveLeft, moveRight, moveUp, moveDown;
	if((top - bot) + h > H){
		moveUp = 10000;
		moveDown = 10000;
	}else{
		int highest = H - h;
		moveDown = max(top - highest, 0);
		moveUp = max(h - bot, 0);
	}
	if((right - left) + w > W){
		moveRight = 10000;
		moveLeft = 10000;
	}else{
		int rightest = W - w;
		moveLeft = max(right - rightest, 0);
		moveRight = max(w - left, 0);
	}
	int minMove = min({moveUp, moveDown, moveLeft, moveRight});
	if(minMove == 10000){
		minMove = -1;
	}
	return minMove;
}

void tcf(){
	int W, H, left, bot, right, top, w, h;
	cin >> W >> H >> left >> bot >> right >> top >> w >> h;
	cout << moveTable(W, H, left, bot, right, top, w, h) << endl;
}

int main(){
	int tc;
	cin >> tc;
	for(int i = 0; i < tc; ++i){
		tcf();
	}
}
