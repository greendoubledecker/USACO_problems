#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

void triangle(vector<pair<int, int>> posts){
	int maxArea = 0;
	for(int p1 = 0; p1 < posts.size(); ++p1){
		for(int p2 = p1+1; p2 < posts.size(); ++p2){
			for(int p3 = p2+1; p3 < posts.size(); ++p3){
				int right, vert, hor;
				if(posts[p1].first == posts[p2].first && posts[p1].second == posts[p3].second){
					right = p1;
					vert = p2;
					hor = p3;
				}else if(posts[p1].first == posts[p3].first && posts[p1].second == posts[p2].second){
					right = p1;
					vert = p3;
					hor = p2;
				}else if(posts[p2].first == posts[p1].first && posts[p2].second == posts[p3].second){
					right = p2;
					vert = p1;
					hor = p3;
				}else if(posts[p2].first == posts[p3].first && posts[p2].second == posts[p1].second){
					right = p2;
					vert = p3;
					hor = p1;
				}else if(posts[p3].first == posts[p1].first && posts[p3].second == posts[p2].second){
					right = p3;
					vert = p1;
					hor = p2;
				}else if(posts[p3].first == posts[p2].first && posts[p3].second == posts[p1].second){
					right = p3;
					vert = p2;
					hor = p1;
				}else{
					continue;//not a valid triangle
				}
				int height = abs(posts[vert].second - posts[right].second);
				int width = abs(posts[hor].first - posts[right].first);
				if(maxArea < height * width){
					maxArea = height * width;
				}
			}
		}
	}
	cout << maxArea << endl;
}

int main(){
	vector<pair<int, int>> posts;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		pair<int, int> post;
		cin >> post.first >> post.second;
		posts.push_back(post);
	}
	triangle(posts);
	return 0;
}
