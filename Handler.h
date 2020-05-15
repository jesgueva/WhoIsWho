//
// Created by sambom on 12/3/2019.
//
#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"


#include <iostream>

using namespace std;

#ifndef WHOISWHO_HANDLER_H
#define WHOISWHO_HANDLER_H

//Constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 540;
const int NUMBER_PICTURES = 25;
const int WIDTH_IMAGES = 106;
const int HEIGHT_IMAGES = 117;
const int QUESTION_NUMBER1 = 11;


class Handler{
private:
    bool running; //Initialization successful
    SDL_Window *window; //window
    SDL_Renderer *renderer; //renderer
    SDL_Texture *picture [NUMBER_PICTURES]; //texture 25 num of pictures
    SDL_Rect questionRect, pictureRect;
    TTF_Font *questionFont;
    string question[QUESTION_NUMBER1];
    bool pressed = false;
//    string question[5] = {
//            "1.What weird food combinations do you really enjoy?",
//            "2.What social stigma does society need to get over?",
//            "3.What food have you never eaten but would really like to try?",
//            "4.What’s something you really resent paying for?",
//            "5.What would a world populated by clones of you be like?"
//    };
    int questionCounter;
public:
    Handler(){
        init("Who is Wu", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT);
        pictureRect = {0,0, WIDTH_IMAGES, HEIGHT_IMAGES};
        //loadImageTexture(p); //load picture array
        questionCounter = 0;
        //loadText("The quick brown fox jumps over the lazy dog");



    };
    ~Handler();

    void init(const char* title, int xpos, int ypos, int width,int height);

    void setQuestion(int index, string  question){

            this->question[index] = question;

    }

    void render(SDL_Texture* texture, SDL_Rect destination) {
        //
        //add things to render
        SDL_RenderCopy(renderer,texture,NULL,&destination);
        SDL_RenderPresent(renderer);
    }
    void clear();
    bool events();
    void loadText( string text){
        if(questionFont == NULL){
            cout<<"Font not found.\n";
            exit(3);
        }
        SDL_Color textColor = {0, 0, 0}; //Black
        SDL_Surface* textSurface = TTF_RenderText_Solid(questionFont, text.c_str(), textColor);

        SDL_Texture* questionTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_FreeSurface( textSurface ); //Free Surface
        questionRect.x = xCenterText(text);
        questionRect.w = text.size()*10+10;
        render(questionTexture, questionRect);





        //make equation in terms of %width and legnht given the position of the mouse click.
        //left and right change questions


    }

    void clearRect(SDL_Rect rect){
        SDL_RenderFillRect(renderer, &rect);
        SDL_RenderPresent(renderer);
    }

    void nextQuestion(){
        clearRect(questionRect);
        loadText(question[questionCounter]);

    }

    void prevQuestion(){
        clearRect(questionRect);
        loadText(question[questionCounter]);

    }

    SDL_Texture *loadImage(string CharacterPath){
        SDL_Surface* surface = IMG_Load(CharacterPath.c_str());
        SDL_Texture* myTexture;
        if(surface == NULL){
            cout<<"image file could not be found. Check file location.\n";
        }
        myTexture = SDL_CreateTextureFromSurface(renderer,surface);
        SDL_FreeSurface(surface);
        return myTexture;
    }

    void loadImageTexture(int i, string path){
        picture[i] = loadImage(path); //Adding textures from files
    }



    void crossCharacter(int x, int y){
        //SDL_Rect target = {0,0, WIDTH_IMAGES, HEIGHT_IMAGES};
        SDL_Texture *cross = loadImage("pics/media/25.png");
        render(cross, getClickedRect(x, y));
    }
    void unCrossCharacter(int x, int y){
        SDL_Rect target = getClickedRect(x,y);
        clearRect(target);
        render(picture[getImage(x,y)], target);
    }
    void printTitleScreen(){
        SDL_Rect target = {0,0, SCREEN_WIDTH, SCREEN_HEIGHT-100};
        SDL_Texture *cross = loadImage("Title screen.png");
        render(cross, target);
        SDL_Delay(5000);
        SDL_RenderClear(renderer);
    }

    void printCharacters(){
        //renderBoard

        for (int i = 0; i < NUMBER_PICTURES ; i++) {

            render(picture[i-1], pictureRect);
            if(i%6 == 0 && i > 0){

                pictureRect.y = pictureRect.y + HEIGHT_IMAGES;
                pictureRect.x = 0;
            } else{
                if(i > 0)
                    pictureRect.x = pictureRect.x + WIDTH_IMAGES;
            }
        }
    }

