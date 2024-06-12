#include "random_forest.h"

char* Q_HAS_TXT = "Does the meme have text?";
char* Q_QUALITY_IMG = "Is the image quality poggers?";
char* Q_GOOFY = "Is there a goofy sound?";
char* Q_BJV_LAUGH =  "Did BJV laugh?";

//Generate a randomic number
int randomicInt(int min, int max) {
    return (rand() % max - min + 1) + min;
}

//Function to create a new decision tree node
Node* createNode(char *question, int isLeaf, int decision) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->question = question;
    newNode->isLeaf = isLeaf;
    newNode->decision = decision;
    newNode->yesBranch = NULL;
    newNode->noBranch = NULL;

    return newNode;
}

//Function to create a new meme
int id = 0;
Meme createMeme (bool hasNext, bool imageQuality, bool goofySound, bool BJVRiram, bool poggers) {
    Meme newMeme;

    newMeme.id = (++id);
    newMeme.hasText = hasNext;
    newMeme.imageQuality = imageQuality;
    newMeme.goofySound = goofySound;
    newMeme.BJVRiram = BJVRiram;
    newMeme.poggers = poggers;

    return newMeme;
}

int randomicPar() {
    return (rand() % P-1);
}

Node *buildRandomTree(Meme* dataset) {
    int param1, param2;
    ig p1IG, p2IG; //information gain of each parameters
    bool p1bigger;
    char* firtQ;
    char* secondQ;

    //choose two random parameters
    param1 = randomicPar();
    param2 = randomicPar(); //it's P-2 because 'id' and 'poggers' will not count in this case

    //avoid param2 being equal to param1
    while (param2 == param1)
        param2 = randomicPar();

    //collect the information gain and the question of the respective column randomic selected
    switch (param1) {
        case 0: 
            p1IG.gain = hasTextIG(dataset);
            p1IG.question = Q_HAS_TXT;
            break; 
        case 1: 
            p1IG.gain = imgQualityIG(dataset);
            p1IG.question = Q_QUALITY_IMG;
            break;
        case 2: 
            p1IG.gain = goofySoundIG(dataset);
            p1IG.question = Q_GOOFY;
            break;
        default: 
            p1IG.gain = BJMLaughIG(dataset);
            p1IG.question = Q_BJV_LAUGH;
            break;
    }

    switch (param2) {
        case 0: 
            p2IG.gain = hasTextIG(dataset);
            p2IG.question = Q_HAS_TXT;
            break; 
        case 1: 
            p2IG.gain = imgQualityIG(dataset);
            p2IG.question = Q_QUALITY_IMG;
            break;
        case 2: 
            p2IG.gain = goofySoundIG(dataset);
            p2IG.question = Q_GOOFY;
            break;
        default: 
            p2IG.gain = BJMLaughIG(dataset);
            p2IG.question = Q_BJV_LAUGH;
            break;
    }

    //if p1 has a better gain the p2, p1bigger is true
    if (p1IG.gain >= p2IG.gain) p1bigger = true;
    else p1bigger = false;

    //set the first and second question based on the p1bigger
    if (p1bigger) {
        firtQ = p1IG.question;
        secondQ = p2IG.question;
    } else {
        firtQ = p2IG.question;
        secondQ = p1IG.question;
    }

    Node* root = createNode(firtQ, 0, -1);

    //randomizing the proccess to choose a struct to the tree
    if (randomicInt(0, 1) == 1) {
        //next question in 'yes'
        root->noBranch = createNode(NULL, 1, 0);
        root->yesBranch = createNode(secondQ, 0, -1);
        root->yesBranch->yesBranch = createNode(NULL, 1, 1);
        root->yesBranch->noBranch = createNode(NULL, 1, 0);
    } else {
        //next question in 'no'
        root->yesBranch = createNode(NULL, 1, 1);
        root->noBranch = createNode(secondQ, 0, -1);
        root->noBranch->yesBranch = createNode(NULL, 0, 1);
        root->noBranch->noBranch = createNode(NULL, 1, 0);
    }
    //OBS.: we basically use two 'kinds' of decisions tree, one with the second question after the 'yes', the other one is after the 'no' 

    return root;
}

