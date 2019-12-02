//Using SDL and standard IO
//#include <SDL2/SDL.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include <stdio.h>
#include <string>
#include "Board.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init(SDL_Window *window, SDL_Renderer *renderer) {
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    } else {
        //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            printf("Warning: Linear texture filtering not enabled!");
        }

        //Create window
        window = SDL_CreateWindow("Guess Who Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL) {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        } else {
            //Create vsynced renderer for window
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (renderer == NULL) {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            } else {
                //Initialize renderer color
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xC9, 0xFF, 0xFF);

                //Initialize PNG and JPG loading
                int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
                int initted = IMG_Init(imgFlags);
                if (!(initted & imgFlags)) {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }

                //Initialize SDL_ttf
                if (TTF_Init() == -1) {
                    printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}

void loadImage(string imagePath) {
    SDL_Surface *image;
    image = IMG_Load(imagePath.c_str());
    if(image == NULL){
        printf("Image loading of %s failed.\nError: %s\n", imagePath.c_str(), IMG_GetError());
    }


}

void close(SDL_Window *window, SDL_Renderer *renderer) {
    //Free loaded images
    //gTextTexture.free();

    //Free global font
//    TTF_CloseFont( gFont );
//    gFont = NULL;

    //Destroy window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    renderer = NULL;

    //Quit SDL subsystems
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

bool quitProgram(SDL_Event e) {
    if (e.type == SDL_QUIT) {
        return true;
    }
    return false;
}

int main(int argc, char *args[]) {
    Board *myBoard = new Board();

    myBoard->printBoard();
    cout << "done\n";


    //Initialize main variables
    SDL_Window *myWindow = NULL;
    SDL_Renderer *renderer = NULL;

    //Start up SDL and create window
    if (!init(myWindow, renderer)) {
        printf("Failed to initialize!\n");
    } else {
        bool quit = false;

        //event Handler
        SDL_Event e;

        while (!quit) {
            while (SDL_PollEvent(&e) != 0) {
                //quit program hitting X
                quit = quitProgram(e);
            }

            SDL_SetRenderDrawColor(renderer, 0xFF, 0xC9, 0xFF, 0xFF);
            SDL_RenderClear( renderer );

            //Update screen
            SDL_RenderPresent(renderer);
        }
    }


    //Free resources and close SDL
    close(myWindow, renderer);
    return 0;
}
