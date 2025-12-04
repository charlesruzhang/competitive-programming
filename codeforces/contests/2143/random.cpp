#include <bits/stdc++.h>
#define int long long

using namespace std;
inline bool chmin(int &a, int b) { return b < a ? (a = b, true) : false; }
inline bool chmax(int &a, int b) { return b > a ? (a = b, true) : false; }

struct node {
    int ls, rs, sum;
};

const int MAXN = 2e5+5, INF = 1e18;
int n, a[MAXN], le[MAXN], ri[MAXN];
bool works = true;

node* recurse(int x) {
    node* nl = new node{0, 0, 0};
    node* nr = new node{0, 0, 0};
    if(!works) return nl;
    if(le[x] != -1) {
        delete nl;
        nl = recurse(le[x]);
    }
    if(ri[x] != -1) {
        delete nr;
        nr = recurse(ri[x]);
    }
    if(max((*nl).rs, (*nr).ls) > 0) {
        works = false;
        return nl;
    }
    chmax((*nl).ls, (*nl).sum + a[x] + (*nr).ls);
    (*nl).rs = max((*nr).rs, (*nr).sum + a[x] + (*nl).rs);
    (*nl).sum = a[x] + (*nl).sum + (*nr).sum;
    delete nr;
    return nl;
}

void solve() {
    works = true;
    cin>>n;
    vector<int> stack;
    int mx = 0, idx = -1;
    for(int i = 1; i <= n; i++) {
        le[i]=ri[i] = -1;
        cin>>a[i];
        int lst = -1;
        while(!stack.empty() && a[stack.back()] <= a[i]) {
            lst = stack.back();
            stack.pop_back();
        }
        le[i] = lst;
        if(!stack.empty()) {
            ri[stack.back()] = i;
        }
        stack.push_back(i);
        if(a[i] > mx) {
            mx = a[i];
            idx = i;
        }
    }
    recurse(idx);
    if(works) {
        cout << "YES\n";
        return;
    }
    cout<<"NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
   // cout << "YES\nYES\nNO\n";
    //cout << "YES\nYES\nNO\n";
    cin >> t;
    while(t--) solve();
    return 0;
}
