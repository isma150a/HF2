#include "HFForest.h"

HFForest::HFForest(int nTrees)
{
    vTrees.resize(nTrees);
}

HFForest::~HFForest()
{
    vTrees.clear();
}


// get/set functions
void HFForest::setTrees(int n) {vTrees.resize(n);}    // create trees
unsigned int HFForest::getSize() {return vTrees.size();}       // get size of trees
unsigned int HFForest::getDepth() {return vTrees[0]->getDepth();}
unsigned int HFForest::getNumLabels() {return vTrees[0]->getNumLabels();}


// other functions
//Training
void HFForest::trainForest(int min_s, int max_d, HFPatch& TrData, int splits, int seed){
    for(int i=0; i < (int)vTrees.size(); ++i) {

      // this constructor found in the header file HFTree.h
        // min_s - minimum number of samples
        // max_d - maximum depth to grow tree
        // Trdata.vLPatches.size() - number of labels
        // splits - binary test number per node
        // seed - to generate random numbers
      vTrees[i] = new HFTree(min_s, max_d, TrData.getnClasses(), splits, seed);
      // std::cout << vTrees[i]->getDepth() << std::endl;

        // TrData - all data for training
      // vTrees[i]->growTree(TrData);

    }
}


