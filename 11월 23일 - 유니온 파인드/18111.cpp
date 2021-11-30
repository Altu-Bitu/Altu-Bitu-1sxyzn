#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9; //큰 수
int mineLand(int n, int m, int b, int height, vector<vector<int>> &land) { // 땅 고르기 작업
    int tot_time = 0; //걸리는 시간
    for (int i = 0; i < n; i++) { //세로만큼
        for (int j = 0; j < m; j++) { //가로만큼
            if (land[i][j] > height) { //블록 제거
                b += (land[i][j] - height); //블록 갯수 갱신
                tot_time += 2 * (land[i][j] - height); //걸리는 시간 갱신
            } else if (land[i][j] < height) { //블록 쌓기
                b -= (height - land[i][j]);//블록 갯수 갱신
                tot_time += (height - land[i][j]); //걸리는 시간 갱신
            }
        }
    }
    if (b < 0) //최종적으로 블럭이 음수면 불가능한 높이
        return INF + 1; //무한대 리턴
    return tot_time; //땅고르는데에 걸리는 시간 리턴
}

/**
 * 1. 가장 낮은 땅의 높이를 h라고 할 때, h-1의 높이를 만드는건 h보다 2*(N*M)의 시간이 더 소요됨
 * 2. 가장 높은 땅의 높이를 h라고 할 때, h+1의 높이를 만드는건 h보다 (N*M)의 시간이 더 소요됨
 * -> 따라서 땅의 높이가 될 수 있는 후보는 (가장 낮은 땅) ~ (가장 높은 땅)
 * -> 가능한 모든 높이에 대해 브루트포스 연산해도 시간 초과 X
 *
 * !주의! 당장 쌓을 블록이 없더라도 언젠가 다른 곳의 블록을 제거해서 쌓을 수 있음.
 */
int main() {
    int n, m, b, min_height = 256, max_height = 0; //세로, 가로, 인벤토리의 블록 갯수, 땅의 높이의 변수 2개

    //입력
    cin >> n >> m >> b; //세로, 가로, 인벤토리의 블록 갯수 입력
    vector<vector<int>> land(n, vector<int>(m, 0)); //땅 생성
    for (int i = 0; i < n; i++) { //세로 만큼
        for (int j = 0; j < m; j++) { //가로 만큼
            cin >> land[i][j]; // 땅의 높이 입력
            min_height = min(min_height, land[i][j]); //제일 낮은 땅 높이
            max_height = max(max_height, land[i][j]); //제일 높은 땅 높이
        }
    }

    //연산
    int min_time = INF, height = 0; //시간과 땅의 높이를 구해보자
    for (int i = min_height; i <= max_height; i++) { //땅의 높이 구하기
        int t = mineLand(n, m, b, i, land); //연산
        if (t <= min_time) { //가장 빨리 작업이 끝나는 높이
            min_time = t; //땅 고르는데 걸리는 시간
            height = i; // 땅 높이
        }
    }

    //출력
    cout << min_time << ' ' << height; // 시간과 땅의 높이 출력
}
