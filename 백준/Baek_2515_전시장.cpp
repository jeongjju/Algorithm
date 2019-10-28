#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 20000001
struct Picture {
	int height;
	int price;
};
bool Compare(Picture a, Picture b);
int main(int argc, char* argv[]) {
	// 그림의 개수
	int N;
	// 판매 그림 정의
	int S;
	cin >> N;
	cin >> S;
	// 그림의 높이
	int H;
	// 그림의 가격
	int C;
	Picture *pictures = new Picture[N];
	int *dp = new int[MAX];
	fill_n(dp, MAX, 0);
	int size = 0;
	int k = 1;
	for (int i = 1; i <= N; i++) {
		cin >> H;
		cin >> C;
		pictures[i].price = C;
		pictures[i].height = H;
	}
	sort(pictures + 1, pictures + N + 1, Compare);
	int j = N + 1;
	for (int i = N; i > 0; i--) {
		while (pictures[j - 1].height - S >= pictures[i].height) {
			j--;
		}
		dp[i] = max(dp[i + 1], dp[j] + pictures[i].price);
	}
	cout << dp[1] << endl;
	delete[] dp;
	delete[] pictures;
	return 0;
}
bool Compare(Picture a, Picture b) {
	if (a.height == b.height) {
		return a.price < b.price;
	}
	else {
		return a.height < b.height;
	}
}
