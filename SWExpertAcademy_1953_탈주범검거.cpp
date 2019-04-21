#include<iostream>
using namespace std;
int map[50][50];
int visited[50][50];
int position[4][2] = { { -1,0 },{ 0,1 },{ 1,0 },{ 0,-1 } }; //up, right, down, left
int N;
int M;
int BFS(int R, int C, int L);
void Init(int map[50][50]);
bool IsConnect(int x, int y, int xNext, int yNext, int position);
bool IsInside(int x, int y);
int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int R, C, L; // 세로크기,가로크기,세로위치,가로위치,탈출 소요된 시간 
		cin >> N;
		cin >> M;
		cin >> R;
		cin >> C;
		cin >> L;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				cin >> map[y][x];
			}
		}
		cout << "#" << i + 1 << " " << BFS(R, C, L) << endl;
		Init(map);
		Init(visited);
	}
	return 0;
}

int BFS(int R, int C, int L) {
	int xQueue[50 * 50], yQueue[50 * 50]; // x큐,y큐
	int x, y, front = 0, rear = 0, escapeCount = 0; // x현재위치,y현재위치,큐의앞의위치,큐의뒤의위치,탈출 방법수
	xQueue[rear] = C;
	yQueue[rear] = R;
	rear++;
	visited[R][C] = 1;
	escapeCount++;
	while (front < rear) {
		x = xQueue[front];
		y = yQueue[front];
		front++;
		if (visited[y][x] == L) {
			return escapeCount;
		}
		for (int i = 0; i < 4; i++) {
			int xNext = x + position[i][1];
			int yNext = y + position[i][0];
			//up,right,down,left 로 이동가능한지 확인한다
			if (IsInside(xNext, yNext) && visited[yNext][xNext] == 0 && IsConnect(x, y, xNext, yNext, i)) {
				xQueue[rear] = xNext;
				yQueue[rear] = yNext;
				rear++;
				visited[yNext][xNext] = visited[y][x] + 1;
				escapeCount++;
			}

		}
	}
}
void Init(int map[50][50]) {
	for (int y = 0; y < 50; y++) {
		for (int x = 0; x < 50; x++) {
			map[y][x] = 0;
		}
	}
}

bool IsConnect(int x, int y, int xNext, int yNext, int position) {
	switch (map[y][x]) {
	case 1: // up,right,down,left
		switch (position) {
			// up
		case 0:
			if (map[yNext][xNext] == 1 || map[yNext][xNext] == 2 || map[yNext][xNext] == 5 || map[yNext][xNext] == 6) return true;
			return false;
			// right
		case 1:
			if (map[yNext][xNext] == 1 || map[yNext][xNext] == 3 || map[yNext][xNext] == 6 || map[yNext][xNext] == 7) return true;
			return false;
			// down
		case 2:
			if (map[yNext][xNext] == 1 || map[yNext][xNext] == 2 || map[yNext][xNext] == 4 || map[yNext][xNext] == 7) return true;
			return false;
			// left
		case 3:
			if (map[yNext][xNext] == 1 || map[yNext][xNext] == 3 || map[yNext][xNext] == 4 || map[yNext][xNext] == 5) return true;
			return false;
		default:
			return false;
		}
	case 2: // up,down
		switch (position)
		{
		case 0:
			if (map[yNext][xNext] == 1 || map[yNext][xNext] == 2 || map[yNext][xNext] == 5 || map[yNext][xNext] == 6) return true;
			return false;
		case 2:
			if (map[yNext][xNext] == 1 || map[yNext][xNext] == 2 || map[yNext][xNext] == 4 || map[yNext][xNext] == 7) return true;
			return false;
		default:
			return false;
		}
	case 3: // right,left
		switch (position)
		{
		case 1:
			if (map[yNext][xNext] == 1 || map[yNext][xNext] == 3 || map[yNext][xNext] == 6 || map[yNext][xNext] == 7) return true;
			return false;
		case 3:
			if (map[yNext][xNext] == 1 || map[yNext][xNext] == 3 || map[yNext][xNext] == 4 || map[yNext][xNext] == 5) return true;
			return false;
		default:
			return false;
		}
	case 4: // up,right
		switch (position)
		{
		case 0:
			if (map[yNext][xNext] == 1 || map[yNext][xNext] == 2 || map[yNext][xNext] == 5 || map[yNext][xNext] == 6) return true;
			return false;
		case 1:
			if (map[yNext][xNext] == 1 || map[yNext][xNext] == 3 || map[yNext][xNext] == 6 || map[yNext][xNext] == 7) return true;
			return false;
		default:
			return false;
		}
	case 5: // right,down
		switch (position)
		{
		case 1:
			if (map[yNext][xNext] == 1 || map[yNext][xNext] == 3 || map[yNext][xNext] == 6 || map[yNext][xNext] == 7) return true;
			return false;
		case 2:
			if (map[yNext][xNext] == 1 || map[yNext][xNext] == 2 || map[yNext][xNext] == 4 || map[yNext][xNext] == 7) return true;
			return false;
		default:
			return false;
		}
	case 6: // down,left
		switch (position)
		{
		case 2:
			if (map[yNext][xNext] == 1 || map[yNext][xNext] == 2 || map[yNext][xNext] == 4 || map[yNext][xNext] == 7) return true;
			return false;
		case 3:
			if (map[yNext][xNext] == 1 || map[yNext][xNext] == 3 || map[yNext][xNext] == 4 || map[yNext][xNext] == 5) return true;
			return false;
		default:
			return false;
		}
	case 7: // up,left
		switch (position)
		{
		case 0:
			if (map[yNext][xNext] == 1 || map[yNext][xNext] == 2 || map[yNext][xNext] == 5 || map[yNext][xNext] == 6) return true;
			return false;
		case 3:
			if (map[yNext][xNext] == 1 || map[yNext][xNext] == 3 || map[yNext][xNext] == 4 || map[yNext][xNext] == 5) return true;
			return false;
		default:
			return false;
		}
	default:
		return false;
	}
}

bool IsInside(int x, int y) {
	return (x >= 0 && x < M) && (y >= 0 && y < N);
}