# 题意
有n种糖，每种糖有candiesCount个数量
现在从第0天开始吃糖，每天最少吃一个，如果要吃第i种类型的糖，必须吃完i-1类型的糖
有m个询问，回答第favoriteDay天是否可以吃到第favoriteType，而且每天最多吃dailyCap个糖

# 解法
因为可以随便吃，只要保证我每天吃一个糖，不会吃完特定类型的后面，此外保证我每天吃最多的糖，能吃到特定类型的糖即可