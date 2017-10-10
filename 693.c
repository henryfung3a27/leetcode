/* 693. Binary Number with Alternating Bits */

int* bits(int n, int* count) {
    int logn = log(n) / log(2);
    int* arr = calloc(logn + 1, sizeof(int));
    
	// produce an array which is the binary pattern of n
    for (int i = logn; i >= 0 && n >= 0; i--) {
        if (n - pow(2, i) >= 0) {
            arr[i] = 1;
            n -= pow(2, i);
        }
    }
    
    *count = logn;
    return arr;
}

bool hasAlternatingBits(int n) {
    int count, flag;
    int* arr = bits(n, &count);
    
    flag = arr[count];
    for (int i = count - 1; i >= 0; i--) {
		// check alternative pattern
        if (arr[i] - flag) {
            flag = arr[i];
        }
        else return false;
    }
    return true;
}

int main() {
    hasAlternatingBits(7);	// 7 = 111(2) -> false
	hasAlternatingBits(10);	// 10 = 1010(2) -> true
	return 0;
}
