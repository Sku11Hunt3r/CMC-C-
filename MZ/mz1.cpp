#include<iostream>
#include<cstring>
char* right(char* str, int N){
	char* p = str;
	int k = 0;
	k = strlen(str);
	if(k <= N) return str;
	p = str +(k-N);
	return p;
}

unsigned long right(unsigned long num, int N){
	unsigned long tmp = num;
	int i,k = 0;
	while(tmp != 0){
		tmp /= 10;
		++k;
	}
	if(k <= N) return num;
	tmp = num;
	for(i = 0;i < N;++i) tmp /= 10;
	for(i = 0;i < N;++i) tmp *= 10;
	return num - tmp;
}

int main(){
	char str1[7];
	char str2[101];
	char str_new_line[1];
	unsigned long num;
	int N;
	std::cin.getline(str1,7);
	if(*str1 == 's'){
		std::cin.getline(str2,101);
		std::cin >> N;
		std::cin.getline(str_new_line,1);
		std::cout << right(str2,N) << std::endl;
	}
	else{
		std::cin >> num;
		std::cin.getline(str_new_line,1);
		std::cin >> N;
		std::cin.getline(str_new_line,1);
		std::cout << right(num,N) << std::endl;
	}
	return 0;
}
