#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
string BFS(int xStart, int yStart, vector<int> xStores, vector<int> yStores, int xGoal, int yGoal);
int Distance(int x1, int y1, int x2, int y2);
int main(int argc, char* argv[]) {
	int t, n;
	string result;
	cin >> t; // 테스트 케이스의 개수
	for (int i = 0; i < t; i++) {
		cin >> n; // 편의점 개수
				  // 집,편의점,페스티벌 좌표를 입력받는다
		int xStart, yStart, xStore, yStore, xGoal, yGoal;
		vector<int> xStores, yStores;
		cin >> xStart;
		cin >> yStart;
		for (int j = 0; j < n; j++) {
			cin >> xStore;
			cin >> yStore;
			xStores.push_back(xStore);
			yStores.push_back(yStore);
		}
		cin >> xGoal;
		cin >> yGoal;
		cout << BFS(xStart, yStart, xStores, yStores, xGoal, yGoal) << endl;
	}

	return 0;
}
string BFS(int xStart, int yStart, vector<int> xStores, vector<int> yStores, int xGoal, int yGoal) {
	queue<int> xQueue;
	queue<int> yQueue;
	int xPosition, yPosition;
	int visited[100] = { 0, };
	xQueue.push(xStart);
	yQueue.push(yStart);
	while (!xQueue.empty())
	{
		xPosition = xQueue.front();
		yPosition = yQueue.front();
		xQueue.pop();
		yQueue.pop();
		if (Distance(xPosition, yPosition, xGoal, yGoal) <= 1000) {
			return "happy";
		}
		int length = xStores.size();
		for (int i = 0; i < length; i++) {
			if (Distance(xPosition, yPosition, xStores[i], yStores[i]) <= 1000 && visited[i] != 1) {
				xQueue.push(xStores[i]);
				yQueue.push(yStores[i]);
				visited[i] = 1;
			}
		}

	}
	return "sad";
}

int Distance(int x1, int y1, int x2, int y2) {
	int xLength;
	int yLength;
	if (x1 > x2) {
		xLength = x1 - x2;
	}
	else {
		xLength = x2 - x1;
	}

	if (y1 > y2) {
		yLength = y1 - y2;
	}
	else {
		yLength = y2 - y1;
	}
	return xLength + yLength;
}
