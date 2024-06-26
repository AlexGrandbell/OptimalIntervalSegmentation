//游艇租用问题
//问题描述
//长江游艇俱乐部在长江上设置了n个游艇出租站1，2，…，n。游客可在这些游艇出租站租用游艇，并在下游的任何一个游艇出租站归还游艇。游艇出租站i到游艇出租站j之间的租金为r(i,j),1£i<j£n。试设计一个算法，计算出从游艇出租站1到游艇出租站n所需的最少租金。
//
//编程任务
//对于给定的游艇出租站i到游艇出租站j之间的租金为r(i,j),1£i<j£n，编程计算从游艇出租站1到游艇出租站n所需的最少租金。
//
//数据输入
//第1行中有1个正整数n（n<=200），表示有n个游艇出租站。接下来的n-1行是r(i,j),1£i<j£n。
//例如：
//3
//5 15
//7
//第一行：表示一共有3个出租站点
//第二行：第1个站点到第2个的租金为5，第1个站点到第3个的租金为15
//第三行：第2个站点到第3个的租金为7
//
//结果输出
//程序运行结束时，输出从游艇出租站1到游艇出租站n所需的最少租金。
//
//输入示例
//3
//5 15
//7
//
//输出示例
//12
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;//站点数
    cin >> n;
    //r[i][j]表示从i到j的票面租金
    vector<vector<int>> r(n+1, vector<int>(n+1, -1));
    //dp[i]表示从1到i的最小租金
    vector<int> dp(n+1, 0);

    //输入
    for (int i = 1; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            cin >> r[i][j];
        }
    }
    //初始化
    for (int i = 2; i <= n; i++) {
        dp[i] = r[1][i];
    }
    //动态规划
    for (int i = 3; i <= n; i++) {
        for (int j = 2; j < i; j++) {
            dp[i] = min(dp[i], dp[j] + r[j][i]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
