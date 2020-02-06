# 初步思路
1. 类似P1030,采用List插入所有数据，按key=distance排序。

# 测试后调整思路
1. 和P1030不同，需要用到Double.compare(double,double)的Comparator。

# 看题解后的改进思路
1. 采用Array排序
2. 无需开方
3. 直接快排

# 知识点
1. Double.compare把Double转换成LongBits，然后比较，输出int。