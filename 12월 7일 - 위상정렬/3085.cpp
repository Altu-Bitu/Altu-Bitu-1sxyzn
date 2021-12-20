#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int candy = 1;
vector<vector<int>> board(51, vector<int>(51, 0));

void cnt(int n) {
	int tmp = 1;
	int i, j;
	for (i = 1; i <= n; i++) {
		tmp = 1;
		for (j = 1; j <= n - 1; j++) {
			if (board[i][j] == board[i][j + 1]) //가로
				tmp++;
			else
				tmp = 1;

			candy = max(candy, tmp);
		}
	}

	for (i = 1; i <= n; i++) {
		tmp = 1;
		for (j = 1; j <= n - 1; j++) {
			if (board[j + 1][i] == board[j][i]) //세로
				tmp++;
			else
				tmp = 1;
			candy = max(candy, tmp);
		}
	}
}

int main() {
	string s;
	int n, i, j;
	cin >> n;

	for (i = 1; i <= n; i++) {
		cin >> s;
		for (j = 1; j <= n; j++) {
			board[i][j] = s[j - 1];
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n - 1; j++) {
			swap(board[i][j], board[i][j + 1]);
			cnt(n);
			swap(board[i][j], board[i][j + 1]);

			swap(board[j][i], board[j + 1][i]);
			cnt(n);
			swap(board[j][i], board[j + 1][i]);
		}
	}

	cout << candy;
}
