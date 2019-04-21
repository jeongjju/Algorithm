#include<iostream>
using namespace std;
#define MAX 1001
int main(int agrc, char* argv[]) {
	int n;
	int prices[MAX];
	int i;
	int accumulatedPrices[MAX];
	int j;
	//1.�ؾ ���� �Է�
	cin >> n;
	//1.���ݵ� �Է�
	for (i = 0; i < n; i++) {
		cin >> prices[i];
	}
	//2. 1���� �ؾ�� �������ݵ��� ���´�.
	accumulatedPrices[0] = prices[0];
	//3. �ؾ ������ŭ �ݺ��Ѵ�.
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