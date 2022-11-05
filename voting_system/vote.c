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

void fillCandidate(int cNum)
{
    printf("Symbols:\n");
    for (int j = 0; j < 10; j++) {
        if (symbolTaken[j] == 1) continue;
        printf("%d %c\n", j + 1, symbols[j]);
    }

    int num;
    printf("Choose symbol for candidate %d: ", cNum + 1);
    scanf("%d", &num);

    if (num <= 0 || num > 10 || symbolTaken[num - 1] == 1) {
        printf("Not available, pick again\n");
        fillCandidate(cNum);
    } else {
        symbolTaken[num - 1] = 1;
        allCandidates[cNum].symbol = symbols[num - 1];
        printf("Enter name of candidate %d: ", cNum + 1);
        scanf("%s", allCandidates[cNum].name);
        allCandidates[cNum].votes = 0;
    }
}

void displayAllCandidates()
{
    for (int j = 0; j < candidateCount; j++) {
        printf("%s\t", allCandidates[j].name);
    }
    printf("\n");
    for (int j = 0; j < candidateCount; j++) {
        printf("%c\t\t", allCandidates[j].symbol);
    }
    printf("\n");
}

