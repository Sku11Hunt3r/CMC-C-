#include<iostream>

class Rect{
	public:
		Rect(int a, int b, unsigned int c, unsigned int d){x = a;y = b;wd = c;hd = d;}
		Rect(){x = 0;y = 0;wd = 1;hd = 1;}
		Rect(unsigned int a){x = 0;y = 0;wd = a;hd = a;}
		void print_corner(){
			std::cout << '(' << x << ',' << y << ')' << std::endl;
		}
		void print_sz(){
			std::cout << "wd=" << wd << " hd=" << hd << std::endl;
		}
		int area(){return wd*hd;}
		int perimeter(){return (2*(wd+hd));}
		bool intersect(Rect r);
	private:
		int x;
		int y;
		unsigned int wd;
		unsigned int hd;
};
bool Rect::intersect(Rect r){
        bool ans = 0;
        int pos1[4];
        int pos2[4];
        pos1[0] = x;pos1[2] = y;pos1[1] = x+wd;pos1[3] = y+hd;
        pos2[0] = r.x;pos2[1] = r.x+r.wd;pos2[2] = r.y;pos2[3] = r.y+r.hd;
	//std::cout << pos1[0] << " " << pos1[1] << " "  << pos1[2] << " " << pos1[3] << std::endl;
	//std::cout << pos2[0] << " " << pos2[1] << " "  << pos2[2] << " " << pos2[3] << std::endl;
	if(pos2[0] >= pos1[0] && pos2[0] <= pos1[1]){
                if(pos1[2] <= pos2[2] && pos2[2] <= pos1[3]){ans = 1;}
        	if(pos1[2] <= pos2[3] && pos2[3] <= pos1[3]){ans = 1;}
	}
	if(pos2[1] >= pos1[0] && pos2[1] <= pos1[1]){
                if(pos1[2] <= pos2[2] && pos2[2] <= pos1[3]){ans = 1;}
                if(pos1[2] <= pos2[3] && pos2[3] <= pos1[3]){ans = 1;}
        }
        if(pos1[0] >= pos2[0] && pos1[0] <= pos2[1]){
                if(pos2[2] <= pos1[2] && pos1[2] <= pos2[3]){ans = 1;}
                if(pos2[2] <= pos1[3] && pos1[3] <= pos2[3]){ans = 1;}
        }
        if(pos1[1] >= pos2[0] && pos1[1] <= pos2[1]){
                if(pos2[2] <= pos1[2] && pos1[2] <= pos2[3]){ans = 1;}
                if(pos2[2] <= pos1[3] && pos1[3] <= pos2[3]){ans = 1;}
        }
	return ans;
}
