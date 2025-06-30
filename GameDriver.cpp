#include <iostream>
#include <vector>
#include <fstream>
#include "Board.h"
#include "Tile.h"
#include "player.h"
#include "game.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>
#include <unistd.h>
using namespace std;



int main()
{   
    srand(time(0));
    Game game1;
    Player player1;
    Player player2;
    Board board1;
    Board boards[1] = {board1};
    int count = 1;
    Player MasterListofPlayers[5];
    string MasterListofAdvisors[5] = {"1. Rafiki-Invisibility", "2. Nala-Night Vision", "3. Sarabi-Energy Manipulation", "4. Zazu-Weather Control", "5. Sarafina- Super Speed"};
    bool PlayerAtEnd = false;

    ofstream OutFile("finalStats.txt");
    OutFile<<" ";
    OutFile.close();

    // int count = 1;
    // int y = 0;
    //--------------------BEGINING OF GAME-----------------------------------
    //board1.displayBoard();
     //--------------------BEGINING OF GAME-----------------------------------
    // display characters. have the user choose what character they want to use
    //ascii art from a website. its not mine.
cout<<"                                  ccc  c  c  ccc"<<endl;
cout<<"                                   $   $cc$  $=="<<endl;
cout<<"                                   $   $  $  $cc"<<endl;
cout<<"         =ccr=    ========================================================  _,r====c,"<<endl;
cout<<"         )$F     =cc= ,z=''?b, `$c.     3$'    '$$' '$P' '3$' '$c,    '$' cP'     `$'"<<endl;
cout<<"         )$F      $$ zP      ?b $F?b,   3$      $$,/'     3$   $'?c,   $ z$          "<<endl;
cout<<"         )$F      $$<$F       $>$F  ?b, 3$      $$C       3$   $  '?c  $ $$     ,,,, "<<endl;
cout<<"         )$F      $$ ?b      z$'$F   `?bJ$      $$`'c,    3$   $    '?c$ `$L      $$ "<<endl;
cout<<"         ,J$L,,,c' $$  'b,..,cP' $L     `?P     $$   ?b,  3$   $      '$  `?c,,.,,P'"<<endl;
cout<<"         `''''''' `'''   ''''   `''      `'     ''''  ''' `''' ''      ''    `'''''  "<<endl;

    cout << "          /\\                      " << endl;
    cout << "         /  \\   /\\      /\\        " << endl;
    cout << "        /    \\ /  \\    /  \\       " << endl;
    cout << "       /      \\    \\  /    \\      " << endl;
    cout << "      /        \\    \\/      \\     " << endl;
    cout << "     /__________\\  /__________\\   " << endl;
    cout << "    /\\           /\\               /\\  " << endl;
    cout << "   /  \\   /\\    /  \\     /\\    /  \\ " << endl;
    cout << "  /    \\ /  \\  /    \\   /  \\  /    \\" << endl;
    cout << " /______\\____\\/______\\_/____\\/______\\ " << endl;
    cout << endl;

    cout << "      - - A Tough Adventure Awaits! Who Will RULE the PrideLands?? - -" << endl;
    cout << endl;
    cout<<"--------------LOADING--------------"<<endl;

    for(int i = 0; i<1; i++){

        cout<<" . ";
        fflush(stdout);
        sleep(1);
        cout<<" . ";
        fflush(stdout);
        sleep(1);
        cout<<" . ";
        fflush(stdout);
        sleep(1);
        cout << "\r               \r"; 
        sleep(1);
    }
    

    int WrongAdvisor = 0;
    
    player1 = game1.loadGame(player1, count, MasterListofPlayers, 5, MasterListofAdvisors, 5,WrongAdvisor);
    count++;
    WrongAdvisor = player1.getAdvisor();
    player2 = game1.loadGame(player2, count, MasterListofPlayers, 5, MasterListofAdvisors, 5, WrongAdvisor);
    count++;

    boards[0].initializeBoard(player1,player2);

    game1.TileEvent('G', 0, 3, player1,player2, 2 ,game1,boards,1);
    
    //cout<<player1.getAdvisor();
    //cout<<board1.getPlayerPosition(1);     
    // apply affected values to chosen chacters.
    // display menu before begining
   
    //--------------------MAIN GAME------------------------------
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<< "---------~~~~~~The Game Will Now Begin!!!~~~~~~~~~~--------------"<<endl;
    
    //cout<<count;
    int breakerMenu;
    cout<<"Starting Game Board:"<<endl;
    boards[0].displayBoard();
    while(PlayerAtEnd == false){


        if(count%2 == 1){
            
            if(player1.getEndofGame() == true){
                count++;
                continue;
            }
            cout<<"~~~~~~~~---------Player 1--------~~~~~~~~~~"<<endl;
            //menu
            int prevNumber = boards[0].getPlayerPosition(0);
            //cout<<"prev position"<< prevNumber<<endl;
            do{
                breakerMenu = game1.MainMenu(count, player1, boards[0]);
            }while(breakerMenu != 5);
            //cout<<"hi1"<<endl;
            //get tile color
            //cout<<"hi2"<<endl;
            int randNum = game1.randNum();
            //cout<<"hi5"<<endl;
            boards[0].movePlayer(0, randNum);
            cout<<"You have rolled a: "<<randNum<<endl;
            boards[0].displayBoard();
            int PlayerPosition = boards[0].getPlayerPosition(0);
            //cout<<"current position"<< PlayerPosition<<endl;
            //cout<<"hi3"<<endl;
            char Color = boards[0].GetPlayerColor(PlayerPosition, 0);
            if(Color == 'B'){
                count++;
            }
            //display the board
            //increment player forward
            //cout<<"hi4"<<endl;
            //Check Tiles
            //cout<<"hi6"<<endl;
            player1 = game1.TileEvent(Color, 0, PlayerPosition, player1,player2, prevNumber,game1,boards,1);
            //cout<<"hi7"<<endl;
            //cout<<board1.getPlayerPosition(0)<<endl;
            //cout<<PlayerPosition;
            if(boards[0].getPlayerPosition(0)!=PlayerPosition){
                boards[0].displayBoard();
            }
            count++;

        }
        else{
           if(player2.getEndofGame() == true){
                count++;
                continue;
            }
            cout<<"~~~~~~~~---------Player 2--------~~~~~~~~~~"<<endl;
            int prevNumber = boards[0].getPlayerPosition(1);
            //menu
            do{
                breakerMenu = game1.MainMenu(count, player2, board1);
            }while(breakerMenu != 5);

            int randNum = game1.randNum();
            boards[0].movePlayer(1, randNum);
            cout<<"You have rolled a: "<<randNum<<endl;
            boards[0].displayBoard();
            //get tile color
            int PlayerPosition = boards[0].getPlayerPosition(1);
            char Color = boards[0].GetPlayerColor(PlayerPosition, 1);
            if(Color == 'B'){
                count++;
            }
            //display the board
            //increment player forward
            //Check Tiles
            player2 = game1.TileEvent(Color,1, PlayerPosition, player2,player1, prevNumber,game1,boards,1);
            if(boards[0].getPlayerPosition(1)!=PlayerPosition){
                boards[0].displayBoard();
            }
            count++;
        }

        //how ot break out of main game
        if(player1.getEndofGame() == true && player2.getEndofGame() == true){
            PlayerAtEnd = true;
        }

    }

    // while loop to keep game running
    // at the begginging of every tunr display the main menu function
    // player 1 and 2 generate random numbers and advance
    // after advancing have both players get affected by the tile landed on
    // keep assesing for negative events and how tiles affect stats for players
    // players will continue to spin random numebrs to move forward.

    //------------------END of GAME--------------------------------------
    // pride rock is reached, whichever player has the most pride points wins.
   
   ///ASCII art from asciiart.eu
    cout<<"Game Complete!!"<<endl;
    ifstream ascii("ascii.txt");    
    string line;

    while(getline(ascii,line)){
        cout<<line<<endl;
    }


    cout<<"The Results Are Loading";
     for(int i = 0; i<1; i++){

        cout<<" . ";
        fflush(stdout);
        sleep(1);
        cout<<" . ";
        fflush(stdout);
        sleep(1);
        cout<<" . ";
        fflush(stdout);
        sleep(1);
        cout << "\r               \r"; 
        sleep(1);
    }


    int player1Ppoint = player1.getPridePoints();

    int player2Ppoint = player2.getPridePoints();

    player1Ppoint += 1000 * (player1.getStrength() / 100 + player1.getStamina() / 100 + player1.getWisdom() / 100);
    player2Ppoint += 1000 * (player2.getStrength() / 100 + player2.getStamina() / 100 + player2.getWisdom() / 100);


    string file  = "finalStats.txt";
    player1.EndOFGamePrint(file, player1Ppoint, player2Ppoint, 1,0);
    player2.EndOFGamePrint(file,player1Ppoint, player2Ppoint, 2,1);
    // fstream file("finalStats.txt");
    // file<<" "<<endl;
    // file.close()

    if (player1Ppoint > player2Ppoint)
    {
        cout << "~~~~------Player 1 rules the Pridelands!!!!~~~~~~--------" << endl;
        cout<<"Player 1: WINNER!"<<endl;
        cout<<endl;
        player1.printStatsShort();
        cout<<endl;
        cout<<"Player 1's Total Final Pride Points: ";
        cout<<player1Ppoint<<endl;
        cout<<endl;
        cout<<"------------------"<<endl;
        cout<<"Player 2: "<<endl;
        cout<<endl;
        player2.printStatsShort();
        cout<<endl;
        cout<<"Player 2's Total Final Pride Points: ";
        cout<<player2Ppoint<<endl;
        cout<<endl;
        return 0;
    }
    else if (player2Ppoint > player1Ppoint)
    {
        cout << "~~~~~~~-------Player 2 rules the Pridelands!!!!!--------~~~~~~~~~" << endl;
        cout<<"Player 2: WINNER!"<<endl;
        cout<<endl;
        player2.printStatsShort();
        cout<<endl;
        cout<<"Player 2's Total Final Pride Points: ";
        cout<<player2Ppoint<<endl;
        cout<<"------------------"<<endl;
        cout<<"Player 1: "<<endl;
        cout<<endl;
        player1.printStatsShort();
        cout<<endl;
        cout<<"Player 1's Total Final Pride Points: ";
        cout<<player1Ppoint<<endl;
        cout<<endl; 

        return 0;
    }
    else
    {
        cout << "The two lions will rule in Unison!!!!" << endl;
        
        return 0;
    }

    return 0;

}



