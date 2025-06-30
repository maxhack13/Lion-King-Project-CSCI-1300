#include "Tile.h"
#include "player.h"
// #include "game.h"

#ifndef BOARD_H
#define BOARD_H

class Board
{
private:  
    static const int _BOARD_SIZE = 52;
    Tile _tiles[2][_BOARD_SIZE];
    static const int _MAX_PLAYERS = 2;
    int _player_count;
    int _player_position[_MAX_PLAYERS];
    void displayTile(int player_index, int pos);
    void initializeTiles(int player_index, int PathChoice);
    bool isPlayerOnTile(int player_index, int pos);

public:
    Board();
    Board(int player_count,Player player1, Player player2);
    void displayTrack(int player_index);
    void initializeBoard(Player player1, Player player2);
    void displayBoard();
    bool movePlayer(int player_index, int num);
    int getPlayerPosition(int player_index) const;
    char GetPlayerColor(int playerposition, int player_index);
    // bool TileEvent(char Color, int player_index, int PlayerPosition ,Player player1, int PreviousNumber, Game game, Board board);
    // int LoadRandEvents(Game game,string RandEvent[][4],const int arr_size);
};
#endif