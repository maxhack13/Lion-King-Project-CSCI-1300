#include <iostream>
#include "advisor.h"

Advisor::Advisor(int num){
    int x = 0;
    while(x == 0){
    if(num == 1){
        name = "Rafiki";
        Description = "Invisibility: the ability to become un-seen.";
        x=1;
    }
    if(num == 2){
        name = "Nala";
        Description = "Night Vision: The ability to see clearly in darkness";
        x=1;
    }
    if(num == 3){
        name = "Sarabi";
        Description = "Energy Manipulation: The ability to shape and control the properties of energy";
        x=1;
    }
    if(num == 4){
        name = "Zazu";
        Description = "Weather Control: The ability to influence and manipulate weather patterns";
        x=1;
    }
    if(num == 5){
        name = "Sarafina";
        Description = "Super Speed: The ability to run 4x faster than the maximum speed of lions";
        x=1;
    }
    if(num == 0){//went to pride lands
        name = "";
        Description = "";
        x=1;
    }
    // else{
    //     "invalid response, try again";
    // }
    }
}

void Advisor::setAdvisor(int num){
     int x = 0;
    while(x == 0){
    if(num == 1){
        name = "Rafiki";
        Description = "Invisibility: the ability to become un-seen.";
        x=1;
    }
    if(num == 2){
        name = "Nala";
        Description = "Night Vision: The ability to see clearly in darkness";
        x=1;
    }
    if(num == 3){
        name = "Sarabi";
        Description = "Energy Manipulation: The ability to shape and control the properties of energy";
        x=1;
    }
    if(num == 4){
        name = "Zazu";
        Description = "Weather Control: The ability to influence and manipulate weather patterns";
        x=1;
    }
    if(num == 5){
        name = "Sarafina";
        Description = "Super Speed: The ability to run 4x faster than the maximum speed of lions";
        x=1;
    }
    if(num == 0){//went to pride lands
        name = "";
        Description = "";
        x=1;
    }
    // else{
    //     "invalid response, try again";
    // }
    }
}
string Advisor::getName(){
    return name;
}
string Advisor::getDescription(){
    return Description;
}

int Advisor::getNum(){
    return num;
}

void Advisor::displayStats(){
    cout<<"Advisors Name: "<<name<<endl;
    cout<<"Advisors Description and abilitys: "<<Description<<endl;
}