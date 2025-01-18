#include "BinarySearchTree.h"
#include <iostream>

namespace tree {
    BinarySearchTree::BinarySearchTree(int value) {
        node_value = value;
        left = nullptr;
        right = nullptr;
    }

    BinarySearchTree::~BinarySearchTree() {
        delete left;
        delete right;
    }


    void BinarySearchTree::insert(int value) {
        if (value < node_value) {
            if (!left) {
                left = new BinarySearchTree(value);
            } else {
                left->insert(value);
            }
        } else {
            if (!right) {
                right = new BinarySearchTree(value);
            } else {
                right->insert(value);
            }
        }
    }

    bool BinarySearchTree::search(int value) {
        if (node_value == value) {
            return true;
        }
        if (value < node_value && left) {
            return left->search(value);
        }
        if (value > node_value && right) {
            return right->search(value);
        }
        
        return false;
    }
}