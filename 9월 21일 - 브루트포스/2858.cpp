#include<iostream>

using namespace std;

int main() {
	int r, b;
	cin >> r >> b;
	
	int l, w;
	//i의 범위
	// 세로 길이가 가장 짧은게 3이다.
	// 이 경우 가로와 겹치지 않은 세로 벽돌은 2개 뿐임.
	//따라서 2개를 빼주고 위와 아래 2개가 있으니 나누기 2
	for (int i = 3; i <= (r-2) / 2; i++) {
		//j의 범위
		//= 전체  테두리 - 위 아래 테두리 (i*2) + i에서 빼버린 왼쪽 오른쪽 테두리 끝 (+4)
		//위의 것을 왼쪽과 오른쪽이 존재하므로 나누기 2
		for (int j = 3; j <= (r - i * 2 + 4) / 2; j++) {
			//전체 - 테두리 == 안쪽 벽돌 갯수일 때
			if (i * j - (i * 2 + (j - 2) * 2) == b) {
				if (i * 2 + (j - 2) * 2 == r) {
					if (i < j) {
						l = j;
						w = i;
					}
					else {
						l = i;
						w = j;
					}
					break;
				}
			}
		}
	}
	cout << l << ' ' << w << '\n';
}
