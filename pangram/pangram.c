#include "pangram.h"

#include <ctype.h>
#include <string.h>

#define ABC_L 26

bool is_pangram(const char *sentence) {
    int abc[ABC_L] = {0};
    int i, c;

    if (!sentence) {
        return 0;
    }

    for (i = 0; i < (int) strlen(sentence); i++) {
        c = sentence[i];
        if (!isalpha(c)) {
            continue;
        }
        c = tolower(c);
        abc[c - 'a']++;
    }

    for (i = 0; i < ABC_L; i++) {
        if (abc[i] == 0) {
            return 0;
        }
    }

    return 1;
}
