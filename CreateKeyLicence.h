#ifndef _CREATEKEYLICENCE_H_
#define _CREATEKEYLICENCE_H_
#include <stdio.h>
#include <string.h> 
#include <iostream>
#include <string>
#include  <fstream>
#include <ctime>
#include <cstdio>

#include "Encode.h"

using namespace std;
#ifdef UNICODE
typedef wchar_t TCHAR;
#else
typedef char TCHAR;
#endif

void base64EncodeString(const char *textToEncode, char *buffer)
{
	base64_encodestate state;
	base64_init_encodestate(&state);
	int numberOfBytesEncoded = base64_encode_block(textToEncode, strlen(textToEncode), buffer, &state);
	numberOfBytesEncoded += base64_encode_blockend(buffer + numberOfBytesEncoded, &state);
	buffer[numberOfBytesEncoded] = '\0';
}

int ReCreateKeyLicenceToCustomer(string strKey, int usingTime)//��ȡȥ�����Ի��з���Ӳ����Ϣlicence
{
	//��ȡ�û����ص�Ӳ����Ϣlicence
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

	const char *inputFilename = "sysInfo_licence.lic";
	FILE *inputFile = fopen(inputFilename, "rb");
	if (inputFile)
	{
		while (!feof(inputFile))
		{
			fgets(readBuffer0, 128, inputFile);			//����1��KeyLicenceFile:
			fgets(readBuffer1, 128, inputFile);			//����2��   
			fgets(readBuffer2, 128, inputFile);			//����3��   mac���ַ����� ���������ʹ�ã�
			fgets(readBuffer3, 128, inputFile);			//����4��  cpuid���ַ����� ���������ʹ�ã�
			fgets(readBuffer4, 128, inputFile);			//����5��   time���ַ����� ���������ʹ�ã�
			fgets(readBuffer5, 128, inputFile);			//����6��   key���ַ����� ���������ʹ�ã���
			fgets(readBuffer6, 128, inputFile);			//����7��//   �ո񣨱�־�У���

		}
		fclose(inputFile);
	}
	else
		printf("Cannot open file: %s\n", inputFilename);

	//���м��ܹ���
	char KeyreadBuffer1[128] = "";
	char KeyreadBuffer2[128] = "";
	char KeyreadBuffer3[128] = "";
	char KeyreadBuffer4[128] = "";
	char KeyreadBuffer5[128] = "";
	char KeyreadkeySize[128] = "";

	char KeyreadBuffer6[128] = "";
	char KeyreadBuffer7[128] = "";
	char KeyreadBuffer8[128] = "";
	char KeyreadBuffer9[128] = "";
	char KeyreadBuffer10[128] = "";
	char UseingTimeStr[128] = "";

	int keySizeNumb = strKey.size();
	string keySize = to_string(keySizeNumb);
	string UseingTime = to_string(usingTime);//ʹ��ʱ���intתstring

	base64EncodeString(readBuffer1, KeyreadBuffer1);//��mac���ַ����� ����
	base64EncodeString(readBuffer2, KeyreadBuffer2);//��mac���ַ����� ����
	base64EncodeString(readBuffer3, KeyreadBuffer3);//��cpu���ַ����� ����

	base64EncodeString(keySize.data(), KeyreadkeySize);//��key���ַ����� ����
	base64EncodeString(UseingTime.data(), UseingTimeStr);//��key���ַ����� ����

	base64EncodeString(readBuffer4, KeyreadBuffer4);//��time���ַ����� ����
	base64EncodeString(readBuffer5, KeyreadBuffer5);//��time���ַ����� ����
	base64EncodeString(readBuffer6, KeyreadBuffer6);//��mac ����

	base64EncodeString((strKey).data(), KeyreadBuffer9); //��key ����

														 //�����µ�keylicence.lic
	ofstream OutFile("key_licence_Key_out_V1.0.lic"/*,fstream::out*/); //���ù��캯������txt�ı������Ҵ򿪸��ı�
	if (OutFile)
	{
		OutFile << "Key_V1.0:" << "\n" << KeyreadBuffer1 << KeyreadBuffer2 << KeyreadBuffer3 << KeyreadkeySize << UseingTimeStr << KeyreadBuffer4 << KeyreadBuffer5 << KeyreadBuffer6 << KeyreadBuffer9;
		OutFile.close();					//�ر��ļ�
		return 0;//�ɹ�������0
	}
	else
	{
		return 6;//�ļ�����ʧ�ܣ����ߴ򲻿�������ʱ��Ĭ���ǻ��ж��Ƿ���ڣ���������ڣ��Զ������ģ�
	}
	return 0;
}

#endif // !_CREATEKEYLICENCE_H_