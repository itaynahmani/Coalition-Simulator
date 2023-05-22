#include "Offer.h"
#include "Coalition.h"
#include "Agent.h"

Offer::Offer ( int id, Coalition* colOffer): agentOfferId(id), colOffer(colOffer){}

Coalition* Offer::getCoalition() const
{
    return colOffer;
}
int Offer::getAgentId() const
{
    return agentOfferId;
}