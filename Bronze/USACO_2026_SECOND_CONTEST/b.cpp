#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> moves;
int n;
pair<int, int> recurse(vector<bool> board,vector<int> mcount, vector<int> ocount){
	//cout << "level " << board.size() << endl;
	if(board.size() == n){
		int count = 0;
		for(int i = 0; i < moves.size(); ++i){
			if(board[moves[i][0]] && !board[moves[i][1]] && !board[moves[i][2]]){
				++count;
			}
		}
		return {count, 1};
	}else{
		if(mcount[board.size() + 1] > ocount[board.size() + 1]){
			board.push_back(true);
			auto r1 = recurse(board, mcount, ocount);
			board.pop_back();
			return r1;
		}
		if(mcount[board.size() + 1] == 0){
			board.push_back(false);
			auto r2 = recurse(board, mcount, ocount);
			board.pop_back();
			return r2;
		}
		board.push_back(true);
		auto r1 = recurse(board, mcount, ocount);
		board.pop_back();
		board.push_back(false);
		auto r2 = recurse(board, mcount, ocount);
		board.pop_back();
		if(r1.first > r2.first){
			return r1;
		}
		if(r2.first > r1.first){
			return r2;
		}
		return {r1.first, r1.second + r2.second};
	}
}

int main(){
	cin >> n;
	vector<int> mcount(n + 1, 0);
	vector<int> ocount(n + 1, 0);
	int m;
	cin >> m;
	while(m--){
		int a,b,c;
		cin >> a >> b >>  c;
		++mcount[a];
		++ocount[b]; ++ocount[c];
		moves.push_back({a-1,b-1,c-1});
	}
	auto ans = recurse({}, mcount, ocount);
	cout << ans.first <<' '<< ans.second << endl;
}
