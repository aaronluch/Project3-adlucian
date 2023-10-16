/**
 * Aaron Luciano
 * CS2240
 * Section A
 * 10-16-2023
 * Project 3
 */
#include "AVLTree.h"
#include "BinarySearchTree.h"
#include "SplayTree.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "Song.h"
using namespace std;

int main() {
    // Create a vector to store the Song objects
    vector<Song> songs;

    // Create BST, AVL Tree and Splay Trees with type int
    BinarySearchTree<int> bst1;
    AVLTree<int> avl1;
    SplayTree<int> splayTree1;

    // Read data from the CSV into the vector
    getDataFromFile(songs);

    // Loop to add integers 1 - 100 in order to each tree
    for(int i = 0; i <= 100; i++){
        bst1.add(i);
        avl1.add(i);
        splayTree1.add(i);
    }

    // Open file for depths to record to
    ofstream outFile;
    outFile.open("../data/depths-output-1.csv");

    // Loop to find each integer in order
    int depth = 0; // Initialize depth
    bool found = bst1.find(13, depth);

    if (found) {
        cout << "Value found at depth: " << depth << endl;
    } else {
        cout << "Value not found." << endl;
    }

    //for(int k = 0; k <= 100; k ++) {
    //}

/*
    // Example of how to declare and use a tree object
    BinarySearchTree<int> bst1;
    if (!bst1.add(8)) {
        cout << "Could not add 8 to the tree." << endl;
    }
    if (bst1.find(8)) {
        cout << "Found 8 in the tree." << endl;
    }
    if (bst1.getSize() != 1) {
        cout << "There are " << bst1.getSize() << " nodes in the tree." << endl;
    } else {
        cout << "There is one node in the tree." << endl;
    }
    bst1.timber();
    */

    return 0;
}