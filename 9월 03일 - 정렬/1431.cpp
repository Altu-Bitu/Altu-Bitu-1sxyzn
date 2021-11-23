#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//각 자리 숫자 합 함수
//아스키 코드 이용해서 문자열 중 숫자만 추출
int sum(string s) {
	int i, sum = 0;
	for (i = 0; i < s.length(); i++) {
		if (s[i] >= 48 && s[i] <= 57) {
			sum = sum + s[i] - 48;
		}
	}
	return sum;
}

//비교 함수
bool cmp(const string & a, const string & b) {
	//조건 1
	if (a.length() != b.length())
		return a.length() < b.length();

	//조건2
	else if (sum(a) != sum(b))
		return sum(a) < sum(b);

	//조건3
	else
		return a < b;
}


int main() {
	vector<string> guitar;
	string num;
	int n, temp;
	cin >> n;
	temp = n;
	while (temp != 0) {
		cin >> num;
		guitar.push_back(num);
		temp--;
	}

	sort(guitar.begin(),guitar.end(),cmp);
	int i;
	for (i = 0; i < n; i++) {
		cout << guitar[i] << endl;
	}
}
