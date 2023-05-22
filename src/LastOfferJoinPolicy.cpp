#include <vector>
using std::vector;
#include "Offer.h"
#include "JoinPolicy.h"
#include "Simulation.h"

class Coalition;
class Offer;

Offer LastOfferJoinPolicy::join(vector<Offer> theOffers,Simulation &sim){
   Offer chosenAgent = theOffers.back();
   return chosenAgent;
}
JoinPolicy* LastOfferJoinPolicy::clone(){return new LastOfferJoinPolicy();}

