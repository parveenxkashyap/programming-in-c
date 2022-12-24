#include <stdio.h>
#include <string.h>
// headers

#define MAX_C 11
// max candidates

typedef struct Candidate {
    char name[50];
    int votes;
    char symbol;
} Candidate;

Candidate allCandidates[MAX_C];

int candidateCount = 0;
// possible symbols
char symbols[10] = { '!', '@', '#', '$', '%', '^', '&', '*', '~', '+' };
// track which symbol used
int symbolTaken[11];

// function stuff
void fillCandidate(int);
void displayAllCandidates();
void getVotes(int);
void getResults();

int main()
{
    // init symbolTaken
    for (int i = 0; i < 11; i++) {
        symbolTaken[i] = 0;
    }

    // get number of candidates
    printf("Enter the number of candidates: ");
    scanf("%d", &candidateCount);
    if (candidateCount >= MAX_C) {
        printf("Too many candidates, bye\n");
        return 0;
    }

    // fill candidate info
    for (int i = 0; i < candidateCount; i++) {
        fillCandidate(i);
    }

    // how many voters
    int numVoters;
    printf("Enter number of voters: ");
    scanf("%d", &numVoters);

    // get votes
    for (int i = 0; i < numVoters; i++) {
        getVotes(i);
    }

    // show results
    getResults();

    return 0;
}

// add candidate info
void fillCandidate(int cNum)
{
    printf("Symbols:\n");
    for (int j = 0; j < 10; j++) {
        if (symbolTaken[j] == 1)
            continue;
        printf("%d %c\n", j + 1, symbols[j]);
    }

    int num = 0;
    printf("Choose symbol for candidate %d: ", cNum + 1);
    scanf("%d", &num);

    if (num <= 0 || num > 10 || symbolTaken[num - 1] == 1) {
        printf("Not available, pick again\n");
        fillCandidate(cNum);
    } else {
        symbolTaken[num - 1] = 1;
        allCandidates[cNum].symbol = symbols[num - 1];
        printf("Name of candidate %d: ", cNum + 1);
        scanf("%s", allCandidates[cNum].name);
        allCandidates[cNum].votes = 0;
    }
}

// show all candidates
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

// voting
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

// results
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
        if (allCandidates[i].votes == maxVotes) {
            winnerFrequency++;
        }
    }

    printf("\nRESULTS\n");

    if (winnerFrequency > 1) {
        printf("No clear winner\n");
    } else if (winnerIndex != -1) {
        printf("Winner: %s (%c) with %d votes\n",
               allCandidates[winnerIndex].name,
               allCandidates[winnerIndex].symbol, maxVotes);
    } else {
        printf("No winner\n");
    }
}
