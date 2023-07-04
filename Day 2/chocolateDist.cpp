/* GFG Problem*/
/* Brute */
// Generate all possible subarray and then find the subarray 
// with minimum value of maxi-mini.

/*Optimal*/
//Sort the array and use sliding window technique
// to find the minimum value of maxi-mini.
//TC-> O(N), SC -> O(1)
#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n = 17, m = 7;
	//cin >> n >> m;
	int a[] = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
	//for (int i = 0; i < n; i++) cin >> a[i];

	if (m == 0 || n == 0) return 0;
	if (n < m) return -1;

	sort(a, a + n);
	//sliding window techniqe:
	int i = 0, j = m - 1;
	int dif = INT_MAX;
	while (j < n) {
		dif = min(dif, a[j] - a[i]);
		j++, i++;
	}
	cout << dif << "\n";
	return 0;
}
