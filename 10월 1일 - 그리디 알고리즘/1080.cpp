#include <iostream>
#include <vector>

using namespace std;

//부분 행렬 원소 뒤집는 함수
void reverseMtx(int row, int col, vector<string> &matrix_a) { //행,렬 과 a 행렬 전달해줌
    for (int i = row; i < row + 3; i++) { // 3*3 크기만큼 원소바꾸기
        for (int j = col; j < col + 3; j++) { // 3*3 크기만큼 원소바꾸기
            if (matrix_a[i][j] == '1') //원래 원소가 1이면
                matrix_a[i][j] = '0'; // 0으로 바꾸기
            else //원래 원소가 0이면
                matrix_a[i][j] = '1'; //1로 바꾸기
        }
    }
}

//마지막으로 A == B인지 확인하는 함수
int isPossible(int n, int m, vector<string> &matrix_a, vector<string> &matrix_b) { //행렬의 크기와 두 행렬을 전달해줌 
    for (int i = 0; i < n; i++) { // n*m행렬 전체 탐색
        for (int j = 0; j < m; j++) { //n*m행렬 전체 탐색
            if (matrix_a[i][j] != matrix_b[i][j]) //만약 같지 않은 원소가 하나라도 있으면
                return false; //false를 리턴
        }
    }

    return true; //a행렬과 b행렬이 모두 같으면 ture 리턴
}

/**
 * (0, 0) 인덱스부터 부분행렬을 만들 수 있는 마지막 인덱스까지 검사하며 그리디하게 푸는 문제
 * A, B 행렬의 현재 인덱스 값이 서로 다르다면 A 행렬에서 현재 인덱스로 '시작'하는 3x3 크기만큼의 부분 행렬 원소 뒤집기
 * 검사가 모두 끝난 후, A와 B가 서로 다르다면 바꿀 수 없는 경우임
 * !주의! 입력이 공백없이 주어지므로 string으로 받음
 */

int main() {
    int n, m; //행렬의 크기

    //입력
    cin >> n >> m; //행렬의 크기 입력
    vector<string> matrix_a(n); //a행렬 담을 벡터
    vector<string> matrix_b(n); //b행렬 담을 벡터
    for (int i = 0; i < n; i++) //n 크기 만큼
        cin >> matrix_a[i]; //한 줄씩 행렬 입력받기
 
    for (int i = 0; i < n; i++) //n 크기 만큼
        cin >> matrix_b[i]; //한 줄씩 행렬 입력받기

    //연산
    int ans = 0; // 행렬 바꾸는데 필요한 연산의 최솟값 담는 변수
    for (int i = 0; i <= n - 3; i++) { //3*3 크기의 부분행렬을 뒤집어야 하므로 n-3까지
        for (int j = 0; j <= m - 3; j++) { //마찬가지 이유로 m-3까지 반복문
            if (matrix_a[i][j] != matrix_b[i][j]) { //(i, j)원소가 서로 다르다면
                reverseMtx(i, j, matrix_a); //부분 행렬 원소 뒤집기
                ans++; //뒤집은 횟수 
            }
        }
    }

    //출력
    if (!isPossible(n, m, matrix_a, matrix_b)) //만약 A를 B로 바꿀 수 없다면
        ans = -1; //-1 출력하기위해 변수에 담기
    cout << ans; // -1 혹은 행렬 변환을 위한 연산의 최솟값 출력

    return 0; //프로그램 종료
}
