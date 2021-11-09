#include <iostream>
#include <vector>

using namespace std;

void floydWarshall(int n, vector<vector<bool>> &graph) { //플로이드 워셜 방법
    for (int k = 1; k <= n; k++) { // 사건 전후 관계 수만큼,
        for (int i = 1; i <= n; i++) { // 사건의 갯수 만큼
            for (int j = 1; j <= n; j++) { //사건의 갯수 만큼
                if (graph[i][k] && graph[k][j]) //i->k, k->j 전후관계 있는 경우
                    graph[i][j] = true; // 그래프에 체크
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); //입출력 향상
    cin.tie(NULL); //입출력 향상

    int n, k, s, a, b; // 사건 갯수, 전후 관계 갯수, s a b는 아래 주석 참고
    //입력
    cin >> n >> k; //사건 갯수, 전후 관계 갯수
    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false)); //그래프 생성
    while (k--) { //전후 관계 갯수 만큼
        cin >> a >> b; // 전후 관계를 알고 있는 두 사건의 번호
        graph[a][b] = true; //전후관계 -> 단방향 그래프
    }

    floydWarshall(n, graph);    //연산

    //입력 & 출력
    cin >> s; //사건의 전후 관계를 알고 싶은 사건 쌍의 수 입력
    while (s--) { // 사건 쌍의 수 만큼
        cin >> a >> b; //서로 다른 두 사건의 번호
        if (graph[a][b]) // 앞에 있는 번호의 사건이 먼저 일어나면
            cout << "-1"; //-1 출력
        else if (graph[b][a]) // 뒤에 있는 번호의 사건이 먼저 일어났으면
            cout << "1"; //1 출력
        else //어떤지 모르면
            cout << "0"; //0 출력
        cout << '\n'; //줄바꿈
    }
    return 0; //프로그램 종료
}
