// Helper.cpp
//
// CHelper class impmementation file
//
// CHelper class is a part of the MafiaLib Engine
//
// Copyright (c) 2003, 2004 ASM

#include "Helper.h"
#include <math.h>
#include <qmessagebox.h>
#include <qstring.h>

CHelper::CHelper(void)
{
}

CHelper::~CHelper(void)
{
}

// Function	: Char2LongBE
//
// Purpose	: Converts a string buffer to long
unsigned long CHelper::Char2Long(BYTE *ptr,int size)
{
	long lOut=0;
	for(int i=0;i<size;i++)
	{
		lOut<<=8;
		lOut|=ptr[i];
	}
	return(lOut);
}

unsigned long CHelper::Char2Long(BYTE *ptr)
{
	long lOut=0;
	for(int i=0;i<4;i++)
	{
		lOut<<=8;
		lOut|=ptr[i];
	}
	return(lOut);
}

// Function	: Char2LongE
//
// Purpse	: Converts a string buffer to long but reverses the order of the digits
unsigned long CHelper::Char2LongE(BYTE * ptr, int size)
{
	long lOut=0;
	for(int i=0;i<size;i++)
	{
		lOut<<=8;
		lOut|=ptr[size-i-1];
	}
	return(lOut);
}

unsigned long CHelper::Char2LongE(BYTE * ptr)
{
	long lOut=0;
	for(int i=0;i<4;i++)
	{
		lOut<<=8;
		lOut|=ptr[4-i-1];
	}
	return(lOut);
}
// Reverses bit order in a long value -- useful for converting big to little endian and vice versa

long CHelper::ReverseBits(unsigned long value, int type, int times)
{
	int i, shift;
	unsigned long lDummy=0, lDummy2=0;
	switch(type)
	{
		case TYPE_BYTE:
			for(i=0,shift=0;i<times;i++,shift+=8)
			{
				lDummy=value>>shift;
				lDummy&=0x000000FF;
				lDummy2<<=8;
				lDummy2|=lDummy;
			}
			break;
		case TYPE_WORD:
			for(i=0,shift=0;i<times;i++,shift+=16)
			{
				lDummy=value>>shift;
				lDummy&=0x0000FFFF;
				lDummy2<<=16;
				lDummy2|=lDummy;
			}
			break;
	}
	return(lDummy2);
}

void CHelper::Long2String(char *out, long number, long size)
{
	int i,shift;
	long dummy;
	for(i=0,shift=0;i<8;i++,shift+=4)
	{
		dummy=number>>shift;
		dummy&=MASK;
		if(dummy>=0 && dummy<=9)
			out[size-i-1]=dummy+0x30;
		else
			out[size-i-1]=dummy+0x37;
	}
	out[i]|=0;
	return;
}

// Used for reading data and buffering it in a temporary file
long CHelper::BufferData(HANDLE hFile, char * szFilename, long lSize)
{
	long lBytesMoved=0;
	unsigned long lBytesRead=0, lBytesWritten=0;
	HANDLE hFileOwn;
	char dummy;

	// open own file
	hFileOwn=CreateFile(szFilename,GENERIC_WRITE,FILE_SHARE_READ,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,NULL);

	// Read out all data of the current position of the Filepointer till we reach EOF
	// or till lSize bytes were read
	do{
		ReadFile(hFile,&dummy,1,&lBytesRead,NULL);
		WriteFile(hFileOwn,&dummy,1,&lBytesWritten,NULL);
		if(lBytesRead!=0)			// we have to check this
			lBytesMoved++;			// lBytesMoved would be invalid if file is read till EOF
	}while((lBytesRead!=0)&&(lBytesMoved!=lSize));

	// close my own file
	CloseHandle(hFileOwn);

	// Move filepointer back
	SetFilePointer(hFile,-(lBytesMoved),0,FILE_CURRENT);

	return(lBytesMoved);
}
// Reads out buffered data and puts it into the currently opened file
long CHelper::PasteBufferedData(HANDLE hFile, char * szFilename, bool bDel)
{
	int i=0;
	char dummy;
	unsigned long lBytesRead=0, lBytesWritten=0;
	HANDLE hFileOwn;

	// open own file
	hFileOwn=CreateFile(szFilename,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,NULL);

	do
	{
		ReadFile(hFileOwn,&dummy,1,&lBytesRead,NULL);
		WriteFile(hFile,&dummy,1,&lBytesWritten,NULL);
		if(lBytesRead!=0)
			i++;				// just like in BufferData(...)
	}while(lBytesRead!=0);

	CloseHandle(hFileOwn);
	
	if(bDel)
		DeleteFile(szFilename);

	// Fix file pointer
	SetFilePointer(hFile,-1,0,FILE_CURRENT);

	return(i);
}

// Used for determining the lenght of a string
long CHelper::StrLen(char * str)
{
	long lenght=0;

	while(str[lenght]!=0)
		lenght++;
	return(lenght);
}

// Compares lSize chars of two binary strings
int CHelper::Compare(char * szString1, char * szString2, long lSize)
{
	int i=0;
	if(szString1[i]==szString2[i])			// were 2 chars equal?
	{
		i++;
		while(szString1[i]==szString2[i])	// if so check if upcoming chars are
		{									// equal as well
			if(i==lSize)					// repeat until chars differ OR lSize
				return(0);					// chars were equal
			i++;
		}
	}
	return(-1);
}

// Returns the size of file szFileName
long CHelper::GetFileSize(char * szFileName)
{
	unsigned long lBytesRead=0;
	long i=0;
	char dummy;
	HANDLE hFileOwn;

	// open own file
	hFileOwn=CreateFile(szFileName,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,NULL);

	i=::GetFileSize(hFileOwn,NULL);
/*
	while(1)
	{
		ReadFile(hFileOwn,&dummy,1,&lBytesRead,NULL);
		if(lBytesRead!=0)
			i++;
		else
			break;
	}
*/
	CloseHandle(hFileOwn);

	return(i);
}

