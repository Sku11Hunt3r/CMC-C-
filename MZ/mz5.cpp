#include<iostream>
#include<cmath>
class Vec{
        public:
        Vec(int a, double *b);
        Vec(int a);
        Vec(Vec &other);
        ~Vec();
        void set(double arg, int coord);
        double get(int coord)const;
        double euc_norm()const;
        double max_norm()const;
        int get_len()const;
        void print()const;
	Vec operator+(const Vec& op)const;
	Vec operator-(const Vec& op)const;
	const Vec operator*(double a)const;
	Vec operator=(const Vec& op);
	friend Vec operator*(double a,const Vec& op);
        friend std::ostream& operator <<(std::ostream& os, const Vec& vec);
	bool operator==(const Vec& op)const;
	double& operator[](int i)const;
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
Vec::Vec(Vec &other){
        int i;
        len = other.len;
        v = new double[len];
        for(i = 0;i < len;++i) v[i] = (other.v)[i];
}
Vec::~Vec(){delete[] v;}
int Vec::get_len()const{return this->len;}
void Vec::set(double arg, int coord){v[coord] = arg;}
double Vec::get(int coord)const{return v[coord];}
double Vec::euc_norm()const{
        double ans = 0;
        int i;
        for(i = 0;i < len;++i) ans += (v[i]*v[i]);
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
Vec Vec::operator+(const Vec& op)const{
	int i;
	Vec tmp(len);
	for(i = 0;i < len;++i) tmp.v[i] = v[i] + op.v[i];
	return tmp;
}
Vec Vec::operator-(const Vec& op)const{
        int i;
        Vec tmp(len);
        for(i = 0;i < len;++i) tmp.v[i] = v[i] - op.v[i];
        return tmp;
}
const Vec Vec::operator*(double a)const{
	int i;
        Vec tmp(len);
        for(i = 0;i < len;++i) tmp.v[i] = v[i] * a;
        return tmp;
}
Vec Vec::operator=(const Vec& op){
        int i;
	if(this->len != op.len){
	        delete[] this->v;
                this->len = op.len;
                this->v = new double[len];
        }
        for(i = 0;i < len;++i) this->v[i] = op.get(i);//std::cout << op.v[i] << " ";}
	return *this;
}
bool Vec::operator==(const Vec& op)const{
        int i;
	bool ans = 1;
	if(len != op.len) return 0;
        for(i = 0;i < len;++i){
		if(v[i] != op.v[i]) ans = 0;	
	}
	return ans;
}
double& Vec::operator[](int i)const{
        return v[i];
}
std::ostream& operator<<(std::ostream &os,const Vec &op){
	int i;
	os << "(";
	for(i = 0;i < op.len;++i){
		if(i < (op.len - 1)) os << op.get(i) << ",";
		else os << op.get(i) << ")";
	}
	return os;
}
Vec operator*(double a,const Vec& op){
	int i;
        Vec tmp(op.len);
        for(i = 0;i < op.len;++i) tmp.v[i] = op.v[i] * a;
        return tmp;
}
/*int main()
{
        double y1[4] = {1,2,3,4};
        double y2[4] = {-2,1,3,-3};
	double y3[6] = {1,2,3,34,5,6};
        Vec u(4, y1), v(4, y2);
        Vec w(4),b(3);
	Vec a(6,y3);
	std::cout << "u = " << u << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "v = " << v << std::endl;
	std::cout << "a = " << a << std::endl;
        b = a = a = a = a;
	std::cout << "b = " << b << std::endl;
	std::cout << "a = " << a << std::endl;
	w = u = u;
	std::cout << "w = u = " << w << std::endl;
        w = 4.*u + v*3;
	std::cout << "w = 4.*u + v*3 = " << w << std::endl;
        w[2] = 3;
        w[0] = -1;
	std::cout << "w = " << w << std::endl;

        return 0;
}*/