// Scene2.cpp
//
// CScene2 class implementation file
//
// CScene2 class is a part of the MafiaLib Engine
//
// Copyright (c) 2003, 2004 ASM

// #include "StdAfx.h"
#include "Scene2.h"
#include "Helper.h"
#include "Datablock.h"
#include <stdlib.h>
#include <conio.h>

CHelper myHelper;
CDatablock thisDatablock;

// Build
#define MAFIALIB_BUILD 1305

// #define PRIVATE			1
// #define PUBLIC			2

#ifdef PRIVATE
	#define COPYRIGHT "MafiaLib Engine v1.3 Copyright (c) 2003, 2004 ASM - BUILD 1305 Private"
#elif PUBLIC
	#define COPYRIGHT "MafiaLib Engine v1.3 Copyright (c) 2003, 2004 ASM - BUILD 1305 Public"
#endif


// strings
// "Type: Datablock\r\n",
#ifdef MAFIALIB_DEBUG
char *strings[]={
	"Type: Comment\r\n\r\n",			//0
	"Type: Unknown\r\n\r\n",			//1
	"Type: Scene2 - Property Datablock 1\r\n\r\n",		//2
	"Type: Scene2 - Property Datablock 2\r\n\r\n",		//3
	"Type: Scene2 - Camera Datablock\r\n\r\n",			//4									
	"Type: Scene2 - Viewdistance Datablock\r\n\r\n",	//5
	"Type: Scene2 - Viewdistance Additional Datablock\r\n\r\n",	//6
	"Type: Object - Object or Sector Name Datablock\r\n\r\n",	//7
	"Type: Object - Position Datablock\r\n\r\n",		//8
	"Type: Object - Rotation Datablock\r\n\r\n",		//9
	"Type: Object - Size Datablock\r\n\r\n",			//10
	"Type: Object - Additional Translation Datablock\r\n\r\n",	//11
	"Type: Object - Sector Datablock\r\n\r\n",			//12
	"Type: Object - Model Datablock\r\n\r\n",			//13
	"Type: Object - Main Datablock\r\n\r\n",			//14
	"Type: Object - Type Datablock\r\n\r\n",			//15
	"Type: Object - Type 06 Data Datablock\r\n\r\n",	//16
	"Type: Lensflare, Glow or Lightmap - Name Datablock	(LENS or LMAP)\r\n\r\n", //17
	"Type: Lightmap - Data Datablock\r\n\r\n",			//18
	"Type: Lightning - Main Datablock\r\n\r\n",			//19
	"Type: Lightning - Type Datablock\r\n\r\n",			//20
	"Type: Lightning - Brightness Datablock 1\r\n\r\n",	//21
	"Type: Lightning - Brightness Datablock 2\r\n\r\n",	//22
	"Type: Lightning - Unknown Datablock 1\r\n\r\n",	//23
	"Type: Lightning - Unknown Datablock 2\r\n\r\n",	//24
	"Type: Lightning - Brightness Datablock 3\r\n\r\n",	//25
	"Type: Lightning - Sector Datablock\r\n\r\n",		//26
	"Type: Main Datablock for Object Definitions\r\n\r\n",	//27
	"Type: Sector - Main Datablock\r\n\r\n",			//28
	"Type: Sector - Unknown Datablock 1\r\n\r\n",		//29
	"Type: Sector - Unknown Datablock 2\r\n\r\n",		//30
	"Type: Sector - Unknown Datablock 3\r\n\r\n",		//31
	"Type: Sector - Unknown Datablock 4\r\n\r\n",		//32
	"Type: Sector - Unknown Datablock 5\r\n\r\n",		//33
	"Type: Sector - Unknown Datablock 6\r\n\r\n",		//34
	"Type: Sector - Unknown Datablock 7\r\n\r\n",		//35
	"Type: Sector - Unknown Datablock 8\r\n\r\n",		//36
	"Type: Sector - Unknown Datablock 9\r\n\r\n",		//37
	"Type: Sector - Unknown Datablock 10\r\n\r\n",		//38
	"Type: Sector - Unknown Datablock 11\r\n\r\n",		//39
	"Type: Sector - Unknown Datablock 12\r\n\r\n",		//40
	"Type: Sector - Unknown Datablock 13\r\n\r\n",		//41
	"Type: Sector - Unknown Datablock 14\r\n\r\n",		//42
	"Type: Sector - Unknown Datablock 15\r\n\r\n",		//43
	"Type: Sector - Unknown Datablock 16\r\n\r\n",		//44
	"Type: Sector - Unknown Datablock 17\r\n\r\n",		//45
	"Type: Sector - Unknown Datablock 18\r\n\r\n",		//46
	"Type: Sector - Unknown Datablock 19\r\n\r\n",		//47
	"Type: Sector - Unknown Datablock 20\r\n\r\n",		//48
	"Type: Sound - Main Datablock\r\n\r\n",				//49
	"Type: Sound - Volume Datablock\r\n\r\n",			//50
	"Type: Sound - How many times to play Datablock\r\n\r\n",	//51
	"Type: Sound - Play at the beginning Datablock\r\n\r\n",	//52
	"Type: Sound - Unknown Datablock 1\r\n\r\n",		//53
	"Type: Sound - Unknown Datablock 2\r\n\r\n",		//54
	"Type: Sound - Unknown Datablock 3\r\n\r\n",		//55
	"Type: Sound - Unknown Datablock 4\r\n\r\n",		//56
	"Type: Sound - Sector Datablock\r\n\r\n",			//57
	"Type: Lensflare or Glow - Main Datablock\r\n\r\n",	//58
	"Type: Lensflare or Glow - Size Datablock\r\n\r\n",	//59
	"Type: Lensflare or Glow - Color Intensity Datablock\r\n\r\n",	//60
	"Type: Lensflare or Glow - Wait before show/hide Datablock\r\n\r\n",	//61
	"Type: Lensflare or Glow - Creation Speed Datablock\r\n\r\n",			//62
	"Type: Lensflare or Glow - Destruction Speed Datablock\r\n\r\n",		//63
	"Type: Lensflare or Glow - Unkown Datablock 1\r\n\r\n",			//64
	"Type: Main Datablock for additional Object Data like Scripts, AI Code, etc...\r\n\r\n",	//65
	"Type: Object Additional Data - Main Datablock\r\n\r\n",	//66
	"Type: Object Additional Data - Name Datablock\r\n\r\n",	//67
	"Type: Object Additional Data - Type Datablock\r\n\r\n",	//68
	"Type: Object Additional Data - Data Datablock\r\n\r\n",	//69
	"Type: Additional Datablock with GameInitEnd object\r\n\r\n",	//70
	"Type: Additional Datablock - Object\r\n\r\n"	//71
};

char *objects[]={
	"Special - Visible Object\r\n\r\n",	//0
	"Special - Player\r\n\r\n",	//1
	"Special - Car\r\n\r\n",	//2
	"Special - Script\r\n\r\n",	//3
	"Special - Door\r\n\r\n",	//4
	"Special - Public Vehicle (like elevated trains)\r\n\r\n",	//5
	"Normal - Model\r\n\r\n",	//6
	"Special - Traffic Property Item\r\n\r\n",	//7
	"Special - Character\r\n\r\n",	//8
	"Special - Pedestrian Property Item\r\n\r\n",	//9
	"Special - Movable Item\r\n\r\n",	//10
	"Special - Dog\r\n\r\n",	//11
	"Special - Plane\r\n\r\n",	//12
	"Special - Rail Route\r\n\r\n",	//13
	"Special - Fuel Station Pumper\r\n\r\n",	//14
	"Special - Race Camera\r\n\r\n",	//15
	"Special - Wagon\r\n\r\n",	//16
	"Special - Clock\r\n\r\n",	//17
	"Special - Truck Backseat\r\n\r\n",	//18
	"Unknown\r\n\r\n",	//19
	"Normal - Light\r\n\r\n",	//20
	"Normal - Sound\r\n\r\n",	//21
	"Normal - Type 06\r\n\r\n",	//22
	"Normal - Occluder\r\n\r\n"	//23
};
#endif

// Predefinied Objects

// car object - name: <tmp>
#define CARDATASIZE		35
unsigned char cardata[CARDATASIZE] = {
	0x21, 0xAE, 0x23, 0x00, 0x00, 0x00, 0x23, 0xAE, 0x0C, 0x00, 0x00, 0x00, 0x3C, 0x74, 0x6D, 0x70, 
	0x3E, 0x00, 0x22, 0xAE, 0x0A, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x24, 0xAE, 0x07, 0x00, 
	0x00, 0x00, 0x01
};

#define SCRIPTDATASIZE	47
unsigned char scriptdata[SCRIPTDATASIZE] = {
	0x21, 0xAE, 0x2F, 0x00, 0x00, 0x00, 0x23, 0xAE, 0x0B, 0x00, 0x00, 0x00, 0x3C, 0x73, 0x74, 0x3E, 
	0x00, 0x22, 0xAE, 0x0A, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x24, 0xAE, 0x14, 0x00, 0x00, 
	0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#define INITSCRIPTDATASIZE	46
unsigned char initscriptdata[INITSCRIPTDATASIZE] = {
	0x51, 0xAE, 0x2E, 0x00, 0x00, 0x00, 0x01, 0x0A, 0x00, 0x00, 0x00, 0x3C, 0x69, 0x6E, 0x69, 0x74, 
	0x2D, 0x74, 0x6D, 0x70, 0x3E, 0x15, 0x00, 0x00, 0x00, 0x59, 0x6F, 0x75, 0x72, 0x20, 0x73, 0x63, 
	0x72, 0x69, 0x70, 0x74, 0x20, 0x67, 0x6F, 0x65, 0x73, 0x20, 0x68, 0x65, 0x72, 0x65
};

CScene2::CScene2(void)
{		
}

CScene2::~CScene2(void)
{
}

// Function	: LoadScene2Bin
//
// Purpose	: Loads a scene2.bin file for reading

HANDLE CScene2::LoadScene2Bin(char * szFilename)
{
	HANDLE hFile=CreateFile(szFilename,GENERIC_READ|GENERIC_WRITE,FILE_SHARE_WRITE|FILE_SHARE_READ|FILE_SHARE_DELETE,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,NULL);
	return(hFile);
}

// Function	: CloseScene2Bin
//
// Purpose	: Closes an open scene2.bin file
void CScene2::CloseScene2Bin(HANDLE hFile)
{
	CloseHandle(hFile);
}

// Function	: IsScene2Bin
//
// Purpose	: Checks if opened file is a scene2.bin file
bool CScene2::IsScene2Bin(HANDLE hFile)
{
	short nSig;
	unsigned long lBytesRead;

	SetFilePointer(hFile,0,0,NULL);
	ReadFile(hFile,(char *)&nSig,sizeof(nSig),&lBytesRead,NULL);
	if(nSig==GENERAL_SCENE2_MAIN)
		return true;
	return false;
}

// Function	: GetSize
//
// Purpose	: Reads size of scene2.bin file found in header

unsigned long CScene2::GetFileSize(HANDLE hFile)
{
	long lSize=0;
	unsigned long lBytesRead;

	SetFilePointer(hFile,2,0,NULL);
	ReadFile(hFile,(char *)&lSize,sizeof(lSize),&lBytesRead,NULL);
	return(lSize);
}

// Reads the complete scene2.bin file and writes all found datablocks/objects into the Datablocks_Objects.txt
#ifdef MAFIALIB_DEBUG
void CScene2::ReadDatablocksObjects(HANDLE hFile)
{
	// Variables
	HANDLE hFileOwn;
	unsigned long lSize, lDatablockSize, lObjectType,lBytesWritten, lOffset=0;
	short nDatablockType;
	char dummy[256]; //message buffer
	char info[256]={"Scene2.bin Datablocks and Objects\r\n"\
		"Created with Muped (c) 2003 ASM - DonCity Internal Build\r\n"\
		"For internal use\r\n\r\n"};
	char seperator[256]={"<<<<<<<< OBJECTS >>>>>>>>\r\n\r\n"};

	//Code

	// open own file
	hFileOwn=CreateFile("datablocks_objects.txt",GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
	WriteFile(hFileOwn,info,strlen(info),&lBytesWritten,NULL);

	// read size
	lSize=GetFileSize(hFile);
	printf("File size from header: (hex) %X - (dec) %u\n",lSize,lSize);
	sprintf(dummy,"File size from header: (hex) %X - (dec) %u\r\n\r\n",lSize,lSize);
	WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);

	printf("Reading Datablocks...\n");
	//when we are here, the file pointer's 6 bytes away form beginning of file

	lOffset=6;

	while(1)
	{
		nDatablockType=thisDatablock.GetShort(hFile);

		if(nDatablockType==SCENE2_EOF)		//stop if we reach end of file
			break;

		sprintf(dummy,"Offset: %X\r\n",lOffset);
		WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);

		lDatablockSize=thisDatablock.GetLong(hFile);
		sprintf(dummy,"Datablock Size: (hex) %X - (dec) %u\r\n",lDatablockSize,lDatablockSize);
		WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);

		switch(nDatablockType)
		{
			case GENERAL_SCENE2_UNK_1:
				WriteFile(hFileOwn,strings[2],strlen(strings[2]),&lBytesWritten,NULL);
				break;

			case GENERAL_SCENE2_UNK_2:
				WriteFile(hFileOwn,strings[3],strlen(strings[3]),&lBytesWritten,NULL);
				break;

			case GENERAL_SCENE2_CAMERA:
				WriteFile(hFileOwn,strings[4],strlen(strings[4]),&lBytesWritten,NULL);
				break;

			case GENERAL_SCENE2_VIEW:
				WriteFile(hFileOwn,strings[5],strlen(strings[5]),&lBytesWritten,NULL);
				break;

			case GENERAL_SCENE2_VIEW_SPECIAL:
				WriteFile(hFileOwn,strings[6],strlen(strings[6]),&lBytesWritten,NULL);
				break;

			case NORMAL_OBJECT_OR_SECTOR_NAME:
				WriteFile(hFileOwn,strings[7],strlen(strings[7]),&lBytesWritten,NULL);
				break;

			case NORMAL_OBJECT_POS:
				WriteFile(hFileOwn,strings[8],strlen(strings[8]),&lBytesWritten,NULL);
				break;

			case NORMAL_OBJECT_ROT:
				WriteFile(hFileOwn,strings[9],strlen(strings[9]),&lBytesWritten,NULL);
				break;

			case NORMAL_OBJECT_DIMENSION:
				WriteFile(hFileOwn,strings[10],strlen(strings[10]),&lBytesWritten,NULL);
				break;

			case NORMAL_OBJECT_ADDTRANSLATION:
				WriteFile(hFileOwn,strings[11],strlen(strings[11]),&lBytesWritten,NULL);
				break;

			case NORMAL_OBJECT_SECTOR:
				WriteFile(hFileOwn,strings[12],strlen(strings[12]),&lBytesWritten,NULL);
				break;

			case NORMAL_OBJECT_MODEL:
				WriteFile(hFileOwn,strings[13],strlen(strings[13]),&lBytesWritten,NULL);
				break;

			case NORMAL_OBJECT_MAIN:
				WriteFile(hFileOwn,strings[14],strlen(strings[14]),&lBytesWritten,NULL);
				lDatablockSize=0;
				break;

			case NORMAL_OBJECT_TYPE:
				WriteFile(hFileOwn,strings[15],strlen(strings[15]),&lBytesWritten,NULL);
				break;
			case NORMAL_OBJECT_TYPE_06_DATA:
				WriteFile(hFileOwn,strings[16],strlen(strings[16]),&lBytesWritten,NULL);
				break;
			case NORMAL_LENSFLARE_OR_LIGHTMAP_OR_GLOW:
				WriteFile(hFileOwn,strings[17],strlen(strings[17]),&lBytesWritten,NULL);
				break;
			case NORMAL_LIGHTMAP_DATA:
				WriteFile(hFileOwn,strings[18],strlen(strings[18]),&lBytesWritten,NULL);
				break;
			case NORMAL_LIGHTNING_MAIN:
				WriteFile(hFileOwn,strings[19],strlen(strings[19]),&lBytesWritten,NULL);
				lDatablockSize=0;
				break;
			case NORMAL_LIGHTNING_TYPE:
				WriteFile(hFileOwn,strings[20],strlen(strings[20]),&lBytesWritten,NULL);
				break;
			case NORMAL_LIGHTNING_COLOR:
				WriteFile(hFileOwn,strings[21],strlen(strings[21]),&lBytesWritten,NULL);
				break;
			case NORMAL_LIGHTNING_POWER:
				WriteFile(hFileOwn,strings[22],strlen(strings[22]),&lBytesWritten,NULL);
				break;
			case NORMAL_LIGHTNING_UNK_1:
				WriteFile(hFileOwn,strings[23],strlen(strings[23]),&lBytesWritten,NULL);
				break;
			case NORMAL_LIGHTNING_RANGE:
				WriteFile(hFileOwn,strings[24],strlen(strings[24]),&lBytesWritten,NULL);
				break;
			case NORMAL_LIGHTNING_FLAGS:
				WriteFile(hFileOwn,strings[25],strlen(strings[25]),&lBytesWritten,NULL);
				break;
			case NORMAL_LIGHTNING_SECTOR:
				WriteFile(hFileOwn,strings[26],strlen(strings[26]),&lBytesWritten,NULL);
				break;
			case NORMAL_MAIN:
				WriteFile(hFileOwn,strings[27],strlen(strings[27]),&lBytesWritten,NULL);
				lDatablockSize=0;
				break;
			case NORMAL_SECTOR_MAIN:
				WriteFile(hFileOwn,strings[28],strlen(strings[28]),&lBytesWritten,NULL);
				lDatablockSize=0;
				break;
			case NORMAL_SECTOR_UNK_1:
				WriteFile(hFileOwn,strings[29],strlen(strings[29]),&lBytesWritten,NULL);
				break;
			case NORMAL_SECTOR_UNK_2:
				WriteFile(hFileOwn,strings[30],strlen(strings[30]),&lBytesWritten,NULL);
				break;
			case NORMAL_SECTOR_UNK_3:
				WriteFile(hFileOwn,strings[31],strlen(strings[31]),&lBytesWritten,NULL);
				break;
			case NORMAL_SECTOR_UNK_4:
				WriteFile(hFileOwn,strings[32],strlen(strings[32]),&lBytesWritten,NULL);
				break;
			case NORMAL_SECTOR_UNK_5:
				WriteFile(hFileOwn,strings[33],strlen(strings[33]),&lBytesWritten,NULL);
				break;
			case NORMAL_SECTOR_UNK_6:
				WriteFile(hFileOwn,strings[34],strlen(strings[34]),&lBytesWritten,NULL);
				break;
			case NORMAL_SECTOR_UNK_7:
				WriteFile(hFileOwn,strings[35],strlen(strings[35]),&lBytesWritten,NULL);
				break;
			case NORMAL_SECTOR_UNK_8:
				WriteFile(hFileOwn,strings[36],strlen(strings[36]),&lBytesWritten,NULL);
				break;
			case NORMAL_SECTOR_UNK_9:
				WriteFile(hFileOwn,strings[37],strlen(strings[37]),&lBytesWritten,NULL);
				break;
			case NORMAL_SECTOR_UNK_10:
				WriteFile(hFileOwn,strings[38],strlen(strings[38]),&lBytesWritten,NULL);
				break;
			case NORMAL_SECTOR_UNK_11:
				WriteFile(hFileOwn,strings[39],strlen(strings[39]),&lBytesWritten,NULL);
				break;
			case NORMAL_SECTOR_UNK_12:
				WriteFile(hFileOwn,strings[40],strlen(strings[40]),&lBytesWritten,NULL);
				break;
			case NORMAL_SECTOR_UNK_13:
				WriteFile(hFileOwn,strings[41],strlen(strings[41]),&lBytesWritten,NULL);
				break;
			case NORMAL_SECTOR_UNK_14:
				WriteFile(hFileOwn,strings[42],strlen(strings[42]),&lBytesWritten,NULL);
				break;
			case NORMAL_SECTOR_UNK_15:
				WriteFile(hFileOwn,strings[43],strlen(strings[43]),&lBytesWritten,NULL);
				break;
			case NORMAL_SECTOR_UNK_17:
				WriteFile(hFileOwn,strings[44],strlen(strings[44]),&lBytesWritten,NULL);
				break;
			case NORMAL_SECTOR_UNK_18:
				WriteFile(hFileOwn,strings[45],strlen(strings[45]),&lBytesWritten,NULL);
				break;
			case NORMAL_SECTOR_UNK_19:
				WriteFile(hFileOwn,strings[46],strlen(strings[46]),&lBytesWritten,NULL);
				break;
			case NORMAL_SECTOR_UNK_20:
				WriteFile(hFileOwn,strings[47],strlen(strings[47]),&lBytesWritten,NULL);
				break;
			case NORMAL_SECTOR_UNK_21:
				WriteFile(hFileOwn,strings[48],strlen(strings[48]),&lBytesWritten,NULL);
				break;
			case NORMAL_SOUND_MAIN:
				WriteFile(hFileOwn,strings[49],strlen(strings[49]),&lBytesWritten,NULL);
				lDatablockSize=0;
				break;
			case NORMAL_SOUND_VOLUME:
				WriteFile(hFileOwn,strings[50],strlen(strings[50]),&lBytesWritten,NULL);
				break;
			case NORMAL_SOUND_HMTTP:
				WriteFile(hFileOwn,strings[51],strlen(strings[51]),&lBytesWritten,NULL);
				break;
			case NORMAL_SOUND_ATBEGIN:
				WriteFile(hFileOwn,strings[52],strlen(strings[52]),&lBytesWritten,NULL);
				break;
			case NORMAL_SOUND_UNK_1:
				WriteFile(hFileOwn,strings[53],strlen(strings[53]),&lBytesWritten,NULL);
				break;
			case NORMAL_SOUND_UNK_2:
				WriteFile(hFileOwn,strings[54],strlen(strings[54]),&lBytesWritten,NULL);
				break;
			case NORMAL_SOUND_UNK_3:
				WriteFile(hFileOwn,strings[55],strlen(strings[55]),&lBytesWritten,NULL);
				break;
			case NORMAL_SOUND_UNK_4:
				WriteFile(hFileOwn,strings[56],strlen(strings[56]),&lBytesWritten,NULL);
				break;
			case NORMAL_SOUND_SECTOR:
				WriteFile(hFileOwn,strings[57],strlen(strings[57]),&lBytesWritten,NULL);
				break;
			case NORMAL_LENSFLARE_OR_GLOW_MAIN:
				WriteFile(hFileOwn,strings[58],strlen(strings[58]),&lBytesWritten,NULL);
				lDatablockSize=0;
				break;
			case NORMAL_LENSFLARE_OR_GLOW_SIZE:
				WriteFile(hFileOwn,strings[59],strlen(strings[59]),&lBytesWritten,NULL);
				break;
			case NORMAL_LENSFLARE_OR_GLOW_COLORS:
				WriteFile(hFileOwn,strings[60],strlen(strings[60]),&lBytesWritten,NULL);
				break;
			case NORMAL_LENSFLARE_OR_GLOW_WAIT:
				WriteFile(hFileOwn,strings[61],strlen(strings[61]),&lBytesWritten,NULL);
				break;
			case NORMAL_LENSFLARE_OR_GLOW_CSPEED:
				WriteFile(hFileOwn,strings[62],strlen(strings[62]),&lBytesWritten,NULL);
				break;
			case NORMAL_LENSFLARE_OR_GLOW_DSPEED:
				WriteFile(hFileOwn,strings[63],strlen(strings[63]),&lBytesWritten,NULL);
				break;
			case NORMAL_LENSFLARE_OR_GLOW_UNK_1:
				WriteFile(hFileOwn,strings[64],strlen(strings[64]),&lBytesWritten,NULL);
				break;

// Object Definition Datablock
			case SPECIAL_MAIN:
				WriteFile(hFileOwn,strings[65],strlen(strings[65]),&lBytesWritten,NULL);
				lDatablockSize=0;
				break;
			case SPECIAL_OBJECT_MAIN:
				WriteFile(hFileOwn,strings[66],strlen(strings[66]),&lBytesWritten,NULL);
				lDatablockSize=0;
				break;
			case SPECIAL_OBJECT_NAME:
				WriteFile(hFileOwn,strings[67],strlen(strings[67]),&lBytesWritten,NULL);
				break;
			case SPECIAL_OBJECT_TYPE:
				WriteFile(hFileOwn,strings[68],strlen(strings[68]),&lBytesWritten,NULL);
				break;
			case SPECIAL_OBJECT_DATA:
				WriteFile(hFileOwn,strings[69],strlen(strings[69]),&lBytesWritten,NULL);
				break;

// Additional Datablock
			case ADDITIONAL_MAIN:
				WriteFile(hFileOwn,strings[70],strlen(strings[70]),&lBytesWritten,NULL);
				lDatablockSize=0;
				break;
			case ADDITIONAL_OBJECT:
				WriteFile(hFileOwn,strings[71],strlen(strings[71]),&lBytesWritten,NULL);
				break;

			case DATABLOCK_COMMENT:
				WriteFile(hFileOwn,strings[0],strlen(strings[0]),&lBytesWritten,NULL);
				break;

			default:
				WriteFile(hFileOwn,strings[1],strlen(strings[1]),&lBytesWritten,NULL);
				break;
		}

		if(lDatablockSize==0)
		{
			lOffset+=6;
		}
		else
		{
			lOffset+=lDatablockSize;
			SetFilePointer(hFile,(lDatablockSize-6),0,FILE_CURRENT);
		}
	}
	printf("Reading Objects...\n");

	lOffset=6;
	SetFilePointer(hFile,lOffset,0,FILE_BEGIN);

	WriteFile(hFileOwn,seperator,strlen(seperator),&lBytesWritten,NULL);

	while(1)
	{
		nDatablockType=thisDatablock.GetShort(hFile);

		if(nDatablockType==SCENE2_EOF)		//stop if we reach end of file
			break;

		lDatablockSize=thisDatablock.GetLong(hFile);

		switch(nDatablockType)
		{
			case NORMAL_OBJECT_MAIN:
			case NORMAL_LIGHTNING_MAIN:
			case NORMAL_MAIN:
			case NORMAL_SECTOR_MAIN:
			case NORMAL_SOUND_MAIN:
			case NORMAL_LENSFLARE_OR_GLOW_MAIN:
			case SPECIAL_MAIN:
			case SPECIAL_OBJECT_MAIN:
			case ADDITIONAL_MAIN:
				lDatablockSize=0;
				break;

			case NORMAL_OBJECT_TYPE:
				lObjectType=thisDatablock.GetLong(hFile);
				SetFilePointer(hFile,-4,0,FILE_CURRENT);
				switch(lObjectType)
				{
					case NORMAL_OBJECT_TYPE_MODEL:
						sprintf(dummy,"Offset: %X\r\n",lOffset);
						WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);
						WriteFile(hFileOwn,objects[6],strlen(objects[6]),&lBytesWritten,NULL);
						break;
					case NORMAL_OBJECT_TYPE_LIGHT:
						sprintf(dummy,"Offset: %X\r\n",lOffset);
						WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);
						WriteFile(hFileOwn,objects[20],strlen(objects[20]),&lBytesWritten,NULL);
						break;
					case NORMAL_OBJECT_TYPE_SOUND:
						sprintf(dummy,"Offset: %X\r\n",lOffset);
						WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);
						WriteFile(hFileOwn,objects[21],strlen(objects[21]),&lBytesWritten,NULL);
						break;
					case NORMAL_OBJECT_TYPE_06:
						sprintf(dummy,"Offset: %X\r\n",lOffset);
						WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);
						WriteFile(hFileOwn,objects[22],strlen(objects[22]),&lBytesWritten,NULL);
						break;
					case NORMAL_OBJECT_TYPE_OCCLUDER:
						sprintf(dummy,"Offset: %X\r\n",lOffset);
						WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);
						WriteFile(hFileOwn,objects[23],strlen(objects[23]),&lBytesWritten,NULL);
						break;

					default:
						sprintf(dummy,"Offset: %X\r\n",lOffset);
						WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);
						WriteFile(hFileOwn,objects[19],strlen(objects[19]),&lBytesWritten,NULL);
						break;
				}
				break;

			case SPECIAL_OBJECT_TYPE:
				lObjectType=thisDatablock.GetLong(hFile);
				SetFilePointer(hFile,-4,0,FILE_CURRENT);
				switch(lObjectType)
				{
					case SPECIAL_OBJECT_TYPE_VISOBJ:
						sprintf(dummy,"Offset: %X\r\n",lOffset);
						WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);
						WriteFile(hFileOwn,objects[0],strlen(objects[0]),&lBytesWritten,NULL);
						break;
					case SPECIAL_OBJECT_TYPE_PLAYER:
						sprintf(dummy,"Offset: %X\r\n",lOffset);
						WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);
						WriteFile(hFileOwn,objects[1],strlen(objects[1]),&lBytesWritten,NULL);
						break;
					case SPECIAL_OBJECT_TYPE_CAR:
						sprintf(dummy,"Offset: %X\r\n",lOffset);
						WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);
						WriteFile(hFileOwn,objects[2],strlen(objects[2]),&lBytesWritten,NULL);
						break;
					case SPECIAL_OBJECT_TYPE_SCRIPT:
						sprintf(dummy,"Offset: %X\r\n",lOffset);
						WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);
						WriteFile(hFileOwn,objects[3],strlen(objects[3]),&lBytesWritten,NULL);
						break;
					case SPECIAL_OBJECT_TYPE_DOOR:
						sprintf(dummy,"Offset: %X\r\n",lOffset);
						WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);
						WriteFile(hFileOwn,objects[4],strlen(objects[4]),&lBytesWritten,NULL);
						break;
					case SPECIAL_OBJECT_TYPE_PUB_VEHICLE:
						sprintf(dummy,"Offset: %X\r\n",lOffset);
						WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);
						WriteFile(hFileOwn,objects[5],strlen(objects[5]),&lBytesWritten,NULL);
						break;
					case SPECIAL_OBJECT_TYPE_TRAFFIC:
						sprintf(dummy,"Offset: %X\r\n",lOffset);
						WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);
						WriteFile(hFileOwn,objects[7],strlen(objects[7]),&lBytesWritten,NULL);
						break;
					case SPECIAL_OBJECT_TYPE_CHARACTER:
						sprintf(dummy,"Offset: %X\r\n",lOffset);
						WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);
						WriteFile(hFileOwn,objects[8],strlen(objects[8]),&lBytesWritten,NULL);
						break;
					case SPECIAL_OBJECT_TYPE_PEDS:
						sprintf(dummy,"Offset: %X\r\n",lOffset);
						WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);
						WriteFile(hFileOwn,objects[9],strlen(objects[9]),&lBytesWritten,NULL);
						break;
					case SPECIAL_OBJECT_TYPE_SHOOTABLE:
						sprintf(dummy,"Offset: %X\r\n",lOffset);
						WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);
						WriteFile(hFileOwn,objects[10],strlen(objects[10]),&lBytesWritten,NULL);
						break;
					case SPECIAL_OBJECT_TYPE_DOG:
						sprintf(dummy,"Offset: %X\r\n",lOffset);
						WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);
						WriteFile(hFileOwn,objects[11],strlen(objects[11]),&lBytesWritten,NULL);
						break;
					case SPECIAL_OBJECT_TYPE_PLANE:
						sprintf(dummy,"Offset: %X\r\n",lOffset);
						WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);
						WriteFile(hFileOwn,objects[12],strlen(objects[12]),&lBytesWritten,NULL);
						break;
					case SPECIAL_OBJECT_TYPE_RAIL_ROUTE:
						sprintf(dummy,"Offset: %X\r\n",lOffset);
						WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);
						WriteFile(hFileOwn,objects[13],strlen(objects[13]),&lBytesWritten,NULL);
						break;
					case SPECIAL_OBJECT_TYPE_PUMPER:
						sprintf(dummy,"Offset: %X\r\n",lOffset);
						WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);
						WriteFile(hFileOwn,objects[14],strlen(objects[14]),&lBytesWritten,NULL);
						break;
					case SPECIAL_OBJECT_TYPE_RACECAM:
						sprintf(dummy,"Offset: %X\r\n",lOffset);
						WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);
						WriteFile(hFileOwn,objects[15],strlen(objects[15]),&lBytesWritten,NULL);
						break;
					case SPECIAL_OBJECT_TYPE_WAGONS:
						sprintf(dummy,"Offset: %X\r\n",lOffset);
						WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);
						WriteFile(hFileOwn,objects[16],strlen(objects[16]),&lBytesWritten,NULL);
						break;
					case SPECIAL_OBJECT_TYPE_CLOCKS:
						sprintf(dummy,"Offset: %X\r\n",lOffset);
						WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);
						WriteFile(hFileOwn,objects[17],strlen(objects[17]),&lBytesWritten,NULL);
						break;
					case SPECIAL_OBJECT_TYPE_TRUCKBACKSEAT:
						sprintf(dummy,"Offset: %X\r\n",lOffset);
						WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);
						WriteFile(hFileOwn,objects[18],strlen(objects[18]),&lBytesWritten,NULL);
						break;

					default:
						sprintf(dummy,"Offset: %X\r\n",lOffset);
						WriteFile(hFileOwn,dummy,strlen(dummy),&lBytesWritten,NULL);
						WriteFile(hFileOwn,objects[19],strlen(objects[19]),&lBytesWritten,NULL);
						break;
				}
		}

		if(lDatablockSize==0)
		{
			lOffset+=6;
		}
		else
		{
			lOffset+=lDatablockSize;
			SetFilePointer(hFile,(lDatablockSize-6),0,FILE_CURRENT);
		}
	}

	printf("File Read Successfully...\n"\
		"You may now press enter to close this program\n"\
		"The file datablocks_objects.txt now contains all found datablocks and objects\n");
	getch();
