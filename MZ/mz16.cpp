#include<iostream>
#include<string>
char S(std::string &s);
char A(char c, std::string &s);

char S(std::string &s){
    char c = std::cin.get(),tmp;
    if(c == 'a'){
        c = std::cin.get();
        s += "2";
        tmp = A(c, s);
        s += "a";
    }
    else if(c == 'b'){
        c = std::cin.get();
        tmp = A(c, s);
        s += "b";
    }
    else throw c;
    return tmp;
}
char A(char c, std::string &s){
    char tmp,ch;
    if(c == 'a'){
        ch = std::cin.get();
        s += "2";
        tmp = A(ch, s);
        s += "a";
    }
    else if(c == 'b'){
        ch = std::cin.get();
        tmp = A(ch, s);
        s += "b";
    } else tmp=c;
    return tmp;
}

int main(){
    try{
        std::string s = "";
        char c;
        c = S(s);
        if(c != '\n') throw c;
        std::cout << s << std::endl;
    }
    catch(char er){
        std::cerr << "Error in: " << er << std::endl;
    }
    return 0;
}