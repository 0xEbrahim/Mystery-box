vector<bool>not_primes(1e6 + 1);vector<int>primes;
vector<int>divisors_num(1e6 + 1);
void sieve(int n){
    for(int i = 1 ; i < 1e6 + 1 ; i++){
        for(int j = i ; j < 1e6 + 1 ; j+=i){
            divisors_num[j]++;
        }
    }
}