//	CloseScene2Bin(hFile);
	CloseHandle(hFileOwn);
}
#endif

// Used for adding or replacing objects to/in scene2.bin file
int CScene2::AddObject(HANDLE hFile, ObjectInfo_t * Scene2ObjectInfo_t, char *szScriptFileName, char * szObjectToReplace)
{
//	char dummy[256];
	int i, cur=0;
	long lOffset=0,
		lDummyOffset=0,			// dummy offset for BufferDataFM
		lScriptOffset=0,
		lScriptSize=0;
	unsigned long lBytesWritten=0, lBytesRead=0;
	// long lSizes[8];
	long lNormalMainSize=0,
		lSpecialMainSize=0,
		lScene2Size=0,
		lDatablockSize=0,
		lObjectSize=0, 		// for replace: how big was object before replace
		lLightMain=0,		// size of lightmain datablock
		lType06Main=0;		// size of type 06 main datablock

	const char null[3]={0,0,0};	// if we have to fill sth w 3 null
	const char bignull[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};	// for Traffic Item
	const char one[3]={1,1,1};				// if we need ones
	const char datatype_character=0x06;		// datatype for character
	const short datatype_movable=0x0102;	// datatype for movable objects
	const char datatype_traffic=0x05;		// datatype for traffic objects
	char dummy;				// the dummy >:)

	HANDLE hFileOwn;

	// Debug Vars
	long Size1=0, Size2=0, Size3=0;

	// check for object type to add
	switch(Scene2ObjectInfo_t->lType)
	{
		case S_NORMAL_OBJECT_TYPE_MODEL:

			// Remove f of object type indicator
			Scene2ObjectInfo_t->lType&=0x0F;

			// check if the object is supposed to be replaced
			if(szObjectToReplace!=NULL)
			{
				// Find Object to replace
				lDummyOffset=lOffset=FindObject(hFile,szObjectToReplace,NORMAL_MAIN);
				if(lOffset==-1)
					return(-1);	// stop function if object not found

				SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);

				// Find End of Object
				lObjectSize=thisDatablock.GetLong(hFile);

				SetFilePointer(hFile,(lObjectSize-6),0,FILE_CURRENT); //set file pointer to end of NORMAL_MAIN
				lDummyOffset+=lObjectSize;
			}
			else
			{
				// Find NORMAL_MAIN
				lDummyOffset=lOffset=thisDatablock.FindDatablock(hFile,NORMAL_MAIN);

				// Find END of NORMAL_MAIN
				lDatablockSize=thisDatablock.GetLong(hFile);

				//	lOffset2+=lOffset+lDatablockSize;				//save address of OBJECT_MAIN (end of NORMAL_MAIN)
				SetFilePointer(hFile,(lDatablockSize-6),0,FILE_CURRENT); //set file pointer to end of NORMAL_MAIN
				lDummyOffset+=lDatablockSize;
			}
				// save all upcoming data
//				myHelper.BufferData(hFile,"buffer.tmp",-1);
			myHelper.BufferDataFM(hFile,"buffer.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);

			// do we replace?
			if(szObjectToReplace!=NULL)
				// yes so we have to set back the file pointer cuz our object must be overwritten
				SetFilePointer(hFile,-(lObjectSize),0,FILE_CURRENT);

			// create the object file
			hFileOwn=CreateFile("object.tmp",GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,NULL);

			// Calculate main datablock size
			// For every datablock we have: Datasize+6

			// General
			lDatablockSize=6;
			// 1. Type
			lDatablockSize+=0x0A;

			// 2. Name
			lDatablockSize+=strlen(Scene2ObjectInfo_t->sName)+7;

			// 3. Position
			lDatablockSize+=0x12;

			// 4. Rotation
			lDatablockSize+=0x16;

			// 5. Size
			lDatablockSize+=0x12;

			// 6. Additional Translation
			lDatablockSize+=0x12;

			// 7. Sector Name
			lDatablockSize+=strlen(Scene2ObjectInfo_t->sSectorName)+13; // 12 - sector datablock + 12 - name datablock + 1 - the 0 at the end

			// 8. Model (if we need one)
			if(Scene2ObjectInfo_t->bUseModel)
				lDatablockSize+=strlen(Scene2ObjectInfo_t->sModelName)+7;

			// Create a new main datablock for our object
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_MAIN,lDatablockSize);

			// Create sub datablocks

			// 1. Type
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_TYPE,sizeof(Scene2ObjectInfo_t->lType)+6);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->lType,sizeof(Scene2ObjectInfo_t->lType),&lBytesWritten,NULL);

			// 2. Name
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_OR_SECTOR_NAME,strlen(Scene2ObjectInfo_t->sName)+7);
			WriteFile(hFileOwn,Scene2ObjectInfo_t->sName,strlen(Scene2ObjectInfo_t->sName)+1,&lBytesWritten,NULL);

			// 3. Position
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_POS,sizeof(Scene2ObjectInfo_t->fPos[0])*3+6);
			for(i=0;i<3;i++)
				WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fPos[i],sizeof(Scene2ObjectInfo_t->fPos[0]),&lBytesWritten,NULL);

			// 4. Rotation
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_ROT,sizeof(Scene2ObjectInfo_t->fRot[0])*4+6);
			for(i=0;i<4;i++)
				WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fRot[i],sizeof(Scene2ObjectInfo_t->fRot[0]),&lBytesWritten,NULL);

			// 5. Size
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_DIMENSION,sizeof(Scene2ObjectInfo_t->fSize[0])*3+6);
			for(i=0;i<3;i++)
				WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fSize[i],sizeof(Scene2ObjectInfo_t->fSize[0]),&lBytesWritten,NULL);

			// 6. Additional Translation
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_ADDTRANSLATION,sizeof(Scene2ObjectInfo_t->fAddTrans[0])*3+6);
			for(i=0;i<3;i++)
				WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fAddTrans[i],sizeof(Scene2ObjectInfo_t->fAddTrans[0]),&lBytesWritten,NULL);

			// 7. Sector Name
			// Create Main Datablock
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_SECTOR,strlen(Scene2ObjectInfo_t->sSectorName)+13);

			// now create sub-datablock with name of sector
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_OR_SECTOR_NAME,strlen(Scene2ObjectInfo_t->sSectorName)+7);
			WriteFile(hFileOwn,Scene2ObjectInfo_t->sSectorName,strlen(Scene2ObjectInfo_t->sSectorName)+1,&lBytesWritten,NULL);

			// 8. Model
			if(Scene2ObjectInfo_t->bUseModel)
			{
				thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_MODEL,strlen(Scene2ObjectInfo_t->sModelName)+7);
				WriteFile(hFileOwn,Scene2ObjectInfo_t->sModelName,strlen(Scene2ObjectInfo_t->sModelName)+1,&lBytesWritten,NULL);
			}

			// Close Handle to Object file
			CloseHandle(hFileOwn);

			// Add my object
			myHelper.PasteBufferedDataFM(hFile,"object.tmp",true);

			// Add other data
			myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

			SetEndOfFile(hFile);

			// -------------------------------------------------
			// Finally, change NORMAL_MAIN size
			if(szObjectToReplace!=NULL)
				lOffset=thisDatablock.FindDatablock(hFile,NORMAL_MAIN);
			SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);

			lNormalMainSize=thisDatablock.GetLong(hFile);

			if(szObjectToReplace!=NULL)
				lNormalMainSize+=(lDatablockSize-lObjectSize);
			else
				lNormalMainSize+=lDatablockSize;

			SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lNormalMainSize,4,&lBytesWritten,NULL);

			// Change size of scene2.bin file in header
			lScene2Size=GetFileSize(hFile);

			if(szObjectToReplace!=NULL)
				lScene2Size+=(lDatablockSize-lObjectSize);
			else
				lScene2Size+=lDatablockSize;
	
			SetFilePointer(hFile,2,0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lScene2Size,4,&lBytesWritten,NULL);
			break;

		case S_NORMAL_OBJECT_TYPE_06:

			// Remove f of object type indicator
			Scene2ObjectInfo_t->lType&=0x0F;

			// check if the object is supposed to be replaced
			if(szObjectToReplace!=NULL)
			{
				// Find Object to replace
				lDummyOffset=lOffset=FindObject(hFile,szObjectToReplace,NORMAL_MAIN);
				if(lOffset==-1)
					return(-1);	// stop function if object not found

				SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);

				// Find End of Object
				lObjectSize=thisDatablock.GetLong(hFile);

				SetFilePointer(hFile,(lObjectSize-6),0,FILE_CURRENT); //set file pointer to end of NORMAL_MAIN
				lDummyOffset+=lObjectSize;
			}
			else
			{
				// Find NORMAL_MAIN
				lDummyOffset=lOffset=thisDatablock.FindDatablock(hFile,NORMAL_MAIN);

				// Find END of NORMAL_MAIN
				lDatablockSize=thisDatablock.GetLong(hFile);

				//	lOffset2+=lOffset+lDatablockSize;				//save address of OBJECT_MAIN (end of NORMAL_MAIN)
				SetFilePointer(hFile,(lDatablockSize-6),0,FILE_CURRENT); //set file pointer to end of NORMAL_MAIN
				lDummyOffset+=lDatablockSize;
			}
				// save all upcoming data
//				myHelper.BufferData(hFile,"buffer.tmp",-1);
			myHelper.BufferDataFM(hFile,"buffer.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);

			// do we replace?
			if(szObjectToReplace!=NULL)
				// yes so we have to set back the file pointer cuz our object must be overwritten
				SetFilePointer(hFile,-(lObjectSize),0,FILE_CURRENT);

			// create the object file
			hFileOwn=CreateFile("object.tmp",GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,NULL);

			// Calculate main datablock size
			// For every datablock we have: Datasize+6

			// General
			lDatablockSize=6;
			// 1. Type
			lDatablockSize+=0x0A;

			// 2. Name
			lDatablockSize+=strlen(Scene2ObjectInfo_t->sName)+7;

			// 3. Position
			lDatablockSize+=0x12;

			// 4. Rotation
			lDatablockSize+=0x16;

			// 5. Size
			lDatablockSize+=0x12;

			// 6. Additional Translation
			lDatablockSize+=0x12;

			// 7. Sector Name
			lDatablockSize+=strlen(Scene2ObjectInfo_t->sSectorName)+13; // 12 - sector datablock + 12 - name datablock + 1 - the 0 at the end

			// 8. Type 06 Main Datablock
			lDatablockSize+=lType06Main=0x1E;

			// Create a new main datablock for our object
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_MAIN,lDatablockSize);

			// Create sub datablocks

			// 1. Type
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_TYPE,sizeof(Scene2ObjectInfo_t->lType)+6);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->lType,sizeof(Scene2ObjectInfo_t->lType),&lBytesWritten,NULL);

			// 2. Name
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_OR_SECTOR_NAME,strlen(Scene2ObjectInfo_t->sName)+7);
			WriteFile(hFileOwn,Scene2ObjectInfo_t->sName,strlen(Scene2ObjectInfo_t->sName)+1,&lBytesWritten,NULL);

			// 3. Position
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_POS,sizeof(Scene2ObjectInfo_t->fPos[0])*3+6);
			for(i=0;i<3;i++)
				WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fPos[i],sizeof(Scene2ObjectInfo_t->fPos[0]),&lBytesWritten,NULL);

			// 4. Rotation
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_ROT,sizeof(Scene2ObjectInfo_t->fRot[0])*4+6);
			for(i=0;i<4;i++)
				WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fRot[i],sizeof(Scene2ObjectInfo_t->fRot[0]),&lBytesWritten,NULL);

			// 5. Size
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_DIMENSION,sizeof(Scene2ObjectInfo_t->fSize[0])*3+6);
			for(i=0;i<3;i++)
				WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fSize[i],sizeof(Scene2ObjectInfo_t->fSize[0]),&lBytesWritten,NULL);

			// 6. Additional Translation
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_ADDTRANSLATION,sizeof(Scene2ObjectInfo_t->fAddTrans[0])*3+6);
			for(i=0;i<3;i++)
				WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fAddTrans[i],sizeof(Scene2ObjectInfo_t->fAddTrans[0]),&lBytesWritten,NULL);

			// 7. Sector Name
			// Create Main Datablock
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_SECTOR,strlen(Scene2ObjectInfo_t->sSectorName)+13);

			// now create sub-datablock with name of sector
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_OR_SECTOR_NAME,strlen(Scene2ObjectInfo_t->sSectorName)+7);
			WriteFile(hFileOwn,Scene2ObjectInfo_t->sSectorName,strlen(Scene2ObjectInfo_t->sSectorName)+1,&lBytesWritten,NULL);

			// 8. Type 06 Main
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_TYPE_06_DATA,lType06Main);
			for(i=0;i<6;i++)
				WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fVal[i],sizeof(Scene2ObjectInfo_t->fVal[0]),&lBytesWritten,NULL);


			// Close Handle to Object file
			CloseHandle(hFileOwn);

			// Add my object
			myHelper.PasteBufferedDataFM(hFile,"object.tmp",true);

			// Add other data
			myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

			SetEndOfFile(hFile);

			// -------------------------------------------------
			// Finally, change NORMAL_MAIN size
			if(szObjectToReplace!=NULL)
				lOffset=thisDatablock.FindDatablock(hFile,NORMAL_MAIN);
			SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);

			lNormalMainSize=thisDatablock.GetLong(hFile);

			if(szObjectToReplace!=NULL)
				lNormalMainSize+=(lDatablockSize-lObjectSize);
			else
				lNormalMainSize+=lDatablockSize;

			SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lNormalMainSize,4,&lBytesWritten,NULL);

			// Change size of scene2.bin file in header
			lScene2Size=GetFileSize(hFile);

			if(szObjectToReplace!=NULL)
				lScene2Size+=(lDatablockSize-lObjectSize);
			else
				lScene2Size+=lDatablockSize;
	
			SetFilePointer(hFile,2,0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lScene2Size,4,&lBytesWritten,NULL);
			break;

		case S_NORMAL_OBJECT_TYPE_LIGHT:

			// Remove f of object type indicator
			Scene2ObjectInfo_t->lType&=0x0F;

			// check if the object is supposed to be replaced
			if(szObjectToReplace!=NULL)
			{
				// Find Object to replace
				lDummyOffset=lOffset=FindObject(hFile,szObjectToReplace,NORMAL_MAIN);
				if(lOffset==-1)
					return(-1);	// stop function if object not found

				SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);

				// Find End of Object
				lObjectSize=thisDatablock.GetLong(hFile);

				SetFilePointer(hFile,(lObjectSize-6),0,FILE_CURRENT); //set file pointer to end of NORMAL_MAIN
				lDummyOffset+=lObjectSize;
			}
			else
			{
				// Find NORMAL_MAIN
				lDummyOffset=lOffset=thisDatablock.FindDatablock(hFile,NORMAL_MAIN);

				// Find END of NORMAL_MAIN
				lDatablockSize=thisDatablock.GetLong(hFile);

				//	lOffset2+=lOffset+lDatablockSize;				//save address of OBJECT_MAIN (end of NORMAL_MAIN)
				SetFilePointer(hFile,(lDatablockSize-6),0,FILE_CURRENT); //set file pointer to end of NORMAL_MAIN
				lDummyOffset+=lDatablockSize;
			}
				// save all upcoming data
