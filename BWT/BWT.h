#pragma once
#include <bits/stdc++.h>
#include "../YKKONEN/CPP/Node.cpp"
#include "../YKKONEN/CPP/Ykkonen.cpp"

struct BWT {
    Node* root;
    std::vector<int> t;
    BWT(const std::vector<int>& t);
    BWT(const std::string& t);
    void init(const std::vector<int>& t);
    std::pair<std::vector<int>, int> coderVector();
    std::pair<std::string, int> coderString();
    int dfs(Node* v, std::vector<int>& result, int& k, bool flag, int rank, int maxRank);
    Ykkonen ykkonen;
};

std::string decoder(const std::string& _data_, int k);
std::vector<int> decoder(const std::vector<int>& _data_, int k);
