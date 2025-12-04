#include <bits/stdc++.h>
using namespace std;
template <class T>
struct V {
    T* vals;
    size_t sz = 0;
    size_t reserved = 0;
    V (int n) {
        vals = new T[n];
        fill(vals, vals+n, T());
        sz = n;
        reserved = n;
    }
    V () {
        vals = new T[64];
        sz = 0;
        reserved = 64;
    }
    V (const V& o) {
        vals = new T[o.reserved];
        copy(o.vals, o.vals + o.sz, vals);
        sz = o.sz;
        reserved = o.reserved;
    }
    V (V&& o) {
        vals = exchange(o.vals, nullptr);
        sz = exchange(o.sz, 0);
        reserved = exchange(o.reserved, 0);
    }
    V& operator=(V& o) {
        delete[] vals;
        vals = new T[o.reserved];
        copy(o.vals, o.vals + o.sz, vals);
        sz = o.sz;
        reserved = o.reserved;
        return *this;
    }
    V& operator=(V&& o) {
        delete[] vals;
        vals = exchange(o.vals, nullptr);
        sz = exchange(o.sz, 0);
        reserved = exchange(o.reserved, 0);
        return *this;
    }
    ~V() {delete[] vals;}
    void push_back(T val) {
        if (sz == reserved) {
            reserved *= 2;
            T* nvals = new T[reserved];
            for (int i = 0; i < sz; i++) {
                nvals[i] = vals[i];
            }
            delete[] vals;
            swap(nvals, vals);
        }
        vals[sz] = val;
        sz++;
    } 
    T& operator[](int idx) {
        return vals[idx];
    }
};
int main() {
    V<int> vec;
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(8);
    cout << vec[0] << " " << vec[1] << " " << vec[2] << endl;
    vec[0] = 9;
    cout << vec[0] << endl;
    return 0; 
}