#include<iostream>
#include<vector>
#include<cmath>

#define SIZE 1000000
using namespace std;

//에라토스테네스의 체

//2부터 시작해서 배수들은 다 지운다. 4, 6, 8.. 모두 소수가 아님!!
//3의 경우 6, 9, 12 ... 모두 소수가 아님

vector<bool> isPrime(int n) {
	vector<bool> is_prime(n, true);
	is_prime[0] = is_prime[1] = false;//0과 1은 소수가 아니므로 제거
	
	//2 ~ 루트n까지 검사
	//왜냐하면 소수 검사 시 2,3,5.... 101 직전까지 검사 했다 하자
	//101에 대해 검사를 하려고 하면 101*2, 101*3...은 2와 3검사 시 이미 검사했다.
	//그러므로 101*101, 101*102... 부터 검사하면 된다.(검사 = false로 바꾸기)
	//이때 101*101이 n보다 크다면 검사하지않아도 되기 때문에
	//루트 n까지만 검사하는 것이다.
    
    //즉 루트n 까지 검사해도, 루트 n에 대해
    //i*i할 시점에 -> 루트n*루트 n= n, 즉 n이 소수인지 아닌지 판단된다.
    
	for (int i = 2; i <= sqrt(n); i++) {
		if (is_prime[i]) {
			//i=2의 경우 2, 4, 6, 8, 10 .... 를 false로(소수가 아니라는 의미)
			for (int j = i * i; j <= n-1; j += i) {
				is_prime[j] = false;
			}
		}
	}
	return is_prime;
}

int main() {

	//시간 효율성을 위해
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//소수인지 아닌지 판단
	vector<bool> is_prime = isPrime(SIZE);

	int n = -1;
	while (true) {
		cin >> n;

		if (n == 0) break;
		
		int check = false;
		for (int i = 0; i < is_prime.size(); i++) {
			if (is_prime[i] == true) {
				//n = a+b 일 때, a와 b도 소수여야함
				//n=8일 때, 소수 2를 보면, 8-2-6은 소수가 아니니 출력X
				//n=8일 때, 소수 3을 보면, 8-3=5도 소수이니 8=3+5 출력하고 break;
				if (is_prime[n - i] == true) {
					cout << n << " = " << i << " + " << n-i << '\n';
					check = true;
					break;
				}
			}
		}
		if (check==false)
			cout << "Goldbach's conjecture is wrong." << '\n';
	}


}
