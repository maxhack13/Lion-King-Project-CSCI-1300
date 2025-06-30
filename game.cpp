#include <iostream>
#include <vector>
#include <fstream>
#include "Tile.h"
#include "player.h"
#include "game.h"
#include "Board.h"

using namespace std;

int Game::split(string input_string, char separator, string arr[], const int ARR3_SIZE)
{
    // int length = input_string.length();

    if (input_string.length() == 0)
    {
        return 0;
    }
    else
    {
        int count = 0;
        // cout << length << endl;
        for (int i = 0; i < (int)input_string.length(); i++)
        {
            int length = input_string.length();
            // cout << "ENDING: " << i << ", " << length - 1 << ", " << input_string << endl;
            if (input_string[i] == separator)
            {
                // cout<< input_string[i]<<endl;
                if (count == ARR3_SIZE)
                {
                    return -1;
                }
                arr[count] = input_string.substr(0, i);
                input_string = input_string.substr(i + 1, length - (i + 1));
                // cout << "new strand: " << input_string << endl;
                i = -1;
                count += 1;
                // cout << "count: " << count << endl;
            }
            else if (i == length - 1)
            {
                // cout << "ENDING" << endl;
                if (count == ARR3_SIZE)
                {
                    return -1;
                }
                arr[count] = input_string;
            }
            if (count > ARR3_SIZE)
            {
                return -1;
            }
        }
        if (count == 0)
        {
            arr[0] = input_string;
            return 1;
        }
        return count + 1;
    }
}

