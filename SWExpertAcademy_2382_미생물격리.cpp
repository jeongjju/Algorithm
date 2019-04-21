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
		// M��ŭ �ݺ��Ѵ�
		for (int i = 0; i < M; i++) {
			// N��ŭ �ݺ��Ѵ�
			for (int y = 0; y < N; y++) {
				// N��ŭ �ݺ��Ѵ�
				for (int x = 0; x < N; x++) {
					if (x == 0 || x == N - 1 || y == 0 || y == N - 1) {
						DeclineMove(x, y);
					}
					else {
						Move(x, y);
					}
				}
			}
			// tempMap�� map�� �ű�� tempMap �ʱ�ȭ
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
	// ������ �ش� ��ġ�� ������ Ȯ��
	if (map[y - 1][x].position == 2) {
		tempMap[y][x].number = map[y - 1][x].number;
		maxMap.number = map[y - 1][x].number;
		tempMap[y][x].position = map[y - 1][x].position;
		maxMap.position = map[y - 1][x].position;
	}
	// �Ʒ����� �ش� ��ġ�� ������ Ȯ��
	if (map[y + 1][x].position == 1) {
		// ���̸� tempMap�� �̻������� �ִ��� Ȯ��
		if (tempMap[y][x].number > 0) {
			// �Ʒ����� �ش� ��ġ�� ���� �̻������� ���� ũ�ٸ�
			if (map[y + 1][x].number > maxMap.number) {
				// �Ʒ����� �ش� ��ġ�� ���� �̻����� ��ġ�� �ٲ۴�.
				tempMap[y][x].position = map[y + 1][x].position;
				// �Ʒ����� �ش� ��ġ�� ���� �̻������� ���� ū���� �ٲ۴�.
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
	// ���ʿ��� �ش� ��ġ�� ������ Ȯ��
	if (map[y][x - 1].position == 4) {
		// ���̸� tempMap�� �̻������� �ִ��� Ȯ��
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

	// �����ʿ��� �ش� ��ġ�� ������ Ȯ��
	if (map[y][x + 1].position == 3) {
		// ���̸� tempMap�� �̻������� �ִ��� Ȯ��
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
	// ������ �ش� ��ġ�� ������ Ȯ��
	if (map[y - 1][x].position == 2) {
		tempMap[y][x].number = map[y - 1][x].number / 2;
		tempMap[y][x].position = 1;
		return;
	}
	// �Ʒ����� �ش� ��ġ�� ������ Ȯ��
	if (map[y + 1][x].position == 1) {
		tempMap[y][x].number = map[y + 1][x].number / 2;
		tempMap[y][x].position = 2;
		return;
	}
	// ���ʿ��� �ش� ��ġ�� ������ Ȯ��
	if (map[y][x - 1].position == 4) {
		tempMap[y][x].number = map[y][x - 1].number / 2;
		tempMap[y][x].position = 3;
		return;
	}
	// �����ʿ��� �ش� ��ġ�� ������ Ȯ��
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