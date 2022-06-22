#include <stdio.h>
 
int main()
{
    int ano=4,n,i;
    
    scanf("%d", &n);
    for(i=1; n>i; i++){
      
        if((ano%400==0 && ano%100!=0)|| ano%4==0) {
            printf("%04d - ano:%4.d\n", i,ano);
            ano+=4;
            }}
            
    if((ano%400==0 && ano%100!=0)|| ano%4==0) {
        printf("%04d - ano:%4.d", i,ano);
        ano+=4;}
}