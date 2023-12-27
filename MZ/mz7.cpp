#include<iostream>
#include<cmath>
#include<cstring>
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
		Vec operator*(double a)const;
		Vec operator=(const Vec& op);
		friend Vec operator*(double a,const Vec& op);
    	friend std::ostream& operator <<(std::ostream& os, const Vec& vec);
		bool operator==(const Vec& op)const;
		double& operator[](int i)const;
	private:
        double *v;
        int len;
};

class Exception{
        public:
			Exception(const Exception& other);
			Exception(const char* s,int a = 0, int b = 0);
			~Exception();
            const char* get_err(){return err_;}
			int get_int1(){return int1_;}
			int get_int2(){return int2_;}
        private:
            char* err_;
			int int1_,int2_;
};

Vec::Vec(int a, double *b){
        if(a < 0){
            throw Exception ("length error");
        }
	else{
		int i;
        	len = a;
        	v = new double[a];
        	for(i = 0;i < len;++i) v[i] = b[i];
	}
}
Vec::Vec(int a){
        if(a < 0){
            throw Exception ("length error");
        }
	else{
		int i;
        	len = a;
        	v = new double[a];
        	for(i = 0;i < len;i++) v[i] = 0;
	}
}
Vec::Vec(Vec &other){
	int i;
    len = other.len;
    v = new double[len];
    for(i = 0;i < len;++i) v[i] = (other.v)[i];
}
Vec::~Vec(){delete[] v;}
Exception::Exception(const Exception &other){
	int tmp = strlen(other.err_);
	err_ = new char[tmp];
	strcpy(err_,other.err_);
	int1_ = other.int1_;
	int2_ = other.int2_;
}
Exception::~Exception(){delete[] err_;}
int Vec::get_len()const{return this->len;}
void Vec::set(double arg, int coord){
	if((0<= coord) && (coord <len)) v[coord] = arg;
	else{
        throw Exception ("coordinate error in set()");
	}
}
Exception::Exception(const char* s,int a, int b){
	err_ = new char[strlen(s) + 1];
    std::memcpy(err_,s,strlen(s));
    err_[strlen(s)] = '\0';
	int1_ = a;
	int2_ = b;
}
double Vec::get(int coord)const{
	if((0 <= coord) && (coord < len)) return v[coord];
	else{
        throw Exception ("coordinate errror in get()");
	}
}
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
	if(this->len != op.len){
		throw Exception ("addition of vectors of different lengths: ",this->len,op.len);
	}
	else{
		int i;
		Vec tmp(len);
		for(i = 0;i < len;++i) tmp.v[i] = v[i] + op.v[i];
		return tmp;
	}
}
Vec Vec::operator-(const Vec& op)const{
        if(this->len != op.len){
            throw Exception ("addition of vectors of different lengths: ",this->len,op.len);
	}
	else{
		int i;
        	Vec tmp(len);
        	for(i = 0;i < len;++i) tmp.v[i] = v[i] - op.v[i];
        	return tmp;
	}
}
Vec Vec::operator*(double a)const{
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
        for(i = 0;i < len;++i) this->v[i] = op.get(i);
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
	if((0<= i) && (i <len)) return v[i];
	else{
		throw Exception ("incorrect indexing: ",i);
	}
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
    catch(Exception& err){
		const char* er = err.get_err();
		int tmp1 = err.get_int1(), tmp2 = err.get_int2();
		std::cerr << "Exception: ";
		if(!strcmp(er, "addition of vectors of different lengths: ")){
			std::cerr << "addition of vectors of different lengths: " << tmp1 << " " << tmp2 << std::endl;
		}
		else{
			if(!strcmp(er, "incorrect indexing: ")){
				std::cerr << "incorrect indexing: " << tmp1 << std::endl;
			}
			else{
				std::cerr << er << std::endl;
			}
		}	
    }
    catch(...){ std::cerr << "Exception: unknown error" << std::endl;}
    return 0;
}
