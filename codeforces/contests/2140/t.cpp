#include "testlib.h"
#include <set>

int main(int argc, char **argv) {
	registerTestlibCmd(argc, argv);

	int n_tests = inf.readInt();

	while (n_tests--) {
		int n = inf.readInt();
		inf.readSpace();
		int m = inf.readInt();
		inf.readEoln();
		
		std::set<int> s;

		for (int _ = 0; _ < n; _++) {
			k = ouf.readInt(1, n);
			if (s.find(k) != s.end()) {
				quitf(_wa, "Number %d appeared more than once", k);
			}
		}
	}

	quitf(_ok, "The permutations are correct");
}