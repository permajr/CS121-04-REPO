#include <SDL3/SDL.h>
#include <iostream>
#include <vector>


//initialize body
int main(int argc, char* argv[]) 
{
    SDL_Init(SDL_INIT_VIDEO);//start draw??

    SDL_Window* window = SDL_CreateWindow("Sphinx's Gambit", 800, 600, 0); // creates a window with title, size, any other flags
    if (window == nullptr) //if the window cant render for some reason, exit with status 1 instead of 0 which means something is wrong
    {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }//code for creating the error message

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL); // start renderer (which i guess makes things show up)
    if (renderer == nullptr) // if the renderer cant render for some reason, exit with status 1 instead of 0
    {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }//code for creating error message

    //initialize an event listener(?) and set up a boolean condition for a while loop
    SDL_Event e;
    bool quit = false;


    //render the window & thing inside window while event listener is false
    while (!quit) 
    {
        //move the event que and if it ever reads as a quit even, destroy the renderer and window
        while (SDL_PollEvent(&e)) 
        {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;// if the event flow detects the quit event, destroy
            }
        }


        //set a number of vertices
        #define vertLen 3
        SDL_Vertex vert[vertLen];

        // center
        vert[0].position.x = 150;
        vert[0].position.y = 100;
        vert[0].color.r = 1.0;
        vert[0].color.g = 0.0;
        vert[0].color.b = 0.0;
        vert[0].color.a = 1.0;

        // left
        vert[1].position.x = 0;
        vert[1].position.y = 400;
        vert[1].color.r = 0.0;
        vert[1].color.g = 0.0;
        vert[1].color.b = 1.0;
        vert[1].color.a = 1.0;

        // right
        vert[2].position.x = 300;
        vert[2].position.y = 400;
        vert[2].color.r = 0.0;
        vert[2].color.g = 1.0;
        vert[2].color.b = 0.0;
        vert[2].color.a = 1.0;
        
        //looks like the same thing as above? listen for quit event, etc, except now we start drawing stuff
        while (!quit) {
            SDL_Event ev;
            while (SDL_PollEvent(&ev) != 0) {
                switch (ev.type) {
                case SDL_EVENT_QUIT:
                    quit = true;
                    break;
                }
            }

            //render the background as black (R,G,B,A)?
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            //kill any rander action
            SDL_RenderClear(renderer);

            /*render geometry using the renderer, no texture, using SDL_Vertex for the information of those vertexs and the number defined in[VertLen]
            * no array of indices into the 'vertices' array, and no indices
            */
            SDL_RenderGeometry(renderer, NULL, vert, vertLen, NULL, 0);
            SDL_Rect fllRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };

            SDL_RenderFillRect(renderer, &fillRect);


            //show your work to the class (and the screen)
            SDL_RenderPresent(renderer);
        }
        
    }

    //pretty self-explanatory
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}