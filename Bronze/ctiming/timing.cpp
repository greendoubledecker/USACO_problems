#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int d,h,m;
	cin >> d >> h >> m;
	int time = 1440 * (d - 11) + 60 * (h - 11) + m - 11;
	cout << max(-1, time) << endl;
}
