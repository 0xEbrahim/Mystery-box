vector<int>divs;
void factorization(int n){
    for(int i = 1 ; i * i <= n ; i++)
    {
        if(n % i == 0){
            divs.push_back(i);
            if(n / i != i)
                divs.push_back(n / i);
        }
    }
}
