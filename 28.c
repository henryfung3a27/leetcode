// 28. Implement strStr()

/* Returns the index of the first occurrence of needle in haystack, 
 * or -1 if needle is not part of haystack.
 */

int strStr(char* haystack, char* needle) {
    int lenh = strlen(haystack);
    int lenn = strlen(needle);
    int i, flag = 1;
    
    if (lenn == 0) return 0;
    
    for (i = 0; i < (lenh - lenn + 1); i++) {
        if (haystack[i] == needle[0]) {
            flag = 1;
            while (flag && flag < lenn) {
                if (needle[flag] == haystack[i+flag]) ++flag;
                else flag = 0;
            }
            if (flag == lenn) return i;
        }
    }
    
    return -1;
}
