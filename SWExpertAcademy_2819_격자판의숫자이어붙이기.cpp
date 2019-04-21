#include<iostream>
#include<string>
#define MAX 10000000
using namespace std;
int board[4][4];
int sevenCount;
void DFS(int x, int y, int l, int sevenDigitNumber);
bool visited[MAX];
int main(int argc, char* argv[]) {

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {

		sevenCount = 0;
		for (int i = 0; i<MAX; i++) {
			visited[i] = 0;
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> board[i][j];
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				DFS(j, i, 1, board[i][j]);
			}
		}
		cout << "#" << i + 1 << " " << sevenCount << endl;

	}

}
void DFS(int x, int y, int l, int sevenDigitNumber) {
	if (l > 6) {
		if (visited[sevenDigitNumber] != 1) {
			visited[sevenDigitNumber] = 1;
			sevenCount++;
		}
		return;
	}
	if (x + 1 < 4) {
		DFS(x + 1, y, l + 1, sevenDigitNumber * 10 + board[y][x + 1]);
	}
	if (y + 1 < 4) {
		DFS(x, y + 1, l + 1, sevenDigitNumber * 10 + board[y + 1][x]);
	}
	if (x - 1 > -1) {
		DFS(x - 1, y, l + 1, sevenDigitNumber * 10 + board[y][x - 1]);
	}
	if (y - 1 > -1) {
		DFS(x, y - 1, l + 1, sevenDigitNumber * 10 + board[y - 1][x]);
	}
}
