#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

void caesarCipher(char *text, int key, int encrypt);
void substitutionCipher(char *text, char *key, int encrypt);
void vigenereCipher(char *text, char *key, int encrypt);
void monoalphabeticCipher(char *text, int encrypt);
void oneTimePadCipher(char *text, char *key, int encrypt);
void hillCipher(char *text, int encrypt);

void caesarCipher(char *text, int key, int encrypt) {
    for (int i = 0; text[i] != '\0'; i++) {
        char offset = isupper(text[i]) ? 'A' : 'a';
        text[i] = (encrypt ? (text[i] - offset + key) : (text[i] - offset - key + 26)) % 26 + offset;
    }
}

void substitutionCipher(char *text, char *key, int encrypt) {
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; text[i] != '\0'; i++) {
        char c = toupper(text[i]);
        if (isalpha(c)) {
            char *pos = strchr(encrypt ? alphabet : key, c);
            text[i] = encrypt ? key[pos - alphabet] : alphabet[pos - key];
        }
    }
}

void vigenereCipher(char *text, char *key, int encrypt) {
    int keyLen = strlen(key);
    for (int i = 0, j = 0; text[i] != '\0'; i++) {
        char offset = isupper(text[i]) ? 'A' : 'a';
        int keyIndex = toupper(key[j % keyLen]) - 'A';
        text[i] = (encrypt ? (text[i] - offset + keyIndex) : (text[i] - offset - keyIndex + 26)) % 26 + offset;
        j += isalpha(text[i]);
    }
}

void monoalphabeticCipher(char *text, int encrypt) {
    // Example monoalphabetic substitution (could be randomized)
    char *key = "QWERTYUIOPASDFGHJKLZXCVBNM";
    substitutionCipher(text, key, encrypt);
}

void oneTimePadCipher(char *text, char *key, int encrypt) {
    for (int i = 0; text[i] != '\0'; i++) {
        char offset = isupper(text[i]) ? 'A' : 'a';
        int keyIndex = toupper(key[i]) - 'A';
        text[i] = (encrypt ? (text[i] - offset + keyIndex) : (text[i] - offset - keyIndex + 26)) % 26 + offset;
    }
}

void hillCipher(char *text, int encrypt) {
    // Simplified Hill Cipher for 2x2 matrix (this is a placeholder for a full implementation)
    int matrix[2][2] = {{3, 3}, {2, 5}}; // Example matrix, must be invertible mod 26
    int len = strlen(text);
    if (len % 2 != 0) strcat(text, "X"); // Padding for odd length
    for (int i = 0; i < len; i += 2) {
        int x = toupper(text[i]) - 'A';
        int y = toupper(text[i + 1]) - 'A';
        text[i] = (matrix[0][0] * x + matrix[0][1] * y) % 26 + 'A';
        text[i + 1] = (matrix[1][0] * x + matrix[1][1] * y) % 26 + 'A';
    }
    if (!encrypt) {
        // Decryption requires the inverse matrix mod 26, which is not implemented here.
        printf("Decryption not implemented for Hill Cipher.\n");
    }
}

int main() {
    char text[MAX];
    char key[MAX];
    int choice, encrypt, caesarKey;

    printf("Enter the text: ");
    fgets(text, MAX, stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove trailing newline

    printf("Choose the cipher type:\n");
    printf("1. Caesar Cipher\n");
    printf("2. Substitution Cipher\n");
    printf("3. Vigenere Cipher\n");
    printf("4. Monoalphabetic Cipher\n");
    printf("5. One-Time Pad Cipher\n");
    printf("6. Hill Cipher\n");
    scanf("%d", &choice);

    printf("Choose operation:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &encrypt);
    encrypt = (encrypt == 1);

    getchar(); // Clear newline character from input buffer

    switch (choice) {
        case 1:
            printf("Enter the key (0-25): ");
            scanf("%d", &caesarKey);
            caesarCipher(text, caesarKey, encrypt);
            break;
        case 2:
            printf("Enter the substitution key (26 letters): ");
            fgets(key, MAX, stdin);
            key[strcspn(key, "\n")] = '\0'; // Remove trailing newline
            substitutionCipher(text, key, encrypt);
            break;
        case 3:
            printf("Enter the Vigenere key: ");
            fgets(key, MAX, stdin);
            key[strcspn(key, "\n")] = '\0'; // Remove trailing newline
            vigenereCipher(text, key, encrypt);
            break;
        case 4:
            monoalphabeticCipher(text, encrypt);
            break;
        case 5:
            printf("Enter the One-Time Pad key: ");
            fgets(key, MAX, stdin);
            key[strcspn(key, "\n")] = '\0'; // Remove trailing newline
            oneTimePadCipher(text, key, encrypt);
            break;
        case 6:
            hillCipher(text, encrypt);
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    printf("Result: %s\n", text);

    return 0;
}