//				myHelper.BufferData(hFile,"buffer.tmp",-1);
			myHelper.BufferDataFM(hFile,"buffer.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);

			// do we replace?
			if(szObjectToReplace!=NULL)
				// yes so we have to set back the file pointer cuz our object must be overwritten
				SetFilePointer(hFile,-(lObjectSize),0,FILE_CURRENT);

			// create the object file
			hFileOwn=CreateFile("object.tmp",GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,NULL);

			// Calculate main datablock size
			// For every datablock we have: Datasize+6

			// General
			lDatablockSize=6;
			// 1. Type
			lDatablockSize+=0x0A;

			// 2. Name
			lDatablockSize+=strlen(Scene2ObjectInfo_t->sName)+7;

			// 3. Position
			lDatablockSize+=0x12;

			// 4. Rotation
			lDatablockSize+=0x16;

			// 5. Size
			lDatablockSize+=0x12;

			// 6. Additional Translation
			lDatablockSize+=0x12;

			// 7. Sector Name
			if(strlen(Scene2ObjectInfo_t->sSectorName)!=0)
				lDatablockSize+=strlen(Scene2ObjectInfo_t->sSectorName)+13; // 12 - sector datablock + 12 - name datablock + 1 - the 0 at the end

			// 8. Light Main
			lDatablockSize+=lLightMain=6;

			// 9. Light Type
			lDatablockSize+=0x0A;
			lLightMain+=0x0A;

			// 10. Light Color
			lDatablockSize+=0x12;
			lLightMain+=0x12;

			// 11. Light Power
			lDatablockSize+=0x0A;
			lLightMain+=0x0A;

			// 12. Light Unk 1
			lDatablockSize+=0x0E;
			lLightMain+=0x0E;

			// 13. Light Range
			lDatablockSize+=0x0E;
			lLightMain+=0x0E;

			// 14. Light Flags
			lDatablockSize+=0x0A;
			lLightMain+=0x0A;

			// 15. Light Sectors
			do{
				lDatablockSize+=strlen(&Scene2ObjectInfo_t->sLightSectors[cur])+7;
				lLightMain+=strlen(&Scene2ObjectInfo_t->sLightSectors[cur])+7;
				cur+=strlen(&Scene2ObjectInfo_t->sLightSectors[cur])+1;
			}while(Scene2ObjectInfo_t->sLightSectors[cur]!=0);

			// Create a new main datablock for our object
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_MAIN,lDatablockSize);

			// Create sub datablocks

			// 1. Type
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_TYPE,sizeof(Scene2ObjectInfo_t->lType)+6);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->lType,sizeof(Scene2ObjectInfo_t->lType),&lBytesWritten,NULL);

			// 2. Name
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_OR_SECTOR_NAME,strlen(Scene2ObjectInfo_t->sName)+7);
			WriteFile(hFileOwn,Scene2ObjectInfo_t->sName,strlen(Scene2ObjectInfo_t->sName)+1,&lBytesWritten,NULL);

			// 3. Position
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_POS,sizeof(Scene2ObjectInfo_t->fPos[0])*3+6);
			for(i=0;i<3;i++)
				WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fPos[i],sizeof(Scene2ObjectInfo_t->fPos[0]),&lBytesWritten,NULL);

			// 4. Rotation
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_ROT,sizeof(Scene2ObjectInfo_t->fRot[0])*4+6);
			for(i=0;i<4;i++)
				WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fRot[i],sizeof(Scene2ObjectInfo_t->fRot[0]),&lBytesWritten,NULL);

			// 5. Size
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_DIMENSION,sizeof(Scene2ObjectInfo_t->fSize[0])*3+6);
			for(i=0;i<3;i++)
				WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fSize[i],sizeof(Scene2ObjectInfo_t->fSize[0]),&lBytesWritten,NULL);

			// 6. Additional Translation
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_ADDTRANSLATION,sizeof(Scene2ObjectInfo_t->fAddTrans[0])*3+6);
			for(i=0;i<3;i++)
				WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fAddTrans[i],sizeof(Scene2ObjectInfo_t->fAddTrans[0]),&lBytesWritten,NULL);

			// 7. Sector Name
			// Create Main Datablock
			// but check if light got a sector
			if(strlen(Scene2ObjectInfo_t->sSectorName)!=0)
			{
				thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_SECTOR,strlen(Scene2ObjectInfo_t->sSectorName)+13);

				// now create sub-datablock with name of sector
				thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_OR_SECTOR_NAME,strlen(Scene2ObjectInfo_t->sSectorName)+7);
				WriteFile(hFileOwn,Scene2ObjectInfo_t->sSectorName,strlen(Scene2ObjectInfo_t->sSectorName)+1,&lBytesWritten,NULL);
			}

			// 8. Light Main
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_LIGHTNING_MAIN,lLightMain);

			// 9. Light Type
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_LIGHTNING_TYPE,sizeof(Scene2ObjectInfo_t->lLightType)+6);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->lLightType,sizeof(Scene2ObjectInfo_t->lLightType),&lBytesWritten,NULL);

			// 10. Light Color
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_LIGHTNING_COLOR,sizeof(Scene2ObjectInfo_t->fRed)*3+6);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fRed,sizeof(Scene2ObjectInfo_t->fRed),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fGreen,sizeof(Scene2ObjectInfo_t->fGreen),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fBlue,sizeof(Scene2ObjectInfo_t->fBlue),&lBytesWritten,NULL);

			// 11. Light Power
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_LIGHTNING_POWER,sizeof(Scene2ObjectInfo_t->fPower)+6);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fPower,sizeof(Scene2ObjectInfo_t->fPower),&lBytesWritten,NULL);

			// 12. Light Unk_1
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_LIGHTNING_UNK_1,sizeof(Scene2ObjectInfo_t->fLightUnk1)*2+6);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fLightUnk1,sizeof(Scene2ObjectInfo_t->fLightUnk1),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fLightUnk2,sizeof(Scene2ObjectInfo_t->fLightUnk2),&lBytesWritten,NULL);

			// 13. Light Range
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_LIGHTNING_RANGE,sizeof(Scene2ObjectInfo_t->fLightNear)*2+6);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fLightNear,sizeof(Scene2ObjectInfo_t->fLightNear),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fLightFar,sizeof(Scene2ObjectInfo_t->fLightFar),&lBytesWritten,NULL);

			// 14. Light Flags
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_LIGHTNING_FLAGS,sizeof(Scene2ObjectInfo_t->lLightFlags)+6);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->lLightFlags,sizeof(Scene2ObjectInfo_t->lLightFlags),&lBytesWritten,NULL);

			// 15. Light Sectors
			cur=0;
			do{
				thisDatablock.CreateDatablock(hFileOwn,NORMAL_LIGHTNING_SECTOR,strlen(&Scene2ObjectInfo_t->sLightSectors[cur])+7);
				WriteFile(hFileOwn,&Scene2ObjectInfo_t->sLightSectors[cur],strlen(&Scene2ObjectInfo_t->sLightSectors[cur])+1,&lBytesWritten,NULL);
				cur+=strlen(&Scene2ObjectInfo_t->sLightSectors[cur])+1;
			}while(Scene2ObjectInfo_t->sLightSectors[cur]!=0);

			// Close Handle to Object file
			CloseHandle(hFileOwn);

			// Add my object
			myHelper.PasteBufferedDataFM(hFile,"object.tmp",true);

			// Add other data
			myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

			SetEndOfFile(hFile);

			// -------------------------------------------------
			// Finally, change NORMAL_MAIN size
			if(szObjectToReplace!=NULL)
				lOffset=thisDatablock.FindDatablock(hFile,NORMAL_MAIN);
			SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);

			lNormalMainSize=thisDatablock.GetLong(hFile);

			if(szObjectToReplace!=NULL)
				lNormalMainSize+=(lDatablockSize-lObjectSize);
			else
				lNormalMainSize+=lDatablockSize;

			SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lNormalMainSize,4,&lBytesWritten,NULL);

			// Change size of scene2.bin file in header
			lScene2Size=GetFileSize(hFile);

			if(szObjectToReplace!=NULL)
				lScene2Size+=(lDatablockSize-lObjectSize);
			else
				lScene2Size+=lDatablockSize;
	
			SetFilePointer(hFile,2,0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lScene2Size,4,&lBytesWritten,NULL);
			break;

		case NORMAL_OBJECT_TYPE_SECTOR:
			// check if the object is supposed to be replaced
			if(szObjectToReplace!=NULL)
			{
				// Find Object to replace
				lDummyOffset=lOffset=FindObject(hFile,szObjectToReplace,NORMAL_MAIN);
				if(lOffset==-1)
					return(-1);	// stop function if object not found

				SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);

				// Find End of Object
				lObjectSize=thisDatablock.GetLong(hFile);

				SetFilePointer(hFile,(lObjectSize-6),0,FILE_CURRENT); //set file pointer to end of NORMAL_MAIN
				lDummyOffset+=lObjectSize;
			}
			else
			{
				// Find NORMAL_MAIN
				lDummyOffset=lOffset=thisDatablock.FindDatablock(hFile,NORMAL_MAIN);

				// Find END of NORMAL_MAIN
				lDatablockSize=thisDatablock.GetLong(hFile);

				//	lOffset2+=lOffset+lDatablockSize;				//save address of OBJECT_MAIN (end of NORMAL_MAIN)
				SetFilePointer(hFile,(lDatablockSize-6),0,FILE_CURRENT); //set file pointer to end of NORMAL_MAIN
				lDummyOffset+=lDatablockSize;
			}
				// save all upcoming data
//				myHelper.BufferData(hFile,"buffer.tmp",-1);
			myHelper.BufferDataFM(hFile,"buffer.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);

			// do we replace?
			if(szObjectToReplace!=NULL)
				// yes so we have to set back the file pointer cuz our object must be overwritten
				SetFilePointer(hFile,-(lObjectSize),0,FILE_CURRENT);

			// create the object file
			hFileOwn=CreateFile("object.tmp",GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,NULL);

			// setup size
			lDatablockSize=0xFE;		// size of normal sector object without name
			// add size of name
			lDatablockSize+=strlen(Scene2ObjectInfo_t->sName)+1;

			// setup datablocks

			// main
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_MAIN,lDatablockSize);

			// Name
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_OR_SECTOR_NAME,strlen(Scene2ObjectInfo_t->sName)+7);
			WriteFile(hFileOwn,Scene2ObjectInfo_t->sName,strlen(Scene2ObjectInfo_t->sName)+1,&lBytesWritten,NULL);

			// sector main
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_SECTOR_MAIN,0xF2);

			// NORMAL_SECTOR_UNK_1
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_SECTOR_UNK_1,0x0A);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fSectorVal1,sizeof(Scene2ObjectInfo_t->fSectorVal1),&lBytesWritten,NULL);

			// NORMAL_SECTOR_UNK_2
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_SECTOR_UNK_2,0x0A);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fSectorVal2,sizeof(Scene2ObjectInfo_t->fSectorVal2),&lBytesWritten,NULL);

			// DATABLOCK_COMMENT
			thisDatablock.CreateDatablock(hFileOwn,DATABLOCK_COMMENT,0x0A);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fSectorVal3,sizeof(Scene2ObjectInfo_t->fSectorVal3),&lBytesWritten,NULL);

			// NORMAL_SECTOR_UNK_3
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_SECTOR_UNK_3,0x0A);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fSectorVal4,sizeof(Scene2ObjectInfo_t->fSectorVal4),&lBytesWritten,NULL);

			// NORMAL_SECTOR_UNK_4
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_SECTOR_UNK_4,0x0A);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->lSectorVal5,sizeof(Scene2ObjectInfo_t->lSectorVal5),&lBytesWritten,NULL);

			// NORMAL_SECTOR_UNK_5
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_SECTOR_UNK_5,0x0A);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fSectorVal6,sizeof(Scene2ObjectInfo_t->fSectorVal6),&lBytesWritten,NULL);

			// NORMAL_SECTOR_UNK_6
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_SECTOR_UNK_6,0x0A);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->lSectorVal7,sizeof(Scene2ObjectInfo_t->lSectorVal7),&lBytesWritten,NULL);

			// NORMAL_SECTOR_UNK_7
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_SECTOR_UNK_7,0x0A);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fSectorVal8,sizeof(Scene2ObjectInfo_t->fSectorVal8),&lBytesWritten,NULL);

			// NORMAL_SECTOR_UNK_8
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_SECTOR_UNK_8,0x0A);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->lSectorVal9,sizeof(Scene2ObjectInfo_t->lSectorVal9),&lBytesWritten,NULL);

			// NORMAL_SECTOR_UNK_9
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_SECTOR_UNK_9,0x0A);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fSectorVal10,sizeof(Scene2ObjectInfo_t->fSectorVal10),&lBytesWritten,NULL);

			// NORMAL_SECTOR_UNK_10
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_SECTOR_UNK_10,0x0A);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fSectorVal11,sizeof(Scene2ObjectInfo_t->fSectorVal11),&lBytesWritten,NULL);

			// NORMAL_SECTOR_UNK_11
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_SECTOR_UNK_11,0x0A);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->lSectorVal12,sizeof(Scene2ObjectInfo_t->lSectorVal12),&lBytesWritten,NULL);

			// NORMAL_SECTOR_UNK_12
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_SECTOR_UNK_12,0x0A);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->lSectorVal13,sizeof(Scene2ObjectInfo_t->lSectorVal13),&lBytesWritten,NULL);

			// NORMAL_SECTOR_UNK_13
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_SECTOR_UNK_13,0x0A);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->lSectorVal14,sizeof(Scene2ObjectInfo_t->lSectorVal14),&lBytesWritten,NULL);

			// NORMAL_SECTOR_UNK_14
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_SECTOR_UNK_14,0x0A);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->lSectorVal15,sizeof(Scene2ObjectInfo_t->lSectorVal15),&lBytesWritten,NULL);

			// NORMAL_SECTOR_UNK_15
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_SECTOR_UNK_15,0x0A);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fSectorVal16,sizeof(Scene2ObjectInfo_t->fSectorVal16),&lBytesWritten,NULL);

			// NORMAL_OBJECT_OR_SECTOR_NAME
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_OBJECT_OR_SECTOR_NAME,0x0A);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->lSectorVal17,sizeof(Scene2ObjectInfo_t->lSectorVal17),&lBytesWritten,NULL);

			// NORMAL_SECTOR_UNK_17
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_SECTOR_UNK_17,0x0A);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fSectorVal18,sizeof(Scene2ObjectInfo_t->fSectorVal18),&lBytesWritten,NULL);

			// NORMAL_SECTOR_UNK_18
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_SECTOR_UNK_18,0x0A);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fSectorVal19,sizeof(Scene2ObjectInfo_t->fSectorVal19),&lBytesWritten,NULL);

			// NORMAL_SECTOR_UNK_19
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_SECTOR_UNK_19,0x0A);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->lSectorVal20,sizeof(Scene2ObjectInfo_t->lSectorVal20),&lBytesWritten,NULL);

			// NORMAL_SECTOR_UNK_20
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_SECTOR_UNK_20,0x12);
			for(i=0;i<3;i++)
				WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->lSectorVal21[i],sizeof(Scene2ObjectInfo_t->lSectorVal21[i]),&lBytesWritten,NULL);

			// NORMAL_SECTOR_UNK_21
			thisDatablock.CreateDatablock(hFileOwn,NORMAL_SECTOR_UNK_21,0x12);
			for(i=0;i<3;i++)
				WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->lSectorVal22[i],sizeof(Scene2ObjectInfo_t->lSectorVal22[i]),&lBytesWritten,NULL);

			// Close Handle to Object file
			CloseHandle(hFileOwn);

			// Add my object
			myHelper.PasteBufferedDataFM(hFile,"object.tmp",true);

			// Add other data
			myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

			SetEndOfFile(hFile);

			// -------------------------------------------------
			// Finally, change NORMAL_MAIN size
			if(szObjectToReplace!=NULL)
				lOffset=thisDatablock.FindDatablock(hFile,NORMAL_MAIN);
			SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);

			lNormalMainSize=thisDatablock.GetLong(hFile);

			if(szObjectToReplace!=NULL)
				lNormalMainSize+=(lDatablockSize-lObjectSize);
			else
				lNormalMainSize+=lDatablockSize;

			SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lNormalMainSize,4,&lBytesWritten,NULL);

			// Change size of scene2.bin file in header
			lScene2Size=GetFileSize(hFile);

			if(szObjectToReplace!=NULL)
				lScene2Size+=(lDatablockSize-lObjectSize);
			else
				lScene2Size+=lDatablockSize;
	
			SetFilePointer(hFile,2,0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lScene2Size,4,&lBytesWritten,NULL);

			break;

		case SPECIAL_OBJECT_TYPE_CAR:
			// car is simple - we easily add the cardata[CARDATASIZE] data
			// Find SPECIAL_MAIN
			lDummyOffset=lOffset=thisDatablock.FindDatablock(hFile,SPECIAL_MAIN);
			SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);

			// Find END of SPECIAL_MAIN
			lDatablockSize=thisDatablock.GetLong(hFile);

			SetFilePointer(hFile,(lDatablockSize-6),0,FILE_CURRENT); //set file pointer to end of NORMAL_MAIN
			lDummyOffset+=lDatablockSize;

			// buffer data
			myHelper.BufferDataFM(hFile,"buffer.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);

			// write cardata
			WriteFile(hFile,cardata,CARDATASIZE,&lBytesWritten,NULL);

			// Paste other data
			myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

			// Change sizes

			// 1. SPECIAL_MAIN
			SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);
			lSpecialMainSize=thisDatablock.GetLong(hFile);
			lSpecialMainSize+=CARDATASIZE;
			SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lSpecialMainSize,sizeof(lSpecialMainSize),&lBytesWritten,NULL);

			// 2. SCENE2_MAIN
			SetFilePointer(hFile,2,0,FILE_BEGIN);
			lScene2Size=thisDatablock.GetLong(hFile);
			lScene2Size+=CARDATASIZE;
			SetFilePointer(hFile,2,0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lScene2Size,sizeof(lScene2Size),&lBytesWritten,NULL);
			break;

		case SPECIAL_OBJECT_TYPE_SCRIPT:
			// script is simple - we easily add the scriptdata[SCRIPTDATASIZE] data
			// Find SPECIAL_MAIN
			lDummyOffset=lOffset=thisDatablock.FindDatablock(hFile,SPECIAL_MAIN);
			SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);

			// Find END of SPECIAL_MAIN
			lDatablockSize=thisDatablock.GetLong(hFile);

			SetFilePointer(hFile,(lDatablockSize-6),0,FILE_CURRENT); //set file pointer to end of NORMAL_MAIN
			lDummyOffset+=lDatablockSize;

			// buffer data
			myHelper.BufferDataFM(hFile,"buffer.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);

			// write scriptdata
			WriteFile(hFile,scriptdata,SCRIPTDATASIZE,&lBytesWritten,NULL);

			// Paste other data
			myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

			// Change sizes

			// 1. SPECIAL_MAIN
			SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);
			lSpecialMainSize=thisDatablock.GetLong(hFile);
			lSpecialMainSize+=SCRIPTDATASIZE;
			SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lSpecialMainSize,sizeof(lSpecialMainSize),&lBytesWritten,NULL);

			// 2. SCENE2_MAIN
			SetFilePointer(hFile,2,0,FILE_BEGIN);
			lScene2Size=thisDatablock.GetLong(hFile);
			lScene2Size+=SCRIPTDATASIZE;
			SetFilePointer(hFile,2,0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lScene2Size,sizeof(lScene2Size),&lBytesWritten,NULL);
			break;

		case ADDITIONAL_OBJECT_TYPE_SCRIPT:
			// script is simple - we easily add the initscriptdata[INITSCRIPTDATASIZE] data
			// Find ADDITIONAL_MAIN
			lDummyOffset=lOffset=thisDatablock.FindDatablock(hFile,ADDITIONAL_MAIN);
			SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);

			// Find END of ADDITIONAL_MAIN
			lDatablockSize=thisDatablock.GetLong(hFile);

			SetFilePointer(hFile,(lDatablockSize-6),0,FILE_CURRENT); //set file pointer to end of ADDITIONAL_MAIN
			lDummyOffset+=lDatablockSize;

			// buffer data
			myHelper.BufferDataFM(hFile,"buffer.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);

			// write scriptdata
			WriteFile(hFile,initscriptdata,INITSCRIPTDATASIZE,&lBytesWritten,NULL);

			// Paste other data
			myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

			// Change sizes

			// 1. ADDITIONAL_MAIN
			SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);
			lSpecialMainSize=thisDatablock.GetLong(hFile);
			lSpecialMainSize+=INITSCRIPTDATASIZE;
			SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lSpecialMainSize,sizeof(lSpecialMainSize),&lBytesWritten,NULL);

			// 2. SCENE2_MAIN
			SetFilePointer(hFile,2,0,FILE_BEGIN);
			lScene2Size=thisDatablock.GetLong(hFile);
			lScene2Size+=INITSCRIPTDATASIZE;
			SetFilePointer(hFile,2,0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lScene2Size,sizeof(lScene2Size),&lBytesWritten,NULL);
			break;

		case SPECIAL_OBJECT_TYPE_SHOOTABLE:
			// replace existing object?
			if(szObjectToReplace!=NULL)
			{
				// Find Object to replace
				lDummyOffset=lOffset=FindObject(hFile,szObjectToReplace,SPECIAL_MAIN);
				if(lOffset==-1)
					return(-1);	// stop function if object not found

				SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);

				// Find End of Object
				lObjectSize=thisDatablock.GetLong(hFile);

				SetFilePointer(hFile,(lObjectSize-6),0,FILE_CURRENT); //set file pointer to end of NORMAL_MAIN
				lDummyOffset+=lObjectSize;
			}
			else
			{
				// Find SPECIAL_MAIN
				lDummyOffset=lOffset=thisDatablock.FindDatablock(hFile,SPECIAL_MAIN);
				SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);

				// Find END of SPECIAL_MAIN
				lDatablockSize=thisDatablock.GetLong(hFile);

				SetFilePointer(hFile,(lDatablockSize-6),0,FILE_CURRENT); //set file pointer to end of NORMAL_MAIN
				lDummyOffset+=lDatablockSize;
			}

			// save all upcoming data
//			myHelper.BufferData(hFile,"buffer.tmp",-1);
			myHelper.BufferDataFM(hFile,"buffer.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);

			// do we replace?
			if(szObjectToReplace!=NULL)
				// yes so we have to set back the file pointer cuz our object must be overwritten
				SetFilePointer(hFile,-(lObjectSize),0,FILE_CURRENT);

			// create the object file
			hFileOwn=CreateFile("object.tmp",GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,NULL);

			// Calculate main datablock size

			lScriptSize=myHelper.GetFileSize(szScriptFileName);

			if(szScriptFileName!=NULL)
//				lDatablockSize=6+lScriptSize+1;
				lDatablockSize=6+lScriptSize;
			else
				lDatablockSize=6;

			// 1. Name Datablock
			lDatablockSize+=strlen(Scene2ObjectInfo_t->sName)+7;

			// 2. Type Datablock
			lDatablockSize+=0x0A;

			// 3. Data Datablock
			lDatablockSize+=0x25;

			//--------NOW WRITE DATA

			// 1. Main Datablock
			thisDatablock.CreateDatablock(hFileOwn,SPECIAL_OBJECT_MAIN,lDatablockSize);

			// 2. Name Datablock
			thisDatablock.CreateDatablock(hFileOwn,SPECIAL_OBJECT_NAME,strlen(Scene2ObjectInfo_t->sName)+7);
			WriteFile(hFileOwn,Scene2ObjectInfo_t->sName,strlen(Scene2ObjectInfo_t->sName)+1,&lBytesWritten,NULL);

			// 3. Type Datablock
			thisDatablock.CreateDatablock(hFileOwn,SPECIAL_OBJECT_TYPE,0x0A);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->lType,sizeof(Scene2ObjectInfo_t->lType),&lBytesWritten,NULL);

			// 4. Data Datablock
			if(szScriptFileName!=NULL)
				thisDatablock.CreateDatablock(hFileOwn,SPECIAL_OBJECT_DATA,0x25+lScriptSize);
			else
				thisDatablock.CreateDatablock(hFileOwn,SPECIAL_OBJECT_DATA,0x25);

//			WriteFile(hFileOwn,(char *)&,sizeof(),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&datatype_movable,sizeof(datatype_movable),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fMovVal1,sizeof(Scene2ObjectInfo_t->fMovVal1),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fMovVal2,sizeof(Scene2ObjectInfo_t->fMovVal2),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fWeight,sizeof(Scene2ObjectInfo_t->fWeight),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fMovVal3,sizeof(Scene2ObjectInfo_t->fMovVal3),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fMovVal4,sizeof(Scene2ObjectInfo_t->fMovVal4),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->lSound,sizeof(Scene2ObjectInfo_t->lSound),&lBytesWritten,NULL);
			WriteFile(hFileOwn,&one,1,&lBytesWritten,NULL);	//strange thing but the 1 needs to be put :|
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->lMovVal5,sizeof(Scene2ObjectInfo_t->lMovVal5),&lBytesWritten,NULL);
			
			// Append script if one was specified
			if(szScriptFileName!=NULL)
				myHelper.PasteBufferedDataFM(hFileOwn,szScriptFileName,true);

			CloseHandle(hFileOwn);

			// Paste object
			myHelper.PasteBufferedDataFM(hFile,"object.tmp",true);

			// Paste other data
			myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

			SetEndOfFile(hFile);

			// Change sizes

			// 1. SPECIAL_MAIN
			if(szObjectToReplace!=NULL)
				lOffset=thisDatablock.FindDatablock(hFile,SPECIAL_MAIN);
			SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);
			lSpecialMainSize=thisDatablock.GetLong(hFile);
			if(szObjectToReplace!=NULL)
				lSpecialMainSize+=(lDatablockSize-lObjectSize);
			else
				lSpecialMainSize+=lDatablockSize;
			SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lSpecialMainSize,sizeof(lSpecialMainSize),&lBytesWritten,NULL);

			// 2. SCENE2_MAIN
			SetFilePointer(hFile,2,0,FILE_BEGIN);
			lScene2Size=thisDatablock.GetLong(hFile);
			if(szObjectToReplace!=NULL)
				lScene2Size+=(lDatablockSize-lObjectSize);
			else
				lScene2Size+=lDatablockSize;
			SetFilePointer(hFile,2,0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lScene2Size,sizeof(lScene2Size),&lBytesWritten,NULL);
			break;

		case SPECIAL_OBJECT_TYPE_TRAFFIC:
			// replace existing object?
			if(szObjectToReplace!=NULL)
			{
				// Find Object to replace
				lDummyOffset=lOffset=FindObject(hFile,szObjectToReplace,SPECIAL_MAIN);
				if(lOffset==-1)
					return(-1);	// stop function if object not found

				SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);

				// Find End of Object
				lObjectSize=thisDatablock.GetLong(hFile);

				SetFilePointer(hFile,(lObjectSize-6),0,FILE_CURRENT); //set file pointer to end of NORMAL_MAIN
				lDummyOffset+=lObjectSize;
			}
			else
			{
				// Find SPECIAL_MAIN
				lDummyOffset=lOffset=thisDatablock.FindDatablock(hFile,SPECIAL_MAIN);
				SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);

				// Find END of SPECIAL_MAIN
				lDatablockSize=thisDatablock.GetLong(hFile);

				SetFilePointer(hFile,(lDatablockSize-6),0,FILE_CURRENT); //set file pointer to end of NORMAL_MAIN
				lDummyOffset+=lDatablockSize;
			}

			// save all upcoming data
