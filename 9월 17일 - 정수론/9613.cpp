#include<iostream>
#include<vector>

using namespace std;

//유클리드 호제법
//a,b의 최대공약수는 a%b, b의 최대공약수와 같다
//x%y 시 크기가 x>y여야 하므로
//a%b와 b의 자리를 바꿔 return gcd(b, a%b)를 한다.
int gcd(int a, int b) {
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}

int main() {
	int t;
	cin >> t ;	
	
	while (t--) {
		vector<int> v;
		//n개의 수를 2개씩 짝이어 gcd를 구하면
		// n(n-1)/2 개가 나옴
		// 한 n이 1000000범위이므로
		//gcd의 합인 sum은 long long 이어야한다.
		long long sum = 0;

		int n;
		cin >> n;
		int temp = n;

		int k;
		while (temp--) {
			cin >> k;
			v.push_back(k);	
		}

		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				sum += gcd(v[i], v[j]);
			}
		}

		cout << sum << '\n';
	}
}
