bool areOccurrencesEqual( char* s ) {
    int i, occur = 0;

    for ( i = 0; i < strlen(s); i++ ) {
        if (s[0] == s[i]) occur++;
    }

    for ( i = 1; i < strlen(s); i++ ) {
        int check = 0;
        int j;
        for ( j = 0; j < strlen(s); j++ ) {
            if ( s[i] == s[j] ) check++;
        }
        if (check != occur) return false;
    }

    return true;
}
