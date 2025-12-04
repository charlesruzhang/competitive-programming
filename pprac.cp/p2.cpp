#include <bits/stdc++.h>
using namespace std;

int n = 1e7;
int tot = 10;
vector<long long> X(n);
atomic<long long> ans = 0;
void work(int id) {
	int l = n / tot * id;
	int r = n / tot * (id + 1);
	for (int i = l; i < r; i++) {
		ans.fetch_add(X[i]);
	}
}
int main() {
	for (int i = 0; i < n; i++) {
		X[i] = 2 * i + 1;
	}
	vector<thread> ts(tot, work);
	for (int i = 0; i < tot; i++) {
		ts[i].join();
	}
	cout << ans << endl;
	return 0;
}