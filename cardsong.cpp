//
// Created by melan on 8/1/2023.
//
//
// Created by melan on 7/21/2023.
// Melanie Saenzpardo ECE312 Summer 2023
//
#include <iostream>
#include <string>
#include "cardsong.h"

using namespace std;

Card :: Card() {
    // default, ace of spades
    myRank = 1;
    mySuit = Suit(0);
}
// constructor for user to implement
Card :: Card(int myRank, Suit s) {
    this->myRank = myRank;
    mySuit = s;
}
// return string version e.g. Ac 4h Js
string Card :: toString() const {
    return (this->rankString(myRank))+(this->suitString(mySuit));
}
// true if suit same as c
bool Card ::sameSuitAs(const Card &c) const {
    return (mySuit == c.mySuit);
}
// return rank, 1..13
int Card ::getRank() const {
    return myRank;
}
// return "s", "h",...
string Card ::suitString(Card::Suit s) const {
    string res;
    if (s == Suit(0)) {
        res = "s";
        return res;
    }

    else if (s == Suit(1)) {
        res = "h";
        return res;
    }

    else if (s == Suit(2)) {
        res = "d";
        return res;
    }

    else if (s == Suit(3)){
        res = "c";
        return res;
    }

    else {
        res = "Error";
        return res;
    }
}
// return "A", "2", ..."Q"
string Card ::rankString(int r) const {
    if (r >= 2 && r <= 10) {
        string res = to_string(r);
        return res;
    }

    else if (r == 1) {
        string res = "A";
        return res;
    }

    else if (r == 11) {
        string res = "J";
        return res;
    }

    else if (r == 12) {
        string res = "Q";
        return res;
    }

    else if (r == 13) {
        string res = "K";
        return res;
    }

    else {
        string res = "Error";
        return res;
    }
}

// define boolean operations in order to determine whether some ranks are equal
// or nor equal
bool Card ::operator==(const Card &rhs) const {
    return (myRank == rhs.myRank);
}

bool Card ::operator!=(const Card &rhs) const {
    return (myRank != rhs.myRank);
}

bool Card::operator < (const Card& rhs) const {
    return (myRank < rhs.myRank);
}
bool Card::operator > (const Card& rhs) const {
    return (myRank > rhs.myRank);
}
