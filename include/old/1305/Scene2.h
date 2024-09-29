// Scene2.h
//
// CScene2 class definition file
//
// CScene2 class is a part of the MafiaLib Engine
//
// Copyright (c) 2003, 2004 ASM

#include <windows.h>

#pragma once

// Filter Types
#define FILTER_OBJECTTYPE	1
#define FILTER_LIGHTMAP		2
#define FILTER_SECTOR		4
#define FILTER_OBJECTNAME	8

// Object Info Structure
typedef struct ObjectTAG{
	long lType;			// type

	// those generic values
	char sName[256];		// name
	float fPos[3];			// X - Z - Y Pos
	float fRot[4];			// four rotation values
	float fSize[3];			// Size
	float fAddTrans[3];		// Additional Translation Info
	char sSectorName[256];	// Sector name
	char sModelName[256];	// Model name
	bool bUseModel;			// use model?

	// Character properties
	unsigned char cBehaviour;	// behaviour
	unsigned char cVoice;		// voice
	float fStrenght;			// strenght
	float fEnergy;				// energy
	float fEnergy_HANDL;		// left hand energy
	float fEnergy_HANDR;		// right hand energy
	float fEnergy_LEGL;			// left leg energy
	float fEnergy_LEGR;			// right leg energy
	float fReactions;			// reactions
	float fSpeed;				// speed
	float fAggr;				// aggressivity
	float fInt;					// intelligence
	float fShooting;			// shooting
	float fSight;				// sight
	float fHearing;				// hearing
	float fDriving;				// driving
	float fMass;				// mass
	float fBehaviour;			// 2. behaviour

	// Light properties
	long lLightType;			// type of light
	float fRed;
	float fGreen;				// RGB - Color of light
	float fBlue;
	long lLightFlags;			// flags for light
	float fPower;				// power of light
	float fLightUnk1;			// ??
	float fLightUnk2;			// ??
	float fLightNear;			// near power
	float fLightFar;			// far power
	char sLightSectors[1000];   // for the sectors (NULL-TERMINATED!); Multiple names can be added continousely
//	int iSectorCount;			// how many sectors

	// Type 06
	float fVal[6];				// for the extra data of type 06

	// Movable Object
	float fMovVal1;				// ??
	float fMovVal2;				// ??
	float fWeight;				// the weight of the object
	float fMovVal3;				// friction
	float fMovVal4;				// ??
	long lSound;				// sound to play in case of hit
	long lMovVal5;				// ??

	// Sector Data
	// It would be nice if I could read out sector values continousely
	// and store them in a big vector but I can't since it is not sure
	// whether or not the datablocks are always written in the same way from
	// sector to sector. So I have to create seperate float vars :(

	float fSectorVal1;
	float fSectorVal2;
	float fSectorVal3;
	float fSectorVal4;
	long lSectorVal5;
	float fSectorVal6;
	long lSectorVal7;
	float fSectorVal8;
	long lSectorVal9;
	float fSectorVal10;
	float fSectorVal11;
	long lSectorVal12;
	long lSectorVal13;
	long lSectorVal14;
	long lSectorVal15;
	float fSectorVal16;
	long lSectorVal17;
	float fSectorVal18;
	float fSectorVal19;
	long lSectorVal20;
	long lSectorVal21[3];
	long lSectorVal22[3];

	// Traffic Data
	float fTrafficVal[3];		// 3 traffic values - meaning ??
	long lDensity;				// Global Density for all cars
	long lNumOfCars;			// number of different car types to create

	char sCarname[1000][20];			// names of car model (names MUST NOT exceed 19 bytes of lenght!)
	float fDensity[1000];				// how often to create car
	long lColor[1000];					// color for car
	bool bPolice[1000];					// is car to be used by police?
	bool bFlag2[1000];					// ? (used with gangster flag)
	bool bGangster[1000];				// is car to be used by gangsters?
	bool bFlag4[1000];					// ?
	bool bDel[1000];					// is item to be deleted?

}ObjectInfo_t;

// Filter_t structure
typedef struct FilterTAG{
	int iFilterType;			// what kind of filter - reference @ // Filter Types - filter types can be combined
	short nDatablock;			// datablocks objects are to be found in (for FILTER_OBJECTTYPE)
	char * szObjectName;		// names to find (for FILTER_OBJECTNAME)
	int iObjectType;			// types to find (for FILTER_OBJECTTYPE)
}Filter_t;

