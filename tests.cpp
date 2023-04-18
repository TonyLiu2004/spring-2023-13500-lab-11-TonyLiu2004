#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"

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