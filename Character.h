//
// Created by esguevaj on 11/29/19.
//

#include <string>
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
        this->origin;
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
    bool stringToBool(stirng logic){
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
        if(type == "actor"){
            this->type = actor;
        } else if(type == "singer"){
            this->type = singer;
        } else{
            throw invalid_argument(type + " wrong input");
        }
    }
};

class Singer:public Character{
public:
    enum Genre{rock, pop, size = 2};
    string GenreString[5] = {"Rock", "Pop"};
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

};

class Actor:public Character{
public:
    string Genre[5] = {"Rock", "pop"};
private:

    string gen;
    int oscars;

public:
    Actor(){

    }
    Actor(string name, string origin, bool isDead, bool isMarried, CharacterType type, string gen, int oscars):Character(name, origin, isDead, isMarried, type){
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
};

#endif //WHOISWHO_CHARACTER_H
