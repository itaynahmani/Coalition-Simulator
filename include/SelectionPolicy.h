#pragma once
#include "Simulation.h"


class Party;
class Simulation;

class SelectionPolicy {
    public:
    virtual Party* select(vector<Party*> potentialParties, int partyId, Simulation &sim)=0;
     virtual SelectionPolicy* clone()=0;
     virtual ~SelectionPolicy(){};
 };

class MandatesSelectionPolicy: public SelectionPolicy{ 
    public:
     virtual Party* select(vector<Party*> potentialParties, int partyId, Simulation &sim);
     virtual SelectionPolicy* clone();
 
};
class EdgeWeightSelectionPolicy: public SelectionPolicy{ 
     public:
     virtual Party* select(vector<Party*> potentialParties, int partyId, Simulation &sim);
      virtual SelectionPolicy*  clone();
};