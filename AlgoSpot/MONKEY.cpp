//
//  main.cpp
//  AlgoSpot_MONKEY
//
//  Created by Young Duke Koh on 11/13/17.
//  Copyright © 2017 Young Duke Koh. All rights reserved.
//
// https://algospot.com/judge/problem/read/MONKEY

#include <iostream>
#include <cstring>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

char buffer[151];

int gcd(int a, int b) {
    int c;
    
    while (a != 0) {
        c = a;
        a = b % a;
        b = c;
    }
    
    return b;
}

void freeNodes(Node* node) {
    if (node == NULL) return;
    freeNodes(node->left);
    freeNodes(node->right);
    delete node;
}

void buildNodes(Node* parent, int start, int end) {
    int i, c, n;
    
    if (start >= end) return;
    
    parent->left = new Node();
    parent->right = new Node();
    
    c = 0;
    n = -1;
    for (i = start + 1; i < end; i++) {
        if (buffer[i] == '[') {
            c++;
        } else {
            c--;
            if (c == 0) {
                n = i;
                break;
            }
        }
    }
    
    if (start < n && n < end) {
        buildNodes(parent->left, start + 1, n);
        buildNodes(parent->right, n + 1, end - 1);
    }
}

int calcNodes(Node* node) {
    int a, b;
    
    if (node == NULL) return 0;
    if (node->left == NULL && node->right == NULL) return 1;
    
    a = calcNodes(node->left);
    b = calcNodes(node->right);
    
    if (a != b) {
        a = a * b / gcd(a, b);
        b = a;
    }
    
    return a + b;
}

int solve() {
    Node* root;
    int ans;
    
    ans = 0;
    
    root = new Node();
    
    buildNodes(root, 0, (int)strlen(buffer) - 1);
    
    ans = calcNodes(root);
    
    freeNodes(root);
    
    return ans;
}

int main(int argc, const char * argv[]) {
    int n, i, k;
    char c;
    
    scanf("%d", &n);
    scanf("%c", &c);
    k = 1;
    while (n--) {
        i = 0;
        while (true) {
            scanf("%c", &c);
            if (c == '\n') {
                buffer[i] = 0;
                break;
            } else {
                buffer[i] = c;
                i++;
            }
        }
        printf("%d %d\n", k, solve());
        k++;
    }
    
    return 0;
}

/*
3
[]

[[][[]]]
=====
1 2
2 1
3 8
*/
