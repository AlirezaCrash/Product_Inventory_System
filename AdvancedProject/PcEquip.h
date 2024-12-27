#include<iostream>
#include"Inventory.h"
#pragma once
using namespace std;
class PcEquip : public Inventory 
{
public:
	PcEquip(int a,int b):Inventory(a,b){};
	~PcEquip(void){};
	virtual void Print(){Inventory::Print();}
};


