#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1234

int is_word_in_list(char *word, char *list, char *delimiters) {
    char *token = strtok(list, delimiters);
    while (token != NULL) {
        if (strcmp(token, word) == 0) {
            return 1;
        }
        token = strtok(NULL, delimiters);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    FILE *fin, *fout;
    char *bufs, *s, *r, *t;
    int found_word = 0;

    if (argc != 6) {
        printf("use a.txt b.txt s r t\n");
        return -1;
    }

    if (!(fin = fopen(argv[1], "r"))) {
        printf("Can't read %s\n", argv[1]);
        return -2;
    }

    if (!(fout = fopen(argv[2], "w"))) {
        printf("Can't write %s\n", argv[2]);
        return -2;
    }

    s = argv[3];
    r = argv[4];
    t = argv[5];
    bufs = (char *)malloc(LEN * sizeof(char));

    while (fgets(bufs, LEN, fin) != NULL) {
        char *buf_copy = strdup(bufs);
        char *word = strtok(s, t);

        found_word = 0;
        while (word != NULL) {
            if (is_word_in_list(word, buf_copy, t)) {
                found_word = 1;
                break;
            }
            word = strtok(NULL, t);
        }

        if (found_word) {
            fprintf(fout, "%s\n", r);
        } else {
            fprintf(fout, "%s", bufs);
        }

        free(buf_copy);
    }

    free(bufs);
    fclose(fin);
    fclose(fout);
    return 0;
}

