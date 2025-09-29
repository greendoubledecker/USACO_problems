#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> overlap(int l1, int b1, int r1, int t1, int l2,int b2, int r2, int t2){
	int left = max(l1, l2);
	int bot = max(b1, b2);
	int right = min(r1, r2);
	int top = min(t1, t2);
	vector<int> coords = {left, bot, right, top};
	return coords;
}

long long area(int x1, int y1, int x2, int y2){
	long long width = 1LL * (x2 - x1);
	long long height = 1LL * (y2 - y1);
	width = max(0LL, width);
	height = max(0LL, height);
	long long area = width * height;
	return area;
}

bool whitesheet(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, int x6, int y6){
	vector<int> overlap1 = overlap(x1, y1, x2, y2, x3, y3, x4, y4);
	vector<int> overlap2 = overlap(x1, y1, x2, y2, x5, y5, x6, y6);
	vector<int> black_overlap = overlap(x3, y3, x4, y4, x5, y5, x6, y6);
	long long area1 = area(overlap1[0], overlap1[1], overlap1[2], overlap1[3]);
	long long area2 = area(overlap2[0], overlap2[1], overlap2[2], overlap2[3]);
	long long doub_neg_area = area(max(x1, black_overlap[0]), max(y1, black_overlap[1]), min(x2, black_overlap[2]), min(y2, black_overlap[3]));
	int width = x2 - x1;
	int height = y2 - y1;
	long long area = (long long)width * height;
	long long totalOverlap = area1 + area2 - doub_neg_area;
	if(totalOverlap < area){
		return true;
	}else{
		return false;
	}
}

int main(){
	int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
	if(whitesheet(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6)){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	return 0;
}
