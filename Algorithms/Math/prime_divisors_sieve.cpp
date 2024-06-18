vector<bool>not_primes(1e6 + 1);vector<int>primes;
vector<int>prime_divs(1e6 + 1);
void sieve(int n){
    primes.clear();
    not_primes[0] = not_primes[1] = true;
    for(int i = 2 ; i <= n ; i++){
        if(!not_primes[i]){
            primes.push_back(i);
            prime_divs[i] = i;
            for(int j = i * i ; j <= n ; j += i) {
                not_primes[j] = true;
                prime_divs[j] = i;
            }
        }
    }
}
