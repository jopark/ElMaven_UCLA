#ifndef DATABASES_H
#define DATABASES_H

#include "standardincludes.h"

class Compound;

using namespace std;

class Databases {

    public:
        bool addCompound(Compound* c);
        int loadCompoundCSVFile(string filename);
        vector<Compound*> getCompoundsSubset(string dbname);
        Compound* extractCompoundfromEachLine(vector<string>& fields, map<string, int> & header, int loadCount, string filename);
        float getChargeFromDB(vector<string>& fields, map<string, int> & header);
        vector<string> getCategoryFromDB(vector<string>& fields, map<string, int> & header);
        void closeAll();
        vector<Compound*> compoundsDB;
        vector<string> invalidRows;

    private:
        map<string,Compound*> compoundIdMap;

        //vector<Adduct*> adductsDB;
        //vector<Adduct*> fragmentsDB;
        //deque<Reaction*> reactionsDB;
        
};

#endif //DATABASES_H
