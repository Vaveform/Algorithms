#include "SearchFunctions.h"

int searchNum(int* array, int len, int value) {
    for (int i = 0; i < len; ++i) {
        if (array[i] == value)
            return i;
    }
    return -1;
}
