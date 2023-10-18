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

int main(){
    // Create a vector to store the Song objects
    vector<Song> songs;

    // Create BST, AVL Tree and Splay Trees with type int
    BinarySearchTree<int> bst1;
    AVLTree<int> avl1;
    SplayTree<int> splayTree1;

    // Read data from the CSV into the vector
    getDataFromFile(songs);

    // Loop to add integers 1 - 100 in order to each tree
    for (int i = 0; i <= 100; i++){
        if (!bst1.add(i)){
            cout << "Could not add " << i << " to the BST tree" << endl;
        }

        if (!avl1.add(i)){
            cout << "Could not add " << i << " to the AVL tree" << endl;
        }

        if (!splayTree1.add(i)){
            cout << "Could not add " << i << " to the Splay tree" << endl;
        }
    }

    // Open file for depths to record to
    ofstream outFile;
    outFile.open("../data/initial-depths-output.csv");
    outFile << "Index,BST Depth,AVL Depth,Splay Depth" << endl; // Add labels

    // Loop to find each integer in order
    for (int k = 0; k < 100; ++k){
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
    cout << "\nTesting Understanding of BST / Tree Functionality:" << endl;
    int depth0 = 0;
    bool found0 = bst1.find(0, depth0);
    if (found0){
        cout << "Found 0 in the BST with depth " << depth0 << endl;
    }
    else{
        cout << "0 not found in the BST, reached depth " << depth0 << endl; // print the depth even if not found
    }

    int depth101 = 0;
    bool found101 = bst1.find(101, depth101);
    if (found101){
        cout << "Found 101 in the BST with depth " << depth101-1 << endl;
    }
    else{
        cout << "101 not found in the BST, reached depth " << depth101-1 << endl; // print the depth even if not found
    }

    int depth102 = 0;
    bool found102 = bst1.find(102, depth102);
    if (found102){
        cout << "Found 102 in the BST with depth " << depth102-1 << endl;
    }
    else{
        cout << "102 not found in the BST, reached depth " << depth102-1 << endl; // print the depth even if not found
    }

    // Get rid of trees
    bst1.timber();
    avl1.timber();
    splayTree1.timber();

    // Create a vector of numbers 1 to 100
    vector<int> shuffledNumbers(100);
    for(int i = 1; i <= 100; i++){
        shuffledNumbers[i - 1] = i;
    }

    // Shuffle the vector
    std::random_device rd;
    std::mt19937 randomizer(rd());
    std::shuffle(shuffledNumbers.begin(), shuffledNumbers.end(), randomizer);

    // Create Binary Search Tree, AVL Tree, and Splay Tree
    BinarySearchTree<int> bst2;
    AVLTree<int> avl2;
    SplayTree<int> splayTree2;

    // Insert the shuffled integers into the trees
    for(int num : shuffledNumbers){
        int insert = shuffledNumbers[num];

        if (!bst2.add(insert)){
            cout << "Could not add " << insert << " to the BST tree" << endl;
        }

        if (!avl2.add(insert)){
            cout << "Could not add " << insert << " to the AVL tree" << endl;
        }

        if (!splayTree2.add(insert)){
            cout << "Could not add " << insert << " to the Splay tree" << endl;
        }
    }

    // printing first 10 values of Shuffled Numbers below
    cout << "--------\nFirst Ten Values from Shuffled Numbers: " << endl;
    for(int firstTen = 0; firstTen <= 10; firstTen++){
        cout << "Value [" << firstTen+1 << "]: " << shuffledNumbers[firstTen] << endl;
    }
    cout << "--------" << endl;

    // Open a file for recording depths
    ofstream outFile2("../data/shuffled-depths-output.csv");
    outFile2 << "Index,BST Depth,AVL Depth,Splay Depth" << endl; // Add labels

    // Loop to find each integer in order and record depths
    for (int j = 0; j < 100; ++j){
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

    // Get rid of trees again
    bst2.timber();
    avl2.timber();
    splayTree2.timber();

    // Create BST, AVL and Splay Tree for my custom data type
    BinarySearchTree<Song> songBST;
    AVLTree<Song> songAVL;
    SplayTree<Song> songSPLAYTREE;

    // Loop to insert all songs into each tree
    for (const Song& song : songs){
        if (!songBST.add(song)){
            cout << "Could not add " << song << " to the BST tree" << endl;
        }

        if (!songAVL.add(song)){
            cout << "Could not add " << song << " to the AVL tree" << endl;
        }

        if (!songSPLAYTREE.add(song)){
            cout << "Could not add " << song << " to the Splay tree" << endl;
        }
    }

    // Check sizes of trees to make sure data was stored correctly
    cout << "Check sizes of trees to make sure data was stored correctly:" << endl;
    if(songBST.getSize() && songAVL.getSize() && songSPLAYTREE.getSize() == songs.size()){
        cout << "Song BST size: " << songBST.getSize() << endl;
        cout << "Song AVL size: " << songAVL.getSize() << endl;
        cout << "Song Splay Tree size: " << songSPLAYTREE.getSize() << endl;
    }
    else{
        cout << "Wrong size recorded -- Problem occurred..." << endl;
    }
    cout << "Song Vector Total size: " << songs.size() << endl;

    // Open a file for recording depths
    ofstream outFile3("../data/songs-depths-output.csv");
    outFile3 << "Row ID [Index],BST Depth,AVL Depth,Splay Depth" << endl; // Add labels

    // Loop to find each integer in order and record depths
    for (int l = 0; l < songs.size(); ++l){
        int depthBST = 0;
        int depthAVL = 0;
        int depthSplay = 0;

        // Find the integer and record the depth
        songBST.find(songs[l], depthBST);
        songAVL.find(songs[l], depthAVL);
        songSPLAYTREE.find(songs[l], depthSplay);

        // Record the depths to the output file
        outFile3 << songs[l].getRowId() << "," << depthBST << "," << depthAVL << "," << depthSplay << endl;
    }

    // Close outfile
    outFile3.close();

    // Get rid of trees again
    songBST.timber();
    songAVL.timber();
    songSPLAYTREE.timber();

    // Create another Splay Tree with Song data type
    SplayTree<Song> anotherSongSplayTree;
    // Add 1000+ objects to this Splay Tree
    for (const Song& song : songs){
        if (!anotherSongSplayTree.add(song)){
            cout << "Could not add " << song << " to the Splay Tree tree" << endl;
        }
    }

    // Open a file for recording depths
    ofstream outFile4("../data/another-splayTree-depths.csv");
    outFile4 << "Row ID [Index],Splay Depth" << endl; // Add labels

    // Find each object five times in a row
    for (int p = 0; p < songs.size(); p++){
        // Loop to find each object five times before the next
        for (int i = 1; i <= 5; i++){
            int depthSplay = 0;
            anotherSongSplayTree.find(songs[p], depthSplay);
            // Record the depths to the output file
            outFile4 << songs[p].getRowId() << "," << depthSplay << endl;
        }
    }
    // Close outfile
    outFile4.close();

    // Get rid of this Splay Tree
    anotherSongSplayTree.timber(); // TIMMMMMBERRRRRR!!!!!!!

    return 0;
}