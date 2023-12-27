#include<iostream>
#include<string.h>
class Flower{
    enum{WH = 0};
    enum{PI = 1};
	public:
		Flower();
		Flower(const char* str,int k);
		~Flower(){if(col) --kol_pi;
			else --kol_wh;
		}
		void static Print_flowers(){
			std::cout << "White: " << kol_wh << " Pink: " << kol_pi << std::endl;
		}
	private:
		static int kol_wh,kol_pi;
		int kol;
		bool col;//wh  = 0,pi = 1
};
int Flower::kol_wh = 0;
int Flower::kol_pi = 0;
Flower::Flower(){
	kol = 10;
	if(kol_wh < kol_pi){
		col = WH;
		++kol_wh;
	}
	else{
		if(kol_wh > kol_pi){
			col = PI;
			++kol_pi;
		}
		else{
			col = PI;
			++kol_pi;
		}
	}
}
Flower::Flower(const char* str,int k = 10){
        if(!strcmp(str,"white")){
		col = WH;
		++kol_wh;
	}
	else{
		if(!strcmp(str,"pink")){
			col = PI;
			++kol_pi;
		}
		else{
			if(kol_wh < kol_pi){
                		col = WH;
                		++kol_wh;
        		}
        		else{
                		if(kol_wh > kol_pi){
                        		col = PI;
                        		++kol_pi;
                		}
                		else{
                        		if(k%2 == 0){
						col = PI;
                        			++kol_pi;
					}
					else{
						col = WH;
						++kol_wh;
					}
                		}
			}
		}
        }
}
/*int main()
{
       Flower fl1("white", 3);
       Flower fl2("pink", 5);
       Flower fl3("white", 7);
       Flower::Print_flowers();
       Flower fl4("green");
       Flower::Print_flowers();
       Flower fl5("blue", 17);
       Flower::Print_flowers();
       Flower fl6;
       Flower::Print_flowers();
       Flower fl7;
       Flower::Print_flowers();
       return 0;
}*/