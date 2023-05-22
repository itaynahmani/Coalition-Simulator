#pragma once
#include <vector>

class Agent;
class Coalition;

class Offer
{
    public:
    Offer(int agentOfferId, Coalition* colOffer);

    int getAgentId() const;
    Coalition* getCoalition() const; 
    
private:
    int agentOfferId;
    Coalition* colOffer;
};