//
// Created by esguevaj on 11/30/19.
//
#include <list>
#include <iostream>
#include "Character.h"
#include "fstream"

#ifndef WHOISWHO_BOARD_H
#define WHOISWHO_BOARD_H
class Board{
    list<Character> board;

    Board(){
        populateBoard();
    }

    void populateBoard(){
        ifstream file("characters.txt");
        if (!file.is_open())
            cout << "File error. Check name/location.\n";
        string name;
        string origin;
        string isDeadTemp;
        string isMarriedTemp;
        string typeTemp;
        string genreTemp;
        string numwinsTemp;

        bool isDead;
        bool isMarried;
        Character::CharacterType type;
        string genre;
        int numWins;
        bool done = true;
        while(file.eof()){
            Character *newCharacter;
            getline(file, name);
            getline(file, origin);
            getline(file, isDeadTemp);
            getline(file, isMarriedTemp);
            getline(file, typeTemp);
            getline(file, genreTemp);
            getline(file, numwinsTemp);

            if(typeTemp == "actor"){
                newCharacter = new Actor();
                newCharacter->setName(name);
                newCharacter->setOrigin(origin);
                newCharacter->setIsDead(isDeadTemp);
                newCharacter->setIsMarried(isMarried);
                newCharacter->setType(typeTemp);
                newCharacter->setGenre(genreTemp);


            } else if(typeTemp == "singer"){
                newCharacter = new Singer();
            }

        }







    }

};
#endif //WHOISWHO_BOARD_H
