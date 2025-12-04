import sys
import random

def main():
    # Set default values if no command line arguments provided.
    # You can run this script with: python gen_input.py [n] [m] [q]
    if len(sys.argv) > 1:
        n = int(sys.argv[1])
    else:
        n = 10  # Default number of cities; change as needed.
    if len(sys.argv) > 2:
        m = int(sys.argv[2])
    else:
        # m must be between n-1 and min(n(n-1)/2, 10^5).
        max_possible = min(n*(n-1)//2, 100000)
        m = n - 1 + random.randint(0, max_possible - (n - 1))
    if len(sys.argv) > 3:
        q = int(sys.argv[3])
    else:
        q = 20  # Default number of queries; change as needed.

    # Ensure m is in the allowed range.
    max_possible = min(n*(n-1)//2, 100000)
    m = max(m, n-1)
    m = min(m, max_possible)

    # Generate the highways (edges)
    # To avoid self-loops and duplicates, we maintain a set.
    # We first generate a spanning tree (n-1 edges) to ensure connectivity.
    edges = set()
    for i in range(2, n + 1):
        u = random.randint(1, i - 1)
        v = i
        k = random.randint(1, 10**9)
        if u > v:
            u, v = v, u
        edges.add((u, v, k))
    
    # Add extra edges until we have m edges.
    while len(edges) < m:
        u = random.randint(1, n)
        v = random.randint(1, n)
        if u == v:
            continue  # skip self-loops
        if u > v:
            u, v = v, u
        # Check for duplicate edge.
        if (u, v) in {(e[0], e[1]) for e in edges}:
            continue
        k = random.randint(1, 10**9)
        edges.add((u, v, k))
    
    edges = list(edges)
    random.shuffle(edges)

    # Generate queries.
    # Each query has two integers x′ and l′.
    # x′ is in the range [0, n-1] and l′ is in the range [0, 10^5 - 1].
    queries = []
    for _ in range(q):
        x_prime = random.randint(0, n - 1)
        l_prime = random.randint(0, 10**5 - 1)
        queries.append((x_prime, l_prime))

    # Output the test case.
    print(n, m, q)
    for u, v, k in edges:
        print(u, v, k)
    for x_prime, l_prime in queries:
        print(x_prime, l_prime)

if __name__ == '__main__':
    main()