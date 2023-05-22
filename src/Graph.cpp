#include "Graph.h"
#include <vector>
#include "Offer.h"
#include "Coalition.h"

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges) 
{
    // You can change the implementation of the constructor, but not the signature!
}

int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}

Party &Graph::getParty(int partyId)
{
    return mVertices[partyId];
}


vector<Party*> Graph::getRelevantNeighbors(int partyId, int mycoal)
{
    vector<Party*> vec;
    const int size = mEdges[partyId].size();
    for(int i=0; i < size;i++){
        
        if(mEdges[partyId][i] != 0 && getParty(i).getState() != Joined ){
            bool cond3 = true;
            vector<Offer> vecOffer = getParty(i).getOffers();
            int x = vecOffer.size();
            for(int i=0; i<x; i++){
                if(vecOffer[i].getCoalition()->getId() == mycoal){ 
                    cond3 = false;
                    i = x;     
                    }
            }
            if(cond3) vec.push_back(&(getParty(i)));
        } 
        
    }

    return vec;
}

void Graph::setPartyState(int partyId, State st)
{
    mVertices[partyId].setState(st);
}


