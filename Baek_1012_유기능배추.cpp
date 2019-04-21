#include<iostream>
using namespace std;
int M;
int N;
int field[50][50];
int minWorm;
int initialX;
int initialY;
void DFS(int x, int y);
int main(int argc, char* argv[]) {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> M;
		cin >> N;
		int k;
		cin >> k;
		int x;
		int y;
		for (int i = 0; i < k; i++) {
			cin >> x;
			cin >> y;
			field[y][x] = 1;
		}
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				initialX = x;
				initialY = y;
				DFS(x, y);
			}
		}
		printf("%d\n", minWorm);
		minWorm = 0;
	}
	return 0;
}

void DFS(int x, int y) {
	if (field[y][x] == 0) {
		return;
	}
	if (x == initialX && y == initialY) {
		minWorm++;
	}
	field[y][x] = 0;
	if (x < M - 1 && field[y][x + 1]>0) {
		DFS(x + 1, y);
	}
	if (y < N - 1 && field[y + 1][x]>0) {
		DFS(x, y + 1);
	}
	if (x > 0 && field[y][x - 1] > 0) {
		DFS(x - 1, y);
	}
	if (y > 0 && field[y - 1][x] > 0) {
		DFS(x, y - 1);
	}
}