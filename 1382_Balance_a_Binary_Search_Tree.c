struct TreeNode* new( int val ) {
    struct TreeNode* node = ( struct TreeNode* )malloc( sizeof( struct TreeNode ));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorder( struct TreeNode* root, int* a, int* idx ) {
    if ( root == NULL ) {
        return;
    }
    inorder( root->left, a, idx );
    a[ ( *idx )++ ] = root->val;
    inorder( root->right, a, idx );
}

struct TreeNode* build( int* a, int start, int end ) {
    if ( start > end ) {
        return NULL;
    }
    int mid = ( start + end ) / 2;
    struct TreeNode* root = new( a[ mid ] );
    root->left = build( a, start, mid - 1 );
    root->right = build( a, mid + 1, end );
    return root;
}

struct TreeNode* balanceBST( struct TreeNode* root ) {
    int a[ 10000 ];
    int idx = 0;
    inorder( root, a, &idx );
    return build( a, 0, idx - 1 );
}
