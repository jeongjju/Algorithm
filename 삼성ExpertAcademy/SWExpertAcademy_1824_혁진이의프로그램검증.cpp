#include<iostream>
#include<string>
#define MAX 1001
using namespace std;
int R;
int C;
int directions[4] = { 1,2,3,4 };
int index;
char language[20][20];
int cursorX;
int cursorY;
string isStop = "NO";
int value;
int direction = 1;
string Program();
void LeftSign();
void RightSign();
void UpSign();
void DownSign();
void UnderBar();
void ColumnBar();
void Period();
void At();
void Number();
void Plus();
void Minus();
int QuestionMark();
void Move();
void Initialize();
int main(int argc, char* argv[]) {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> R;
		cin >> C;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> language[i][j];
			}
		}
		int k = 0;
		while (k < 4 && isStop == "NO") {
			if (k == 0) {
				index = 0;
				Program();
			}
			else if (k == 1) {
				index = 1;
				Program();
			}
			else if (k == 2) {
				index = 2;
				Program();
			}
			else if (k == 3) {
				index = 3;
				Program();
			}
			Initialize();
			k++;
		}
		cout << "#";
		cout << i + 1;
		cout << " ";
		cout << isStop << endl;
		isStop = "NO";
		index = 0;

	}

	return 0;
}

void Initialize() {
	cursorX = 0;
	cursorY = 0;
	value = 0;
	direction = 1;
}

string Program() {
	int count = 0;

	while (isStop == "NO" && count < MAX) {
		if (language[cursorY][cursorX] == '<') {
			LeftSign();
		}
		else if (language[cursorY][cursorX] == '>') {
			RightSign();
		}
		else if (language[cursorY][cursorX] == '^') {
			UpSign();
		}
		else if (language[cursorY][cursorX] == 'v') {
			DownSign();
		}
		else if (language[cursorY][cursorX] == '_') {
			UnderBar();
		}
		else if (language[cursorY][cursorX] == '|') {
			ColumnBar();
		}
		else if (language[cursorY][cursorX] == '?') {
			QuestionMark();
		}
		else if (language[cursorY][cursorX] == '.') {
			Period();
		}
		else if (language[cursorY][cursorX] == '@') {
			At();
		}
		else if (language[cursorY][cursorX] == '0' || language[cursorY][cursorX] == '1' || language[cursorY][cursorX] == '2' || language[cursorY][cursorX] == '3' || language[cursorY][cursorX] == '4' ||
			language[cursorY][cursorX] == '5' || language[cursorY][cursorX] == '6' || language[cursorY][cursorX] == '7' || language[cursorY][cursorX] == '8' || language[cursorY][cursorX] == '9') {
			Number();
		}
		else if (language[cursorY][cursorX] == '+') {
			Plus();
		}
		else if (language[cursorY][cursorX] == '-') {
			Minus();
		}
		count++;
	}
	return isStop;
}

void LeftSign() {
	direction = 3;
	cursorX--;
	if (cursorX < 0) {
		cursorX = C - 1;
	}
}

void RightSign() {
	direction = 1;
	cursorX++;
	if (cursorX > C - 1) {
		cursorX = 0;
	}
}

void UpSign() {
	direction = 4;
	cursorY--;
	if (cursorY <0) {
		cursorY = R - 1;
	}
}

void DownSign() {
	direction = 2;
	cursorY++;
	if (cursorY > R - 1) {
		cursorY = 0;
	}
}

void UnderBar() {
	if (value == 0) {
		RightSign();
	}
	else {
		LeftSign();
	}
}

void ColumnBar() {
	if (value == 0) {
		DownSign();
	}
	else {
		UpSign();
	}
}

void Period() {
	Move();
}

void Move() {
	if (direction > 1) {
		switch (direction) {
		case 2:
			DownSign();
			break;
		case 3:
			LeftSign();
			break;
		case 4:
			UpSign();
			break;
		default:
			break;
		}
	}
	else {
		RightSign();
	}
}

int QuestionMark() {
	direction = directions[index++];
	if (index > 3) {
		index = 0;
	}
	Move();
	return direction;
}

void At() {
	isStop = "YES";
}

void Number() {
	value = language[cursorY][cursorX] - '0';
	Move();
}

void Plus() {
	value++;
	if (value >= 16) {
		value = 0;
	}
	Move();
}

void Minus() {
	value--;
	if (value <= -1) {
		value = 15;
	}
	Move();
}