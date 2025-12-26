#include <iostream>
#include <vector>
#include <climits>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

struct Node{
	long long group = -1;
	vector<long long> connections;
};

vector<vector<long long>> groups;
vector<Node*> nodes;
vector<long long> first, last;
vector<pair<long long, long long>> dists;

void setGroup(long long node, long long group, int level){
	//cout << "level " << level << endl;
	nodes[node]->group = group;
	if(group >= groups.size()){
		groups.push_back({});
	}
	//cout << "push " << node << "into " << group << endl;
	groups[group].push_back(node);
	for(long long neighbor : nodes[node]->connections){
		if(nodes[neighbor]->group == -1){
			setGroup(neighbor, group, level + 1);
		}
	}
}

long long assignAll(){
	long long group = 0;
	for(long long i = 0; i < nodes.size(); ++i){
		if(nodes[i]->group == -1){
			setGroup(i, group, 0);
			++group;
		}
	}
	long long firstGroup = nodes[0]->group;
	first = groups[firstGroup];
	long long lastGroup = nodes[nodes.size() - 1]->group;
	last = groups[lastGroup];
	sort(first.begin(), first.end());
	sort(last.begin(), last.end());
	return group;
}

void loop(){
	
	long long firstCounter = 0;
	long long lastCounter = 0;
	
	for(long long i = 0; i < nodes.size(); ++i){
		long long firstCost = abs(i - first[firstCounter]) * abs(i -first[firstCounter]);
		long long lastCost = abs(i - last[lastCounter]) * abs(i - last[lastCounter]);
		dists[nodes[i]->group].first = min(dists[nodes[i]->group].first, firstCost);
		dists[nodes[i]->group].second = min(dists[nodes[i]->group].second, lastCost);
		if(first[firstCounter] < i && firstCounter != first.size() - 1){
			++firstCounter;
			firstCost = abs(i - first[firstCounter]) * abs(i -first[firstCounter]);
			dists[nodes[i]->group].first = min(dists[nodes[i]->group].first, firstCost);
			if(first[firstCounter] > i){
				--firstCounter;
			}
		}
		/*if(first[firstCounter] > i && firstCounter != 0){
			--firstCounter;
		}*/
		if(last[lastCounter] < i && lastCounter != last.size() - 1){
			++lastCounter;
			lastCost = abs(i - last[lastCounter]) * abs(i - last[lastCounter]);
			dists[nodes[i]->group].second = min(dists[nodes[i]->group].second, lastCost);
			if(last[lastCounter] > i){
				--lastCounter;
			}
		}
		/*if(last[lastCounter] > i && lastCounter != 0){
			--lastCounter;
		}*/
	}
}

int main(){
	long long t;
	cin >> t;
	for(long long i = 0; i < t; ++i){
		long long n, m;
		last = {};
		first = {};
		dists = {};
		groups = {};
		cin >> n >> m;
		nodes.assign(n, nullptr);
		for(long long j = 0; j < n; ++j){
			nodes[j] = new Node;
		}
		for(long long j = 0; j < m; ++j){
			long long a, b;
			cin >> a >> b;
			nodes[a - 1]->connections.push_back(b - 1);
			nodes[b - 1]->connections.push_back(a - 1);
		}
		//cout << "recieved" << endl;
		long long num = assignAll();
		//cout << "assigned, last has size " << last.size() << endl;
		/*
		for(int x=0; x<groups.size(); x++){
			for(int z=0; z<groups[x].size(); z++){
				cout << groups[x][z] << " ";
			}
			cout << endl;
		}
		*/
		//cout << "there are " << groups.size() << " groups" << endl;
		//groups.assign(num, {});
		
		dists.assign(groups.size(), {LLONG_MAX, LLONG_MAX});
		//cout << "start loop" << endl;
		loop();
		long long minn = LLONG_MAX;
		for(pair<long long, long long> p : dists){
			minn = min(minn, p.first + p.second);
		}

		
		cout << minn << endl;
	}
}
