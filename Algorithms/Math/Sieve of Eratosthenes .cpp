vector<int>primes;
vector<bool>composite(1e6);

void sieveOfEratosthenes(){
    composite[0]=composite[1]=true;

    for(int i = 2 ; i * i < composite.size() ; i++){
        if(!composite[i]){
            for(int j = i * i ; j <= composite.size() ; j+=i){
                composite[j] = true;
            }
        }
    }
}
