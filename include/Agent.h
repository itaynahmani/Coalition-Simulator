#pragma once

#include <vector>
using std::vector;

class SelectionPolicy;
class Party;
class Graph;
class Simulation;

class Agent
{
public:
    Agent();
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    //rule of 5
    Agent (const Agent& other);
    Agent& operator=(const Agent& other);
    virtual ~Agent();
    Agent(Agent&& other);
    Agent& operator=(Agent&& other);


    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    vector<Party*> getRelevantParties ();
    void setRelevantParties(vector<Party*> vec);
    void addParty(Party* p);
    SelectionPolicy* getSelectionPolicy();
    int getCoalitionId() const;
    void setCoalitionId(int c);

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    vector<Party*> relevantParties;
    int mCoal;
};
