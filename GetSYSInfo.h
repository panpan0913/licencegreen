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
//--------------------------------------------------------------
//						����MAC��ַ
//--------------------------------------------------------------

static std::string getCurrentTimeStr()
{
	time_t t = time(NULL);
	char ch[64] = { 0 };
	strftime(ch, sizeof(ch) - 1, "%Y$%m$%d", localtime(&t));     //��-��-�� ʱ-��-��
	return ch;
}

int GetSystemHardwareInfo( )
{
	char lpszMac[128] = "";
	if (!get_mac_address(lpszMac,"ens33"))
	{
		return 1;//Mac��ȡʧ�ܣ�����1
	} 
	std::string macs = lpszMac;

	char lpszCpu[128] = "";
	if (!get_cpuid(lpszCpu))
	{
		return 2;//cpu��ȡʧ�ܣ�����1
	}
	std::string CpuId = lpszCpu;

	std::string TimeStr = getCurrentTimeStr();//��ȡϵͳ��ǰʱ����ַ�������?$��$�ո�ʽ

	int MacIDSize = macs.size();
	if (MacIDSize == 0)
	{
		return 3;//mac��������ʧ�ܣ�����3
	}
	int CPUIDSize = CpuId.size();
	if (CPUIDSize == 0)
	{
		return 4;//CPU��������ʧ�ܣ�����4
	}
	int timeSize = TimeStr.size();
	if (timeSize == 0)
	{
		return 5;//time��������ʧ�ܣ�����5
	}

	std::ofstream OutFile("sysInfo_licence.lic");

	if (OutFile)
	{
		OutFile << "SystemHardwareInfo:" << "\n" << MacIDSize << "\n" << CPUIDSize << "\n" << timeSize << "\n" << macs << "\n" << CpuId << "\n" << TimeStr;
		OutFile.close();					//�ر��ļ�
		return 0;//�ɹ�������0
	}
	else
	{
		return 6;//�ļ�����ʧ�ܣ����ߴ򲻿�������ʱ��Ĭ���ǻ��ж��Ƿ���ڣ���������ڣ��Զ������ģ�
	}
}