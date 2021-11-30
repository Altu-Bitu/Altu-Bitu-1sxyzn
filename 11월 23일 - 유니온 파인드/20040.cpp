#include <iostream>
#include <vector>

using namespace std;

vector<int> parent; // 집합

int findParent(int node) {//Find 연산
    if (parent[node] < 0) //루트 정점
        return node; //루트를 리턴
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

bool unionInput(int x, int y) { //Union 연산
    int xp = findParent(x); // 두 집합 x, y
    int yp = findParent(y);// 두 집합 x, y

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return false; //유니온 불가, false리턴
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp]; //union하기
        parent[yp] = xp; //xp를 yp에 union
    } else { //새로운 루트 yp
        parent[yp] += parent[xp];//union하기
        parent[xp] = yp;//yp를 xp에 union
    }
    return true; //유니온 하고 true 리턴
}

/**
 * 사이클이 발생한 순간 = 같은 집합에 있는 원소 두 개를 유니온하려 할 때
 * unionInput 함수의 반환형을 bool로 선언하여 cycle이 생성되는 순간 발견하기
 */
int main() {
    int n, m, x, y; //점의 갯수, 진행된 차례의 수, 선택한 두 점의 번호

    //입력
    cin >> n >> m; //점의 갯수와 진행된 차례의 수 입력
    parent.assign(n, -1); // 다 -1로 초기화
    for (int i = 0; i < m; i++) { //차례의 수 만큼
        cin >> x >> y; // 해당 플레이어가 선택한 두 점의 번호 입력

        //연산 & 출력
        if (!unionInput(x, y)) { //유니온 할 수 없음 = 사이클이 생성됨
            cout << i + 1; // 사이클이 첨 만들어진 차례의 번호 출력
            return 0; //프로그램 종료
        }
    }
    cout << 0; //차례가 끝났는데 종료되지 않으면 0 출력
}
