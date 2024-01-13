#pragma once
#include <bits/stdc++.h>
#include "NodeBor.h"


struct Bor {
    Bor() {}
    NodeBor* root = new NodeBor();
    void add(const std::string& _data_);
    std::string generator(int start, const std::string& _data_);
};
