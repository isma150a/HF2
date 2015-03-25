#ifndef HFTREE_H
#define HFTREE_H

#include <vector>
#include "HFPatch.h"

using namespace std;


struct LeafNode {
  // Constructors
  LeafNode() {}

  // Probability of class
  vector<float> vPrLabel;

  // Vectors from object to training patches <label><patch><dimension>
  // where dimension stands for x,y,t
  vector<vector<vector<float> > > vCenter;
};


class HFTree
{
public:
    HFTree(int min_s, int max_d, unsigned int labels, int splits, int seed);
    ~HFTree();

    // get/set functions
    unsigned int getDepth() const;
    unsigned int getNumLabels() const;


private:
    // Data structure

    // tree table
    // 2^(max_depth+1)-1 x 9 matrix as vector
    // column: leafindex x1 y1 t1 x2 y2 t2 channel thres
    // if node is not a leaf, leafindex=-1
    int* treetable;

    // stop growing when number of patches is less than min_samples
    unsigned int min_samples;

    // depth of the tree: 0-max_depth
    unsigned int max_depth;

    // number of nodes: 2^(max_depth+1)-1
    unsigned int num_nodes;

    // number of leafs
    unsigned int num_leaf;

    // number of labels (classes)
    unsigned int num_labels;

    // number of splits
    unsigned int num_splits;

    //leafs as vector
    LeafNode* leaf;

    // seed to generate random numbers
    int seed;
};

#endif // HFTREE_H
