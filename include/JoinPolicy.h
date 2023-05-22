#pragma once
#include <vector>
using std::vector;
class Agent;
class Simulation;
class Offer;

class JoinPolicy {
    public:
    virtual Offer join(vector<Offer> theOffers, Simulation &sim)=0;
    virtual JoinPolicy* clone()=0;
    virtual ~JoinPolicy(){};
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
    virtual Offer join(vector<Offer> theOffers, Simulation &sim);
    virtual JoinPolicy* clone();
};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
   virtual  Offer join(vector<Offer> theOffers,  Simulation &sim);
   virtual JoinPolicy* clone();
};