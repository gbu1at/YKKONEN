#include <bits/stdc++.h>
using namespace std;



void source(string& t) {
    string a; std::cin >> a;

    bool flag = false;
    for (int i = 0; i <= t.size() - a.size(); ++i) {
        bool f = true;
        for (int j = 0; j < a.size(); ++j) if (t[i + j] != a[j]) f = false;
        if (f) flag = true;
    }

    if (flag) std::cout << "YES\n";
    else std::cout << "NO\n";
}


int main() {
    string t; std::cin >> t;

    int m; std::cin >> m;
    while (m--) source(t);


    return 0;
}