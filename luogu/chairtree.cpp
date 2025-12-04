#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
const ll MOD = 998244353;
const ll MAXX = 1e16;
const int INF = 1e9+7;
struct Node {
	Node* left;
	Node* right;
	int val;
	Node(int v, Node* l, Node* r) {
		left = l;
		right = r;
		val = v;
	}
};
int build(int l, int r, Node* cur, Node* prev, int v) {
	int ret = 0;
	if (l == r) {
		if (prev != nullptr) {
    		cur -> val = v + prev -> val;
    	} else {
    		cur -> val = v;
    	}
    	return cur -> val;
	}
	int m = (l + r) / 2;
	if (v > m) {
		Node* rr = new Node(0, nullptr, nullptr);
		cur -> right = rr;
		if (prev != nullptr) {
			cur -> left = prev -> left;
			prev = prev -> right;
		} else {
			cur -> left = nullptr;
		}
		ret = build(m+1, r, cur -> right, prev, v);
		if (cur -> left != nullptr) {
			ret += cur -> left -> val;
		}
		cur -> val = ret;
	} else {
		Node* ll = new Node(0, nullptr, nullptr);
		cur -> left = ll;
		if (prev != nullptr) {
			cur -> right = prev -> right;
			prev = prev -> left;
		} else {
			cur -> right = nullptr;
		}
		ret = build(l, m, cur -> left, prev, v);
		if (cur -> right != nullptr) {
			ret += cur -> right -> val;
		}
		cur -> val = ret;
	}
	return ret;
}
int query(int l, int r, int val, Node* prev, Node * cur) {
	if (cur == nullptr) return 0;
	if (l == r) {
		int res = 0;
		res += cur -> val;
		if (prev != nullptr) res -= prev -> val;
		return res;
	}
	int m = (l + r) / 2;
	int res = 0;
	if (val > m) {
		Node* newprev = prev;
		if (prev != nullptr) newprev = prev -> right;
		res += query(m+1, r, val, newprev, cur -> right);
	}
	if (val >= m) {
		if (prev != nullptr && prev -> left != nullptr) res -= prev -> left -> val;
		if (cur -> left != nullptr) res += cur -> left -> val;
		return res;
	}
	Node * newprev = (prev == nullptr) ? prev: prev -> left; 
	return query(l, m, val, newprev, cur -> left);
}
void solve() {
    int n;
    cin >> n;
    vi a(n+1);
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    }
    int q;
    cin >> q;
    vector<Node*> roots(n+1, nullptr);
    for (int i = 1; i <= n; i++) {
    	Node* root = new Node(0, nullptr, nullptr);
    	roots[i] = root;
    	build(1, 1 << 30, root, roots[i-1], a[i]);
    }
    while (q--) {
    	int x, y;
    	cin >> x >> y;
    	int val = 1;
    	int res = 0;
    	int prevres = 0;
    	do {
    		prevres = res;
    		res = query(1, 1 << 30, val, roots[x-1], roots[y]);
    		val = res + 1;
    	} while (res != prevres);
    	cout << val << endl;
    }	
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
