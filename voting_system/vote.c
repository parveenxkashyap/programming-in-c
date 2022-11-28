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

void getVotes(int voterCount)
{
    displayAllCandidates();
    printf("Voter %d, pick (1-%d): ", voterCount + 1, candidateCount);
    int choice;
    scanf("%d", &choice);

    if (choice >= 1 && choice <= candidateCount) {
        allCandidates[choice - 1].votes++;
    } else {
        printf("Invalid! vote again\n");
        getVotes(voterCount);
    }
}

int main()
{
    for (int i = 0; i < 11; i++) symbolTaken[i] = 0;

    printf("Enter number of candidates: ");
    scanf("%d", &candidateCount);
    if (candidateCount >= MAX_C) {
        printf("Too many candidates, bye\n");
        return 0;
    }

    for (int i = 0; i < candidateCount; i++) fillCandidate(i);

    int numVoters;
    printf("Enter number of voters: ");
    scanf("%d", &numVoters);

    for (int i = 0; i < numVoters; i++) getVotes(i);

    return 0;
}

void getResults()
{
    int maxVotes = 0;
    int winnerIndex = -1;
    int winnerFrequency = 0;

    for (int i = 0; i < candidateCount; i++) {
        if (allCandidates[i].votes > maxVotes) {
            maxVotes = allCandidates[i].votes;
            winnerIndex = i;
        }
    }

    for (int i = 0; i < candidateCount; i++) {
        if (allCandidates[i].votes == maxVotes) winnerFrequency++;
    }

    printf("\nRESULTS\n");

    if (winnerFrequency > 1) printf("No clear winner\n");
    else if (winnerIndex != -1)
        printf("Winner: %s (%c) with %d votes\n",
               allCandidates[winnerIndex].name,
               allCandidates[winnerIndex].symbol,
               maxVotes);
    else printf("No winner\n");
}

// call getResults at end of main
int main()
{
    for (int i = 0; i < 11; i++) symbolTaken[i] = 0;

    printf("Enter number of candidates: ");
    scanf("%d", &candidateCount);
    if (candidateCount >= MAX_C) {
        printf("Too many candidates, bye\n");
        return 0;
    }

    for (int i = 0; i < candidateCount; i++) fillCandidate(i);

    int numVoters;
    printf("Enter number of voters: ");
    scanf("%d", &numVoters);

    for (int i = 0; i < numVoters; i++) getVotes(i);

    getResults();

    return 0;
}
