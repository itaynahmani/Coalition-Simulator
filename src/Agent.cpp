#include "Agent.h"
#include "Simulation.h"
#include "SelectionPolicy.h"
#include "Offer.h"
//#include "Coalition.h"
//#include "Graph.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), 
relevantParties(), mCoal()
{

}
Agent:: ~Agent(){
    if(mSelectionPolicy)delete mSelectionPolicy;
}
Agent:: Agent (const Agent& other):mAgentId(other.mAgentId),mPartyId(other.mPartyId),mSelectionPolicy(),relevantParties(other.relevantParties), mCoal(other.mCoal){
    mSelectionPolicy=other.mSelectionPolicy->clone();
}
Agent& Agent:: operator=(const Agent& other){
    if(this!=&other){
        if(mSelectionPolicy)delete(mSelectionPolicy);
        //mSelectionPolicy=other.mSelectionPolicy->clone();
        mAgentId=other.mAgentId;
        mPartyId=other.mPartyId;
        mSelectionPolicy=(other.mSelectionPolicy);
    }
    return *this;
}
Agent::Agent(Agent&& other):mAgentId(other.mAgentId),mPartyId(other.mPartyId),mSelectionPolicy(other.mSelectionPolicy),relevantParties(), mCoal(other.mCoal){
    mSelectionPolicy=other.mSelectionPolicy;
    other.mSelectionPolicy=nullptr;
    
}
 Agent& Agent::operator=(Agent&& other){
    if(this!=&other){
        if(mSelectionPolicy)delete(mSelectionPolicy);
        mSelectionPolicy=other.mSelectionPolicy;
        other.mSelectionPolicy=nullptr;
        mAgentId=other.mAgentId;
        mPartyId=other.mPartyId;
    }
    return *this;
 } 

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

vector<Party*> Agent:: getRelevantParties (){
    return relevantParties;
}
void Agent::setRelevantParties(vector<Party*> vec){
    relevantParties = vec;
}
void Agent::addParty(Party* p)
{
    relevantParties.push_back(p);
}
SelectionPolicy* Agent::getSelectionPolicy(){
    return mSelectionPolicy;
}
int Agent ::getCoalitionId() const
{
    return mCoal;
}
void Agent:: setCoalitionId(int c)
{
    mCoal=c;
}

void Agent::step(Simulation &sim)
{

   this->setRelevantParties(sim.getGraph().getRelevantNeighbors(mPartyId,mCoal));
   if(!relevantParties.empty()){
    Offer toChosen(this->getId(),&(sim.getCoalition(mCoal))); //to check
    Party* selected = (mSelectionPolicy->select(relevantParties,mPartyId,sim));
    selected->addOffer(toChosen);
    selected->setState(CollectingOffers);
   }
      
}
