#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> hoofs(1, 0);
	vector<int> scissorss(1, 0);
	vector<int> papers(1, 0);
	for(int i = 1; i < n + 1; ++i){
		char c;
		cin >> c;
		hoofs.push_back(hoofs[i - 1]);
		scissorss.push_back(scissorss[i - 1]);
		papers.push_back(papers[i - 1]);
		if(c == 'H') ++hoofs[i];
		if(c == 'S') ++scissorss[i];
		if(c == 'P') ++papers[i];
	}
	int maxWins = 0;
	for(int i = 0; i <= n; ++i){
		int firstPartWins = max(hoofs[i], max(scissorss[i], papers[i]));
		int hoofs2ndPart = hoofs[n] - hoofs[i];
		int scissorss2ndPart = scissorss[n] - scissorss[i];
		int papers2ndPart = papers[n] - papers[i];
		int secondPartWins = max(hoofs2ndPart, max(scissorss2ndPart, papers2ndPart));
		if(maxWins < firstPartWins + secondPartWins){
			maxWins = firstPartWins + secondPartWins;
		}
	}
	cout << maxWins << endl;
	return 0;
}
