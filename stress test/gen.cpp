// gen_letter.cpp — prints ONE test to stdout.
// Usage: gen_letter.exe --seed=<u64> --nmax=<int>
// Build: g++ -std=c++20 -O2 gen_letter.cpp -o gen_letter.exe
#include <bits/stdc++.h>
using namespace std;

// ---------- RNG helpers (mt19937_64 + uniform dists) ----------
struct RNG {
    mt19937_64 eng;
    explicit RNG(uint64_t seed) : eng(seed) {}

    // inclusive uniform int
    template<class Int>
    Int uni(Int lo, Int hi) {
        return std::uniform_int_distribution<Int>(lo, hi)(eng);
    }

    // uniform real in [lo, hi)
    double real(double lo = 0.0, double hi = 1.0) {
        return std::uniform_real_distribution<double>(lo, hi)(eng);
    }

    // probability check: returns true with probability p in [0,1]
    bool prob(double p) {
        return real() < p;
    }

    // pick one element from a container by index
    template<class Cont>
    auto pick(const Cont& c) {
        size_t n = c.size();
        return c[uni<size_t>(0, n - 1)];
    }

    template<class It>
    void shuffle(It first, It last) {
        std::shuffle(first, last, eng);
    }
};

// ---------- Some reusable generators ----------

// Random permutation of [1..n]
vector<int> gen_perm(int n, RNG& rng) {
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    rng.shuffle(p.begin(), p.end());
    return p;
}

// Random array of length n with values in [lo, hi]
template<class Int=int>
vector<Int> gen_array(int n, Int lo, Int hi, RNG& rng) {
    vector<Int> a(n);
    for (int i = 0; i < n; ++i) a[i] = rng.uni<Int>(lo, hi);
    return a;
}

// Random tree on 1..n (Prufer-like)
vector<pair<int,int>> gen_tree(int n, RNG& rng) {
    if (n == 1) return {};
    vector<int> prufer(n - 2);
    for (int i = 0; i < n - 2; ++i) prufer[i] = rng.uni(1, n);
    vector<int> deg(n + 1, 1);
    for (int x : prufer) deg[x]++;

    // min-heap of leaves
    priority_queue<int, vector<int>, greater<int>> leaves;
    for (int v = 1; v <= n; ++v) if (deg[v] == 1) leaves.push(v);

    vector<pair<int,int>> edges; edges.reserve(n - 1);
    for (int x : prufer) {
        int u = leaves.top(); leaves.pop();
        edges.emplace_back(u, x);
        if (--deg[x] == 1) leaves.push(x);
        // deg[u] becomes 0
    }
    // last two
    int u = leaves.top(); leaves.pop();
    int v = leaves.top(); leaves.pop();
    edges.emplace_back(u, v);

    // optional shuffle of edges
    rng.shuffle(edges.begin(), edges.end());
    return edges;
}

// Random string of length n over alphabet [A..Z] or custom
string gen_string(int n, const string& alphabet, RNG& rng) {
    string s; s.resize(n);
    for (int i = 0; i < n; ++i) s[i] = alphabet[rng.uni<int>(0, (int)alphabet.size() - 1)];
    return s;
}

// ---------- Build one test here ----------
string make_test(uint64_t seed, int nmax) {
    RNG rng(seed);

    // EXAMPLE: a single tree test (like your current problem)
    int n = max(2, rng.uni(2, nmax));           // size ~ U[2, nmax]
    auto E = gen_tree(n, rng);                   // edges 1-indexed

    ostringstream out;
    out << n << "\n";
    for (auto [u, v] : E) out << u << " " << v << "\n";
    return out.str();

    /*
    // EXAMPLE 2: array + queries format
    int n = rng.uni(1, nmax);
    int q = rng.uni(1, nmax);
    auto a = gen_array<int>(n, -1'000'000, 1'000'000, rng);
    ostringstream out;
    out << n << " " << q << "\n";
    for (int i = 0; i < n; ++i) out << a[i] << (i + 1 == n ? '\n' : ' ');
    while (q--) {
        int t = rng.uni(1, 3);
        int l = rng.uni(1, n);
        int r = rng.uni(l, n);
        out << t << " " << l << " " << r << "\n";
    }
    return out.str();
    */

    /*
    // EXAMPLE 3: multiple test cases
    int T = rng.uni(1, 5);
    ostringstream out;
    out << T << "\n";
    while (T--) {
        int n = rng.uni(2, nmax);
        auto E = gen_tree(n, rng);
        out << n << "\n";
        for (auto [u, v] : E) out << u << " " << v << "\n";
    }
    return out.str();
    */
}

// ---------- main: parse args & print ----------
int main(int argc, char** argv) {
    uint64_t seed = 1;
    int nmax = 50;
    for (int i = 1; i < argc; ++i) {
        string s = argv[i];
        if (s.rfind("--seed=", 0) == 0)      seed = stoull(s.substr(7));
        else if (s.rfind("--nmax=", 0) == 0) nmax = stoi(s.substr(7));
    }
    cout << make_test(seed, nmax);
    return 0;
}
