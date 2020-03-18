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
	//��Կ��(e,n) ��˽Կ(d,n)
	DataType m_ekey;
	DataType m_dkey;
	DataType m_pkey;
};

/*
���裺
�٣����ѡȡ��������ȵ�����p,q
�ڣ������������ĳ˻�n��n=p*q
�ۣ���n��ŷ������f(n),f(n) = (p-1)*(q-1)
�ܣ���Կe��1<e<f(n)��e��f(n)����(e���ѡȡ)
�ݣ���˽Կd��e*d mod f(n) = 1
*/

class RSA
{
	Key m_key;
public:
	RSA();
	void ecrept(const char * filename, const char * fileout);
	void decrept(const char * filename, const char * fileout);
	DataType ecrept(DataType data, DataType ekey, DataType pkey);//����
	DataType decrept(DataType data, DataType dkey, DataType pkey);//����
	DataType getPrime();
	bool isPrimeBigInt(DataType data);
	DataType getPkey(DataType prime1, DataType prime2);//��n
	DataType getOrla(DataType prime1, DataType prime2);
	DataType getEkey(DataType orla);
	DataType getDkey(DataType ekey, DataType orla);
	DataType getGcd(DataType data1, DataType data2);//��ȡ���Լ��
	DataType exGcd(DataType a, DataType b, DataType &x, DataType& y);
	void getKeys();
	Key getallKey();
};
