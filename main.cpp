/*
���ܣ���1����ȡ�����Ӳ����Ϣ��ʱ����Ϣ������Ϣ�ĳ��ȣ�������Ӳ����Ϣlicence
��2����ȡӲ����Ϣlicence������Ϊkey��licence
��3��Ӧ�ó����У���ȡ���ܵ�licence���ж�ϵͳ�Ƿ����
*/


//��Ϊ1��ִ�ж�ȡӲ���ĳ���Ŀ��;����exe�����͸��û����û����к��ڵ�ǰ�ļ����£�����sysInfo_licence.lic�ļ����û���Ҫ���͸�����
#if 0 
/*
����˵����ִ�ж�ȡӲ���ĳ���Ŀ�ģ�����exe�����͸��û���
�û����к��ڵ�ǰ�ļ����£�����sysInfo_licence.lic�ļ���
�û���Ҫ���͸�����
*/

#define _CRT_SECURE_NO_WARNINGS
#include "GetSYSInfo.h"
//#include "CreateKeyLicence.h"
//#include "Run.h"
//#include "AddDll.h"
#include <stdio.h>
#include <string.h> 
#include <iostream>
#include <string>
#include  <fstream>
#include <ctime>
#include <cstdio>

using namespace std;

int  main()
{

	int GetHardwareInfo_flag =	GetSystemHardwareInfo();//��ȡӲ����Ϣ��д��licence��
	switch (GetHardwareInfo_flag) {
	case 0:
		cout << "0 ϵͳ��Ϣ��ȡ�ɹ���"<< endl;
		break;
	case 1:
		cout << "1 Mac��ȡʧ��..." << endl;		break;
	case 2:
		cout << "2 cpu��ȡʧ��..." << endl;		break;
	case 3:
		cout << "3 mac���Ȼ�ȡʧ��... " << endl;		break;
	case 4:
		cout << "4 CPU���Ȼ�ȡʧ��... " << endl;		break;
	case 5:
		cout << "5 time���Ȼ�ȡʧ��... " << endl;		break;
	case 6:
		cout << "6 �ļ�����ʧ��... " << endl;		break;
	default:
			break;
	}
	return 0;
}


#endif // 1//��Ϊ1��ִ�ж�ȡӲ���ĳ���Ŀ�ģ�����exe�����͸��û����û����к��ڵ�ǰ�ļ����£�����sysInfo_licence.lic�ļ����û���Ҫ���͸�����

#if 0//��Ϊ1��ִ�н���Ӳ����licence��Ŀ�ģ�����exe���û����к󣬶�ȡ��ǰ�ļ�����sysInfo_licence.lic�����ɼ��ܹ���licence�ļ�����ͬ���ð����һ���͸��û�
/*
����˵����ִ�н���Ӳ����licence�����ļ���Դ���û��������ɽ��
Ŀ�ģ�����exe���û����к󣬶�ȡ��ǰ�ļ�����sysInfo_licence.lic��
�������û�������Ϣ������ʾ�����������ɼ��ܹ���licence�ļ���
��ͬ���ð����һ���͸��û�
*/
#define _CRT_SECURE_NO_WARNINGS
#include "CreateKeyLicence.h"
//#include "Run.h"
//#include "AddDll.h"
#include <stdio.h>
#include <string.h> 
#include <iostream>
#include <string>
#include  <fstream>
#include <ctime>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	std::string str = "zhangpan";
	int time = 120;
	for (size_t i = 0; i < argc; i++)
	{
		if (std::string(argv[i]) == "-u")
		{
			if (i + 1 >= argc)
			{
				cout << "need userid" << endl;
				return 0;
			}

			str = argv[i + 1];
			i++;
		}
		else if (std::string(argv[i]) == "-t")
		{
			if (i + 1 >= argc)
			{
				cout << "need time" << endl;
				return 0;
			}

			time = atoi(argv[i + 1]);
			i++;
		}
		else
		{
			cout << "unknow param:" << argv[i] << endl;
		}
	}
	
	
	ReCreateKeyLicenceToCustomer(str, time);//�ֱ�Ϊ��Կ��ʹ��ʱ�䣨�죩
	return 0;
}


