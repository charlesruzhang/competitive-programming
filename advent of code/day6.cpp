#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> lines;
    string s;
    while (getline(cin, s)) {
        if (s == "!") break;
        if (!s.empty() && s.back() == '\n') s.pop_back(); // windows line endings
        lines.push_back(s);
    }
    if (lines.empty()) { cout << 0 << "\n"; return 0; }

    int H = (int)lines.size();
    int W = 0;
    for (auto &t : lines) W = max(W, (int)t.size());
    for (auto &t : lines) if ((int)t.size() < W) t += string(W - t.size(), ' ');

    // separator columns: entirely spaces in all rows
    vector<char> is_sep(W, 1);
    for (int c = 0; c < W; c++) {
        for (int r = 0; r < H; r++) {
            if (lines[r][c] != ' ') { is_sep[c] = 0; break; }
        }
    }

    // contiguous non-separator ranges are problems
    vector<pair<int,int>> ranges;
    for (int c = 0; c < W; ) {
        while (c < W && is_sep[c]) c++;
        if (c >= W) break;
        int l = c;
        while (c < W && !is_sep[c]) c++;
        int r = c;
        ranges.push_back({l, r});
    }

    long long total = 0;

    for (auto [l, r] : ranges) {
        // operator in last row within [l, r)
        char op = 0;
        for (int c = l; c < r; c++) {
            char ch = lines[H - 1][c];
            if (ch == '+' || ch == '*') {
                if (op && op != ch) {
                    cerr << "Error: multiple operators in one problem block.\n";
                    return 1;
                }
                op = ch;
            }
        }
        if (!op) continue; // or error; depends on how strict you want

        __int128 blockVal = (op == '+') ? 0 : 1;
        bool saw_any_number = false;

        // read numbers column-by-column, right-to-left, digits top->bottom (excluding last row)
        for (int c = r - 1; c >= l; c--) {
            string digits;
            digits.reserve(H);
            for (int row = 0; row < H - 1; row++) {
                char ch = lines[row][c];
                if ('0' <= ch && ch <= '9') digits.push_back(ch);
            }
            if (!digits.empty()) {
                saw_any_number = true;
                long long x = stoll(digits);
                if (op == '+') blockVal += x;
                else blockVal *= x;
            }
        }

        if (!saw_any_number) continue;
        total += (long long)blockVal; // assume fits in 64-bit for AoC input
    }

    cout << total << "\n";
    return 0;
}
