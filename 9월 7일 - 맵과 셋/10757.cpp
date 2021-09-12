#include<iostream>
#include<algorithm>

using namespace std;

string add(string a, string b) {
	//역순으로 해서 끝자리부터 더해주기
	
	//1234
	//+
	//  12 의 경우
	
	//4321
	//+
	//21 로 변경, 자리 수 다를 경우 번거로워서..

	reverse(a.begin(),a.end());
	reverse(b.begin(), b.end());

	string c;
	string max;


	//4321
	//+
	//21 의 경우

	//4321
	//+
	//2100 으로 변경
	
	//역순된거이므로 실제로 계산값 차이X
	//원래대로라면 1234+12 -> 1234+0012로 변경한 것
	int z;
	if (a.length() < b.length()) {
		for (z = a.length(); z < b.length(); z++)
			a += '0';
		max = b;
	}
	else {
		for (z = b.length(); z < a.length(); z++)
			b += '0';
		max = a;
	}
	
	//반올림 여부
	bool carry = false;
	int i, n;
	for (i = 0; i < max.length(); i++) {

		//끝자리 더해주기 끼리
		if (carry == true) {
			n = a[i] - '0' + b[i] - '0' + 1;
		}
		else
			n = a[i] - '0' + b[i] - '0';

		//반올림값 있으면 +1
		if (n >= 10) {
			c += n % 10 + '0';

			//05+08의 경우 031이어야 함 (역순이므로)
			//즉 마지막 계산의 경우 문자열 끝에 '1'더하기
			if (i == max.length() - 1)
				c += '1';
			carry = true;
		}
		else {
			c += n + '0';
			carry = false;
		}
	}

	reverse(c.begin(), c.end());
	return c;
}

int main() {
	string a, b;
	cin >> a >> b;
	cout << add(a,b) << '\n';
}
