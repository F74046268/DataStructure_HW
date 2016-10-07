hw1-1:
輸入值>0 存入a,b
在recursive裡，回傳值為a*(a-1)*(a-2)...一直到為0項時，回傳1
所以回傳給main function的值為a*(a-1)*(a-2)...*2*1=a!

在iterative裡，先將c設為1，然後用b乘上c再assign給c，每loop一次，b-1
直到b=0結束loop，所得結果為c*b*(b-1)*(b-2)...*2*1=b!

hw1-2:

因為array要傳function很麻煩，所以我設為global變數
data[MAX]存的是使用者輸入的字串，index為奇數時，為集合的元素，除了\0
used[MAX]用來代表可取、可不取，為0不取，為1取
size為集合S所擁有的元素個數


取子集合的想法是，每個元素都有可取、可不取兩種可能，實作在44~47行
有點像樹狀圖，把所有可能計算出，然後用print function輸出

