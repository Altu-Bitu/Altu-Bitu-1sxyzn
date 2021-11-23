#include<iostream>
#include<vector>

using namespace std;
int main() {
	//시험장 수
	int n;
	cin >> n;

	//각 시험장의 응시자 수
	vector<int> num;
	while (n!=0) {
		int people;
		cin >> people;
		num.push_back(people);
		n--;
	}

	//B와 C
	int b, c;
	cin >> b >> c;

	//감독관의 최소 수
	int i;
	long long total = 0;
	for (i = 0; i < num.size(); i++) {
		if (num[i] <= b)
			total++;
		else {
			num[i] -= b;
			total++;
			total += num[i] / c;
			if (num[i] % c != 0)
				total++;
		}
	}
	cout << total << endl;
}
