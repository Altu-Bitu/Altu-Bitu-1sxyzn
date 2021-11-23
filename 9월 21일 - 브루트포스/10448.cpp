#include<iostream>
#include<vector>

using namespace std;

vector<int> num;
//삼각수를 벡터에 push_back
void calc() {
	int sum = 0;
	int k = 1;
	while (sum < 1000) {
		sum += k;
		num.push_back(sum);
		k++;
	}
}

//세 삼각수의 합이 입력한 수이면 true 리턴
bool check(int n) {
	bool c = false;
	for (int i = 0; i < num.size(); i++) {
		for (int j = 0; j < num.size(); j++) {
			for (int k = 0; k < num.size(); k++) {
				if (num[i] + num[j] + num[k] == n)
				{
					c = true;
					break;
				}
			}
		}
	}
	return c;
}

int main() {
	int n;
	cin >> n;

	calc();

	while (n--) {
		int t;
		cin >> t;
		if (check(t))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

}
