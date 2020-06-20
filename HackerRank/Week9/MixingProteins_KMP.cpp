// Wrong answer

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

/*
 * Complete the pmix function below.
 */

void preKMP(char* pattern, int m, int* fail) {
    int i, k;

    fail[0] = -1;
    for (i = 1; i < m; i++) {
        k = fail[i - 1];
        while (k >= 0) {
            if (pattern[k] == pattern[i - 1]) {
                break;
            } else {
                k = fail[k];
            }
        }
        fail[i] = k + 1;
    }
}

int KMP(char* pattern, char* target, int m, int n, int* fail) {
    int i, k;

    i = 0;
    k = 0;
    while (i <= m) {
        if (k == -1) {
            i++;
            k = 0;
        } else if (target[i] == pattern[k]) {
            i++;
            k++;
            if (k == m)
                return i - m;
        } else {
            k = fail[k];
        }
    }

    return -1;
}

/*
 * Please either make the string static or allocate on the heap. For example,
 * static char str[] = "hello world";
 * return str;
 *
 * OR
 *
 * char* str = "hello world";
 * return str;
 *
 */
char* pmix(char* s, int n, int k) {
    char str[1000001] = {0, };
    int fail[1000001] = {0, };
    int i, c, x, r;
    bool flag;
    
    for (i = 0; i < n; i++) {
        str[i] = s[i];
        str[i + n] = s[i];
    }
    
    preKMP(s, n, fail);
    
    flag = false;
    c = 0;
    while (c < k) {
        c++;
        for (i = 0; i < n; i++) {
            if (str[i] == 'A') {
                if (str[i + 1] == 'A') {
                    str[i] = 'A';
                } else if (str[i + 1] == 'B') {
                    str[i] = 'B';
                } else if (str[i + 1] == 'C') {
                    str[i] = 'C';
                } else if (str[i + 1] == 'D') {
                    str[i] = 'D';
                }
            } else if (str[i] == 'B') {
                if (str[i + 1] == 'A') {
                    str[i] = 'B';
                } else if (str[i + 1] == 'B') {
                    str[i] = 'A';
                } else if (str[i + 1] == 'C') {
                    str[i] = 'D';
                } else if (str[i + 1] == 'D') {
                    str[i] = 'C';
                }
            } else if (str[i] == 'C') {
                if (str[i + 1] == 'A') {
                    str[i] = 'C';
                } else if (str[i + 1] == 'B') {
                    str[i] = 'D';
                } else if (str[i + 1] == 'C') {
                    str[i] = 'A';
                } else if (str[i + 1] == 'D') {
                    str[i] = 'B';
                }
            } else if (str[i] == 'D') {
                if (str[i + 1] == 'A') {
                    str[i] = 'D';
                } else if (str[i + 1] == 'B') {
                    str[i] = 'C';
                } else if (str[i + 1] == 'C') {
                    str[i] = 'B';
                } else if (str[i + 1] == 'D') {
                    str[i] = 'A';
                }
            }
        }
        for (i = 0; i < n; i++) {
            str[i + n] = str[i];
        }
        
        if (flag == false) {
            x = KMP(s, str, n, n + n, fail);
            if (x != -1) {
                flag = true;
                r = k / c;
                c = r * c;
                x = (x * r) % n;
                for (i = 0; i < n; i++) {
                    str[(x + i) % (n + n)] = s[i]; 
                    str[(x + i + n) % (n + n)] = s[i]; 
                }
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        s[i] = str[i];
    }
    
    return s;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nk = split_string(readline());

    char* n_endptr;
    char* n_str = nk[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* k_endptr;
    char* k_str = nk[1];
    int k = strtol(k_str, &k_endptr, 10);

    if (k_endptr == k_str || *k_endptr != '\0') { exit(EXIT_FAILURE); }

    char* s = readline();

    char* result = pmix(s, n, k);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
