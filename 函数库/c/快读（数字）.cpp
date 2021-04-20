#include<cstdio>

int read()
{
    int a = 0, b = 1;
    char ch = getchar();
    while((ch < '0' || ch > '9') && (ch != '-')) {
        ch = getchar();
    }
    if(ch == '-'){
        b = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        a = a * 10 + ch - '0';
        ch = getchar();
    }
    return a * b;
}
