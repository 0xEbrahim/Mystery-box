vector<bool>not_primes(1e6 + 1);vector<int>primes;
void sieve(int n){
    primes.clear();
    not_primes[0] = not_primes[1] = true;
    for(int i = 2 ; i<= n ; i++){
        if(!not_primes[i]){
            primes.push_back(i);
            for(int j = i * i ; j <= n ; j += i)
                not_primes[j] = true;
        }
    }
}