    bool working(){
        return running;
    }

    SDL_Rect getClickedRect(int x, int y){
        SDL_Rect clicked = {0, 0, WIDTH_IMAGES, HEIGHT_IMAGES};
        clicked.x = xNum(x)*WIDTH_IMAGES;
        clicked.y = yNum(y)*HEIGHT_IMAGES;
        return clicked;
    }


    int xNum(int x){
        return x / WIDTH_IMAGES;
    }
    int yNum(int y){
        return y / HEIGHT_IMAGES;
    }
    int getImage(int x, int y){
        return yNum(y)*6+xNum(x);

    }

    int getQuestionCounter(){
        //cout<<"Question OCunter "<< questionCounter <<endl;
        return questionCounter;
    }

    void evaluator(bool eval){
        clearRect(questionRect);
        if(eval)
            loadText("Yes!!!");
        else
            loadText("No!!!");
    }

    int xCenterText(string text){
        int size = text.size()*10;
        int x = SCREEN_WIDTH-size;
        return x/2;
    }

    void checkCharacter(int x, int y){
        //to be filled
    }

};


Handler::~Handler(){}
void Handler::init(const char * title, int xpos, int ypos, int width, int height){
    int flags = SDL_WINDOW_SHOWN;
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        cout<<"Working!!"<<endl;
        window = SDL_CreateWindow(title,xpos,ypos,width,height,flags);
        if(window){
            cout<<"Window had been created"<<endl;
        }
        renderer = SDL_CreateRenderer(window,-1,0 );
        if(renderer){
            SDL_SetRenderDrawColor(renderer,255,255,255,255);
            cout<<"Renderer has been created"<<endl;
        }
        //Initialize PNG and JPG loading
        int imgFlags = IMG_INIT_PNG;
        int initted = IMG_Init(imgFlags);
        if (!(initted & imgFlags)) {
            printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
            exit(2);
        }
        //initialize board coordinates
        questionRect.y = SCREEN_HEIGHT-70;
        questionRect.x = 0;
        questionRect.w = 640;
        questionRect.h = 50;

        //Initialize SDL_ttf
        if (TTF_Init() == -1) {
            printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
            exit(2);
        }
        questionFont =  TTF_OpenFont( "fonts/ELEPHNT.ttf", 100 );

        running = true;

    }
    SDL_RenderClear(renderer);

}



bool Handler::events() {
    bool check = false;

    const Uint8 *state = SDL_GetKeyboardState(NULL);
//    if (state[SDL_SCANCODE_RETURN]) {
//        printf("<RETURN> is pressed.\n");
//    }
//    if (state[SDL_SCANCODE_RIGHT] && state[SDL_SCANCODE_UP]) {
//        printf("Right and Up Keys Pressed.\n");
//    }

    SDL_Event e;
    SDL_PollEvent(&e);
    switch(e.type){
        case SDL_QUIT:
            running = false;
            break;
        case SDL_KEYDOWN:
            switch ( e.key.keysym.sym ){
                case SDLK_RIGHT:

                    questionCounter++;
                    if(questionCounter == QUESTION_NUMBER1){
                        questionCounter = 0;
                    }
                    nextQuestion();




                    SDL_Delay( 1000 );
                    break;
                case SDLK_LEFT:

                    questionCounter--;
                    if(questionCounter == -1){
                        questionCounter = QUESTION_NUMBER1-1;
                    }
                    prevQuestion();
                    SDL_Delay( 1000 );
//                    if( e.key.keysym.sym == SDLK_LEFT)
//                        //waste token
                        break;
                case SDLK_KP_ENTER:
                    check = true;
                    //whoKnows



                    break;
                default:
                    break;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:

            if( e.button.button == SDL_BUTTON_LEFT){
                int x, y;
                //SDL_GetMouseState(&x, &y);
                x = e.motion.x;
                y = e.motion.y;
                crossCharacter(x, y);
               // cout << x << ", " << y << endl;

            }
            else if (e.button.button == SDL_BUTTON_MIDDLE){
                int x,y;
                x = e.motion.x;
                y = e.motion.y;
                unCrossCharacter(x,y);
            } else if(e.button.button == SDL_BUTTON_RIGHT){
                int x,y;
                x = e.motion.x;
                y = e.motion.y;
                checkCharacter(x, y);
            }
            break;

    }
    return check;
}
void Handler::clear() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}





#endif //WHOISWHO_HANDLER_H
