int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int findContentChildren(int* g, int gSize, int* s, int sSize) {
    // Sort the children's and cookie's sizes in non-decreasing order
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);
    
    // Initialize variables for the current child and cookie indices
    int i = 0, j = 0;
    
    // Iterate through the children and try to assign cookies to them
    while (i < gSize && j < sSize) {
        // If the current cookie is big enough to satisfy the current child, move to the next child and cookie
        if (s[j] >= g[i]) {
            i++;
        }
        j++;
    }
    
    // Return the number of satisfied children
    return i;
}