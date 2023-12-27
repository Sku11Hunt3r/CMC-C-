#include<iostream>
#include<cstring>
class mstring{
	public:
		mstring(){
			c = new char[1];
			c[0] = '\0';
			len = 0;
		}
		mstring(const mstring &op){
			int i;
			c = new char[op.len + 1];
			for(i = 0;i < op.len;++i) c[i] = op.c[i];
			c[op.len] = '\0';
			len = op.len;
		}
		mstring(const char *str){
			int i,k = 0;
			const char *tmp = str;
			while(tmp[k] != '\0') ++k;
			c = new char[k + 1];
			for(i = 0;i < k;++i) c[i] = str[i];
			c[k] = '\0';
			len = k;
		}
		~mstring(){delete[] c;}
		int length() const;
		bool isempty() const;
		void add(char c);
		void add(const char* c);
		void insert(char c,int i);
		void insert(const char* c,int i);
		void del(int i);
		void del(int i, int j);
		int search(const char* str) const;
		void replace(const char* sub_str, const char *new_str);
		void print() const;
	private:
		char* c;
		int len;
};

int mstring::length() const{return this->len;}
bool mstring::isempty() const{
	bool ans = 0;
	if(c[0] == '\0') ans = 1;
	return ans;
}
void mstring::add(char c1){
	int i; 
	char* tmp = new char[this->len + 2];
	for(i = 0;i < this->len;++i) tmp[i] = c[i];
	tmp[this->len] = c1;
	delete[] c;
	c = new char[this->len + 2];
	std::memcpy(c,tmp,this->len + 1);
	delete[] tmp;
	c[this->len + 1] = '\0';
	++len;
}
void mstring::add(const char* str){
	int i;
	int len = 0;
	while(str[len] != '\0') ++len;
        for(i = 0;i < len;++i) this->add(str[i]);
}
void mstring::insert(char c1,int k){
	int i;
	char* tmp;
        tmp = new char[this->len + 2];
	for(i = 0;i < k;++i) tmp[i] = c[i];
	tmp[k] = c1;
	for(i = k;i < this->len;++i) tmp[i+1] = c[i]; 
        delete[] c;
	++len;
        c = new char[this->len + 1];
	std::memcpy(c,tmp,this->len);
        delete[] tmp;
        c[this->len] = '\0';
}
void mstring::insert(const char* str,int k){
	int i;
        int len = 0;
        while(str[len] != '\0') ++len;
        for(i = 0;i < len;++i) this->insert(str[i],k+i);
}
void mstring::del(int k){
	int i;
	for(i = k;i <= this->len;++i) c[i] = c[i+1];
	--len;
}		
void mstring::del(int k, int j){
	int i;
	for(i = 0;i <= (j-k);++i) this->del(k);
}
int mstring::search(const char* str)const{
	int len = 0, k = 0,i;
        while(str[len] != '\0') ++len;
	while(c[k] != '\0'){
		if(c[k] == str[0]){
			for(i = 0;i < len;++i){
				if(i == len-1 && c[i+k] == str[i]) return k;
				if(c[k+i] != str[i]) break;
			}
		}
		++k;
	}
	return -1;
}
void mstring::replace(const char* sub_str, const char *new_str){
	int pos,len1 = 0;
	while(sub_str[len1] != '\0') ++len1;
	pos = search(sub_str);
	if(pos == -1) return;
	else{
		del(pos,pos+len1-1);
		insert(new_str,pos);
	}	
}
void mstring::print()const{std::cout << this->c << std::endl;}
/*int main()
{
       mstring s ("hello world");
       mstring s1 = s;
       mstring s2;
       std::cout << s2.length() << std::endl;
       if (s2.isempty())
       {
           s.add(' ');
           s2.add("HI!");
           s.print();
           s2.print();
       }
       if (!s1.isempty()){
           s1.insert(' ',5);
           s1.insert('m',6);
           s1.insert('y',7);
           s.insert(" my",5);
           s.print();
           s1.print();
       }
       s.del(9);
       s1.del(5,7);
       s.print();
       s1.print();
       s1.replace("ll","ll");
       s1.print();
       return 0;
}*/
