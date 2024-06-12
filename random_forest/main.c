#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "random_forest.h"

int main() {
    int result;
    bool decisions[M][N];
    bool *randoms;
    Meme *memes;

    srand(time(NULL));

    //Create a initial dataset of memes with the results
    memes = originalMemesDataset();
    
    Meme* memesToCreateTrees = malloc(sizeof(Meme) * (M-T));
    for (int i = 0; i < (M-T); i++) {
        memesToCreateTrees[i] = memes[i];
    } 

    //Creates and implement the forest with random decisions trees
    Node* forest[N];
    for (int i = 0; i < N; i++) {
        forest[i] = buildRandomTree(bootstrapped_dataset(memesToCreateTrees));
    }

    //Pass each meme through the forest (minus the testing decisions trees) and 'train' the random forest
    //OBS.: the 'poggers' atributte it's not used to make the decision
    for (int i = 0; i<M-T; i++) {
        for (int j = 0; j<N; j++) {
            decisions[i][j] = makeDecision(memes[i], forest[j]);
        }
    }

    //Testing the random forest
    int correct=0, wrong=0;
    printf("testing...\n\n");
    for (int i = 0; i < T; i++) {
        printf("meme #%d\n", memes[M-T+i].id);
        printf("\tresult from forest: "); 
        result = moda(decisions[M-T+i]);
        switch (result) {
            case -1: printf("not poggers\n"); break;
            case 0: printf("poggers and bad!! LOL it's a draw\n"); break; //if M it's not pair, doesn't happen
            case 1: printf("poggers\n"); break;
        } 
        printf("\tresult expected: %s\n", memes[M-T+i].poggers ? "poggers" : "not poggers");  
        if ( (result == 1 && memes[M-T+i].poggers) || (result == -1 && !memes[M-T+i].poggers) ) correct++;
        else wrong++;
    } 
    printf("\ntest finished!\n\n"
                    "accuracy: %f%%\n", ((double)correct/(double)T)*100);

    // Free the allocated memory
    for (int i=0; i<N; i++)
        free(forest[i]);
    free(memes);

    return 0;
}