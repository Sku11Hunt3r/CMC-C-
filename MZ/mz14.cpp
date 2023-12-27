#include <iostream>
enum {A,B,C,D,E,F,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,AA,AB,AC,AD,AE,AF};
int Parser(){
        int CS = AA;
        int dig = 0;
        char c;
        c = std::cin.get();
        do{
            switch(CS){
                case AA:
                    if(c == '.'){
                        c = std::cin.get();
                        CS = A;
                    }
                    else if(c == '-'){
                        c = std::cin.get();
                    	CS = Q;
                    }
					else if(c == '\n'){
						return dig;
					}
                    else throw c;
                    break;
				case A:
                    if(c == '.'){
                        c = std::cin.get();
                        CS = B;
                    }
                    else if(c == '-'){
                        c = std::cin.get();
                    	CS = C;
                    }
                    else throw c;
                    break;
				case B:
                    if(c == '.'){
                        c = std::cin.get();
                        CS = K;
                    }
                    else if(c == '-'){
                        c = std::cin.get();
                    	CS = H;
                    }
                    else throw c;
                    break;
				case C:
                    if(c == '-'){
                        c = std::cin.get();
                    	CS = D;
                    }
                    else throw c;
                    break;
				case D:
                    if(c == '-'){
                        c = std::cin.get();
                    	CS = E;
                    }
                    else throw c;
                    break;
				case E:
                   if(c == '-'){
                        c = std::cin.get();
                    	CS = F;
                    }
                    else throw c;
                    break;
				case F:
                	if(c == ' '){
                        c = std::cin.get();
                    	CS = AA;
						dig *=10;
						dig += 1;
                    }
					else if(c == '\n'){
						dig *=10;
						dig += 1;
						return dig;
                    }
                    else throw c;
                    break;
				case H:
                    if(c == '-'){
                        c = std::cin.get();
                    	CS = I;
                    }
                    else throw c;
                    break;
				case I:
                	if(c == '-'){
                        c = std::cin.get();
                    	CS = J;
                    }
                    else throw c;
                    break;
				case J:
                    if(c == ' '){
                        c = std::cin.get();
                    	CS = AA;
						dig *=10;
						dig += 2;
                    }
					else if(c == '\n'){
						dig *=10;
						dig += 2;
						return dig;
                    }
                    else throw c;
                    break;
				case K:
                    if(c == '.'){
                        c = std::cin.get();
                        CS = N;
                    }
                    else if(c == '-'){
                        c = std::cin.get();
                    	CS = L;
                    }
                    else throw c;
                    break;
				case L:
                    if(c == '-'){
                        c = std::cin.get();
                    	CS = M;
                    }
                    else throw c;
                    break;
				case M:
                    if(c == ' '){
                        c = std::cin.get();
                    	CS = AA;
						dig *=10;
						dig += 3;
                    }
					else if(c == '\n'){
						dig *=10;
						dig += 3;
						return dig;
                    }
                    else throw c;
                    break;
				case N:
                    if(c == '.'){
                        c = std::cin.get();
                        CS = P;
                    }
                    else if(c == '-'){
                        c = std::cin.get();
                    	CS = O;
                    }
                    else throw c;
                    break;
				case O:
                    if(c == ' '){
                        c = std::cin.get();
                    	CS = AA;
						dig *=10;
						dig += 4;
                    }
					else if(c == '\n'){
						dig *=10;
						dig += 4;
						return dig;
                    }
                    else throw c;
                    break;
				case P:
                    if(c == ' '){
                        c = std::cin.get();
                    	CS = AA;
						dig *=10;
						dig += 5;
                    }
					else if(c == '\n'){
						dig *=10;
						dig += 5;
						return dig;
                    }
                    else throw c;
                    break;
				case Q:
                    if(c == '.'){
                        c = std::cin.get();
                        CS = R;
                    }
                    else if(c == '-'){
                        c = std::cin.get();
                    	CS = V;
                    }
                    else throw c;
                    break;
				case V:
                    if(c == '.'){
                        c = std::cin.get();
                        CS = W;
                    }
                    else if(c == '-'){
                        c = std::cin.get();
                    	CS = Z;
                    }
                    else throw c;
                    break;
				case R:
                    if(c == '.'){
                        c = std::cin.get();
                    	CS = S;
                    }
                    else throw c;
                    break;
				case S:
                    if(c == '.'){
                        c = std::cin.get();
                    	CS = T;
                    }
                    else throw c;
                    break;
				case T:
                   if(c == '.'){
                        c = std::cin.get();
                    	CS = U;
                    }
                    else throw c;
                    break;
				case U:
                	if(c == ' '){
                        c = std::cin.get();
                    	CS = AA;
						dig *=10;
						dig += 6;
                    }
					else if(c == '\n'){
						dig *=10;
						dig += 6;
						return dig;
                    }
                    else throw c;
                    break;
				case W:
                    if(c == '.'){
                        c = std::cin.get();
                    	CS = X;
                    }
                    else throw c;
                    break;
				case X:
                	if(c == '.'){
                        c = std::cin.get();
                    	CS = Y;
                    }
                    else throw c;
                    break;
				case Y:
                    if(c == ' '){
                        c = std::cin.get();
                    	CS = AA;
						dig *=10;
						dig += 7;
                    }
					else if(c == '\n'){
						dig *=10;
						dig += 7;
						return dig;
                    }
                    else throw c;
                    break;
				case Z:
                    if(c == '.'){
                        c = std::cin.get();
                        CS = AB;
                    }
                    else if(c == '-'){
                        c = std::cin.get();
                    	CS = AD;
                    }
                    else throw c;
                    break;
				case AB:
                    if(c == '.'){
                        c = std::cin.get();
                    	CS = AC;
                    }
                    else throw c;
                    break;
				case AC:
                    if(c == ' '){
                        c = std::cin.get();
                    	CS = AA;
						dig *=10;
						dig += 8;
                    }
					else if(c == '\n'){
						dig *=10;
						dig += 8;
						return dig;
                    }
                    else throw c;
                    break;
				case AD:
                    if(c == '.'){
                        c = std::cin.get();
                        CS = AE;
                    }
                    else if(c == '-'){
                        c = std::cin.get();
                    	CS = AF;
                    }
                    else throw c;
                    break;
				case AE:
                    if(c == ' '){
                        c = std::cin.get();
                    	CS = AA;
						dig *=10;
						dig += 9;
                    }
					else if(c == '\n'){
						dig *=10;
						dig += 9;
						return dig;
                    }
                    else throw c;
                    break;
				case AF:
                    if(c == ' '){
                        c = std::cin.get();
                    	CS = AA;
						dig *=10;
                    }
					else if(c == '\n'){
						dig *=10;
						return dig;
                    }
                    else throw c;
                    break;	
            }
        }
        while(1);
}
int main(){
	try{
		int s; 
		s = Parser();
		std::cout << s << std::endl;
	}
	catch(char c){
		std::cerr << "Error in Lexcem: " << c << std::endl;
	}
	return 0;
}