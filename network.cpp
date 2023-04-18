#include "network.h"
#include "profile.h"

int Network::findID (std::string usrn){
    for(int i = 0;i < numUsers;i++){
        if(profiles[i].getUsername() == usrn){
            return i;
        }
    }
    return -1;
}

Network::Network(){
    numUsers = 0;
}

bool Network::addUser(std::string usrn, std::string dspn){
    if((numUsers >= MAX_USERS) || (usrn.length() == 0)){
        return false;
    }
    for(int i = 0;i < numUsers;i++){
        if(profiles[i].getUsername() == usrn){
            return false;
        }
    }
    for(char x : usrn){
        if(!iswalnum(x)){ // iswalnum returns true if the character is alphanumeric (number or alphabet)
            return false;
        }
    }
    profiles[numUsers].setDisplayName(dspn);
    profiles[numUsers].setUsername(usrn);
    numUsers++;
    return true;
}