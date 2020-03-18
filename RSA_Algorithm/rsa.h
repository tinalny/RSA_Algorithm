#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<cmath>
#include<boost/multiprecision/cpp_int.hpp>
#include<boost/multiprecision/random.hpp>
#include<boost/multiprecision/miller_rabin.hpp>
using namespace std;

#define NUMBER 256

typedef boost::multiprecision::int1024_t DataType;
namespace brdm = boost::random;

struct Key
{
	//公钥：(e,n) ，私钥(d,n)
	DataType m_ekey;
	DataType m_dkey;
	DataType m_pkey;
};

/*
步骤：
①：随机选取两个不相等的素数p,q
②：求两个素数的乘积n，n=p*q
③：求n的欧拉函数f(n),f(n) = (p-1)*(q-1)
④：求公钥e，1<e<f(n)且e与f(n)互质(e随机选取)
⑤：求私钥d，e*d mod f(n) = 1
*/

class RSA
{
	Key m_key;
public:
	RSA();
	void ecrept(const char * filename, const char * fileout);
	void decrept(const char * filename, const char * fileout);
	DataType ecrept(DataType data, DataType ekey, DataType pkey);//加密
	DataType decrept(DataType data, DataType dkey, DataType pkey);//解密
	DataType getPrime();
	bool isPrimeBigInt(DataType data);
	DataType getPkey(DataType prime1, DataType prime2);//求n
	DataType getOrla(DataType prime1, DataType prime2);
	DataType getEkey(DataType orla);
	DataType getDkey(DataType ekey, DataType orla);
	DataType getGcd(DataType data1, DataType data2);//获取最大公约数
	DataType exGcd(DataType a, DataType b, DataType &x, DataType& y);
	void getKeys();
	Key getallKey();
};