//			myHelper.BufferData(hFile,"buffer.tmp",-1);
			myHelper.BufferDataFM(hFile,"buffer.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);

			// do we replace?
			if(szObjectToReplace!=NULL)
				// yes so we have to set back the file pointer cuz our object must be overwritten
				SetFilePointer(hFile,-(lObjectSize),0,FILE_CURRENT);

			// create the object file
			hFileOwn=CreateFile("object.tmp",GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,NULL);

			// Calculate main datablock size

			lScriptSize=myHelper.GetFileSize(szScriptFileName);

			if(szScriptFileName!=NULL)
//				lDatablockSize=6+lScriptSize+1;
				lDatablockSize=6+lScriptSize;
			else
				lDatablockSize=6;

			// 1. Name Datablock
			lDatablockSize+=strlen(Scene2ObjectInfo_t->sName)+7;

			// 2. Type Datablock
			lDatablockSize+=0x0A;

			// 3. Data Datablock
			lDatablockSize+=30+(Scene2ObjectInfo_t->lNumOfCars*32);

			//--------NOW WRITE DATA

			// 1. Main Datablock
			thisDatablock.CreateDatablock(hFileOwn,SPECIAL_OBJECT_MAIN,lDatablockSize);

			// 2. Name Datablock
			thisDatablock.CreateDatablock(hFileOwn,SPECIAL_OBJECT_NAME,strlen(Scene2ObjectInfo_t->sName)+7);
			WriteFile(hFileOwn,Scene2ObjectInfo_t->sName,strlen(Scene2ObjectInfo_t->sName)+1,&lBytesWritten,NULL);

			// 3. Type Datablock
			thisDatablock.CreateDatablock(hFileOwn,SPECIAL_OBJECT_TYPE,0x0A);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->lType,sizeof(Scene2ObjectInfo_t->lType),&lBytesWritten,NULL);

			// 4. Data Datablock
			if(szScriptFileName!=NULL)
				thisDatablock.CreateDatablock(hFileOwn,SPECIAL_OBJECT_DATA,30+(Scene2ObjectInfo_t->lNumOfCars*32)+lScriptSize);
			else
				thisDatablock.CreateDatablock(hFileOwn,SPECIAL_OBJECT_DATA,30+(Scene2ObjectInfo_t->lNumOfCars*32));

//			WriteFile(hFileOwn,(char *)&,sizeof(),&lBytesWritten,NULL);
			WriteFile(hFileOwn,&datatype_traffic,sizeof(datatype_traffic),&lBytesWritten,NULL);
			WriteFile(hFileOwn,null,sizeof(null),&lBytesWritten,NULL);
			for(i=0;i<3;i++)
				WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fTrafficVal[i],sizeof(Scene2ObjectInfo_t->fTrafficVal[i]),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->lDensity,sizeof(Scene2ObjectInfo_t->lDensity),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->lNumOfCars,sizeof(Scene2ObjectInfo_t->lNumOfCars),&lBytesWritten,NULL);

			// now write car entries
			for(i=0;i<Scene2ObjectInfo_t->lNumOfCars;i++)
			{
				if(!Scene2ObjectInfo_t->bDel[i])
				{
					WriteFile(hFileOwn,Scene2ObjectInfo_t->sCarname[i],strlen(Scene2ObjectInfo_t->sCarname[i])+1,&lBytesWritten,NULL);
					WriteFile(hFileOwn,bignull,20-(strlen(Scene2ObjectInfo_t->sCarname[i])+1),&lBytesWritten,NULL);
					WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fDensity[i],sizeof(Scene2ObjectInfo_t->fDensity[i]),&lBytesWritten,NULL);
					WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->lColor[i],sizeof(Scene2ObjectInfo_t->lColor[i]),&lBytesWritten,NULL);
					WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->bPolice[i],sizeof(Scene2ObjectInfo_t->bPolice[i]),&lBytesWritten,NULL);
					WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->bFlag2[i],sizeof(Scene2ObjectInfo_t->bFlag2[i]),&lBytesWritten,NULL);
					WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->bGangster[i],sizeof(Scene2ObjectInfo_t->bGangster[i]),&lBytesWritten,NULL);
					WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->bFlag4[i],sizeof(Scene2ObjectInfo_t->bFlag4[i]),&lBytesWritten,NULL);
				}
				else
					Scene2ObjectInfo_t->lNumOfCars++;
			}
			
			// Append script if one was specified
			if(szScriptFileName!=NULL)
				myHelper.PasteBufferedDataFM(hFileOwn,szScriptFileName,true);

			CloseHandle(hFileOwn);

			// Paste object
			myHelper.PasteBufferedDataFM(hFile,"object.tmp",true);

			// Paste other data
			myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

			SetEndOfFile(hFile);

			// Change sizes

			// 1. SPECIAL_MAIN
			if(szObjectToReplace!=NULL)
				lOffset=thisDatablock.FindDatablock(hFile,SPECIAL_MAIN);
			SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);
			lSpecialMainSize=thisDatablock.GetLong(hFile);
			if(szObjectToReplace!=NULL)
				lSpecialMainSize+=(lDatablockSize-lObjectSize);
			else
				lSpecialMainSize+=lDatablockSize;
			SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lSpecialMainSize,sizeof(lSpecialMainSize),&lBytesWritten,NULL);

			// 2. SCENE2_MAIN
			SetFilePointer(hFile,2,0,FILE_BEGIN);
			lScene2Size=thisDatablock.GetLong(hFile);
			if(szObjectToReplace!=NULL)
				lScene2Size+=(lDatablockSize-lObjectSize);
			else
				lScene2Size+=lDatablockSize;
			SetFilePointer(hFile,2,0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lScene2Size,sizeof(lScene2Size),&lBytesWritten,NULL);
			break;

		case SPECIAL_OBJECT_TYPE_CHARACTER:
		case SPECIAL_OBJECT_TYPE_PLAYER:
			// replace existing object?
			if(szObjectToReplace!=NULL)
			{
				// Find Object to replace
				lDummyOffset=lOffset=FindObject(hFile,szObjectToReplace,SPECIAL_MAIN);
				if(lOffset==-1)
					return(-1);	// stop function if object not found

				SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);

				// Find End of Object
				lObjectSize=thisDatablock.GetLong(hFile);

				SetFilePointer(hFile,(lObjectSize-6),0,FILE_CURRENT); //set file pointer to end of NORMAL_MAIN
				lDummyOffset+=lObjectSize;
			}
			else
			{
				// Find SPECIAL_MAIN
				lDummyOffset=lOffset=thisDatablock.FindDatablock(hFile,SPECIAL_MAIN);
				SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);

				// Find END of SPECIAL_MAIN
				lDatablockSize=thisDatablock.GetLong(hFile);

				SetFilePointer(hFile,(lDatablockSize-6),0,FILE_CURRENT); //set file pointer to end of NORMAL_MAIN
				lDummyOffset+=lDatablockSize;
			}

			// save all upcoming data
//			myHelper.BufferData(hFile,"buffer.tmp",-1);
			myHelper.BufferDataFM(hFile,"buffer.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);

			// do we replace?
			if(szObjectToReplace!=NULL)
				// yes so we have to set back the file pointer cuz our object must be overwritten
				SetFilePointer(hFile,-(lObjectSize),0,FILE_CURRENT);

			// create the object file
			hFileOwn=CreateFile("object.tmp",GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,NULL);

			// Calculate main datablock size

			lScriptSize=myHelper.GetFileSize(szScriptFileName);

			if(szScriptFileName!=NULL)
//				lDatablockSize=6+lScriptSize+1;
				lDatablockSize=6+lScriptSize;
			else
				lDatablockSize=6;

			// 1. Name Datablock
			lDatablockSize+=strlen(Scene2ObjectInfo_t->sName)+7;

			// 2. Type Datablock
			lDatablockSize+=0x0A;

			// 3. Data Datablock
			lDatablockSize+=0x4f;

			//--------NOW WRITE DATA

			// 1. Main Datablock
			thisDatablock.CreateDatablock(hFileOwn,SPECIAL_OBJECT_MAIN,lDatablockSize);

			// 2. Name Datablock
			thisDatablock.CreateDatablock(hFileOwn,SPECIAL_OBJECT_NAME,strlen(Scene2ObjectInfo_t->sName)+7);
			WriteFile(hFileOwn,Scene2ObjectInfo_t->sName,strlen(Scene2ObjectInfo_t->sName)+1,&lBytesWritten,NULL);

			// 3. Type Datablock
			thisDatablock.CreateDatablock(hFileOwn,SPECIAL_OBJECT_TYPE,0x0A);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->lType,sizeof(Scene2ObjectInfo_t->lType),&lBytesWritten,NULL);

			// 4. Data Datablock
			if(szScriptFileName!=NULL)
				thisDatablock.CreateDatablock(hFileOwn,SPECIAL_OBJECT_DATA,0x4f+lScriptSize);
			else
				thisDatablock.CreateDatablock(hFileOwn,SPECIAL_OBJECT_DATA,0x4f);

//			WriteFile(hFileOwn,(char *)&,sizeof(),&lBytesWritten,NULL);
			WriteFile(hFileOwn,&datatype_character,1,&lBytesWritten,NULL);
			WriteFile(hFileOwn,&Scene2ObjectInfo_t->cBehaviour,sizeof(Scene2ObjectInfo_t->cBehaviour),&lBytesWritten,NULL);
			WriteFile(hFileOwn,&null,3,&lBytesWritten,NULL);
			WriteFile(hFileOwn,&Scene2ObjectInfo_t->cVoice,sizeof(Scene2ObjectInfo_t->cVoice),&lBytesWritten,NULL);
			WriteFile(hFileOwn,&null,3,&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fStrenght,sizeof(Scene2ObjectInfo_t->fStrenght),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fEnergy,sizeof(Scene2ObjectInfo_t->fEnergy),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fEnergy_HANDL,sizeof(Scene2ObjectInfo_t->fEnergy_HANDL),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fEnergy_HANDR,sizeof(Scene2ObjectInfo_t->fEnergy_HANDR),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fEnergy_LEGL,sizeof(Scene2ObjectInfo_t->fEnergy_LEGL),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fEnergy_LEGR,sizeof(Scene2ObjectInfo_t->fEnergy_LEGR),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fReactions,sizeof(Scene2ObjectInfo_t->fReactions),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fSpeed,sizeof(Scene2ObjectInfo_t->fSpeed),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fAggr,sizeof(Scene2ObjectInfo_t->fAggr),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fInt,sizeof(Scene2ObjectInfo_t->fInt),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fShooting,sizeof(Scene2ObjectInfo_t->fShooting),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fSight,sizeof(Scene2ObjectInfo_t->fSight),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fHearing,sizeof(Scene2ObjectInfo_t->fHearing),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fDriving,sizeof(Scene2ObjectInfo_t->fDriving),&lBytesWritten,NULL);
			WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fMass,sizeof(Scene2ObjectInfo_t->fMass),&lBytesWritten,NULL);
//			if(Scene2ObjectInfo_t->lType==SPECIAL_OBJECT_TYPE_CHARACTER)
				WriteFile(hFileOwn,(char *)&Scene2ObjectInfo_t->fBehaviour,sizeof(Scene2ObjectInfo_t->fBehaviour),&lBytesWritten,NULL);
			
			// Append script if one was specified
			if(szScriptFileName!=NULL)
				myHelper.PasteBufferedDataFM(hFileOwn,szScriptFileName,true);

			CloseHandle(hFileOwn);

			// Paste object
			myHelper.PasteBufferedDataFM(hFile,"object.tmp",true);

			// Paste other data
			myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

			SetEndOfFile(hFile);

			// Change sizes

			// 1. SPECIAL_MAIN
			if(szObjectToReplace!=NULL)
				lOffset=thisDatablock.FindDatablock(hFile,SPECIAL_MAIN);
			SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);
			lSpecialMainSize=thisDatablock.GetLong(hFile);
			if(szObjectToReplace!=NULL)
				lSpecialMainSize+=(lDatablockSize-lObjectSize);
			else
				lSpecialMainSize+=lDatablockSize;
			SetFilePointer(hFile,(lOffset+2),0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lSpecialMainSize,sizeof(lSpecialMainSize),&lBytesWritten,NULL);

			// 2. SCENE2_MAIN
			SetFilePointer(hFile,2,0,FILE_BEGIN);
			lScene2Size=thisDatablock.GetLong(hFile);
			if(szObjectToReplace!=NULL)
				lScene2Size+=(lDatablockSize-lObjectSize);
			else
				lScene2Size+=lDatablockSize;
			SetFilePointer(hFile,2,0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lScene2Size,sizeof(lScene2Size),&lBytesWritten,NULL);
			break;

	}
	return(1);
}

// Reads out the distance between the cam and the player
float CScene2::GetCamDist(HANDLE hFile)
{
	thisDatablock.FindDatablock(hFile,GENERAL_SCENE2_CAMERA);
	SetFilePointer(hFile,4,0,FILE_CURRENT);
	return(thisDatablock.GetFloat(hFile));
}

// Reads out the viewdistance
float CScene2::GetViewDist(HANDLE hFile)
{
	thisDatablock.FindDatablock(hFile,GENERAL_SCENE2_VIEW);
	SetFilePointer(hFile,4,0,FILE_CURRENT);
	return(thisDatablock.GetFloat(hFile));
}

// Used for modifying the camera distance
long CScene2::SetCamDist(HANDLE hFile, float fCamDist)
{
	unsigned long lBytesWritten=0;
	thisDatablock.FindDatablock(hFile,GENERAL_SCENE2_CAMERA);
	SetFilePointer(hFile,4,0,FILE_CURRENT);
	WriteFile(hFile,(char *)&fCamDist,sizeof(fCamDist),&lBytesWritten,NULL);
	return(lBytesWritten);
}

// Used for modifying the viewdistance
long CScene2::SetViewDist(HANDLE hFile, float fViewDist)
{
	unsigned long lBytesWritten=0;
	thisDatablock.FindDatablock(hFile,GENERAL_SCENE2_VIEW);
	SetFilePointer(hFile,4,0,FILE_CURRENT);
	WriteFile(hFile,(char *)&fViewDist,sizeof(fViewDist),&lBytesWritten,NULL);
	return(lBytesWritten);
}



// Used for reading the (probably) wolrd dimension
float CScene2::GetWorldDim(HANDLE hFile, bool bReadFirst)
{
	thisDatablock.FindDatablock(hFile,GENERAL_SCENE2_VIEW_SPECIAL);
	if(bReadFirst)
		SetFilePointer(hFile,4,0,FILE_CURRENT);
	else
		SetFilePointer(hFile,8,0,FILE_CURRENT);
	return(thisDatablock.GetFloat(hFile));
}

// Writes the world dimension
long CScene2::SetWorldDim(HANDLE hFile, float fDim1, float fDim2)
{
	unsigned long lBytesWritten=0;
	thisDatablock.FindDatablock(hFile,GENERAL_SCENE2_VIEW_SPECIAL);
	SetFilePointer(hFile,4,0,FILE_CURRENT);
	WriteFile(hFile,(char *)&fDim1,sizeof(fDim1),&lBytesWritten,NULL);
	WriteFile(hFile,(char *)&fDim2,sizeof(fDim2),&lBytesWritten,NULL);
	return(lBytesWritten);
}

// Used for finding objects
long CScene2::FindObject(HANDLE hFile, char * szObjectName, short nDatablockType)
{
	CDatablock thisDatablock;
	short nType=DATABLOCK_UNKNOWN;
	long lMainSize=0, lSubSize=0, lObjectOffsetMain=0, lObjectOffsetDummy=0;
	unsigned long lBytesRead=0;
	char szObjectNameDummy[256];	// 256 chars max

	// first check if nDatablockType is set correctly
	if((nDatablockType==NORMAL_MAIN)||(nDatablockType==SPECIAL_MAIN)||(nDatablockType==ADDITIONAL_MAIN)||(nDatablockType==0))
	{
		// First set file pointer to 6 bytes after file begin
		SetFilePointer(hFile,6,0,FILE_BEGIN);
		lObjectOffsetDummy=6;
	
		while(1)
		{
			nType=thisDatablock.GetShort(hFile);
			if(nType==SCENE2_EOF)
				return(-1);
			lMainSize=thisDatablock.GetLong(hFile);

			switch(nType)
			{
				case NORMAL_OBJECT_MAIN:
					// first check if the object is to be searched in the NORMAL_MAIN
					// datablock
					if((nDatablockType==SPECIAL_MAIN) || (nDatablockType==ADDITIONAL_MAIN))
					{
						SetFilePointer(hFile,(lMainSize-6),0,FILE_CURRENT);
						lObjectOffsetDummy+=lMainSize;
						break;
					}
					// First save offset of object
					lObjectOffsetMain=lObjectOffsetDummy;
					lObjectOffsetDummy=lObjectOffsetMain+lMainSize;
	
					// if it was one of the object main buffers, the name is situated directly
					// after the main datablock. However we check if the upcoming datablock
					// is the name datablock
					nType=thisDatablock.GetShort(hFile);
					if((nType==NORMAL_OBJECT_OR_SECTOR_NAME) || (nType==SPECIAL_OBJECT_NAME))
					{
						
						lSubSize=thisDatablock.GetLong(hFile);
						lSubSize-=6;	// to get effective size
						ReadFile(hFile,szObjectNameDummy,lSubSize,&lBytesRead,NULL);
						if(!strcmp(szObjectNameDummy,szObjectName))
							return(lObjectOffsetMain);
						// Put file pointer to next object
						SetFilePointer(hFile,(lMainSize-(lSubSize+6)-6),0,FILE_CURRENT);
					}
					else
					{
						SetFilePointer(hFile,10,0,FILE_CURRENT);
						lSubSize=thisDatablock.GetLong(hFile);
						lSubSize-=6;	// to get effective size
						ReadFile(hFile,szObjectNameDummy,lSubSize,&lBytesRead,NULL);
						if(!strcmp(szObjectNameDummy,szObjectName))
							return(lObjectOffsetMain);
						// Put file pointer to next object
						SetFilePointer(hFile,(lMainSize-(lSubSize+6)-16),0,FILE_CURRENT);
					}
					break;

				case SPECIAL_OBJECT_MAIN:
					// first check if the object is to be searched in the SPECIAL_MAIN
					// datablock
					if((nDatablockType==NORMAL_MAIN) || (nDatablockType==ADDITIONAL_MAIN))
					{
						SetFilePointer(hFile,(lMainSize-6),0,FILE_CURRENT);
						lObjectOffsetDummy+=lMainSize;
						break;
					}
					// First save offset of object
					lObjectOffsetMain=lObjectOffsetDummy;
					lObjectOffsetDummy=lObjectOffsetMain+lMainSize;

					// if it was one of the object main buffers, the name is situated directly
					// after the main datablock. However we check if the upcoming datablock
					// is the name datablock
					nType=thisDatablock.GetShort(hFile);
					if((nType==NORMAL_OBJECT_OR_SECTOR_NAME) || (nType==SPECIAL_OBJECT_NAME))
					{
					
						lSubSize=thisDatablock.GetLong(hFile);
						lSubSize-=6;	// to get effective size
						ReadFile(hFile,szObjectNameDummy,lSubSize,&lBytesRead,NULL);
						if(!strcmp(szObjectNameDummy,szObjectName))
							return(lObjectOffsetMain);
						// Put file pointer to next object
						SetFilePointer(hFile,(lMainSize-(lSubSize+6)-6),0,FILE_CURRENT);
					}
					else
					{
						SetFilePointer(hFile,10,0,FILE_CURRENT);
						lSubSize=thisDatablock.GetLong(hFile);
						lSubSize-=6;	// to get effective size
						ReadFile(hFile,szObjectNameDummy,lSubSize,&lBytesRead,NULL);
						if(!strcmp(szObjectNameDummy,szObjectName))
							return(lObjectOffsetMain);
						// Put file pointer to next object
						SetFilePointer(hFile,(lMainSize-(lSubSize+6)-16),0,FILE_CURRENT);
					}
					break;

				case ADDITIONAL_OBJECT:
					// first check if the object is to be searched in the ADDITIONAL_MAIN
					// datablock
					if((nDatablockType==NORMAL_MAIN)||(nDatablockType==SPECIAL_MAIN))
					{
						SetFilePointer(hFile,(lMainSize-6),0,FILE_CURRENT);
						lObjectOffsetDummy+=lMainSize;
						break;
					}
					// First save offset of object
					lObjectOffsetMain=lObjectOffsetDummy;
					lObjectOffsetDummy=lObjectOffsetMain+lMainSize;
					
					SetFilePointer(hFile,1,0,FILE_CURRENT);
					lSubSize=thisDatablock.GetLong(hFile);
					ReadFile(hFile,szObjectNameDummy,lSubSize,&lBytesRead,NULL);
					if(!myHelper.Compare(szObjectNameDummy,szObjectName,strlen(szObjectName)-1))
						return(lObjectOffsetMain);
					// Put file pointer to next object
					SetFilePointer(hFile,lMainSize-lSubSize-11,0,FILE_CURRENT);
					break;

				case NORMAL_MAIN:
				case SPECIAL_MAIN:
				case ADDITIONAL_MAIN:
					lObjectOffsetDummy+=6;
					break;

				default:
					SetFilePointer(hFile,(lMainSize-6),0,FILE_CURRENT);
					lObjectOffsetDummy+=lMainSize;
					break;
			}
		}
	}
	else
	{
		return(-1);
	}
	return(-1);
}

