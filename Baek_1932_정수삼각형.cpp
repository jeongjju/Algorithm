#include<iostream>
using namespace std;
int main(int argc, char* argv[]) {
	//삼각형의 크기를 입력받는다
	int n;
	cin >> n;
	// 숫자삼각형을 입력받는다
	int **triangle = new int*[n];
	for (int i = 0; i < n; ++i) {
		triangle[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}

	int i;
	int j;
	int k;
	int *accumulatedSum = new int[n];
	int *newAccumulatedSum;
	for (i = 0; i < n; i++) {
		accumulatedSum[i] = triangle[n - 1][i];
	}
	for (i = 0; i < n - 1; i++) {
		newAccumulatedSum = new int[n - i - 1];
		for (j = 0; j < n - i - 1; j++) {
			if (triangle[n - i - 2][j] + accumulatedSum[j] < triangle[n - i - 2][j] + accumulatedSum[j + 1]) {
				newAccumulatedSum[j] = triangle[n - i - 2][j] + accumulatedSum[j + 1];
			}
			else {
				newAccumulatedSum[j] = triangle[n - i - 2][j] + accumulatedSum[j];
			}
		}
		delete[] accumulatedSum;
		accumulatedSum = new int[n - i - 1];
		for (k = 0; k < n - i - 1; k++) {
			accumulatedSum[k] = newAccumulatedSum[k];
		}
		delete[] newAccumulatedSum;
	}
	cout << accumulatedSum[0] << endl;
	delete[] accumulatedSum;
	return 0;
}
