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
struct Node {
	map<int, Node*> children;
	Node* parent;
	int val;
	Node(Node * p) {
		parent = p;
		val = -1;
	}
};
void solve() {
    int n;
    cin >> n;
    Node* root = new Node(nullptr);
    vector<string> st(n+1);
    vector<Node*> nodes(n+1, nullptr);
    unordered_map<ll, int> ma;
   	const ll INF = 1e9;
    function <int(int, int)> comp = [&](int a, int b) {
    	auto it = ma.find(a * INF + b);
    	if (it != ma.end()) {
    		return (it -> second);
    	}
    	if (st[a].size() != st[b].size()) {
    		return (st[a].size() > st[b].size()) ? 0 : 1;
    	}
    	if (st[a] < st[b]) {
    		return 0;
    	} else if (st[a] > st[b]) {
    		return 1;
    	} else {
    		return (a < b) ? 0 : 1;
    	}
    };
    Node *now = root;
    int off = 0;
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	if (s == "add") {
    		int id;
    		string t;
    		cin >> id >> t;
    		st[id] = t;
    		Node * cur = root;
    		if (cur -> val == -1) {
				cur -> val = id;
			} else  {
				int B = comp(id, cur -> val);
				if (B == 0 || B == 1) {
					ma[id * INF + cur -> val] = B;
				}
				if (B == 0 || B == 2) cur -> val = id;
			}
    		for (int j = 0; j < t.size(); j++) {
    			int c = t[j] - 33;
    			if (cur -> children[c] == nullptr) {
    				Node * nnode = new Node(cur);
    				cur -> children[c] = nnode;
    			}
    			cur = cur -> children[c];
    			if (cur -> val == -1) {
    				cur -> val = id;
    			} else  {
    				int B = comp(id, cur -> val);
    				if (B == 0 || B == 1) {
    					ma[id * INF + cur -> val] = B;
    				}
    				if (B == 0 || B == 2) cur -> val = id;
    			}
    		}
    		Node * endnode = new Node(cur);
    		cur -> children[id + 1000] = endnode;
    		cur = endnode;
    		cur -> val = id;
    		nodes[id] = cur;
    	} else if (s == "append") {
    		string t;
    		cin >> t;
			for (int j = 0; j < t.size(); j++) {
    			int c = t[j] - 33;
    			if (now -> children[c] == nullptr) {
    				Node * nnode = new Node(now);
    				now -> children[c] = nnode;
    			}
    			now = now -> children[c];
    		}
    	} else if (s == "backspace") {
    		int z;
    		cin >> z;
    		for (int j = 0; j < z; j++) {
    			if (now == root) break;
    			now = now -> parent;
    		}
    	} else {
    		int id;
    		cin >> id;
    		Node * cur = nodes[id];
    		while (cur != nullptr) {
	    		int nval = -1;
	    		for (auto j = cur -> children.begin(); j != cur -> children.end(); ++j) {
	    			if (nval == -1) {
	    				nval = j -> second -> val;
	    				continue;
	    			}
	    			if (j -> second -> val == -1) {
	    				continue;
	    			}
	    			int B = comp(j -> second -> val, nval);
	    			if (B == 0 || B == 1) {
						ma[j -> second -> val * INF + nval] = B;
					}
	    			if (B == 0 || B == 2) nval = j -> second -> val;
	    		}
	    		cur -> val = nval;
	    		cur = cur -> parent;
    		}
    	}

    	cout << (now -> val) << endl;
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