Player Game::loadGame(Player player, int count, Player MasterListOfPlayers[], const int ARR1_SIZE, string MasterListofAdvisors[], const int ARR2_SIZE, int WrongAdvisor)
{
    cout << endl;
    cout << endl;
    cout << endl;
    // cout << MasterListofAdvisors[2]<<endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "------~~~~~~Choose Your Character Wisely...~~~~~~------" << endl;
    string arr[5];
    // int IncorrectChoice = 6;
    int idx = 0;

    // use filestream to get player info in
    ifstream Characters("character.txt");
    string character;

    if (count % 2 == 1) // I only want to pull from the file once.
    {
        while (getline(Characters, character))
        {
            split(character, '|', arr, 5);
            if (arr[0] == "playerName")
            {
                continue;
            }
            else
            {
                Player setPlayer;
                setPlayer.setName(arr[0]);
                setPlayer.setAge(stoi(arr[1]));
                setPlayer.setStrength(stoi(arr[2]));
                setPlayer.setStamina(stoi(arr[3]));
                setPlayer.setWisdom(stoi(arr[4]));
                setPlayer.setPridePoints(20000);

                MasterListOfPlayers[idx] = setPlayer;
                idx++;
            }
        }
    }
    // cout << MasterListofAdvisors[2]<<endl;
    // cout<<"blahblah"<<MasterListOfPlayers[0].getName()<<endl;
    if (count == 1)
    {
        for (int j = 0; j < ARR1_SIZE; j++)
        {
            cout << "(" << j + 1 << ")" << endl;
            cout << "Name: " << MasterListOfPlayers[j].getName() << endl;
            cout << "Age: " << MasterListOfPlayers[j].getAge() << endl;
            cout << "Strength: " << MasterListOfPlayers[j].getStrength() << endl;
            cout << "Stamina: " << MasterListOfPlayers[j].getStamina() << endl;
            cout << "Wisdom: " << MasterListOfPlayers[j].getWisdom() << endl;
            cout << "Pride points: " << MasterListOfPlayers[j].getPridePoints() << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }
    }
    else if (count == 2)
    {
        for (int j = 0; j < ARR1_SIZE - 1; j++)
        {
            cout << "Player 2" << endl;
            cout << "(" << j + 1 << ")" << endl;
            cout << "Name: " << MasterListOfPlayers[j].getName() << endl;
            cout << "Age: " << MasterListOfPlayers[j].getAge() << endl;
            cout << "Strength: " << MasterListOfPlayers[j].getStrength() << endl;
            cout << "Stamina: " << MasterListOfPlayers[j].getStamina() << endl;
            cout << "Wisdom: " << MasterListOfPlayers[j].getWisdom() << endl;
            cout << "Pride points: " << MasterListOfPlayers[j].getPridePoints() << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }
    }
    // cout << i << endl;
    // cout<<"blahblah"<<MasterListOfPlayers[0].getName()<<endl;
    int PlayerChoice;
    if (count % 2 == 0)
    {
        cout << endl;
        cout << "~~~~~Player 2, Enter your Choice. You have 4 options~~~~~" << endl;
        cin >> PlayerChoice;
        while ((PlayerChoice < 1 || PlayerChoice > 4))
        {
            cout << PlayerChoice << " is not an option" << endl;
            cout << "Enter your Choice (1-4)" << endl;
            cin >> PlayerChoice;
        }
        player = MasterListOfPlayers[PlayerChoice - 1]; // player2
    }
    else
    {
        cout << "~~~~~Player 1, Enter your Choice (1-5)~~~~~~" << endl;
        cin >> PlayerChoice;
        while (PlayerChoice < 1 || PlayerChoice > 5)
        {
            cout << "incorrect option. Input a new choice (1-5):" << endl;
            cin >> PlayerChoice;
        }
        player = MasterListOfPlayers[PlayerChoice - 1];
        // remove an index from the array basically.
        // cout <<"before the array index switch"<< MasterListofAdvisors[2]<<endl;
        // Player tempHold;
        for (int i = 0; i < 5; i++)
        {
            if (i + 1 == PlayerChoice)
            {
                // cout <<"1: "<< MasterListofAdvisors[2]<<endl;
                for (int j = i; j < 4; j++)
                {
                    MasterListOfPlayers[j] = MasterListOfPlayers[j + 1];
                    // cout <<"2: "<< MasterListofAdvisors[2]<<endl;
                }
            }
            else
            {
                // cout <<"3: "<< MasterListofAdvisors[2]<<endl;
                continue;
            }
        }
        cout << "-~-~~~~~~~~~~~~~~~~--------------------~~~~~~~~~~~~~~~~~~~~~~~------" << endl;
    }
    // cout <<"after the array index switch"<< MasterListofAdvisors[2]<<endl;
    // cout<<"blahblah"<<MasterListOfPlayers[0].getName()<<endl;
    //  then user chooses what path type he wants to follow. cub training or straight to pride lands
    int pathDecision1;
    int pathDecision2;
    // cout <<"path decisions"<< MasterListofAdvisors[2]<<endl;
    if (count % 2 == 1)
    {
        cout << "Player 1, ~~~~CHOOSE YOUR PATH~~~~~~ Pridelands(1) or Cub training?(2)" << endl;
        cin >> pathDecision1;
        while (pathDecision1 < 1 || pathDecision1 > 2)
        {
            cout << "Incorrect input, Choose again" << endl;
            cin >> pathDecision1;
        }
        player.setPathType(pathDecision1);
        if (pathDecision1 == 1)
        {
            player.toPrideLands();
        }
        else
        {
            player.trainCub(500, 500, 1000);
        }
    }
    else
    {
        cout << "Player 2, ~~~~CHOOSE YOUR PATH~~~~~~ Pridelands(1) or Cub training?(2)" << endl;
        cin >> pathDecision2;
        while (pathDecision2 < 1 || pathDecision2 > 2)
        {
            cout << "Incorrect input, Choose again" << endl;
            cin >> pathDecision2;
        }
        player.setPathType(pathDecision2);
        if (pathDecision2 == 1)
        {
            player.toPrideLands();
        }
        else
        {
            player.trainCub(500, 500, 1000);
        }
    }
    // apply advisors
    // player1
    // cout <<"path decisions"<< MasterListofAdvisors[2]<<endl;
    
    switch (count % 2)
    {
    case 1:
        player.setAdvisor(ChooseAdvisors(player, MasterListofAdvisors, 5, pathDecision1, count, WrongAdvisor));
        // cout<<"hi";
        break;
    case 0:
        player.setAdvisor(ChooseAdvisors(player, MasterListofAdvisors, 5, pathDecision2, count, WrongAdvisor));
        break;
    default:
        cout << "Error" << endl;
    }
    return player;
}

