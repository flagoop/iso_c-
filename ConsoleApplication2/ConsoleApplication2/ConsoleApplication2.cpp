// ConsoleApplication2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "test.h"

class Bad_val { public:Bad_val() { cout << "Bad_val()" << endl; } };
class Bad_val2{};

void funtmp1(unsigned val)
{
	if (val > 10)throw Bad_val{};
	if (val < 3)throw Bad_val2{};
	//if (val < 3)throw Bad_val2{};
	
	cout << "val=" << val << endl;
}



int funtmp2(int i)
{
	//static int k = i;
	static int k;
	k = i;
	return k;
}

struct Reading
{
	unsigned	uHour;
	double		dTemps;
};

bool	chkist(ifstream &ist)
{
	if (ist.fail()||ist.bad())
	{
		cout << "bad reading in file.\n";
		//funerr("bad reading in file.");
		return	false;
	}
	return true;
}

void getinfo(vector<Reading> &v, ifstream &ist)
{
	Reading	rd;
	int line = 1;
	//while (ist>>rd.uHour>>rd.dTemps){	v.push_back(rd);}
	while (true)
	{
		ist >> rd.uHour >> rd.dTemps;
		if (ist.eof())
		{
			cout << "End of file.\n";
			break;
		}
		if (chkist(ist))
			v.push_back(rd);
		else
		{
			cout << "line " << line << " data is invalid.\n";
			break;
		}
		++line;
	}

}
void pt(ostream &os,vector<Reading> &v)
{
	os << "File context:\n";
	for (auto c:v)
	{
		os << "hour:" << c.uHour << "  Temperature:" << c.dTemps << endl;

	}
}

void read_file_test()
{
	vector<Reading> vecTmp;
	string	fname = "info.txt";
	ifstream ist{ fname };
	
	getinfo(vecTmp, ist);
	pt(cout, vecTmp);
}

void skip_to_int()
{
	if (cin.fail())
	{
		cin.clear();
		for (char ch;cin>>ch;)
		{
			if (isdigit(ch) || ch=='.')
			{
				cin.unget();
				return;
			}
		}
	}
	cerr << "no input.\n";
}

void fun_cin_chk()
{
	int n = 0;
	cin >> n;
	cout << "begin chk cin n:" << n << endl;
	if (cin.fail())
	{
		cerr << "input type is error.\n";
		cin.clear();
		for (char ch; cin >> ch;)
		{
			if (isdigit(ch) || ch == '|')
			{
				cin.unget();
				break;
			}
		}
	}
	cin >> n;
	cout << "after n:" << n << endl;
}

vector<string> vec_month{ "jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec" };
void fun_create_tempstable()
{
	ofstream	ost("temperture_rec.txt");
	if (!ost)
	{
		cout << "create file failded.\n";
		return;
	}
	static	default_random_engine e;
	static uniform_real_distribution<>	u(-30, 40);
	for (int i=2000;i<=2001;++i) //year
	{
		ost << "{year " << i;
		for (int j = 0; j <12; j++) //month
		{
			ost <<"{month "<< vec_month[j].c_str()<<" ";
			for (int k=1;k<32;++k) //day
			{
				for (int h=0;h<24;++h) //hour
				{
					ost << "(" << k << " " << h << " " << u(e) << " ) ";

				}
				
			}
		}
		ost << "}";
	}
	ost << "}" << endl;
	

}

struct Str1
{
	int k = 70;
};

struct Str2
{
	vector<int>	vec_int{ 1,2,3,4,5 };
};
struct Str3
{
	int str3;
	vector<Str2> vec_str3{ 3 };
};

template<class T>
char * as_bytes(T &i)
{
	void* addr = &i;
	return static_cast<char*>(addr);
}


MyVector myfill()
{
	MyVector res{ 1.1,2.2,3.3 };
	return res;	//一个临时变量
}


