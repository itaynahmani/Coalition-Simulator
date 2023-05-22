#include <vector>
#include "Simulation.h"
#include "JoinPolicy.h"
#include "Offer.h"
#include "Coalition.h"


Offer MandatesJoinPolicy :: join(vector<Offer> theOffers, Simulation &sim){
    int maxIndex=0;
    int maxMandates = theOffers[0].getCoalition()->getMandates();
    int size = theOffers.size();
    for(int i=1;i<size;i++){
        int currMandates = theOffers[i].getCoalition()->getMandates();
        if(maxMandates<currMandates){
            maxIndex=i;
            maxMandates=currMandates;
        }
    }
    return theOffers[maxIndex];
    

}
JoinPolicy* MandatesJoinPolicy::clone(){ return new MandatesJoinPolicy();}