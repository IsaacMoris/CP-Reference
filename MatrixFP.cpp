struct Matrix
{
    int n,val;
    vector<vector<int> > a;
    Matrix(int _n, int _val)
    {
        a.resize(n,vector<int>(n,0));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                a[i][j]= (i==j ? val : 0 );
    }
    Matrix operator*(const Matrix &other)
    {
        Matrix res(n,0);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                for(int k=0; k<n; k++)
                    res.a[i][j]=(1LL*res.a[i][j]+1LL*a[i][k]*other.a[k][j])%mod;
        return res ;
    }
};
Matrix power(Matrix a, int p)
{
    Matrix res(a.n,1), temp=a;
    while(p)
    {
        if(p&1)
            res=res*temp;
        temp=temp*temp;
        p>>1;
    }
    return res;
}
