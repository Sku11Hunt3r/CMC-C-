#include<iostream>

template<class T> class Set{
    public:
        Set(){len_ = max_len_ = 0;data_ = new T;}
        Set(T* data,int kol);
        Set(const Set<T>& other);
        ~Set(){delete[] data_;}
        void add(T a);
        void add(T* data,int kol);
        void del(T elem);
        bool in(T elem)const;
        void print()const;
        Set<T> operator+(const Set<T> a);
	    Set<T> operator*(const Set<T> a);
	    Set<T>& operator =(const Set<T>& a);
    private:
        int len_, max_len_;
        T* data_;
};
template<typename T>
Set<T>::Set(T* data, int kol){
	len_ = 0;
	max_len_ = 0;
    data_ = new T;
	for(int i = 0; i < kol; ++i){
		add(data[i]);
	}
}
template<typename T>
Set<T>::Set(const Set<T>& other){
    int i;
    len_ = other.len_;
    max_len_ = other.max_len_;
    data_ = new T[other.len_];
    for(i=0;i < other.len_;++i){
        data_[i] = other.data_[i];
    }
}
template<typename T>
void Set<T>::add(T a){
    if(in(a)) return;
    if(len_ == max_len_){
        int i;
        max_len_ = (max_len_ + 1) * 2;
        T* tmp = new T[max_len_];
        for(i = 0;i < max_len_/2;i++){
            tmp[i] = data_[i];
        }
        delete[] data_;
        data_ = new T[max_len_];
        for(i = 0;i < max_len_/2;i++){
            data_[i] = tmp[i];
        }
    }
    data_[len_] = a;
    ++len_;
}
template<typename T>
void Set<T>::add(T* elem, int len){
	for(int i = 0; i < len; i++){
		add(elem[i]);
	}
}
template<typename T>
void Set<T>::del(T elem){
	int pos = -1,i;
    for(i = 0;i < len_;i++){
        if(data_[i] == elem){
            pos = i;
            break;
        }
    }
    if(pos == -1) return;
    for(i = pos; i < len_ - 1; i++){
		data_[i] = data_[i+1];
	}
	len_--;
}
template<typename T>
bool Set<T>::in(T elem)const{
    int i;
    for(i = 0;i < len_;i++){
        if(data_[i] == elem) return true;
    }
    return false;
}
template<typename T>
void Set<T>::print()const{
    for(int i = 0;i < len_;i++){
        for(int j = i;j < len_;j++){
            if(data_[i] > data_[j]){
                T tmp;
                tmp = data_[i];
                data_[i] = data_[j];
                data_[j] = tmp; 
            }
        }
    }
    for(int i = 0;i < len_;i++){
        std::cout << data_[i];
        if(i < len_ - 1) std::cout << ' ';
    }
    std::cout << std::endl;
}
template<typename T>
Set<T> Set<T>::operator+(const Set<T> a){
	Set<T> tmp(data_, len_);
	for(int i = 0;i < a.len_; ++i){
		tmp.add(a.data_[i]);
	}
	return tmp;
}
template<typename T>
Set<T> Set<T>::operator*(const Set<T> a){
	Set<T> tmp;
	for(int i = 0;i < len_; ++i){
		if(a.in(data_[i])) tmp.add(data_[i]);
	}
	return tmp;
}
template<typename T>
Set<T>& Set<T>::operator =(const Set<T>& a){
	delete[] data_;
	int i;
    len_ = a.len_;
    max_len_ = a.max_len_;
    data_ = new T[a.len_];
    for(i=0;i < a.len_;++i){
        data_[i] = a.data_[i];
    }
	return *this;
}