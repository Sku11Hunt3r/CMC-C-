#include<iostream>
class BitString{
	public:
	BitString(unsigned int a, unsigned int b){st = a; ml = b;}
	BitString(unsigned int a){st = 0; ml = a;}
	BitString(){st = 0; ml = 0;}
	void Print(){
		unsigned long tmp = st;
		tmp <<= 32;
		tmp += ml;
		std::cout << tmp << std::endl;
	}
	void ShiftLeft(unsigned offset){
		unsigned int mask = 1 << 31, tmp,i;
		for(i = 0;i < offset;i++){
                	tmp = mask & ml;
			ml <<= 1;
			st <<= 1;
			st += (tmp >> 31);
		}	
	}
	void ShiftRight(unsigned offset){
		unsigned int mask = 1, tmp,i;
                for(i = 0;i < offset;i++){
			tmp = mask & st;
                	tmp <<= 31;
                	st >>= 1;
			ml >>= 1;
			ml += tmp;
		}
	}
	void NOT(){
		unsigned int mask = 1,i;
		for(i = 0;i < 31;++i){
			mask <<= 1;
			mask++;
		}
		st = st ^ mask;
		ml = ml ^ mask;
	}
	void AND(const BitString& b){
		ml = ml & b.ml;
		st = st & b.st;
	}
	void OR(const BitString& b){
		ml = ml | b.ml;
		st = st | b.st;
	}
	void XOR(const BitString& b){
		ml = ml ^ b.ml;
		st = st ^ b.st;
	}
	private:
	unsigned int st;
	unsigned int ml;
};
