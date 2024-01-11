#include <bits/stdc++.h>
#include "BWT.cpp"

int main() {
    int m ; std::cin >> m;
    while (m--) {
        std::string t; std::cin >> t;
        BWT bwt(t);
        auto[result, k] = bwt.coder();
        std::cout << result << " " << k << '\n';
        if (decoder(result, k) != t) std::cout << "------ERROR------\n";
    }
    return 0;
}