#include "Coalition.h"
#include <vector>
#include "Party.h"

using std::vector;

Coalition::Coalition():cId(), myMandates(),mParties(){}

Coalition::Coalition(int id, int mandates) : cId(id), myMandates(mandates),mParties()
{ 
    
}

int Coalition::getId() const
{
    return cId;
}

void Coalition::setId(int num)
{
    cId = num;
}

int Coalition::getMandates() const
{
    return myMandates;
}

void Coalition::addMandates(int num)
{
    myMandates = myMandates + num;
}
void Coalition::addParty(Party* p)
{
    this->addMandates(p->getMandates());
    this->mParties.push_back(p);
}

vector<Party*> Coalition:: getParties() 
{
    return mParties;
}

vector<int> Coalition::getPartiesId()
{
    vector<int> list;
    for(Party* p : mParties){
        list.push_back(p->getId());
    }

    return list;
}

