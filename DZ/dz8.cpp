#include<iostream>
#include<vector>
#include<cstring>
class Matrix{
    public:
        //Matrix(){n_=m_=0;data_ = nullptr;}
        Matrix(int n, int m, int* data){
			data_ = std::vector<int>(n*m);n_ = n;m_ = m;
			for(int i = 0; i< n*m; ++i) data_[i] = data[i];
		}
        void ins_row_bef(int num);
        void ins_row_aft(int num);
        void ins_col_bef(int num);
        void ins_col_aft(int num);
        void del_row(int num);
        void del_col(int num);
        void sw_row(int num1,int num2);
        void sw_col(int num1,int num2);
        void trans();
        void analyze(int argc, char** argv);
    private:
        int n_,m_;
        std::vector<int> data_;
        void print()const;
};
void Matrix::print()const{
    for(int i = 0;i < n_;i++){
        if(i != 0) std::cout << std::endl;
        for(int j = 0;j < m_;j++){
            std::cout << data_[m_*i+j];
            if(j != m_-1) std::cout << " ";
        }
    }
    std::cout << std::endl;
}
void Matrix::trans(){
    int new_n = m_;
    int new_m = n_;
    std::vector<int> tmp(n_*m_);
    for(int i = 0;i < n_;i++){
        for(int j = 0;j < m_;j++){
            tmp[j*new_m + i] = data_[i*m_+j];
        }
    }
    data_ = tmp;
    n_ = new_n;
    m_ = new_m;
    this->print();
}
void Matrix::ins_row_aft(int num){
    if(num < 1 || num > n_){this->print();return;}
    std::vector<int> new_data((n_+1)*m_);
    for(int i = 0;i < num;i++){
        for(int j = 0;j < m_;j++){
            new_data[i*m_+j] = data_[i*m_+j];            
        }
    }
    for(int j = 0;j < m_;j++) std::cin >> new_data[num*m_+j];
    for(int i = num;i < n_;i++){
        for(int j = 0;j < m_;j++){
            new_data[(i+1)*m_+j] = data_[i*m_+j];            
        }
    }
    ++n_;
    data_ = new_data;
    this->print();
}
void Matrix::ins_row_bef(int num){
    if(num < 1 || num > n_){this->print();return;}
    std::vector<int> new_data((n_+1)*m_);
    for(int i = 0;i < num-1;i++){
        for(int j = 0;j < m_;j++){
            new_data[i*m_+j] = data_[i*m_+j];            
        }
    }
    for(int j = 0;j < m_;j++) std::cin >> new_data[(num-1)*m_+j];
    for(int i = num-1;i < n_;i++){
        for(int j = 0;j < m_;j++){
            new_data[(i+1)*m_+j] = data_[i*m_+j];            
        }
    }
    ++n_;
    data_ = new_data;
    this->print();
}
void Matrix::ins_col_aft(int num){
    if(num < 1 || num > m_){this->print();return;}
    std::vector<int> new_data(n_*(m_+1));
    for(int i = 0;i < n_;i++){
        for(int j = 0;j < num;j++){
            new_data[i*(m_+1)+j] = data_[i*m_+j];            
        }
    }
    for(int i = 0;i < n_;i++) std::cin >> new_data[num+i*(m_+1)];
    for(int i = 0;i < n_;i++){
        for(int j = num;j < m_;j++){
            new_data[i*(m_+1)+j+1] = data_[i*m_+j];            
        }
    }
    ++m_;
    data_ = new_data;
    this->print();
}
void Matrix::ins_col_bef(int num){
    if(num < 1 || num > m_){this->print();return;}
    std::vector<int> new_data(n_*(m_+1));
    for(int i = 0;i < n_;i++){
        for(int j = 0;j < num-1;j++){
            new_data[i*(m_+1)+j] = data_[i*m_+j];            
        }
    }
    for(int i = 0;i < n_;i++) std::cin >> new_data[(num-1)+i*(m_+1)];
    for(int i = 0;i < n_;i++){
        for(int j = num-1;j < m_;j++){
            new_data[i*(m_+1)+j+1] = data_[i*m_+j];            
        }
    }
    ++m_;
    data_ = new_data;
    this->print();
}
void Matrix::del_row(int num){
    if(num < 1 || num > n_){this->print();return;}
    std::vector<int> new_data((n_-1)*m_);
    for(int i = 0;i < num-1;i++){
        for(int j = 0;j < m_;j++){
            new_data[i*m_+j] = data_[i*m_+j];            
        }
    }
    for(int i = num;i < n_;i++){
        for(int j = 0;j < m_;j++){
            new_data[(i-1)*m_+j] = data_[i*m_+j];            
        }
    }
    --n_;
    data_ = new_data;
    this->print();
}
void Matrix::del_col(int num){
    if(num < 1 || num > m_){this->print();return;}
    std::vector<int> new_data(n_*(m_-1));
    for(int i = 0;i < n_;i++){
        for(int j = 0;j < num-1;j++){
            new_data[i*(m_-1)+j] = data_[i*m_+j];            
        }
    }
    for(int i = 0;i < n_;i++){
        for(int j = num;j < m_;j++){
            new_data[i*(m_-1)+j-1] = data_[i*m_+j];            
        }
    }
    --m_;
    data_ = new_data;
    this->print();
}
void Matrix::sw_row(int num1, int num2){
    if(num1 < 1 || num1 > n_){this->print();return;}
    if(num2 < 1 || num2 > n_){this->print();return;}
    for(int j = 0;j < m_;j++){
        int tmp = data_[(num1-1)*m_+j];
        data_[(num1-1)*m_+j] = data_[(num2-1)*m_+j];
        data_[(num2-1)*m_+j] = tmp;
    }
    this->print();
}
void Matrix::sw_col(int num1, int num2){
    if(num1 < 1 || num1 > m_){this->print();return;}
    if(num2 < 1 || num2 > m_){this->print();return;}
    for(int i = 0;i < n_;i++){
        int tmp = data_[i*m_+num1-1];
        data_[i*m_+num1-1] = data_[i*m_+num2-1];
        data_[i*m_+num2-1] = tmp;
    }
    this->print();
}
void Matrix::analyze(int argc, char** argv){
    if(!strcmp(argv[1], "-irb")){
		if(argc != 3) return;
		this->ins_row_bef(atoi(argv[2]));
	}
	else if(!strcmp(argv[1], "-ira")){
		if(argc != 3) return;
		this->ins_row_aft(atoi(argv[2]));
	}
	else if(!strcmp(argv[1], "-icb")){
		if(argc != 3) return;
        this->ins_col_bef(atoi(argv[2]));
    }
	else if(!strcmp(argv[1], "-ica")){
		if(argc != 3) return;
        this->ins_col_aft(atoi(argv[2]));
    }
	else if(!strcmp(argv[1], "-dr")){
		if(argc != 3) return;
        this->del_row(atoi(argv[2]));
	}
	else if(!strcmp(argv[1], "-dc")){
		if(argc != 3) return;
		this->del_col(atoi(argv[2]));
	}
	else if(!strcmp(argv[1], "-sr")){
		if(argc != 4) return;
		this->sw_row(atoi(argv[2]),atoi(argv[3]));
	}
	else if(!strcmp(argv[1], "-sc")){
		if(argc != 4) return;
		this->sw_col(atoi(argv[2]),atoi(argv[3]));
	}
	else if(!strcmp(argv[1], "-t")){
		if(argc != 2) return;
		this->trans();
	}
}
int main(int argc, char** argv){
    int n,m;
    std::cin >> n >> m;
    int* data = new int[n*m];
    for(int i = 0;i < n*m;i++){
        std::cin >> data[i]; 
    }
    Matrix mat(n,m,data);
    delete[] data;
    mat.analyze(argc,argv);
    return 0;
}