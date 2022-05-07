#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 33 // 2 * n - 1 n = 6
#define COLS 33 // 2 * n - 1 n = 5


typedef struct {
    int y;
    int x;
    int value;
} block;

block maze[ROWS][COLS];

block path[ROWS * COLS / 3];
int path_index = 0;

block neighbors[4];
int has_neighbors = 0;
int neighbor_index = 0;

void print_maze_as_is(block*);
void print_maze(block*);
block get_neighbors(block current);

int main() {
    for(int j=0; j<ROWS; j++) {
        for(int i=0; i<COLS; i++) {
            maze[j][i].y = j;
            maze[j][i].x = i;
            maze[j][i].value = 0;
        }
    }

    block current, next;

    path[path_index] = maze[0][0];
    ++path_index;

    while(path_index > 0) {
        current = path[path_index - 1];
        maze[current.y][current.x].value = 1;
        next = get_neighbors(current);

        if(has_neighbors == 0) {
            --path_index;
        } else {
            path[path_index] = next;
            path_index++;
        }
    // printf("Current: [%d, %d]\n", current.y, current.x);
    // printf("No of neighbors: %d\n", neighbor_index);
    // print_maze_as_is(maze[0]);
    // getchar();
    }
    print_maze_as_is(maze[0]);
    print_maze(maze[0]); // TODO make better maze rendering function;
    return 0;
}

void print_maze_as_is(block* start) {
    for(int j=0; j<ROWS; j++) {
        for(int i=0; i<COLS; i++) {
            printf("%d ", start->value);
            ++start;
        }
        printf("\n");
        
    }
}

void print_maze(block* start) {
    for(int t=0; t<=COLS; t++) printf("___");
    printf("\n");
    for(int j=0; j<ROWS; j++) {
        printf(" | ");
        for(int i=0; i<COLS; i++) {
            if(start->value == 1) {
                printf("   ");
            } else {
                printf(" | ");
            }
            ++start;
        }
        printf(" | ");
        printf("\n");
        
    }
    for(int t=0; t<=COLS; t++) printf("---");
}




block get_neighbors(block current) {
    neighbor_index = 0;
    has_neighbors = 0;
    block next = current;
    int dy = 0, dx = 0;
    srand(time(0) * path_index * rand());
    //srand(rand());

    if(current.y != 0 && maze[current.y - 2][current.x].value != 1) {
        neighbors[neighbor_index] = maze[current.y - 2][current.x];
        ++neighbor_index;
    }

    if(current.y != ROWS-1 && maze[current.y + 2][current.x].value != 1) {
        neighbors[neighbor_index] = maze[current.y + 2][current.x];
        ++neighbor_index;
    }

    if(current.x != 0 && maze[current.y][current.x - 2].value != 1) {
        neighbors[neighbor_index] = maze[current.y][current.x - 2];
        ++neighbor_index;
    }

    if(current.x != COLS-1 && maze[current.y][current.x + 2].value != 1) {
        neighbors[neighbor_index] = maze[current.y][current.x + 2];
        ++neighbor_index;
    }

    if(neighbor_index == 0) {
        return next;
    } else {
        int index = rand() % neighbor_index;
        // printf("index: %d\n", index);
        has_neighbors = 1;
        next = neighbors[index];
        if(current.x == next.x) {
            maze[current.y / 2 + next.y / 2][current.x].value = 1;
        } else {
            maze[current.y][current.x / 2 + next.x / 2].value = 1;  
        }
        // printf("next: [%d, %d]\n", next.y, next.x);
    }
    return next;
}