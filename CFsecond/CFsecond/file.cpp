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
		//只读
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
		//只写
	case WriteOnly:
		m_fileHandle = fopen(m_fileName, "w");

		//读写
	case ReadWrite:
		m_fileHandle = fopen(m_fileName, "r+");
	
		//追加
	case Append:
		m_fileHandle = fopen(m_fileName, "a");

		//截断
	case Truncate:
		m_fileHandle = fopen(m_fileName, "w");
		/*int a = 0;
		cout << "请输入截断的长度：" << endl;
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
	cout << "请输入文件地址" << endl;
	cin >> *location;
	const char *m_fileName = location;
    
}

int CFile::readBuffer(char *buf, int maxsize)//读数据，返回值是读入的字节数，maxsize表示最多读的字节数，读出的内容保存在 buf
{
	bool open(ReadOnly);
	int MAX_LINE = 1024;
	
	
	fread(buf,sizeof(m_fileHandle),1, m_fileHandle);

	maxsize = sizeof(buf);
	
	return maxsize;

}

int CFile::write(char *data)//写数据，返回值写入的字节数
{
	bool open(Append);

	//fwrite(data,sizeof(data),1, m_fileHandle);

	//返回写入的字节数
	int size = fwrite(data, sizeof(data), 1, m_fileHandle);
	//size = sizeof(data);
	return size;      
}