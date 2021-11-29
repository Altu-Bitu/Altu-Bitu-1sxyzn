#include <iostream>
#include <vector>

using namespace std;

vector<int> parent(201);

int findParent(int node) {
	if (parent[node] == node)
		return node;
	return parent[node] = findParent(parent[node]);
}

void unionInput(int x, int y) {
	int xp = findParent(x);
	int yp = findParent(y);

	if (xp == yp)
		return;

	parent[xp] = yp;
	findParent(xp);
}

int main()
{
	int n, m;
	cin >> n >> m;
	int temp = 0;

	while (temp < 201) {
		parent[temp] = temp;
		temp++;
	}
	
	int i, j;
	for (i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> temp;
			if (temp == 1)
				unionInput(i, j);
		}
	}

	bool check = true;

	cin >> i;
	while(m--) {
		cin >> j;
		if (check==false)
			continue;
		if (findParent(i) != findParent(j))
			check = false;

		i = j;
	}

	if (check==true)
		cout << "YES";
	else
		cout << "NO";
}
