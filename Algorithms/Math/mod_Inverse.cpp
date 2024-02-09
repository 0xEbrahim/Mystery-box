int fastPowerMod( int base, int exponent, int modulus )
{
    int result = 1;
    base %= modulus;
    while (exponent > 0)
    {
        if ( exponent & 1 )
            result = (result * base) % modulus;

        base = (base * base) % modulus;
        exponent >>= 1;
    }
    return result;
}

int inv( int num )
{
    return fastPowerMod( num , MOD - 2, MOD );
}

int NCR( int num, int i )
{
    return mul( mul( fact[num], inv( fact[num - i] ) ), inv( fact[i] ) );
}

// ------------------
int Extended_Euclid(int a, int b, int& x, int& y) {
    if (b==0) {
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int d = Extended_Euclid(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}
//-------------------
  int Mod_Inverse( int A, int M )
{ 
    Extended_Euclid( int A, int M );
    return ( x % M + M ) % M;
}
