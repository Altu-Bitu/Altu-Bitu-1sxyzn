#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> matrix; //행렬 담을 벡터

int divide(int row, int col, int size) { //분할 정복!
    //Conquer : n의 크기가 1
    if (size == 1) //하나 남으면
        return matrix[row][col]; //남은 수 리턴

    //Divide : 행렬 4등분 하기
    int next_size = size / 2; // 4등분 하기
    vector<int> sub_problem; // 등분 낸 행렬 정보 저장
    for (int i = 0; i <= next_size; i += next_size) { //등분 낸 만큼
        for (int j = 0; j <= next_size; j += next_size) //등분 낸 만큼
            sub_problem.push_back(divide(row + i, col + j, next_size)); // sub_problem에 저장
    }

    //Combine : 두번째로 큰 수만 남기기
    sort(sub_problem.begin(), sub_problem.end(), greater<>()); //내림차순으로 정렬
    return sub_problem[1]; // 행렬의 가장 큰 값 리턴
}

/**
 * 1. 행렬 4등분 하기
 * 2. 행렬의 크기가 1이라면 원소 리턴
 * 3. 리턴된 원소 4개 모아서 두번째로 큰 수만 리턴
 */
int main() {
    int n; //n * n 행렬을 위한 n 입력

    //입력
    cin >> n; // 행렬 크기 입력
    matrix.assign(n, vector<int>(n)); // 행렬 초기화
    for (int i = 0; i < n; i++) { // n * n 행렬 입력을 위한 이중 반복문
        for (int j = 0; j < n; j++) //행렬 입력 위한 반복문
            cin >> matrix[i][j]; //행렬에 값 입력
    }

    //연산 & 출력
    cout << divide(0, 0, n); // 마지막에 남은 수 출력
} 
