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
    for(int row = 0;row < MAX_USERS;row++){
        for(int col = 0;col < MAX_USERS;col++){
            following[row][col] = false;
        }
    }
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

bool Network::follow(std::string usrn1, std::string usrn2){
    if((Network::findID(usrn1) == -1) || (Network::findID(usrn2) == -1)){
        std::cout << "cannot add";
        return false;
    }
    for(int row = 0;row < MAX_USERS;row++){
        for(int col = 0;col < MAX_USERS;col++){
            if((Network::findID(usrn1) == row) && (Network::findID(usrn2) == col)){
                following[row][col] = true;
            }
        }
    }
    return true;
}

void Network::printDot(){
    std::cout << "  digraph {" << std::endl;
    for(int i = 0;i < numUsers;i++){
        std::cout << "   \"@" <<  profiles[i].getUsername() << "\"" << "\n";
    }
    for(int row = 0;row < MAX_USERS;row++){
        for(int col = 0;col < MAX_USERS;col++){
            if(following[row][col]){
                std::cout << "   \"@" <<  profiles[row].getUsername() << "\"" << " -> \"@" << profiles[col].getUsername() << "\""<< "\n";
            }
        }
    }
    std::cout << "}" << "\n";
}