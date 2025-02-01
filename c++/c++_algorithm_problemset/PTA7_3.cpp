#include <stdio.h>
int Gcd(int a, int b);
int main()
{
    int a, b, c;
    scanf("%d %d", &a, &b);
    c = Gcd(a,b);
    if (c != -1)
    {
        printf("%d\n", c);
    }
    else
    {
        printf("Input number should be positive!\n");
    }
    return 0;
}
int Gcd(int a,int b){
    int temp;
    if(a<0||b<0){
    	return -1;
	}
    if(a>b) temp=b;b=a;a=temp;
    for(int i=a;i>0;i--){
        if(a%i==0&&b%i==0){
            return i;
        }
    }
    return -1;
}
