#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci; //위치 정보 저장할 pair
const int SIZE = 100 + 1; //격자 사이즈

int dy[4] = {0, -1, 0, 1}; //우, 상, 좌, 하
int dx[4] = {1, 0, -1, 0}; //우, 상, 좌, 하

//크기가 1x1인 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 것이 개수 구하기
int cntSquare(vector<vector<bool>> &board) { //문제에서 원하는 답,
    int ans = 0;// 정답 담을 변수
    for (int i = 0; i < SIZE - 1; i++) { //격자 행
        for (int j = 0; j < SIZE - 1; j++) { //격자 열
            if (board[i][j] && board[i][j + 1] && board[i + 1][j] && board[i + 1][j + 1]) //네 꼭지점이 모두 드래곤 커브의 일부이면 
                ans++;//정답수 증가
        }
    }
    return ans; //정답 리턴
}

ci makeDragonCurve(vector<vector<bool>> &board, vector<int> &direc, ci point) { //드래곤 커브 만들기
    int size = direc.size(); //그 전 세대까지의 방향 정보 
    for (int i = size - 1; i >= 0; i--) { //격자 사이즈만큼 반복
        int new_direc = (direc[i] + 1) % 4; //현재 시작 점의 방향
        point = {point.first + dy[new_direc], point.second + dx[new_direc]}; //현재 끝 점
        board[point.first][point.second] = true; //드래곤 커브 생서
        direc.push_back(new_direc); //방향 정보 push
    }
    return point; //끝 점 리턴
}

/**
 * x: 열, y: 행
 *
 * 드래곤 커브 = 선분들로 이루어짐
 * => 각 선분들의 방향을 저장해서 드래곤 커브의 좌푯값을 구해나가자
 *
 * 드래곤 커브는 각 세대마다 끝 점을 기준으로 시계 방향으로 90도 회전
 * -> 드래곤 커브 세대의 각 선분 방향 = 전 세대 방향들에서 차례로 끝 점을 기준으로 시계방향으로 이동한 것과 같음
 * -> (우(0) -> 상(1), 상(1) -> 좌(2), 좌(2) -> 하(3), 하(3) -> 우(0)) 로 이동
 * ex) 0세대: 우
 *     1세대: 상
 *     2세대: 좌 상 (1세대 + 0세대의 상, 우에서 각각 시계방향 이동)
 *     3세대: 좌 하 좌 상 (2세대 + 1세대 + 0세대에서 각각 시계방향 이동)
 *
 * 0세대는 이미 방향이 주어지므로 먼저 처리
 * 드래곤 커브는 격자 밖으로 나가지 않음 -> 범위 검사 필요 x
 */

int main() {
    int n, x, y, d, g; //순서대로 드래콘 커브의 개수, x y는 시작점, d는 시작 방향, g는 세대

    //입력 & 연산
    cin >> n; //커브의 개수
    vector<vector<bool>> board(SIZE, vector<bool>(SIZE, false)); //100x100 격자
    while (n--) { //커브의 개수 만큼
        cin >> x >> y >> d >> g; //커브의 정보 입력
        vector<int> direc; //세대의 방향 정보 저장 및 보존하는 벡터
        ci end_point = {y + dy[d], x + dx[d]}; //0세대 끝점
        board[y][x] = board[end_point.first][end_point.second] = true; //0세대 시작점, 끝점 초기화
        direc.push_back(d); //0세대 방향 삽입
        while (g--) { //각 세대마다 드래곤 커브 만들기
            end_point = makeDragonCurve(board, direc, end_point); //드래곤 커브 생성
        }
    }

    //출력
    cout << cntSquare(board) << '\n'; // 정사각형 네 꼭짓점이, 모두 드래곤 커브의 일부인 것의 갯수
    return 0; //프로그램 종료
}
