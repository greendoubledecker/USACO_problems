#include <iostream>
#include <vector>

using namespace std;

int ascending(vector<int> vec){//1,2,3,6,4,5,7
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

vector<int> flipInd(vector<int> vec){//4,5,3,1,2 becomes *,3,4,2,0,1
	vector<int> ans(vec.size() + 1);
	for(int i = 0; i < vec.size(); ++i){
		ans[vec[i]] = i;
	}
	return ans;
}

vector<int> endPlace(vector<int> start, vector<int> end){// a = 3,2,4,5,1 , b = 5,1,2,3,4, 1 goes to 1, 2 goes to 2, 3 goes to position 3, 4 goes to 4, 5 goes to 0.
	vector<int> flip = flipInd(end);
	vector<int> ans;
	for(int i = 0; i < start.size(); ++i){
		ans.push_back(flip[start[i]]);
	}
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