int Game::ChooseAdvisors(Player player, string MasterListofAdvisors[], const int ARR4_SIZE, int pathDecision, int count, int WrongAdvisor)
{   
    int AdvisorChoice;
    int finalChoice = 0;
    if (pathDecision == 2)
    {
        // cout <<"path decisions"<< MasterListofAdvisors[2]<<endl;
        cout << endl;
        cout << endl;
        cout << "--------------------------------------" << endl;
        cout << "Possible Advisors" << endl;
        if (count % 2 == 1)
        {
            for (int i = 0; i < ARR4_SIZE; i++)
            {
                cout << MasterListofAdvisors[i] << endl;
            }
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                cout << MasterListofAdvisors[i] << endl;
            }
        }

        cout << "------------" << player.getName() << ", Choose your Advisor Wisely------" << endl;
        cin >> AdvisorChoice;
        //cout<<"count"<<count<<endl;
        if (count % 2 == 1)
        {   
            //cout<<"hi:"<<endl;
            while (AdvisorChoice < 1 || AdvisorChoice > 5)
            {
                cout << "Incorrect option. Choose again" << endl;
                cin >> AdvisorChoice;
            }
            WrongAdvisor = AdvisorChoice;
             //cout<<"WrongChoice: "<<WrongAdvisor;
        }
        
        else
        {
            //cout<<"hi"<<endl;
            //cout<<AdvisorChoice<<endl;
            //cout<<WrongAdvisor<<endl;
             while ((AdvisorChoice == WrongAdvisor) || (AdvisorChoice < 1 || AdvisorChoice > 5))
            {
                cout << AdvisorChoice <<" is not an option. Choose again" << endl;
                cin >> AdvisorChoice;
            }
        }
        finalChoice = AdvisorChoice;
        // remove an index from the array basically.   this is way over complicated but it works so im not touching it
        for (int i = 0; i < 5; i++)
        {
            if (i + 1 == AdvisorChoice)
            {
                // cout <<"1: "<< MasterListofAdvisors[2]<<endl;
                for (int j = i; j < 4; j++)
                {
                    MasterListofAdvisors[j] = MasterListofAdvisors[j + 1];
                    // cout <<"2: "<< MasterListofAdvisors[2]<<endl;
                }
            }
            else
            {
                // cout <<"3: "<< MasterListofAdvisors[2]<<endl;
                continue;
            }
        }
        cout << "-~-~~~~~~~~~~~~~~~~--------------------~~~~~~~~~~~~~~~~~~~~~~~------" << endl;
        return finalChoice;
    }
    else
    {
        return finalChoice;
    }
}