// BasicObjectInfo_t structure - for GetNextObject
typedef struct BasicInfoTAG{
	char name[256];				// name of the found object
	short nDatablock;			// datablock, the object was found in
	int iObjectType;			// type of the found object
	long lNextObjectOffset;		// offset of next object
}BasicObjectInfo_t;

// Scene2General
//
// Used for loading general information from the scene2.bin file

// The CSene2 Class

class CScene2
{
public:
	CScene2(void);
	~CScene2(void);
	// Object Offsets
//	long lObjectOffsets[50000];
	// NORMAL_MAIN datablock address
	long lNormalMainOffset;
	// SPECIAL_MAIN datablock address
	long lSpecialMainOffset;
	// Global file handle
	HANDLE hFile;
	// Loads a scene2 bin
	HANDLE LoadScene2Bin(char * szFilename);
	void CloseScene2Bin(HANDLE hFile);
	bool IsScene2Bin(HANDLE hFile);
	unsigned long GetFileSize(HANDLE hFile);
	// Reads the complete scene2.bin file and writes all found datablocks/objects into the Datablocks_Objects.txt
#ifdef MAFIALIB_DEBUG
	void ReadDatablocksObjects(HANDLE hFile);
#endif
	// Used for adding or replacing objects to scene2.bin file
	int AddObject(HANDLE hFile, ObjectInfo_t * Scene2ObjectInfo_t, char * szScriptFileName, char * szObjectToReplace);
	float GetCamDist(HANDLE hFile);
	// Reads out the viewdistance
	float GetViewDist(HANDLE hFile);
	// Used for modifying the camera distance
	long SetCamDist(HANDLE hFile, float fCamDist);
	// Used for modifying the viewdistance
	long SetViewDist(HANDLE hFile, float fViewDist);
	// Used for reading the (probably) wolrd dimension
	float GetWorldDim(HANDLE hFile, bool bReadFirst);
	// Writes the world dimension
	long SetWorldDim(HANDLE hFile, float fDim1, float fDim2);
	// Used for finding objects
	long FindObject(HANDLE hFile, char * szObjectName, short nDatablockType);
	// Reads out all object properties
	bool ReadObject(HANDLE hFile, long lOffset, ObjectInfo_t * Scene2ObjectInfo_t, bool bUseFilter=true); //true because we don't want to read out special data by default
	// Deletes an object
	int DeleteObject(HANDLE hFile, char * szObjectName, short nDatablockType);
	// Exports an object
	long ExportObject(HANDLE hFile, char * szFileName, char * szObjectName, short nDatablockType);
	// Imports an object
	long ImportObject(HANDLE hFile, char * szFileName);
	// Used to find the script section of a special object
	long FindScript(HANDLE hFile, char * szObjectName);
	// Extracts the script of an object in SPECIAL_MAIN datablock
	long ExtractObjectScript(HANDLE hFile, char * szObjectName, short nDatablockType, char * szFileName);
	// Adds a script to an object situated in SPECIAL_MAIN
	long AddObjectScript(HANDLE hFile, char *  szObjectName, char * szFileName, short nDatablockType);
	// Removes a script from an object
	long RemoveObjectScript(HANDLE hFile, char * szObjectName);
	// Edits name of object szObjectName
	long EditObjectName(HANDLE hFile, char * szOldObjectName, char * szObjectName, short nDatablockType);
	// Initalizes ObjectInfo_t structure with default values, recommend after every declaration of this struct
	static void PrepareObjectInfo(ObjectInfo_t * Scene2ObjectInfo_t);
	// Retreives object names from scene2.bin
	int GetNextObject(HANDLE hFile, BasicObjectInfo_t * pBasicObjectInfo_t, Filter_t * pObjectFilter_t);
	// Reads out the copyright text in scene2.bin
	bool GetCopyrightText(HANDLE hFile, char * Buffer);
	// Sets the copyright
	bool SetCopyrightText(HANDLE hFile, char * Copyright);
	// Reads the script of a given object and puts it into a buffer
	long ReadObjectScript(HANDLE hFile, char * Buffer, char * szObjectName, short nDatablockType);
	// Adds a script to an object - reads script from buffer
	int AddObjectScriptBuffer(HANDLE hFile, char * szObjectName, char * Buffer, int ScriptSize, short nDatablockType);
	// Returns the build (=version) of MafiaLib Engine
	int GetVersion(void);
};
