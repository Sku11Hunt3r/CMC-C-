#include<iostream>
#include<list>
#include<string.h>
int main(int argc,char** argv){
	int i; 
	std::list<int> l;
	std::list<int>::iterator p;
	while(std::cin >> i){
		l.push_back(i);
	}
	p = l.begin();
	if(!strcmp(argv[1],"-af")){
		if(argv[2] != nullptr){
			int num = strtol(argv[2],nullptr,10);
			l.push_front(num);
		}
		else{
			std::cerr << "Not enough arguments" << std::endl;
		}
	}
	else if(!strcmp(argv[1],"-ae")){
		if(argv[2] != nullptr){
			int num = strtol(argv[2],nullptr,10);
			l.push_back(num);
		}
		else{
			std::cerr << "Not enough arguments" << std::endl;
		}
	}
	else if(!strcmp(argv[1],"-ib")){
		if(argv[2] != nullptr && argv[3] != nullptr){
			int tmp;
			int num1 = strtol(argv[2],nullptr,10);
			int num2 = strtol(argv[3],nullptr,10);
			while(p != l.end()){
		       		if(*p != num2) ++p;
				else break;
			}
			if(p != l.end()){
				tmp = *p;
				*p = num1;
				++p;
				l.insert(p,tmp);
			}
		}
		else{
			std::cerr << "Not enough arguments" << std::endl;
		}
	}
	else if(!strcmp(argv[1],"-ia")){
		if(argv[2] != nullptr && argv[3] != nullptr){
			int num1 = strtol(argv[2],nullptr,10);
			int num2 = strtol(argv[3],nullptr,10);
			while(p != l.end()){
                        	if(*p != num2) ++p;
                        	else break;
			}
			if(p != l.end()){
				++p;
				l.insert(p,num1);
			}
		}
		else{
			std::cerr << "Not enough arguments" << std::endl;
		}
	}
	else if(!strcmp(argv[1],"-d")){
		if(argv[2] != nullptr){
			int num = strtol(argv[2],nullptr,10);
			while(p != l.end()){
                        	if(*p != num) ++p;
                                else break;
                        }
			if(p != l.end()) l.erase(p);
		}
	}
	else if(!strcmp(argv[1],"-sa")){
		l.sort();
	}
	else if(!strcmp(argv[1],"-sd")){
		l.sort();
		l.reverse();
	}
	else if(!strcmp(argv[1],"-mf")){
		int m = *p;
		std::list<int>::iterator max = l.begin();
		while(p != l.end()){
			if(*p > m){
				max = p;
				m = *p;
			}
			++p;
		}
		l.erase(max);
		l.push_front(m);
	}
	else if(!strcmp(argv[1],"-me")){
		int m = *p;
		std::list<int>::iterator max = l.begin();
		while(p != l.end()){
			if(*p > m){
				max = p;
				m = *p;
			}
			++p;
		}
		l.erase(max);
		l.push_back(m);
	}
	else{
		std::cerr << "No command" << std::endl;
	}
	for(p = l.begin();p != l.end();++p) std::cout << *p << " ";
	std::cout << std::endl;
}
