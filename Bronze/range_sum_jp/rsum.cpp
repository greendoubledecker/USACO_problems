#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N, Q;
	cin >> N >> Q;
	vector<long long> ps(N + 1);
	ps.push_back(0);
	for(int i = 1; i < N + 1; ++i){
		long long n;
		cin >> n;
		ps[i] = ps[i - 1] + n;
	}
	for(int i = 0; i < Q; ++i){
		int a, b;
		cin >> a >> b;
		//cout << "b + 1 is" << ps[b + 1] << ", a is" << ps[a] << endl;
		cout << ps[b] - ps[a] << endl;
	}
	return 0;
}