#endif // 1


#if 0 //��Ϊ1������
/*
����˵�������Լ������ϵͳ�У��������´��룬
��ʱ����������û����������У���ˣ�����ǿ��Զ�ȡ�õ�����Ϣ���ȶԸ���Ϣ�ͽ����������Ƿ�һ�£�
���һ�£�˵�������û�ָ���ĵ���û
�����һ�£��û��޷�ʹ�ø����
*/
#define _CRT_SECURE_NO_WARNINGS
//#include "GetSYSInfo.h"
//#include "CreateKeyLicence.h"
#include "Run.h"
#include <stdio.h>
#include <string.h> 
#include <iostream>
#include <string>
#include  <fstream>
#include <ctime>
#include <cstdio>

using namespace std;

int  main()
{
	/*
	licence�ļ���ȡʧ�ܣ�	����1
	Mac��ȡʧ�ܣ�			����2
	cpu��ȡʧ�ܣ�			����3
	mac��������ʧ�ܣ�		����4
	CPU��������ʧ�ܣ�		����5
	time��������ʧ�ܣ�		����6
	mac�ȶ�ʧ�� ��			����7
	cpu�ȶ�ʧ�� ��			����8
	licenceʱ���ʽ����   ����9��
	ϵͳʱ���ʽ����		����10��
	ʣ��ʱ���ԣ,			����11��
	ʣ��ʱ�䲻��;	ʣ������,���ظ�����
	*/
	int isOk = DecodeKeyLicenceInMyCode();
	switch (isOk) {
	case 1:
		cout << "1 licence�ļ���ȡʧ��    " << endl;	break;
	case 2:
		cout << "2 Mac��ȡʧ��     " << endl;		break;
	case 3:
		cout << "3 cpu��ȡʧ��     " << endl;		break;
	case 4:
		cout << "4 mac��������ʧ��     " << endl;		break;
	case 5:
		cout << "5 CPU��������ʧ��    " << endl;		break;
	case 6:
		cout << "6 time��������ʧ��       " << endl;		break;
	case 7:
		cout << "7 mac�ȶ�ʧ��          " << endl;		break;
	case 8:
		cout << "8 cpu�ȶ�ʧ��           " << endl;		break;
	case 9:
		cout << "9 licenceʱ���ʽ����    " << endl;		break;
	case 10:
		cout << "10 ϵͳʱ���ʽ����      " << endl;		break;
	case 11:
		cout << "11 ʣ��ʱ���ԣ        " << endl;		break;

	default:
		int RemainingTime = isOk; cout << RemainingTime << endl;

		break;
	}
	return 0;
}
#endif // 1



/*������������������������������������������1����ȡϵͳ��Ϣ������������������������������������
//���д���ʵ�֣���ȡӲ����Ϣ��ʱ�䣬ingд�뵽exeĿ¼�µ�.lic�С�
//��Σ���
//������ɹ�������ʾ��Ϣ
#define _CRT_SECURE_NO_WARNINGS
#include "GetSYSInfo.h"

int GetHardwareInfo_flag =	GetSystemHardwareInfo();//��ȡӲ����Ϣ��д��licence��
switch (GetHardwareInfo_flag) {
case 0:
	cout << "ϵͳ��Ϣ��ȡ�ɹ���"<< endl;
	break;
case 1:
	cout << "Mac��ȡʧ��..." << endl;		break;
case 2:
	cout << "cpu��ȡʧ��..." << endl;		break;
case 3:
	cout << "mac���Ȼ�ȡʧ��... " << endl;		break;
case 4:
	cout << "CPU���Ȼ�ȡʧ��... " << endl;		break;
case 5:
	cout << "time���Ȼ�ȡʧ��... " << endl;		break;
case 6:
	cout << "�ļ�����ʧ��... " << endl;		break;
default:
		break;
}
system("pause");
*/

