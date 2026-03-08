class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Use long long or int to store the actual numerical values
        stack<long long> st; 

        for (string& s : tokens) {
            // Check if the token is an operator
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                long long second = st.top(); st.pop();
                long long first = st.top(); st.pop();

                if (s == "+") st.push(first + second);
                else if (s == "-") st.push(first - second);
                else if (s == "*") st.push(first * second);
                else if (s == "/") st.push(first / second);
            } 
            else {
                // Convert string "123" to integer 123
                st.push(stoll(s)); 
            }
        }

        return (int)st.top();
    }
};