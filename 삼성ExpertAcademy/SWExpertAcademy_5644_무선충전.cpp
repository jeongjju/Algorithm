#include<iostream>
#define N 11

using namespace std;
int AMoves[100];
int BMoves[100];
int BCInformations[8][4];
int A;
int Ax = 1;
int Ay = 1;
int Bx = 10;
int By = 10;
int map[8][N][N];
int cntMap[N][N];
void ChargeArea();
int Distance(int x1, int x2, int y1, int y2);
void Move(int APosition, int BPosition);
int ChangeCal();
void Init();
int main(int argc, char *argv[]) {
	int T, M;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> M >> A;
		for (int j = 0; j < M; j++) {
			cin >> AMoves[j];
		}
		for (int j = 0; j < M; j++) {
			cin >> BMoves[j];
		}
		for (int j = 0; j < A; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> BCInformations[j][k];
			}
		}
		int maxSum = 0;
		Init();
		// 맨처음 자리도 계산하기 이동시간 +1번 반복한다
		ChargeArea();
		Move(0, 0);
		maxSum += ChangeCal();
		for (int j = 0; j <M; j++) {
			Move(AMoves[j], BMoves[j]);
			maxSum += ChangeCal();
		}
		cout << "#" << i + 1 << " " << maxSum << endl;
	}
	return 0;
}
void ChargeArea() {
	for (int i = 0; i < A; i++) {
		for (int y = 1; y < N; y++) {
			for (int x = 1; x < N; x++) {
				if (BCInformations[i][2] >= Distance(BCInformations[i][0], x, BCInformations[i][1], y)) {
					map[i][y][x] = BCInformations[i][3];
					cntMap[y][x] += 1;
				}
			}
		}
	}
}

int Distance(int x1, int x2, int y1, int y2) {
	int xDistance = x1 - x2;
	int yDistance = y1 - y2;
	if (xDistance < 0) {
		xDistance *= -1;
	}
	if (yDistance < 0) {
		yDistance *= -1;
	}
	return xDistance + yDistance;
}

void Move(int APosition, int BPosition) {
	switch (APosition)
	{
	case 0:
		break;
	case 1:
		Ay -= 1;
		break;
	case 2:
		Ax += 1;
		break;
	case 3:
		Ay += 1;
		break;
	case 4:
		Ax -= 1;
		break;
	default:
		break;
	}

	switch (BPosition)
	{
	case 0:
		break;
	case 1:
		By -= 1;
		break;
	case 2:
		Bx += 1;
		break;
	case 3:
		By += 1;
		break;
	case 4:
		Bx -= 1;
		break;
	default:
		break;
	}
}

int ChangeCal() {
	int maxSum = 0;
	//1. A와 B의 BC 개수가 0인지 확인한다
	if (cntMap[Ay][Ax] == 0 && cntMap[By][Bx] == 0) {
		//1.1 참이면 끝낸다. 
		return maxSum;
	}
	//2. A의 BC개수가 0이 아니고 B의 BC개수가 0인지 확인한다.
	if (cntMap[Ay][Ax] != 0 && cntMap[By][Bx] == 0) {
		//2.1 참이면 A의 최대합을 적는다.
		for (int i = 0; i < A; i++) {
			if (map[i][Ay][Ax] > maxSum) {
				maxSum = map[i][Ay][Ax];
			}
		}
		return maxSum;
	}
	//3. A의 BC개수가 0이고, B의 BC개수가 0이 아닌지 확인한다.
	if (cntMap[Ay][Ax] == 0 && cntMap[By][Bx] != 0) {
		//3.1 참이면 B의 최대합을 적는다.
		for (int i = 0; i < A; i++) {
			if (map[i][By][Bx] > maxSum) {
				maxSum = map[i][By][Bx];
			}
		}
		return maxSum;
	}
	// 4. A의 BC 개수가 0이 아니고, B의 BC개수가 0이 아닌지 확인한다.
	if (cntMap[Ay][Ax] != 0 && cntMap[By][Bx] != 0) {
		// 4.1 참이면 겹쳐지는 부분이 있는지 확인한다
		int sameChargeArea = 0;
		int i = 0;
		int index = 0;
		while (i < A && sameChargeArea == 0) {
			if (map[i][Ay][Ax] == map[i][By][Bx]) {
				sameChargeArea++;
			}
			i++;
		}
		// 4.1.1 참이면 반복하여 최대합을 구한다.
		if (sameChargeArea>0) {
			int tempMaxSum;
			for (int i = 0; i < A; i++) {
				for (int j = 0; j < A; j++) {
					if (i == j) {
						tempMaxSum = (map[i][Ay][Ax] + map[j][By][Bx]) / 2;
					}
					else {
						tempMaxSum = map[i][Ay][Ax] + map[j][By][Bx];
					}
					if (tempMaxSum > maxSum) {
						maxSum = tempMaxSum;
					}
				}
			}
		}
		// 4.1.2 거짓이면 각각의 최대합을 구한다.
		else {
			int AmaxSum = 0;
			for (int i = 0; i < A; i++) {
				if (map[i][Ay][Ax] > AmaxSum) {
					AmaxSum = map[i][Ay][Ax];
				}
			}
			int BmaxSum = 0;
			for (int i = 0; i < A; i++) {
				if (map[i][By][Bx] > BmaxSum) {
					BmaxSum = map[i][By][Bx];
				}
			}
			maxSum = AmaxSum + BmaxSum;
		}
		return maxSum;
	}
}

void Init() {
	Ax = 1;
	Ay = 1;
	Bx = 10;
	By = 10;
	for (int i = 0; i < 8; i++) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				map[i][y][x] = 0;
				cntMap[y][x] = 0;
			}
		}
	}
}