#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string reverse(const string &input);
int main(int argc, char* argv[]) {
	string str;
	cin >> str;

	string reverseStr = reverse(str);
	int size = str.size();
	float halfIndex;
	if (size % 2 == 0) {
		halfIndex = size / 2 + 0.5 - 1.0;
	}
	else {
		halfIndex = size / 2 + 1 - 1.0;
	}
	int palindromeLength = 0;
	float initialHalfIndex;
	int sameCount = 0;
	while (halfIndex>0.0 &&palindromeLength == 0)
	{
		initialHalfIndex = halfIndex;
		//ºóÁöÁ¡
		if (halfIndex - (int)halfIndex > 0.0) {
			int i = (int)halfIndex;
			int j = (int)halfIndex + 1;
			while (initialHalfIndex == halfIndex&&i >= 0)
			{
				if (reverseStr[i] == reverseStr[j]) {
					sameCount++;
					i--;
					j++;
				}
				else {
					halfIndex -= 0.5;
					sameCount = 0;
				}
			}
			if (halfIndex == initialHalfIndex) {
				palindromeLength = reverseStr.size() - sameCount * 2 + reverseStr.size();
			}
		}
		else {
			int i = (int)halfIndex - 1;
			int j = (int)halfIndex + 1;
			while (initialHalfIndex == halfIndex&&i >= 0) {
				if (reverseStr[i] == reverseStr[j]) {
					sameCount++;
					i--;
					j++;
				}
				else {
					halfIndex -= 0.5;
					sameCount = 0;
				}
			}
			if (halfIndex == initialHalfIndex) {
				palindromeLength = reverseStr.size() - sameCount * 2 - 1 + reverseStr.size();
			}
		}
	}
	if (palindromeLength == 0) {
		palindromeLength = size * 2 - 1;
	}
	cout << palindromeLength << endl;
	return 0;
}
string reverse(const string &input)
{
	string temp(input);

	reverse(temp.begin(), temp.end());

	return temp;
}