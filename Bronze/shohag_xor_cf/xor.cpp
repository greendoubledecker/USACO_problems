#include <iostream>
#include <vector>

using namespace std;

void tc(){
	long long x, m;
	cin >> x >> m;
	//cout << "recieved" << endl;
	long long ans = 0;
	for(int y = 1; y < 2 * x; ++y){
		if(y > m){
			break;
		}
		if((x ^ y) != 0 && (x % (x ^ y) == 0 || y % (x ^ y) == 0)){
			//cout << "y" << y << endl;
			++ans;
		}
	}
	cout << ans << endl;
}

int main(){
	long long t;
	cin >> t;
	while(t--){
		tc();
	}
}
