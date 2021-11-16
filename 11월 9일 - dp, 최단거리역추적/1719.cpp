#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e5 * 2; //최대 n-1개의 간선을 지나게 됨

void floydWarshall(int n, vector<vector<int>> &graph, vector<vector<int>> &table) { //플로이드 워셜
    for (int k = 1; k <= n; k++) { //집하장 수만큼
        for (int i = 1; i <= n; i++) { //집하장 수만큼
            for (int j = 1; j <= n; j++) { //집하장 수만큼
                int new_dist = graph[i][k] + graph[k][j]; //중간에 k를 거쳐서 i에서 j로 감
                if (new_dist < graph[i][j]) { //i->k->j가 i->j보다 빠른 경로라면
                    graph[i][j] = new_dist; //경로 갱신
                    table[i][j] = table[i][k]; // 경로 갱신
                }
            }
        }
    }
}

/**
 * graph : 플로이드-워셜 결과 행렬 그래프
 * table : 경로표. table[i][j] = i->j로 가기 위해 제일 먼저 거쳐야 하는 정점
 *
 * 1. i->j의 중간 경로를 i로 초기화
 * 2. i->k->j가 i->j보다 짧다면 i->j의 중간 경로를 i->k의 중간 경로(table[i][k])로 갱신
 *    k로 갱신하는게 아니라 table[i][k]로 갱신하는 이유는?
 *    만약 i->k의 경로가 i->t->k라면 최종 경로는 i->t->k->j
 *    바로 k로 갱신하면 t를 놓칠 수 있기 때문에 table[i][k]로 갱신
 *    line 16을 table[i][j] = k로 바꾸면 결과가 어떻게 되는지 확인해보세요
 */
int main() {
    int n, m, s, d, c; //집하장수, 경로개수, 두 집하장 번호, 오가는 시간

    //입력
    cin >> n >> m;// 집하장 수, 경로 개수 입력
    vector<vector<int>> graph(n+1, vector<int>(n+1, INF)); //플로이드 결과 행렬 저장
    vector<vector<int>> table(n+1, vector<int>(n+1, 0)); //거쳐야하는 경로 저장
    for (int i = 1; i <= n; i++) //집하장 수 만큼
        graph[i][i] = 0; //0으로 초기화

    while (m--) { //무방향 그래프
        cin >> s >> d >> c; // 두 집하장 번호와 시간 입력
        //간선 정보
        graph[s][d] = graph[d][s] = c; //정보 저장

        //경로 정보
        table[s][d] = d; //경로 정보 저장
        table[d][s] = s;//경로 정보 저장
    }

    //연산
    floydWarshall(n, graph, table); //플로이드 워셜 연산

    //출력
    for (int i = 1; i <= n; i++) { //집하장 수만큼
        for (int j = 1; j <= n; j++) { //집하장 수 만큼
            if (i == j) // 같은곳으로가는거면
                cout << "- "; //- 표시
            else
                cout << table[i][j] << ' '; //그렇지 않으면 경로표 출력
        }
        cout << '\n'; //줄바꿈
    }
}
