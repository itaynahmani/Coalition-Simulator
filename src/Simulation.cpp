#include "Simulation.h"
#include "Agent.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), mCoalitions() 
{
    // You can change the implementation of the constructor, but not the signature!
    const int aSize = mAgents.size();
    for(int i=0;i<aSize;i++){
        Coalition coal(i,0);
        coal.addParty(&(mGraph.getParty(mAgents[i].getPartyId())));
        mAgents[i].setCoalitionId(i);
        mCoalitions.push_back(coal);
        mAgents[i].setRelevantParties(mGraph.getRelevantNeighbors(mAgents[i].getPartyId(),mAgents[i].getCoalitionId()));
        mGraph.getParty(mAgents[i].getPartyId()).setState(Joined);
    }   
}

void Simulation::step() //check what comes before what
{
    int size = mGraph.getNumVertices();
    for(int i=0; i<size;i++){
         mGraph.getParty(i).step(*this);
    }
    size = mAgents.size();
    for(int i=0; i<size;i++){
        mAgents[i].step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    const int size = mAgents.size();
    if(size==mGraph.getNumVertices())
        return true;
    for(Coalition coal: mCoalitions){
        if(coal.getMandates()>60)
            return true;
    }
    return false;
 }

    

const Graph &Simulation::getGraph() const
{
    return mGraph;
}
Graph &Simulation ::getGraph()
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}
void Simulation:: addAgent(Agent& clonedAgent){
    mAgents.push_back(clonedAgent);
}

 vector<Agent> &Simulation:: getAgents()
 {
    return mAgents;
 }

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}
Coalition &Simulation:: getCoalition(int coalitionID){
    return mCoalitions[coalitionID];
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
     vector<vector<int>> output;
    for(Coalition c: mCoalitions){
        output.push_back(c.getPartiesId());
    }
    return output;
}
