#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
class Figure{
    public:
        Figure(char t = 'K', int x = 1, int y = 1){x1_ = x;y1_ = y;type_ = t;}
        Figure(const Figure& other) {type_ = other.type_; x1_ = other.x1_; y1_ = other.y1_;}
        virtual ~Figure(){}
        virtual bool move(int x2, int y2)const = 0;
        void set_coord(int x1,int y1){x1_ = x1;y1_ = y1;}
        void set_type(char c){type_ = c;}
        bool right_coord(int x1,int y1)const{return x1>=1 && x1<=8 && y1>=1 && y1<=8;}
    protected:
        int x1_,y1_;
    private:
        char type_;
};
class King : public Figure{
    public:
        King(int x1 = 1, int y1 = 1){x1_ = x1;y1_ = y1;set_type('K');}
        virtual ~King(){}
        bool move(int x2,int y2)const{
            return right_coord(x1_,y1_) && right_coord(x2,y2) && abs(x1_-x2) <= 1 && abs(y1_-y2) <= 1;
        }
};
class Queen : public Figure{
    public:
        Queen(int x1 = 1, int y1 = 1){x1_ = x1;y1_ = y1;set_type('Q');}
        virtual ~Queen(){}
        bool move(int x2,int y2)const{
            return right_coord(x1_,y1_) && right_coord(x2,y2) && ((abs(x1_-x2) == abs(y1_-y2)) || (x1_-x2 == 0) || (y1_-y2 == 0));
        }
};
class Knight : public Figure{
    public:
        Knight(int x1 = 1, int y1 = 1){x1_ = x1;y1_ = y1;set_type('N');}
        virtual ~Knight(){}
        bool move(int x2,int y2)const{
            return right_coord(x1_,y1_) && right_coord(x2,y2) && ((x1_-x2)*(x1_-x2) + (y1_-y2)*(y1_-y2) == 5);
        }
};
class Bishop : public Figure{
    public:
        Bishop(int x1 = 1, int y1 = 1){x1_ = x1;y1_ = y1;set_type('B');}
        virtual ~Bishop(){}
        bool move(int x2,int y2)const{
            return right_coord(x1_,y1_) && right_coord(x2,y2) && (abs(x1_-x2) == abs(y1_-y2));
        }
};
class Rook : public Figure{
    public:
        Rook(int x1 = 1, int y1 = 1){x1_ = x1;y1_ = y1;set_type('R');}
        virtual ~Rook(){}
        bool move(int x2,int y2)const{
            return right_coord(x1_,y1_) && right_coord(x2,y2) && ((x1_-x2 == 0) || (y1_-y2 == 0));
        }
};
class Parser{
    public:
        Parser(std::string str);
        char get_type(){return type_;}
        int get_x1(){return x1_;}
        int get_y1(){return y1_;}
        int get_x2(){return x2_;}
        int get_y2(){return y2_;}
    private:
        int x1_,y1_,x2_,y2_;
        char type_;
};
Parser::Parser(std::string str){
    type_ = str[0];
    x1_ = str[2] - 'a' + 1;
    y1_ = str[3] - '0';
    x2_ = str[5] - 'a' + 1;
    y2_ = str[6] - '0';
}
class ChessChecker{
    public:
        ChessChecker();
        ~ChessChecker();
        bool analyze();
    private:
        Figure** figures;
};
ChessChecker :: ChessChecker(){
    figures = new Figure*[5];
    figures[0] = new King();
    figures[1] = new Queen();
    figures[2] = new Knight();
    figures[3] = new Bishop();
    figures[4] = new Rook();
}
ChessChecker :: ~ChessChecker(){
    for(int i = 0;i < 5;i++) delete figures[i];
    delete[] figures;
}
bool ChessChecker :: analyze(){
    char tmp;
    int x1,y1,x2,y2;
    std::string str;
    std::getline(std::cin,str);
    Parser p(str);
    tmp = p.get_type();
    x1 = p.get_x1();
    x2 = p.get_x2();
    y1 = p.get_y1();
    y2 = p.get_y2();
    switch(tmp){
        case 'K':
            figures[0]->set_coord(x1,y1);
            return figures[0]->move(x2,y2);
        case 'Q':
            figures[1]->set_coord(x1,y1);
            return figures[1]->move(x2,y2);
        case 'N':
            figures[2]->set_coord(x1,y1);
            return figures[2]->move(x2,y2);
        case 'B':
            figures[3]->set_coord(x1,y1);
            return figures[3]->move(x2,y2);
        case 'R':
            figures[4]->set_coord(x1,y1);
            return figures[4]->move(x2,y2);
        default:
            std::cerr << "Wrong figure" << std::endl;
            return false;
    }
}
int main(){
    ChessChecker check;
	if(check.analyze()) std::cout << "YES" << std::endl;
	else std::cout << "NO" << std::endl;
    return 0;
}