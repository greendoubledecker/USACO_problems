#include <iostream>
#include <vector>

using namespace std;

int ascending(vector<int> vec){
	int count = 0;
	int largest = -1;
	for(int i = 0; i < vec.size(); ++i){
		if(vec[i] > largest){
			largest = vec[i];
		}else{
			++count;
		}
	}
	return count;
}

vector<int> flipInd(vector<int> vec){
	vector<int> ans(vec.size() + 1);
	for(int i = 0; i < vec.size(); ++i){
		ans[vec[i]] = i;
	}
	/*
	for(int i = 0; i < ans.size(); ++i){
		cout << ans[i] << " ";
	}
	cout << endl;
	*/
	return ans;
}

vector<int> endPlace(vector<int> start, vector<int> end){
	vector<int> flip = flipInd(end);
	vector<int> ans;
	//cout << "end is" << endl;
	for(int i = 0; i < start.size(); ++i){
		//cout << flip[start[i]] << " ";
		ans.push_back(flip[start[i]]);
	}
	//cout << endl;
	return ans;
}

int main(){
	int cows;
	cin >> cows;
	vector<int> a;
	for(int i = 0; i < cows; ++i){
		int n;
		cin >> n;
		a.push_back(n);
	}
	vector<int> b;
	for(int i = 0; i < cows; ++i){
		int n;
		cin >> n;
		b.push_back(n);
	}
	cout << ascending(endPlace(a, b)) << endl;
	return 0;
}
