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

	// ��
	for (int x = 0; x < N; x++) {
		// ���� �� ����
		previous = currentBoard[0][x];
		// ���� �� ��ġ
		previousIndex = 0;
		// ���� ���� ���� ���ѻ��� ����
		bool combine = false;
		for (int y = 1; y < N; y++) {
			// ��ǥ ���� 0�� �ƴϸ�
			if (currentBoard[y][x] != 0) {
				// ���� ���� 0�� �ƴϸ�
				if (previous != 0) {
					// ���� ���ڿ� ���� ���վ��� ���¸�
					if (currentBoard[y][x] == previous && combine == false) {
						// ���� ���ڿ� ���� �� �����ϱ�
						currentBoard[previousIndex][x] = currentBoard[y][x] + previous;
						// ���� ���� 0 ����
						currentBoard[y][x] = 0;
						// ���� �� ������ ������ �ٲٱ�
						previous = currentBoard[previousIndex][x];
						// ���� ���� ����
						combine = true;
					}
					// ���� ���ڿ� ����������
					else {
						// ���� �� ���� ��ġ�� ���� ��ġ�� ���� ������
						if (previousIndex + 1 != y) {
							// ���� �� ���� ��ġ�� ����
							currentBoard[previousIndex + 1][x] = currentBoard[y][x];
							// ���� ���� 0 ����
							currentBoard[y][x] = 0;
						}
						// ���� �� �ٲٱ�
						previous = currentBoard[previousIndex + 1][x];
						// ���� �� ��ġ �ٲٱ�(������ ���� �� �ڿ�)
						previousIndex++;
						// ���� ���� ����
						combine = false;
					}
				}
				// ���� ���� 0�̸�
				else {
					// ù��° ��ġ�� ���� �� ����
					currentBoard[0][x] = currentBoard[y][x];
					// ���� ���� 0 ����
					currentBoard[y][x] = 0;
					// ���� �� ����
					previous = currentBoard[0][x];
					// ���� �� ��ġ ���� (ù��° ��ġ)
					previousIndex = 0;
				}
			}
		}
	}
	DFS(currentBoard, tempPreviousBoard, move + 1);

	// temp -> current 
	Copy(currentBoard, tempPreviousBoard);
	// ��
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
	�� ���� �����ϵ���
	*/

	// temp -> current
	Copy(currentBoard, tempPreviousBoard);
	// ��
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
	//��
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
