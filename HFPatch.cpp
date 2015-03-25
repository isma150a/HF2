#include "HFPatch.h"

using namespace std;



HFPatch::HFPatch(){
    this->isEmpty = 1;
    this->nFeatures = 0;
}

HFPatch::~HFPatch(){
    for (int i = 0; i < HFPatches.size(); ++i)
        HFPatches[i].clear();

    isEmpty = 0;
    nFeatures = 0;
}


// get/set functions
unsigned int HFPatch::getnClasses(){ return HFPatches.size();}
void HFPatch::setnClasses(unsigned int nLabels) { HFPatches.resize(nLabels);}
unsigned int HFPatch::getnPatches(unsigned int nLabel){
    if (nLabel <= HFPatches.size()){
        return HFPatches[nLabel].size();
    }
}
void HFPatch::setnPatches(unsigned int nLabel, unsigned int nPatches){
    if (nLabel <= HFPatches.size()){
        HFPatches[nLabel].resize(nPatches);
    }
}
unsigned int HFPatch::getnFeatures(){ return nFeatures;}



// Other functions
void HFPatch::addPatch(vector<double> features, unsigned int label, double centers[3]){
    PatchFeature auxP;
    auxP.features = features;
    auxP.label = label;
    auxP.centers[0] = centers[0];
    auxP.centers[1] = centers[1];
    auxP.centers[2] = centers[2];

    if (label <= HFPatches.size()){
        if (isEmpty){
            HFPatches[label].push_back(auxP);
            isEmpty = 0;
            nFeatures = auxP.features.size();
        }else{
            if (nFeatures == auxP.features.size())
                HFPatches[label].push_back(auxP);
            else
                cout << "The size features does not math" << endl;
        }
    }else{
        cout << " Error size" << endl;
    }
}

void HFPatch::addPatch(vector<double> features){
    PatchFeature auxP;
    auxP.features = features;
    auxP.label = 0;                        // Unknow label
    auxP.centers[0] = 0;
    auxP.centers[1] = 0;
    auxP.centers[2] = 0;                    // Unknow center

    if (isEmpty){
        HFPatches[auxP.label].push_back(auxP);
        isEmpty = 0;
        nFeatures = auxP.features.size();
    }else{
        if (nFeatures == auxP.features.size())
            HFPatches[0].push_back(auxP);
        else
            cout << "The size features does not math" << endl;
    }
}

void HFPatch::addPatch(PatchFeature path){
    int label = path.label;
    if (label == -1)
        label = 0;

    if (label <= HFPatches.size()){
        if (isEmpty){
            HFPatches[label].push_back(path);
            isEmpty = 0;
            nFeatures = path.features.size();
        }else{
            if (nFeatures == path.features.size())
                HFPatches[label].push_back(path);
            else
                cout << "The size features does not math" << endl;
        }
    }else{
        cout << " Error size" << endl;
    }
}


void HFPatch::show(unsigned int label, unsigned int patch){
    if (label <= HFPatches.size() && patch<HFPatches[label].size() ){
        double x = HFPatches[label][patch].centers[0];
        double y = HFPatches[label][patch].centers[1];
        double t = HFPatches[label][patch].centers[2];

        cout << " C(" << patch << ")=" << label << ", D(" << patch << ")=(" << x
             << "," << y << "," << t << "), I(" << patch << ")=(";

        for(int i=0; i< HFPatches[label][patch].features.size(); ++i){
            cout << HFPatches[label][patch].features[i] << ", ";
        }

        cout << ")" << endl;
    }

}

void HFPatch::show(){
    if (!isEmpty){
        for (int label = 0; label <= HFPatches.size(); ++label){
            for (int patch = 0; patch <= HFPatches[label].size(); ++patch)
                show(label, patch);
        }
    }
}


