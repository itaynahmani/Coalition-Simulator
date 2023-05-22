
#include "SelectionPolicy.h"

Party* EdgeWeightSelectionPolicy ::select (vector<Party*> myParties, int partyId, Simulation &sim){

   int index =0;
   Graph curr = sim.getGraph();
   int size = myParties.size();
   for(int i=1;i<size;i++){
    if(curr.getEdgeWeight(partyId,myParties[i]->getId())>curr.getEdgeWeight(partyId,index)){
        index =i;
    }
   }
   return (myParties[index]);

}
SelectionPolicy* EdgeWeightSelectionPolicy::clone(){ return new EdgeWeightSelectionPolicy();}