// Buffers data from hFile, offset lOffset, uses File Mapping
long CHelper::BufferDataFM(HANDLE hFile, char * szFileName, long lOffset, long lSize)
{
	char * lMapAddress;
	DWORD lBytesWritten;

	HANDLE hFileOwn=CreateFile(szFileName,GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,NULL);
	HANDLE hFileMapping=CreateFileMapping(hFile,NULL,PAGE_READWRITE,0,0,NULL);
	if(hFileMapping==0)
	{
		CloseHandle(hFileOwn);
		return(1);
	}

	lMapAddress=(char *)MapViewOfFile(hFileMapping,FILE_MAP_ALL_ACCESS,0,0,0);
	if(lMapAddress==NULL)
	{
		CloseHandle(hFileMapping);
		CloseHandle(hFileOwn);
		return(2);
	}

	lMapAddress+=lOffset;

	WriteFile(hFileOwn,lMapAddress,lSize,&lBytesWritten,NULL);

	UnmapViewOfFile(lMapAddress);
	CloseHandle(hFileMapping);
	CloseHandle(hFileOwn);

	return 0;
}

// Pastes all data of szFileName to current pos of hFile, uses File Mapping
long CHelper::PasteBufferedDataFM(HANDLE hFile, char * szFileName, bool bDel)
{
	char * lMapAddress;
	DWORD lBytesWritten;

	HANDLE hFileOwn=CreateFile(szFileName,GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,NULL);
	HANDLE hFileMapping=CreateFileMapping(hFileOwn,NULL,PAGE_READWRITE,0,0,NULL);
	if(hFileMapping==0)
	{
		CloseHandle(hFileOwn);
		return(1);
	}

	lMapAddress=(char *)MapViewOfFile(hFileMapping,FILE_MAP_ALL_ACCESS,0,0,0);
	if(lMapAddress==NULL)
	{
		CloseHandle(hFileMapping);
		CloseHandle(hFileOwn);
		return(2);
	}

	WriteFile(hFile,lMapAddress,::GetFileSize(hFileOwn,NULL),&lBytesWritten,NULL);

	UnmapViewOfFile(lMapAddress);
	CloseHandle(hFileMapping);
	CloseHandle(hFileOwn);
	// delete file if requested

	if(bDel)
		DeleteFile(szFileName);

	return 0;
}

// Looks for a sequence of bytes in a buffer (binary)
int CHelper::binstrstr(char * buffer, char * tofind, int tofindsize, int size)
{
	int i=0, j=0, k=0, l=0;

	while(i!=size)
	{
		if(buffer[i]==tofind[0])
		{
			j=i+1;
			k++;
			l=i;
			while(buffer[j]==tofind[k])
			{
				if(k==tofindsize)
					return(l);
				j++;
				k++;
			}
			k=0;
			l=0;
		}

		i++;
	}
	return(0);
}

// Computes the Z-angle from the first rotation value of Mafia objects
float CHelper::ZRot2Angle(float fZRot)
{
	float fAngle=0.0;

	fAngle=(float)acos((float)fZRot);
	fAngle=(fAngle*180/(float)MAFIALIB_PI)*2;

	return(fAngle);
}

// Computes the X or Y angle from the second or fourth rotation value of Mafia objects
float CHelper::XYRot2Angle(float fXYRot)
{
	float fAngle=0.0;

	fAngle=(float)atan((float)fXYRot);
	fAngle=(fAngle*180/(float)MAFIALIB_PI)*2;

	return(fAngle);
}

// Computes the rotation value for the first rotation parameter
float CHelper::Angle2ZRotCos(float fAngle)
{
	float fZRot=0.0;

	fZRot=(float)cos((float)(fAngle/2)*MAFIALIB_PI/180);

	return(fZRot);
}

// Computes the rotation value for the third rotation parameter
float CHelper::Angle2ZRotSin(float fAngle)
{
	float fZRot=0.0;

	fZRot=(float)sin((float)(fAngle/2)*MAFIALIB_PI/180);

	return(fZRot);
}

// Computes the rotation value for the second or fourth rotation parameter
float CHelper::Angle2XYRot(float fAngle)
{
	float fXYRot=0.0;

	fXYRot=(float)tan((float)(fAngle/2)*MAFIALIB_PI/180);

	return(fXYRot);
}

// Used for reading strings
int CHelper::ReadTillNull(HANDLE hFile, char * Buffer)
{
	int i=0;
	unsigned long lBytesRead=1;	// because the loop is to be executed

	while(lBytesRead!=0)
	{
		ReadFile(hFile,&Buffer[i],1,&lBytesRead,NULL);
		if(Buffer[i]==0)
			return(i);
		i++;
	}
	return 0;
}

QStringList CHelper::lightSList2StringList( char sLightSectors[1000] )
{
	QStringList returnValue;
	int cur = 0;
	while( sLightSectors[cur]!=0 )
	{
		returnValue.append( QString( &sLightSectors[cur] ) );
		cur += strlen( &sLightSectors[cur] ) + 1;
	}
	return returnValue;
}

char * CHelper::lightStringList2SList( QStringList sectorList )
{
	int cur = 0;
	static char returnValue[1000];
	for( int i = 0; i < sectorList.count(); i++ )
	{
		//&returnValue[cur] = ( char * )( sectorList[i].latin1() );
		strcpy( &returnValue[cur], ( char * )( sectorList[i].latin1() ) );
		cur += strlen(&returnValue[cur])+1;
	}
	return returnValue;
}