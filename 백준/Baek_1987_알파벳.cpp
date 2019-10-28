#include<iostream>
#include<cstring>
#define MAX 26
#define CONVERT 65
int R;
int C;
char board[21][21];
int maxPath;
using namespace std;
int DFS(int x, int y, int alphabat[MAX], int path);
int main(int argc, char* argv[]) {
	// 세로
	cin >> R;
	// 가로
	cin >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}
	maxPath = 1;
	int alphabat[MAX];
	fill_n(alphabat, MAX, 0);
	DFS(0, 0, alphabat, 0);
	cout << maxPath << endl;
	return 0;
}
int DFS(int x, int y, int alphabat[MAX], int path) {
	path++;
	alphabat[board[y][x] - CONVERT] = 1;
	if (x < C - 1 && alphabat[board[y][x + 1] - CONVERT] != 1) {
		int temp[MAX];
		memcpy(temp, alphabat, MAX * sizeof(int));
		int previousPath = DFS(x + 1, y, temp, path);
		if (previousPath > maxPath) {
			maxPath = previousPath;
		}
	}
	if (y < R - 1 && alphabat[board[y + 1][x] - CONVERT] != 1) {
		int temp[MAX];
		memcpy(temp, alphabat, MAX * sizeof(int));
		int previousPath = DFS(x, y + 1, temp, path);
		if (previousPath > maxPath) {
			maxPath = previousPath;
		}
	}
	if (x >0 && alphabat[board[y][x - 1] - CONVERT] != 1) {
		int temp[MAX];
		memcpy(temp, alphabat, MAX * sizeof(int));
		int previousPath = DFS(x - 1, y, temp, path);
		if (previousPath > maxPath) {
			maxPath = previousPath;
		}
	}
	if (y >0 && alphabat[board[y - 1][x] - CONVERT] != 1) {
		int temp[MAX];
		memcpy(temp, alphabat, MAX * sizeof(int));
		int previousPath = DFS(x, y - 1, temp, path);
		if (previousPath > maxPath) {
			maxPath = previousPath;
		}
	}
	return path;
}


