//Github link here: https://gist.github.com/MarcusKiwi/d264180cf78b257af40090d833afe949 -Nik

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <SDL2\SDL.h>

// type for points
typedef struct {
    int x;
    int y;
} pt;

// used for sorting
int compare(const void* a, const void* b) {
    double aa = *(double*)a;
    double bb = *(double*)b;
    if(aa > bb) return 1;
    if(aa < bb) return -1;
    return 0;
}

int main(int args, char *argv[]) {

    // argument format:
    // circles.exe GRID_SIZE NUMBER_POINTS SELECT_PERCENT DISPLAY_SCALE

    printf("Calculating");

    int size = 300;
    int points = 100;
    float percent = 0.5;
    int scale = 3;

    // take arguments
    if(args>0) sscanf(argv[1], "%i", &size);
    if(args>1) sscanf(argv[2], "%i", &points);
    if(args>2) sscanf(argv[3], "%f", &percent);
    if(args>3) sscanf(argv[4], "%i", &scale);

    /**************************/
    /* GENERATE RANDOM POINTS */
    /**************************/

    pt point[points];
    srand(time(NULL));
    {
        int grid[size][size]; // stack overflow with large values
        for(int x=0; x<size; x++) {
            for(int y=0; y<size; y++) {
                grid[x][y] = 0;
            }
        }
        int x, y;
        for(int i=0; i<points; i++) {
            // find random unique point
            do {
                x = rand() % size;
                y = rand() % size;
            } while(grid[x][y] == 1);
            // record point
            grid[x][y] = 1;
            point[i].x = x;
            point[i].y = y;
        }
    }

    /***************/
    /* FIND CIRCLE */
    /***************/

    double rad; // radius
    pt cen; // center of circle

    for(cen.y=0; cen.y<size; cen.y++) {
        for(cen.x=0; cen.x<size; cen.x++) {

            // will a circle with this center work?
            double hypo[points];

            // calculate hypotenuse for each point
            for(int i=0; i<points; i++) {
                hypo[i] = sqrt(
                    pow(abs(point[i].x - cen.x), 2) + 
                    pow(abs(point[i].y - cen.y), 2)
                );
            }

            // sort hypotenuse
            qsort(hypo, points, sizeof(double), compare);

            // find rad of circle
            if(points%2==1) {
                rad = hypo[(int)(points * percent)];
            } else {
                rad = (hypo[(int)(points * percent)] + hypo[(int)(points * percent) - 1]) / 2;
            }

            // see if circle fits
            if((cen.x-rad>0 && rad+cen.x<size) && (cen.y-rad>0 && rad+cen.y<size) ) {
                // circle fits
                break;
            } else {
                // circle does not fit
                rad = -1;
            }
        }

        if(rad>0) {
            break;
        }
    }

    printf(" Finished!\n");

    /************/
    /* INIT SDL */
    /************/

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* w = SDL_CreateWindow(
        "Points and Circles Exercise",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        size * scale,
        size * scale,
        SDL_WINDOW_SHOWN
    );
    SDL_Renderer* r = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event ev;
    SDL_SetRenderDrawColor(r, 0, 0, 0, 255);
    SDL_RenderClear(r);
    SDL_RenderPresent(r);

    /***************/
    /* DRAW CIRCLE */
    /***************/

    if(rad>0) {
        // draw circle (midpoint circle algo)
        SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
        pt off = {cen.x* scale, cen.y* scale};
        double e = rad * scale * -1;
        double x = rad * scale;
        int y = 0;
        while(y<=x) {
            // top left
            SDL_RenderDrawPoint(r, off.x - x, off.y - y);
            SDL_RenderDrawPoint(r, off.x - y, off.y - x);
            // top right
            SDL_RenderDrawPoint(r, off.x + x, off.y - y);
            SDL_RenderDrawPoint(r, off.x + y, off.y - x);
            // bottom left
            SDL_RenderDrawPoint(r, off.x - x, off.y + y);
            SDL_RenderDrawPoint(r, off.x - y, off.y + x);
            // bottom right
            SDL_RenderDrawPoint(r, off.x + x, off.y + y);
            SDL_RenderDrawPoint(r, off.x + y, off.y + x);
            // calculate next coordinate
            e = e + 2 * y + 1;
            y++;
            if(e>=0) {
                e = e - 2 * x - 1;
                x--;
            }
        }
    }

    /***************/
    /* DRAW POINTS */
    /***************/
    
    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    for(int i=0; i<points; i++) {
        for(int x=0; x<scale; x++) {
            for(int y=0; y<scale; y++) {
                SDL_RenderDrawPoint(r, point[i].x * scale + x, point[i].y * scale + y);
            }
        }
    }

    /***********/
    /* DISPLAY */
    /***********/

    // set window title
    char title[250];
    if(rad>0) {
        snprintf(title, 200, "G=%i D=%i P=%0.2f - X=%i Y=%i R=%.3f", size, points, percent, cen.x, cen.y, rad);
    } else {
        snprintf(title, 200, "G=%i D=%i P=%0.2f - Circle Not Found", size, points, percent);
    }
    SDL_SetWindowTitle(w, title);

    // show window
    SDL_RenderPresent(r);
    while(1) {
        while(SDL_PollEvent(&ev)!=0) {
            if(ev.type==SDL_QUIT) {
                return 0;
            }
        }
        SDL_Delay(16);
    }
    return 0;
}