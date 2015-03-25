#include <vector>
#include <math.h>
#include "HFTree.h"

using namespace std;

HFTree::HFTree(int min_s, int max_d, unsigned int labels, int splits, int seedNum){
    min_samples = min_s;
    max_depth = max_d;
    num_labels = labels;
    num_splits = splits;
    seed = seedNum;

    num_nodes = (int)pow(2.0,int(max_depth+1))-1;

    // currently x 9 to keep extra 2 time variables
    treetable = new int[num_nodes * 9];
    for(unsigned int i=0; i<num_nodes * 9; ++i) treetable[i] = 0;

    // allocate memory for leafs
    leaf = new LeafNode[(int)pow(2.0,int(max_depth))];
}

HFTree::~HFTree(){
    delete[] leaf;
    delete[] treetable;
}


// get/set functions
unsigned int HFTree::getDepth() const {return max_depth;}
unsigned int HFTree::getNumLabels() const {return num_labels;}



// other functions