bool isEqual (char *string1, char *string2) {
    return strcmp(string1, string2) == 0 ? true : false;
}

bool makeDecision(Meme meme, Node* node) {
    if (node->isLeaf) {
        return node->decision;
    }

    if (node->question != NULL) {
        if (isEqual(node->question, Q_HAS_TXT)) {
            return meme.hasText ? makeDecision(meme, node->yesBranch)
                           : makeDecision(meme, node->noBranch);

        } else if (isEqual(node->question, Q_QUALITY_IMG)) {
            return meme.imageQuality ? makeDecision(meme, node->yesBranch)
                               : makeDecision(meme, node->noBranch);

        } else if (isEqual(node->question, Q_GOOFY)) {
            return meme.goofySound ? makeDecision(meme, node->yesBranch)
                              : makeDecision(meme, node->noBranch);

        } else if (isEqual(node->question, Q_BJV_LAUGH)) {
            return meme.BJVRiram ? makeDecision(meme, node->yesBranch)
                            : makeDecision(meme, node->noBranch);
        }
    }
    
    return 0; // Default decision
}

int moda (bool *arr) {
    int trues=0, falses=0;
    for (int i = 0; i<N; i++) {
        if (arr[i]) trues++;
        else falses++;
    }

    if (trues == falses)
        return 0;
    if (trues > falses)
        return 1;
    else 
        return -1;
}

bool* randomBools () {
    int ran;
    bool *arr = malloc(sizeof(bool) * P);
    for (int i = 0; i < P; i++) {
        ran = rand() % 2;
        arr[i] = (ran != 0);
    }

    return arr;
} 

Meme* bootstrapped_dataset (Meme *original) {
    Meme *bootstrapped = malloc(sizeof(Meme) * M);
    for (int i = 0; i<M; i++) {
        int random = randomicInt(0, M-1);
        //printf("random: %d\n", random);
        bootstrapped[i] = original[random];
    }
    return bootstrapped;
}

void printMeme (Meme meme) {
    printf("\nmeme #%d\n", meme.id);
    printf("\thas next: %d\n", meme.hasText);
    printf("\timage quality: %d\n", meme.imageQuality);
    printf("\tgoofy sound: %d\n", meme.goofySound);
    printf("\tfriends laugh: %d\n", meme.BJVRiram);
    printf("\tpoggers: %d\n", meme.poggers);
}

double entropy(int pMais, int pMenos) {
    return  (-(pMenos)*log2*(pMais) - (pMenos)*log2*(pMenos));
}

double IG (double entropyS, double trueEntropy, double falseEntropy) {
    double sum = 0;

    return (entropyS - (trueEntropy + falseEntropy));
}

double geralEntropyF (Meme *memes) {
    int positives = 0, negatives = 0;
    for (int i = 0; i < M; i++) {
        if (memes[i].poggers) {
            positives++;
        } else negatives++;
    }
    return entropy(positives, negatives);
}

double hasTextIG (Meme *memes) {
    double geralEntropy, trueEntropy, falseEntropy;
    int positives = 0, negatives = 0;

    for (int i = 0; i < M; i++) {
        if (memes[i].hasText) {
            if (memes[i].poggers) positives++;
            else negatives--;
        }
    }
    trueEntropy = entropy(positives, negatives);
    positives = 0; negatives = 0;

    for (int i = 0; i < M; i++) {
        if (memes[i].hasText == false) {
            if (memes[i].poggers) positives++;
            else negatives--;
        }
    }
    falseEntropy = entropy(positives, negatives);

    return (IG(geralEntropyF(memes), trueEntropy, falseEntropy));
}

double imgQualityIG (Meme *memes) {
    double geralEntropy, trueEntropy, falseEntropy;
    int positives = 0, negatives = 0;

    for (int i = 0; i < M; i++) {
        if (memes[i].imageQuality) {
            if (memes[i].poggers) positives++;
            else negatives--;
        }
    }
    trueEntropy = entropy(positives, negatives);
    positives = 0; negatives = 0;

    for (int i = 0; i < M; i++) {
        if (memes[i].imageQuality == false) {
            if (memes[i].poggers) positives++;
            else negatives--;
        }
    }
    falseEntropy = entropy(positives, negatives);

    return (IG(geralEntropyF(memes), trueEntropy, falseEntropy));
}

