#include<iostream>
#define NMAX 10
#define MMAX 8
using namespace std;

int N, M;
int changedMap[NMAX][MMAX];
int maxSafeZone; //0의 개수는 3보다 커야함
void Copy(int copied[NMAX][MMAX], int copying[NMAX][MMAX]);
bool Check(int x, int y);
void DFS(int x, int y);
int main(int argc, char* argv[]) {
	cin >> N;
	cin >> M;
	int map[NMAX][MMAX];
	int virusX[10], virusY[10];
	int k = 0;
	int beforSpreadVirusCount = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virusX[k] = j;
				virusY[k] = i;
				beforSpreadVirusCount++;
				k++;
			}
		}
	}
	int beforeOneWallMap[NMAX][MMAX], beforeTwoWallMap[NMAX][MMAX], beforThreeWallMap[NMAX][MMAX];
	int x1, x2, x3, y1, y2, y3;
	Copy(changedMap, map);
	Copy(beforeOneWallMap, changedMap);
	for (y1 = 0; y1 < N; y1++) {
		for (x1 = 0; x1 < M; x1++) {
			if (Check(x1, y1)) {
				if (x1 >= M) {
					x2 = 0;
					y2 = y1 + 1;
				}
				else {
					x2 = x1 + 1;
					y2 = y1;
				}
				Copy(beforeTwoWallMap, changedMap);
				for (y2; y2 < N; y2++) {
					for (x2; x2 < M; x2++) {
						if (Check(x2, y2)) {
							if (x2 >= M) {
								x3 = 0;
								y3 = y2 + 1;
							}
							else {
								x3 = x2 + 1;
								y3 = y2;
							}
							Copy(beforThreeWallMap, changedMap);
							for (y3; y3 < N; y3++) {
								for (x3; x3 < M; x3++) {
									if (Check(x3, y3)) {
										for (int i = 0; i < beforSpreadVirusCount; i++) {
											DFS(virusX[i], virusY[i]);
										}
										int safezone = 0;
										for (int i = 0; i < N; i++) {
											for (int j = 0; j < M; j++) {
												if (changedMap[i][j] == 0) {
													safezone++;
												}
											}
										}
										if (safezone > maxSafeZone) {
											maxSafeZone = safezone;
										}
										Copy(changedMap, beforThreeWallMap);
									}
								}
								x3 = 0;
							}
							Copy(changedMap, beforeTwoWallMap);
						}
					}
					x2 = 0;
				}
				Copy(changedMap, beforeOneWallMap);
			}
		}
		x1 = 0;
	}
	cout << maxSafeZone << endl;
	return 0;
}
void Copy(int copied[NMAX][MMAX], int copying[NMAX][MMAX]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copied[i][j] = copying[i][j];
		}
	}
}
bool Check(int x, int y) {
	if (changedMap[y][x] == 0) {
		changedMap[y][x] = 1;
		return true;
	}
	return false;
}
void DFS(int x, int y) {
	changedMap[y][x] = 2;
	if (x < M - 1 && changedMap[y][x + 1] == 0) {
		DFS(x + 1, y);
	}
	if (y < N - 1 && changedMap[y + 1][x] == 0) {
		DFS(x, y + 1);
	}
	if (x > 0 && changedMap[y][x - 1] == 0) {
		DFS(x - 1, y);
	}
	if (y > 0 && changedMap[y - 1][x] == 0) {
		DFS(x, y - 1);
	}
}