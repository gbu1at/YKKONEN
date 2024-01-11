#include <bits/stdc++.h>
#include "LZ77.cpp"


std::string randStr(int n) {
    std::string res;
    // int n = 6;
    for (int i = 0; i < n; ++i) {
        int c = rand() % 2;
        res += toString(c);
    }
    return res;
}



int main() {
    
    #ifdef TIME
        int start = clock();
    #endif
    int n = 1;
    while (n--) {
        std::string t = randStr(10000); 
        std::cout << "-----START BUILD LZ77----\n";
        std::string a = LZ77<std::string>().compress(t);
        std::cout << "-----FINISH BUILD LZ77----\n";
        std::cout << "-----START CHECK CORRECT DECODER----\n";
        std::cout << a << '\n';
        assert(decoder(a) == t);
        std::cout << "-----DECODER IS CORRECT----\n";
        std::cout << t.size() << " / " << a.size() << '\n';
    }
    #ifdef TIME
        int finish = clock();
        std::cout << (finish - start) / (double) CLOCKS_PER_SEC << '\n';
    #endif

	return 0;
}