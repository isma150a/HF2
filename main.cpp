#include <iostream>

#include "HFPatch.h"
#include "HFForest.h"

using namespace std;

int main()
{
    // cout << "Hello World!" << endl;

    HFPatch patches;

    patches.setnClasses(5);
    // cout << patches.getnClasses() << endl;

    vector<double> features;
    features.push_back(1);
    features.push_back(2);
    features.push_back(3);
    features.push_back(4);
    vector<double> features2(4,20);
    vector<double> features3(4,30);
    double centers[3] = {1,5,2};

    // cout << patches.getnFeatures() << endl;

    patches.addPatch(features, 1, centers);
    patches.addPatch(features2, 1, centers);
    patches.addPatch(features3, 1, centers);

    patches.addPatch(features, 2, centers);
    patches.addPatch(features2, 2, centers);
    patches.addPatch(features3, 2, centers);

    patches.show();

    // HFForest forest(5);
    //forest.trainForest(5,5,patches,5,5);


    return 0;
}

