//
// Created by esguevaj on 12/5/19.
//
#include "Character.h"
#include <fstream>
#ifndef SDL_TEST_QUESTION_H
#define SDL_TEST_QUESTION_H
const int QUESTION_NUMBER = 11;


class QuestionStack{
private:
    string questionArr[QUESTION_NUMBER];
//    string questionArr[QUESTION_NUMBER] = {
//            "1.What weird food combinations do you really enjoy?",
//            "2.What social stigma does society need to get over?",
//            "3.What food have you never eaten but would really like to try?",
//            "4.What’s something you really resent paying for?",
//            "5.What would a world populated by clones of you be like?"
//    };
    string questionKey[QUESTION_NUMBER];
//    string questionKey[QUESTION_NUMBER] = {
//
//            "American",
//            "English",
//            "Israeli",
//            "Australian",
//            "Irish"
//    };

public:
    QuestionStack(){
        populateQuestions();
    }

    void populateQuestions(){
        ifstream file("files/questionList.txt");
        if (!file.is_open()) {
            cout << "Questions file error. Check name/location.\n";
            exit(6);
        }
        string question;
        string key;

        for(int i = 0; i<11; i++){
            getline(file, key);
            getline(file, question);
            questionArr[i] = question;
            questionKey[i] = key;
        }
    }
    string getQuestion(int index){
        return questionArr[index];
    }
    string getQuestionKey(int index){
        return questionKey[index];
    }

    bool checkName(Character myCharacter, int index){
        return myCharacter.nameEquals(questionKey[index]);
    }

    bool originCheck(Character myCharacter, int index){
        return myCharacter.OriginEquals(questionKey[index]);
    }

    bool isDeadCheck(Character myCharacter, int index){
        return myCharacter.getIsDead();
    }

    bool isMarriedCheck(Character myCharacter, int index){
        return myCharacter.getIsMarried();
    }

    bool typeCheck(Character myCharacter, int index){
        return myCharacter.typeEquals(questionKey[index]);
    }

    bool genreCheckCheck(Character myCharacter, int index){
        return myCharacter.genEquals(questionKey[index]);
    }

    bool numWindscheck(Character myCharacter, int index){
        return myCharacter.numWinsEquals(atoi(questionKey[index].c_str()));
    }


};
#endif //SDL_TEST_QUESTION_H


