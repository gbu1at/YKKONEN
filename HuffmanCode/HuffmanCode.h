#pragma once
#include <bits/stdc++.h>

struct HuffmanCode {
    std::map<int, int> aplphabet;
    std::map<int, std::string> code;
    std::map<std::string, int> newAlphabet;
    std::vector<std::pair<int, int>> values;
    std::string t;
    HuffmanCode(const std::string& data);
    std::string huffmanCodeFirst();
    void FirstRecursion(int left, int right);
    std::string huffmanCodeSecond();
    std::string getNewData();
    std::string decoder(const std::string& _data_);
};