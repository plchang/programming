/*
作業二
給定一個陣列 chess[8][8], chess[i][j] 只有三種值
0: 表示空白
1: 表示黑棋
2: 表示白棋
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const int CHESS_BOARD_SIZE = 8;


char chess[8][8] = {0};
char *temp[8][8] = {0};


void init(){
    printf("INIT\n");
    for(int i = 0;i < 8;i ++){
        for(int j = 0;j < 8;j ++){
            if(i == 3){
                if(j == 4) chess[i][j] = '1';
                else if(j == 3) chess[i][j] = '2';
                else chess[i][j] = '0';
            }else if(i == 4){
                if(j == 3) chess[i][j] = '1';
                else if(j == 4) chess[i][j] = '2';
                else chess[i][j] = '0';
            }else{
                chess[i][j] = '0';
            }

            printf("%c", chess[i][j]);
        }
        printf("\n");
    }
    
}

/*
Reference:
對局開始時C4和D3擺上黑棋，C3和D4擺上白棋
雙方交替輪下，黑方先下棋。
一步合法棋步：在一個空位新落下一顆棋子，然後翻轉對方一顆或多顆棋子。
在新落下的棋子與棋盤上已有同色棋子之間，任何被包圍住的對方棋子都要翻轉過來。可以是橫著包圍、豎著包圍、或是斜著包圍；而且被包圍住的位置上必須全部是對方的棋子才行，不能有空位。
同一步棋可以在多個方向上翻棋，任何被包圍住的棋子都必須翻轉過來；下棋方無權選擇不去翻轉某個棋子。
至少要能翻轉對方的一顆棋子，否則就不能落子。如果都無法至少翻轉一顆棋子，那麼這一回合只得跳過（Pass），由對方繼續下棋，直到有合法棋步可下為止。
如果一方至少還有一步合法棋步可下，他就必須下棋，不得跳步。

Reference:
https://blog.gtwang.org/programming/c-cpp-rand-random-number-generation-tutorial-examples/

*/
// (i,j) 的8個方向，有哪些位子可以下子(黑白棋規則)
// NOTE: 下子的顏色跟 (i,j) 的棋子一樣顏色
/*i.e.,
case 1: 如果 (i,j) 是空白，那(i,j)周圍不能下
case 3: 如果 (i,j) 是白棋，那就找(i,j) 8方向可下白棋的位址輸出*/

int dir(int row, int j, int k){
    for(int i = 0;i < 8;i ++){
        switch (i)
        {
        case 0: //right
            temp[k][i] = &chess[row + k][j];
        case 1: //left
            temp[k][i] = &chess[row - k][j];

        case 2: //up
            temp[k][i] = &chess[row][j - k];

        case 3: //left up
            temp[k][i] = &chess[row - k][j - k];

        case 4: //right up
            temp[k][i] = &chess[row + k][j - k];

        case 5: // left down
            temp[k][i] = &chess[row - k][j + k];

        case 6: // right down
            temp[k][i] = &chess[row + k][j + k];
        case 7: // down
            temp[k][i] = &chess[row][j + k];
        
        default:
            break;
        }

    }

    return 1;
}

int able(int row, int j){
    for(int k = 0;k < 8;k ++){
        for(int t = 0;t < 8;t ++){
            printf("%c", chess[k][t]);
        }
        printf("\n");
    }

    printf("chess[%d][%d] = %c \n", row, j, chess[row][j]);
    if(chess[row][j] == '0'){
        printf("Can't play, pass! %c\n", chess[row][j]);
    }else{
        for(int k = 1;row + k < 7 && row - k >= 0 && j + k < 7 && j - k >= 0;k ++){
            dir(row, j, k);

            for(int v = 0;v < 8;v ++){    
                printf("test1 temp[%d][%d] = %c\n", k, v, temp[k][v]);
                if(*temp[k][v] == '0'){
                    break;
                }else{
                    if(*temp[k][v] != chess[row][j]){ // different color
                        
                        dir(row, j, k + 1); //next 
                        
                        printf("temp[%d][%d] = %c\n", k + 1, v, temp[k + 1][v]);
                        if(*temp[k + 1][v] == '0') chess[k + 1][v] = 'x';
                            
                    }else if(*temp[k][v] == chess[row][j]){
                        k ++;   
                    }                 
                }
            }
        }
    }

    return 1;
}



/*
給定任意一個棋盤內容，給定任意有效一個座標 (i,j), 寫一個程式回答
程式必須要有 nested loop, for or while, 都可以
黑白棋規則子行上網找，或上課聽*/

int main()
{
    int col = 0, row = 0;

    init();

    for(int i = 0;i < 8;i ++){
        for(int j = 0;j < 8;j ++){
            if(j == 7)scanf("%c\n", &chess[i][j]);
            else scanf("%c ", &chess[i][j]);
        }
    }
    printf("scanf\n");
    for(int i = 0;i < 8;i ++){
        for(int j = 0;j < 8;j ++){
            printf("chess[%d][%d] = %c ", i, j, chess[i][j]);
        }
        printf("\n");
    }
        
    scanf("%d %d", &row, &col);

    printf("%d %d\n", row, col);
    able(row, col);

    for(int i = 0;i < 8;i ++){
        for(int j = 0;j < 8;j ++){
            printf("%c", chess[i][j]);
        }
        printf("\n");
    }

    return 0;
}



