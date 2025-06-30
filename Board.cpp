#include <iostream>
#include <fstream>
#include "Board.h"
#include "player.h"
#include "game.h"
#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m" /* Grassy Green (34,139,34) */
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m" /* Orange (230,115,0) */
#define GREY "\033[48;2;128;128;128m" /* Grey (128,128,128) */
#define RESET "\033[0m"
using namespace std;

void Board::initializeBoard(Player player1, Player player2)
{
    srand(time(0));
    // Seed random number generator in your main function once
    initializeTiles(0, player1.getPathType()); // This ensures each lane has a unique tile distribution
    initializeTiles(1, player2.getPathType());
    _player_position[0] = 0;
    _player_position[1] = 0;
}
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

void Board::initializeTiles(int player_index, int PathChoice)
{
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;

    // Keep track of green tile positions to ensure we place exactly 30 greens
    for (int i = 0; i < total_tiles; i++)
    {
        if (i == total_tiles - 1)
        {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'O';
            cout << RESET << endl;
        }
        else if (i == 0)
        {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'Y';
        }
        else if (green_count < 30 && (rand() % (total_tiles - i) < 30 - green_count))
        {
            temp.color = 'G';
            green_count++;
        }
        else
        {
            if (i > total_tiles / 2)
            {
                if (PathChoice == 1)
                {
                    // Randomly assign one of the other colors: Blue, Pink, Brown, Red,Purple
                    int color_choice = rand() % 10;
                    switch (color_choice)
                    {
                    case 0:
                        temp.color = 'B'; // Blue
                        break;
                    case 1:
                        temp.color = 'P'; // Pink
                        break;
                    case 3:
                    case 4:
                    case 5:
                        temp.color = 'N'; // Brown
                        break;
                    case 6:
                    case 7:
                    case 8:
                        temp.color = 'R'; // Red
                        break;
                    case 9:
                    case 2:
                        temp.color = 'U'; // Purple
                        break;
                    }
                }
                else
                {
                    // Randomly assign one of the other colors: Blue, Pink, Brown, Red,Purple
                    int color_choice = rand() % 10;
                    switch (color_choice)
                    {
                    case 0:
                    case 1:
                    case 2:
                        temp.color = 'B'; // Blue
                        break;
                    case 3:
                        temp.color = 'P'; // Pink
                        break;
                    case 4:
                    case 5:
                        temp.color = 'N'; // Brown
                        break;
                    case 6:
                    case 7:
                        temp.color = 'R'; // Red
                        break;
                    case 8:
                    case 9:
                        temp.color = 'U'; // Purple
                        break;
                    }
                }
            }
            else
            {
                if (PathChoice == 1)
                {
                    // Randomly assign one of the other colors: Blue, Pink, Brown, Red,Purple
                    int color_choice = rand() % 10;
                    switch (color_choice)
                    {
                    case 0:
                    case 1:
                        temp.color = 'B'; // Blue
                        break;
                    case 2:
                    case 3:
                        temp.color = 'P'; // Pink
                        break;
                    case 4:
                    case 5:
                        temp.color = 'N'; // Brown
                        break;
                    case 6:
                    case 7:
                        temp.color = 'R'; // Red
                        break;
                    case 8:
                    case 9:
                        temp.color = 'U'; // Purple
                        break;
                    }
                }
                else
                {
                    // Randomly assign one of the other colors: Blue, Pink, Brown, Red,Purple
                    int color_choice = rand() % 10;
                    switch (color_choice)
                    {
                    case 0:
                    case 1:
                        temp.color = 'B'; // Blue
                        break;
                    case 2:
                        temp.color = 'P'; // Pink
                        break;
                    case 3:
                    case 4:
                        temp.color = 'N'; // Brown
                        break;
                    case 5:
                    case 6:
                        temp.color = 'R'; // Red
                        break;
                    case 7:
                    case 8:
                    case 9:
                        temp.color = 'U'; // Purple
                        break;
                    }
                }
            }
        }
        // Assign the tile to the board for the specified lane
        _tiles[player_index][i] = temp;
    }
}

