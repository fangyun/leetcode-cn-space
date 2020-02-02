**思路**

我们可以将最大的元素（在位置 i，下标从 1 开始）进行煎饼翻转 i 操作将它移动到序列的最前面，然后再使用煎饼翻转 A.length 操作将它移动到序列的最后面。 此时，最大的元素已经移动到正确的位置上了，所以之后我们就不需要再使用 k 值大于等于 A.length 的煎饼翻转操作了。

我们可以重复这个过程直到序列被排好序为止。 每一步，我们只需要花费两次煎饼翻转操作。

* 作者：LeetCode
* 链接：https://leetcode-cn.com/problems/pancake-sorting/solution/jian-bing-pai-xu-by-leetcode/
* 来源：力扣（LeetCode）
* 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。