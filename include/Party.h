#pragma once
#include <string>
#include <vector>
#include "Coalition.h"
using std::vector;
using std::string;

class JoinPolicy;
class Simulation;
class Coalition;
class Agent;
class Offer;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party();
    Party(int id, string name, int mandates, JoinPolicy *); 
    //rule of 5
    Party (const Party& other);
    Party& operator=(const Party& other);
    virtual ~Party();
    Party(Party&& other);
    Party& operator=(Party&& other);
    //
    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    int getId() const;
    int getTimer() const ;
    void increaseTimer();
    void addOffer(Offer& a);
    vector<Offer> getOffers();
    Coalition getCoalition();

   

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    //
    int timer;
    vector<Offer> myOffers;
    Coalition myCoal;
    
    

};
