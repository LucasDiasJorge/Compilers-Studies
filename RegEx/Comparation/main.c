#include <stdio.h>
#include <regex.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define NUM_STRINGS 100

// Define the regex for EPC verification
const char* epcRegex = "^[a-fA-F0-9]{6,24}$";

// List of test strings (fill with appropriate values for testing)
const char* testStrings[NUM_STRINGS] = {
    "abcdef", "123456", "12a4fB", "GHIJKL", "000000", "1A2b3C", "ab12cd", "9f8e7d", "aaaaaa",
    "f0f0f0", "1234567890123456789012", "FFFFFF", "012345", "654321", "7b8d9e", "A1B2C3",
    "abcdefabcdefabcdefabcde", "00000", "abZ456", "xyzxyz", "12345g", "9h8i7j", "34567", "111111",
    "00ff00", "AABBCC", "123XYZ", "098765", "ghijkl", "mnopqr", "999999", "223344", "11223344", 
    "345FDE", "ABCDEF1234567890", "123", "aBcDeF", "998877", "1A2b3CdEfGh", "ffFfFf", "0123456789ABCDEF",
    "abcdefghi", "098F7D", "333333", "101010", "abcdefABCDEF", "1a2b3c4d5e", "ab0ff0", "defabc123456", 
    "FEDCBA9876543210", "777777", "abC123", "11AA22BB33", "123abc456def", "xyzABCxyz", "abcde0",
    "ZXY987", "76543210", "0f0f0f", "111aaa", "1234abc", "feedbeef", "0a1b2c", "3f4e5d", "ABCDE", 
    "1245678", "abcdef123", "fa8b3c", "9a7b8c", "ffAA55", "9988ff", "abcdefabcdef", "c0ffee", 
    "abcdefG", "987ABC", "ABC12DEF", "345GGG", "x9y8z7", "000001", "abcdef789012", "987654321ABC", 
    "1234ABCD5678", "1B2A3D4C5F", "ffdd44", "ABCabc123", "9876543210", "AaBbCcDdEeFf", "1234xyz5678", 
    "123abcABCdef", "ab12ef34gh", "1a2B3c4D", "F0F0F0F", "feedbeefcafe", "xyz987654", "abcdef123456", 
    "001122334455", "987def789abc", "123123123", "999FFF", "aabbccddeeff"
};

// Function to verify string using regex
int regexVerify(const char* string) {
    regex_t regex;
    int reti;

    // Compile the regular expression
    reti = regcomp(&regex, epcRegex, REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        return 0;
    }

    // Execute regular expression
    reti = regexec(&regex, string, 0, NULL, 0);
    regfree(&regex); // Free the regex

    return !reti;
}

// Scratch code for manual verification
int scratchVerify(const char* string) {
    int len = strlen(string);

    // Check if the length is between 6 and 24
    if (len < 6 || len > 24) {
        return 0;
    }

    // Check if each character is a valid hexadecimal digit
    for (int i = 0; i < len; i++) {
        if (!isxdigit(string[i])) {
            return 0;
        }
    }

    return 1;
}

int main() {
    clock_t start, end;
    double cpu_time_used;
    
    int regexMatches = 0;
    int scratchMatches = 0;

    // Measure regex verification time
    start = clock();
    for (int i = 0; i < NUM_STRINGS; i++) {
        if (regexVerify(testStrings[i])) {
            regexMatches++;
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Regex verification time: %f seconds\n", cpu_time_used);

    // Measure scratch code verification time
    start = clock();
    for (int i = 0; i < NUM_STRINGS; i++) {
        if (scratchVerify(testStrings[i])) {
            scratchMatches++;
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Scratch verification time: %f seconds\n", cpu_time_used);

    // Results
    printf("Regex matched %d strings\n", regexMatches);
    printf("Scratch code matched %d strings\n", scratchMatches);

    return 0;
}
