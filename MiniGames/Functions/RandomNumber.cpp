#include "RandomNumber.h"

int RandomNumber(int max, int min) {
    srand(time(nullptr));
    return min + rand() % (max - min);
}
