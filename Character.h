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
    string picPath;

public:
    Character(string name, string origin, bool isDead, bool isMarried, CharacterType type, string path){
        this->name = name;
        this->origin = origin;
        this->isDead = isDead;
        this->isMarried = isMarried;
        this->type = type;
        this->picPath = path;
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

    bool nameEquals(string name){
        return this->name == name;
    }

    string getOrigin(){
        return origin;
    }

    void setOrigin(string origin){
        this->origin = origin;
    }

    bool OriginEquals(string origin){
        return this->origin == origin;
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
    CharacterType ConvertsetType(string type){
        if(type == "Actor" || type == "actor"){
            return  actor;
        } else if(type == "Singer" || type == "singer"){
            return singer;
        } else{
            throw invalid_argument(type + " wrong input");
        }
    }

    bool typeEquals(string type){
        return this->type == ConvertsetType(type);
    }

    void setPicPath(string path){
        picPath = path;
    }

    string getPicPath(){
        return picPath;
    }


    virtual bool genEquals(string gen){
        return false;
    }
    virtual bool numWinsEquals(int){return false;}

    virtual void print(){
        cout<<"Name: " << name << " Origin: " << origin << " isDead: " << isDead << " isMarried: " << isMarried << " type: " << type<<endl;
    }
};

class Singer:public Character{

private:

    string gen;
    int grammyAwards;

public:
    Singer(){

    }
    Singer(string name, string origin, bool isDead, bool isMarried, CharacterType type, string path, string gen, int grammyAwards):Character(name, origin, isDead, isMarried, type, path){
        this->gen = gen;
        this->grammyAwards = grammyAwards;
    }
    Singer(string name, string origin, string isDead, string isMarried, string type, string path, string gen, int grammyAwards){
        setName(name);
        setOrigin(origin);
        setIsDead(isDead);
        setIsMarried(isMarried);
        setType(type);
        setPicPath(path);
        this->gen = gen;
        this->grammyAwards = grammyAwards;
    }
    string getGenre(){
        return gen;
    }
    void setGenre(string genre){
        gen = genre;
    }

    bool genEquals(string gen){
        return this->gen == gen;
    }

    int getGrammyAwards(){
        return grammyAwards;
    }

    void setGrammyAwards(int numGrammyAwards){
        grammyAwards = numGrammyAwards;
    }

    bool numWinsEquals(int num){
        return grammyAwards == num;
    }



    void print(){
        cout<<"Name: " << getName() << " Origin: " << getOrigin() << " isDead: " << getIsDead() << " isMarried: " << getIsMarried() << " type: " << getType()
        << " Genre: " << gen << " GrammyAwards: " << grammyAwards <<endl;
    }

};

class Actor:public Character{
private:

    string gen;
    int oscars;

public:
    Actor():Character(){

    }
    Actor(string name, string origin, bool isDead, bool isMarried, CharacterType type, string path, string gen, int oscars):Character(name, origin, isDead, isMarried, type, path){
        this->gen = gen;
        this->oscars = oscars;
    }
    Actor(string name, string origin, string isDead, string isMarried, string type, string path, string gen, int oscars){
        setName(name);
        setOrigin(origin);
        setIsDead(isDead);
        setIsMarried(isMarried);
        setType(type);
        setPicPath(path);
        this->gen = gen;
        this->oscars = oscars;
    }
    string getGenre(){
        return gen;
    }
    void setGenre(string genre){
        gen = genre;
    }

    virtual bool genEquals(string gen){
        return this->gen == gen;
    }

    int getOscars(){
        return oscars;
    }

    void setOscars(int numoscars){
        oscars = numoscars;
    }
    bool numWinsEquals(int num){
        return oscars == num;
    }

    void print(){
        cout<<"Name: " << getName() << " Origin: " << getOrigin() << " isDead: " << getIsDead() << " isMarried: " << getIsMarried() << " type: " << getType()
            << " Genre: " << gen << " GrammyAwards: " << oscars <<endl;
    }
};

#endif //WHOISWHO_CHARACTER_H
