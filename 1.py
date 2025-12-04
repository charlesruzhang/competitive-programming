def create_hack(a, b, n, CPython=False):
    def sequence(x, pow2):
        i = perturb = hash(x)
        i %= pow2
        yield i
        while True:
            if CPython:
                perturb >>= 5
            i = (5 * i + perturb + 1) % pow2
            yield i
            if not CPython:
                perturb >>= 5

    def prime_dict(a, b, n):
        pow2 = 2 ** ((b - a - 1).bit_length() - 1)
        A = []
        for i in sequence(a, pow2):
            i = i + (a + 1 - i + pow2 - 1) // pow2 * pow2
            A.append(i)
            if len(A) == n or len(A) == pow2 // 3 - 10:
                break
        assert all(a <= x < b for x in A)
        return sorted(A)

    return prime_dict(a, b, n // 2)


N = 2 * 100
A = create_hack(1, N, N, False)

print(1)
print(N)

unused = set(range(1, N + 1))
s1 = set()

for i in range(0, len(A), 2):
    print(A[i], A[i + 1])
    unused.remove(A[i + 1])
    s1.add(A[i])

for i in s1:
    unused.remove(i)
    print(1, i)

for i in unused:
    if i == 1:
        continue
    print(1, i)