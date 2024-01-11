#pragma once
#include <bits/stdc++.h>
#include "Node.h"



struct Ykkonen {
    Node* root = new Node();
    std::vector<int> t;
    Ykkonen() {}
    Ykkonen(const std::string& _data_);
    Ykkonen(const std::vector<int>& _data_);
    void init(const std::vector<int>& _data_);
    void build();
    void reInit(const std::vector<int>& _data_);
    bool find(const std::vector<int>& _data);
    bool find(const std::string& _data);
    std::vector<int> stringToVector(const std::string& s);
};