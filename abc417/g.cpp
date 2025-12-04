#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const ull MAXX = 1000000000000000000ULL; // 1e18

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    int N = Q + 2;

    vector<int> cleft(N), cright(N);
    vector<ull> X(N), len(N), xleft(N), xright(N);

    // Base strings S0 = "0", S1 = "1"
    const string S0 = "0";
    const string S1 = "1";
    len[0] = 1;
    len[1] = 1;

    // Read operations
    for(int i = 2; i < N; i++){
        cin >> cleft[i] >> cright[i] >> X[i];
        ull sum = len[cleft[i]] + len[cright[i]];
        len[i] = (sum > MAXX ? MAXX : sum);
        xleft[i]  = 0;
        xright[i] = len[cleft[i]];
    }

    // Determine heavy and light edges
    vector<int> heavy(N), light(N);
    vector<ull> xheavy(N), xlight(N);
    for(int i = 2; i < N; i++){
        ull lsz = len[cleft[i]];
        ull rsz = len[cright[i]];
        if(lsz >= rsz){
            heavy[i]  = cleft[i];  xheavy[i] = xleft[i];
            light[i]  = cright[i]; xlight[i] = xright[i];
        } else {
            heavy[i]  = cright[i]; xheavy[i] = xright[i];
            light[i]  = cleft[i];  xlight[i] = xleft[i];
        }
    }

    // Precompute binary lifting for heavy edges
    int LOG = 0;
    while((1 << LOG) <= Q) LOG++;
    vector<vector<int>> jp(LOG, vector<int>(N));
    vector<vector<ull>> jx(LOG, vector<ull>(N));
    // level-0
    for(int i = 2; i < N; i++){
        jp[0][i] = heavy[i];
        jx[0][i] = xheavy[i];
    }
    // higher levels
    for(int k = 1; k < LOG; k++){
        for(int i = 2; i < N; i++){
            int mid = jp[k-1][i];
            jp[k][i] = (mid <= 1 ? mid : jp[k-1][mid]);
            jx[k][i] = jx[k-1][i] + (mid <= 1 ? 0 : jx[k-1][mid]);
        }
    }

    // Function to fetch the B-th char of S[A]
    auto get_char = [&](int A, ull B){
        // heavy jumps
        for(int k = LOG - 1; k >= 0; k--){
            if(A > 1){
                ull st = jx[k][A];
                int to = jp[k][A];
                ull seg = (to == 0 || to == 1 ? 1 : len[to]);
                if(st < B && B <= st + seg){
                    B -= st;
                    A = to;
                }
            }
        }
        // light edge traversals (≤60)
        while(A > 1){
            if(xlight[A] < B && B <= xlight[A] + len[light[A]]){
                B -= xlight[A];
                A = light[A];
            } else {
                B -= xheavy[A];
                A = heavy[A];
            }
        }
        // Base case
        return (A == 0 ? S0[B-1] : S1[B-1]);
    };

    // Answer each query
    for(int i = 2; i < N; i++){
        char ans = get_char(i, X[i]);
        cout << ans << '\n';
    }
    return 0;
}