int Game::MainMenu(int count, Player player, Board Board)
{
    // count%2=1 is player1
    // count%2=0 is player 2

    int input;
    cout << "Main Menu: Select an option to continue" << endl;
    cout << "1. Check Player Progress" << endl;
    cout << "2. Review Character" << endl;
    cout << "3. Check Position" << endl;
    cout << "4. Review your Advisor" << endl;
    cout << "5. Move Forward" << endl;
    cin >> input;

    if (input == 1)
    {   
        cout<<endl;
        player.printStatsComplete();
        cout<<endl;
        return input;
    }
    if (input == 2)
    {   
        cout<<endl;
        player.printStatsShort();
        cout<<endl;
        return input;
    }
    if (input == 3)
    {   
        cout<<endl;
        Board.displayBoard();
        cout<<endl;
        return input;
    }
    if (input == 4)
    {
        int advisor = player.getAdvisor();
        string input1;
        int x = 0;
        if (advisor == 1)
        {
            cout << "Rafiki: The Ability to become unseen! ";
            cout << "Have you taken advantage of this? yes or no" << endl;
            cin >> input1;
            while (x == 0)
            {
                if (input1 == "yes")
                {
                    cout << "wonderful!" << endl;
                    x = 1;
                    break;
                }
                else if (input1 == "no")
                {
                    cout << "this will be of use soon" << endl;
                    x = 1;
                    break;
                }
                cout << "invalid response. enter again:" << endl;
                cin >> input1;
            }
        }
        if (advisor == 2)
        {
            cout << "Nala: Night Vision, you see clearly at all times!";
            cout << "Have you taken advantage of this? yes or no" << endl;
            cin >> input1;
            while (x == 0)
            {
                if (input1 == "yes")
                {
                    cout << "wonderful!" << endl;
                    x = 1;
                    break;
                }
                else if (input1 == "no")
                {
                    cout << "this will be of use soon" << endl;
                    x = 1;
                    break;
                }
                cout << "invalid response. enter again:" << endl;
                cin >> input1;
            }
        }
        if (advisor == 3)
        {
            cout << "Sarabi: Energy Manipulation, the ability to shape and control the properties of energy!";
            cout << "Have you taken advantage of this? yes or no" << endl;
            cin >> input1;
            while (x == 0)
            {
                if (input1 == "yes")
                {
                    cout << "wonderful!" << endl;
                    x = 1;
                    break;
                }
                else if (input1 == "no")
                {
                    cout << "this will be of use soon" << endl;
                    x = 1;
                    break;
                }
                cout << "invalid response. enter again:" << endl;
                cin >> input1;
            }
        }
        if (advisor == 4)
        {
            cout << "Zazu: Weather control, you command the clouds!";
            cout << "Have you taken advantage of this? yes or no" << endl;
            cin >> input1;
            while (x == 0)
            {
                if (input1 == "yes")
                {
                    cout << "wonderful!" << endl;
                    x = 1;
                    break;
                }
                else if (input1 == "no")
                {
                    cout << "this will be of use soon" << endl;
                    x = 1;
                    break;
                }
                cout << "invalid response. enter again:" << endl;
                cin >> input1;
            }
        }
        if (advisor == 5)
        {
            cout << "Sarafina: Super Speed, you outrun the competition!";
            cout << "Have you taken advantage of this? yes or no" << endl;
            cin >> input1;
            while (x == 0)
            {
                if (input1 == "yes")
                {
                    cout << "wonderful!" << endl;
                    x = 1;
                    return input;
                    break;
                }
                else if (input1 == "no")
                {
                    cout << "this will be of use soon" << endl;
                    x = 1;
                    return input;
                    break;
                }
                cout << "invalid response. enter again:" << endl;
                cin >> input1;
            }
        }
        return input;
    }
    if (input == 5)
    {
        cout << "You shall continue your Journey!" << endl;
        return input;
    }
    return input;
}

int Game::randNum()
{
    return rand() % 6 + 1;
}
int Game::LoadRandEvents(Game game, string RandEvent[][4], const int arr_size)
{
    ifstream RandEvents("random_events.txt");

    string RandomEvent;
    int count = 0;
    string arr[4];
    // const int ARR3_SIZE = 4;
    while (getline(RandEvents, RandomEvent))
    {
        if (count == 0)
        {
            // cout<<"yo"<<endl;
            count++;
            continue;
        }
        game.split(RandomEvent, '|', arr, 4);
        for (int i = 0; i < 4; i++)
        {
            RandEvent[count-1][i] = arr[i];
        }
        count++; // amount of lines we get from the file
    }
    // cout<<"count: "<<count<<endl;
    RandEvents.close();
    //cout<<"count"<<count;
    // cout<<"hi::"<<RandEvent[0][0];
    return rand() % (count-1); // return a random index taht is in the rang of the file.
}

