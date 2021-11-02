#include <iostream>
#include <vector>

using namespace std;

int dr[4] = {-1, 1, 0, 0}; //상, 하, 좌, 우
int dc[4] = {0, 0, -1, 1}; //상, 하, 좌, 우

vector<vector<int>> board, dp; //지도와 dp를 저장하는 2차원 배열 (벡터) 생성
int n, m; // 세로, 가로를 저장하는 변수

int dfs(int cr, int cc) { //dfs로 탐색
    if (cr == n - 1 && cc == m - 1) //오른쪽 아래 끝까지 왔다면 경로가 하나 생긴 것이므로 dp값 1로 초기화 후 리턴
        return dp[cr][cc] = 1; //dp값 1로 변경후 리턴
    if (dp[cr][cc] != -1) //이미 값(현재 정점에서 오른쪽 아래 끝까지 가는 경로의 수)이 존재한다면
        return dp[cr][cc]; //현재 dp값 리턴

    dp[cr][cc] = 0; //탐색 시작을 위해 0으로 초기화
    for (int i = 0; i < 4; i++) { // 상하좌우 총 4번 반복문
        int nr = cr + dr[i]; //새로 탐색할 row 값
        int nc = cc + dc[i]; //새로 탐색할 col 값
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && board[cr][cc] > board[nr][nc]) //보드의 범위 안에 있고, 현재 정점의 값보다 작을 경우
            dp[cr][cc] += dfs(nr, nc); //다음 정점의 값을 현재 정점에 더함(현재 정점에서 다음 정점 가는게 가능하므로)
    }

    return dp[cr][cc]; //자식 노드를 모두 탐색했다면 현재 정점의 값을 리턴해서 부모 노드로 돌아감
}

/**
 * [DFS + DP활용 문제]
 * dfs만 활용하면 시간초과
 * 따라서 경로의 경우의 수를 저장하며 탐색해야 함
 *
 * [BFS가 안되는 이유]
 * 주변 노드부터 탐색하다 갈 수 있는 경로에 이미 방문 처리가 되어 탐색 못할 수 있음
 * 주변 노드부터 탐색하므로 여러 경우의 수를 한 번에 탐색해서, 도착지점을 찍기 전이기 때문에 dp 활용이 불가
 */

int main() {
    //입력
    cin >> n >> m; //지도의 세로와 가료 입력
    board.assign(n, vector<int>(m, 0)); //지도, 보드 생성
    dp.assign(n, vector<int>(m, -1)); //이미 탐색한 값이 0일 수도 있기 때문에 구분하기 위해 -1로 초기화
    for (int i = 0; i < n; i++) //지도의 세로만큼 반복
        for (int j = 0; j < m; j++) //지도의 가로만큼 반복
            cin >> board[i][j]; // 지도에 값 저장

    //연산 & 출력
    cout << dfs(0, 0); //깊이 탐색 후 이동 가능한 경로 수 출력

    return 0; // 프로그램 종료
}
