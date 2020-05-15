//
// Created by esguevaj on 11/30/19.
//
#include <list>
#include <iostream>
#include "Character.h"
#include "fstream"
#include <cstdlib>

#ifndef WHOISWHO_BOARD_H
#define WHOISWHO_BOARD_H
class Board{
    list<Character> board;

    list<Character>::iterator iter;

public:
    Board(){
        populateBoard();
        iter = board.begin();
    }
    //debug
    void printBoard(){
        list<Character>::iterator iter;
        for(iter = board.begin(); iter != board.end(); iter++){
            iter->print();
        }
    }

    void setIterator(int index){
        advance(iter, index);
    }

    string getCharacter(){
        string path = (iter->getPicPath());
        iter++;
        resetIterator();
        return path;
    }



//    Character *getCharacterPrope(){
//        return search(iter->getName());
//    }

    Character getCharacterPrope(){
        return *iter;
    }

    Character *search(string tempName) {
        if (!board.empty()) {
            list<Character>::iterator iter;
            for (iter = board.begin(); iter != board.end(); iter++) {
                if (iter->getName() == tempName) {
                    return &(*iter);
                }
            }

        }

        return NULL;
    }

    void resetIterator(){
        if(iter == board.end()){
            iter = board.begin();
        }
    }

    void populateBoard(){
        ifstream file("files/characters.txt");
        if (!file.is_open()) {
            cout << "Characters file error. Check name/location.\n";
            exit(5);
        }
        int counter = 1;
        string name;
        string origin;
        string isDeadTemp;
        string isMarriedTemp;
        string typeTemp;
        string genreTemp;
        string numwinsTemp;
        string newPath;
        while(!file.eof()){
            Character * newCharacter;
            getline(file, name);
            getline(file, origin);
            getline(file, isDeadTemp);
            getline(file, isMarriedTemp);
            getline(file, typeTemp);
            getline(file, numwinsTemp);
            getline(file, genreTemp);
            newPath = getPath(counter);

            if(typeTemp == "Actor" || typeTemp == "actor"){
                //Actor *newCharacter;
                newCharacter = new Actor(name, origin, isDeadTemp, isMarriedTemp, typeTemp, newPath,genreTemp, atoi(numwinsTemp.c_str()));
//                newCharacter->setName(name);
//                newCharacter->setOrigin(origin);
//                newCharacter->setIsDead(isDeadTemp);
//                newCharacter->setIsMarried(isMarriedTemp);
//                newCharacter->setType(typeTemp);
//                newCharacter->setGenre(genreTemp);
//                newCharacter->setOscars(atoi(numwinsTemp.c_str()));
                board.push_back(*newCharacter);

            } else if(typeTemp == "Singer" || typeTemp == "singer"){
                //Singer *newCharacter;
                newCharacter = new Singer(name, origin, isDeadTemp, isMarriedTemp, typeTemp, newPath, genreTemp, atoi(numwinsTemp.c_str()));
//                newCharacter->setName(name);
//                newCharacter->setOrigin(origin);
//                newCharacter->setIsDead(isDeadTemp);
//                newCharacter->setIsMarried(isMarriedTemp);
//                newCharacter->setType(typeTemp);
//                newCharacter->setGenre(genreTemp);
//                newCharacter->setGrammyAwards(atoi(numwinsTemp.c_str()));
                board.push_back(*newCharacter);
            }
            counter++; //increase counter path


        }

    }
    string getPath(int fileNum){
        string pathFull = "pics/media/";
        pathFull.append(to_string(fileNum));
        pathFull.append(".png");
        return pathFull;
    }

};
#endif //WHOISWHO_BOARD_H
