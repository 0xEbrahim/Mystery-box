double modpow(double base, ll pow)
{
    if (pow == 0)
        return 1;
    double u = modpow(base, pow / 2);
    u = (u * u);
    if (pow % 2 == 1)
        u = (u * base);
    return u;
}
