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

    bool getIsMarried(){
        return isMarried;
    }
    void setIsMarried(bool isMarried){
        this->isMarried = isMarried;
    }
    CharacterType getType(){
        return type;
    }
    void setType(CharacterType type){
        this->type = type;
    }
};

class Singer:public Character{
public:
    enum Genre{rock, pop};
private:

    Genre gen;
    int grammyAwards;

public:
    Singer(string name, string origin, bool isDead, bool isMarried, CharacterType type, Genre gen, int grammyAwards):Character(name, origin, isDead, isMarried, type){
        this->gen = gen;
        this->grammyAwards = grammyAwards;
    }
    Genre getGenre(){
        return gen;
    }
    void setGenre(Genre genre){
        gen = genre;
    }

    int getGrammyAwards(){
        return grammyAwards;
    }

    void setGrammyAwards(int numGrammyAwards){
        grammyAwards = numGrammyAwards;
    }



};

#endif //WHOISWHO_CHARACTER_H
