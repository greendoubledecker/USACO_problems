#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	long long N, K;
	cin >> N >> K;
	long long prev;
	cin >> prev;
	long long price = K + 1;
	for(int i = 1; i < N; ++i){
		long long num;
		cin >> num;
		price += min(num - prev, K + 1);
		prev = num;
	}
	cout << price << endl;
	return 0;
}
