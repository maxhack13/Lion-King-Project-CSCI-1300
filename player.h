#include <iostream>

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player{
    private:
        string _name;
        int _strength, _stamina, _wisdom, _pride_points, _age;
        int _advisor;
        int _pathType;
        bool _endofGame;

    public:
        Player();
        Player(string,int, int, int);

        string getName(); 
        int getStrength(); 
        int getStamina();
        int getAdvisor();
        int getWisdom(); 
        int getPridePoints();
        int getAge();
        int getPathType();
        bool getEndofGame();

        void setName(string name);
        void setStrength(int strength); 
        void setStamina(int stamina); 
        void setWisdom(int wisdom); 
        void setPridePoints(int pride_points); 
        void setAge(int age); 
        void setAdvisor(int advisor);
        void setPathType(int pathDecision);
        void SetEndofGame(bool endOFgame);

        void trainCub(int strenght, int stamina, int wisdom);
        void toPrideLands();
        void printStatsComplete();
        void printStatsShort();
        void EndOFGamePrint(string file, int Ppoint1,int Ppoint2, int playerIndex, int counts);

};


#endif