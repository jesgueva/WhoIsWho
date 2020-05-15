//
// Created by esguevaj on 12/6/19.
//

#ifndef SDL_TEST_PLAYER_H
#define SDL_TEST_PLAYER_H
class Player{
private:
    Character myCharacter;

public:
    void setCharacter(Character foo){
        cout<<"My Character: "<< foo.getName()<<endl;
        this->myCharacter = foo;
    }

    Character getCharacter(){
        return myCharacter;
    }
};

#endif //SDL_TEST_PLAYER_H
