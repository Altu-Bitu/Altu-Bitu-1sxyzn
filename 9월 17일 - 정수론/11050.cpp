#include<iostream>

using namespace std;

int main() {
	int n, k, temp;;
	cin >> n >> k;
	temp = k;

	int a = 1;
	while (temp--) {
		a = a * n;
		n--;
	}

	int b = 1;
	for (; k > 0; k--) {
		b = b * k;
	}

	cout << a / b << '\n';

}
