#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxLengthSubstring(char* s) {

    int freq[26] = {0};

    int n = strlen(s);

    int maxLen = 0;

    int start = 0;

    for (int end = 0; end < n; end++) {

        freq[s[end] - 'a']++;

        while (freq[s[end] - 'a'] > 2) {

            freq[s[start] - 'a']--;
            start++;
        }

        int currLen = end - start + 1;

        if (currLen > maxLen) {
            maxLen = currLen;
        }
    }

    return maxLen;
}


int main() {
    char s[] = "bcbbbcba";
    printf("O comprimento maximo da substring sem repetir caracteres e: %d\n", maxLengthSubstring(s));
    return 0;
}
