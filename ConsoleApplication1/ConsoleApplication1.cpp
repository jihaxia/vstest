#include<iostream>
#include<string>
#include<algorithm>
//#include<bits/stdc++.h>
using namespace std;

//�������ӷ�
string ladd(string x, string y)
{
	int n = x.size();
	int m = y.size();
	string res;
	int ext = 0;
	int now = 0;
	if (n < m)
	{
		string qw = x;
		x = y;
		y = qw;
		int w = n;
		n = m;
		m = w;
	}
	for (int i = m - 1; i >= 0; i--)
	{
		now = ((x[i + (n - m)] - '0') + (y[i] - '0') + ext) % 10;
		ext = ((x[i + (n - m)] - '0') + (y[i] - '0') + ext) / 10;
		res.push_back('0' + now);
	}
	for (int i = n - m - 1; i >= 0; i--)
	{
		if (ext != 0)
		{
			now = ((x[i] - '0') + ext) % 10;
			ext = ((x[i] - '0') + ext) / 10;
			res.push_back('0' + now);
		}
		else
			res.push_back(x[i]);
	}
	if (ext != 0)
	{
		res.push_back('0' + ext);
		ext = 0;
	}
	reverse(res.begin(), res.end());
	return res;
}

//����������
string lsub(string x, string y)
{
	int n = x.size();
	int m = y.size();
	string res;
	int ext = 0;
	int now = 0;
	int valu = 0;
	if (n < m || n == m && int(x[0] - y[0]) < 0)
	{
		string qw = x;
		x = y;
		y = qw;
		valu = 1;
		int w = n;
		n = m;
		m = w;
	}

	for (int i = m - 1; i >= 0; i--)
	{

		now = ((x[i + (n - m)] - '0') - (y[i] - '0') - ext);
		if (now < 0)
		{
			now += 10;
			ext = 1;
		}
		else
		{
			ext = 0;
		}
		res.push_back('0' + now);
	}

	for (int i = n - m - 1; i >= 0; i--)
	{
		if (ext == 1)
		{
			now = ((x[i] - '0') - ext);
			if (now < 0)
			{
				now += 10;
				ext = 1;
			}
			else
			{
				ext = 0;
			}
			res.push_back('0' + now);
		}
		else
		{
			res.push_back(x[i]);
		}
	}
	if (valu)
		res.push_back('-');
	reverse(res.begin(), res.end());
	return res;
}

//�������˷� string* int 
string irid(string x, int y)
{
	string valu, te;
	int ext = 0, now = 0;
	for (int i = x.size() - 1; i >= 0; i--)
	{
		now = ((x[i] - '0') * y + ext) % 10;
		ext = ((x[i] - '0') * y + ext) / 10;
		valu.push_back(now + '0');
	}
	while (ext != 0)
	{
		valu.push_back('0' + ext%10);
		ext = ext / 10;
	}
	reverse(valu.begin(), valu.end());
	return valu;
}

//����������  x/y
string ldiv(string x, int y, int& k)
{
	string valu;
	k = 0;
	for (int i = 0; i < x.size(); i++)
	{
		k = k * 10 + (x[i] - '0');
		if(!(i==0&&k<y))
		valu.push_back(k / y + '0');
		k %= y;
	}
	return valu;
}


//n!
string jc(int x, int& z, int& w)
{
	string valu(1, '1');
	for(int i=x;i>0;i--)
		valu = irid(valu, i);
	z = count(valu.begin(), valu.end(),'0');
	w = 0;
	for (int i = valu.size()-1; valu[i] == '0'; i++)
	{
		w++;
	}
	return valu;
}




//�������˷� string*string
string lrid(string x, string y)
{
	string valu(y.size()+x.size(),'0');
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());	
	for (int i = 0; i <=x.size() - 1 ; i++)
	{
	    int k = 0;
		for (int j = i; j <= i + y.size() - 1; j++)
		{
			k = valu[j] - '0' + (x[i] - '0') * (y[j - i] - '0') + k;
			valu[j] =  k % 10+'0';
			k /= 10;
		}
		valu[i+y.size()]=k+'0';
	}
	while (valu.size() > 1 && valu.back() == '0')valu.pop_back();
	reverse(valu.begin(), valu.end());
	return valu;
}

bool isAllZero(const std::string& str) {
	for (char c : str) {
		if (c != '0') {
			return false;
		}
	}
	return true;
}

//n! 0个数和末尾0个数
string jie(string x,int &z,int & w)
{
	string valu("1");
	while (!isAllZero(x))
	{
		valu = lrid(valu, x);
		x = lsub(x, string("1"));
	}
	z = count(valu.begin(), valu.end(), '0');
	w = 0;
	for (int i = valu.size() - 1; valu[i] == '0'; i--)
	{
		w++;
	}
	return valu;
}






int main(void)
{
	string a, b;
	int b1=1,z=0,a1=1;
	cin >>a;
	//cout << ladd(a, b);//a+b 
	//cout<<lsub(a,b);//a-b
	//cout << irid(a, b1);//a*b1
	//cout<< ldiv(a,b1);//a/b1
	//cout << lrid(a, b);//a*b
	cout << jie(a, b1, z) <<"\n"<<b1 << "\n" << z;
}



