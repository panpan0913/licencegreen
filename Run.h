#ifndef _RUN_H_
#define _RUN_H_
#include <stdio.h>
#include <string.h> 
#include <iostream>
#include <string>
#include  <fstream>
#include <ctime>
#include <cstdio>

#include "Decode.h"

#include "differTime.h"

using namespace std;
#ifdef UNICODE
typedef wchar_t TCHAR;
#else
typedef char TCHAR;
#endif

#include <cpuid.h>
#include <stdio.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <netdb.h>
#include <time.h>
#include <string>
#include <fstream>

bool get_cpuid(char* buf) {
    unsigned int eax, ebx, ecx, edx;
    if (__get_cpuid(1, &eax, &ebx, &ecx, &edx)) {
        sprintf(buf, "%08x%08x%08x%08x", eax, ebx, ecx, edx);
        return true;
    } else {
        return false;
    }
}

#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>

bool get_mac_address(char* buf, const char* iface) {
	int fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (fd == -1) {
		return false;
	}

	struct ifreq ifr;
	strcpy(ifr.ifr_name, iface);

	if (ioctl(fd, SIOCGIFHWADDR, &ifr) == -1) {
		close(fd);
		return false;
	}

	close(fd);

	const unsigned char* mac = (unsigned char*)ifr.ifr_hwaddr.sa_data;
	sprintf(buf, "%02x:%02x:%02x:%02x:%02x:%02x", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

	return true;
}

void base64DecodeString(const char *codeToDecode, char *buffer)
{
	base64_decodestate state;
	base64_init_decodestate(&state);
	int numberOfCharactersDecoded = base64_decode_block(codeToDecode, strlen(codeToDecode), buffer, &state);
	buffer[numberOfCharactersDecoded] = '\0';
}

static string  getCurrentTimeStr()
{
	time_t t = time(NULL);
	char ch[64] = { 0 };
	strftime(ch, sizeof(ch) - 1, "%Y$%m$%d", localtime(&t));     //��-��-�� ʱ-��-��
	return ch;
}
/*
�˶δ���Ӧ��������ʵ����Ŀ�ĳ�ʼ���У������ж��Ƿ����?

*/
int DecodeKeyLicenceInMyCode()
{
	//��ȡ�û���keylicence�ļ�����������Ӧ�е�����

	char readBuffer0[128] = "";
	char readBuffer1[128] = "";
	char readBuffer2[128] = "";
	char readBuffer3[128] = "";
	char readBuffer4[128] = "";
	char readBuffer5[128] = "";
	char readBuffer6[128] = "";
	char readBuffer7[128] = "";
	char readBuffer8[128] = "";
	char readBuffer9[128] = "";

	const char *inputFilename = "key_licence_Key_out_V1.0.lic";
	FILE *inputFile = fopen(inputFilename, "rb");
	if (inputFile)
	{
		while (!feof(inputFile))
		{
		 
			fgets(readBuffer0, 128, inputFile);		//����1��KeyLicenceFile:

			fgets(readBuffer1, 128, inputFile);		//����2��   
			fgets(readBuffer2, 128, inputFile);		//����3��   mac���ַ����� ���������ʹ�ã�?
			fgets(readBuffer3, 128, inputFile);		//����4��  cpuid���ַ����� ���������ʹ�ã�?
			fgets(readBuffer4, 128, inputFile);		//����5��   time���ַ����� ���������ʹ�ã�?

			fgets(readBuffer5, 128, inputFile);		//����6��   key���ַ����� ���������ʹ�ã���?
			fgets(readBuffer6, 128, inputFile);		//����7��//   �ո񣨱�־�У���
			fgets(readBuffer7, 128, inputFile);		//����8��// Mac��string
			fgets(readBuffer8, 128, inputFile);		//����9��// cpu�� string 
			fgets(readBuffer9, 128, inputFile);		//����10��// time��string

		}
		fclose(inputFile);
	}
	else
		return 1;//licence�ļ���ȡʧ�ܣ�����1///////////////////////////////////////////////////////////////////////////////////////
	//�Զ�Ӧ�н��н���
	char	macSize[128] = "";
	char	cpuSize[128] = "";
	char	timeSize[128] = "";
	char	KeySizeOutstr[128] = "";

	char	macOutstr[128] = "";
	char	cpuOutstr[128] = "";
	char	timeOutstr[128] = "";
	char	keyOutstr[128] = "";
	char	UseingTimeOutstr[128] = "";

	base64DecodeString(readBuffer1, macSize);//����Mac 
	base64DecodeString(readBuffer2, cpuSize);//����Mac 
	base64DecodeString(readBuffer3, timeSize);//����Mac 
	base64DecodeString(readBuffer4, KeySizeOutstr);//����Mac 

	base64DecodeString(readBuffer5, UseingTimeOutstr);// ʹ��ʱ�� 
	base64DecodeString(readBuffer6, macOutstr);//  Mac 
	base64DecodeString(readBuffer7, cpuOutstr);//  cpu 
	base64DecodeString(readBuffer8, timeOutstr);//  Time
	base64DecodeString(readBuffer9, keyOutstr);// key

	string	macSizeTostr = macSize;
	int macNumb = atoi(macSizeTostr.c_str());

	string	cpuSizeTostr = cpuSize;
	int cpuNumb = atoi(cpuSizeTostr.c_str());

	string	timeSizeTostr = timeSize;
	string	KeySizeOutstrTo = KeySizeOutstr;

	string	macOutstrTostr = macOutstr;
	string	cpuOutstrTostr = cpuOutstr;
	string	timeOutstrTostr = timeOutstr;
	string	keyOutstrTostr = keyOutstr;
	string	UseingTimeOutstrTostr = UseingTimeOutstr;
	//��ȡ��ǰ�����ϵͳ��Ӳ�����?
	char lpszMac[128] = "";
	if (!get_mac_address(lpszMac, "ens33"))
	{
		return 2;//Mac��ȡʧ�ܣ�����2///////////////////////////////////////////////////////////////////////////////////////
	}
	string macs = lpszMac;

	char lpszCpu[128] = "";
	if (!get_cpuid(lpszCpu))
	{
		return 3;//cpu��ȡʧ�ܣ�����3///////////////////////////////////////////////////////////////////////////////////////
	}
	string CpuId = lpszCpu;

	string TimeStr = getCurrentTimeStr();//��ȡϵͳ��ǰʱ����ַ�������?$��$�ո�ʽ

	int MacIDSize = macs.size();
	if (MacIDSize == 0)
	{
		return 4;//mac��������ʧ�ܣ�����4///////////////////////////////////////////////////////////////////////////////////////
	}
	int CPUIDSize = CpuId.size();
	if (CPUIDSize == 0)
	{
		return 5;//CPU��������ʧ�ܣ�����5///////////////////////////////////////////////////////////////////////////////////////
	}
	int timeSizeSys = TimeStr.size();
	if (timeSizeSys == 0)
	{
		return 6;//time��������ʧ�ܣ�����6///////////////////////////////////////////////////////////////////////////////////////
	}

	//�ж�key�����ĺ�ϵͳ�������Ƿ�һ��
	string pureMacLic = macOutstrTostr.substr(0, macNumb);
	string pureMacSys = macs.substr(0, macNumb);
	int sameMac = strcmp(pureMacLic.data(), pureMacSys.data());//�ж�mac

	int samecpu = 0;//�ж�cpu
	for (size_t i = 0; i < cpuNumb; i++)
	{
		if (cpuOutstrTostr[i] != CpuId[i])
		{
			samecpu++;
		}
	}

	 //������Ӧ��Ϣ
	if (0 != sameMac)
	{
		return 7;//mac�ȶ�ʧ�� ������7///////////////////////////////////////////////////////////////////////////////////////
	}
	if (samecpu > 1)
	{

		cout << "samecpu = " << samecpu << endl;
		return 8;//cpu�ȶ�ʧ�� ������8///////////////////////////////////////////////////////////////////////////////////////
	}

	//�ж�ʣ��ʹ������
	return  TimeDiff(timeOutstrTostr, stoi("10"));//����9��licenceʱ���ʽ���󣻷���?10��ϵͳʱ���ʽ����?//����11��ʣ��ʱ����?///////////////////////////////////////////////////////////////////////////////////////
	//���ظ�����ʣ�����ʹ������?
}

#endif