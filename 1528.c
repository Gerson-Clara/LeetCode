char* restoreString(char* s, int* indices, int indicesSize) {
    char *p;
    p = (char *)malloc((indicesSize + 1) * sizeof(char));

    for (int i = 0; i < indicesSize; i++) {
        p[indices[i]] = s[i];
    }

    p[indicesSize] = '\0';
    
    return p;
}