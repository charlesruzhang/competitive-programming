#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using pii = pair<int, int>;

static long long num(const string& s) {
    size_t p = s.rfind('-');
    return (p == string::npos) ? LLONG_MAX : stoll(s.substr(p + 1));
}

void solve() {
	unordered_map<string, vector<string>> task_to_bugs;
    string line;

    while (getline(cin, line)) {
        if (line.empty()) continue;
        size_t sep = line.find(": ");
        if (sep == string::npos) continue;
        string bug = line.substr(0, sep);
        string rest = line.substr(sep + 2);

        size_t start = 0;
        while (start <= rest.size()) {
            size_t pos = rest.find(", ", start);
            string task = (pos == string::npos) ? rest.substr(start)
                                                : rest.substr(start, pos - start);
            if (!task.empty()) task_to_bugs[task].push_back(bug);
            if (pos == string::npos) break;
            start = pos + 2;
        }
    }

    vector<string> tasks;
    tasks.reserve(task_to_bugs.size());
    for (auto &kv : task_to_bugs) tasks.push_back(kv.first);
    sort(tasks.begin(), tasks.end(),
         [](const string& a, const string& b){ return num(a) < num(b); });

    for (const string& t : tasks) {
        auto &bugs = task_to_bugs[t];
        sort(bugs.begin(), bugs.end(),
             [](const string& a, const string& b){ return num(a) < num(b); });
        cout << t << ": ";
        for (size_t i = 0; i < bugs.size(); ++i) {
            if (i) cout << ", ";
            cout << bugs[i];
        }
        cout << '\n';
    }

}

int main() {
	solve();
	return 0;
}