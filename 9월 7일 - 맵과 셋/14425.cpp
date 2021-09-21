#include<iostream>
#include<map>

using namespace std;

int main() {
	int n, m;
	map<string, int> first;
	string temp;
	cin >> n >> m;

	while (n--) {
		cin >> temp;
		first[temp] = 1;
	}
	
	int count = 0;
	while (m--) {
		cin >> temp;
		if (first[temp] == 1)
			count++;
	}
	cout << count << '\n';
}
