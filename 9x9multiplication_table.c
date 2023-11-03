#include <stdio.h>
#include <stdlib.h>

int row(int r){
    
}
int col(int c){

}
int main()
{
    for (int i = 1;i < 10;i ++){
        for(int j = 1;j < 4;j ++){
        
            printf("%d X %d = %d    ", j, i, i * j);

            if(i * j < 10) printf(" ");
        }

        printf("\n");
    }

    printf("\n");
    for (int i = 1;i < 10;i ++){
        for(int j = 4;j < 7;j ++){
            printf("%d X %d = %d    ", j, i, i * j);
            if(i * j < 10) printf(" ");
        }

        printf("\n");
    }

    printf("\n");
    for (int i = 1;i < 10;i ++){
        for(int j = 7;j < 10;j ++){
            
            printf("%d X %d = %d    ", j, i, i * j);
            if(i * j < 10) printf(" ");

        }

        printf("\n");
    }
}