# programming

## 作業二A
給定一個陣列 chess[8][8], chess[i][j] 只有三種值

0: 表示空白
1: 表示黑棋
2: 表示白棋

給定一個棋盤內容，給定一個座標 (i,j), 寫一個程式回答
1. (i,j) 是什麼顏色的棋子
2. (i,j) 的8個方向，有哪些位子可以下子(黑白棋規則)
NOTE: 下子的顏色跟 (i,j) 的棋子一樣顏色
i.e.,
case 1: 如果 (i,j) 是空白，那(i,j)周圍不能下
case 2: 如果 (i,j) 是黑棋，那就找(i,j) 8方向可下黑棋的位址輸出
case 3: 如果 (i,j) 是白棋，那就找(i,j) 8方向可下白棋的位址輸出

程式必須要有 nested loop, for or while, 都可以
黑白棋規則子行上網找，或上課聽

＊以後所有作業都只交github, gitee, or gitlab 或其他 git 網址，並可能要到Lab被口試＊

以下鏈結，有範例

https://hackmd.io/@chtsai/ryI1vRQbT


也可以試試(可能比較簡單)
但未來效果一樣可用
作業二B

https://hackmd.io/@chtsai/HyJwgII-6

Answer in file : 9x9multiplication_table.exe

## (作業三) 作業完成期限上課最後一周 ，第18週前你可以自行更新你的
電子筆記，作業頁面，18週之後我就不看了。
(但10/25日前請將作業連結交上，我會不定期的每週上去瀏覽)

https://hackmd.io/@chtsai/B1abq0QZ6

Answer in link : https://gms-ndhu-edu.gitbook.io/c_library/c_library/c_library

## (作業四) 將作業二改寫成函數，(此函數功能為，找出 i,j 座標，方向(dx,dy)是否有可下子的位置，若無傳回0, 若有傳回1還有距離(i,j)幾步)。

1. 函數輸入參數，chess棋盤, i,j座標，方向(dx, dy)
函數輸出
 case 1: 0, 表示沒有可下的位置
 case 2: n, 表示有可下的位置，並位置在離 i,j 方向n步處。
 例如: 若(i,j)=(3,3)， 方向西北方，也就是 (dx,dy)=(-1,-1)
 如果 (1,1)為可下的位址，函數會傳回 2，也就是 (i,j)+2(dx,dy) == (1,1)。只要知道方向跟n步就可以算出座標為 (i,j)+n(dx,dy)。

https://hackmd.io/@chtsai/r1G25JHba


2. 再利用這個函數，列印出目前棋盤，白子所有可以走的位置，黑子所有可以走的位置。


上課影片:https://youtu.be/vtWfpw5v8SA

 作業四
僅顯示第 6 週
 	
10月 22日 - 10月 28日 (第7週)
完成作業四的同學可以接下去挑戰
## 作業五
## 作業六

https://hackmd.io/@chtsai/Bk2PbLrWa

## 作業七
總結:
作業二，四，五，六。就是在設計一個與電腦對弈的黑白棋
思維的過程，過程中會有一些子問題被分割出來(也就是作業二
作業四，作業五)
然後一個階段一個階段完成子問題的設計，測試
最後在完成 作業六 main function
這個以程式解決問題思維的過程。請同學做完作業六
之後，寫一個黑白棋設計的總結心得。
還有你認為你可以再改善的部分。
