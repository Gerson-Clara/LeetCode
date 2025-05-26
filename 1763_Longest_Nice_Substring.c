bool isNice( const char* sub ) {
    int low = 0;
    int upp = 0;
    for ( int i = 0; sub[ i ] != '\0'; i++ ) {
        if ( islower( sub[ i ] ) ) {
            low |= ( 1 << ( sub[ i ] - 'a' ) );
        } else if ( isupper( sub[ i ] ) ) {
            upp |= ( 1 << ( sub[ i ] - 'A' ) );
        }
    }
    return low == upp && low != 0;
}

char* longestNiceSubstring( char* s ) {
    int n = strlen( s );
    int max = 0;
    int sttIdx = -1;

    for ( int i = 0; i < n; i++ ) {
        for ( int j = i; j < n; j++ ) {
            
            char sub[ 101 ]; 
            strncpy( sub, s + i, j - i + 1 );
            sub[ j - i + 1 ] = '\0';

            if ( isNice( sub ) ) {
                if ( strlen( sub ) > max ) {
                    max = strlen( sub );
                    sttIdx = i;
                }
            }
        }
    }

    if ( sttIdx == -1 ) {
        char* emp = ( char* )malloc( 1 );
        emp[ 0 ] = '\0';
        return emp;
    } else {
        char* out = ( char* )malloc( max + 1 );
        strncpy( out, s + sttIdx, max );
        out[ max ] = '\0';
        return out;
    }
}
