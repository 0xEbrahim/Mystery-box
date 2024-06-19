bool get_bit(int n , int bit){
    return ((n >> (bit)) & 1);
}

int set_bit(int n , int bit){
    return ((n) | (1 << bit));
}
int unset_bit(int n , int bit){
    return (((n) & (~(1 << bit))));
}
int flip_bit(int n , int bit){
    return (n ^ ( 1 << bit ));
}
int count_ones(int n){
    int counter = 0;
    while(n){
        counter += 1;
        n&=(n - 1);
    }
    return counter;
}
