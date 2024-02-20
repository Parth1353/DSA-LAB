#include <iostream>
#include <stack>
using namespace std;

int cal(string s) {
    stack<int> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            st.push(s[i] - '0');
        } else {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if (s[i] == '+') {
                st.push(b + a);
            } else if (s[i] == '-') {
                st.push(b - a);
            } else if (s[i] == '*') {
                st.push(b * a);
            } else if (s[i] == '/') {
                st.push(b / a);
            }
            else
            {
                cout<<"wrong input"<<endl;
                return -1;
            }
        }
    }
    return st.top();
}

int main() {
    string s;
    getline(cin, s);
    cout << cal(s);
    return 0;
}
