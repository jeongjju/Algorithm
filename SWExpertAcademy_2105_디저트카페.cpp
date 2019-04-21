#include <iostream>
using namespace std;
int visited[101];
int map[20][20];
int N, maxLength;
void DFS(int x, int y, int rightBottomLength, int leftBottomLength);
bool IsInside(int x, int y);
void Init();
void CopyVisited(int copiedVisited[101], int copying[101]);
int main(int agrc, char *argv[]) {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				cin >> map[y][x];
			}
		}
		for (int y = 0; y < N - 2; y++) {
			for (int x = 1; x < N - 1; x++) {
				DFS(x, y, 0, 0);
				// 방문표시 초기화
				for (int index = 0; index < 101; index++) {
					visited[index] = 0;
				}
			}
		}
		if (maxLength == 0) {
			maxLength = -1;
		}
		cout << "#" << i + 1 << " " << maxLength << endl;
		Init();
	}
	return 0;
}
void DFS(int x, int y, int rightBottomLength, int leftBottomLength) {
	visited[map[y][x]] = 1;
	// 우측 아래
	if (leftBottomLength == 0 && visited[map[y + 1][x + 1]] == 0 && IsInside(x + 1, y + 1)) {
		int tempVisited[101];
		CopyVisited(tempVisited, visited);
		DFS(x + 1, y + 1, rightBottomLength + 1, 0);
		CopyVisited(visited, tempVisited);
	}
	if (rightBottomLength >= 1) {
		// 좌측 아래
		if (visited[map[y + 1][x - 1]] == 0 && IsInside(x - 1, y + 1)) {
			int tempVisited2[101];
			CopyVisited(tempVisited2, visited);
			DFS(x - 1, y + 1, rightBottomLength, leftBottomLength + 1);
			CopyVisited(visited, tempVisited2);
		}
		if (leftBottomLength >= 1) {
			int leftUpLength = 0, rightUpLength = 0;
			int tempX = x, tempY = y;
			int i = 0;
			while (i < rightBottomLength) {
				tempX--;
				tempY--;
				if (visited[map[tempY][tempX]] == 0 && IsInside(tempX, tempY)) {
					visited[map[tempY][tempX]] = 1;
					leftUpLength++;
				}
				else {
					return;
				}
				i++;
			}
			if (leftUpLength >= 1) {
				int j = 0;
				while (j < leftBottomLength - 1) {
					tempX++;
					tempY--;
					if (visited[map[tempY][tempX]] == 0 && IsInside(tempX, tempY)) {
						visited[map[tempY][tempX]] = 1;
						rightUpLength++;
					}
					else {
						return;
					}
					j++;
				}
				if (maxLength < rightBottomLength + leftBottomLength + leftUpLength + rightUpLength + 1) {
					maxLength = rightBottomLength + leftBottomLength + leftUpLength + rightUpLength + 1;
				}
			}
		}

	}
}




bool IsInside(int x, int y) {
	return (x >= 0 && x < N) && (y >= 0 && y < N);
}

void Init() {
	for (int i = 0; i < 101; i++) {
		visited[i] = 0;
	}
	maxLength = 0;
}


void CopyVisited(int copiedVisited[101], int copying[101]) {
	for (int i = 0; i < 101; i++) {
		copiedVisited[i] = copying[i];
	}
}