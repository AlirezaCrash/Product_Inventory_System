#pragma once
#include "mobequip.h"
using namespace std;
class Repair :	public MobEquip
{
public:
	Repair(int,int,string,string);
	~Repair(void);
	void SetOSName(string);
	string GetOSName();
	virtual void Print();
private:
string OSName;
};