// Reads out all object properties
bool CScene2::ReadObject(HANDLE hFile, long lOffset, ObjectInfo_t * Scene2ObjectInfo_t, bool bUseFilter)
{
	CDatablock thisDatablock;
	short nType=DATABLOCK_UNKNOWN;
	long lSize=0,
		lDummySize=0;
	short dummy=0;
	unsigned long lBytesRead=0;
	int cur=0, i;

	Scene2ObjectInfo_t->bUseModel=false;

	SetFilePointer(hFile,(lOffset+6),0,FILE_BEGIN);

	while(1)
	{
		nType=thisDatablock.GetShort(hFile);
		if(nType==SCENE2_EOF)
			return false;

		lSize=thisDatablock.GetLong(hFile);
		switch(nType)
		{
			case NORMAL_OBJECT_MAIN:
			case SPECIAL_OBJECT_MAIN:
			case NORMAL_MAIN:
			case SPECIAL_MAIN:
//			case DATABLOCK_COMMENT:
			case UNKNOWN_DATABLOCK_MAIN:
				return true;

			// a normal object
			case NORMAL_OBJECT_TYPE:
			case SPECIAL_OBJECT_TYPE:
				Scene2ObjectInfo_t->lType=thisDatablock.GetLong(hFile);
				break;

			case ADDITIONAL_OBJECT:
				SetFilePointer(hFile,1,0,FILE_CURRENT);
				lDummySize=thisDatablock.GetLong(hFile);
				ReadFile(hFile,Scene2ObjectInfo_t->sName,lDummySize,&lBytesRead,NULL);
				break;

			case NORMAL_OBJECT_OR_SECTOR_NAME:
			case SPECIAL_OBJECT_NAME:
				lSize-=6;
				ReadFile(hFile,Scene2ObjectInfo_t->sName,lSize,&lBytesRead,NULL);
				break;

			case NORMAL_OBJECT_POS:
				for(i=0;i<3;i++)
					Scene2ObjectInfo_t->fPos[i]=thisDatablock.GetFloat(hFile);
				break;

			case NORMAL_OBJECT_ROT:
				for(i=0;i<4;i++)
					Scene2ObjectInfo_t->fRot[i]=thisDatablock.GetFloat(hFile);
				break;

			case NORMAL_OBJECT_DIMENSION:
				for(i=0;i<3;i++)
					Scene2ObjectInfo_t->fSize[i]=thisDatablock.GetFloat(hFile);
				break;

			case NORMAL_OBJECT_ADDTRANSLATION:
				for(i=0;i<3;i++)
					Scene2ObjectInfo_t->fAddTrans[i]=thisDatablock.GetFloat(hFile);
				break;

			case NORMAL_OBJECT_SECTOR:
				SetFilePointer(hFile,2,0,FILE_CURRENT);
				lSize=thisDatablock.GetLong(hFile);
				lSize-=6;
				ReadFile(hFile,Scene2ObjectInfo_t->sSectorName,lSize,&lBytesRead,NULL);
				break;

			case NORMAL_OBJECT_MODEL:
				Scene2ObjectInfo_t->bUseModel=true;
				lSize-=6;
				ReadFile(hFile,Scene2ObjectInfo_t->sModelName,lSize,&lBytesRead,NULL);
				break;

			case NORMAL_SECTOR_MAIN:
				Scene2ObjectInfo_t->lType=NORMAL_OBJECT_TYPE_SECTOR;
				// in sectors we read all data directly till we come to a new object to avoid problems
//				SetFilePointer(hFile,(lSize-6),0,FILE_CURRENT);	// we still need it as long as there's no code here
				// read out sector data
				while(1)
				{
					nType=thisDatablock.GetShort(hFile);
					if((nType==SCENE2_EOF)||
						(nType==NORMAL_OBJECT_MAIN)||
						(nType==SPECIAL_OBJECT_MAIN)||
						(nType==NORMAL_MAIN)||
						(nType==SPECIAL_MAIN)||
						(nType==UNKNOWN_DATABLOCK_MAIN))
					{
						SetFilePointer(hFile,-2,0,FILE_CURRENT);
						break;
					}

					lSize=thisDatablock.GetLong(hFile);

					switch(nType)
					{
						case NORMAL_SECTOR_UNK_1:
							Scene2ObjectInfo_t->fSectorVal1=thisDatablock.GetFloat(hFile);
							break;
						case NORMAL_SECTOR_UNK_2:
							Scene2ObjectInfo_t->fSectorVal2=thisDatablock.GetFloat(hFile);
							break;
						case DATABLOCK_COMMENT:
							Scene2ObjectInfo_t->fSectorVal3=thisDatablock.GetFloat(hFile);
							break;
						case NORMAL_SECTOR_UNK_3:
							Scene2ObjectInfo_t->fSectorVal4=thisDatablock.GetFloat(hFile);
							break;
						case NORMAL_SECTOR_UNK_4:
							Scene2ObjectInfo_t->lSectorVal5=thisDatablock.GetLong(hFile);
							break;
						case NORMAL_SECTOR_UNK_5:
							Scene2ObjectInfo_t->fSectorVal6=thisDatablock.GetFloat(hFile);
							break;
						case NORMAL_SECTOR_UNK_6:
							Scene2ObjectInfo_t->lSectorVal7=thisDatablock.GetLong(hFile);
							break;
						case NORMAL_SECTOR_UNK_7:
							Scene2ObjectInfo_t->fSectorVal8=thisDatablock.GetFloat(hFile);
							break;
						case NORMAL_SECTOR_UNK_8:
							Scene2ObjectInfo_t->lSectorVal9=thisDatablock.GetLong(hFile);
							break;
						case NORMAL_SECTOR_UNK_9:
							Scene2ObjectInfo_t->fSectorVal10=thisDatablock.GetFloat(hFile);
							break;
						case NORMAL_SECTOR_UNK_10:
							Scene2ObjectInfo_t->fSectorVal11=thisDatablock.GetFloat(hFile);
							break;
						case NORMAL_SECTOR_UNK_11:
							Scene2ObjectInfo_t->lSectorVal12=thisDatablock.GetLong(hFile);
							break;
						case NORMAL_SECTOR_UNK_12:
							Scene2ObjectInfo_t->lSectorVal13=thisDatablock.GetLong(hFile);
							break;
						case NORMAL_SECTOR_UNK_13:
							Scene2ObjectInfo_t->lSectorVal14=thisDatablock.GetLong(hFile);
							break;
						case NORMAL_SECTOR_UNK_14:
							Scene2ObjectInfo_t->lSectorVal15=thisDatablock.GetLong(hFile);
							break;
						case NORMAL_SECTOR_UNK_15:
							Scene2ObjectInfo_t->fSectorVal16=thisDatablock.GetFloat(hFile);
							break;
						case NORMAL_OBJECT_OR_SECTOR_NAME:
							Scene2ObjectInfo_t->lSectorVal17=thisDatablock.GetLong(hFile);
							break;
						case NORMAL_SECTOR_UNK_17:
							Scene2ObjectInfo_t->fSectorVal18=thisDatablock.GetFloat(hFile);
							break;
						case NORMAL_SECTOR_UNK_18:
							Scene2ObjectInfo_t->fSectorVal19=thisDatablock.GetFloat(hFile);
							break;
						case NORMAL_SECTOR_UNK_19:
							Scene2ObjectInfo_t->lSectorVal20=thisDatablock.GetLong(hFile);
							break;
						case NORMAL_SECTOR_UNK_20:
							for(i=0;i<3;i++)
								Scene2ObjectInfo_t->lSectorVal21[i]=thisDatablock.GetLong(hFile);
							break;
						case NORMAL_SECTOR_UNK_21:
							for(i=0;i<3;i++)
								Scene2ObjectInfo_t->lSectorVal22[i]=thisDatablock.GetLong(hFile);
							break;
					}
				}
				break;

			case NORMAL_LIGHTMAP_DATA:
				Scene2ObjectInfo_t->lType=NORMAL_OBJECT_TYPE_LIGHTMAP;
				SetFilePointer(hFile,(lSize-6),0,FILE_CURRENT);
				break;

			case NORMAL_LIGHTNING_MAIN:
				// do nothing :p
				break;

			case NORMAL_LIGHTNING_TYPE:
				Scene2ObjectInfo_t->lLightType=thisDatablock.GetLong(hFile);
				break;

			case NORMAL_LIGHTNING_COLOR:
				Scene2ObjectInfo_t->fRed=thisDatablock.GetFloat(hFile);
				Scene2ObjectInfo_t->fGreen=thisDatablock.GetFloat(hFile);
				Scene2ObjectInfo_t->fBlue=thisDatablock.GetFloat(hFile);
				break;

			case NORMAL_LIGHTNING_POWER:
				Scene2ObjectInfo_t->fPower=thisDatablock.GetFloat(hFile);
				break;

			case NORMAL_LIGHTNING_UNK_1:
				Scene2ObjectInfo_t->fLightUnk1=thisDatablock.GetFloat(hFile);
				Scene2ObjectInfo_t->fLightUnk2=thisDatablock.GetFloat(hFile);
				break;

			case NORMAL_LIGHTNING_RANGE:
				Scene2ObjectInfo_t->fLightNear=thisDatablock.GetFloat(hFile);
				Scene2ObjectInfo_t->fLightFar=thisDatablock.GetFloat(hFile);
				break;

			case NORMAL_LIGHTNING_FLAGS:
				Scene2ObjectInfo_t->lLightFlags=thisDatablock.GetLong(hFile);
				break;

			case NORMAL_LIGHTNING_SECTOR:
				lSize-=6;
				ReadFile(hFile,&Scene2ObjectInfo_t->sLightSectors[cur],lSize,&lBytesRead,NULL);
				cur+=lSize;
//				Scene2ObjectInfo_t->sLightSectors[cur]=';';
//				cur++;
				break;

			case NORMAL_OBJECT_TYPE_06_DATA:
				for(i=0;i<6;i++)
					Scene2ObjectInfo_t->fVal[i]=thisDatablock.GetFloat(hFile);
				break;

			case SPECIAL_OBJECT_DATA:
				if(bUseFilter==true)
				{
					SetFilePointer(hFile,(lSize-6),0,FILE_CURRENT);
					break;
				}
				// ok, now we have to differenciate
				switch(Scene2ObjectInfo_t->lType)
				{
					case SPECIAL_OBJECT_TYPE_SHOOTABLE:
						SetFilePointer(hFile,2,0,FILE_CURRENT);
						Scene2ObjectInfo_t->fMovVal1=thisDatablock.GetFloat(hFile);
						Scene2ObjectInfo_t->fMovVal2=thisDatablock.GetFloat(hFile);
						Scene2ObjectInfo_t->fWeight=thisDatablock.GetFloat(hFile);
						Scene2ObjectInfo_t->fMovVal3=thisDatablock.GetFloat(hFile);
						Scene2ObjectInfo_t->fMovVal4=thisDatablock.GetFloat(hFile);
						Scene2ObjectInfo_t->lSound=thisDatablock.GetLong(hFile);
						SetFilePointer(hFile,1,0,FILE_CURRENT);
						Scene2ObjectInfo_t->lMovVal5=thisDatablock.GetLong(hFile);
						break;

					case SPECIAL_OBJECT_TYPE_TRAFFIC:
						SetFilePointer(hFile,4,0,FILE_CURRENT);
						for(i=0;i<3;i++)
							Scene2ObjectInfo_t->fTrafficVal[i]=thisDatablock.GetFloat(hFile);
						Scene2ObjectInfo_t->lDensity=thisDatablock.GetLong(hFile);
						Scene2ObjectInfo_t->lNumOfCars=thisDatablock.GetLong(hFile);
						// ignore upcoming stuff <-- Ignore this
//						SetFilePointer(hFile,(lSize-(6+(strlen(Scene2ObjectInfo_t->sName)+7)+40),0,FILE_CURRENT);
						// read out cars
						for(i=0;i<Scene2ObjectInfo_t->lNumOfCars;i++)
						{
							lSize=myHelper.ReadTillNull(hFile,Scene2ObjectInfo_t->sCarname[i])+1;
							SetFilePointer(hFile,(20-lSize),0,FILE_CURRENT);
							Scene2ObjectInfo_t->fDensity[i]=thisDatablock.GetFloat(hFile);
							Scene2ObjectInfo_t->lColor[i]=thisDatablock.GetLong(hFile);
							Scene2ObjectInfo_t->bPolice[i]=thisDatablock.GetByte(hFile);
							Scene2ObjectInfo_t->bFlag2[i]=thisDatablock.GetByte(hFile);
							Scene2ObjectInfo_t->bGangster[i]=thisDatablock.GetByte(hFile);
							Scene2ObjectInfo_t->bFlag4[i]=thisDatablock.GetByte(hFile);
							Scene2ObjectInfo_t->bDel[i]=false;
						}
						break;

					case SPECIAL_OBJECT_TYPE_CHARACTER:
					case SPECIAL_OBJECT_TYPE_PLAYER:
						SetFilePointer(hFile,1,0,FILE_CURRENT);
						Scene2ObjectInfo_t->cBehaviour=thisDatablock.GetByte(hFile);
						SetFilePointer(hFile,3,0,FILE_CURRENT);
						Scene2ObjectInfo_t->cVoice=thisDatablock.GetByte(hFile);
						SetFilePointer(hFile,3,0,FILE_CURRENT);
						Scene2ObjectInfo_t->fStrenght=thisDatablock.GetFloat(hFile);
						Scene2ObjectInfo_t->fEnergy=thisDatablock.GetFloat(hFile);
						Scene2ObjectInfo_t->fEnergy_HANDL=thisDatablock.GetFloat(hFile);
						Scene2ObjectInfo_t->fEnergy_HANDR=thisDatablock.GetFloat(hFile);
						Scene2ObjectInfo_t->fEnergy_LEGL=thisDatablock.GetFloat(hFile);
						Scene2ObjectInfo_t->fEnergy_LEGR=thisDatablock.GetFloat(hFile);
						Scene2ObjectInfo_t->fReactions=thisDatablock.GetFloat(hFile);
						Scene2ObjectInfo_t->fSpeed=thisDatablock.GetFloat(hFile);
						Scene2ObjectInfo_t->fAggr=thisDatablock.GetFloat(hFile);
						Scene2ObjectInfo_t->fInt=thisDatablock.GetFloat(hFile);
						Scene2ObjectInfo_t->fShooting=thisDatablock.GetFloat(hFile);
						Scene2ObjectInfo_t->fSight=thisDatablock.GetFloat(hFile);
						Scene2ObjectInfo_t->fHearing=thisDatablock.GetFloat(hFile);
						Scene2ObjectInfo_t->fDriving=thisDatablock.GetFloat(hFile);
						Scene2ObjectInfo_t->fMass=thisDatablock.GetFloat(hFile);
						Scene2ObjectInfo_t->fBehaviour=thisDatablock.GetFloat(hFile);

						dummy=thisDatablock.GetShort(hFile);
						if(dummy==0x0101)
						{
							SetFilePointer(hFile,6,0,FILE_CURRENT);
							lSize=thisDatablock.GetLong(hFile);
							SetFilePointer(hFile,(lSize+1),0,FILE_CURRENT);
						}
						else
							SetFilePointer(hFile,-2,0,FILE_CURRENT);
						break;

					default:
						SetFilePointer(hFile,(lSize-6),0,FILE_CURRENT);
						break;
				}
				break;

			default:
				SetFilePointer(hFile,(lSize-6),0,FILE_CURRENT);
				break;
		}
	}
	return true;
}

// Deletes an object
int CScene2::DeleteObject(HANDLE hFile, char * szObjectName, short nDatablockType)
{
	CDatablock thisDatablock;
	CHelper myHelper;
	unsigned long lBytesRead=0, lBytesWritten=0;
	long lObjectOffset=0,			// offset of the main datablock of the object to delete
		lNormalMainOffset=0,		// offset of NORMAL_MAIN
		lSpecialMainOffset=0,		// offset of SPECIAL_MAIN
		lAdditionalMainOffset=0,	// offset of ADDITIONAL_MAIN
		lObjDelSize=0,				// size of the datablock of the object to delete
		lMainSize=0,
		lDummyOffset=0;				// used for BufferDataFM

	// At first get some basic values
	lNormalMainOffset=thisDatablock.FindDatablock(hFile,NORMAL_MAIN);
	lSpecialMainOffset=thisDatablock.FindDatablock(hFile,SPECIAL_MAIN);
	lAdditionalMainOffset=thisDatablock.FindDatablock(hFile,ADDITIONAL_MAIN);

	lDummyOffset=lObjectOffset=FindObject(hFile,szObjectName,nDatablockType);
	if(lObjectOffset==-1)
		return(-1);

	// Set file pointer to datablock size
	SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);

	lObjDelSize=thisDatablock.GetLong(hFile);

	lDummyOffset+=lObjDelSize;

	SetFilePointer(hFile,(lObjDelSize-6),0,FILE_CURRENT);
//	myHelper.BufferData(hFile,"buffer.tmp",-1);
	myHelper.BufferDataFM(hFile,"buffer.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);
	SetFilePointer(hFile,-(lObjDelSize),0,FILE_CURRENT);
	myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

	SetEndOfFile(hFile);

	// Now change important sizes
	if((lObjectOffset>lNormalMainOffset)&&(lObjectOffset<lSpecialMainOffset))
	{
		SetFilePointer(hFile,lNormalMainOffset+2,0,FILE_BEGIN);
		lMainSize=thisDatablock.GetLong(hFile);
		lMainSize-=lObjDelSize;
		SetFilePointer(hFile,lNormalMainOffset+2,0,FILE_BEGIN);
		WriteFile(hFile,(char *)&lMainSize,sizeof(lMainSize),&lBytesWritten,NULL);
	}
	else
	if((lObjectOffset>lSpecialMainOffset)&&(lObjectOffset<lAdditionalMainOffset))
	{
		SetFilePointer(hFile,lSpecialMainOffset+2,0,FILE_BEGIN);
		lMainSize=thisDatablock.GetLong(hFile);
		lMainSize-=lObjDelSize;
		SetFilePointer(hFile,lSpecialMainOffset+2,0,FILE_BEGIN);
		WriteFile(hFile,(char *)&lMainSize,sizeof(lMainSize),&lBytesWritten,NULL);
	}
	else
	if(lObjectOffset>lAdditionalMainOffset)
	{
		SetFilePointer(hFile,lAdditionalMainOffset+2,0,FILE_BEGIN);
		lMainSize=thisDatablock.GetLong(hFile);
		lMainSize-=lObjDelSize;
		SetFilePointer(hFile,lAdditionalMainOffset+2,0,FILE_BEGIN);
		WriteFile(hFile,(char *)&lMainSize,sizeof(lMainSize),&lBytesWritten,NULL);
	}

	SetFilePointer(hFile,2,0,FILE_BEGIN);
	lMainSize=thisDatablock.GetLong(hFile);
	lMainSize-=lObjDelSize;
	SetFilePointer(hFile,2,0,FILE_BEGIN);
	WriteFile(hFile,(char *)&lMainSize,sizeof(lMainSize),&lBytesWritten,NULL);
	return 0;
}

// Exports an object
long CScene2::ExportObject(HANDLE hFile, char * szFileName, char * szObjectName, short nDatablockType)
{
	CDatablock thisDatablock;
	CHelper thisHelper;

	long lObjectOffset=0,
		lObjDatablockSize=0,
		lDummyOffset=0;

	lDummyOffset=lObjectOffset=FindObject(hFile,szObjectName,nDatablockType);
	if(lObjectOffset==-1)
		return(-1);

	SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
	lObjDatablockSize=thisDatablock.GetLong(hFile);
	SetFilePointer(hFile,-6,0,FILE_CURRENT);
	myHelper.BufferDataFM(hFile,szFileName,lDummyOffset,lObjDatablockSize);
	return 0;
//	return(myHelper.BufferData(hFile,szFileName,(lObjDatablockSize)));
}

