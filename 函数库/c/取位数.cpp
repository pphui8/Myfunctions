int[] getNum(long long n) {
    int a[10000];
    int len = 0;
    while(n) {
        a[l++] = n%10;
        n/=10;
    }
    return a;
}