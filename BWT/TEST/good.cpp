#include <bits/stdc++.h>
using namespace std;



void source(string& t) {
    string doubleT = t + t;
    std::vector<std::string> T;

    for (int i = 0; i < t.size(); ++i) {
        string result;
        for (int j = 0; j < t.size(); ++j)
            result += doubleT[i + j];
        T.push_back(result);
    }
    sort(T.begin(), T.end());
    string result;
    for (auto& s : T) result += s.back();
    int k;
    for (int i = 0; i < T.size(); ++i)
        if (T[i] == t) { k = i; break; }
    std::cout << result << " " << k << '\n';
}


int main() {
    int m; std::cin >> m;
    while (m--) {
        string t; std::cin >> t;
        source(t);
    }


    return 0;
}