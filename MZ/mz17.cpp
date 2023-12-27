#include<iostream>
#include<string>
#include<stack>

void sum(std::stack<int>& st){
    int a,b;
    b = st.top();
    st.pop();
    a = st.top();
    st.pop();
    st.push(a+b);
}
void dif(std::stack<int>& st){
    int a,b;
    b = st.top();
    st.pop();
    a = st.top();
    st.pop();
    st.push(a-b);
}
void mul(std::stack<int>& st){
    int a,b;
    b = st.top();
    st.pop();
    a = st.top();
    st.pop();
    st.push(a*b);
}
void div(std::stack<int>& st){
    int a,b;
    b = st.top();
    st.pop();
    a = st.top();
    st.pop();
    st.push(a/b);
}
void un_min(std::stack<int>& st){
    int a;
    a = st.top();
    st.pop();
    st.push(-1 * a);
}

int main(){
    char c;
    std::string str = "";
    std::stack<int> st;
    while(1){
        c = std::cin.get();
        if(c == '\n') break;
        else if(c == '+') sum(st);
        else if(c == '-') dif(st);
        else if(c == '*') mul(st);
        else if(c == '/') div(st);
        else if(c == '@') un_min(st);
        else{
            if(c >= '0' && c <= '9') str += c;
            else{
                if(str != ""){
                    st.push(stoi(str));
                    str = "";
                }
            }
        }
    }
    std::cout << st.top() << std::endl;
    st.pop();
    return 0;
}