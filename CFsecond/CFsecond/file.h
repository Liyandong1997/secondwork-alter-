#pragma once
#include<stdio.h>
#include<stdbool.h>
#include <string>
class CFile
{
public:
	CFile();
	CFile(const char *file_name);
	//��������
	CFile(const CFile &);

	enum OpenMode
	{
		ReadOnly,  //ֻ��
		WriteOnly, //ֻд
		ReadWrite, //��д
		Append,	//׷�ӣ���ԭ���ļ���ĩβд��
		Truncate   //�ضϣ����ļ���ԭ������ȫ����գ��ٶ�д�ļ�
	};

	bool open(OpenMode mode);
	void setFileName(const char *);

	int readBuffer(char *buf, int maxsize); //�����ݣ�����ֵ�Ƕ�����ֽ�����maxsize��ʾ�������ֽ��������������ݱ����� buf
	int write(char *data);			//д���ݣ�����ֵд����ֽ���

private:
	FILE *m_fileHandle;
	const char *m_fileName;
};