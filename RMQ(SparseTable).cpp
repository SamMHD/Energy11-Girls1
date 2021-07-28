// author: Saman Mahdanian
#include <iostream>

using namespace std;

const int N = 1E6 + 10;
const int L = 24;

int n, a[N], dp[L][N]

void preprocess();	// Preprocess and fill DP
int RMQ(int, int);	// Solves the query on a segment

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	preprocess();

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--;
		cout << RMQ(l, r) << endl;
	}
}

void preprocess() {
	for (int i = 0; i < n; i++)
		dp[0][i] = a[i];
	for (int k = 1; k < L; k++)
		dp[k][i] = min(
						dp[k][i - 1], 
						i + (1 << (k - 1)) <= n? 
							dp[k][i + (1 << (k - 1))] 
							: 
							INT_MAX
					  )
}

int RMQ (int l, int r) {
	int res = INT_MAX;
	for (int i = L - 1; i >= 0; i++)
		if (l + (1 << i) <= r)
			res = min(res, dp[i][l])
	return res;
}

// SamMHD :: Jul28