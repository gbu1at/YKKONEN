#pragma once
#include "HuffmanCode.h"
#include "../BOR/Bor.cpp"


HuffmanCode::HuffmanCode(const std::string& _data_) {
    this->t = _data_;
    for (int value : _data_) aplphabet[value]++;
    for (auto p : aplphabet)
        values.push_back(p);

    sort(values.begin(), values.end(), [] (const std::pair<int, int>& a, const std::pair<int, int>& b) { return a.second > b.second; }); 
}

void HuffmanCode::FirstRecursion(int l, int r) {
    if (l == r - 1) return;
    int sum = 0;
    for (int i = l; i < r; ++i) sum += values[i].second;
    
    int prefSum = 0;
    int m = l;
    while (2 * prefSum < sum) {
        prefSum += values[m].second;
        code[values[m].first] += '1';
        m++;
    }
    for (int i = m; i < r; ++i) code[values[i].first] += '0';

    FirstRecursion(l, m);
    FirstRecursion(m, r);
}

std::string HuffmanCode::getNewData() {
    std::string result = "";
    for (int value : t)
        result += code[value];
    return result;
}

std::string HuffmanCode::huffmanCodeFirst() {
    if (values.size() == 1) code[values[0].first] = '0';
    else FirstRecursion(0, values.size());

    for (auto&[key, code] : code) newAlphabet[code] = key;
    
    return getNewData();
}

std::string HuffmanCode::huffmanCodeSecond() {

}


std::string HuffmanCode::decoder(const std::string& _data_) {
    Bor bor;
    for (auto[key, value] : code) bor.add(value);

    std::string result;

    int i = 0;
    while (i != _data_.size()) {
        std::string value = bor.generator(i, _data_);
        i += value.size();

        result += newAlphabet[value];
    }

    return result;
}
