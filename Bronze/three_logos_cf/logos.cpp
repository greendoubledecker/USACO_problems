#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

void twoLogos(int longSide, int shortSide, pair<int, int> logo1, pair<int, int> logo2, char logo1Ltr, char logo2Ltr){
	if(logo1.first == shortSide){
		for(int i = 0; i < shortSide; ++i){
			for(int j = 0; j < logo1.second; ++j){
				cout << logo1Ltr;
			}
			if(logo2.first == shortSide){
				for(int j = 0; j < logo2.second; ++j){
					cout << logo2Ltr;
				}
			}else{
				for(int j = 0; j < logo2.first; ++j){
					cout << logo2Ltr;
				}
			}
			cout << endl;
		}
	}else if(logo1.second == shortSide){
		for(int i = 0; i < shortSide; ++i){
			for(int j = 0; j < logo1.first; ++j){
				cout << logo1Ltr;
			}
			if(logo2.first == shortSide){
				for(int j = 0; j < logo2.second; ++j){
					cout << logo2Ltr;
				}
			}else{
				for(int j = 0; j < logo2.first; ++j){
					cout << logo2Ltr;
				}
			}
			cout << endl;
		}
	}else if(logo1.first == longSide){
		for(int i = 0; i < logo1.second; ++i){
			for(int j = 0; j < longSide; ++j){
				cout << logo1Ltr;
			}
			cout << endl;
		}
		for(int i = 0; i < shortSide - logo1.second; ++i){
			for(int j = 0; j < longSide; ++j){
				cout << logo2Ltr;
			}
			cout << endl;
		}
	}else if(logo1.second == longSide){
		for(int i = 0; i < logo1.first; ++i){
			for(int j = 0; j < longSide; ++j){
				cout << logo1Ltr;
			}
			cout << endl;
		}
		for(int i = 0; i < shortSide - logo1.first; ++i){
			for(int j = 0; j < longSide; ++j){
				cout << logo2Ltr;
			}
			cout << endl;
		}
	}
}

int main(){
	vector<pair<int, int>> dims;
	int sum = 0;
	for(int i = 0; i < 3; ++i){
		pair<int, int> logo;
		cin >> logo.first >> logo.second;
		dims.push_back(logo);
		sum += logo.first * logo.second;
		//cout << "sum" << sum << endl;
	}
	int side = sqrt(sum);
	//cout << "side" << side << "sum" << sum << endl;
	if(side * side == sum && max({dims[0].first, dims[0].second, dims[1].first, dims[1].second, dims[2].first, dims[2].second}) <= side){
		int anchorIndex = -1; //There is always one logo that will cover an entire side. Proof on the bottom.
		int anchorWidth;
		char anchorLetter;
		int numAnchors = 0;
		for(int i = 0; i < 3; ++i){
			if(dims[i].first == side){
				anchorIndex = i;
				anchorWidth = dims[i].second;
				++numAnchors;
				if(i == 0){
					anchorLetter = 'A';
				}
				if(i == 1){
					anchorLetter = 'B';
				}
				if(i == 2){
					anchorLetter = 'C';
				}
			}else if(dims[i].second == side){
				anchorIndex = i;
				anchorWidth = dims[i].first;
				++numAnchors;
				if(i == 0){
					anchorLetter = 'A';
				}
				if(i == 1){
					anchorLetter = 'B';
				}
				if(i == 2){
					anchorLetter = 'C';
				}
			}
		}
		if(numAnchors != 1 && numAnchors != 3){
			cout << -1 << endl;
			return 0;
		}
		cout << side << endl;
		for(int i = 0; i < anchorWidth; ++i){
			for(int j = 0; j < side; ++j){
				cout << anchorLetter;
			}
			cout << endl;
		}
		if(anchorIndex == 0){
			twoLogos(side, side - anchorWidth, dims[1], dims[2], 'B', 'C');
		}
		if(anchorIndex == 1){
			twoLogos(side, side - anchorWidth, dims[0], dims[2], 'A', 'C');
		}
		if(anchorIndex == 2){
			twoLogos(side, side - anchorWidth, dims[0], dims[1], 'A', 'B');
		}
	}else{
		//cout << "fail basic check" << endl;
		cout << -1 << endl;
		return 0;
	}
}

/* Here's the proof.
 * There are 4 corners, but only 3 logos.
 * This means that one logo will take up at least 2 corners.
 * The logo cannot take up 3 corners (has to cover 4th corner),
 * and it also cannot take up all 4 corners because there still needs to be space for the other two logos.
 * So, one logo must always take up 2 corners.
 * We will call this the anchor.
 * Note that there are two possible arrangements of logos.
 * 1.
 * AAACC
 * AAACC
 * AAABB
 * AAABB
 * AAABB
 * The space without the anchor in it is split perpendicular to the anchor's long side.
 * 2.
 * AAAAAA
 * AAAAAA
 * AAAAAA
 * CCCCCC
 * BBBBBB
 * BBBBBB
 * The three logos' long and short sides are parallel.
 * These are all I need to check for.
 */
