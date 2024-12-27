#pragma once
#include<iostream>
#include<string>
#include "pcequip.h"
using namespace std;
class SoftW :
	public PcEquip
{
public:
	SoftW(int id , int numB,string N );
	~SoftW(void);
void SetName(string N);
string GetName();
virtual void Print();
private:
string Name ;
};
