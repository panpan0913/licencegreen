/*
功能：（1）读取计算机硬件信息、时间信息、各信息的长度；并生成硬件信息licence
（2）读取硬件信息licence，加密为key的licence
（3）应用程序中，读取加密的licence，判断系统是否可用
*/


//设为1，执行读取硬件的程序，目的;生成exe，发送给用户，用户运行后，在当前文件夹下，生成sysInfo_licence.lic文件。用户需要发送给我们
#if 0 
/*
功能说明：执行读取硬件的程序，目的，生成exe，发送给用户，
用户运行后，在当前文件夹下，生成sysInfo_licence.lic文件。
用户需要发送给我们
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

	int GetHardwareInfo_flag =	GetSystemHardwareInfo();//读取硬件信息并写进licence中
	switch (GetHardwareInfo_flag) {
	case 0:
		cout << "0 系统信息获取成功！"<< endl;
		break;
	case 1:
		cout << "1 Mac获取失败..." << endl;		break;
	case 2:
		cout << "2 cpu获取失败..." << endl;		break;
	case 3:
		cout << "3 mac长度获取失败... " << endl;		break;
	case 4:
		cout << "4 CPU长度获取失败... " << endl;		break;
	case 5:
		cout << "5 time长度获取失败... " << endl;		break;
	case 6:
		cout << "6 文件创建失败... " << endl;		break;
	default:
			break;
	}
	return 0;
}


#endif // 1//设为1，执行读取硬件的程序。目的：生成exe，发送给用户，用户运行后，在当前文件夹下，生成sysInfo_licence.lic文件。用户需要发送给我们

#if 0//设为1，执行解析硬件的licence。目的：生成exe，用户运行后，读取当前文件夹下sysInfo_licence.lic，生成加密过的licence文件。连同试用版程序一起发送给用户
/*
功能说明：执行解析硬件的licence，该文件来源于用户处的生成结果
目的：生成exe，用户运行后，读取当前文件夹下sysInfo_licence.lic，
解析出用户电脑信息（不显示出来）；生成加密过的licence文件。
连同试用版程序一起发送给用户
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
	
	
	ReCreateKeyLicenceToCustomer(str, time);//分别为密钥和使用时间（天）
	return 0;
}


#endif // 1


#if 0 //设为1；解析
/*
功能说明：在自己的软件系统中，加入以下代码，
此时，软件就在用户电脑上运行，因此，软件是可以读取该电脑信息，比对该信息和解析出来的是否一致，
如果一致，说明就是用户指定的电脑没
如果不一致，用户无法使用该软件
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
	licence文件读取失败，	返回1
	Mac获取失败，			返回2
	cpu获取失败，			返回3
	mac长度有误失败，		返回4
	CPU长度有误失败，		返回5
	time长度有误失败，		返回6
	mac比对失败 ，			返回7
	cpu比对失败 ，			返回8
	licence时间格式错误；   返回9，
	系统时间格式错误；		返回10，
	剩余时间充裕,			返回11，
	剩余时间不足;	剩余天数,返回负数：
	*/
	int isOk = DecodeKeyLicenceInMyCode();
	switch (isOk) {
	case 1:
		cout << "1 licence文件读取失败    " << endl;	break;
	case 2:
		cout << "2 Mac获取失败     " << endl;		break;
	case 3:
		cout << "3 cpu获取失败     " << endl;		break;
	case 4:
		cout << "4 mac长度有误失败     " << endl;		break;
	case 5:
		cout << "5 CPU长度有误失败    " << endl;		break;
	case 6:
		cout << "6 time长度有误失败       " << endl;		break;
	case 7:
		cout << "7 mac比对失败          " << endl;		break;
	case 8:
		cout << "8 cpu比对失败           " << endl;		break;
	case 9:
		cout << "9 licence时间格式错误    " << endl;		break;
	case 10:
		cout << "10 系统时间格式错误      " << endl;		break;
	case 11:
		cout << "11 剩余时间充裕        " << endl;		break;

	default:
		int RemainingTime = isOk; cout << RemainingTime << endl;

		break;
	}
	return 0;
}
#endif // 1



