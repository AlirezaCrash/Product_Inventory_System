#pragma once
#include "inventory.h"
#include<string>
#include<iostream>
using namespace std;
class MobEquip : public Inventory
{
public:
	MobEquip(int a,int b,string Part_Name):Inventory(a,b){SetPName(Part_Name);};
	MobEquip():Inventory(){SetPName(" ");}
	~MobEquip(void){};
	void SetPName(string N){PName=N;}
	string GetPName(){return PName;}
	virtual void Print(){Inventory::Print() ;cout << GetPName() << "\t" ;}
private:
string PName;
};

