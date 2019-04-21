#include<iostream>
using namespace std;
#define MAX 1001
int main(int agrc, char* argv[]) {
	int n;
	int prices[MAX];
	int i;
	int accumulatedPrices[MAX];
	int j;
	//1.붕어빵 개수 입력
	cin >> n;
	//1.가격들 입력
	for (i = 0; i < n; i++) {
		cin >> prices[i];
	}
	//2. 1개의 붕어빵의 누적가격들을 적는다.
	accumulatedPrices[0] = prices[0];
	//3. 붕어빵 개수만큼 반복한다.
	for (i = 1; i <= n; i++) {
		accumulatedPrices[i] = prices[i];
		for (j = 0; j <= i / 2; j++) {
			if (accumulatedPrices[j] + accumulatedPrices[i - j - 1] > accumulatedPrices[i]) {
				accumulatedPrices[i] = accumulatedPrices[j] + accumulatedPrices[i - j - 1];
			}
		}
	}
	cout << accumulatedPrices[n - 1] << endl;
	return 0;
}