#include <iostream>
#include <vector>

using namespace std;

int dp(int n, int m, vector<vector<int>> &board) { //가장 긴 정사각형의 한 변의 길이 찾기
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); //임시 정사각형 한 변의 길이를 담을 변수 
    int ans = 0; //정답 담을 변수
    for (int i = 1; i <= n; i++) { //표의 크기 만큼
        for (int j = 1; j <= m; j++) { //한 변의 길이 만큼
            if (board[i - 1][j - 1]) //현재 위치(i-1, j-1)의 board 값이 1일 경우
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1; //1일 경우 정사각형 한 변의 길이가 작은 것을 가져옴
            ans = max(ans, dp[i][j]); //가장 큰 정사각형의 한 변 길이 갱신
        }
    }
    return ans; //가장 긴 정사각형의 한 변의 길이 리턴
}

int solution(vector<vector<int>> board) { //가장 큰 정사각형 찾는 함수
    int n = board.size(); // 표의 size
    int m = board[0].size(); // 표의 한 변의 길이
    int square_len = dp(n, m, board); //정사각형 한 변의 길이 계산
    return square_len * square_len; //가장 큰 정사각형의 넓이 리턴
}

/**
 * dp: 1로 이루어지는 정사각형의 한 변의 길이 저장, 즉 dp[i][j]에는 (i, j)를 끝 점으로 하는 정사각형의 한 변의 길이가 저장됨
 * 점화식: 현재 위치에서 왼쪽, 위쪽, 좌상향 중 가장 작은 정사각형의 한 변 길이 + 1 (단, 현재 위치가 1일 경우)
 *
 * 가장 '작은' 정사각형의 한 변 길이를 가져오는 이유
 * -> 정사각형의 모든 칸이 1로 이루어져있어야 하는데, 가장 큰 값을 가져올 경우 모든 칸이 1이 아닐 수 있기 때문
 * -> 즉, 가장 작은 한 변의 길이 값을 가져오는 경우가 모든 칸이 1인 정사각형을 만드는 경우임
 * ex.        1  0  0        1  0  0
 *            0  1  1   ->   0  1  1
 *            1  1  1        1  1  2
 *             board            dp
 *
 * 해당 풀이는 인덱스 관리를 편하게 하기 위해 dp 배열을 (1, 1)부터 시작 (따라서 현재 board 의 위치를 (i-1, j-1)로 접근)
 */

int main() {
    vector<vector<int>> board = {{0, 1, 1, 1}, //주어진 예시
                                 {1, 1, 1, 1}, //주어진 예시
                                 {1, 1, 1, 1}, //주어진 예시
                                 {0, 0, 1, 0}}; //주어진 예시
    int ans = solution(board); // 가장 큰 정사각형 찾는 함수 호출
    cout << ans; //정답 출력
}
