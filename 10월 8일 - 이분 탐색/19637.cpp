#include <iostream>
#include <map>

using namespace std;

/**
 * 모든 캐릭터와 칭호를 매칭하는 브루트 포스를 사용하기엔 최대 연산 횟수 10^5 * 10^5 -> 100억!
 * 특정 전투력 '이하'까지 해당하는 칭호를 받을 수 있음
 * -> 이분 탐색
 *
 * 맵과 셋은 원소를 정렬된 상태로 저장하기 때문에 알고리즘 헤더 없이 자체적으로 이분 탐색 함수를 사용할 수 있음
 */
int main() { //메인 함수
    ios::sync_with_stdio(false); //입출력 속도 향상을 위해
    cin.tie(NULL); //입력 속도 향상

    map<int, string> title; //칭호와 그 칭호의 전투력 상한값

    int n, m, power; // n은 칭호의 갯수, weak normal 등 // m은 캐릭터 갯수 //power는 입력용 임시 변수
    string name; // 칭호 입력받을 갯수

    //입력
    cin >> n >> m; // 입력
    while (n--) { //칭호와 상한값 입력받기
        cin >> name >> power; // 칭호 >> 상한값
        if (title[power].empty()) //해당 상한값을 갖는 map이 비어있으면
            title[power] = name; // 칭호와 상한값 입력
    }

    //출력
    while (m--) { //캐릭터 갯수만큼 입,출력
        cin >> power; //입력 받기
        cout << title.lower_bound(power)->second << '\n'; // 전투력에 따라 상한값 확인해서 출력
    }
}
