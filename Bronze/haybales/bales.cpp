#include <iostream>
#include <vector>

using namespace std;

int main(){
	int num; cin >> num;
	int sum = 0;
	vector<int> nums(num);
	for(int i = 0; i < num; ++i){
		int n;
		cin >> n;
		sum += n;
		nums[i] = n;
	}
	int avg = sum / num;
	//cout << "avg = " << avg;
	sum = 0;
	for(int i = 0; i < num; ++i){
		if(nums[i] > avg){
			sum += nums[i] - avg;
		}else{
			sum += avg - nums[i];
		}
	}
	cout << sum/2 << endl;
	return 0;
}
