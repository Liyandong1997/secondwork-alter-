#include<stdio.h>
#include<stdbool.h>
#include <string>
#include"file.h"
#include<iostream>
#include<fstream>

using namespace std;

CFile::CFile()
{

}

CFile::CFile(const char *file_name)
{

}

CFile::CFile(const CFile&)
{

}

bool CFile::open(OpenMode mode)
{

	int i = 0;
	i = mode;

	switch (i)
	{
		//ֻ��
	case ReadOnly:
		m_fileHandle = fopen(m_fileName, "r");

		/*if((m_fileHandle = fopen("file_1", "r")) == NULL)
		{
			printf("Cannot open this file\n");
			exit(0);
		}
		else {
			printf("open this file successfully\n");
		}*/
		//ֻд
	case WriteOnly:
		m_fileHandle = fopen(m_fileName, "w");

		//��д
	case ReadWrite:
		m_fileHandle = fopen(m_fileName, "r+");
	
		//׷��
	case Append:
		m_fileHandle = fopen(m_fileName, "a");

		//�ض�
	case Truncate:
		m_fileHandle = fopen(m_fileName, "w");
		/*int a = 0;
		cout << "������ضϵĳ��ȣ�" << endl;
		cin >> a;

		int truncate(const char *m_fileHandle, off_t  a);
	*/

	default:
		cout << "you enter the char is wrong!\n" << endl;

		break;
	}

	

	return 0;
}


void CFile::setFileName(const char *)
{
	char *location=0;
	cout << "�������ļ���ַ" << endl;
	cin >> *location;
	const char *m_fileName = location;
    
}

int CFile::readBuffer(char *buf, int maxsize)//�����ݣ�����ֵ�Ƕ�����ֽ�����maxsize��ʾ�������ֽ��������������ݱ����� buf
{
	bool open(ReadOnly);
	int MAX_LINE = 1024;
	
	
	fread(buf,sizeof(m_fileHandle),1, m_fileHandle);

	maxsize = sizeof(buf);
	
	return maxsize;

}

int CFile::write(char *data)//д���ݣ�����ֵд����ֽ���
{
	bool open(Append);

	//fwrite(data,sizeof(data),1, m_fileHandle);

	//����д����ֽ���
	int size = fwrite(data, sizeof(data), 1, m_fileHandle);
	//size = sizeof(data);
	return size;      
}