#pragma once
#include <bits/stdc++.h>
#include <H/Ykkonen.h>
#include "H/Node.h"
#include "H/Edge.h"


void Ykkonen::build() {
    Node* activeNode = root;
    Edge activeEdge;
    int deepEdge = 0;

    for (int i = 0; i < t.size(); ++i) {
        Node* prefSuffix = nullptr;
        int nextLetter = t[i]; 
        while (true) {
            if (deepEdge == 0) {
                if (activeNode->find(nextLetter)) {
                    activeEdge = activeNode->get(nextLetter);
                    deepEdge++;
                    if (activeEdge.len() == deepEdge) {
                        activeNode = activeEdge.to;
                        deepEdge = 0;
                    }
                    break;
                }
                activeNode->createSuffixEnd(nextLetter, i, &t);
                if (activeNode == root) break;
                activeNode = activeNode->suffixLink;
            } else {
                if (activeEdge.get(deepEdge) == nextLetter) {
                    deepEdge++;
                    if (activeEdge.len() == deepEdge) {
                        activeNode = activeEdge.to;
                        deepEdge = 0;
                    }
                    break;
                }
                Node* newNode = activeEdge.cut(deepEdge);
                newNode->createSuffixEnd(nextLetter, i, &t);
                if (prefSuffix != nullptr) prefSuffix->suffixLink = newNode;
                prefSuffix = newNode;
                activeEdge = newNode->get(activeEdge.firstLetter());
                int firstIndexEdge = activeEdge.l;
                if (activeNode == root) {
                    firstIndexEdge++;
                    deepEdge--;
                } else activeNode = activeNode->suffixLink;

                while (deepEdge > 0 && deepEdge >= activeNode->get(t[firstIndexEdge]).len()) {
                    activeEdge = activeNode->get(t[firstIndexEdge]);
                    deepEdge -= activeEdge.len();
                    firstIndexEdge += activeEdge.len();
                    activeNode = activeEdge.to;
                }
                if (deepEdge == 0) {
                    prefSuffix->suffixLink = activeNode;
                    prefSuffix = activeNode;
                } 
            }
        }
    }
}


Ykkonen::Ykkonen(const std::string& _data_) {
    std::vector<int> convertToInt = stringToVector(_data_);
    convertToInt.push_back(INT_MAX);
    settingData(convertToInt);
}

Ykkonen::Ykkonen(const std::vector<int>& _data_) {
    settingData(_data_);
}

void Ykkonen::settingData(const std::vector<int>& _data_) {
    this->t = _data_;
}

bool Ykkonen::find(const std::vector<int>& _data_) {
    Node* activeNode = root;
    Edge activeEdge;
    int deepEdge = 0;
    for (int letter : _data_) {
        if (deepEdge == 0) {
            if (!activeNode->find(letter)) return false;
            activeEdge = activeNode->get(letter);
            deepEdge++;
        } else {
            if (activeEdge.get(deepEdge) != letter) return false;
            deepEdge++;
        }
        if (activeEdge.len() == deepEdge) {
            deepEdge = 0;
            activeNode = activeEdge.to;
        }
    }
    return true;
}

bool Ykkonen::find(const std::string& _data_) {
    return find(stringToVector(_data_));
}