/*————————————————————（1）读取系统信息——————————————————
//运行代码实现，读取硬件信息及时间，ing写入到exe目录下的.lic中。
//入参：无
//输出：成功与否的提示信息
#define _CRT_SECURE_NO_WARNINGS
#include "GetSYSInfo.h"

int GetHardwareInfo_flag =	GetSystemHardwareInfo();//读取硬件信息并写进licence中
switch (GetHardwareInfo_flag) {
case 0:
	cout << "系统信息获取成功！"<< endl;
	break;
case 1:
	cout << "Mac获取失败..." << endl;		break;
case 2:
	cout << "cpu获取失败..." << endl;		break;
case 3:
	cout << "mac长度获取失败... " << endl;		break;
case 4:
	cout << "CPU长度获取失败... " << endl;		break;
case 5:
	cout << "time长度获取失败... " << endl;		break;
case 6:
	cout << "文件创建失败... " << endl;		break;
default:
		break;
}
system("pause");
*/

/*————————————————————（2）系统信息加密——————————————————
//运行代码实现，读取硬件信息及时间的lic，加密并写入新的.lic中。
//入参：密码、使用时间
//输出：exe同级目录下的.lic。不提示
#define _CRT_SECURE_NO_WARNINGS
 
#include "CreateKeyLicence.h"

ReCreateKeyLicenceToCustomer("dongkangle",120);
 
*/

/*————————————————————（3）解析lic，并判断是否成功——————————————————
//运行代码实现，读取加密过的lic，解析并判断是否可用。
//入参：无
//输出：返回提示信息，注程序通过调用其，实现判断lic是否可用
#define _CRT_SECURE_NO_WARNINGS
 
#include "Run.h"
int isOk=DecodeKeyLicenceInMyCode();
switch (isOk) {
case 1:
cout << "licence文件读取失败    " << endl;	break;
case 2:
cout << "Mac获取失败     " << endl;		break;
case 3:
cout << "cpu获取失败     " << endl;		break;
case 4:
cout << "mac长度有误失败     " << endl;		break;
case 5:
cout << "CPU长度有误失败    " << endl;		break;
case 6:
cout << "time长度有误失败       " << endl;		break;
case 7:
cout << "mac比对失败          " << endl;		break;
case 8:
cout << "cpu比对失败           " << endl;		break;
case 9:
cout << "licence时间格式错误    " << endl;		break;
case 10:
cout << "系统时间格式错误      " << endl;		break;
case 11:
cout << "剩余时间充裕        " << endl;		break;

default:
int RemainingTime = isOk; cout << RemainingTime<<endl;

break;
}
system("pause");
 

*/


/*————————————————————（4）使用调用dll的方式，解析lic，并判断是否成功——————————————————
//运行代码实现，读取硬件信息及时间的lic，加密并写入新的.lic中。
//入参：无
//输出：返回提示信息，注程序通过调用其，实现判断lic是否可用 
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
		cout << "licence文件读取失败    " << endl;	break;
	case 2:
		cout << "Mac获取失败     " << endl;		break;
	case 3:
		cout << "cpu获取失败     " << endl;		break;
	case 4:
		cout << "mac长度有误失败     " << endl;		break;
	case 5:
		cout << "CPU长度有误失败    " << endl;		break;
	case 6:
		cout << "time长度有误失败       " << endl;		break;
	case 7:
		cout << "mac比对失败          " << endl;		break;
	case 8:
		cout << "cpu比对失败           " << endl;		break;
	case 9:
		cout << "licence时间格式错误    " << endl;		break;
	case 10:
		cout << "系统时间格式错误      " << endl;		break;
	case 11:
		cout << "剩余时间充裕        " << endl;		break;

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






















