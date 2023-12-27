#include<iostream>
#include<string>
class event{
	public:
		event(const char* str = nullptr,int a = 0,int b = 0,int c =0){name_ = str;year_ = a;month_ = b;day_ = c;}
		virtual void print_res() const = 0;
		//std::cout<<str<<" "<<year_<<" "<<month_<<" "<<day_<<std::endl;
		void change_date(int new_year,int new_month,int new_day){year_ = new_year;month_ = new_month;day_ = new_day;}
		virtual void change_grade(int a) = 0;
		virtual void change_grade(bool a) = 0;
		virtual ~event(){year_ = 0;}
	private:
		int day_,month_,year_;
		std::string name_;
};

class test:public event{
	public:
		test(const char* str = nullptr,int a = 0,int b = 0,int c = 0,bool gr = false):event(str,a,b,c){grade_ = gr;}
		void print_res() const{
			if(grade_) std::cout<<name_<<" "<<year_<<" "<<month_<<" "<<day_<<" true"<<std::endl;
			else std::cout<<name_<<" "<<year_<<" "<<month_<<" "<<day_<<" false"<<std::endl;
		}
		virtual void change_grade(int a){grade_ = a;}
		virtual void change_grade(bool gr){grade_ = gr;}
		virtual ~test(){year_ = 0;}
	private:
		bool grade_;
};
class exam:public event{
        public:
            exam(const char* str = nullptr,int a = 0,int b = 0,int c = 0,int gr = 0):event(str,a,b,c){grade_ = gr;}
            void print_res() const{
                std::cout<<name_<<" "<<year_<<" "<<month_<<" "<<day_<<" Grade "<<grade_<<std::endl;
            }
            virtual void change_grade(int gr){grade_ = gr;}
		virtual void change_grade(bool a){grade_ = a;}
		virtual ~exam(){year_ = 0;}
        private:
                int grade_;
};
/*
int main()
{
        enum {NUM = 7};
        event *session[NUM];

        session[0]=new test("Mathematical analysis",2022,12,23,true);
        session[1]=new exam("Operation System",2023,1,15,2);
        session[2]=new test("Practicum",2022,12,25,false);
        session[3]=new exam("Differential equation",2023,1,20,3);
        session[4]=new test("Theory of probability",2022,12,29,true);
        session[5]=new exam("Philosophy",2022,1,24,5);
        session[6]=new exam("Numerical methods",2023,1,11,4);

        for (int i=0;i<NUM;i++)
                session[i]->print_res();

        session[2]->change_date(2023,2,25);
        session[2]->change_grade(true);

        session[1]->change_date(2023,3,3);
        session[1]->change_grade(3);

	std::cout<<std::endl;
        for (int i=0;i<NUM;i++)
                session[i]->print_res();

        for (int i=0;i<NUM;i++)
        delete session[i];
        return 0;
}*/