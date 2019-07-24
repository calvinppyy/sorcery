#include "rng.h"

using namespace std;

int generateRandom(int maxValue) {
    srand((unsigned) time(0));
    return (rand() % maxValue);
}