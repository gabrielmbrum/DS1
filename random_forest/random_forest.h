#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define N 137 //number of trees on the forest
#define P 5 //number of parameters to create a MEME 
#define M 45 // number of memes
#define T 10 //memes quantify to test
#define log2 0.301

//----------- STRUCTS -------------//
//Define the structure for a node in the decision tree
typedef struct Node {
    int isLeaf;
    int decision;
    char *question;
    struct Node *yesBranch;
    struct Node *noBranch;
} Node;

//Define the structu for a meme
typedef struct meme {
    int id;
    bool hasText;
    bool imageQuality;
    bool goofySound;
    bool BJVRiram;
    bool poggers; //famous word with a lot of meanings, in this case is used to decide if 'Allan Riu' or 'Allan Não Riu'
} Meme;

//Define the struct of a 'information gain', which has the gain and the question
//The question is used into the randomly construction of the doupts tree's nodes
typedef struct ig {
    char *question; 
    double gain;
} ig;


//---------- CREATERS ------------//
//Function to create a new decision tree node
Node* createNode(char *question, int isLeaf, int decision);

//Function to create a new meme
Meme createMeme (bool hasNext, bool imageQuality, bool goofySound, bool BJVRiram, bool poggers);

//creates the original dataset
Meme *originalMemesDataset ();

//Returns a bootstrapped datased based on the original one
Meme* bootstrapped_dataset (Meme *original);

Node *buildRandomTree(Meme* dataset);

//--------- RANDOMICS --------//

//Generate a randomic number
int randomicInt(int min, int max);

//Generate a randomic """index""" of parameter
int randomicPar();

//Generate an array of randoms boolens
bool* randomBools ();

//------- "DECIDERS" -----------//

//Function that compares two strings
bool isEqual (char *string1, char *string2);

//Function to travel through the decision tree and make a decision
bool makeDecision(Meme meme, Node* node);

//Returns the moda of the array 
int moda (bool *arr);

//---------- CALCULATORS ---------------//

// Entropy(S) = -(p-)log2(p+) - (p-)log2(p-)
//Calculates the entropy of a columns
double entropy (int pMais, int pMenos);

//Gain(S, <parameter>) = Entropy(S) - (sum)possibleValuesEntropy
double IG (double entropyS, double trueEntropy, double falseEntropy);

//Geral Entropy Function
double geralEntropyF (Meme *memes);

//Calculate 'hasText' information gain
double hasTextIG (Meme *memes);

//Calculate 'imgQuality' information gain
double imgQualityIG (Meme *memes);

//Calculate 'goofySound' information gain
double goofySoundIG (Meme *memes);

//Calculate 'BJVMLaugh' information gain
double BJMLaughIG (Meme *memes);

//---------- PRINTERS -------------//

//Print characteristics of a meme
void printMeme (Meme meme);