#include <iostream>
using namespace std;

#ifndef ADVISOR_H
#define ADVISOR_H


class Advisor{
    private:
    string name;
    string Description;
    int num;//1-5. if 0, then pridelands was chosen

    public:
    Advisor(int num);//only constructor / setter needed.

    void setAdvisor(int num);
    string getName(); 
    string getDescription();
    int getNum();


    void displayStats();
};

#endif