#include <iostream>
#include <fstream>
#include "player.h"
#include "advisor.h"

Player::Player()
{
    _name = "";
    _age = 1;
    _stamina = 100;
    _wisdom = 100;
    _pride_points = 0;
    _strength = 100;
    _advisor = 0;
    _endofGame = false;    
}
Player::Player(string name, int strength, int stamina, int wisdom)
{
    _name = name;
    _age = 1;
    _pride_points = 0;
    if (strength > 100 && strength < 1000)
    {
        _strength = strength;
    }
    else
    {
        _strength = 100;
    }
    if (stamina > 100 && stamina < 1000)
    {
        _stamina = stamina;
    }
    else
    {
        _stamina = 100;
    }
    if (wisdom > 100 && wisdom < 1000)
    {
        _wisdom = wisdom;
    }
    else
    {
        _wisdom = 100;
    }
}

string Player::getName()
{
    return _name;
}
int Player::getStrength()
{
    return _strength;
}
int Player::getStamina()
{
    return _stamina;
}

int Player::getWisdom()
{
    return _wisdom;
}
int Player::getPridePoints()
{
    return _pride_points;
}
int Player::getAge()
{
    return _age;
}
int Player::getAdvisor()
{
    return _advisor;
}
int Player::getPathType()
{
    return _pathType;
}

void Player::setName(string name)
{
    _name = name;
}
void Player::setStrength(int strength)
{
    if (strength <= 0)
    {
        _strength = 100;
    }
    else
    {
        _strength = strength;
    }
}
void Player::setStamina(int stamina)
{
    if (stamina <= 0)
    {
        _stamina = 100;
    }
    else
    {
        _stamina = stamina;
    }
}
void Player::setWisdom(int wisdom)
{
    if (wisdom <= 0)
    {
        _wisdom = 100;
    }
    else
    {
        _wisdom = wisdom;
    }
}
void Player::setPridePoints(int pride_points)
{
    if (pride_points < 0)
    {
        _pride_points = 0;
    }
    else
    {
        _pride_points = pride_points;
    }
}
void Player::setAge(int age)
{
    if (age < 0)
    {
        _age = 1;
    }
    else
    {
        _age = age;
    }
}
void Player::setAdvisor(int advisor)
{
    _advisor = advisor;
}
void Player::setPathType(int pathDecision)
{
    _pathType = pathDecision;
}

void Player::trainCub(int strength, int stamina, int wisdom)
{
    if (strength < 0)
    {
    }
    else
    {
        _strength += strength;
    }
    if (stamina < 0)
    {
    }
    else
    {
        _stamina += stamina;
    }
    if (wisdom < 0)
    {
    }
    else
    {
        _wisdom += wisdom;
    }
    _pride_points -= 5000;
}
void Player::toPrideLands()
{
    _pride_points += 5000;
    if (_strength < 200)
    {
        _strength = 0;
    }
    else
    {
        _strength -= 200;
    }
    if (_wisdom < 200)
    {
        _wisdom = 0;
    }
    else
    {
        _wisdom -= 200;
    }
    if (_stamina < 100)
    {
        _stamina = 0;
    }
    else
    {
        _stamina -= 200;
    }
}
void Player::printStatsComplete()
{
    cout << "Player Stats:" << endl;
    cout << _name << ", " << _age << " years old" << endl;
    cout << "strength: " << _strength << endl;
    cout << "stamina: " << _stamina << endl;
    cout << "wisdom: " << _wisdom << endl;
    cout << "PridePoints: " << _pride_points << endl;
    cout << "Advisor: ";
    switch (_advisor)
    {
    case 1:
        cout << "RafikiInvisibility-" << endl;
        break;
    case 2:
        cout << "Nala-Night Vision" << endl;
        break;
    case 3:
        cout << "Sarabi-Energy Manipulation" << endl;
        break;
    case 4:
        cout << "Zazu-Weather Control" << endl;
        break;
    case 5:
        cout << "Sarafina-Super Speed" << endl;
        break;
    default:
        cout << endl;
        break;
    }
    cout << "Path Chosen: ";
    switch (_pathType)
    {
    case 1:
        cout << "PrideLands Imediately." << endl;
        break;
    case 2:
        cout << "Cub Training." << endl;
        break;
    default:
        cout << endl;
        break;
    }
}

void Player::printStatsShort()
{
    cout << "Player Stats:" << endl;
    cout << _name << ", " << _age << " years old" << endl;
}

bool Player::getEndofGame()
{
    return _endofGame;
}
void Player::SetEndofGame(bool endOFgame)
{
    _endofGame = endOFgame;
}
void Player::EndOFGamePrint(string file, int Ppoint1, int Ppoint2, int playerIndex, int counts)
{
    fstream fout;
    switch (playerIndex)
    {
    case 1:
        fout.open(file);
        fout << "GAME STATS" << endl;
        fout << "Player 1's stats: " << endl;
        break;
    case 2:
        fout.open(file, fstream::app);
        fout << "Player 2's stats: " << endl;
        break;
    default:
        break;
    }
    // fout << "Player Stats:" << endl;
    fout << _name << ", " << _age << " years old" << endl;
    fout << "strength: " << _strength << endl;
    fout << "stamina: " << _stamina << endl;
    fout << "wisdom: " << _wisdom << endl;
    fout << "PridePoints: " << _pride_points << endl;
    fout << "Advisor: ";
    switch (_advisor)
    {
    case 1:
        fout << "RafikiInvisibility-" << endl;
        break;
    case 2:
        fout << "Nala-Night Vision" << endl;
        break;
    case 3:
        fout << "Sarabi-Energy Manipulation" << endl;
        break;
    case 4:
        fout << "Zazu-Weather Control" << endl;
        break;
    case 5:
        fout << "Sarafina-Super Speed" << endl;
        break;
    default:
        fout << endl;
        break;
    }
    fout << "Path Chosen: ";
    switch (_pathType)
    {
    case 1:
        fout << "PrideLands Imediately." << endl;
        break;
    case 2:
        fout << "Cub Training." << endl;
        break;
    default:
        fout << endl;
        break;
    }
    if (playerIndex == 1)
    {
        fout << "Total Final Pride Points: ";
        fout << Ppoint1 << endl;
    }
    else
    {
        fout << "Total Final Pride Points: ";
        fout << Ppoint2 << endl;
    }

    if (counts == 1)
    {   
        if (Ppoint1 > Ppoint2)
        {
            fout << "Player 1 wins and will rule the Pridelands!!!" << endl;
        }
        else if (Ppoint2 > Ppoint1)
        {
            fout << "Player 2 wins and will rule the Pridelands!!!" << endl;
        }
        else
        {
            fout << "The two lions will rule in Unison as their Pridefullness is the same!!!!";
        }
    }
    else{}

    cout << endl;
    fout << "---------------------------------------" << endl;
    cout << endl;
    //fout.close();
}
