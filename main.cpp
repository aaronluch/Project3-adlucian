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
#include <algorithm>
#include <random>
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
    outFile << "Value,BST Depth,AVL Depth,Splay Depth" << endl; // Add labels

    // Loop to find each integer in order
    for (int k = 1; k <= 100; k++) {
        int depthBST = 0;
        int depthAVL = 0;
        int depthSplay = 0;

        // Find the integer and record the depth
        bst1.find(k, depthBST);
        avl1.find(k, depthAVL);
        splayTree1.find(k, depthSplay);

        // Record the depths to the output file
        outFile << k << "," << depthBST << "," << depthAVL << "," << depthSplay << endl;
    }
    outFile.close(); // Close current outFile

    // Check understanding with BST print statements
    int depth0 = 0;
    bool found0 = bst1.find(0, depth0);
    if (found0) {
        cout << "Found 0 in the BST with depth " << depth0 << endl;
    } else {
        cout << "0 not found in the BST" << endl;
    }

    int depth101 = 0;
    bool found101 = bst1.find(101, depth101);
    if (found101) {
        cout << "Found 101 in the BST with depth " << depth101 << endl;
    } else {
        cout << "101 not found in the BST" << endl;
    }

    int depth102 = 0;
    bool found102 = bst1.find(102, depth102);
    if (found102) {
        cout << "Found 102 in the BST with depth " << depth102 << endl;
    } else {
        cout << "102 not found in the BST" << endl;
    }

    // Get rid of trees
    bst1.timber();
    avl1.timber();
    splayTree1.timber();

    // Create a vector of numbers 1 to 100
    vector<int> numbers(100);
    for(int i = 1; i <= 100; i++){
        numbers[i - 1] = i;
    }

    // Shuffle the vector
    // ref: https://www.geeksforgeeks.org/stdmt19937-class-in-cpp/
    std::random_device rd;
    std::mt19937 randomizer(rd());
    std::shuffle(numbers.begin(), numbers.end(), randomizer);

    // Create Binary Search Tree, AVL Tree, and Splay Tree
    BinarySearchTree<int> bst2;
    AVLTree<int> avl2;
    SplayTree<int> splayTree2;

    // Insert the shuffled integers into the trees
    for (int num : numbers) {
        bst2.add(num);
        avl2.add(num);
        splayTree2.add(num);
        cout << num << endl;
    }

    // Open a file for recording depths
    ofstream outFile2("../data/depths-output-2.csv");
    outFile2 << "Value,BST Depth,AVL Depth,Splay Depth" << endl; // Add labels

    // Loop to find each integer in order and record depths
    for (int j = 1; j <= 100; j ++) {
        int depthBST = 0;
        int depthAVL = 0;
        int depthSplay = 0;

        // Find the integer and record the depth
        bst2.find(j, depthBST);
        avl2.find(j, depthAVL);
        splayTree2.find(j, depthSplay);

        // Record the depths to the output file
        outFile2 << j << "," << depthBST << "," << depthAVL << "," << depthSplay << endl;
    }

    // Close the output file
    outFile2.close();

    return 0;
}