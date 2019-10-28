// 백준 1699번 제곱수의 합
#include<iostream>
#include<math.h>
#define MAX 100000
using namespace std;

int main(int argc, char* argv[]) {

	int naturalNumber;
	cin >> naturalNumber;
	int termMinCounts[MAX];
	fill_n(termMinCounts, MAX, 0);
	int i = 0;
	termMinCounts[i++] = 1;
	termMinCounts[i++] = 2;
	termMinCounts[i++] = 3;
	for (i; i < naturalNumber; i++) {
		float squareRoot = sqrt(i + 1);
		if (squareRoot - (int)squareRoot != 0) {
			for (int j = 1; j <= (int)squareRoot; j++) {
				// 
				if (termMinCounts[i] == 0 || 1 + termMinCounts[i - j*j] < termMinCounts[i]) {
					if (i == 181 && 1 + termMinCounts[i - j*j] < termMinCounts[i]) {
						//cout << i-j*j << endl;
					}
					termMinCounts[i] = termMinCounts[i - j*j] + 1;
				}
			}
		}
		else {
			termMinCounts[i] = 1;
		}
	}
	cout << termMinCounts[naturalNumber - 1] << endl;

	return 0;
}

