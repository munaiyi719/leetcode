# 题意
给定一个字符串，询问是否可以分解为3个回复的字串

# 解法
n的大小只有2000，可以n^2的求解
最简单的做法就是枚举中间字符串的左右端点
此外要预处理出一个区间是否是回文串
由于可以n^2，所以不用马拉车，直接暴力就可以