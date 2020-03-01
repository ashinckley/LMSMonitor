/*
 *	(c) 2015 László TÓTH
 *	(c) 2020 Stuart Hunter
 *
 *	Todo:
 *
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	See <http://www.gnu.org/licenses/> to get a copy of the GNU General
 *	Public License.
 *
 */
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "common.h"

int verbose = 0;
int textOut = false;

int incVerbose(void) {
    if (verbose < INT_MAX) {
        verbose++;
    }
    return verbose;
}

int getVerbose(void) { return verbose; }

int putMSG(const char *msg, int loglevel) {
    if (loglevel > verbose) {
        return false;
    }
    printf("%s", msg);
    return true;
}

void enableTOut(void) { textOut = true; }

int tOut(const char *msg) {
    if (!textOut) {
        return false;
    }
    printf("%s", msg);
    return true;
}

void abortMonitor(const char *msg) {
    perror(msg);
    exit(1);
}

bool isEmptyStr(const char *s) {
    if ((s == NULL) || (s[0] == '\0'))
        return true;
    return false;
}

char *replaceStr(const char *s, const char *find, const char *replace) {
    char *result;
    int i, cnt = 0;
    int rlen = strlen(replace);
    int flen = strlen(find);

    // Counting the number of times substring
    // occurs in the string
    for (i = 0; s[i] != '\0'; i++) {
        if (strstr(&s[i], find) == &s[i]) {
            cnt++;
            i += flen - 1;
        }
    }
    // Making new string of enough length
    result = (char *)malloc(i + cnt * (rlen - flen) + 1);

    i = 0;
    while (*s) {
        // compare the substring with the result
        if (strstr(s, find) == s) {
            strcpy(&result[i], replace);
            i += rlen;
            s += flen;
        } else
            result[i++] = *s++;
    }

    result[i] = '\0';
    return result;
}
