#include <iostream>
#include "SDL2/SDL.h"
#include "Handler.h"
#include "Board.h"
#include "Question.h"
#include "Player.h"
#include <ctime>

Handler *handler = nullptr;
int main(int argc, char *args[]) {
    bool check = false;
    Board *celebrities = new Board();
    handler = new Handler();
    QuestionStack *whoQuestion = new QuestionStack;
    Player *computer = new Player;
    srand((unsigned int) time (NULL)); //random seed
    handler->printTitleScreen();

    for (int i = 0; i < NUMBER_PICTURES-1; i++) {
        handler->loadImageTexture(i, celebrities->getCharacter());
    }
    handler->printCharacters();
    //fill questions


    //reset iterator
    celebrities->resetIterator();
    celebrities->setIterator(rand() % 24); //iterate to random position
    //My celebrity for you to guess
    computer->setCharacter(celebrities->getCharacterPrope());

    //feeed questions
    for(int i = 0; i < QUESTION_NUMBER; i++) {
        handler->setQuestion(i, whoQuestion->getQuestion(i));
    }



    while(handler->working()) {
        check = handler->events();
        int counter = handler->getQuestionCounter();
        if (check == true) {
            if (counter >= 0 && counter <= 4) { //origin
                handler->evaluator(whoQuestion->originCheck((computer->getCharacter()), handler->getQuestionCounter()));
            } else if (counter >= 5 && counter <= 6) { //type
                handler->evaluator(whoQuestion->typeCheck((computer->getCharacter()), handler->getQuestionCounter()));
            } else if (counter == 7) {//dead
                handler->evaluator(whoQuestion->isDeadCheck((computer->getCharacter()), handler->getQuestionCounter()));
            } else if (counter == 8) { //married
                handler->evaluator(
                        whoQuestion->isMarriedCheck((computer->getCharacter()), handler->getQuestionCounter()));
            } else if (counter >= 9 && counter <= 10) {
            handler->evaluator(whoQuestion->numWindscheck((computer->getCharacter()), handler->getQuestionCounter()));
            }
        }

    }



    handler->clear();
    return 0;
}


