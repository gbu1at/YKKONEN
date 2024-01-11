#include <bits/stdc++.h>
#include "../YKKONEN/CPP/Ykkonen.cpp"

int main() {
    std::string t; std::cin >> t;
    Ykkonen ykkonen(t);
    int m; std::cin >> m;
    while (m--) {
        std::string a; std::cin >> a;
        std::cout << (ykkonen.find(a) ? "YES" : "NO") << '\n';
    }
}

