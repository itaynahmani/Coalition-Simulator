#include "Simulation.h"
#include "SelectionPolicy.h"

Party* MandatesSelectionPolicy ::select (vector<Party*> myParties, int partyId, Simulation &sim){

   int index =0;
   int size = myParties.size();
   for(int i=1;i<size;i++){
    if(myParties[i]->getMandates()>myParties[index]->getMandates()){
        index =i;
    }
   }
   return myParties[index];
}
SelectionPolicy* MandatesSelectionPolicy::clone(){ return new MandatesSelectionPolicy();}
