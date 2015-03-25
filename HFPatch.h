#ifndef HFPATCH_H
#define HFPATCH_H

#include <vector>
#include <iostream>

using namespace std;

// structure for image patch
struct PatchFeature {           // Pi
  vector<double> features;      // Ii
  unsigned int label;           // Ci
  double centers[3];            // Di
};


class HFPatch
{
public:
    // constructor
    HFPatch();
    ~HFPatch();

    // get/set functions
    void setnClasses(unsigned int nLabels);
    unsigned int getnClasses();
    void setnPatches(unsigned int nLabels, unsigned int nPatches);
    unsigned int getnPatches(unsigned int nLabel);
    unsigned int getnFeatures();


    // other functions
    void addPatch(vector<double> fetures, unsigned int label, double centers[3]);
    void addPatch(vector<double> fetures);
    void addPatch(PatchFeature patch);
    void show(unsigned int label, unsigned int path);
    void show();


private:
    int nFeatures;
    int isEmpty;
    vector<vector<PatchFeature> > HFPatches;
};

#endif // HFPATCH_H
