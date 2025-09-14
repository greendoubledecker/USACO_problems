#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

long recurse(vector<long> apples, size_t level, vector<long> included, long totalWeight){
	if (level == apples.size()){
		long incWeight = 0;
		for (size_t i = 0; i < included.size(); ++i){
			incWeight += included[i];
			cout << "Included: " << included[i] << endl;
		}
		cout << "Excluded: " << totalWeight - incWeight << " Included: " << incWeight << " Difference: " << abs(totalWeight - 2 * incWeight) << endl << endl;
		return abs(totalWeight - 2 * incWeight); // (totalWeight - incWeight) - incWeight
	}
	vector<long> newInc = included;
	newInc.push_back(apples[level]);
	return min(recurse(apples, level + 1, included, totalWeight), recurse(apples, level + 1, newInc, totalWeight));
}

void apples(){
	int n = 0;
	cin >> n;
	vector<long> apples;
	long value = 0;
	for (int i = 0; i < n; ++i){
		cin >> value;
		apples.push_back(value);
	}
	vector<long> included = {};
	size_t zero = 0;
	long totalWeight = 0;
	for (size_t i = 0; i < apples.size(); ++i){
		totalWeight += apples[i];
	}
	cout << "t" << totalWeight << endl;
	cout << recurse(apples, zero, included, totalWeight) << endl; 
}

int main(){
	apples();
	return 0;
}
