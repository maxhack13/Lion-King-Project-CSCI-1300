#include <iostream>
#include "player.h"
#include "Board.h"

using namespace std;

#ifndef GAME_H
#define GAME_H

class Game{
    private:
    Player player;
    public:
    
    Player loadGame(Player player, int count, Player MasterListOfPlayers[], const int ARR1_SIZE, string MasterListofAdvisors[], const int ARR2_SIZE,int WrongAdvisor );
    int split(string input_string, char separator, string arr[], const int ARR3_SIZE);
    int MainMenu(int count, Player player, Board Board);
    int ChooseAdvisors(Player player, string MasterListofAdvisors[],const int ARR4_SIZE ,int pathDecision, int count,int WrongAdivsor);
    int randNum();
    Player TileEvent(char Color, int player_index, int PlayerPosition ,Player player1, Player player2, int PreviousNumber, Game game, Board boards[],const int arr0_size);
    int LoadRandEvents(Game game,string RandEvent[][4],const int arr_size);
};


#endif