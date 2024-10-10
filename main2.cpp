#include <iostream>
#include "time2.h"
using namespace chron;

int main(){
	
	Time t(21723);
	Time t1(10, 18, 5);
	Time t2(25, 10, 42);
	Time t3;
	std::cout<<"работа гетов:\n";
	std::cout<<t1.GetHours()<<":"<<t1.GetMinuts()<<":"<<t1.GetSeconds()<<"\n\n";
	std::cout<<"работа дефолтного значения:\n";
	std::cout<<t3.GetHours()<<":"<<t3.GetMinuts()<<":"<<t3.GetSeconds()<<"\n\n";
	//std::cout<<t2.GetHours()<<":"<<t2.GetMinuts()<<":"<<t2.GetSeconds()<<"\n";
	std::cout<<"работa перевода секунд во время:\n";
	std::cout<<t.GetHours()<<":"<<t.GetMinuts()<<":"<<t.GetSeconds()<<"\n";
	t.AddSeconds(58);
	t.AddMinuts(4);
	t.AddHours(2);
	std::cout<<"работа аддов:\n";
	std::cout<<t.GetHours()<<":"<<t.GetMinuts()<<":"<<t.GetSeconds()<<"\n\n";
	t+=23;
	std::cout<<"работа + и +=:\n";
	std::cout<<(t+23).GetHours()<<":"<<(t+23).GetMinuts()<<":"<<(t+23).GetSeconds()<<"\n\n";                                                                
	/*std::cout<<t1.GetHours()<<":"<<t1.GetMinuts()<<":"<<t1.GetSeconds()<<"\n";
	std::cout<<t1.GetHours()<<":"<<t1.GetMinuts()<<":"<<t1.GetSeconds()<<"\n\n";
	std::cout<<t2.GetHours()<<":"<<t2.GetMinuts()<<":"<<t2.GetSeconds()<<"\n";
	std::cout<<t3.GetHours()<<":"<<t3.GetMinuts()<<":"<<t3.GetSeconds()<<"\n\n";*/
	std::cout<<"работа минуса:\n";
	std::cout<<(t1-t2)<<"\n";
	std::cout<<"работа вывода через сout:\n";
	std::cout<<t<<"\n";
	std::cout<<"работа ввода:\n";
	std::cin>>t3;
	std::cout<<"\n"<<t3<<"\n";
	//std::cout<<"\n\n"<<t3.GetHours()<<":"<<t3.GetMinuts()<<":"<<t3.GetSeconds()<<"\n\n";
	
	/*if(IsAfternoonTime(t)){
		std::cout<<"Yes it's "<<t.GetHours()-12<<" PM\n";
	}else
		std::cout<<"No\n";
		}*/

	return 0;
}
