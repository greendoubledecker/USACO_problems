#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int triangle(int start, int end){
	return end * (end + 1) / 2 - start * (start + 1) / 2;
}

int main(){
	long long dist;
	int num;
	cin >> dist >> num;
	for(int i = 0; i < num; ++i){
		int endVel;
		cin >> endVel;
		int maxSpeed = ceil((sqrt(8 * dist + 1) - 1) / 2);
		if(endVel >= maxSpeed){
			cout << maxSpeed << endl;
		}else{
			int accelTime, decelTime;
			double stallTime;
			for(int trySpeed = endVel; ; ++ trySpeed){
				int length = triangle(0, trySpeed) + triangle(endVel - 1, trySpeed - 1);
				//cout << "trying speed " << trySpeed << ", length " << length << endl;
				if(length > dist + endVel - 1){
					//cout << "speed is " << trySpeed - 1 << endl;
					int accelDist = triangle(0, trySpeed - 1);
					int decelDist = triangle(endVel - 1, trySpeed - 2);
					accelTime = trySpeed - 1;
					decelTime = trySpeed - 2 - endVel + 1;
					stallTime = (dist - accelDist - decelDist) / float(trySpeed - 1);
					//cout << "stallTime " << stallTime << endl;
					stallTime = ceil(stallTime);
					break;
				}
			}
			cout << accelTime + stallTime + decelTime << endl;
		}
	}
	return 0;
}