double goofySoundIG (Meme *memes) {
    double geralEntropy, trueEntropy, falseEntropy;
    int positives = 0, negatives = 0;

    for (int i = 0; i < M; i++) {
        if (memes[i].goofySound) {
            if (memes[i].poggers) positives++;
            else negatives--;
        }
    }
    trueEntropy = entropy(positives, negatives);
    positives = 0; negatives = 0;

    for (int i = 0; i < M; i++) {
        if (memes[i].goofySound == false) {
            if (memes[i].poggers) positives++;
            else negatives--;
        }
    }
    falseEntropy = entropy(positives, negatives);

    return (IG(geralEntropyF(memes), trueEntropy, falseEntropy));
}

double BJMLaughIG (Meme *memes) {
    double geralEntropy, trueEntropy, falseEntropy;
    int positives = 0, negatives = 0;

    for (int i = 0; i < M; i++) {
        if (memes[i].BJVRiram) {
            if (memes[i].poggers) positives++;
            else negatives--;
        }
    }
    trueEntropy = entropy(positives, negatives);
    positives = 0; negatives = 0;

    for (int i = 0; i < M; i++) {
        if (memes[i].BJVRiram == false) {
            if (memes[i].poggers) positives++;
            else negatives--;
        }
    }
    falseEntropy = entropy(positives, negatives);

    return (IG(geralEntropyF(memes), trueEntropy, falseEntropy));
}

Meme *originalMemesDataset () {
    Meme *memes = malloc(sizeof(Meme) * M);

    memes[0] = createMeme(true, true, false, true, false);
    memes[1] = createMeme(false, false, false, false, false);
    memes[2] = createMeme(false, true, false, true, false);
    memes[3] = createMeme(false, true, false, false, false);
    memes[4] = createMeme(true, true, false, false, true);
    memes[5] = createMeme(false, true, false, true, true);
    memes[6] = createMeme(false, false, false, true, true); 
    memes[7] = createMeme(true, false, false, true, true); 
    memes[8] = createMeme(true, false, true, true, true); 
    memes[9] = createMeme(false, true, true, true, true);
    memes[10] = createMeme(false, false, true, true, true);
    memes[11] = createMeme(false, false, false, true, true);
    memes[12] = createMeme(false, false, true, false, false);
    memes[13] = createMeme(true, true, false, false, false);
    memes[14] = createMeme(true, false, true, true, true);
    memes[15] = createMeme(true, false, true, true, true);
    memes[16] = createMeme(true, false, false, false, false);
    memes[17] = createMeme(false, false, true, false, true);
    memes[18] = createMeme(true, true, false, true, false);
    memes[19] = createMeme(false, true, false, true, false);
    memes[20] = createMeme(true, true, false, false, true);
    memes[21] = createMeme(false, true, true, true, true);
    memes[22] = createMeme(false, false, false, true, false);
    memes[23] = createMeme(true, true, false, true, true);
    memes[24] = createMeme(false, true, false, false, false);
    memes[25] = createMeme(true, true, false, true, true);
    memes[26] = createMeme(true, true, false, false, false);
    memes[27] = createMeme(true, true, false, true, false);
    memes[28] = createMeme(true, true, true, false, false);
    memes[29] = createMeme(false, true, false, false, false);
    memes[30] = createMeme(false, false, true, true, true);
    memes[31] = createMeme(false, true, false, false, true);
    memes[32] = createMeme(false, false, false, false, false);
    memes[33] = createMeme(false, false, false, false, true);
    memes[34] = createMeme(false, false, true, true, true);
    memes[35] = createMeme(false, true, false, true, true);
    memes[36] = createMeme(true, true, false, true, true);
    memes[37] = createMeme(true, true, false, true, true);
    memes[38] = createMeme(true, true, false, false, true);
    memes[39] = createMeme(false, false, false, true, false);
    memes[40] = createMeme(false, true, false, false, false);
    memes[41] = createMeme(true, true, false, false, false);
    memes[42] = createMeme(true, true, false, true, true);
    memes[43] = createMeme(true, true, false, true, true);
    memes[44] = createMeme(true, false, false, false, true); 

    return memes;
}