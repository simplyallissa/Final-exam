//
// Created by Allissa Hertz on 11/26/22.
//

#include "ActorActress.h"
using namespace std;

 //Contructor functionality
ActorActress::ActorActress()
{
}
ActorActress::ActorActress(int year, string award, bool isWinner, string name, string film)
{
    this->setYear(year);
    this->setAward(award);
    this->setWinner(isWinner);
    this->setName(name);
    this->setFilm(film);
}
    
//Implemented Getters
int ActorActress::getYear() const {
    return year;
}
string ActorActress::getAward() const {
    return award;
}
bool ActorActress::getWinner() const {
    return winner;
}
string ActorActress::getName() const {
    return name;
}
string ActorActress::getFilm() const {
    return film;
}

//Implemented Setters
void ActorActress::setYear(int y) {
    year = y;
}
void ActorActress::setAward(string a) {
    award = a;
}
void ActorActress::setWinner(bool w) {
    winner = w;
}
void ActorActress::setName(string n) {
    name = n;
}
void ActorActress::setFilm(string f) {
    film = f;
}


string ActorActress::print() const {
    //create a string formated as year,award,isWinner,name,film and print to the console
    string returnString;
    if (this->getYear() == -1){
        returnString += ",";
    } else {
        returnString += to_string(this->getYear()) + ",";
    }
    returnString +=this->getAward()+",";
    if (this->getWinner())
        returnString += "yes,";
    else
        returnString += "no,";
    returnString += this->getName()+","+this->getFilm();
    return returnString;
}
