#ifndef HFFOREST_H
#define HFFOREST_H

#include <vector>
#include "HFTree.h"


class HFForest
{
public:
    HFForest(int nTrees = 0);
    ~HFForest();

    // Set/Get functions
    void setTrees(int n);         // create trees
    unsigned int getSize();       // get size of trees
    unsigned int getDepth();
    unsigned int getNumLabels();

    // other funcions
    void trainForest(int min_s, int max_d, HFPatch& TrData, int splits, int seed);


private:
    // Trees
    std::vector<HFTree*> vTrees;
};

#endif // HFFOREST_H
