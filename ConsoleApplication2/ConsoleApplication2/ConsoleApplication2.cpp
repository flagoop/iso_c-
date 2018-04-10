// ConsoleApplication2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Bad_val { public:Bad_val() { cout << "Bad_val()" << endl; } };
class Bad_val2{};

void funtmp1(unsigned val)
{
	if (val > 10)throw Bad_val{};
	if (val < 3)throw Bad_val2{};
	//if (val < 3)throw Bad_val2{};
	
	cout << "val=" << val << endl;
}

void funerr(const string &s)
{
	throw runtime_error(s);
}
int main()
{
	double	d;

	
	try
	{
		cin >> d;
		if (!cin) funerr("i have a double type.");
		cout << "d=" << d << endl;
		
	}
	
	catch (const std::exception&e) { cerr << "this." << e.what() << endl;	}
	//catch (runtime_error &e)	{	cerr << "runtime_error:" << e.what() << endl;}
	catch (...)
	{
		cerr << "input error val.\n";
	}

	/*
	unsigned	i = 0;
	cin >> i;
	try
	{
		funtmp1(i);
	}
	catch (Bad_val)
	{
		cerr<<("Bad_val.\n");
	}
	catch (...)
	{
		cerr << "other error.\n";
	}
	*/

    return 0;
}

