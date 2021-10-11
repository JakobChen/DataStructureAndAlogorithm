/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/





class Solution {
private:
    stack<char> str_stack;
public:
    bool isValid(string s) {
        for(int i=0; i<s.size();i++){
            if(s[i]=='(' | s[i]=='['|s[i]=='{'){
                str_stack.push(s[i]);
            }else{
                if(str_stack.empty()){
                    return false;
                }
                if( (s[i] == ')'&& str_stack.top()=='(') || \
                    (s[i] == ']'&& str_stack.top()=='[') || \
                    (s[i] == '}'&& str_stack.top()=='{') ){
                        str_stack.pop();
                }else{
                    return false;
                }
            }    
        }
        return str_stack.empty();
    }
};