Board::Board()
{
    _player_count = 1;
    // Initialize player position
    _player_position[0] = 0;
    // Initialize tiles
    initializeTiles(_player_position[0], 1);
}
Board::Board(int player_count, Player player1, Player player2)
{
    if (player_count > _MAX_PLAYERS)
    {
        _player_count = _MAX_PLAYERS;
    }
    else
    {
        _player_count = player_count;
    }
    // Initialize player position
    for (int i = 0; i < _player_count; i++)
    {
        _player_position[i] = 0;
    }
    // Initialize board
    initializeBoard(player1, player2);
}
bool Board::isPlayerOnTile(int player_index, int pos)
{
    if (_player_position[player_index] == pos)
    {
        return true;
    }
    return false;
}
void Board::displayTile(int player_index, int pos)
{
    // string space = " ";
    string color = "";
    int player = isPlayerOnTile(player_index, pos);
    // Template for displaying a tile: <line filler space> <color start> |<player symbol or blank space > | <reset color><line filler space><endl>
    // Determine color to display
    if (_tiles[player_index][pos].color == 'R')
    {
        color = RED;
    }
    else if (_tiles[player_index][pos].color == 'G')
    {
        color = GREEN;
    }
    else if (_tiles[player_index][pos].color == 'B')
    {
        color = BLUE;
    }
    else if (_tiles[player_index][pos].color == 'U')
    {
        color = PURPLE;
    }
    else if (_tiles[player_index][pos].color == 'N')
    {
        color = BROWN;
    }
    else if (_tiles[player_index][pos].color == 'P')
    {
        color = PINK;
    }
    else if (_tiles[player_index][pos].color == 'O')
    {
        color = ORANGE;
    }
    else if (_tiles[player_index][pos].color == 'Y')
    {
        color = GREY;
    }
    if (player == true)
    {
        cout << color << "|" << (player_index + 1) << "|" << RESET;
    }
    else
    {
        cout << color << "| |" << RESET;
    }
}
void Board::displayTrack(int player_index)
{
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        displayTile(player_index, i);
    }
    cout << endl;
}
void Board::displayBoard()
{
    for (int i = 0; i < 2; i++)
    {
        displayTrack(i);
        if (i == 0)
        {
            cout << endl; // Add an extra line between the two lanes
        }
    }
}
bool Board::movePlayer(int player_index, int Num)
{
    // Increment player position
    _player_position[player_index] += Num;

    if (_player_position[player_index] > _BOARD_SIZE - 1)
    {
        _player_position[player_index] = _BOARD_SIZE - 1;
        return true;
    }
    if (_player_position[player_index] < 0)
    {
        _player_position[player_index] = 0;
        return false;
    }

    if (_player_position[player_index] == _BOARD_SIZE - 1)
    {
        // Player reached last tile
        return true;
    }
    return false;
}
int Board::getPlayerPosition(int player_index) const
{
    if (player_index >= 0 && player_index <= _player_count)
    {
        return _player_position[player_index];
    }
    return -1;
}
char Board::GetPlayerColor(int playerposition, int player_index)
{
    return _tiles[player_index][playerposition].color;
}

// int Board::LoadRandEvents(Game game, string RandEvent[][4], const int arr_size)
// {
//     ifstream RandEvents("random_events.txt");

//     string RandomEvent;
//     int count = 0;
//     string arr[4];
//     // const int ARR3_SIZE = 4;
//     while (getline(RandEvents, RandomEvent))
//     {
//         if (count == 0)
//         {
//             continue;
//         }
//         game.split(RandomEvent, '|', arr, 4);
//         for (int i = 0; i < 4; i++)
//         {
//             RandEvent[count][i] = arr[i];
//         }
//         count++; // amount of lines we get from the file
//     }
//     RandEvents.close();

//     return rand() % count + 1; // return a random index taht is in the rang of the file.
// }

