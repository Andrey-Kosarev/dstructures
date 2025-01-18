#pragma once
#include <memory>

namespace tree {
    class BinarySearchTree {
    public:
        BinarySearchTree(int value = 0);
        ~BinarySearchTree();
        
        void insert(int value);
        bool search(int value);
    
        int node_value;
        BinarySearchTree* left;
        BinarySearchTree* right;
    };
}