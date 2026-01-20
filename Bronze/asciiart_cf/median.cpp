#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> x = {a,b,c};
	sort(x.begin(), x.end());
	if(x[0] + 10 <= x[2]){
		cout << "check again" << endl;
	}else{
		cout << "final " <<  x[1] << endl;
	}
}
