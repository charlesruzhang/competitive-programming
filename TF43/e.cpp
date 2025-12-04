int maxXorPartitionSum(const vector<int>& a) {
    int n = a.size();
    int T = 0;
    for (int v : a) {
        T ^= v;
    }

    const int W = 31;          
    int basis[W] = {0};

    for (int v : a) {
        int x = v;
        for (int j = W - 1; j >= 0; --j) {
            if (!(x & (1 << j))) continue;
            if (!basis[j]) {
                basis[j] = x;
                break;
            }
            x ^= basis[j];
        }
    }

    int X = 0;
    for (int j = W - 1; j >= 0; --j) {
        if (((T >> j) & 1) == 0
            && basis[j]
            && !((X >> j) & 1)) {
            X ^= basis[j];
        }
    }

    return X + (T ^ X);
}