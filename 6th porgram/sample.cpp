#include <iostream>
#include <stack>
using namespace std;
void evaluvatepostfix(string &s, stack<int>& st) {
string temp = "";
for (int j = 0; j < s.size(); j++) {
char i = s[j];
if (i == '$') {
int a = st.top();
st.pop();
int b = st.top();
st.pop();
int c = pow(b, a);
st.push(c);
} else if (i == '+') {
int a = st.top();
st.pop();
int b = st.top();
st.pop();
int c = a + b;
st.push(c);
} else if (i == '-') {
int a = st.top();
st.pop();
int b = st.top();
st.pop();
int c = b - a;
st.push(c);
} else if (i == '*') {
int a = st.top();
st.pop();
int b = st.top();
st.pop();
int c = b * a;
st.push(c);
} else if (i == '/') {
int a = st.top();
st.pop();
int b = st.top();
st.pop();
int c = b / a;
st.push(c);
} else if (isdigit(i)) {
temp = "";
while (isdigit(s[j])) {
temp += s[j];
j++;
}
j--;
int a = stoi(temp);
st.push(a);
}
}
}
int main(){
string s="2 3$5 2 2 $*+12 6/-";
stack<int>st;
evaluvatepostfix(s,st);
cout<<st.top();
 
}
