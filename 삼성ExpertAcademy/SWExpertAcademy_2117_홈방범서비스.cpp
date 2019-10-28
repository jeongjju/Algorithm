#include<iostream>
using namespace std;
int N, M, maxHouseCount;
int serviceCosts[21];
int map[20][20];
void Calc(int x, int y, int k);
int Path(int x, int y, int x1, int y1);
int main(int argc, char *argv[]) {
	// 운영 비용 구함
	for (int i = 1; i <= 21; i++) {
		serviceCosts[i] = (i*i) + ((i - 1)*(i - 1));
	}
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				cin >> map[y][x];
			}
		}
		maxHouseCount = 0;
		for (int k = 1; k <= N + 1; k++) {
			for (int y = 0; y < N; y++) {
				for (int x = 0; x < N; x++) {
					Calc(x, y, k);
				}
			}
		}
		cout << "#" << t + 1 << " " << maxHouseCount << endl;
	}
	return 0;
}
void Calc(int x, int y, int k) {
	int houseCount = 0;
	for (int y1 = 0; y1 < N; y1++) {
		for (int x1 = 0; x1 < N; x1++) {
			if (Path(x, y, x1, y1) < k && map[y1][x1] == 1) {
				houseCount++;
			}
		}
	}
	if (houseCount > 0 && houseCount*M - serviceCosts[k] >= 0) {
		if (houseCount > maxHouseCount) {
			maxHouseCount = houseCount;
		}
	}
}

int Path(int x, int y, int x1, int y1) {
	int xLength = x - x1;
	int yLength = y - y1;
	if (xLength < 0) {
		xLength = xLength*-1;
	}
	if (yLength < 0) {
		yLength = yLength*-1;
	}
	return xLength + yLength;
}