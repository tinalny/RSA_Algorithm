#pragma once
#include "rsa.h"
#include "windows.h"

class RsaMenu
{
	RSA rsa;
public:
	void menu()
	{
		RSA rsa;
		int choose;
		DataType prime1 = rsa.getPrime();
		DataType prime2 = rsa.getPrime();
		DataType orla = rsa.getOrla(prime1, prime2);
		DataType ekey = rsa.getEkey(orla);
		DataType dkey = rsa.getDkey(ekey, orla);

		while (1)
		{
			system("cls");
			cout << "\t\t\t---------------------------------------------------" << endl;
			cout << "\t\t\t|           --- RSA ���ܹ��߲˵�ѡ�� ---          |" << endl;
			cout << "\t\t\t|                1����ȡ����                      |" << endl;
			cout << "\t\t\t|                2����ȡŷ������                  |" << endl;
			cout << "\t\t\t|                3����ȡ��Կ                      |" << endl;
			cout << "\t\t\t|                4����ȡ˽Կ                      |" << endl;
			cout << "\t\t\t|                5����ȡ�����ļ�                  |" << endl;
			cout << "\t\t\t|                6����ȡ�����ļ�                  |" << endl;
			cout << "\t\t\t|                7���˳�����                      |" << endl;
			cout << "\t\t\t---------------------------------------------------" << endl;
			cout << "\t\t\t���������ѡ��";
			cin >> choose;
			if (choose == 1)
			{
				system("cls");
				cout << "prime1 = " << rsa.getPrime() << endl;
				cout << "prime2 = " << rsa.getPrime() << endl;
				wait();
				Sleep(1000);
			}
			else if (choose == 2)
			{
				system("cls");
				cout << "orla = " << orla << endl;
				wait();
				Sleep(1000);
			}
			else if (choose == 3)
			{
				system("cls");
				cout << "ekey = " << ekey << endl;
				wait();
				Sleep(1000);

			}
			else if (choose == 4)
			{
				system("cls");
				cout << "dkey = " << dkey << endl;
				wait();
				Sleep(1000);
			}
			else if (choose == 5)
			{
				rsa.ecrept("test.txt", "test.ecrept.txt");
				wait();
				Sleep(1000);
			}
			else if (choose == 6)
			{
				rsa.decrept("test.ecrept.txt", "test.decrept.txt");
				wait();
				Sleep(1000);
			}
			else
			{
				system("cls");
				exit();
				Sleep(1000);
				break;
			}
		}
	}


	void wait()
	{
		cout << "\t\t\t---------------------------------------------------" << endl;
		cout << "\t\t\t|                                                 | " << endl;
		cout << "\t\t\t|          --- ��������������˵� ---             |" << endl;
		cout << "\t\t\t|                                                 |" << endl;
		cout << "\t\t\t---------------------------------------------------" << endl;
		system("pause");
	}

	void exit()
	{
		cout << "\t\t\t---------------------------------------------------" << endl;
		cout << "\t\t\t|                                                 | " << endl;
		cout << "\t\t\t|                   --- �˳��ɹ� ---              |" << endl;
		cout << "\t\t\t|                                                 |" << endl;
		cout << "\t\t\t---------------------------------------------------" << endl;
	}
};