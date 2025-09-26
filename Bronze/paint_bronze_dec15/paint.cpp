#include <iostream>
//#include <vector>
#include <algorithm>

using namespace std;

int paint(int a, int b, int c, int d){
	int count;
	for(int i = 0; i < 100; ++i){
		if((a <= i && i < b) || (c <= i && i < d)){
			count ++;
		}
	}
	return count;
}

int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << paint(a, b, c, d);
	return 0;
}
