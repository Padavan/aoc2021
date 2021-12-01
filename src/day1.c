#include <stdio.h>
#define MAX_LINE_LENGTH 80
#define FILE_LENGTH 2000

/* This is a comment. */
int main(int argc, char *argv[])
{
    char path[] = "../input/day1.txt";
    
    FILE *fp;
    fp = fopen(path, "r");
    // char line[64];
    char line[MAX_LINE_LENGTH] = {0};
    unsigned int line_count = 0;

    if (!fp)
    {
        perror(path);
        return 1;
    }

    int dataList[FILE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, fp))
    {
        // printf("int on line %d: %d \n", line_count++, atoi(line));
        dataList[line_count++] = atoi(line);
        
        /* Add a trailing newline to lines that don't already have one */
        if (line[strlen(line) - 1] != '\n')
            printf("\n");
    }


    // for (int line_number = 0; line_number < FILE_LENGTH; line_number++) {
    //     printf("d: %d \n", dataList[line_number]);
    // }

    

    printf("--Day 1--\n");
    part1(dataList);

    fclose(fp);
    free(line);


    return 0;
}

int part1(int list[]) {
    int increase_cases = 0;
    for (int line_number = 1; line_number < FILE_LENGTH; line_number++) {
        if (list[line_number] > list[line_number - 1]) {
            increase_cases++;
        }
    }
    printf("Part 1: %d \n", increase_cases);
    return 0;
}
