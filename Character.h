//
// Created by esguevaj on 11/29/19.
//

#include <string>
#include <iostream>

using namespace std;
#ifndef WHOISWHO_CHARACTER_H
#define WHOISWHO_CHARACTER_H

class Character {
public:
    enum CharacterType{actor, singer};
private:
    string name;
    string origin;
    bool isDead;
    bool isMarried;
    CharacterType type;

public:
    Character(string name, string origin, bool isDead, bool isMarried, CharacterType type){
        this->name = name;
        this->origin = origin;
        this->isDead = isDead;
        this->isMarried = isMarried;
        this->type = type;
    }

    Character(){
        //empty constructor
    }

    string getName(){
        return name;
    }
    void setName(string name){
        this->name = name;
    }

    string getOrigin(){
        return origin;
    }

    void setOrigin(string origin){
        this->origin = origin;
    }

    bool getIsDead(){
        return isDead;
    }

    void setIsDead(bool isDead){
        this->isDead = isDead;
    }

    void setIsDead(string isDead){
        this->isDead = stringToBool(isDead);
    }
    bool stringToBool(string logic){
        if(logic == "0"){
            return false;
        } else if(logic == "1"){
            return true;
        } else{
            throw invalid_argument(isDead + " is a wrong input.");
        }
    }

    bool getIsMarried(){
        return isMarried;
    }
    void setIsMarried(bool isMarried){
        this->isMarried = isMarried;
    }

    void setIsMarried(string isMarried){
        this->isMarried = stringToBool(isMarried);
    }
    CharacterType getType(){
        return type;
    }
    void setType(CharacterType type){
        this->type = type;
    }
    void setType(string type){
        if(type == "Actor" || type == "actor"){
            this->type = actor;
        } else if(type == "Singer" || type == "singer"){
            this->type = singer;
        } else{
            throw invalid_argument(type + " wrong input");
        }
    }

    virtual void print(){
        cout<<"Name: " << name << " Origin: " << origin << " isDead: " << isDead << " isMarried: " << isMarried << " type: " << type<<endl;
    }
};

class Singer:public Character{
//public:
//    string GenreString[4] = {"Rap", "R&B", "Rock", "Pop"};
private:

    string gen;
    int grammyAwards;

public:
    Singer(){

    }
    Singer(string name, string origin, bool isDead, bool isMarried, CharacterType type, string gen, int grammyAwards):Character(name, origin, isDead, isMarried, type){
        this->gen = gen;
        this->grammyAwards = grammyAwards;
    }
    Singer(string name, string origin, string isDead, string isMarried, string type, string gen, int grammyAwards){
        setName(name);
        setOrigin(origin);
        setIsDead(isDead);
        setIsMarried(isMarried);
        setType(type);
        this->gen = gen;
        this->grammyAwards = grammyAwards;
    }
    string getGenre(){
        return gen;
    }
    void setGenre(string genre){
        gen = genre;
    }

    int getGrammyAwards(){
        return grammyAwards;
    }

    void setGrammyAwards(int numGrammyAwards){
        grammyAwards = numGrammyAwards;
    }

    void print(){
        cout<<"Name12: " << getName() << " Origin: " << getOrigin() << " isDead: " << getIsDead() << " isMarried: " << getIsMarried() << " type: " << getType()
        << " Genre: " << gen << " GrammyAwards: " << grammyAwards <<endl;
    }

};

class Actor:public Character{
//public:
//    string Genre[5] = {"Action", "Reality TV", "Comedy", "Drama"};
private:

    string gen;
    int oscars;

public:
    Actor():Character(){

    }
    Actor(string name, string origin, bool isDead, bool isMarried, CharacterType type, string gen, int oscars):Character(name, origin, isDead, isMarried, type){
        this->gen = gen;
        this->oscars = oscars;
    }
    Actor(string name, string origin, string isDead, string isMarried, string type, string gen, int oscars){
        setName(name);
        setOrigin(origin);
        setIsDead(isDead);
        setIsMarried(isMarried);
        setType(type);
        this->gen = gen;
        this->oscars = oscars;
    }
    string getGenre(){
        return gen;
    }
    void setGenre(string genre){
        gen = genre;
    }

    int getOscars(){
        return oscars;
    }

    void setOscars(int numoscars){
        oscars = numoscars;
    }

    void print(){
        cout<<"Name: " << getName() << " Origin: " << getOrigin() << " isDead: " << getIsDead() << " isMarried: " << getIsMarried() << " type: " << getType()
            << " Genre: " << gen << " GrammyAwards: " << oscars <<endl;
    }
};

#endif //WHOISWHO_CHARACTER_H
