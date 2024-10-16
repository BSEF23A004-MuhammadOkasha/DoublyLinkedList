#include<iostream>
using namespace std;
class tesla
{
	private:
	int vol;
	int size;
public:
	tesla()
	{
		vol = 40;
		size = 20;
	}
	virtual void print() = 0;
	virtual void v() = 0;
	
	
	
};
class teslaA:public tesla
{
	int base;
public:
	teslaA(int ba):tesla()
	{
		base = ba;
	}
	void print()
	{
		
		cout << base << "\n";
		
	}
	virtual void v()
	{

	}
	
};
class teslaB:public tesla
{
	int autotune;
public:

	teslaB(int aut):tesla()
	{
		autotune = aut;
	}

	void print()
	{

		cout << autotune << "\n";
		
	}
	virtual void v()
	{

	}
	
};
int main()
{
	teslaB t(25);
	//t.print();
	tesla* p = new teslaB(25);
	p->print();
	//teslaB* p = & t;
//	teslaB* (teslaB * p);


	return 0;
}