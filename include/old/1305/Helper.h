// Helper.cpp
//
// CHelper class definition file
//
// CHelper class is a part of the MafiaLib Engine
//
// Copyright (c) 2003, 2004 ASM

#include <windows.h>
#include <qstringlist.h>

#pragma once

// definitions
#define TYPE_BYTE	1
#define TYPE_WORD	2

#define MASK 0x0F

#define MAFIALIB_PI 3.14159265358979323846

#pragma once

class CHelper
{
public:
	CHelper(void);
	~CHelper(void);
	unsigned long Char2Long(BYTE *ptr,int size);
	unsigned long Char2Long(BYTE *ptr);
	unsigned long Char2LongE(BYTE * ptr, int size);
	unsigned long Char2LongE(BYTE * ptr);

	// Reverses bit order in a long value -- useful for converting big to little endian and vice versa
	long ReverseBits(unsigned long value, int type, int times);

	void CHelper::Long2String(char *out, long number, long size);
	// Used for reading data and buffering it in a temporary file
	long BufferData(HANDLE hFile, char * szFilename, long lSize);
	// Reads out buffered data and puts it into the currently opened file
	long PasteBufferedData(HANDLE hFile, char * szFilename, bool bDel);
	// Used for determining the lenght of a string
	long StrLen(char * str);
	// Compares lSize chars of two strings
	int Compare(char * szString1, char * szString2, long lSize);
	// Returns the size of file szFileName
	long GetFileSize(char * szFileName);
	// Buffers data from the current pos of hFile, uses File Mapping
	long BufferDataFM(HANDLE hFile, char * szFileName, long lOffset, long lSize);
	// Pastes all data of szFileName to current pos of hFile, uses File Mapping
	long PasteBufferedDataFM(HANDLE hFile, char * szFileName, bool bDel);
	// Looks for a sequence of bytes in a buffer (binary)
	int binstrstr(char * buffer, char * tofind, int tofindsize, int size);
	// Computes the Z-angle from the first rotation value of Mafia objects
	static float ZRot2Angle(float fZRot);
	// Computes the X or Y angle from the second or fourth rotation value of Mafia objects
	static float XYRot2Angle(float fXYRot);
	// Computes the rotation value for the first rotation parameter
	static float Angle2ZRotCos(float fAngle);
	// Computes the rotation value for the third rotation parameter
	static float Angle2ZRotSin(float fAngle);
	// Computes the rotation value for the second or fourth rotation parameter
	static float Angle2XYRot(float fAngle);
	// Used for reading strings
	int ReadTillNull(HANDLE hFile, char * Buffer);
	// Returns a QStringList of ObjectInfo_t.sLightSectors
	static QStringList lightSList2StringList( char sLightSectors[1000] );
	static char * lightStringList2SList( QStringList sectorList );
};
