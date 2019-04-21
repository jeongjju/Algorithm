#include<iostream>
using namespace std;
int M;
int N;
int map[501][501];
int dp[500][500];
int DFS(int x, int y);
int main(int argc, char* argv[]) {
	// ������ ũ�⸦ �Է¹޴´�
	cin >> M;

	// ������ ũ�⸦ �Է¹޴´�
	cin >> N;

	// ������ �Է¹޴´�.
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	// ���üũ������ �ʱ�ȭ �Ѵ�.
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