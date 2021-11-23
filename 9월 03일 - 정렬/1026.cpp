#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minSort(vector<int>a, vector<int>b) {
	vector<int>c = b;
	sort(c.begin(), c.end());
	sort(a.begin(), a.end(), greater<int>());

	int i, sum=0;
	for (i = 0; i < a.size(); i++)
		sum += a[i] * c[i];
	return sum;
}

int main() {
	int n, temp;
	cin >> n;

	vector<int> a;
	vector<int> b;

	temp = n;
	while (temp != 0) {
		int an;
		cin >> an;
		a.push_back(an);
		temp--;
	}

	temp = n;
	while (temp != 0) {
		int bn;
		cin >> bn;
		b.push_back(bn);
		temp--;
	}

	cout << minSort(a,b) << '\n';
}
