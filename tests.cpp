#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"

TEST_CASE("Profile Class"){
    Profile p1("marco", "Marco");
    CHECK(p1.getUsername() == "marco");
    CHECK(p1.getFullName() == "Marco (@marco)");

    p1.setDisplayName("Marco Rossi");
    CHECK(p1.getUsername() == "marco");
    CHECK(p1.getFullName() == "Marco Rossi (@marco)");

    Profile p2("tarma1", "Tarma Roving");
    CHECK(p2.getUsername() == "tarma1");
    CHECK(p2.getFullName() == "Tarma Roving (@tarma1)");
}

TEST_CASE("Network Class"){
    Network nw;
    CHECK(nw.addUser("mario", "Mario") == true);
    CHECK(nw.addUser("luigi", "Luigi") == true);

    CHECK(nw.addUser("mario", "Mario2") == false);
    CHECK(nw.addUser("mario 2", "Mario2") == false);
    CHECK(nw.addUser("mario-2", "Mario2") == false);

    for(int i = 2; i < 20; i++)
    CHECK(nw.addUser("mario" + std::to_string(i),"Mario" + std::to_string(i)) == true);

    CHECK(nw.addUser("yoshi", "Yoshi") == false);
}