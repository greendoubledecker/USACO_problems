#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void tc(){
	int num;
	cin >> num;
	vector<int> locations(num);//, permutation;
	for(int i = 1; i <= num; ++i){
		int value;
		cin >> value;
		locations[value] = i;
		//permutation.push_back(value);
	}
	for(int i = 0; i < num; ++i){
		//cout << locations[i] << ",";
	}
	//cout << endl;
	long long ans = 1;
	int l = locations[0], r = locations[0];
	for(int size = 2; size <= num; ++size){
		int middle = (size - 1)/2;
		l = min({l, locations[middle], num - size + 1});
		r = max({r, locations[middle], size});
		//cout << "size=" << size << ",l=" << l << ",r=" << r << ",middle=" << middle << endl;
		if(r - l < size){
			ans += (size - (r - l));
		}
		//cout << "ans:" << ans << endl;
	}
	cout << ans << endl;
}

int main(){
	int tests;
	cin >> tests;
	for(int i = 0; i < tests; ++i){
		tc();
	}
	return 0;
}

