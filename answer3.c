#include <stdlib.h>
#include <stdio.h>

void paintRoom( char** room, int numrows, int numcols );
void recPaintRoom( char** room, int numrows, int numcols, int x, int y, int distance);

void paintRoom(char** room, int numrows, int numcols) {
    recPaintRoom(room, numrows, numcols, 1, 1, 'A');
}

void recPaintRoom(char** room, int numrows, int numcols, int x, int y, int distance) {
    //Base case: 
    if(room[x][y] == '*')
        return;
    if(room[x][y] != ' ' && room[x][y] < distance)
        return;
    
    if(distance > 'Z')
        room[x][y] = 'Z';
    else
        room[x][y] = distance;

    //Recursive case:
    recPaintRoom(room, numrows, numcols, x, y - 1, distance + 1);
    recPaintRoom(room, numrows, numcols, x, y + 1, distance + 1);
    recPaintRoom(room, numrows, numcols, x + 1, y, distance + 1);
    recPaintRoom(room, numrows, numcols, x - 1, y, distance + 1);
}