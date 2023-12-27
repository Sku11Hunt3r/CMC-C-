#include<iostream>
#include<cmath>
class Vec{
	public:
	Vec(int a, double *b);
	Vec(int a);
	Vec(const Vec &other);
	~Vec();
	void set(double arg, int coord);
	double get(int coord)const;
	double euc_norm()const;
	double max_norm()const;
	void print()const;
	private:
	double *v;
	int len;
};
class Exception{
	public:
		Exception(int a){a_ = a;}
		int get_a()const{return a_;}
	private:
		int a_;
};
Vec::Vec(int a, double *b){
	int i;
	len = a;
	if(a < 0){
		Exception er1(1);
		throw er1;
	}
	else{
		v = new double[a];
		for(i = 0;i < len;++i) v[i] = b[i];
	}
}
Vec::Vec(int a){
        int i;
	if(a < 0){
		Exception er2(1);
		throw er2;
	}
	else{
		len = a;
       		v = new double[a];
       		for(i = 0;i < len;i++) v[i] = 0;
	}
}
Vec::Vec(const Vec &other){
        int i;
        len = other.len;
	v = new double[len];
        for(i = 0;i < len;++i) v[i] = (other.v)[i];
}
Vec::~Vec(){delete[] v;}
void Vec::set(double arg, int coord){
	if((coord >= 0) && (coord < len)) v[coord] = arg;
	else{
		Exception er3(2);
                throw er3;
	}
}
double Vec::get(int coord)const{
	if((coord >= 0) && (coord < len)) return v[coord];
	else{
		Exception er4(3);
                throw er4;
	}
}
double Vec::euc_norm()const{
        double ans = 0;
	int i;
	for(i = 0;i < len;++i) ans += v[i] * v[i];
	return sqrt(ans);
}
double Vec::max_norm()const{
	double max = 0;
	int i;
	for(i = 0;i < len;++i){
		if(max < abs(v[i])) max = abs(v[i]);
	}
	return max;
}
void Vec::print()const{
	int i;
	std::cout << '(';
	for(i = 0;i < len;++i){
		std::cout << v[i];
		if(i < (len - 1)) std::cout << ',';
	}
	std::cout << ')' << std::endl;
}
/*void error()
{
	    double y1[3] = {1,2,3};
	        double y2[5] = {2,1,0,5,7};
		    Vec x(-3, y1), y(5, y2), z(4);
		        Vec u = x;
			    y.print();
			        x.print();
				    z.print();
				        u.print();
}*/
int main(){
	try{
		error();
	}
	catch(Exception err){
		int er = err.get_a();
		if(er == 1) std::cerr << "Exception: length error" << std::endl;
		if(er == 3) std::cerr << "Exception: coordinate error in get()" << std::endl;
		if(er == 2) std::cerr << "Exception: coordinate error in set()" << std::endl;
	}
	catch(...){ std::cerr << "Exception: unknown error" << std::endl;}
	return 0;
}