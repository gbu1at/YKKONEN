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


	int n = 1000;
	auto t = rndVec(n, k);
	for (int x : t) std::cout << x; std::cout << '\n';

	int m = 100;
	std::cout << m << '\n';
	while (m--) {
		int x = min((rand() % 30) + 1, n);
		auto a = rndVec(x, k);
	    for (int x : a) std::cout << x; std::cout << '\n';	
	}


	return 0;
}