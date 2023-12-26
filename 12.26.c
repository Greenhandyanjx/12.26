#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int max(int a, int b)
{
    return a > b ? a : b;
}
int maxProfit(int* prices, int pricesSize) {
    int dp[pricesSize][2];//0表示持有股票的最大利润，1表示不持有股票的最大利润
    int i, j;
    dp[0][0] = -prices[0];//第0天表示持有股票
    dp[0][1] = 0;//不持有股票
    for (i = 1; i < pricesSize; i++) {
        dp[i][0] = max(dp[i - 1][0], -prices[i]);//当前持有股票是与前一天和当天股票价格最小决定
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    return dp[pricesSize - 1][1];
}
int main()
{
    int arr[5] = { 1,2,5,7,2 };
    printf("%d", maxProfit(arr, 5));
	return 0;
}
//int lengthOfLastWord(char* s) {
//    char str[100][10000] = { "" };
//    int a = 0, b = 0, c = 0;
//    while (s[a])
//    {
//        c = 0;
//        while (isalpha(s[a]))
//        {
//            str[b][c++] = s[a++];
//            if (isspace(s[a]))
//            {
//                b++;
//                break;
//            }
//        }
//        a++;
//    }
//    return strlen(str[b - 1]);
//}