/*������������������������������������������2��ϵͳ��Ϣ���ܡ�����������������������������������
//���д���ʵ�֣���ȡӲ����Ϣ��ʱ���lic�����ܲ�д���µ�.lic�С�
//��Σ����롢ʹ��ʱ��
//�����exeͬ��Ŀ¼�µ�.lic������ʾ
#define _CRT_SECURE_NO_WARNINGS
 
#include "CreateKeyLicence.h"

ReCreateKeyLicenceToCustomer("dongkangle",120);
 
*/

/*������������������������������������������3������lic�����ж��Ƿ�ɹ�������������������������������������
//���д���ʵ�֣���ȡ���ܹ���lic���������ж��Ƿ���á�
//��Σ���
//�����������ʾ��Ϣ��ע����ͨ�������䣬ʵ���ж�lic�Ƿ����
#define _CRT_SECURE_NO_WARNINGS
 
#include "Run.h"
int isOk=DecodeKeyLicenceInMyCode();
switch (isOk) {
case 1:
cout << "licence�ļ���ȡʧ��    " << endl;	break;
case 2:
cout << "Mac��ȡʧ��     " << endl;		break;
case 3:
cout << "cpu��ȡʧ��     " << endl;		break;
case 4:
cout << "mac��������ʧ��     " << endl;		break;
case 5:
cout << "CPU��������ʧ��    " << endl;		break;
case 6:
cout << "time��������ʧ��       " << endl;		break;
case 7:
cout << "mac�ȶ�ʧ��          " << endl;		break;
case 8:
cout << "cpu�ȶ�ʧ��           " << endl;		break;
case 9:
cout << "licenceʱ���ʽ����    " << endl;		break;
case 10:
cout << "ϵͳʱ���ʽ����      " << endl;		break;
case 11:
cout << "ʣ��ʱ���ԣ        " << endl;		break;

default:
int RemainingTime = isOk; cout << RemainingTime<<endl;

break;
}
system("pause");
 

*/


/*������������������������������������������4��ʹ�õ���dll�ķ�ʽ������lic�����ж��Ƿ�ɹ�������������������������������������
//���д���ʵ�֣���ȡӲ����Ϣ��ʱ���lic�����ܲ�д���µ�.lic�С�
//��Σ���
//�����������ʾ��Ϣ��ע����ͨ�������䣬ʵ���ж�lic�Ƿ���� 
#define _CRT_SECURE_NO_WARNINGS
#include "AddDll.h"
#include <stdio.h>
#include <string.h> 
#include <iostream>
#include <string>
#include <windows.h>
#include  <fstream>
#include <ctime>
#include <cstdio>

using namespace std;
void  main()
{
 
	int isOk = DecodeKeyLicenceInMyCode();
	switch (isOk) {
	case 1:
		cout << "licence�ļ���ȡʧ��    " << endl;	break;
	case 2:
		cout << "Mac��ȡʧ��     " << endl;		break;
	case 3:
		cout << "cpu��ȡʧ��     " << endl;		break;
	case 4:
		cout << "mac��������ʧ��     " << endl;		break;
	case 5:
		cout << "CPU��������ʧ��    " << endl;		break;
	case 6:
		cout << "time��������ʧ��       " << endl;		break;
	case 7:
		cout << "mac�ȶ�ʧ��          " << endl;		break;
	case 8:
		cout << "cpu�ȶ�ʧ��           " << endl;		break;
	case 9:
		cout << "licenceʱ���ʽ����    " << endl;		break;
	case 10:
		cout << "ϵͳʱ���ʽ����      " << endl;		break;
	case 11:
		cout << "ʣ��ʱ���ԣ        " << endl;		break;

	default:
		int RemainingTime = isOk; cout << RemainingTime << endl;

		break;
	}
	system("pause");

}



*/
#if 1
#include "Run.h"


#endif // 1






















