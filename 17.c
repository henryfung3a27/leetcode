/* 17. Letter Combinations of a Phone Number */

/* The fun() is to merge the array of strings (a) and the char array (b).
 * Then it returns the pointer to pointer to the array of new strings.
 */


char** fun(char** a, char *b, int *size) {
    int len_b = strlen(b);
    int len = len_b * (*size);      // size of new array of strings
    int w = 0;
    
    char** res = malloc(len * sizeof(char*));
    char temp[32];
    
    for (int i = 0; i < len; i++) {
        res[i] = calloc(strlen(a[0]) + 2, sizeof(char));
    }
    
    for (int i = 0; i < len_b; i++) {
        for (int k = 0; k < *size; k++) {
            sprintf(temp, "%s%c", a[k], b[i]);
            strcpy(res[w++], temp);
        }
    }
    
    *size = len;
    return res;
}

char** letterCombinations(char* digits, int* returnSize) {
    if (strlen(digits) < 1) return 0;
    
    const char key[8][5] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int len_digits = strlen(digits);
    
    char** ret = malloc(sizeof(char*));
    
    ret[0] = calloc(1, sizeof(char));
    
    *returnSize = 1;
    
    for (int i = 0; i < len_digits; i++) {
        ret = fun(ret, key[digits[i] - '0' - 2], returnSize);
        // ret is keep on pointing to a new array of strings. Then, use the new
        // pointer to merge new characters by giving the ret as a parameter of fun();
    }
    
    return ret;
}
