#include<iostream>
#include<cmath>
#include<cstring>
template<class T>
class Vec{
        public:
        	Vec(int a, T *b);
        	Vec(int a);
        	Vec(Vec &other);
        	~Vec();
        	void set(T arg, int coord);
        	T get(int coord)const;
        	T euc_norm();
        	T max_norm();
        	int get_len();
        	void print();
		Vec<T> operator+(const Vec<T>& op)const;
		template<typename V>
		friend Vec<V> operator+=(Vec<V>& op1,const Vec<V>& op2);
		Vec<T> operator-(const Vec<T>& op)const;
		Vec<T> operator*(T a)const;
		Vec<T> operator=(const Vec<T>& op);
		T operator^(const Vec<T>& op)const;
		template<typename V>
		friend Vec<V> operator*(V a,const Vec<V>& op);
		template<typename D>
        	friend std::ostream& operator <<(std::ostream& os, const Vec<D>& vec);
		bool operator==(const Vec& op)const;
		T& operator[](int i);
	private:
        	T* v;
        	int len;
};

class Exception{
        public:
		Exception(const char* s,int a = -1, int b = -1){
			err_ = new char[strlen(s) + 1];
                        std::memcpy(err_,s,strlen(s));
                        err_[strlen(s)] = '\0';
			int1_ = a;
			int2_ = b;
		}
                const char* get_err(){return err_;}
		int get_int1(){return int1_;}
		int get_int2(){return int2_;}
        private:
                char* err_;
		int int1_,int2_;
};
template<typename T>
Vec<T>::Vec(int a, T*b){
        if(a < 0){
                Exception er1("length error");
                throw er1;
        }
	else{
		int i;
        	len = a;
        	v = new T[a];
        	for(i = 0;i < len;++i) v[i] = b[i];
	}
}
template<typename T>
Vec<T>::Vec(int a){
        if(a < 0){
                Exception er2("length error");
                throw er2;
        }
	else{
		int i;
        	len = a;
        	v = new T[a];
        	for(i = 0;i < len;i++) v[i] = 0;
	}
}
template<typename T>
Vec<T>::Vec(Vec<T> &other){
	int i;
       	len = other.len;
       	v = new T[len];
       	for(i = 0;i < len;++i) v[i] = (other.v)[i];
}
template<typename T>
Vec<T>::~Vec(){delete[] v;}
template<typename T>
int Vec<T>::get_len(){return this->len;}
template<typename T>
void Vec<T>::set(T arg, int coord){
	if((0<= coord) && (coord <len)) v[coord] = arg;
	else{
                Exception er3("coordinate error in set()");
                throw er3;
	}
}
template<typename T>
T Vec<T>::get(int coord)const{
	if((0 <= coord) && (coord < len)) return v[coord];
	else{
		Exception er4("coordinate errror in get()");
                throw er4;
	}
}
template<typename T>
T Vec<T>::euc_norm(){
        T ans = 0;
        int i;
        for(i = 0;i < len;++i) ans += (v[i]*v[i]);
        return sqrt(ans);
}
template<typename T>
T Vec<T>::max_norm(){
        T max = 0;
        int i;
        for(i = 0;i < len;++i){
                if(max < abs(v[i])) max = abs(v[i]);
        }
        return max;
}
template<typename T>
void Vec<T>::print(){
        int i;
        std::cout << '(';
        for(i = 0;i < len;++i){
                std::cout << v[i];
                if(i < (len - 1)) std::cout << ',';
        }
        std::cout << ')' << std::endl;
}
template<typename T>
Vec<T> Vec<T>::operator+(const Vec<T>& op)const{
	if(this->len != op.len){
		Exception er5("addition of vectors of different lengths: ",this->len,op.len);
		throw er5;
	}
	else{
		int i;
		Vec<T> tmp(len);
		for(i = 0;i < len;++i) tmp.v[i] = v[i] + op.v[i];
		return tmp;
	}
}
template<typename T>
Vec<T> operator+=(Vec<T>& op1,const Vec<T>& op2){
        if(op1.len != op2.len){
                Exception er5("addition of vectors of different lengths: ",op1.len,op2.len);
                throw er5;
        }
        else{
                int i;
                for(i = 0;i < op1.len;++i) op1.v[i] += op2.v[i];
                return op1;
        }
}
template<typename T>
Vec<T> Vec<T>::operator-(const Vec<T>& op)const{
        if(this->len != op.len){
                Exception er6("addition of vectors of different lengths: ",this->len,op.len);
                throw er6;
	}
	else{
		int i;
        	Vec<T> tmp(len);
        	for(i = 0;i < len;++i) tmp.v[i] = v[i] - op.v[i];
        	return tmp;
	}
}
template<typename T>
Vec<T> Vec<T>::operator*(T a)const{
	int i;
       	Vec<T> tmp(len);
       	for(i = 0;i < len;++i) tmp.v[i] = v[i] * a;
       	return tmp;
}
template<typename T>
T Vec<T>::operator^(const Vec<T>& op)const{
        if(this->len != op.len){
                Exception er6("multiplication of vectors of different lengths: ",this->len,op.len);
                throw er6;
        }
	int i;
        T pr = 0;
        for(i = 0;i < len;++i) pr += v[i] * op.v[i];
        return pr;
}
template<typename T>
Vec<T> Vec<T>::operator=(const Vec& op){
        /*if(this->len != op.len){
                Exception er6("unknown error");
                throw er6;
        }*/
	int i;
	if(this->len != op.len){
	        delete[] this->v;
                this->len = op.len;
                this->v = new T[len];
        }
        for(i = 0;i < len;++i) this->v[i] = op.get(i);
	return *this;
}
template<typename T>
bool Vec<T>::operator==(const Vec<T>& op)const{
        /*if(this->len != op.len){
                Exception er6("unknown error");
                throw er6;
        }*/
	int i;
	bool ans = 1;
	if(len != op.len) return 0;
        for(i = 0;i < len;++i){
		if(v[i] != op.v[i]) ans = 0;
	}
	return ans;
}
template<typename T>
T& Vec<T>::operator[](int i){
	if((0<= i) && (i <len)) return v[i];
	else{
		Exception er7("incorrect indexing: ",i);
		throw er7;
	}
}
template<typename T>
std::ostream& operator<<(std::ostream &os,const Vec<T> &op){
	int i;
	os << "(";
	for(i = 0;i < op.len;++i){
		if(i < (op.len - 1)) os << op.get(i) << ",";
		else os << op.get(i) << ")";
	}
	return os;
}
template<typename T>
Vec<T> operator*(T a,const Vec<T>& op){
	int i;
        Vec<T> tmp(op.len);
        for(i = 0;i < op.len;++i) tmp.v[i] = op.v[i] * a;
        return tmp;
}
/*void Vector(){
	double wd[3] = {1.5,2.3,-1.7};
	double wd2[4] = {1.1,2.3,4.5,6.7};
        Vec<double>  vd1(3, wd), vd2(4, wd2);
        double i = vd1[4];
	vd2 += vd1;
	std::cout << "vd1 = " << vd1 << std::endl;
	std::cout << "vd2 = " << vd2 << std::endl;
        double prd = vd1^vd2;
	std::cout << "vd1^vd2 = " << prd << std::endl;
        vd2 = vd1 = vd1;
	std::cout << "vd2 = " << vd2 << std::endl;
}*/
int main(){
	try{
                Vector();
        }
        catch(Exception err){
		const char* er = err.get_err();
		int tmp1 = err.get_int1(), tmp2 = err.get_int2();
		std::cerr << "Exception: ";
		if(tmp1 == -1 && tmp2 == -1) std::cerr << er << std::endl;
		if(tmp1 != -1 && tmp2 == -1) std::cerr << er << tmp1 << std::endl;
		if(tmp1 != -1 && tmp2 != -1) std::cerr << er << tmp1 << " " << tmp2 <<std::endl;
        }
        catch(...){ std::cerr << "Exception: unknown error" << std::endl;}
        return 0;
}

