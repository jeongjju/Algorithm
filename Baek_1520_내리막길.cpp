#include<iostream>
using namespace std;
int M;
int N;
int map[501][501];
int dp[500][500];
int DFS(int x, int y);
int main(int argc, char* argv[]) {
	// 세로의 크기를 입력받는다
	cin >> M;

	// 가로의 크기를 입력받는다
	cin >> N;

	// 지도를 입력받는다.
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	// 경로체크지도를 초기화 한다.
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = -1;
		}
	}
	DFS(N - 1, M - 1);
	cout << dp[M - 1][N - 1] << endl;

	return 0;
}
int DFS(int x, int y) {
	if (dp[y][x] != -1) {
		return dp[y][x];
	}
	if (x == 0 && y == 0) {
		return 1;
	}
	dp[y][x] = 0;
	if (x < N - 1 && map[y][x] < map[y][x + 1]) {
		dp[y][x] = dp[y][x] + DFS(x + 1, y);
	}
	if (y < M - 1 && map[y][x] < map[y + 1][x]) {
		dp[y][x] = dp[y][x] + DFS(x, y + 1);
	}
	if (x > 0 && map[y][x] < map[y][x - 1]) {
		dp[y][x] = dp[y][x] + DFS(x - 1, y);
	}
	if (y > 0 && map[y][x] < map[y - 1][x]) {
		dp[y][x] = dp[y][x] + DFS(x, y - 1);
	}
	return dp[y][x];
}