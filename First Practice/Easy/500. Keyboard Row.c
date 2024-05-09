// Solution 1
#define HASH_TABLE_SIZE 26

// 哈希表节点的结构Structure of Hash Table Node
struct Node {
    char key;
    int value;
    struct Node* next;
};

// Structure of Hash Table
struct HashTable {
    struct Node* buckets[HASH_TABLE_SIZE];
};

// Initialize the Hash Table
struct HashTable* initHashTable() {
    struct HashTable* ht = (struct HashTable*)malloc(sizeof(struct HashTable));
    memset(ht->buckets, 0, sizeof(ht->buckets));
    return ht;
}

// Inserting key-value pairs into a Hash Table
void insert(struct HashTable* ht, char key, int value) {
    int index = key - 'a';
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = ht->buckets[index];
    ht->buckets[index] = newNode;
}

// Find the value corresponding to the key
int find(struct HashTable* ht, char key) {
    int index = key - 'a';
    struct Node* current = ht->buckets[index];
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1; // Return -1 if not found
}

char ** findWords(char ** words, int wordsSize, int* returnSize) {
    struct HashTable* ht = initHashTable();
    char** ans = (char **)malloc(sizeof(char*) * wordsSize);
    *returnSize = 0;

    // Initialize the Hash Table of keyboard line numbers
    insert(ht, 'q', 1);
    insert(ht, 'w', 1);
    insert(ht, 'e', 1);
    insert(ht, 'r', 1);
    insert(ht, 't', 1);
    insert(ht, 'y', 1);
    insert(ht, 'u', 1);
    insert(ht, 'i', 1);
    insert(ht, 'o', 1);
    insert(ht, 'p', 1);
    insert(ht, 'a', 2);
    insert(ht, 's', 2);
    insert(ht, 'd', 2);
    insert(ht, 'f', 2);
    insert(ht, 'g', 2);
    insert(ht, 'h', 2);
    insert(ht, 'j', 2);
    insert(ht, 'k', 2);
    insert(ht, 'l', 2);
    insert(ht, 'z', 3);
    insert(ht, 'x', 3);
    insert(ht, 'c', 3);
    insert(ht, 'v', 3);
    insert(ht, 'b', 3);
    insert(ht, 'n', 3);
    insert(ht, 'm', 3);

    // Iterate through the array of words, checking if each word can be entered using the same line of keyboard characters
    for (int i = 0; i < wordsSize; i++) {
        char* word = words[i];
        int row = find(ht, tolower(word[0]));
        bool valid = true;
        for (int j = 1; word[j] != '\0'; j++) {
            if (find(ht, tolower(word[j])) != row) {
                valid = false;
                break;
            }
        }
        if (valid) {
            ans[*returnSize] = strdup(word); // Copying words to the result array
            (*returnSize)++;
        }
    }

    // Free hash table memory
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        struct Node* current = ht->buckets[i];
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht);

    return ans;
}

// Solution 2
/*
 * 500. Keyboard Row
 *
 * Given an array of strings words, return the words that can be typed using 
 * letters of the alphabet on only one row of American keyboard like the image below.
 * 
 * In the American keyboard:
 * 
 * the first row consists of the characters "qwertyuiop",
 * the second row consists of the characters "asdfghjkl", and
 * the third row consists of the characters "zxcvbnm".
 *
 * 1 <= words.length <= 20
 * 1 <= words[i].length <= 100
 * words[i] consists of English letters (both lowercase and uppercase). 
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/* English letter (a~z) and key row position lookup table */
static const unsigned char lookup[] = {
    1,  /* 00:a */
    0,  /* 01:b */
    0,  /* 02:c */
    1,  /* 03:d */
    2,  /* 04:e */
    1,  /* 05:f */
    1,  /* 06:g */
    1,  /* 07:h */
    2,  /* 08:i */
    1,  /* 09:j */
    1,  /* 10:k */
    1,  /* 11:l */
    0,  /* 12:m */
    0,  /* 13:n */
    2,  /* 14:o */
    2,  /* 15:p */
    2,  /* 16:q */
    2,  /* 17:r */
    1,  /* 18:s */
    2,  /* 19:t */
    2,  /* 20:u */
    0,  /* 21:v */
    2,  /* 22:w */
    0,  /* 23:x */
    2,  /* 24:y */
    0,  /* 25:z */
};

char ** findWords(char ** words, int wordsSize, int* returnSize){

    /*
     * Input:
     *  words,
     *  wordsSize
     */

    char **ans = (char **)malloc(sizeof(char *) * 20);

    *returnSize = 0;

    for (int i = 0, row, len; i < wordsSize; i++) {

        /* Get the row position of first character */
        row = lookup[tolower(words[i][0]) - 'a'];
        len = 0;

        /* Check if all the characters are in same row */
        for (int j = 0; words[i][j]; j++) {
            if (lookup[tolower(words[i][j]) - 'a'] != row) {
                break;
            }

            len++;
        }

        if (words[i][len] == 0) {
            ans[*returnSize] = malloc(sizeof(char) * (len + 1));
            strcpy(ans[*returnSize], words[i]);
            (*returnSize) += 1;
        }
    }

    if(*returnSize == 0) {
        free(ans);
        ans = NULL;
    }

    /*
     * Output:
     *  *returnSize
     *  return the words that can be typed using letters of the alphabet 
     *  on only one row of American keyboard like the image below.
     */

    return ans;
}
