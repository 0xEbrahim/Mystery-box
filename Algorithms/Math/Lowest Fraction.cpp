void lowestFraction(int num1, int num2){
    int denom;
    denom = gcd(num1,num2);
    num1/=denom;
    num2/=denom;
    cout<<num1<<"/"<<num2;
}
