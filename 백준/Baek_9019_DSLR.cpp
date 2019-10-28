#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#define MAX 10001
using namespace std;
string BFS(int A, int B);
int D(int value);
int S(int value);
int L(int value);
int R(int value);
int main(int argc, char* argv[]) {
	int T;
	int A;
	int B;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A;
		cin >> B;
		cout << BFS(A, B) << endl;
	}
	return 0;
}
int D(int value) {
	value *= 2;
	if (value > 9999) {
		value %= 10000;
	}
	return value;
}

int S(int value) {
	value -= 1;
	if (value < 0) {
		value = 9999;
	}
	return value;
}

int L(int value) {
	int d1, d2, d3, d4;
	d4 = value % 10;
	value /= 10;
	d3 = value % 10;
	value /= 10;
	d2 = value % 10;
	value /= 10;
	d1 = value % 10;
	return ((d2 * 10 + d3) * 10 + d4) * 10 + d1;
}

int R(int value) {
	int d1, d2, d3, d4;
	d4 = value % 10;
	value /= 10;
	d3 = value % 10;
	value /= 10;
	d2 = value % 10;
	value /= 10;
	d1 = value % 10;
	return ((d4 * 10 + d1) * 10 + d2) * 10 + d3;
}

string BFS(int A, int B) {
	string minimalSequence = "";
	int visited[MAX];
	queue<int> queue;
	int root[MAX];
	int command[MAX];
	int name[4] = { 'D','S','L','R' };
	int values[4];
	int value;
	for (int i = 0; i < MAX; i++) {
		visited[i] = 0;
	}
	visited[A] = 1;
	queue.push(A);
	while (queue.front() != B && !queue.empty()) {
		value = queue.front();
		queue.pop();
		values[0] = D(value);
		values[1] = S(value);
		values[2] = L(value);
		values[3] = R(value);
		for (int i = 0; i < 4; i++) {
			if (visited[values[i]] == 0) {
				visited[values[i]] = 1;
				queue.push(values[i]);
				root[values[i]] = value;
				command[values[i]] = name[i];
			}
		}
	}
	while (A != B) {
		minimalSequence += command[B];
		B = root[B];
	}
	reverse(minimalSequence.begin(), minimalSequence.end());
	return minimalSequence;
}
