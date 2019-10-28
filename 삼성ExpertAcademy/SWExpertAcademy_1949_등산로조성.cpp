#include<iostream>
using namespace std;
int maxPath, N;
int map[8][8];
int originalMap[8][8];
int visited[8][8];
void DFS(int x, int y, int k, int path);
void Init(int map[8][8]);
void Copy(int copiedMap[8][8], int copingMap[8][8]);
int main(int argc, char* argv[]) {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int k;
		int highest = 0;
		cin >> N;
		cin >> k;
		maxPath = -1;
		Init(map);
		Init(visited);
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				cin >> map[y][x];
				if (map[y][x] > highest) {
					highest = map[y][x];
				}
			}
		}
		for (k; k > 0; k--) {
			for (int y = 0; y < N; y++) {
				for (int x = 0; x < N; x++) {
					if (map[y][x] == highest) {
						DFS(x, y, k, 1);
					}
				}
			}
			Init(visited);
		}
		cout << "#" << i + 1 << " " << maxPath << endl;
	}
	return 0;
}
void DFS(int x, int y, int k, int path) {
	visited[y][x] = 1;
	// 우측
	if (visited[y][x + 1] != 1 && map[y][x + 1] < map[y][x] && x + 1<N) {
		DFS(x + 1, y, k, path + 1);
	}
	else {
		if (k != 0 && visited[y][x + 1] != 1 && map[y][x + 1] - k < map[y][x] && x + 1<N) {
			Copy(originalMap, map);
			map[y][x + 1] = map[y][x + 1] - k;
			DFS(x + 1, y, 0, path + 1);
			Copy(map, originalMap);
		}
	}
	// 아래
	if (visited[y + 1][x] != 1 && map[y + 1][x] < map[y][x] && y + 1<N) {
		DFS(x, y + 1, k, path + 1);
	}
	else {
		if (k != 0 && visited[y + 1][x] != 1 && map[y + 1][x] - k < map[y][x] && y + 1<N) {
			Copy(originalMap, map);
			map[y + 1][x] = map[y + 1][x] - k;
			DFS(x, y + 1, 0, path + 1);
			Copy(map, originalMap);
		}
	}
	// 좌측
	if (visited[y][x - 1] != 1 && map[y][x - 1] < map[y][x] && x - 1 >= 0) {
		DFS(x - 1, y, k, path + 1);
	}
	else {
		if (k != 0 && visited[y][x - 1] != 1 && map[y][x - 1] - k < map[y][x] && x - 1 >= 0) {
			Copy(originalMap, map);
			map[y][x - 1] = map[y][x - 1] - k;
			DFS(x - 1, y, 0, path + 1);
			Copy(map, originalMap);
		}
	}
	// 위측
	if (visited[y - 1][x] != 1 && map[y - 1][x] < map[y][x] && y - 1 >= 0) {
		DFS(x, y - 1, k, path + 1);
	}
	else {
		if (k != 0 && visited[y - 1][x] != 1 && map[y - 1][x] - k < map[y][x] && y - 1 >= 0) {
			Copy(originalMap, map);
			map[y - 1][x] = map[y - 1][x] - k;
			DFS(x, y - 1, 0, path + 1);
			Copy(map, originalMap);
		}
	}
	visited[y][x] = 0;
	if (path > maxPath) {
		maxPath = path;

	}
}

void Init(int map[8][8]) {
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			map[y][x] = 0;
		}
	}
}

void Copy(int copiedMap[8][8], int copingMap[8][8]) {
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			copiedMap[y][x] = copingMap[y][x];
		}
	}

}

