vector<int>primes;

void prime_factor(int n){
 for(int i = 2 ; i * i <= n ; i++){
     while(n%i==0){
         n/=i;
         primes.pb(i);
     }
 }
 if( n != 1 )
     primes.pb(n);
}
