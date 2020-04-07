#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int n; string s;
int fail[1000001];

void failure(void) {
	int i,j,  len = s.length();
	fail[0] = -1;
	for (j = 1; j < n; j++) {
		i = fail[j - 1];
		while ((s[j] != s[i + 1]) && (i >= 0)) { i = fail[i]; }
		if (s[j] == s[i + 1])fail[j] = i + 1;
		else fail[j] = -1;
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> s;
	int ans = -1;
	failure();
	cout << n - (fail[n-1]+1) << "\n";
	return 0;
}