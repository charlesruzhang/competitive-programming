long long modInv(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;
    if (m == 1) return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

long long chineseRemainder(vi a, vi m, int n) {
    long long M = 1, x = 0;
    for (int i = 0; i < n; i++) M *= m[i];

    for (int i = 0; i < n; i++) {
        long long Mi = M / m[i];
        long long yi = modInv(Mi, m[i]);
        x = (x + a[i] * Mi % M * yi % M) % M;
    }
    return (x + M) % M;
}
