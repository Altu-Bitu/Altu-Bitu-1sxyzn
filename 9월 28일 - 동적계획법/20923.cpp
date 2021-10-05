#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//그라운드에 있는 카드를 덱으로 옮기는 함수
void moveCard(deque<int> &deck, deque<int> &ground) { //카드 덱과 그라운드를 매개변수로..
    while (!ground.empty()) { //그라운드에 카드가 있다면
        deck.push_back(ground.back()); //덱에 카드 push
        ground.pop_back(); //그라운드 비우기
    }
}

//게임을 진행하는 함수
pair<int, int> playGame(int m, vector<deque<int>> &deck, vector<deque<int>> &ground) { //게임 진행 함수
    bool turn = false; //도도부터 시작

    while (m--) { //게임 진행 횟수 m을 카운트 해 나가기
        //이번 턴의 사람이 카드 뒤집어서 그라운드에 올려놓기
        int card = deck[turn].front(); //카드 덱의 카드를
        ground[turn].push_front(card); //그라운드에 push
        deck[turn].pop_front(); //그라운드에 올린 카드를, 카드 덱에서 pop

        //게임 진행 도중 둘 중 한 명의 덱에 있는 카드의 수가 0개가 되는 즉시 게임 종료
        if (deck[turn].empty()) //한명이라도 덱이 비면
            break; //함수 (게임) 종료

        //이번에 종을 칠 사람
        int bell = -1; //벨을 -1 초기화
        if (card == 5) //카드 넘버가 5면
            bell = 0; // 도도가 종을 침
        else if (!ground[0].empty() && !ground[1].empty() && (card + ground[!turn].front() == 5)) //카드 덱이 비어있지 않고 카드 넘버의 합이 5면 
            bell = 1; //수연이가 종을 침

        if (bell != -1) { //누군가가 종을 쳤다면
            moveCard(deck[bell], ground[!bell]); //상대방의 그라운드에 있는 더미를 자신의 덱 아래로 합치기
            moveCard(deck[bell], ground[bell]); //자기 그라운드에 있는 더미도 합치기
        }
        turn = !turn; //차례 바꾸기
    }
    return make_pair(deck[0].size(), deck[1].size()); //도도와 수연의 카드덱 수를 pair로 리턴
}

/**
 * 1. 카드 덱과 그라운드의 카드를 관리하기 위해 덱 사용
 * 2. 게임을 진행하던 도중 언제든지 누군가의 카드 덱이 비게되면 게임을 종료
 */
int main() { //메인함수
    int n, m, num1, num2; //카드 갯수, 게임 진행 횟수, 도도와 수연의 카드 넘버
    vector<deque<int>> deck(2), ground(2); //카드 덱, 그라운드 덱

    cin >> n >> m; //카드 갯수, 게임 진행 횟수 입력
    while (n--) { //카드 갯수 만큼 while문 돌기
        cin >> num1 >> num2; // 아래에 위치한 카드 넘버부터 맨위 카드 넘버까지 입력
        deck[0].push_front(num1); // 도도의 카드 덱에 push
        deck[1].push_front(num2); // 수연의 카드 덱에 push
    }

    pair<int, int> result = playGame(m, deck, ground); //result 라는 pair에 게임 결과 저장

    if (result.first == result.second) // 비긴경우
        cout << "dosu\n"; //dosu 출력
    else if (result.first > result.second) //도도의 승리일 경우
        cout << "do\n"; //do 출력
    else if (result.first < result.second) //수연의 승리일 경우
        cout << "su\n"; //su 출력
}
