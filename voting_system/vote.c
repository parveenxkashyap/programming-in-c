#include <stdio.h>
#include <string.h>

#define MAX_C 11

typedef struct Candidate {
    char name[50];
    int votes;
    char symbol;
} Candidate;

Candidate allCandidates[MAX_C];
int candidateCount = 0;
char symbols[10] = { '!', '@', '#', '$', '%', '^', '&', '*', '~', '+' };
int symbolTaken[11];
