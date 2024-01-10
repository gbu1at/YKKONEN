#pragma once
#include <bits/stdc++.h>
#include <Node.h>



struct Ykkonen {
    Node* root = new Node();
    std::vector<int> t;
    Ykkonen(const std::string& _data_);
    Ykkonen(const std::vector<int>& _data_);
    void settingData(const std::vector<int>& _data_);
    void build();
    bool find(const std::vector<int>& _data);
    bool find(const std::string& _data);
    std::vector<int> stringToVector(const std::string& s);
};