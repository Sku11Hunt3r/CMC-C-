#include<iostream>
#include<cmath>
class Vector_3d{
	private:
	double x;
	double y;
	double z;
	public:
	Vector_3d(double a, double b, double c){x = a;y = b;z = c;}
	Vector_3d(){x = 0;y = 0; z = 0;}
	Vector_3d(double a){x = a;y = 0; z = 0;}
	void print(){std::cout << '(' << x << ',' << y << ',' << z << ')' << std::endl;}
	double euc_norm(){return sqrt(x*x + y*y + z*z);}
	double max_norm(){
		double a = abs(x),b = abs(y), c = abs(z);
		if(a >= b){
			if(a >= c) return a;
			else return b;
		}
		else{
			if(b >= c) return b;
			else return c;
		}
	}
	double get_x(){return x;}
	double get_y(){return y;}
	double get_z(){return z;}
	void set(double a, double b, double c){x = a;y = b; z = c;}
};