Player Game::TileEvent(char Color, int player_index, int PlayerPosition, Player player1, Player player2, int PreviousNumber, Game game, Board boards[],const int arr0_size)
{
    string RandEvent[50][4];
    if (Color == 'R') // red
    {
        // cout<<"hi9"<<endl;
        cout << "You Have stumbled into a graveyard and have lost 100 stamina, strength, and wisdom points." << endl;
        cout << "You have also been knocked back 10 positions."<<endl;
        boards[0].movePlayer(player_index, -10);
        player1.setStamina(player.getStamina() - 100);
        player1.setStrength(player.getStrength() - 100);
        player1.setWisdom(player.getWisdom() - 100);
        player1.SetEndofGame(false);
        return player1;
    }
    else if (Color == 'G') // green
    {
         //cout<<"hi10"<<endl;
        //  load in a random event
        int PlayerIDX = LoadRandEvents(game, RandEvent, 50);
        //cout<<"PlayerIDX"<< PlayerIDX<<endl;
        // cout<<"player idx: " << PlayerIDX;
        //cout<<"hi11"<<endl;
        while (stoi(RandEvent[PlayerIDX][1]) != player1.getPathType() - 1 || stoi(RandEvent[PlayerIDX][1]) == 2)
        {
            //cout<<"hi20"<<endl;
            PlayerIDX = LoadRandEvents(game, RandEvent, 50);
        }
        // 50% chance of a random event
        // swtich
        // cout<<"hi21"<<endl;
        switch (rand()%2+1)
        {
        // random event
        case 1:
            // check if they have an adivsor
            // cout<<"hi22"<<endl;
            cout << RandEvent[PlayerIDX][0] << endl;
            // cout<<"hi23"<<endl;
            if (stoi(RandEvent[PlayerIDX][2]) == 0)
            {
                //cout<<"hi24"<<endl;
                player1.setPridePoints(player1.getPridePoints() + stoi(RandEvent[PlayerIDX][3]));
                cout << "Your pride points have changed by: " << RandEvent[PlayerIDX][3] << endl;
                cout << endl;
                cout << endl;
                cout << "~~~~####New Player Stats####~~~~~" << endl;
                player1.printStatsComplete();
                cout << endl;
            }

            // no advisor
            else if (stoi(RandEvent[PlayerIDX][2]) != player.getAdvisor())
            {
                // bad event
                //cout<<"hi26"<<endl;
                player1.setPridePoints(player1.getPridePoints() + stoi(RandEvent[PlayerIDX][3]));
                cout << "You have lost: " << RandEvent[PlayerIDX][3] << " Pridepoints." << endl;
                cout << endl;
                cout << endl;
                cout << "~~~~####New Player Stats####~~~~~" << endl;
                player1.printStatsComplete();
                cout << endl;
            }
            else if (stoi(RandEvent[PlayerIDX][2]) == player1.getAdvisor())
            {
                // bad even
                //cout<<"hi27"<<endl;
                cout << "Your advisor's training has come in handy!! You have lost no Health!" << endl;
                //cout<<"hi28"<<endl;
            }
            break;
        // nothing happens
        case 2:
            break;
        default:
            break;
        }
        player1.SetEndofGame(false);
        return player1;
    }
    else if (Color == 'B') // blue
    {
        // cout<<"hi11"<<endl;
        cout << "~~~~~You have reached and Oasis!!!! sit back and relax~~~~~~. You have gained 200 stamina, strength, and wisdom. " << endl;
        cout << "Now have also been granted an exta turn." << player1.getName() << ", spin again. " << endl;
        player1.setStamina(player1.getStamina() + 200);
        player1.setStrength(player1.getStrength() + 200);
        player1.setWisdom(player1.getWisdom() + 200);
        player1.SetEndofGame(false);
        return player1;
    }
    else if (Color == 'U') // purple
    {
        // cout<<"hi12"<<endl;
        ifstream Riddles("riddles.txt");
        string input;
        string arr[2];
        string RiddleArr[28][2];
        int counter = 0;

        while (getline(Riddles, input))
        {
            game.split(input, '|', arr, 2);
            if (counter == 0)
            {
                counter++;
                continue;
            }
            for (int i = 0; i < 2; i++)
            {
                RiddleArr[counter][i] = arr[i];
            }
            counter++;
        }
        int randIndex = rand() % counter + 1;
        // cout<<"randIDX"<<randIndex<<endl;
        // cout<<"counter"<<counter<<endl;
        string answer;
        cout << "You have been taksed to asnwer a riddle:" << endl;
        cout << RiddleArr[randIndex][0] << endl;
        cin >> answer;

        while (answer != RiddleArr[randIndex][1])
        {
            cout << "wrong answer, try again." << endl;
            cin >> answer;
        }
        cout << "Congradulations,!! That was correct. You have gained 500 wisdom points!" << endl;
        player1.setWisdom(player1.getWisdom() + 500);
        player1.SetEndofGame(false);
        return player1;
    }
    else if (Color == 'N') // brown
    {
        // cout<<"hi13"<<endl;
        cout << "The Hyenas have dragged you back to your last position. You have also lost 300 stamina points." << endl;
        boards[0].movePlayer(player_index, -(PlayerPosition-PreviousNumber));
        player1.setStamina(player1.getStamina() - 300);
        player1.SetEndofGame(false);
        return player1;
    }
    else if (Color == 'P') // pink
    {
        // cout<<"hi14"<<endl;
        cout << "~~~~The land of Enrichment!~~~~" << endl;
        cout << "+300 Stamina, +300 Strength, +300 Wisdom" << endl;
        player1.setStamina(player1.getStamina() + 300);
        player1.setStrength(player1.getStrength() + 300);
        player1.setWisdom(player1.getWisdom() + 300);
        int input;
        if(player1.getAdvisor() == 0){//dont already have an advisor
            cout<<"You May Choose an advisor if you would like."<<endl;
            cout<<"0. None"<<endl;
            cout<<"1. Rafiki-Invisibility"<<endl;
            cout<<"2. Nala-Night Vision"<<endl;
            cout<<"3. Sarabi-Energy Manipulation"<<endl;
            cout<<"4. Zazu-Weather Control"<<endl; 
            cout<<"5. Sarafina- Super Speed"<<endl;
            cin>>input;
            while(input>5 || input<0){
                cout<<"Incorrect Option. Try again"<<endl;
                cin>>input;
            }
            while(input == player2.getAdvisor()){
                cout<<"Advisor has already been by your opponent. Select a new one."<<endl;
                cin>>input;
            }
            player1.setAdvisor(input);
           
        }
        else if(player1.getAdvisor()>0 && player1.getAdvisor()<6){//already have an advisor
            cout<<"You May select a new advisor if wanted."<<endl;
            cout<<"0. None"<<endl;
            cout<<"1. Rafiki-Invisibility"<<endl;
            cout<<"2. Nala-Night Vision"<<endl;
            cout<<"3. Sarabi-Energy Manipulation"<<endl;
            cout<<"4. Zazu-Weather Control"<<endl; 
            cout<<"5. Sarafina- Super Speed"<<endl;
            cout<<"6. No Change to current advisor"<<endl;
            cin>>input;
            while(input>6 || input<0){
                cout<<"Incorrect Option. try again"<<endl;
                cin>>input;
            }
            while(input == player2.getAdvisor()){
                cout<<"Advisor has already been by your opponent. Select a new one."<<endl;
                cin>>input;
            }
            if(input == 6){

            }
            else{
               player1.setAdvisor(input); 
            }
        }

        player1.SetEndofGame(false);
        return player1;
    }
    else if (Color == 'O') // orange
    {
        // cout<<"hi15"<<endl;
        cout << "Congratulations!!!! You Have reached PRIDE ROCK" << endl;
        player1.SetEndofGame(true);
        return player1;
    }
    else if (Color == 'Y') // grey
    {
        // cout<<"hi16"<<endl;
        player1.SetEndofGame(false);
        return player1;
    }
    player1.SetEndofGame(false);
    return player1;
}