#pragma once

#include <vector>
using std::vector;

class Party;

class Coalition
{
public:
    Coalition();
    Coalition(int cId, int mandates);
    int getId() const;
    void setId(int num);
    int getMandates() const;
    void addMandates(int num);
    void addParty (Party* p);
    vector<Party*> getParties();
    vector<int> getPartiesId();

   

private:
    int cId;
    int myMandates;
    vector<Party*> mParties;

};