// bool Board::TileEvent(char Color, int player_index, int PlayerPosition, Player player, int PreviousNumber, Game game, Board board)
// {
//     string RandEvent[51][4];
//     if (Color == 'R') // red
//     {
//         cout << "You Have stumbled into a graveyard and have lost 100 stamina, strength, and wisdom points." << endl;
//         movePlayer(player_index, -10);
//         player.setStamina(player.getStamina() - 100);
//         player.setStrength(player.getStrength() - 100);
//         player.setWisdom(player.getWisdom() - 100);
//         return false;
//     }
//     else if (Color == 'G') // green
//     {
//         // load in a random event
//         int PlayerIDX = LoadRandEvents(game, RandEvent, 50);
//         while (stoi(RandEvent[PlayerIDX][1]) != player.getPathType() - 1 || stoi(RandEvent[PlayerIDX][1]) == 2)
//         {
//             PlayerIDX = LoadRandEvents(game, RandEvent, 50);
//         }
//         // 50% chance of a random event
//         // swtich
//         switch (rand() % 2 + 1)
//         {
//         // random event
//         case 1:
//             // check if they have an adivsor
//             cout << RandEvent[PlayerIDX][0] << endl;

//             if (stoi(RandEvent[PlayerIDX][2]) == 0)
//             {
//                 player.setPridePoints(player.getPridePoints() + stoi(RandEvent[PlayerIDX][3]));
//                 cout << "Your pride points have changed by: " << RandEvent[PlayerIDX][3] << endl;
//                 player.printStatsComplete();
//             }

//             // no advisor
//             if (stoi(RandEvent[PlayerIDX][2]) != player.getAdvisor())
//             {
//                 // bad event
//                 player.setPridePoints(player.getPridePoints() + stoi(RandEvent[PlayerIDX][3]));
//                 cout << "You have lost: " << RandEvent[PlayerIDX][3] << "Pridepoints." << endl;
//                 player.printStatsComplete();
//             }
//             if (stoi(RandEvent[PlayerIDX][2]) == player.getAdvisor())
//             {
//                 // bad even
//                 cout << "Your advisor's trianing has come in handy" << endl;
//                 player.printStatsComplete();
//             }
//             break;
//         // nothing happens
//         case 2:
//             break;
//         default:
//             break;
//         }
//         return false;
//     }
//     else if (Color == 'B') // blue
//     {
//         cout << "~~~~~You have reached and Oasis!!!! sit back and relax~~~~~~. You have gained 200 stamina, strength, and wisdom. " << endl;
//         cout << "Now have also been granted an exta turn." << player.getName() << "spin again. " << endl;
//         player.setStamina(player.getStamina() + 200);
//         player.setStrength(player.getStrength() + 200);
//         player.setWisdom(player.getWisdom() + 200);
//         return false;
//     }
//     else if (Color == 'U') // purple
//     {
//         ifstream Riddles("riddles.txt");
//         string input;
//         string arr[2];
//         string RiddleArr[28][2];
//         int counter = 0;

//         while (getline(Riddles, input))
//         {
//             game.split(input, '|', arr, 2);
//             if (counter == 0)
//             {
//                 continue;
//             }
//             for (int i = 0; i < 2; i++)
//             {
//                 RiddleArr[counter][i] = arr[i];
//             }
//             counter++;
//         }

//         int randIndex = rand() % counter + 1;
//         string answer;
//         cout << "You have been taksed to asnwer a riddle" << endl;
//         cout << RiddleArr[randIndex][0] << endl;
//         cin >> answer;

//         while (answer != RiddleArr[randIndex][1])
//         {
//             cout << "wrong answer, try again." << endl;
//             cin >> answer;
//         }
//         cout << "Congradulations,!! That was correct" << endl;
//         return false;
//     }
//     else if (Color == 'N') // brown
//     {
//         cout << "The Hyenas have dragged you back to your last position. You have also lost 300 stamina points." << endl;
//         board.movePlayer(player_index, -PreviousNumber);
//         player.setStamina(player.getStamina() - 300);
//         return false;
//     }
//     else if (Color == 'P') // pink
//     {
//         cout << "~~~~The land of Enrichment!~~~~" << endl;
//         cout << "+300 Stamina, +300 Strength, +300 Wisdom" << endl;
//         player.setStamina(player.getStamina() + 300);
//         player.setStrength(player.getStrength() + 300);
//         player.setWisdom(player.getWisdom() + 300);
//         return false;
//     }
//     else if (Color == 'O') // orange
//     {
//         cout << "Congratulations!!!! You Have reached PRIDE ROCK" << endl;
//         return true;
//     }
//     else if (Color == 'Y') // grey
//     {
//         return false;
//     }
// }