// Imports an object
long CScene2::ImportObject(HANDLE hFile, char * szFileName)
{
	CDatablock thisDatablock;
	CHelper thisHelper;
	short nDatablockType=DATABLOCK_UNKNOWN;
	long lObjDatablockSize=0,		// size of datablock of object to add
		lNormalMainOffset=0,		// offset of NORMAL_MAIN
		lNormalMainSize=0,			// size of NORMAL_MAIN
		lSpecialMainOffset=0,		// offset of SPECIAL_MAIN
		lSpecialMainSize=0,			// size of SPECIAL_MAIN
		lAddMainOffset=0,			// offset of ADDITIONAL_MAIN
		lAddMainSize=0,				// size ADDITIONAL_MAIN
		lScene2MainSize=0,			// size of SCENE2_MAIN
		lDummyOffset=0;				// used for BufferDataFM
	unsigned long lBytesWritten=0;
	HANDLE hDummy=CreateFile(szFileName,GENERIC_WRITE|GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN,NULL);
	if(hDummy==INVALID_HANDLE_VALUE)
		return(-1);

	nDatablockType=thisDatablock.GetShort(hDummy);
	lObjDatablockSize=thisDatablock.GetLong(hDummy);
	// Ok, we can close the file
	CloseHandle(hDummy);

	switch(nDatablockType)
	{
		case NORMAL_OBJECT_MAIN:
			// Find NORMAL_MAIN
			lDummyOffset=lNormalMainOffset=thisDatablock.FindDatablock(hFile,NORMAL_MAIN);
			// Go to end of NORMAL_MAIN
			SetFilePointer(hFile,(lNormalMainOffset+2),0,FILE_BEGIN);
			lNormalMainSize=thisDatablock.GetLong(hFile);
			lDummyOffset+=lNormalMainSize;
			SetFilePointer(hFile,(lNormalMainSize-6),0,FILE_CURRENT);
			// Buffer all data
//			myHelper.BufferData(hFile,"buffer.tmp",-1);
			myHelper.BufferDataFM(hFile,"buffer.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);
			// Paste object
			myHelper.PasteBufferedDataFM(hFile,szFileName,false);
			// Paste other data
			myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

			SetEndOfFile(hFile);

			// Now change size of NORMAL_MAIN
			lNormalMainSize+=lObjDatablockSize;
			SetFilePointer(hFile,(lNormalMainOffset+2),0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lNormalMainSize,sizeof(lNormalMainSize),&lBytesWritten,NULL);
			break;

		case SPECIAL_OBJECT_MAIN:
			// Find SPECIAL_MAIN
			lDummyOffset=lSpecialMainOffset=thisDatablock.FindDatablock(hFile,SPECIAL_MAIN);
			// Go to end of SPECIAL_MAIN
			SetFilePointer(hFile,(lSpecialMainOffset+2),0,FILE_BEGIN);
			lSpecialMainSize=thisDatablock.GetLong(hFile);
			lDummyOffset+=lSpecialMainSize;
			SetFilePointer(hFile,(lSpecialMainSize-6),0,FILE_CURRENT);
			// Buffer all data
//			myHelper.BufferData(hFile,"buffer.tmp",-1);
			myHelper.BufferDataFM(hFile,"buffer.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);
			// Paste object
			myHelper.PasteBufferedDataFM(hFile,szFileName,false);
			// Paste other data
			myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

			SetEndOfFile(hFile);

			// Now change size of SPECIAL_MAIN
			lSpecialMainSize+=lObjDatablockSize;
			SetFilePointer(hFile,(lSpecialMainOffset+2),0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lSpecialMainSize,sizeof(lSpecialMainSize),&lBytesWritten,NULL);
			break;

		case ADDITIONAL_OBJECT:
			// Find ADDITIONAL_MAIN
			lDummyOffset=lAddMainOffset=thisDatablock.FindDatablock(hFile,ADDITIONAL_MAIN);
			// Go to end of ADDITIONAL_MAIN
			SetFilePointer(hFile,(lAddMainOffset+2),0,FILE_BEGIN);
			lAddMainSize=thisDatablock.GetLong(hFile);
			lDummyOffset+=lAddMainSize;
			SetFilePointer(hFile,(lAddMainSize-6),0,FILE_CURRENT);
			// Buffer all data
//			myHelper.BufferData(hFile,"buffer.tmp",-1);
			myHelper.BufferDataFM(hFile,"buffer.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);
			// Paste object
			myHelper.PasteBufferedDataFM(hFile,szFileName,false);
			// Paste other data
			myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

			SetEndOfFile(hFile);

			// Now change size of ADDITIONAL_MAIN
			lAddMainSize+=lObjDatablockSize;
			SetFilePointer(hFile,(lAddMainOffset+2),0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lAddMainSize,sizeof(lAddMainSize),&lBytesWritten,NULL);
			break;

		default:
			// if MFC
			// AfxMessageBox("CScene2::ImportObject(): MPE file does not contain a valid object",MB_OK|MB_ICONWARNING);
			// if not MFC
			MessageBox(NULL,"CScene2::ImportObject(): MPE file does not contain a valid object","Muped",MB_OK|MB_ICONWARNING);
			break;
	}

	// At the end change size of SCENE2_MAIN
	SetFilePointer(hFile,2,0,FILE_BEGIN);
	lScene2MainSize=thisDatablock.GetLong(hFile);
	lScene2MainSize+=lObjDatablockSize;
	SetFilePointer(hFile,2,0,FILE_BEGIN);
	WriteFile(hFile,(char *)&lScene2MainSize,sizeof(lScene2MainSize),&lBytesWritten,NULL);
	return 1;
}

/*
// Used to find the script section of a special object
long CScene2::FindScript(HANDLE hFile, char * szObjectName)
{
	CHelper myHelper;
	long lObjectOffset=FindObject(hFile,szObjectName,SPECIAL_MAIN),
		lObjDatablockSize=0;
	char szDummy[6];
	char sig_script[6]={0x01,0x01,0x00,0x00,0x00,0x01};
	char sig_script_alt[6]={0x01,0x00,0x00,0x00,0x00,0x01};
	char sig_char[6]={0x01,0x01,0x00,0x00,0x00,0x00};
	unsigned long lBytesRead=0;
	CDatablock thisDatablock;
	int i=6;
	
/*	DuplicateHandle(GetCurrentProcess(), hFile,
        GetCurrentProcess(), &hDummy , 0,
        FALSE,
        DUPLICATE_SAME_ACCESS);


	// ok now we know where to find the object so let's start with looking for the
	// 01 01 00 00 00 signature
	SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
	lObjDatablockSize=thisDatablock.GetLong(hFile);
	while(i!=lObjDatablockSize)
	{
		ReadFile(hFile,&szDummy,1,&lBytesRead,NULL);
		i++;
		if(szDummy[0]==1)
		{
			SetFilePointer(hFile,-1,0,FILE_CURRENT);

			ReadFile(hFile,&szDummy,6,&lBytesRead,NULL);
			// compare with first script signature
			if(!myHelper.Compare(szDummy,sig_script,6))
				return(lObjectOffset+i-1);
			// compare with second script signature
			if(!myHelper.Compare(szDummy,sig_script_alt,6))
				return(lObjectOffset+i-1);
			// compare with char script signature
			if(!myHelper.Compare(szDummy,sig_char,6))
				return(lObjectOffset+i-1);
			SetFilePointer(hFile,-5,0,FILE_CURRENT);
		}
	}
	return(-1);
}
*/

// Extracts the script of an object in SPECIAL_MAIN datablock
long CScene2::ExtractObjectScript(HANDLE hFile, char * szObjectName, short nDatablockType, char * szFileName)
{
	ObjectInfo_t Scene2ObjectInfo_t;
	CDatablock thisDatablock;
	CHelper myHelper;
	long lObjectOffset=0,		// offset of our object
		lScriptSize=0,			// the size of the script to extract
		lDummyOffset=0;			// for BufferDataFM
	unsigned long lBytesRead=0;

	if(nDatablockType==SPECIAL_MAIN)
	{
		lObjectOffset=FindObject(hFile,szObjectName,SPECIAL_MAIN);
		ReadObject(hFile,lObjectOffset,&Scene2ObjectInfo_t,true);
		if(Scene2ObjectInfo_t.lType==SPECIAL_OBJECT_TYPE_SCRIPT)
		{
			// Object is a script object so we have:
			// 01 01 00 00 00 01 00 00 00 00 <size> <script>
			lDummyOffset=lObjectOffset=FindScript(hFile,szObjectName);
			if(lObjectOffset==-1)
				// no script was found
				return(-1);
			SetFilePointer(hFile,(lObjectOffset+10),0,FILE_BEGIN);	// to get to size of script
			lDummyOffset+=14;
			lScriptSize=thisDatablock.GetLong(hFile);
			// first check if it is really a script
			if(lScriptSize==0)
				return(-1);
			// now read out lScriptSize bytes
//			myHelper.BufferData(hFile,szFileName,lScriptSize);
			myHelper.BufferDataFM(hFile,szFileName,lDummyOffset,lScriptSize);
		}
		else
		{
			// Object is a non-script object so we have:
			// 01 01 00 00 00 00 <size> <script>
			lDummyOffset=lObjectOffset=FindScript(hFile,szObjectName);
			if(lObjectOffset==-1)
				//no script found
				return(-1);
			SetFilePointer(hFile,(lObjectOffset+6),0,FILE_BEGIN);
			lDummyOffset+=10;
			lScriptSize=thisDatablock.GetLong(hFile);
//			myHelper.BufferData(hFile,szFileName,lScriptSize);
			myHelper.BufferDataFM(hFile,szFileName,lDummyOffset,lScriptSize);
		}
	}
	else
	if(nDatablockType==ADDITIONAL_MAIN)
	{
		// find additional script object
		lDummyOffset=lObjectOffset=FindObject(hFile,szObjectName,ADDITIONAL_MAIN);
		SetFilePointer(hFile,(lObjectOffset+7),0,FILE_BEGIN);
		lDummyOffset+=7;
		// Get lenght of script name
		lScriptSize=thisDatablock.GetLong(hFile);
		SetFilePointer(hFile,lScriptSize,0,FILE_CURRENT);
		lDummyOffset+=(8+lScriptSize);
		// Get size of script
		lScriptSize=thisDatablock.GetLong(hFile);
		// Buffer data
//		myHelper.BufferData(hFile,szFileName,lScriptSize);
		myHelper.BufferDataFM(hFile,szFileName,lDummyOffset,lScriptSize);
	}
	else
	{
		return(-1);
	}
	return(lScriptSize);
}

// Adds a script to an object situated in SPECIAL_MAIN
long CScene2::AddObjectScript(HANDLE hFile, char *  szObjectName, char * szFileName, short nDatablockType)
{
	ObjectInfo_t Scene2ObjectInfo_t;
	CDatablock thisDatablock;
	CHelper myHelper;

	long lObjectOffset=0,			// offset of object
		lObjDatablockSize=0,		// size of objects datablock
		lScriptOffset=0,			// offset of script of object
		lOldScriptSize=0,			// size of original script
		lNewScriptSize=0,			// size of new script
		lDatablockOffset=0,			// offsets of datablocks to change
		lDatablockSize=0,			// sizes of datablocks to change
		lDummyOffset=0;				// for BufferDataFM

	unsigned long lBytesWritten=0;

	char sSig[6]={0x01,0x01,0x00,0x00,0x00,0x00};

	// check specified datablock
	if((nDatablockType!=SPECIAL_MAIN) && (nDatablockType!=ADDITIONAL_MAIN))
		return(-1);

	if(nDatablockType==ADDITIONAL_MAIN)
	{
		lDummyOffset=lObjectOffset=FindObject(hFile,szObjectName,ADDITIONAL_MAIN);
		if(lObjectOffset==-1)
			return(-1);

		SetFilePointer(hFile,(lObjectOffset+7),0,FILE_BEGIN);
		lDummyOffset+=7;
		lObjDatablockSize=thisDatablock.GetLong(hFile);
		lDummyOffset+=(4+lObjDatablockSize);
		SetFilePointer(hFile,lObjDatablockSize,0,FILE_CURRENT);
		// get old script size
		lOldScriptSize=thisDatablock.GetLong(hFile);
		lDummyOffset+=(4+lOldScriptSize);
		// write new size
		SetFilePointer(hFile,-4,0,FILE_CURRENT);
		lNewScriptSize=myHelper.GetFileSize(szFileName);
		WriteFile(hFile,(char *)&lNewScriptSize,sizeof(lNewScriptSize),&lBytesWritten,NULL);
		// buffer upcoming data
		SetFilePointer(hFile,lOldScriptSize,0,FILE_CURRENT);
//		myHelper.BufferData(hFile,"buffer.tmp",-1);
		myHelper.BufferDataFM(hFile,"buffer.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);

		// now write new script
		SetFilePointer(hFile,(lObjectOffset+lObjDatablockSize+15),0,FILE_BEGIN);
		myHelper.PasteBufferedDataFM(hFile,szFileName,false);

		// paste other data
		myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

		SetEndOfFile(hFile);

		// now change sizes
		// 1. objects size
		SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
		lDatablockSize=thisDatablock.GetLong(hFile);
		lDatablockSize+=(lNewScriptSize-lOldScriptSize);
		SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
		WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

		// 2. ADDITIONAL_MAIN size
		lDatablockOffset=thisDatablock.FindDatablock(hFile,ADDITIONAL_MAIN);
		SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
		lDatablockSize=thisDatablock.GetLong(hFile);
		lDatablockSize+=(lNewScriptSize-lOldScriptSize);
		SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
		WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

		// 3. SCENE2_MAIN
		SetFilePointer(hFile,2,0,FILE_BEGIN);
		lDatablockSize=thisDatablock.GetLong(hFile);
		lDatablockSize+=(lNewScriptSize-lOldScriptSize);
		SetFilePointer(hFile,2,0,FILE_BEGIN);
		WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);
	}
	else
	{
		// look for object

		lDummyOffset=lObjectOffset=FindObject(hFile,szObjectName,SPECIAL_MAIN);
		if(lObjectOffset==-1)
			return(-1);

		// get lenght
		SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
		lObjDatablockSize=thisDatablock.GetLong(hFile);

		// now check if the object already got a script section
		lScriptOffset=FindScript(hFile,szObjectName);
		if(lScriptOffset==-1)
		{
			// no
			// buffer data after object (ie new 21AE)
			SetFilePointer(hFile,(lObjectOffset+lObjDatablockSize),0,FILE_BEGIN);
			lDummyOffset+=lObjDatablockSize;
//			myHelper.BufferData(hFile,"buffer.tmp",-1);
			myHelper.BufferDataFM(hFile,"buffer.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);
			// Now write script signature
			WriteFile(hFile,&sSig,6,&lBytesWritten,NULL);
			// Get Script File Size
			lNewScriptSize=myHelper.GetFileSize(szFileName);
			// Write script size
			WriteFile(hFile,(char *)&lNewScriptSize,sizeof(lNewScriptSize),&lBytesWritten,NULL);
			// Write the script
			myHelper.PasteBufferedDataFM(hFile,szFileName,false);
			// Paste other data
			myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

			SetEndOfFile(hFile);

			// ---NOW: change datablock sizes
			// 2. 24AE datablock
//			SetFilePointer(hFile,(lObjectOffset+6),0,FILE_BEGIN);
//			lDatablockOffset=thisDatablock.FindSubDatablock(hFile,SPECIAL_OBJECT_DATA,(lObjectOffset+6));
			lDatablockOffset=thisDatablock.FindObjectDatablock(hFile,SPECIAL_OBJECT_DATA,(lObjectOffset+6));
			SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
			lDatablockSize=thisDatablock.GetLong(hFile);
			lDatablockSize+=(lNewScriptSize+10);
			SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

			// 3. 21AE
			SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
			lDatablockSize=thisDatablock.GetLong(hFile);
			lDatablockSize+=(lNewScriptSize+10);
			SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

			// 4. 20AE datablock
			lDatablockOffset=thisDatablock.FindDatablock(hFile,SPECIAL_MAIN);
			SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
			lDatablockSize=thisDatablock.GetLong(hFile);
			lDatablockSize+=(lNewScriptSize+10);
			SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

			// 5. SL datablock
			SetFilePointer(hFile,2,0,FILE_BEGIN);
			lDatablockSize=thisDatablock.GetLong(hFile);
			lDatablockSize+=(lNewScriptSize+10);
			SetFilePointer(hFile,2,0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);
		}
		else
		{
			// yes
			// at first we have to determine what object type it is
			ReadObject(hFile,lObjectOffset,&Scene2ObjectInfo_t,true);
			if(Scene2ObjectInfo_t.lType==SPECIAL_OBJECT_TYPE_SCRIPT)
			{
				// Object is a script so we have:
				// 01 00/01 00 00 00 01 00 00 00 00 <size> <script>

				// First get size of previous script
				SetFilePointer(hFile,(lScriptOffset+10),0,FILE_BEGIN);
				lOldScriptSize=thisDatablock.GetLong(hFile);
				// buffer data after object (ie new 21AE)
				SetFilePointer(hFile,(lObjectOffset+lObjDatablockSize),0,FILE_BEGIN);
				lDummyOffset+=lObjDatablockSize;
//				myHelper.BufferData(hFile,"buffer.tmp",-1);
				myHelper.BufferDataFM(hFile,"buffer.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);
				// Go back to script
				SetFilePointer(hFile,(lScriptOffset+14),0,FILE_BEGIN);
				// Now write the script + save script size (lNewScriptSize)
				myHelper.PasteBufferedDataFM(hFile,szFileName,false);
				lNewScriptSize=myHelper.GetFileSize(szFileName);
				// Paste other data
				myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

				SetEndOfFile(hFile);

				// ---NOW: change datablock sizes
				// 1. Script Size
				SetFilePointer(hFile,(lScriptOffset+10),0,FILE_BEGIN);
				WriteFile(hFile,(char *)&lNewScriptSize,sizeof(lNewScriptSize),&lBytesWritten,NULL);
				// 2. 24AE datablock
//				SetFilePointer(hFile,(lObjectOffset+6),0,FILE_BEGIN);
//				lDatablockOffset=thisDatablock.FindSubDatablock(hFile,SPECIAL_OBJECT_DATA,(lObjectOffset+6));
				lDatablockOffset=thisDatablock.FindObjectDatablock(hFile,SPECIAL_OBJECT_DATA,(lObjectOffset+6));
				SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
				lDatablockSize=thisDatablock.GetLong(hFile);
				lDatablockSize+=(lNewScriptSize-lOldScriptSize);
				SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
				WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

				// 3. 21AE
				SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
				lDatablockSize=thisDatablock.GetLong(hFile);
				lDatablockSize+=(lNewScriptSize-lOldScriptSize);
				SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
				WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

				// 4. 20AE datablock
				lDatablockOffset=thisDatablock.FindDatablock(hFile,SPECIAL_MAIN);
				SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
				lDatablockSize=thisDatablock.GetLong(hFile);
				lDatablockSize+=(lNewScriptSize-lOldScriptSize);
				SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
				WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

				// 5. SL datablock
				SetFilePointer(hFile,2,0,FILE_BEGIN);
				lDatablockSize=thisDatablock.GetLong(hFile);
				lDatablockSize+=(lNewScriptSize-lOldScriptSize);
				SetFilePointer(hFile,2,0,FILE_BEGIN);
				WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);
			}
			else
			{
				// Object is NOT a script so we have:
				// 01 01 00 00 00 00 <size> <script>

				// First get size of previous script
				SetFilePointer(hFile,(lScriptOffset+6),0,FILE_BEGIN);
				lOldScriptSize=thisDatablock.GetLong(hFile);
				// buffer data after object (ie new 21AE)
				SetFilePointer(hFile,(lObjectOffset+lObjDatablockSize),0,FILE_BEGIN);
				lDummyOffset+=lObjDatablockSize;
//				myHelper.BufferData(hFile,"buffer.tmp",-1);
				myHelper.BufferDataFM(hFile,"buffer.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);
				// Go back to script
				SetFilePointer(hFile,(lScriptOffset+10),0,FILE_BEGIN);
				// Now write the script + save script size (lNewScriptSize)
				myHelper.PasteBufferedDataFM(hFile,szFileName,false);
				lNewScriptSize=myHelper.GetFileSize(szFileName);
				// Paste other data
				myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

				SetEndOfFile(hFile);

				// ---NOW: change datablock sizes
				// 1. Script Size
				SetFilePointer(hFile,(lScriptOffset+6),0,FILE_BEGIN);
				WriteFile(hFile,(char *)&lNewScriptSize,sizeof(lNewScriptSize),&lBytesWritten,NULL);
				// 2. 24AE datablock
//				SetFilePointer(hFile,(lObjectOffset+6),0,FILE_BEGIN);
//				lDatablockOffset=thisDatablock.FindSubDatablock(hFile,SPECIAL_OBJECT_DATA,(lObjectOffset+6));
				lDatablockOffset=thisDatablock.FindObjectDatablock(hFile,SPECIAL_OBJECT_DATA,(lObjectOffset+6));
				SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
				lDatablockSize=thisDatablock.GetLong(hFile);
				lDatablockSize+=(lNewScriptSize-lOldScriptSize);
				SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
				WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

				// 3. 21AE
				SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
				lDatablockSize=thisDatablock.GetLong(hFile);
				lDatablockSize+=(lNewScriptSize-lOldScriptSize);
				SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
				WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

				// 4. 20AE datablock
				lDatablockOffset=thisDatablock.FindDatablock(hFile,SPECIAL_MAIN);
				SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
				lDatablockSize=thisDatablock.GetLong(hFile);
				lDatablockSize+=(lNewScriptSize-lOldScriptSize);
				SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
				WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

				// 5. SL datablock
				SetFilePointer(hFile,2,0,FILE_BEGIN);
				lDatablockSize=thisDatablock.GetLong(hFile);
				lDatablockSize+=(lNewScriptSize-lOldScriptSize);
				SetFilePointer(hFile,2,0,FILE_BEGIN);
				WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);
			}
		}
	}
	return 0;
}

// Removes a script from an object
long CScene2::RemoveObjectScript(HANDLE hFile, char * szObjectName)
{
	ObjectInfo_t Scene2ObjectInfo_t;
	CDatablock thisDatablock;
	CHelper myHelper;
	char null[4]={0,0,0,0};

	long lObjectOffset=0,			// offset of object
		lObjDatablockSize=0,		// size of objects datablock
		lScriptOffset=0,			// offset of script of object
		lScriptSize=0,				// size of script
		lDatablockOffset=0,			// offsets of datablocks to change
		lDatablockSize=0,			// sizes of datablocks to change
		lDummyOffset=0;

	unsigned long lBytesWritten=0;

	lDummyOffset=lObjectOffset=FindObject(hFile,szObjectName,SPECIAL_MAIN);
	SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
	lObjDatablockSize=thisDatablock.GetLong(hFile);
	ReadObject(hFile,lObjectOffset,&Scene2ObjectInfo_t,true);
	if(Scene2ObjectInfo_t.lType==SPECIAL_OBJECT_TYPE_SCRIPT)
	{
		// Object is a script:
		// 01 00/01 00 00 00 01 00 00 00 00 <size> <script>
		lScriptOffset=FindScript(hFile,szObjectName);
		if(lScriptOffset==-1)
			return(-1);
		// Get size of script
		SetFilePointer(hFile,(lScriptOffset+10),0,FILE_BEGIN);
		lScriptSize=thisDatablock.GetLong(hFile);
		// ZERO it
		SetFilePointer(hFile,(lScriptOffset+10),0,FILE_BEGIN);
		WriteFile(hFile,null,4,&lBytesWritten,NULL);

		// Got to end of object
		SetFilePointer(hFile,(lObjectOffset+lObjDatablockSize),0,FILE_BEGIN);
		lDummyOffset+=lObjDatablockSize;
		// Buffer all data
//		myHelper.BufferData(hFile,"buffer.tmp",-1);
		myHelper.BufferDataFM(hFile,"buffer.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);
		// paste data
		SetFilePointer(hFile,(lScriptOffset+14),0,FILE_BEGIN);
		myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

		SetEndOfFile(hFile);

		// NOW: change sizes
		// 1. 24AE
//		lDatablockOffset=thisDatablock.FindSubDatablock(hFile,SPECIAL_OBJECT_DATA,(lObjectOffset+6));
		lDatablockOffset=thisDatablock.FindObjectDatablock(hFile,SPECIAL_OBJECT_DATA,(lObjectOffset+6));
		SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
		lDatablockSize=thisDatablock.GetLong(hFile);
		lDatablockSize-=lScriptSize;
		SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
		WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

		// 2. 21AE
		SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
		lDatablockSize=thisDatablock.GetLong(hFile);
		lDatablockSize-=lScriptSize;
		SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
		WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

		// 3. 20AE datablock
		lDatablockOffset=thisDatablock.FindDatablock(hFile,SPECIAL_MAIN);
		SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
		lDatablockSize=thisDatablock.GetLong(hFile);
		lDatablockSize-=lScriptSize;
		SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
		WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

		// 4. SL datablock
		SetFilePointer(hFile,2,0,FILE_BEGIN);
		lDatablockSize=thisDatablock.GetLong(hFile);
		lDatablockSize-=lScriptSize;
		SetFilePointer(hFile,2,0,FILE_BEGIN);
		WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

	}
	else
	{
		// Object is NOT a script:
		// 01 01 00 00 00 00 <size> <script>
		lScriptOffset=FindScript(hFile,szObjectName);
		if(lScriptOffset==-1)
			return(-1);
		// Get size of script
		SetFilePointer(hFile,(lScriptOffset+6),0,FILE_BEGIN);
		lScriptSize=thisDatablock.GetLong(hFile);

		// Got to end of object
		SetFilePointer(hFile,(lObjectOffset+lObjDatablockSize),0,FILE_BEGIN);
		lDummyOffset+=lObjDatablockSize;
		// Buffer all data
//		myHelper.BufferData(hFile,"buffer.tmp",-1);
		myHelper.BufferDataFM(hFile,"buffer.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);
		// paste data
		SetFilePointer(hFile,lScriptOffset,0,FILE_BEGIN);
		myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

		SetEndOfFile(hFile);

		// NOW: change sizes
		// 1. 24AE
//		lDatablockOffset=thisDatablock.FindSubDatablock(hFile,SPECIAL_OBJECT_DATA,(lObjectOffset+6));
		lDatablockOffset=thisDatablock.FindObjectDatablock(hFile,SPECIAL_OBJECT_DATA,(lObjectOffset+6));
		SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
		lDatablockSize=thisDatablock.GetLong(hFile);
		lDatablockSize-=(lScriptSize+10);
		SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
		WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

		// 2. 21AE
		SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
		lDatablockSize=thisDatablock.GetLong(hFile);
		lDatablockSize-=(lScriptSize+10);
		SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
		WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

		// 3. 20AE datablock
		lDatablockOffset=thisDatablock.FindDatablock(hFile,SPECIAL_MAIN);
		SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
		lDatablockSize=thisDatablock.GetLong(hFile);
		lDatablockSize-=(lScriptSize+10);
		SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
		WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

		// 4. SL datablock
		SetFilePointer(hFile,2,0,FILE_BEGIN);
		lDatablockSize=thisDatablock.GetLong(hFile);
		lDatablockSize-=(lScriptSize+10);
		SetFilePointer(hFile,2,0,FILE_BEGIN);
		WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);
	}
	return 0;
}

// Edits name of object szObjectName
long CScene2::EditObjectName(HANDLE hFile, char * szOldObjectName, char * szObjectName, short nDatablockType)
{
	CDatablock thisDatablock;
	CHelper myHelper;

	unsigned long lBytesWritten=0;
	long lObjectOffset=0,
		lNameDatablockOffset=0,
		lNameDatablockSize=0,
		lOldNameDatablockSize=0,
		lDatablockOffset=0,
		lDatablockSize=0,
		lDummyOffset=0;


	// Check if a proper datablock has been specified
	if((nDatablockType!=SPECIAL_MAIN) && (nDatablockType!=NORMAL_MAIN) && (nDatablockType!=ADDITIONAL_MAIN))
		return(-1);

	lDummyOffset=lObjectOffset=FindObject(hFile,szOldObjectName,nDatablockType);
	if(lObjectOffset==-1)
		return(-1);

	// additional object?
	if(nDatablockType==ADDITIONAL_MAIN)
	{
		// yes, we have to follow some other steps
		// get size of name
		SetFilePointer(hFile,(lObjectOffset+7),0,FILE_BEGIN);
		lDummyOffset+=11;
		lOldNameDatablockSize=thisDatablock.GetLong(hFile);
		// Write new size
		SetFilePointer(hFile,-4,0,FILE_CURRENT);
		lNameDatablockSize=strlen(szObjectName);
		WriteFile(hFile,(char *)&lNameDatablockSize,sizeof(lNameDatablockSize),&lBytesWritten,NULL);
		// Go to end of name
		SetFilePointer(hFile,lOldNameDatablockSize,0,FILE_CURRENT);
		lDummyOffset+=lOldNameDatablockSize;
		// Buffer the data
//		myHelper.BufferData(hFile,"buffer.tmp",-1);
		myHelper.BufferDataFM(hFile,"buffer.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);
		// go back to name and write it
		SetFilePointer(hFile,(lObjectOffset+11),0,FILE_BEGIN);
		WriteFile(hFile,szObjectName,strlen(szObjectName),&lBytesWritten,NULL);
		// paste other data
		myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

		SetEndOfFile(hFile);

		// now change sizes
		// 1. object size
		SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
		lDatablockSize=thisDatablock.GetLong(hFile);
		lDatablockSize+=(lNameDatablockSize-lOldNameDatablockSize);
		SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
		WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

		// 2. ADDITIONAL_MAIN size
		lDatablockOffset=thisDatablock.FindDatablock(hFile,ADDITIONAL_MAIN);
		SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
		lDatablockSize=thisDatablock.GetLong(hFile);
		lDatablockSize+=(lNameDatablockSize-lOldNameDatablockSize);
		SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
		WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);
	}
	else
	{
		if(nDatablockType==SPECIAL_MAIN)
//			lDummyOffset=lNameDatablockOffset=thisDatablock.FindSubDatablock(hFile,SPECIAL_OBJECT_NAME,(lObjectOffset+6));
			lDummyOffset=lNameDatablockOffset=thisDatablock.FindObjectDatablock(hFile,SPECIAL_OBJECT_NAME,(lObjectOffset+6));
		else
//			lDummyOffset=lNameDatablockOffset=thisDatablock.FindSubDatablock(hFile,NORMAL_OBJECT_OR_SECTOR_NAME,(lObjectOffset+6));
			lDummyOffset=lNameDatablockOffset=thisDatablock.FindObjectDatablock(hFile,NORMAL_OBJECT_OR_SECTOR_NAME,(lObjectOffset+6));

		SetFilePointer(hFile,(lNameDatablockOffset+2),0,FILE_BEGIN);

		lOldNameDatablockSize=thisDatablock.GetLong(hFile);

		// go to end of name datablock and buffer everything
		SetFilePointer(hFile,(lOldNameDatablockSize-6),0,FILE_CURRENT);
		lDummyOffset+=lOldNameDatablockSize;
//		myHelper.BufferData(hFile,"buffer3.tmp",-1);
		myHelper.BufferDataFM(hFile,"buffer3.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);

		// go back to name datablock,edit size and replace my name
		SetFilePointer(hFile,(lNameDatablockOffset+2),0,FILE_BEGIN);
		lNameDatablockSize=strlen(szObjectName)+7;
		WriteFile(hFile,(char *)&lNameDatablockSize,sizeof(lNameDatablockSize),&lBytesWritten,NULL);
		WriteFile(hFile,szObjectName,strlen(szObjectName)+1,&lBytesWritten,NULL);

		// paste other data
		myHelper.PasteBufferedDataFM(hFile,"buffer3.tmp",true);

		SetEndOfFile(hFile);

		// change sizes
		// 1. XXXXX_OBJECT_MAIN

		SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
		lDatablockSize=thisDatablock.GetLong(hFile);
		lDatablockSize+=((strlen(szObjectName)+1)-(lOldNameDatablockSize-6));
		SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
		WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

		// 2. XXXXX_MAIN
		if(nDatablockType==SPECIAL_MAIN)
		{
			lDatablockOffset=thisDatablock.FindDatablock(hFile,nDatablockType);
			SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
			lDatablockSize=thisDatablock.GetLong(hFile);
			lDatablockSize+=((strlen(szObjectName)+1)-(lOldNameDatablockSize-6));
			SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);
		}
		else
		{
			lDatablockOffset=thisDatablock.FindDatablock(hFile,nDatablockType);
			SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
			lDatablockSize=thisDatablock.GetLong(hFile);
			lDatablockSize+=((strlen(szObjectName)+1)-(lOldNameDatablockSize-6));
			SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);
		}

	}
	// 3. SCENE2_MAIN

	SetFilePointer(hFile,2,0,FILE_BEGIN);
	lDatablockSize=thisDatablock.GetLong(hFile);
	if(nDatablockType==ADDITIONAL_MAIN)
		lDatablockSize+=(lNameDatablockSize-lOldNameDatablockSize);
	else
		lDatablockSize+=((strlen(szObjectName)+1)-(lOldNameDatablockSize-6));
	SetFilePointer(hFile,2,0,FILE_BEGIN);
	WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);
	return 0;
}

// Initalizes ObjectInfo_t structure with default values, recommend after every declaration of this struct
void CScene2::PrepareObjectInfo(ObjectInfo_t * Scene2ObjectInfo_t)
{
	int i;
	
	// clear sName
	for(i=0;i<256;i++)
		Scene2ObjectInfo_t->sName[i]=0;

	// clear sModelName
	for(i=0;i<256;i++)
		Scene2ObjectInfo_t->sModelName[i]=0;

	// clear sSectorName
	for(i=0;i<256;i++)
		Scene2ObjectInfo_t->sSectorName[i]=0;

	// set bUseModel to false
	Scene2ObjectInfo_t->bUseModel=false;

	// clear pos
	for(i=0;i<3;i++)
		Scene2ObjectInfo_t->fPos[i]=0;

	// clear rot
	for(i=0;i<4;i++)
		Scene2ObjectInfo_t->fRot[i]=0;

	// clear size
	for(i=0;i<3;i++)
		Scene2ObjectInfo_t->fSize[i]=0;

	// clear additional translation
	for(i=0;i<3;i++)
		Scene2ObjectInfo_t->fAddTrans[i]=0;

	// ---- Character Specific

	// clear behaviour
	Scene2ObjectInfo_t->cBehaviour=0;

	// clear voice
	Scene2ObjectInfo_t->cVoice=0;

	// clear strenght
	Scene2ObjectInfo_t->fStrenght=0;

	// clear energy
	Scene2ObjectInfo_t->fEnergy=0;

	// clear left hand energy
	Scene2ObjectInfo_t->fEnergy_HANDL=0;

	// clear right hand energy
	Scene2ObjectInfo_t->fEnergy_HANDR=0;

	// clear left leg energy
	Scene2ObjectInfo_t->fEnergy_LEGL=0;

	// clear right leg energy
	Scene2ObjectInfo_t->fEnergy_LEGR=0;

	// clear reactions
	Scene2ObjectInfo_t->fReactions=0;

	// clear speed
	Scene2ObjectInfo_t->fSpeed=0;

	// clear aggressivity
	Scene2ObjectInfo_t->fAggr=0;

	// clear intelligence
	Scene2ObjectInfo_t->fInt=0;

	// clear shooting
	Scene2ObjectInfo_t->fShooting=0;

	// clear sight
	Scene2ObjectInfo_t->fSight=0;

	// clear hearing
	Scene2ObjectInfo_t->fHearing=0;

	// clear mass
	Scene2ObjectInfo_t->fMass=0;

	// clear driving
	Scene2ObjectInfo_t->fDriving=0;

	// clear behaviour 2
	Scene2ObjectInfo_t->fBehaviour=0;

	// ---- Light Specific

	// clear lighttype
	Scene2ObjectInfo_t->lLightType=0;

	// clear red
	Scene2ObjectInfo_t->fRed=0;

	// clear green
	Scene2ObjectInfo_t->fGreen=0;

	// clear blue
	Scene2ObjectInfo_t->fBlue=0;

	// clear flags
	Scene2ObjectInfo_t->lLightFlags=0;

	// clear power
	Scene2ObjectInfo_t->fPower=0;

	// clear unk1
	Scene2ObjectInfo_t->fLightUnk1=0;

	// clear unk2
	Scene2ObjectInfo_t->fLightUnk2=0;

	// clear near
	Scene2ObjectInfo_t->fLightNear=0;

	// clear far
	Scene2ObjectInfo_t->fLightFar=0;

	// clear light sector
	for(i=0;i<1000;i++)
		Scene2ObjectInfo_t->sLightSectors[i]=0;

	// ------ Type 06 specific
	for(i=0;i<6;i++)
		Scene2ObjectInfo_t->fVal[i]=0;

	// ------ Movable Object specific
	Scene2ObjectInfo_t->fMovVal1=0;
	Scene2ObjectInfo_t->fMovVal2=0;
	Scene2ObjectInfo_t->fMovVal3=0;
	Scene2ObjectInfo_t->fMovVal4=0;
	Scene2ObjectInfo_t->lMovVal5=0;
	Scene2ObjectInfo_t->fWeight=0;
	Scene2ObjectInfo_t->lSound=0;

	// Sector Specific
	Scene2ObjectInfo_t->fSectorVal1=0;
	Scene2ObjectInfo_t->fSectorVal2=0;
	Scene2ObjectInfo_t->fSectorVal3=0;
	Scene2ObjectInfo_t->fSectorVal4=0;
	Scene2ObjectInfo_t->lSectorVal5=0;
	Scene2ObjectInfo_t->fSectorVal6=0;
	Scene2ObjectInfo_t->lSectorVal7=0;
	Scene2ObjectInfo_t->fSectorVal8=0;
	Scene2ObjectInfo_t->lSectorVal9=0;
	Scene2ObjectInfo_t->fSectorVal10=0;
	Scene2ObjectInfo_t->fSectorVal11=0;
	Scene2ObjectInfo_t->lSectorVal12=0;
	Scene2ObjectInfo_t->lSectorVal13=0;
	Scene2ObjectInfo_t->lSectorVal14=0;
	Scene2ObjectInfo_t->lSectorVal15=0;
	Scene2ObjectInfo_t->fSectorVal16=0;
	Scene2ObjectInfo_t->lSectorVal17=0;
	Scene2ObjectInfo_t->fSectorVal18=0;
	Scene2ObjectInfo_t->fSectorVal19=0;
	Scene2ObjectInfo_t->lSectorVal20=0;

	for(i=0;i<3;i++)
		Scene2ObjectInfo_t->lSectorVal21[i]=0;

	for(i=0;i<3;i++)
		Scene2ObjectInfo_t->lSectorVal22[i]=0;

	// Traffic Object (only global vars)
	for(i=0;i<3;i++)
		Scene2ObjectInfo_t->fTrafficVal[i]=0;
	Scene2ObjectInfo_t->lDensity=0;
	Scene2ObjectInfo_t->lNumOfCars=0;
}

// Retreives object names from scene2.bin
int CScene2::GetNextObject(HANDLE hFile, BasicObjectInfo_t * pBasicObjectInfo_t, Filter_t * pObjectFilter_t)
{
	CDatablock thisDatablock;
//	CString czObjectName;
	ObjectInfo_t Scene2ObjectInfo_t;
	short nType=DATABLOCK_UNKNOWN;
	long lMainSize=0, lSubSize=0, /*lObjectOffset=6,*/ lDummyOffset=0, lTempOffset=0;
	unsigned long lBytesRead=0;
	char szObjectName[256];			// 256 chars max
	int i;
	char *dummy=0;					// for strstr

	PrepareObjectInfo(&Scene2ObjectInfo_t);


	// check if no filter was set up

	if(pObjectFilter_t==NULL)
	{
		//no
		// First set file pointer to 6 bytes after file begin
//		SetFilePointer(hFile,6,0,FILE_BEGIN);

//		while(1)
//		{
			// flush name buffer
			for(i=0;i<256;i++)
				szObjectName[i]=0;

			nType=thisDatablock.GetShort(hFile);
			if(nType==SCENE2_EOF)
				return(-1);
			lMainSize=thisDatablock.GetLong(hFile);

			switch(nType)
			{
				case NORMAL_OBJECT_MAIN:
					// Get Name
					ReadObject(hFile,pBasicObjectInfo_t->lNextObjectOffset,&Scene2ObjectInfo_t,true);

					// Store name
					strcpy(pBasicObjectInfo_t->name,Scene2ObjectInfo_t.sName);
					pBasicObjectInfo_t->nDatablock=NORMAL_MAIN;
					pBasicObjectInfo_t->iObjectType=Scene2ObjectInfo_t.lType;

					// Put file pointer to next object
					pBasicObjectInfo_t->lNextObjectOffset+=lMainSize;
					SetFilePointer(hFile,pBasicObjectInfo_t->lNextObjectOffset,0,FILE_BEGIN);
					return(1);

				case SPECIAL_OBJECT_MAIN:
					// Get Name
					ReadObject(hFile,pBasicObjectInfo_t->lNextObjectOffset,&Scene2ObjectInfo_t,true);

					// Store name
					strcpy(pBasicObjectInfo_t->name,Scene2ObjectInfo_t.sName);
					pBasicObjectInfo_t->nDatablock=SPECIAL_MAIN;
					pBasicObjectInfo_t->iObjectType=Scene2ObjectInfo_t.lType;

					// Put file pointer to next object
					pBasicObjectInfo_t->lNextObjectOffset+=lMainSize;
					SetFilePointer(hFile,pBasicObjectInfo_t->lNextObjectOffset,0,FILE_BEGIN);
					return(1);

				case ADDITIONAL_OBJECT:
					SetFilePointer(hFile,1,0,FILE_CURRENT);
					lSubSize=thisDatablock.GetLong(hFile);
					ReadFile(hFile,szObjectName,lSubSize,&lBytesRead,NULL);

					// Store name
					strcpy(pBasicObjectInfo_t->name,szObjectName);
					pBasicObjectInfo_t->nDatablock=ADDITIONAL_MAIN;
					pBasicObjectInfo_t->iObjectType=ADDITIONAL_OBJECT_TYPE_SCRIPT;

					// Put to next object
					pBasicObjectInfo_t->lNextObjectOffset+=lMainSize;
					SetFilePointer(hFile,pBasicObjectInfo_t->lNextObjectOffset,0,FILE_BEGIN);
					return(1);

				case UNKNOWN_DATABLOCK_NAME:
					SetFilePointer(hFile,10,0,FILE_CURRENT);
					lSubSize=thisDatablock.GetLong(hFile);
					ReadFile(hFile,szObjectName,lSubSize,&lBytesRead,NULL);

					// Store name
					strcpy(pBasicObjectInfo_t->name,szObjectName);
					pBasicObjectInfo_t->nDatablock=UNKNOWN_DATABLOCK_MAIN;
					pBasicObjectInfo_t->iObjectType=UNKNOWN_OBJECT_TYPE_UNKNOWN;
					pBasicObjectInfo_t->lNextObjectOffset=+lMainSize;

					// Put to next object
					pBasicObjectInfo_t->lNextObjectOffset=+lMainSize;
					SetFilePointer(hFile,pBasicObjectInfo_t->lNextObjectOffset,0,FILE_BEGIN);
					return(1);

				case NORMAL_MAIN:
					lNormalMainOffset=pBasicObjectInfo_t->lNextObjectOffset;
					pBasicObjectInfo_t->lNextObjectOffset+=6;
					return(0);
				case SPECIAL_MAIN:
					lSpecialMainOffset=pBasicObjectInfo_t->lNextObjectOffset;
					pBasicObjectInfo_t->lNextObjectOffset+=6;
					return(0);

				case ADDITIONAL_MAIN:
					pBasicObjectInfo_t->lNextObjectOffset+=6;
					return(0);

				case UNKNOWN_DATABLOCK_MAIN:
					pBasicObjectInfo_t->lNextObjectOffset+=6;
					return(0);

				default:
					SetFilePointer(hFile,(lMainSize-6),0,FILE_CURRENT);
					pBasicObjectInfo_t->lNextObjectOffset+=lMainSize;
					return(0);
				}
	}

	if((pObjectFilter_t->iFilterType&FILTER_OBJECTNAME)==8)
	{
		// name filter enabled
		// First set file pointer to 6 bytes after file begin
//		SetFilePointer(hFile,6,0,FILE_BEGIN);

//		while(1)
//		{
			// flush name buffer
			for(i=0;i<256;i++)
				szObjectName[i]=0;

			// clear lType
			Scene2ObjectInfo_t.lType=-1;

			nType=thisDatablock.GetShort(hFile);
			if(nType==SCENE2_EOF)
				return(-1);

			lMainSize=thisDatablock.GetLong(hFile);

			switch(nType)
			{
				case NORMAL_OBJECT_MAIN:
					ReadObject(hFile,pBasicObjectInfo_t->lNextObjectOffset,&Scene2ObjectInfo_t,true);
					dummy=strstr(Scene2ObjectInfo_t.sName,pObjectFilter_t->szObjectName);
					if(dummy!=NULL)
					{
						strcpy(pBasicObjectInfo_t->name,Scene2ObjectInfo_t.sName);
						pBasicObjectInfo_t->nDatablock=NORMAL_MAIN;
						pBasicObjectInfo_t->iObjectType=Scene2ObjectInfo_t.lType;

						// Put file pointer to next object
						pBasicObjectInfo_t->lNextObjectOffset+=lMainSize;
						SetFilePointer(hFile,pBasicObjectInfo_t->lNextObjectOffset,0,FILE_BEGIN);
						return(1);
					}
					else
					{
						// Put file pointer to next object
						pBasicObjectInfo_t->lNextObjectOffset+=lMainSize;
						SetFilePointer(hFile,pBasicObjectInfo_t->lNextObjectOffset,0,FILE_BEGIN);
						return(0);
					}
					break;	// bull shit but who cares

				case SPECIAL_OBJECT_MAIN:
					ReadObject(hFile,pBasicObjectInfo_t->lNextObjectOffset,&Scene2ObjectInfo_t,true);
					dummy=strstr(Scene2ObjectInfo_t.sName,pObjectFilter_t->szObjectName);
					if(dummy!=NULL)
					{
						strcpy(pBasicObjectInfo_t->name,Scene2ObjectInfo_t.sName);
						pBasicObjectInfo_t->nDatablock=SPECIAL_MAIN;
						pBasicObjectInfo_t->iObjectType=Scene2ObjectInfo_t.lType;

						// Put file pointer to next object
						pBasicObjectInfo_t->lNextObjectOffset+=lMainSize;
						SetFilePointer(hFile,pBasicObjectInfo_t->lNextObjectOffset,0,FILE_BEGIN);
						return(1);
					}
					else
					{
						// Put file pointer to next object
						pBasicObjectInfo_t->lNextObjectOffset+=lMainSize;
						SetFilePointer(hFile,pBasicObjectInfo_t->lNextObjectOffset,0,FILE_BEGIN);
						return(0);
					}
					break;

				case NORMAL_MAIN:
					lNormalMainOffset=pBasicObjectInfo_t->lNextObjectOffset;
					pBasicObjectInfo_t->lNextObjectOffset+=6;
					return(0);

				case SPECIAL_MAIN:
					lSpecialMainOffset=pBasicObjectInfo_t->lNextObjectOffset;
					pBasicObjectInfo_t->lNextObjectOffset+=6;
					return(0);

				case ADDITIONAL_MAIN:
					pBasicObjectInfo_t->lNextObjectOffset+=6;
					return(0);

				case UNKNOWN_DATABLOCK_MAIN:
					pBasicObjectInfo_t->lNextObjectOffset+=6;
					return(0);

				default:
					SetFilePointer(hFile,(lMainSize-6),0,FILE_CURRENT);
					pBasicObjectInfo_t->lNextObjectOffset+=lMainSize;
					return(0);
				}
//		}
	}

	if((pObjectFilter_t->iFilterType&FILTER_SECTOR)==4)
	{
		// sector filter enabled
		// First set file pointer to 6 bytes after file begin
//		SetFilePointer(hFile,6,0,FILE_BEGIN);

//		while(1)
//		{
			// flush name buffer
			for(i=0;i<256;i++)
				szObjectName[i]=0;

			// clear lType
			Scene2ObjectInfo_t.lType=-1;

			nType=thisDatablock.GetShort(hFile);
			if(nType==SCENE2_EOF)
				return(-1);

			lMainSize=thisDatablock.GetLong(hFile);

			switch(nType)
			{
				case NORMAL_OBJECT_MAIN:
					lDummyOffset=thisDatablock.FindObjectDatablock(hFile,NORMAL_SECTOR_MAIN,(pBasicObjectInfo_t->lNextObjectOffset+6));
					if(lDummyOffset!=SCENE2_EOF)
					{
						ReadObject(hFile,pBasicObjectInfo_t->lNextObjectOffset,&Scene2ObjectInfo_t,true);
						strcpy(pBasicObjectInfo_t->name,Scene2ObjectInfo_t.sName);
						pBasicObjectInfo_t->nDatablock=NORMAL_MAIN;
						pBasicObjectInfo_t->iObjectType=Scene2ObjectInfo_t.lType;

						// Put file pointer to next object
						pBasicObjectInfo_t->lNextObjectOffset+=lMainSize;
						SetFilePointer(hFile,pBasicObjectInfo_t->lNextObjectOffset,0,FILE_BEGIN);
						return(1);
					}
					else
					{
						// Put file pointer to next object
						pBasicObjectInfo_t->lNextObjectOffset+=lMainSize;
						SetFilePointer(hFile,pBasicObjectInfo_t->lNextObjectOffset,0,FILE_BEGIN);
						return(0);
					}
					break;

				case NORMAL_MAIN:
					lNormalMainOffset=pBasicObjectInfo_t->lNextObjectOffset;
					pBasicObjectInfo_t->lNextObjectOffset+=6;
					return(0);

				case SPECIAL_MAIN:
					lSpecialMainOffset=pBasicObjectInfo_t->lNextObjectOffset;
					pBasicObjectInfo_t->lNextObjectOffset+=6;
					return(0);

				case ADDITIONAL_MAIN:
					pBasicObjectInfo_t->lNextObjectOffset+=6;
					return(0);

				case UNKNOWN_DATABLOCK_MAIN:
					pBasicObjectInfo_t->lNextObjectOffset+=6;
					return(0);

				default:
					SetFilePointer(hFile,(lMainSize-6),0,FILE_CURRENT);
					pBasicObjectInfo_t->lNextObjectOffset+=lMainSize;
					return(0);
				}
//		}
	}

	if((pObjectFilter_t->iFilterType&FILTER_LIGHTMAP)==2)
	{
		// lightmap filter enabled
		// First set file pointer to 6 bytes after file begin
//		SetFilePointer(hFile,6,0,FILE_BEGIN);

//		while(1)
//		{
			// flush name buffer
			for(i=0;i<256;i++)
				szObjectName[i]=0;

			// clear lType
			Scene2ObjectInfo_t.lType=-1;

			nType=thisDatablock.GetShort(hFile);
			if(nType==SCENE2_EOF)
				return(-1);

			lMainSize=thisDatablock.GetLong(hFile);

			switch(nType)
			{
				case NORMAL_OBJECT_MAIN:
					lDummyOffset=thisDatablock.FindObjectDatablock(hFile,NORMAL_LENSFLARE_OR_LIGHTMAP_OR_GLOW,(pBasicObjectInfo_t->lNextObjectOffset+6));
					if(lDummyOffset!=SCENE2_EOF)
					{
						ReadObject(hFile,pBasicObjectInfo_t->lNextObjectOffset,&Scene2ObjectInfo_t,true);
						strcpy(pBasicObjectInfo_t->name,Scene2ObjectInfo_t.sName);
						pBasicObjectInfo_t->nDatablock=NORMAL_MAIN;
						pBasicObjectInfo_t->iObjectType=Scene2ObjectInfo_t.lType;

						// Put file pointer to next object
						pBasicObjectInfo_t->lNextObjectOffset+=lMainSize;
						SetFilePointer(hFile,pBasicObjectInfo_t->lNextObjectOffset,0,FILE_BEGIN);
						return(1);
					}
					else
					{
						// Put file pointer to next object
						pBasicObjectInfo_t->lNextObjectOffset+=lMainSize;
						SetFilePointer(hFile,pBasicObjectInfo_t->lNextObjectOffset,0,FILE_BEGIN);
						return(0);
					}
					break;

				case NORMAL_MAIN:
					lNormalMainOffset=pBasicObjectInfo_t->lNextObjectOffset;
					pBasicObjectInfo_t->lNextObjectOffset+=6;
					return(0);

				case SPECIAL_MAIN:
					lSpecialMainOffset=pBasicObjectInfo_t->lNextObjectOffset;
					pBasicObjectInfo_t->lNextObjectOffset+=6;
					return(0);

				case ADDITIONAL_MAIN:
					pBasicObjectInfo_t->lNextObjectOffset+=6;
					return(0);

				case UNKNOWN_DATABLOCK_MAIN:
					pBasicObjectInfo_t->lNextObjectOffset+=6;
					return(0);

				default:
					SetFilePointer(hFile,(lMainSize-6),0,FILE_CURRENT);
					pBasicObjectInfo_t->lNextObjectOffset+=lMainSize;
					return(0);
				}
//		}
	}

	if((pObjectFilter_t->iFilterType&FILTER_OBJECTTYPE)==1)
	{
		// yes
		// First set file pointer to 6 bytes after file begin
//		SetFilePointer(hFile,6,0,FILE_BEGIN);

//		while(1)
//		{
			// flush name buffer
			for(i=0;i<256;i++)
				szObjectName[i]=0;

			// clear lType
			Scene2ObjectInfo_t.lType=-1;

			nType=thisDatablock.GetShort(hFile);
			if(nType==SCENE2_EOF)
				return(-1);

			lMainSize=thisDatablock.GetLong(hFile);

			switch(nType)
			{
				case NORMAL_OBJECT_MAIN:
					// first check if the object is to be searched in NORMAL_MAIN
					if((pObjectFilter_t->nDatablock==SPECIAL_MAIN) || (pObjectFilter_t->nDatablock==ADDITIONAL_MAIN))
					{
						pBasicObjectInfo_t->lNextObjectOffset+=lMainSize;
						SetFilePointer(hFile,pBasicObjectInfo_t->lNextObjectOffset,0,FILE_BEGIN);
						return(0);
					}

					// now compare the object type to the requested one (filter)
					ReadObject(hFile,pBasicObjectInfo_t->lNextObjectOffset,&Scene2ObjectInfo_t,true);
					if(pObjectFilter_t->iObjectType==-1)
						Scene2ObjectInfo_t.lType=-1;
//					SetFilePointer(hFile,(pBasicObjectInfo_t->lNextObjectOffset+6),0,FILE_BEGIN);
					if((Scene2ObjectInfo_t.lType!=pObjectFilter_t->iObjectType)&&(Scene2ObjectInfo_t.lType!=-1))
					{
						pBasicObjectInfo_t->lNextObjectOffset+=lMainSize;
						SetFilePointer(hFile,pBasicObjectInfo_t->lNextObjectOffset,0,FILE_BEGIN);
						return(0);
					}

					strcpy(pBasicObjectInfo_t->name,Scene2ObjectInfo_t.sName);
					pBasicObjectInfo_t->nDatablock=NORMAL_MAIN;
					pBasicObjectInfo_t->iObjectType=Scene2ObjectInfo_t.lType;

					// put filepointer
					pBasicObjectInfo_t->lNextObjectOffset+=lMainSize;
					SetFilePointer(hFile,pBasicObjectInfo_t->lNextObjectOffset,0,FILE_BEGIN);
					return(1);

				case SPECIAL_OBJECT_MAIN:
					// first check if the object is to be searched in SPECIAL_MAIN
					if((pObjectFilter_t->nDatablock==NORMAL_MAIN) || (pObjectFilter_t->nDatablock==ADDITIONAL_MAIN))
					{
						pBasicObjectInfo_t->lNextObjectOffset+=lMainSize;
						SetFilePointer(hFile,pBasicObjectInfo_t->lNextObjectOffset,0,FILE_BEGIN);
						return(0);
					}

					// now compare the object type to the requested one (filter)
					ReadObject(hFile,pBasicObjectInfo_t->lNextObjectOffset,&Scene2ObjectInfo_t,true);
					if(pObjectFilter_t->iObjectType==-1)
						Scene2ObjectInfo_t.lType=-1;
//					SetFilePointer(hFile,(pBasicObjectInfo_t->lNextObjectOffset+6),0,FILE_BEGIN);
					if((Scene2ObjectInfo_t.lType!=pObjectFilter_t->iObjectType)&&(Scene2ObjectInfo_t.lType!=-1))
					{
						pBasicObjectInfo_t->lNextObjectOffset+=lMainSize;
						SetFilePointer(hFile,pBasicObjectInfo_t->lNextObjectOffset,0,FILE_BEGIN);
						return(0);
					}

					strcpy(pBasicObjectInfo_t->name,Scene2ObjectInfo_t.sName);
					pBasicObjectInfo_t->nDatablock=SPECIAL_MAIN;
					pBasicObjectInfo_t->iObjectType=Scene2ObjectInfo_t.lType;

					// put filepointer
					pBasicObjectInfo_t->lNextObjectOffset+=lMainSize;
					SetFilePointer(hFile,pBasicObjectInfo_t->lNextObjectOffset,0,FILE_BEGIN);
					return(1);

				case ADDITIONAL_OBJECT:
					// first check if the object is to be searched in ADDITIONAL_MAIN
					if((pObjectFilter_t->nDatablock==NORMAL_MAIN) || (pObjectFilter_t->nDatablock==SPECIAL_MAIN))
					{
						pBasicObjectInfo_t->lNextObjectOffset+=lMainSize;
						SetFilePointer(hFile,pBasicObjectInfo_t->lNextObjectOffset,0,FILE_BEGIN);
						return(0);
					}

					SetFilePointer(hFile,1,0,FILE_CURRENT);
					lSubSize=thisDatablock.GetLong(hFile);
					ReadFile(hFile,szObjectName,lSubSize,&lBytesRead,NULL);
					
					// Store name
					strcpy(pBasicObjectInfo_t->name,szObjectName);
					pBasicObjectInfo_t->nDatablock=ADDITIONAL_MAIN;
					pBasicObjectInfo_t->iObjectType=ADDITIONAL_OBJECT_TYPE_SCRIPT;

					// Put filepointer
					pBasicObjectInfo_t->lNextObjectOffset=+lMainSize;
					SetFilePointer(hFile,pBasicObjectInfo_t->lNextObjectOffset,0,FILE_BEGIN);
					return(1);

				case NORMAL_MAIN:
					lNormalMainOffset=pBasicObjectInfo_t->lNextObjectOffset;
					pBasicObjectInfo_t->lNextObjectOffset+=6;
					return(0);

				case SPECIAL_MAIN:
					lSpecialMainOffset=pBasicObjectInfo_t->lNextObjectOffset;
					pBasicObjectInfo_t->lNextObjectOffset+=6;
					return(0);

				case ADDITIONAL_MAIN:
					pBasicObjectInfo_t->lNextObjectOffset+=6;
					return(0);

				case UNKNOWN_DATABLOCK_MAIN:
					pBasicObjectInfo_t->lNextObjectOffset+=6;
					return(0);

				default:
					SetFilePointer(hFile,(lMainSize-6),0,FILE_CURRENT);
					pBasicObjectInfo_t->lNextObjectOffset+=lMainSize;
					return(0);
				}
		}
//	*pResult = 0;

	return(-1);
}

// Reads out the copyright text in scene2.bin
bool CScene2::GetCopyrightText(HANDLE hFile, char * Buffer)
{
	CDatablock thisDatablock;
	short nDatablockType=0;
	long lSize;
	unsigned long lBytesRead=0;

	SetFilePointer(hFile,6,0,FILE_BEGIN);
	nDatablockType=thisDatablock.GetShort(hFile);
	if(nDatablockType!=DATABLOCK_COMMENT)
		return false;

	lSize=thisDatablock.GetLong(hFile);
	lSize-=10;
	SetFilePointer(hFile,4,0,FILE_CURRENT);
	ReadFile(hFile,Buffer,lSize,&lBytesRead,NULL);

	return(true);
}

// Sets the copyright
bool CScene2::SetCopyrightText(HANDLE hFile, char * Copyright)
{
	CDatablock thisDatablock;
	CHelper myHelper;

	short nDatablockType=0;
	long lOffset=6,lSize=0, lOldSize;
	unsigned long lBytesWritten=0;
	char null[2]={0,0};

	SetFilePointer(hFile,6,0,FILE_BEGIN);
	nDatablockType=thisDatablock.GetShort(hFile);
	if(nDatablockType!=DATABLOCK_COMMENT)
		return false;

	// buffer data
	lOldSize=thisDatablock.GetLong(hFile);
	lOffset+=lOldSize;
	myHelper.BufferDataFM(hFile,"buffer.tmp",lOffset,::GetFileSize(hFile,NULL)-lOffset);

	// return
	SetFilePointer(hFile,2,0,FILE_BEGIN);
	lSize=thisDatablock.GetLong(hFile);
	lSize+=((strlen(Copyright)+12)-lOldSize);
	SetFilePointer(hFile,2,0,FILE_BEGIN);
	WriteFile(hFile,(char *)&lSize,sizeof(lSize),&lBytesWritten,NULL);

	SetFilePointer(hFile,2,0,FILE_CURRENT);
	lSize=strlen(Copyright)+12;
	WriteFile(hFile,(char *)&lSize,sizeof(lSize),&lBytesWritten,NULL);

	SetFilePointer(hFile,4,0,FILE_CURRENT);

	// write copyright text
	WriteFile(hFile,Copyright,strlen(Copyright),&lBytesWritten,NULL);

	// put 00
	WriteFile(hFile,null,2,&lBytesWritten,NULL);

	// append data
	myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

	return true;
}

// Reads the script of a given object and puts it into a buffer
long CScene2::ReadObjectScript(HANDLE hFile, char * Buffer, char * szObjectName, short nDatablockType)
{
	ObjectInfo_t Scene2ObjectInfo_t;
	CDatablock thisDatablock;
	CHelper myHelper;
	long lObjectOffset=0,		// offset of our object
		lScriptSize=0,			// the size of the script to extract
		lDummyOffset=0;			// for BufferDataFM
	unsigned long lBytesRead=0;

	if(nDatablockType==SPECIAL_MAIN)
	{
		lObjectOffset=FindObject(hFile,szObjectName,SPECIAL_MAIN);
		ReadObject(hFile,lObjectOffset,&Scene2ObjectInfo_t,true);
		if(Scene2ObjectInfo_t.lType==SPECIAL_OBJECT_TYPE_SCRIPT)
		{
			// Object is a script object so we have:
			// 01 01 00 00 00 01 00 00 00 00 <size> <script>
			lDummyOffset=lObjectOffset=FindScript(hFile,szObjectName);
			if(lObjectOffset==-1)
				// no script was found
				return(-1);
			SetFilePointer(hFile,(lObjectOffset+10),0,FILE_BEGIN);	// to get to size of script
			// now read out lScriptSize bytes
			lScriptSize=thisDatablock.GetLong(hFile);
			lDummyOffset+=14;
			SetFilePointer(hFile,(lObjectOffset+14),0,FILE_BEGIN);
			// first check if it is really a script
			if(lScriptSize==0)
				return(-1);

//			myHelper.BufferData(hFile,szFileName,lScriptSize);
//			myHelper.BufferDataFM(hFile,szFileName,lDummyOffset,lScriptSize);
			ReadFile(hFile,Buffer,lScriptSize,&lBytesRead,NULL);
		}
		else
		{
			// Object is a non-script object so we have:
			// 01 01 00 00 00 00 <size> <script>
			lDummyOffset=lObjectOffset=FindScript(hFile,szObjectName);
			if(lObjectOffset==-1)
				//no script found
				return(-1);
			SetFilePointer(hFile,(lObjectOffset+6),0,FILE_BEGIN);
			lScriptSize=thisDatablock.GetLong(hFile);
			lDummyOffset+=10;
			SetFilePointer(hFile,(lObjectOffset+10),0,FILE_BEGIN);
//			myHelper.BufferData(hFile,szFileName,lScriptSize);
//			myHelper.BufferDataFM(hFile,szFileName,lDummyOffset,lScriptSize);
			ReadFile(hFile,Buffer,lScriptSize,&lBytesRead,NULL);
		}
	}
	else
	if(nDatablockType==ADDITIONAL_MAIN)
	{
		// find additional script object
		lDummyOffset=lObjectOffset=FindObject(hFile,szObjectName,ADDITIONAL_MAIN);
		SetFilePointer(hFile,(lObjectOffset+7),0,FILE_BEGIN);
		lDummyOffset+=7;
		// Get lenght of script name
		lScriptSize=thisDatablock.GetLong(hFile);
		SetFilePointer(hFile,lScriptSize,0,FILE_CURRENT);
		lDummyOffset+=(8+lScriptSize);
		// Get size of script
		lScriptSize=thisDatablock.GetLong(hFile);
		// Buffer data
//		myHelper.BufferData(hFile,szFileName,lScriptSize);
//		myHelper.BufferDataFM(hFile,szFileName,lDummyOffset,lScriptSize);
		ReadFile(hFile,Buffer,lScriptSize,&lBytesRead,NULL);
	}
	else
	{
		return(-1);
	}
	return(lScriptSize);
}

// Adds a script to an object - reads script from buffer
int CScene2::AddObjectScriptBuffer(HANDLE hFile, char * szObjectName, char * Buffer, int ScriptSize, short nDatablockType)
{
	ObjectInfo_t Scene2ObjectInfo_t;
	CDatablock thisDatablock;
	CHelper myHelper;

	long lObjectOffset=0,			// offset of object
		lObjDatablockSize=0,		// size of objects datablock
		lScriptOffset=0,			// offset of script of object
		lOldScriptSize=0,			// size of original script
//		lNewScriptSize=0,			// size of new script - commented in order to detect/prevent usage
		lDatablockOffset=0,			// offsets of datablocks to change
		lDatablockSize=0,			// sizes of datablocks to change
		lDummyOffset=0;				// for BufferDataFM

	unsigned long lBytesWritten=0;

	char sSig[6]={0x01,0x01,0x00,0x00,0x00,0x00};

	// check specified datablock
	if((nDatablockType!=SPECIAL_MAIN) && (nDatablockType!=ADDITIONAL_MAIN))
		return(-1);

	if(nDatablockType==ADDITIONAL_MAIN)
	{
		lDummyOffset=lObjectOffset=FindObject(hFile,szObjectName,ADDITIONAL_MAIN);
		if(lObjectOffset==-1)
			return(-1);

		SetFilePointer(hFile,(lObjectOffset+7),0,FILE_BEGIN);
		lDummyOffset+=7;
		lObjDatablockSize=thisDatablock.GetLong(hFile);
		lDummyOffset+=(4+lObjDatablockSize);
		SetFilePointer(hFile,lObjDatablockSize,0,FILE_CURRENT);
		// get old script size
		lOldScriptSize=thisDatablock.GetLong(hFile);
		lDummyOffset+=(4+lOldScriptSize);
		// write new size
		SetFilePointer(hFile,-4,0,FILE_CURRENT);
//		lNewScriptSize=myHelper.GetFileSize(szFileName);
//		WriteFile(hFile,(char *)&lOldScriptSize,sizeof(lOldScriptSize),&lBytesWritten,NULL);
		WriteFile(hFile,(char *)&ScriptSize,sizeof(ScriptSize),&lBytesWritten,NULL);
		// buffer upcoming data
		SetFilePointer(hFile,lOldScriptSize,0,FILE_CURRENT);
//		myHelper.BufferData(hFile,"buffer.tmp",-1);
		myHelper.BufferDataFM(hFile,"buffer.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);

		// now write new script
		SetFilePointer(hFile,(lObjectOffset+lObjDatablockSize+15),0,FILE_BEGIN);
//		myHelper.PasteBufferedDataFM(hFile,szFileName,false);
		WriteFile(hFile,Buffer,ScriptSize,&lBytesWritten,NULL);

		// paste other data
		myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

		SetEndOfFile(hFile);

		// now change sizes
		// 1. objects size
		SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
		lDatablockSize=thisDatablock.GetLong(hFile);
//		lDatablockSize+=(lNewScriptSize-lOldScriptSize);
		lDatablockSize+=(ScriptSize-lOldScriptSize);
		SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
		WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

		// 2. ADDITIONAL_MAIN size
		lDatablockOffset=thisDatablock.FindDatablock(hFile,ADDITIONAL_MAIN);
		SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
		lDatablockSize=thisDatablock.GetLong(hFile);
//		lDatablockSize+=(lNewScriptSize-lOldScriptSize);
		lDatablockSize+=(ScriptSize-lOldScriptSize);
		SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
		WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

		// 3. SCENE2_MAIN
		SetFilePointer(hFile,2,0,FILE_BEGIN);
		lDatablockSize=thisDatablock.GetLong(hFile);
//		lDatablockSize+=(lNewScriptSize-lOldScriptSize);
		lDatablockSize+=(ScriptSize-lOldScriptSize);
		SetFilePointer(hFile,2,0,FILE_BEGIN);
		WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);
	}
	else
	{
		// look for object

		lDummyOffset=lObjectOffset=FindObject(hFile,szObjectName,SPECIAL_MAIN);
		if(lObjectOffset==-1)
			return(-1);

		// get lenght
		SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
		lObjDatablockSize=thisDatablock.GetLong(hFile);

		// now check if the object already got a script section
		lScriptOffset=FindScript(hFile,szObjectName);
		if(lScriptOffset==-1)
		{
			// no
			// buffer data after object (ie new 21AE)
			SetFilePointer(hFile,(lObjectOffset+lObjDatablockSize),0,FILE_BEGIN);
			lDummyOffset+=lObjDatablockSize;
//			myHelper.BufferData(hFile,"buffer.tmp",-1);
			myHelper.BufferDataFM(hFile,"buffer.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);
			// Now write script signature
			WriteFile(hFile,&sSig,6,&lBytesWritten,NULL);
			// Get Script File Size
//			lNewScriptSize=myHelper.GetFileSize(szFileName);
			// Write script size
//			WriteFile(hFile,(char *)&lNewScriptSize,sizeof(lNewScriptSize),&lBytesWritten,NULL);
			WriteFile(hFile,(char *)&ScriptSize,sizeof(ScriptSize),&lBytesWritten,NULL);
			// Write the script
//			myHelper.PasteBufferedDataFM(hFile,szFileName,false);
			WriteFile(hFile,Buffer,ScriptSize,&lBytesWritten,NULL);
			// Paste other data
			myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

			SetEndOfFile(hFile);

			// ---NOW: change datablock sizes
			// 2. 24AE datablock
//			SetFilePointer(hFile,(lObjectOffset+6),0,FILE_BEGIN);
//			lDatablockOffset=thisDatablock.FindSubDatablock(hFile,SPECIAL_OBJECT_DATA,(lObjectOffset+6));
			lDatablockOffset=thisDatablock.FindObjectDatablock(hFile,SPECIAL_OBJECT_DATA,(lObjectOffset+6));
			SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
			lDatablockSize=thisDatablock.GetLong(hFile);
//			lDatablockSize+=(lNewScriptSize+10);
			lDatablockSize+=(ScriptSize+10);
			SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

			// 3. 21AE
			SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
			lDatablockSize=thisDatablock.GetLong(hFile);
//			lDatablockSize+=(lNewScriptSize+10);
			lDatablockSize+=(ScriptSize+10);
			SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

			// 4. 20AE datablock
			lDatablockOffset=thisDatablock.FindDatablock(hFile,SPECIAL_MAIN);
			SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
			lDatablockSize=thisDatablock.GetLong(hFile);
//			lDatablockSize+=(lNewScriptSize+10);
			lDatablockSize+=(ScriptSize+10);
			SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

			// 5. SL datablock
			SetFilePointer(hFile,2,0,FILE_BEGIN);
			lDatablockSize=thisDatablock.GetLong(hFile);
//			lDatablockSize+=(lNewScriptSize+10);
			lDatablockSize+=(ScriptSize+10);
			SetFilePointer(hFile,2,0,FILE_BEGIN);
			WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);
		}
		else
		{
			// yes
			// at first we have to determine what object type it is
			ReadObject(hFile,lObjectOffset,&Scene2ObjectInfo_t,true);
			if(Scene2ObjectInfo_t.lType==SPECIAL_OBJECT_TYPE_SCRIPT)
			{
				// Object is a script so we have:
				// 01 00/01 00 00 00 01 00 00 00 00 <size> <script>

				// First get size of previous script
				SetFilePointer(hFile,(lScriptOffset+10),0,FILE_BEGIN);
				lOldScriptSize=thisDatablock.GetLong(hFile);
				// buffer data after object (ie new 21AE)
				SetFilePointer(hFile,(lObjectOffset+lObjDatablockSize),0,FILE_BEGIN);
				lDummyOffset+=lObjDatablockSize;
//				myHelper.BufferData(hFile,"buffer.tmp",-1);
				myHelper.BufferDataFM(hFile,"buffer.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);
				// Go back to script
				SetFilePointer(hFile,(lScriptOffset+14),0,FILE_BEGIN);
				// Now write the script + save script size (lNewScriptSize)
//				myHelper.PasteBufferedDataFM(hFile,szFileName,false);
				WriteFile(hFile,Buffer,ScriptSize,&lBytesWritten,NULL);
//				lNewScriptSize=myHelper.GetFileSize(szFileName);
				// Paste other data
				myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

				SetEndOfFile(hFile);

				// ---NOW: change datablock sizes
				// 1. Script Size
				SetFilePointer(hFile,(lScriptOffset+10),0,FILE_BEGIN);
//				WriteFile(hFile,(char *)&lNewScriptSize,sizeof(lNewScriptSize),&lBytesWritten,NULL);
				WriteFile(hFile,(char *)&ScriptSize,sizeof(ScriptSize),&lBytesWritten,NULL);
				// 2. 24AE datablock
//				SetFilePointer(hFile,(lObjectOffset+6),0,FILE_BEGIN);
//				lDatablockOffset=thisDatablock.FindSubDatablock(hFile,SPECIAL_OBJECT_DATA,(lObjectOffset+6));
				lDatablockOffset=thisDatablock.FindObjectDatablock(hFile,SPECIAL_OBJECT_DATA,(lObjectOffset+6));
				SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
				lDatablockSize=thisDatablock.GetLong(hFile);
//				lDatablockSize+=(lNewScriptSize-lOldScriptSize);
				lDatablockSize+=(ScriptSize-lOldScriptSize);
				SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
				WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

				// 3. 21AE
				SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
				lDatablockSize=thisDatablock.GetLong(hFile);
//				lDatablockSize+=(lNewScriptSize-lOldScriptSize);
				lDatablockSize+=(ScriptSize-lOldScriptSize);
				SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
				WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

				// 4. 20AE datablock
				lDatablockOffset=thisDatablock.FindDatablock(hFile,SPECIAL_MAIN);
				SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
				lDatablockSize=thisDatablock.GetLong(hFile);
//				lDatablockSize+=(lNewScriptSize-lOldScriptSize);
				lDatablockSize+=(ScriptSize-lOldScriptSize);
				SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
				WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

				// 5. SL datablock
				SetFilePointer(hFile,2,0,FILE_BEGIN);
				lDatablockSize=thisDatablock.GetLong(hFile);
//				lDatablockSize+=(lNewScriptSize-lOldScriptSize);
				lDatablockSize+=(ScriptSize-lOldScriptSize);
				SetFilePointer(hFile,2,0,FILE_BEGIN);
				WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);
			}
			else
			{
				// Object is NOT a script so we have:
				// 01 01 00 00 00 00 <size> <script>

				// First get size of previous script
				SetFilePointer(hFile,(lScriptOffset+6),0,FILE_BEGIN);
				lOldScriptSize=thisDatablock.GetLong(hFile);
				// buffer data after object (ie new 21AE)
				SetFilePointer(hFile,(lObjectOffset+lObjDatablockSize),0,FILE_BEGIN);
				lDummyOffset+=lObjDatablockSize;
//				myHelper.BufferData(hFile,"buffer.tmp",-1);
				myHelper.BufferDataFM(hFile,"buffer.tmp",lDummyOffset,::GetFileSize(hFile,NULL)-lDummyOffset);
				// Go back to script
				SetFilePointer(hFile,(lScriptOffset+10),0,FILE_BEGIN);
				// Now write the script + save script size (lNewScriptSize)
//				myHelper.PasteBufferedDataFM(hFile,szFileName,false);
				WriteFile(hFile,Buffer,ScriptSize,&lBytesWritten,NULL);
//				lNewScriptSize=myHelper.GetFileSize(szFileName);
				// Paste other data
				myHelper.PasteBufferedDataFM(hFile,"buffer.tmp",true);

				SetEndOfFile(hFile);

				// ---NOW: change datablock sizes
				// 1. Script Size
				SetFilePointer(hFile,(lScriptOffset+6),0,FILE_BEGIN);
//				WriteFile(hFile,(char *)&lNewScriptSize,sizeof(lNewScriptSize),&lBytesWritten,NULL);
				WriteFile(hFile,(char *)&ScriptSize,sizeof(ScriptSize),&lBytesWritten,NULL);
				// 2. 24AE datablock
//				SetFilePointer(hFile,(lObjectOffset+6),0,FILE_BEGIN);
//				lDatablockOffset=thisDatablock.FindSubDatablock(hFile,SPECIAL_OBJECT_DATA,(lObjectOffset+6));
				lDatablockOffset=thisDatablock.FindObjectDatablock(hFile,SPECIAL_OBJECT_DATA,(lObjectOffset+6));
				SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
				lDatablockSize=thisDatablock.GetLong(hFile);
//				lDatablockSize+=(lNewScriptSize-lOldScriptSize);
				lDatablockSize+=(ScriptSize-lOldScriptSize);
				SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
				WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

				// 3. 21AE
				SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
				lDatablockSize=thisDatablock.GetLong(hFile);
//				lDatablockSize+=(lNewScriptSize-lOldScriptSize);
				lDatablockSize+=(ScriptSize-lOldScriptSize);
				SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
				WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

				// 4. 20AE datablock
				lDatablockOffset=thisDatablock.FindDatablock(hFile,SPECIAL_MAIN);
				SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
				lDatablockSize=thisDatablock.GetLong(hFile);
//				lDatablockSize+=(lNewScriptSize-lOldScriptSize);
				lDatablockSize+=(ScriptSize-lOldScriptSize);
				SetFilePointer(hFile,(lDatablockOffset+2),0,FILE_BEGIN);
				WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);

				// 5. SL datablock
				SetFilePointer(hFile,2,0,FILE_BEGIN);
				lDatablockSize=thisDatablock.GetLong(hFile);
//				lDatablockSize+=(lNewScriptSize-lOldScriptSize);
				lDatablockSize+=(ScriptSize-lOldScriptSize);
				SetFilePointer(hFile,2,0,FILE_BEGIN);
				WriteFile(hFile,(char *)&lDatablockSize,sizeof(lDatablockSize),&lBytesWritten,NULL);
			}
		}
	}
	return 0;
}

// Used to find the script section of a special object
long CScene2::FindScript(HANDLE hFile, char * szObjectName)
{
	CHelper myHelper;
	long lObjectOffset=0,
		lObjDatablockSize=0;
	char * BigBuf;		// buffer
	char sig_script[6]={0x01,0x01,0x00,0x00,0x00,0x01};
	char sig_script_alt[6]={0x01,0x00,0x00,0x00,0x00,0x01};
	char sig_char[6]={0x01,0x01,0x00,0x00,0x00,0x00};
	unsigned long lBytesRead=0;
	CDatablock thisDatablock;
	int i=0, loc=0;
	
/*	DuplicateHandle(GetCurrentProcess(), hFile,
        GetCurrentProcess(), &hDummy , 0,
        FALSE,
        DUPLICATE_SAME_ACCESS);
*/
	lObjectOffset=FindObject(hFile,szObjectName,SPECIAL_MAIN);
	if(lObjectOffset==-1)
		return(-1);

	// ok now we know where to find the object so let's start with looking for the
	// script signature
	SetFilePointer(hFile,(lObjectOffset+2),0,FILE_BEGIN);
	lObjDatablockSize=thisDatablock.GetLong(hFile);

	// create buffer
	BigBuf=new char[lObjDatablockSize];

	SetFilePointer(hFile,-6,0,FILE_CURRENT);						// move back
	ReadFile(hFile,BigBuf,lObjDatablockSize,&lBytesRead,NULL);	// read whole object

	// compare with first script signature
	loc=myHelper.binstrstr(BigBuf,sig_script,5,lObjDatablockSize);
	if(loc!=0)
	{
		delete[] BigBuf;
		return(lObjectOffset+loc);
	}
	// compare with second script signature
	loc=myHelper.binstrstr(BigBuf,sig_script_alt,5,lObjDatablockSize);
	if(loc!=0)
	{
		delete[] BigBuf;
		return(lObjectOffset+loc);
	}
	// compare with char script signature
	loc=myHelper.binstrstr(BigBuf,sig_char,5,lObjDatablockSize);
	if(loc!=0)
	{
		delete[] BigBuf;
		return(lObjectOffset+loc);
	}

	delete[] BigBuf;
	return(-1);
}
// Looks for a particular car in a traffic object
/*long CScene2::FindCar(char * szCarName)
{
	return 0;
}
*/
// Returns the build (=version) of MafiaLib Engine
int CScene2::GetVersion(void)
{
	return(MAFIALIB_BUILD);
}
