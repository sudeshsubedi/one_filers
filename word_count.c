#include <stdio.h>

#define IN 1
#define OUT 0

int main(int argc, char** argv) {
    int nc = 0, nw = 0, nl = 1, state;
    int c;
    if(argc != 2){
        printf("Usage: word_count file\n");
        return 64;
    }

    FILE* f;

    if((f = fopen(argv[1], "r")) == NULL) {
        printf("Error: file does not exist.\n");
        return 1;
    }

    while ((c = fgetc(f)) != EOF)
    {
        ++nc;
        if(c == '\n') ++nl;

        if(c == ' ' || c == '\t' || c == '\n'){
            state = OUT;
        } else if(state == OUT){
            ++nw;
            state = IN;
        }
    }

    printf("%s file summary\n", argv[1]);
    printf("No of characters: %d\n", nc);
    printf("No of words: %d\n", nw);
    printf("No of lines: %d\n", nl);
}