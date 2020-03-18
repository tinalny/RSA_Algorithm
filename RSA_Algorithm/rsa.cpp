#include"rsa.h"

RSA::RSA()
{
	getKeys();
}

void RSA::ecrept(const char * filename, const char * fileout)
{
	std::ifstream fin(filename, std::ifstream::binary);//模式，有二进制模式/文本文件模式
	std::ofstream fout(fileout, std::ifstream::binary);

	if (!fin.is_open())
	{
		perror("input file open failed!");
		return;
	}
	char* buffer = new char[NUMBER];
	DataType* bufferout = new DataType[NUMBER];
	while (!fin.eof())
	{
		fin.read(buffer, NUMBER);
		//gcount()可以获取最近一次读取的字节数
		int curNum = fin.gcount();
		for (int i = 0; i < curNum; i++)
		{
			bufferout[i] = ecrept((DataType)buffer[i], m_key.m_ekey, m_key.m_pkey);
		}
		fout.write((char*)bufferout, curNum * sizeof(DataType));
	}
	delete[] bufferout;
	delete[] buffer;

	fin.close();
	fout.close();
}

void RSA::decrept(const char * filename, const char * fileout)
{
	std::ifstream fin(filename, std::ifstream::binary);//模式，有二进制模式/文本文件模式
	std::ofstream fout(fileout, std::ifstream::binary);

	if (!fin.is_open())
	{
		perror("input file open failed!");
		return;
	}
	DataType* buffer = new DataType[NUMBER];
	char* bufferout = new char[NUMBER];
	while (!fin.eof())
	{
		fin.read((char*)buffer, NUMBER * sizeof(DataType));
		//gcount()可以获取最近一次读取的字节数
		int num = fin.gcount();//实际读取的字节
		num /= sizeof(DataType);
		for (int i = 0; i < num; i++)
		{
			bufferout[i] = (char)decrept(buffer[i], m_key.m_dkey, m_key.m_pkey);
		}
		fout.write(bufferout, num);
	}
	delete[] bufferout;
	delete[] buffer;

	fout.close();
	fin.close();
}

void RSA::getKeys()
{
	DataType prime1 = getPrime();
	DataType prime2 = getPrime();
	while (prime1 == prime2)
	{
		prime2 = getPrime();
	}
	DataType orla = getOrla(prime1, prime2);
	m_key.m_pkey = getPkey(prime1, prime2);
	m_key.m_ekey = getEkey(orla);
	m_key.m_dkey = getDkey(m_key.m_ekey, orla);
}

Key RSA::getallKey()
{
	return m_key;
}

DataType RSA::ecrept(DataType data, DataType ekey, DataType pkey)
{
	DataType Ai = data;
	DataType msgE = 1;
	while (ekey)
	{
		if (ekey & 1)
		{
			msgE = (msgE * Ai) % pkey;
		}
		ekey >>= 1;
		Ai = (Ai * Ai) % pkey;
	}
	return msgE;
}

DataType RSA::decrept(DataType data, DataType dkey, DataType pkey)
{
	return ecrept(data, dkey, pkey);
}

DataType RSA::getPrime()
{
	DataType prime;
	brdm::mt19937 gen(time(NULL));
	brdm::uniform_int_distribution<DataType> dist(0, DataType(1) << 256);

	while (true)
	{
		prime = dist(gen);
		if (isPrimeBigInt(prime))
		{
			break;
		}
	}
	return prime;
}

bool RSA::isPrimeBigInt(DataType data)
{
	brdm::mt11213b gen(time(NULL));
	if (miller_rabin_test(data, 25, gen))
	{
		if (miller_rabin_test((data - 1) / 2, 25, gen));
		{
			return true;
		}
	}
	return false;
}

DataType RSA::getPkey(DataType prime1, DataType prime2)
{
	return prime1*prime2;
}

DataType RSA::getOrla(DataType prime1, DataType prime2)
{
	return (prime1 - 1)*(prime2 - 1);
}

DataType RSA::getEkey(DataType orla)
{
	brdm::mt19937 gen(time(NULL));
	brdm::uniform_int_distribution<DataType> dist(2, orla);

	DataType ekey;
	while (true)
	{
		ekey = dist(gen);
		if (getGcd(ekey, orla) == 1)//两个数的最大公约数为1表示互质
		{
			return ekey;
		}
	}
}

DataType RSA::getDkey(DataType ekey, DataType orla)
{
	DataType x = 0, y = 0;
	exGcd(ekey, orla, x, y);
	//变换，让解密秘钥是一个比较小的正值(扩展的欧几里得定理)
	return (x% orla + orla) % orla;
}

//辗转相除法求最大公约数
//例如a,b两个数求最大公约数，可以等价为 b,a%b --->a%b, a%b%(a%b),....直到它们的余数为0
DataType RSA::getGcd(DataType data1, DataType data2)
{
	DataType residual;
	while (residual = data1%data2)
	{
		data1 = data2;
		data2 = residual;
	}
	return data2;
}

DataType RSA::exGcd(DataType a, DataType b, DataType &x, DataType& y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	DataType gcd = exGcd(b, a%b, x, y);
	DataType x1 = x, y1 = y;
	x = y1;
	y = x1 - a / b *y1;
	return gcd;
}
