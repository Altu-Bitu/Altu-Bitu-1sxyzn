#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

vector<vector<int>> board; // 모눈 종이
int dr[4] = {-1, 1, 0, 0}; // 열 정보
int dc[4] = {0, 0, -1, 1}; // 행 정보

void dfs(int n, int m, int row, int col) { //치즈 외부 공간과 내부 공간을 구분하는 dfs 함수
    if (row < 0 || row >= n || col < 0 || col >= m || board[row][col] != 0) // 범위를 벗어나면
        return; // 종료
    board[row][col] = -1; //외부 공기로 표시
    for (int i = 0; i < 4; i++) // 네 변 체크
        dfs(n, m, row + dr[i], col + dc[i]); // dfs
}

bool canMelt(int row, int col) { // 2면 이상 접촉한 치즈
    int cnt = 0;
    for (int i = 0; i < 4; i++) { //4면 탐색
        int nr = row + dr[i]; //위치 갱신
        int nc = col + dc[i]; //위치 갱신
        if (board[nr][nc] == -1) //외부 공간
            cnt++;
    }
    return cnt >= 2;
}

vector<ci> findCheese(int n, int m) { //녹을  치즈
    vector<ci> list; // 치즈 담을 벡터
    for (int i = 0; i < n; i++) { //모눈 크기만큼
        for (int j = 0; j < m; j++) { // 모눈 크기만큼
            if (board[i][j] == 1 && canMelt(i, j)) //녹지 않은 치즈면서, 이번에 녹일 수 있다면
                list.emplace_back(i, j); //치즈 저장
        } 
    }
    return list; //녹을 치즈들 리턴
}

/**
 * 아이디어
 * 1. 외부 공기와 2변 이상 접촉한 치즈 찾기
 * 2. 치즈 녹이기
 * 3. 해당 치즈가 녹으면서 새로운 외부 공간이 생기지 않았는지 체크
 * !외부 공간과 내부 공간을 구분하는 것이 중요!
 *
 * 구현
 * 1. dfs 함수로 외부 공간(-1)과 내부 공간(0)을 구분하기
 * 2. 녹지 않은 치즈면서, 외부 공간과 2변 이상 접촉한(canMelt) 치즈라면 이번에 녹을 수 있음(findCheese)
 *    !주의! 녹일 수 있는 치즈를 찾자마자 녹이지 않는 이유 :
 *          한 타임의 녹을 수 있는 치즈는 모두 동시에 녹아야 한다. 만약 치즈를 바로 녹이면 연쇄적으로 외부 공간이 생겨 녹지 못하는 치즈를 녹여버릴 수 있음
 * 3-1. 만약 녹을 수 있는 치즈가 없다면(list.empty()) 모든 치즈가 녹은 것이다.
 * 3-2. 녹을 수 있는 치즈가 있다면, 치즈를 녹이고(0), 새롭게 생긴 외부 공간을 표시(dfs)한다.
 */
int main() {
    int n, m; // 모눈 종이 크기

    //입력
    cin >> n >> m; // 모눈 종이 크기 입력
    board.assign(n, vector<int>(m)); // 모눈 종이
    for (int i = 0; i < n; i++) { //모눈 크기 만큼
        for (int j = 0; j < m; j++) //모눈 크기 만큼
            cin >> board[i][j]; // 치즈 정보 입력
    }

    //연산
    dfs(n, m, 0, 0); //외부 공간 표시

    int cnt = 0; //시간 변수
    while (true) { //치즈 없을 때 까지 무한 반복
        vector<ci> list = findCheese(n, m); //이번에 녹을 치즈들
        if (list.empty()) //치즈 없으면
            break; // 반복 종료
        //치즈를 녹이고, 새롭게 생긴 외부 공간 표시
        for (int i = 0; i < list.size(); i++) { // 치즈 갯수 만큼
            int row = list[i].first, col = list[i].second; // 위치 정보 저장
            board[row][col] = 0; // 모눈 비우기
            dfs(n, m, row, col); //dfs 연산
        }
        cnt++; // 시간 
    }

    //출력
    cout << cnt; //치즈가 모두 녹아 없어지는데 걸리는 시간
}
