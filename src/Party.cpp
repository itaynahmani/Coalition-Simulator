#include "Party.h"
#include "Agent.h"
#include "Offer.h"
#include "JoinPolicy.h"
#include "Simulation.h"
#include "SelectionPolicy.h"
#include <vector>
#include "Graph.h"
#include "Coalition.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting),
 timer(0),myOffers(),myCoal()
{

}
Party:: ~Party(){
    if(mJoinPolicy)delete mJoinPolicy;
}
Party:: Party (const Party& other): mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(), mState(other.mState),
 timer(other.timer),myOffers(other.myOffers),myCoal(other.myCoal){
    mJoinPolicy=(other.mJoinPolicy)->clone();
}
Party& Party:: operator=(const Party& other){
    if(this!=&other){
        if(mJoinPolicy)delete(mJoinPolicy);
        mId=other.getId();
        mName=other.getName();
        mMandates=other.getMandates();
        mState=other.getState();
        mJoinPolicy=(other.mJoinPolicy);  // clone ??
    }
    return *this;
}
Party::Party(Party&& other): mId(other.mId), mName(other.mName), mMandates(other.mMandates),mJoinPolicy(),mState(other.mState),
    timer(other.timer),myOffers(other.myOffers),myCoal(other.myCoal){
    mJoinPolicy=other.mJoinPolicy;
    other.mJoinPolicy=nullptr;
}
 Party& Party::operator=(Party&& other){
    if(this!=&other){
        if(mJoinPolicy)delete(mJoinPolicy);
        mJoinPolicy=other.mJoinPolicy; // removed clone
        other.mJoinPolicy=nullptr;
        mId=other.getId();
        mName=other.getName();
        mMandates=other.getMandates();
        mState=other.getState();
    }
    return *this;
 }

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getId() const
{
    return mId;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

void Party ::addOffer(Offer& a)
{
    myOffers.push_back(a);
}
 
  vector<Offer> Party:: getOffers(){
    return myOffers;
  }

  Coalition Party:: getCoalition(){
    return myCoal;
  }

void Party::step(Simulation &s)
{ 
    if(getState()== CollectingOffers){
        if (getTimer()<2) increaseTimer();
        else {
           Offer chosen = (*mJoinPolicy).join(myOffers,s);
           chosen.getCoalition()->addParty(this);
           myCoal=*(chosen.getCoalition());
           const int agentID = chosen.getAgentId();
           SelectionPolicy *sp = s.getAgents()[agentID].getSelectionPolicy()->clone();
           Agent newAgent(s.getAgents().size(),getId(),sp);
           newAgent.setCoalitionId(chosen.getCoalition()->getId());
           newAgent.setRelevantParties(s.getGraph().getRelevantNeighbors(newAgent.getPartyId(),newAgent.getCoalitionId())); 
           s.getAgents().push_back(newAgent);      
           setState(Joined);
        }
    }
}

int Party::getTimer() const
{
    return timer;
}
void Party::increaseTimer()
{
    timer++;
}


