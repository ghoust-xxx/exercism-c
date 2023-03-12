#include "secret_handshake.h"
#include <stdlib.h>

#define N_WORDS 4

char *words[N_WORDS] = {
    "wink",
    "double blink",
    "close your eyes",
    "jump"
};

const char **commands(size_t number) {
    const char **res;
    int i, move, is_revers, tmp;
    size_t count;

    is_revers = number & 0x10;
    number = number & 0x0F;
    tmp = number;

    for (count = 0; tmp; tmp >>= 1) {
        count += tmp & 1;
    }
    if (!count) {
        res = calloc(1, sizeof(char *));
        return res;
    }
    res = calloc(count, sizeof(char *));

    if (is_revers) {
        i = count - 1;
    } else {
        i = 0;
    }
    move = 0;
    for (move = 0; move < N_WORDS; move++) {
        tmp = number & 1;
        number >>= 1;
        if (tmp) {
            res[i] = words[move];
            if (is_revers) {
                i--;
            } else {
                i++;
            }
        }
    }

    return res;
}
