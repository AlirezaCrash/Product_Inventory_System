#pragma once
#include<iostream>
#include "pcequip.h"
using namespace std;
class HardW :public PcEquip
{
public:
	HardW(int id,int numB,int date,string Brand);
	~HardW(void);
void SetRDate(int Date);
int GetRDate();
void SetBrand(string);
string Getbrand();
virtual void Print();
private:
int RDate;
string Brand;
};

