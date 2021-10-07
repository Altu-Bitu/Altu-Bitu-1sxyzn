#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

/*
삼각형을 만드는 조건 = 가장 긴 변의 길이는 나머지 두 변의 길이의 합보다 작다
*/

int max_tri(vector<int> tri) {
	//빨대의 길이를 오름차순으로 정렬
	sort(tri.begin(), tri.end(),greater<int>());
	/*
	1. 가장 긴 빨대 3개를 찾는다
	2. 크기가 a>b>c>d>e...일 때 a b c를 이용해 삼각형이 만들어지지 않는다면
		a b d, a c d... 모두 삼각형이 만들어 지지 않음
		(세 빨대 중 가장 큰 값인 a를 제외한, 나머지 두 빨대의 합이 a보다 커야하는데)
		(오름차순을 했으므로 뒤의 빨대들을 합할수록 크기가 더 작아짐)
	3. 삼각형을 만들 수 있는 다른 경우는
		a, 즉 가장 큰 빨대의 길이를 제외하고 나머지 빨대로 삼각형을 만드는 것!
	*/
	for (int i = 0; i < tri.size()-2; i++) {
		if (tri[i] < tri[i + 1] + tri[i + 2])
			return tri[i] + tri[i + 1] + tri[i + 2];
	}
	return -1;
}

int main() {
	int n, straw;
	cin >> n;

	vector<int> tri;
	while (n--) {
		cin >> straw;
		tri.push_back(straw);
	}

	cout << max_tri(tri) << '\n';

}
