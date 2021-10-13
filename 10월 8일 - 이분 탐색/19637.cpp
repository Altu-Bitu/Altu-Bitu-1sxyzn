#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<string> ch; //칭호
vector<int> u; //상한값
vector<int> p; //전투력

string bs(int left, int right, int p) { //binary search
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (p <= u[mid])
			right = mid - 1;
		else {
			//upper
			ans = mid;
			left = mid + 1;
		}
	}

	/*
	예제에 의해 아래와 같을 경우
	WEAK 10000
	NORMAL 100000
	STRONG 1000000
	*/

	//left가 right를 넘어감
	if (p > u[ans]) // 10001 입력된 경우를 예로 들면 현재 u[ans] = weak 이므로
		return ch[ans + 1]; //weak의 윗 레벨인 normal 칭호 리턴
	else //9999입력된 경우
		return ch[ans]; //weak 리턴
}

int main() {
	int n, m, temp; //n은 칭호의 개수, m은 캐릭터 개수
	cin >> n >> m;

	temp = n;
	string a; int b;
	while (temp--) {
		cin >> a >> b;
		ch.push_back(a);
		u.push_back(b);
	}

	temp = m;
	while (temp--) {
		cin >> b;
		p.push_back(b);
	}

	for (int i = 0; i < m; i++) {
		cout << bs(0, n - 1, p[i]) << '\n';
	}

}