int main()
{
	int arBuf[6];
	//char arBuf[6];
	int *pd = arBuf;
	cin >> *pd;
	pd++;
	cin >> *pd;
	//scanf("%d", arBuf);
	//scanf("%d", &arBuf[1]);

	//printf("%d\n", arBuf[0]);
	cout << arBuf[0] << endl;
	cout << arBuf[1] << endl;

	printf("%p\n", arBuf);
	printf("%p\n", &arBuf[1]);

	//cout << arBuf << endl;
	/*
	BYTE arBuf[41] = "01230000000000000000000000000000000000";

	cout << &arBuf << endl;
	cout << "--------" << endl;
	DWORD ival = 20;
	DWORD *pby;
	for (int i=0;i<(int)10-3;i++)
	{
		pby = (DWORD*)&arBuf[i];
		cout <<hex<<pby[0] << endl;
		
	}
	


	/*
	BYTE *pby2;
	pby2 = &arBuf[0];
	cout << pby << endl;
	cout << pby2 << endl;
	/*
	char c = 'a';
	int k;
	k = (int)c;
	cout << k << endl;
	cout << c << endl;
	/*
	int i = 20;
	int *pi;
	pi = &i;
	printf("%p\n", &i);
	cout << pi << endl;

	/*
	vector<Def_struc> v1;
	Def_struc ds1(3);
	v1.push_back(ds1);
	v1[0].pt();

	//vector<Def_struc> v2(3);

	/*
	TmpStruct	ad{ 5,6,9 };
	cout << ad.v1 << " " << ad.d1 << " " << ad.v2 << endl;

	//cout << ad.v1 << " " << ad.v2 <<" "<<ad.v3<< endl;

	/*
	Arr<int, 7> ad{ 5 };
	cout << ad.v1 << endl;

	/*
	Arr<int, 3> ad{ 1,2,3 };
	cout << ad.elem[1] << endl;

	/*
	Shape	s1;
	Circle	s2;

	vector<Shape*> vps{ &s2 };
	vector<Circle*> vpc;
	//vps = vpc;	//error
	for (auto c:vps)
	{
		c->pt();
		cout << endl;
	}

	/*
	vector<int>	v1{ 1,2,3 };
	vector<int>	v2{ 7,9 };
	v1 = v2;
	for (auto c:v1)
	{
		cout << c << endl;
	}

	/*
	Shape *p1 = &s1;
	Circle *p2 = &s2;
	p1 = p2;
	p1->pt();

	/*
	s1 = s2;
	s1.pt();
	
	

	/*
	Tmpcls	t1 = 10;//调用拷贝构造函数 Tmpcls(int) 编译器先将10隐式转换为 Tmpcls(10)临时对象，
				//再将临时对象拷贝赋值给t1;
	t1.pt();

	/*
	MyVector mvec = myfill(); //对于临时变量 ，编译器会很聪明的选择 参数为(&&v)的移动构造函数
	//MyVector mvec;
	//mvec = myfill();

	mvec.pt();

	/*
	MyVector	v1{ 1.0,2.2,3.3 };
	MyVector	v2 = v1;
	v1.set(1, 7.7);
	v1.pt();
	v2.pt();

	/*
	ifstream	ifs("info.txt");
	//istringstream	iss(ifs.rdbuf());
	auto ss = ifs.rdbuf();
	cout << ifs.rdbuf() << endl;

	/*
	//ifstream	ifs("temperture_rec2.txt",ios::ate);
	ifstream	ifs("temperture_rec2.txt", ios::binary|ios::ate);
	ofstream	ofs("temperture_rec2_bak.txt", ios::binary);
	char *pm = nullptr;
	auto fsize = ifs.tellg();
	ifs.seekg(ios::beg);
	pm = new char[fsize];
	ifs.read(pm, fsize);
	//cout << pm << endl; //非二进制打开模式可以输出

	ofs.write(pm, fsize);
	delete[] pm;
	ifs.close();


	/*
	ifstream	ifs("tt.jpg", ios::binary | ios::ate);
	ofstream	ofs("tt_bak.jpg", ios::binary);
	binaryfile_to_binaryfile(ifs, ofs);


	
	/*
	//fstream	fs("temperture_rec2.txt", ios_base::out);

	//fstream	fs("temperture_rec2.txt", ios_base::in|ios_base::out);

	/*	cout << 1234.56789 << " " << fixed << 123.5678912345 <<" "<<scientific<<1234.5678912<< endl;
	cout << defaultfloat;
	cout << 7732.11231243 << endl;
	/*
	int i, j, k;
	//int i=1234, j=0x4d2, k=02322;
	//cin >> i >>hex>> j >>oct>> k;
	cin >> i >> j >> k;
	cout << showbase;
	cout << i << " " <<hex<< j << " " <<oct<< k << endl;
	//cout << i << " " << j << " " << k << endl;
	cout.unsetf(ios::oct);
	cout <<oct<< 1234 << endl;

	/*
	//fun_create_tempstable()
	
	ifstream	ist("temperture_rec2.txt");
	ist.exceptions(ios_base::failbit);

	
	char ch;
	while (!ist.eof())
	{
		while (true)
		{
			ist >> ch;
			if (ch == '(')
			{
				ist.unget();
				break;
			}
		}
		try
		{
			for (Reading2 r; ist >> r;)
			{
				cout << r.day << " " << r.hour << " " << r.tmps << endl;
			}

		}
		catch (ios_base::failure &fb)
		{
			cerr << fb.what() << endl;
			ist.clear();
		}

	}



	


	/*
	try
	{
		for (Reading2 r; ist >> r;)
		{
			cout << r.day << " " << r.hour << " " << r.tmps << endl;
		}
	}
	catch (ios_base::failure &fb)
	{
		cerr << fb.what() << endl;
	}
	
	
	
	
	/*
	ifstream	ist("temperture_rec.txt");

	Year	y;
	ist >> y;
	cout << y.year << " "
		<< y.vec_month[0].month
		<< y.vec_month[0].vec_day[0].vec_hour[0] << endl;

	/*
	try
	{
		ifstream	ist("temperture_rec.txt");
		ist.exceptions(ios_base::failbit);

		while (true)
		{
			Year	y;
			ist >> y;
			cout << y.year << endl;

		}
	}
	catch (ios_base::failure &e)
	{
		cerr << e.what() << endl;
	}
	catch (Input_type_error &e)
	{
		cerr << e.msg << endl;
	}
	catch (const std::exception&e)
	{
		cerr << e.what() << endl;
	}


	/*
	cin.exceptions(ios_base::failbit);
	int i;
	try
	{
		cin >> i;
	}
	
	catch (ios_base::failure &fb)
	{
		cerr << "input type invaild.\n";
		cout << fb.what() << endl;
	}
	catch (const std::exception&)
	{

	}
	/*
	try
	{
		ifstream	ist("temperture_rec2.txt");
		if (!ist)
		{
			throw exception("can't open file.");
		}
	}
	catch (const exception &e)
	{
		cout << e.what() << endl;
	}


	/*

	ifstream	ist;
	//ist.exceptions(ist.exceptions() | ios_base::badbit);
	//cin.exceptions(cin.exceptions() | ios_base::failbit);
	int j;

	try
	{
		//if(cin >> j)throw exception("wo cao");
		cin >> j;
		cout << j << endl;
	}
	catch (ios_base::failure &fb)
	{
		cout << fb.what() << endl;
	}
	/*
	catch (const std::exception&e)
	{
		cerr << "error. " << e.what() << endl;
	}
	catch (...)
	{
		cerr << "...... " << endl;

	}
	
	//if (!ist)	{		funerr("can't open file.");	}
	

	/*
	Str3 st3;
	cout<<st3.vec_str3[0].vec_int[0]<<endl;
	cout << st3.vec_str3[0].vec_int[1] << endl;

	/*
	ifstream	ist("temperture_rec.txt");
	Reading2	r;
	ist >> r;
	cout << r.day << " " << r.hour << " " << r.tmps << endl;

	/*
	int n = 0;
	ifstream	ist("temperture_rec.txt");
	string	s;
	while (getline(ist, s))
	{
		++n;
		cout << s <<"*"<< endl;
	}
	cout << n << endl;
	/*
	
	

	/*
	//vector<int> v{ 3 };
	vector<Str1> v(3);	//表示Str1的数量
	for (auto c:v)
	{
		cout << c.k << " ";
	}
	cout << "\n";
	/*
	Month	m;
	Day	d1;
	for (auto c:m.vec_day)
	{
		for (auto e:c.vec_hour)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	/*
	ofstream	ost("temperture_rec.txt");
	string s;
	s = "kkk";
	const char *ps = "jjj";
	ost << ps;
	ost << s.c_str();
	//ost << vec_month[1];

	/*
	enum class Month_enum
	{
		jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
	};
	
	int n = 0;
	cin >> n;
	auto k2 = static_cast<Month_enum>(n);
	
	switch (k2)
	{
	case Month_enum::jan:
		break;
	case Month_enum::feb:
		break;
	case Month_enum::mar:
		break;
	case Month_enum::apr:
		break;
	case Month_enum::may:
		break;
	case Month_enum::jun:
		break;
	case Month_enum::jul:
		break;
	case Month_enum::aug:
		cout << "aug" << endl;

		break;
	case Month_enum::sep:
		cout << "sep" << endl;

		break;
	case Month_enum::oct:
		cout << "oct" << endl;
		break;
	case Month_enum::nov:
		break;
	case Month_enum::dec:
		break;
	default:
		break;
	}

	//auto k = Month_enum::oct;
	//int k = static_cast<int>(Month_enum::oct);
	//cout << k << endl;
	//int j = static_cast<int>(k);
	//cout << j << endl;

	/*
	int n = 0;
	while (true)
	{
		if (cin>>n)
		{
			if (n>=1 && n<=10) break;
		}
		else
		{
			cout << "sorry,that was not a number;please try again.\n";
			skip_to_int();
		}
	}

	/*
	cin.exceptions(cin.exceptions() | ios_base::failbit);

	int i;
	try
	{
		while (cin>>i)
		{
			cout << i << endl;
		}
		
	}
	catch (const std::exception&e)
	{
		cout << "catch..." << endl;
		cout << e.what() << endl;
	}


	//FileReadingTest	frt("info.txt");
	//frt.pt_file();
	//read_file_test();
	

	/*
	auto val = funtmp2(20);
	cout << val << endl;
	val = funtmp2(70);
	cout << val << endl;

	/*
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

