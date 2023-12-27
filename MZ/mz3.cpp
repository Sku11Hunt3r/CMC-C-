#include<iostream>
#include<cmath>
class Vec{
	public:
	Vec(int a, double *b);
	Vec(int a);
	Vec(const Vec &other);
	~Vec();
	void set(double arg, int coord);
	double get(int coord);
	double euc_norm();
	double max_norm();
	void print();
	private:
	double *v;
	int len;
};

Vec::Vec(int a, double *b){
	int i;
	len = a;
	v = new double[a];
	for(i = 0;i < len;++i) v[i] = b[i];
}
Vec::Vec(int a){
        int i;
        len = a;
        v = new double[a];
        for(i = 0;i < len;i++) v[i] = 0;
}
Vec::Vec(const Vec &other){
        int i;
        len = other.len;
	v = new double[len];
        for(i = 0;i < len;++i) v[i] = (other.v)[i];
}
Vec::~Vec(){delete[] v;}
void Vec::set(double arg, int coord){
	if(coord >= 0 and coord < len) v[coord] = arg;
}
double Vec::get(int coord){
	if(coord >= 0 and coord < len) return v[coord];
	else return 0;
}
double Vec::euc_norm(){
        double ans = 0;
	int i;
	for(i = 0;i < len;++i) ans += v[i] * v[i];
	return sqrt(ans);
}
double Vec::max_norm(){
	double max = 0;
	int i;
	for(i = 0;i < len;++i){
		if(max < abs(v[i])) max = abs(v[i]);
	}
	return max;
}
void Vec::print(){
	int i;
	std::cout << '(';
	for(i = 0;i < len;++i){
		std::cout << v[i];
		if(i < (len - 1)) std::cout << ',';
	}
	std::cout << ')' << std::endl;
}

