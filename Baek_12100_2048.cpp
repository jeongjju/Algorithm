#include<iostream>
#define MAX 20
using namespace std;
int N;
int maxBlock;
int maximum;
int board[MAX][MAX];

void DFS(int currentBoard[MAX][MAX], int previousBoard[MAX][MAX], int move);
void Copy(int copied[MAX][MAX], int coping[MAX][MAX]);
int main(int argc, char* argv[]) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			maximum += board[i][j];
		}
	}
	int previousBoard[MAX][MAX];
	for (int i = 0; i < MAX; i++) {
		fill_n(previousBoard[i], MAX, 0);
	}
	DFS(board, previousBoard, 0);
	cout << maxBlock << endl;
	return 0;
}
void Copy(int copied[MAX][MAX], int coping[MAX][MAX]) {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			copied[i][j] = coping[i][j];
		}
	}
}
void DFS(int currentBoard[MAX][MAX], int previousBoard[MAX][MAX], int move) {
	int sameCount = 0;
	int previous;
	int previousIndex;
	if (move > 5) {
		return;
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (currentBoard[y][x] >= maxBlock) {
				maxBlock = currentBoard[y][x];
				if (maxBlock >= maximum) {
					maxBlock = maximum;
					return;
				}
			}
			if (previousBoard[y][x] == currentBoard[y][x]) {
				sameCount++;
			}
		}
	}
	if (sameCount == N*N) {
		return;
	}
	int tempPreviousBoard[MAX][MAX];
	// current -> temp
	Copy(tempPreviousBoard, currentBoard);

	// 상
	for (int x = 0; x < N; x++) {
		// 위의 값 적기
		previous = currentBoard[0][x];
		// 위의 값 위치
		previousIndex = 0;
		// 위의 값이 결합 안한상태 적기
		bool combine = false;
		for (int y = 1; y < N; y++) {
			// 좌표 값이 0이 아니면
			if (currentBoard[y][x] != 0) {
				// 위의 값이 0이 아니면
				if (previous != 0) {
					// 위의 숫자와 같고 결합안한 상태면
					if (currentBoard[y][x] == previous && combine == false) {
						// 위의 숫자와 현재 값 결합하기
						currentBoard[previousIndex][x] = currentBoard[y][x] + previous;
						// 현재 값에 0 적기
						currentBoard[y][x] = 0;
						// 위의 값 결합한 값으로 바꾸기
						previous = currentBoard[previousIndex][x];
						// 결합 했음 적기
						combine = true;
					}
					// 위의 숫자와 같지않으면
					else {
						// 위의 값 다음 위치랑 현재 위치랑 같지 않으면
						if (previousIndex + 1 != y) {
							// 위의 값 다음 위치에 적기
							currentBoard[previousIndex + 1][x] = currentBoard[y][x];
							// 현재 값에 0 적기
							currentBoard[y][x] = 0;
						}
						// 위의 값 바꾸기
						previous = currentBoard[previousIndex + 1][x];
						// 위의 값 위치 바꾸기(무조건 위의 값 뒤에)
						previousIndex++;
						// 결합 안함 적기
						combine = false;
					}
				}
				// 위의 값이 0이면
				else {
					// 첫번째 위치에 현재 값 적기
					currentBoard[0][x] = currentBoard[y][x];
					// 현재 값에 0 적기
					currentBoard[y][x] = 0;
					// 위의 값 적기
					previous = currentBoard[0][x];
					// 위의 값 위치 적기 (첫번째 위치)
					previousIndex = 0;
				}
			}
		}
	}
	DFS(currentBoard, tempPreviousBoard, move + 1);

	// temp -> current 
	Copy(currentBoard, tempPreviousBoard);
	// 우
	for (int y = 0; y < N; y++) {
		previous = currentBoard[y][N - 1];
		previousIndex = N - 1;
		bool combine = false;
		for (int x = N - 2; x >= 0; x--) {
			if (currentBoard[y][x] != 0) {
				if (previous != 0) {
					if (currentBoard[y][x] == previous && combine == false) {
						currentBoard[y][previousIndex] = currentBoard[y][x] + previous;
						currentBoard[y][x] = 0;
						previous = currentBoard[y][previousIndex];
						combine = true;
					}
					else {
						if (previousIndex - 1 != x) {
							currentBoard[y][previousIndex - 1] = currentBoard[y][x];
							currentBoard[y][x] = 0;
						}
						previous = currentBoard[y][previousIndex - 1];
						previousIndex--;
						combine = false;
					}
				}
				else {
					currentBoard[y][N - 1] = currentBoard[y][x];
					currentBoard[y][x] = 0;
					previous = currentBoard[y][N - 1];
					previousIndex = N - 1;
				}
			}
		}
	}
	DFS(currentBoard, tempPreviousBoard, move + 1);

	/*
	4
	2 2 0 0
	0 0 4 0
	0 0 0 4
	16 8 0 0
	하 부터 시작하도록
	*/

	// temp -> current
	Copy(currentBoard, tempPreviousBoard);
	// 하
	for (int x = 0; x < N; x++) {
		previous = currentBoard[N - 1][x];
		previousIndex = N - 1;
		bool combine = false;
		for (int y = N - 2; y >= 0; y--) {
			if (currentBoard[y][x] != 0) {
				if (previous != 0) {
					if (currentBoard[y][x] == previous && combine == false) {
						currentBoard[previousIndex][x] = currentBoard[y][x] + previous;
						currentBoard[y][x] = 0;
						previous = currentBoard[previousIndex][x];
						combine = true;
					}
					else {
						if (previousIndex - 1 != y) {
							currentBoard[previousIndex - 1][x] = currentBoard[y][x];
							currentBoard[y][x] = 0;
						}
						previous = currentBoard[previousIndex - 1][x];
						previousIndex--;
						combine = false;
					}
				}
				else {
					currentBoard[N - 1][x] = currentBoard[y][x];
					currentBoard[y][x] = 0;
					previous = currentBoard[N - 1][x];
					previousIndex = N - 1;
				}
			}
		}
	}
	DFS(currentBoard, tempPreviousBoard, move + 1);

	// temp -> current
	Copy(currentBoard, tempPreviousBoard);
	//좌
	for (int y = 0; y < N; y++) {
		previous = currentBoard[y][0];
		previousIndex = 0;

		bool combine = false;
		for (int x = 1; x < N; x++) {
			if (currentBoard[y][x] != 0) {
				if (previous != 0) {
					if (currentBoard[y][x] == previous && combine == false) {
						currentBoard[y][previousIndex] = currentBoard[y][x] + previous;
						currentBoard[y][x] = 0;
						previous = currentBoard[y][previousIndex];
						combine = true;
					}
					else {
						if (previousIndex + 1 != x) {
							currentBoard[y][previousIndex + 1] = currentBoard[y][x];
							currentBoard[y][x] = 0;
						}
						previous = currentBoard[y][previousIndex + 1];
						previousIndex++;
						combine = false;
					}
				}
				else {
					currentBoard[y][0] = currentBoard[y][x];
					currentBoard[y][x] = 0;
					previous = currentBoard[y][0];
					previousIndex = 0;
				}
			}
		}
	}
	DFS(currentBoard, tempPreviousBoard, move + 1);
}
