#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(int k = 1;k < 10;k = k + 3){
        for (int i = 1;i < 10;i ++){
            for(int j = k ;j < 3 + k;j ++){
            
                printf("%d X %d = %d    ", j, i, i * j);

                if(i * j < 10) printf(" ");
            }

            printf("\n");
        }

        printf("\n");

    }
   
}
