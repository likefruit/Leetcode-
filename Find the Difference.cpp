解法一：

复制代码
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> m;
        for (char c : s) ++m[c];
        for (char c : t) {
            if (--m[c] < 0) return c;
        }
        return 0;
    }
};
复制代码
 

我们也可以使用位操作Bit Manipulation来做，利用异或的性质，相同位返回0，这样相同的字符都抵消了，剩下的就是后加的那个字符，参见代码如下：

 

解法二：

复制代码
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for (char c : s) res ^= c;
        for (char c : t) res ^= c;
        return res;
    }
};
复制代码
 

我们也可以直接用加和减，相同的字符一减一加也抵消了，剩下的就是后加的那个字符，参见代码如下：

 

解法三：

复制代码
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for (char c : s) res -= c;
        for (char c : t) res += c;
        return res;
    }
};
复制代码
 

下面这种方法是史蒂芬大神提出来的，利用了STL的accumulate函数，实际上是上面解法二的改写，一行就写完了真是丧心病狂啊，参见代码如下：

 

解法四：

class Solution {
public:
    char findTheDifference(string s, string t) {
        return accumulate(begin(s), end(s += t), 0, bit_xor<int>());
    }
};
