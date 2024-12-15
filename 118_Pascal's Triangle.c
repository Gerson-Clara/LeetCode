int** generate ( int numRows, int* returnSize, int** returnColumnSizes ) {
    int** tri =  ( int** )malloc ( numRows * sizeof ( int* ) );
    *returnSize = numRows;
    *returnColumnSizes =  ( int* )malloc ( numRows * sizeof ( int ) );

    for  ( int i = 0; i < numRows; i++ ) {
        tri[i] =  ( int* )malloc (  ( i + 1 ) * sizeof ( int ) );
        ( *returnColumnSizes )[i] = i + 1;
        tri[i][0] = 1;
        tri[i][i] = 1;

        for  ( int j = 1; j < i; j++ ) {
            tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
        }
    }

    return tri;
}
