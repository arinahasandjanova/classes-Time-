#include "time2.h"
#include <ostream>
#include <iostream>
using namespace chron;
Time::Time(int h, int m, int s){
	totalSeconds=s+m*60+h*3600;
	normalize();
	}
void Time::normalize(){
	totalSeconds%=86400;
	if(totalSeconds<0){
		totalSeconds+=86400;
		}
	}
int Time::GetHours() const{
	return totalSeconds/3600;
	}
int Time::GetMinuts() const{
	return totalSeconds/60-(totalSeconds/3600)*60;
	}
int Time::GetSeconds() const{
	return totalSeconds%60;
	}
void Time::AddHours(int h){
	totalSeconds+=h*3600;
	normalize();
	}
void Time::AddMinuts(int m){
	totalSeconds+=m*60;
	normalize();
	}
void Time::AddSeconds(int s){
	totalSeconds+=s;
	normalize();
	}
int Time::TotalSeconds() const{
	return totalSeconds;
	}
Time& Time::operator+=(int s){
	totalSeconds+=s;
	normalize();
	return *this;
	}
Time Time::operator+(int s) const{
	return Time(totalSeconds+s);
	}
int operator-(const Time&t1, const Time&t2){
	return t1.TotalSeconds()-t2.TotalSeconds();
	}
std::ostream& operator << (std::ostream& out, const chron::Time& t){
	out<<t.GetHours()<<":"<<t.GetMinuts()<<":"<<t.GetSeconds();
	return out;
	}
std::istream& operator >> (std::istream& in, Time& t){
	int h, m, s;
	char temp;
	in>>h>>temp;
	in>>m>>temp;
	in>>s>>temp;
	t=Time(h, m, s);
	return in;
	}

