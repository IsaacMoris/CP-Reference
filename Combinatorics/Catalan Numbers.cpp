const int MOD = ....
const int MAX = ....
int catalan[MAX];
void init() {
    catalan[0] = catalan[1] = 1;
    for (int i=2; i<=n; i++) {
        catalan[i] = 0;
        for (int j=0; j < i; j++) {
            catalan[i] += (catalan[j] * catalan[i-j-1]) % MOD;
            if (catalan[i] >= MOD) {
                catalan[i] -= MOD;
            }
        }
    }
}

// 1- Number of correct bracket sequence consisting of n opening and n closing brackets.
// 2- The number of rooted full binary trees with n+1 leaves (vertices are not numbered). 
//    A rooted binary tree is full if every vertex has either two children or no children.
// 3- The number of ways to completely parenthesize n+1 factors.
// 4- The number of triangulations of a convex polygon with n+2 sides 
//    (i.e. the number of partitions of polygon into disjoint triangles by using the diagonals).
// 5- The number of ways to connect the 2n points on a circle to form n disjoint chords.
// 6- The number of non-isomorphic full binary trees with n internal nodes (i.e. nodes having at least one son).
// 7- The number of monotonic lattice paths from point (0,0) to point (n,n) in a square lattice of size n×n, 
//    which do not pass above the main diagonal (i.e. connecting (0,0) to (n,n)).
// 8- Number of permutations of length n that can be stack sorted 
//    (i.e. it can be shown that the rearrangement is stack sorted if and only if
//    there is no such index i<j<k, such that ak<ai<aj ).
// 9- The number of non-crossing partitions of a set of n elements.
// 10- The number of ways to cover the ladder 1…n using n rectangles 
// (The ladder consists of n columns, where ith column has a height i).
