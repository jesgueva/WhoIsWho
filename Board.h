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

            getline(file, name);
            getline(file, origin);
            getline(file, isDeadTemp);
            getline(file, isMarriedTemp);
            getline(file, typeTemp);
            getline(file, genreTemp);
            getline(file, numwinsTemp);

            if(typeTemp == "actor"){
                Actor *newCharacter;
                newCharacter = new Actor();
                newCharacter->setName(name);
                newCharacter->setOrigin(origin);
                newCharacter->setIsDead(isDeadTemp);
                newCharacter->setIsMarried(isMarried);
                newCharacter->setType(typeTemp);
                newCharacter->setGenre(genreTemp);
                newCharacter->setOscars(atoi(numwinsTemp.c_str()));
                board.push_back(*newCharacter);

            } else if(typeTemp == "singer"){
                Singer *newCharacter;
                newCharacter = new Singer();
                newCharacter->setName(name);
                newCharacter->setOrigin(origin);
                newCharacter->setIsDead(isDeadTemp);
                newCharacter->setIsMarried(isMarried);
                newCharacter->setType(typeTemp);
                newCharacter->setGenre(genreTemp);
                newCharacter->setGrammyAwards(atoi(numwinsTemp.c_str()));
                board.push_back(*newCharacter);
            }


        }







    }

};
#endif //WHOISWHO_BOARD_H
