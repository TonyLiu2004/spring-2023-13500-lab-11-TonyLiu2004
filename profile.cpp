#include <iostream>
#include "profile.h"

Profile::Profile(std::string usrn, std::string dspn){
        username = usrn;
        displayname = dspn;
}

Profile::Profile(){
    username = "";
    displayname = "";
}

std::string Profile::getUsername(){
    return username;
}

// Return name in the format: "displayname (@username)"
std::string Profile::getFullName(){
    return displayname + " (@" + username + ")";
}

// Change display name
void Profile::setDisplayName(std::string dspn){
    displayname = dspn;
}

void Profile::setUsername(std::string usrn){
    username = usrn;
}