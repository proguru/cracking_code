#include <stdio.h>
#ifndef max
    # define max(a,b) (a > b ? a : b)
#endif

int main(){
    printf("\n%d\n",max(15,200));
    return 0;
}
