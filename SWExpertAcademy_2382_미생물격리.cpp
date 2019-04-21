#include<iostream>
using namespace std;
struct Info {
	int number;
	int position;
};
int N, M, K, sum = 0;
Info map[100][100];
Info tempMap[100][100];
void Move(int x, int y);
void DeclineMove(int x, int y);
void Init();
int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++) {
			int x, y, n, p;
			cin >> y >> x >> n >> p;
			map[y][x].number = n;
			map[y][x].position = p;
		}
		// M만큼 반복한다
		for (int i = 0; i < M; i++) {
			// N만큼 반복한다
			for (int y = 0; y < N; y++) {
				// N만큼 반복한다
				for (int x = 0; x < N; x++) {
					if (x == 0 || x == N - 1 || y == 0 || y == N - 1) {
						DeclineMove(x, y);
					}
					else {
						Move(x, y);
					}
				}
			}
			// tempMap을 map에 옮기고 tempMap 초기화
			for (int y = 0; y < N; y++) {
				for (int x = 0; x < N; x++) {
					map[y][x].number = tempMap[y][x].number;
					map[y][x].position = tempMap[y][x].position;
					sum += map[y][x].number;
					tempMap[y][x].number = 0;
					tempMap[y][x].position = 0;
				}
			}
			if (i != M - 1) {
				sum = 0;
			}
		}
		cout << "#" << t + 1 << " " << sum << endl;
		Init();

	}

	return 0;
}

void Move(int x, int y) {
	Info maxMap;
	// 위에서 해당 위치로 오는지 확인
	if (map[y - 1][x].position == 2) {
		tempMap[y][x].number = map[y - 1][x].number;
		maxMap.number = map[y - 1][x].number;
		tempMap[y][x].position = map[y - 1][x].position;
		maxMap.position = map[y - 1][x].position;
	}
	// 아래에서 해당 위치로 오는지 확인
	if (map[y + 1][x].position == 1) {
		// 참이면 tempMap에 미생물수가 있는지 확인
		if (tempMap[y][x].number > 0) {
			// 아래에서 해당 위치로 오는 미생물수가 가장 크다면
			if (map[y + 1][x].number > maxMap.number) {
				// 아래에서 해당 위치로 오는 미생물수 위치로 바꾼다.
				tempMap[y][x].position = map[y + 1][x].position;
				// 아래에서 해당 위치로 오는 미생물수를 가장 큰수로 바꾼다.
				maxMap.number = map[y + 1][x].number;
			}
			tempMap[y][x].number += map[y + 1][x].number;
		}
		else {
			tempMap[y][x].number = map[y + 1][x].number;
			maxMap.number = map[y + 1][x].number;
			tempMap[y][x].position = map[y + 1][x].position;
			maxMap.position = map[y + 1][x].position;
		}
	}
	// 왼쪽에서 해당 위치로 오는지 확인
	if (map[y][x - 1].position == 4) {
		// 참이면 tempMap에 미생물수가 있는지 확인
		if (tempMap[y][x].number > 0) {
			if (map[y][x - 1].number > maxMap.number) {
				tempMap[y][x].position = map[y][x - 1].position;
				maxMap.number = map[y][x - 1].number;
			}
			tempMap[y][x].number += map[y][x - 1].number;
		}
		else {
			tempMap[y][x].number = map[y][x - 1].number;
			maxMap.number = map[y][x - 1].number;
			tempMap[y][x].position = map[y][x - 1].position;
			maxMap.position = map[y][x - 1].position;
		}
	}

	// 오른쪽에서 해당 위치로 오는지 확인
	if (map[y][x + 1].position == 3) {
		// 참이면 tempMap에 미생물수가 있는지 확인
		if (tempMap[y][x].number > 0) {
			if (map[y][x + 1].number > maxMap.number) {
				tempMap[y][x].position = map[y][x + 1].position;
				maxMap.number = map[y][x + 1].number;
			}
			tempMap[y][x].number += map[y][x + 1].number;
		}
		else {
			tempMap[y][x].number = map[y][x + 1].number;
			maxMap.number = map[y][x + 1].number;
			tempMap[y][x].position = map[y][x + 1].position;
			maxMap.position = map[y][x + 1].position;
		}
	}
}

void DeclineMove(int x, int y) {
	// 위에서 해당 위치로 오는지 확인
	if (map[y - 1][x].position == 2) {
		tempMap[y][x].number = map[y - 1][x].number / 2;
		tempMap[y][x].position = 1;
		return;
	}
	// 아래에서 해당 위치로 오는지 확인
	if (map[y + 1][x].position == 1) {
		tempMap[y][x].number = map[y + 1][x].number / 2;
		tempMap[y][x].position = 2;
		return;
	}
	// 왼쪽에서 해당 위치로 오는지 확인
	if (map[y][x - 1].position == 4) {
		tempMap[y][x].number = map[y][x - 1].number / 2;
		tempMap[y][x].position = 3;
		return;
	}
	// 오른쪽에서 해당 위치로 오는지 확인
	if (map[y][x + 1].position == 3) {
		tempMap[y][x].number = map[y][x + 1].number / 2;
		tempMap[y][x].position = 4;
		return;
	}
}

void Init() {
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++)
		{
			map[y][x].number = 0;
			map[y][x].position = 0;
			tempMap[y][x].number = 0;
			tempMap[y][x].position = 0;
		}
	}
	N = 0;
	M = 0;
	K = 0;
	sum = 0;
}