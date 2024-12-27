#pragma once
#include "mobequip.h"
using namespace std;
class Decoration :public MobEquip
{
public:
	Decoration(int,int,string,string);
	Decoration();
	~Decoration(void);
	void SetMName(string);
	string GetMName();
	virtual void Print();
private:
string Mobile_Name;
};

