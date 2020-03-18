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
			cout << "\t\t\t|           --- RSA 加密工具菜单选择 ---          |" << endl;
			cout << "\t\t\t|                1、获取素数                      |" << endl;
			cout << "\t\t\t|                2、获取欧拉函数                  |" << endl;
			cout << "\t\t\t|                3、获取公钥                      |" << endl;
			cout << "\t\t\t|                4、获取私钥                      |" << endl;
			cout << "\t\t\t|                5、获取加密文件                  |" << endl;
			cout << "\t\t\t|                6、获取解密文件                  |" << endl;
			cout << "\t\t\t|                7、退出程序                      |" << endl;
			cout << "\t\t\t---------------------------------------------------" << endl;
			cout << "\t\t\t请输入你的选择：";
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
		cout << "\t\t\t|          --- 按任意键返回主菜单 ---             |" << endl;
		cout << "\t\t\t|                                                 |" << endl;
		cout << "\t\t\t---------------------------------------------------" << endl;
		system("pause");
	}

	void exit()
	{
		cout << "\t\t\t---------------------------------------------------" << endl;
		cout << "\t\t\t|                                                 | " << endl;
		cout << "\t\t\t|                   --- 退出成功 ---              |" << endl;
		cout << "\t\t\t|                                                 |" << endl;
		cout << "\t\t\t---------------------------------------------------" << endl;
	}
};