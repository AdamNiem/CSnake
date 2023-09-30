#include <stdio.h>
#include <curses.h> //Allows for keyboard inputs detection

//This lets us use the sleep function for unix or windows
//https://stackoverflow.com/questions/14818084/what-is-the-proper-include-for-the-function-sleep
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#include <stdlib.h>
#endif

/*
    General layout
    main loop function 

    draw function
    logic function

    world stored as an array

*/
struct Player 
{
    int x;
    int y;
    int len;
    int body[1000];
    //could have an array of structs or multi dimensional array
};

struct SnakeBody 
{
    int x;
    int y;
};

////Variable definitions
    int gameEnd = 0;
    //define some beginning properties to the player
    struct Player player = {
        .x = 5,
        .y = 5,
        .len = 1,
    };

    //This is a little grid of the world, 0 represents empty air tiles while 1 represents solid tiles
    //Also, the world has to be rectangular so that each dimension has the same length arrays
    int world[10][10] = { 
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //1
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //2
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //3
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //4
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //5 
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //6
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //7
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //8
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, //9
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //10
    };
///

//right now the last length of the array needs to be passed to the draw function for it to work
//should try to fix this later on
void draw(int world[10][10], struct Player player)
{
    //define looping variables
    int j;
    int i;

    //store a copy of the world so that we can modify to add the snake and apple to it
    int worldCopy[10][10];

    for(i = 0; i < 10; i++) 
    {
        for(j = 0; j < 10; j++) 
        {
            worldCopy[i][j] = world[i][j];
        }
    }

    //Now edit the World Copy to include the player
    worldCopy[player.y][player.x] = 8;
    //

    //clear terminal before printing
    system("clear");

    //simple printf statements to draw the world Copy with the player to screen
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            printf("%d", worldCopy[i][j]);
        }
        printf("\n"); //adds a new line so that each row is on a separate line
    }
} 

//This is to get keyboard input to move the player
void input()
{

}

//Giving up for now in passing reference of player struct, instead just grabs the variable player thats in the script
void logic()
{
        //update frame speed
        //https://stackoverflow.com/questions/55483994/having-problems-with-the-sleep-function-inside-a-loop-in-c
        fflush(stdout); //this clears the stdout buffer so that printf can show up immediately after sleep 
        sleep(1);

        //move player
        player.y += 1;
        
}

int main()
{
    //Game loop
    while(!gameEnd){
        
        logic();
        draw(world, player);

        if(3 == 2)
        {
            gameEnd = 1;
        }
    }

        // init curses:
    initscr();

    // in curses, you have to use curses functions for all terminal I/O
    addstr("How are you?");

    int k = getch();

    // end curses:
    endwin();

    printf("hello cruel world");
    return 0;
}