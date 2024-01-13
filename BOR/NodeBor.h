#pragma once
#include <bits/stdc++.h>

struct NodeBor {
    NodeBor() {}
    bool stop = false;
    std::map<int, NodeBor*> children;
    bool findChild(int value);
    NodeBor* get(int value);
    NodeBor* createChild(int value);
};
