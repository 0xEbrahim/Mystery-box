vector<int> arr;
bool sprime[N];
void computeSemiPrime()
{
    memset(sprime, false, sizeof(sprime));

    for (int i = 2; i < N; i++) {

        int cnt = 0;
        int num = i;
        for (int j = 2; cnt < 2 && j * j <= num; ++j) {
            while (num % j == 0) {
                num /= j, ++cnt; 
              
            }
        }
        if (num > 1)
            ++cnt;
        if (cnt == 2) {

            sprime[i] = true;
            arr.push_back(i);
        }
    }
}
