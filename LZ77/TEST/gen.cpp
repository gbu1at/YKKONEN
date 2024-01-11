#include <bits/stdc++.h>
using namespace std;

vector<int> rndVec(int n, int m) {
	vector<int> s(n);
	for (int i = 0; i < n; ++i)
		s[i] = (rand() % m);
	return s;
}


int main(int argc, char** argv) {
	int seed = atoi(argv[1]);
	srand(seed);
	
	int k = 2;


	
	int m = 1000;
	std::cout << m << '\n';
	while (m--) {
		int n = 100;
		auto t = rndVec(n, k);
		for (int x : t) std::cout << x; std::cout << '\n';
	}


	return 0;
}