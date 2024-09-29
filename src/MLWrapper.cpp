// MLWrapper.cpp
//
// CMLWrapper implementation file
//
// CMLWrapper class is a part of the MafiaLib Engine
//
// Copyright (c) 2003, 2004 ASM

// for scream
#include "MLWrapper.h"
#include <qmessagebox.h>
#include <qfileinfo.h>
#include <qtextstream.h>



static void dcDebug( QString title, QString message )
{
	QMessageBox::information( 0, title, message );
}

CMLWrapper::CMLWrapper()
{
	hFile = 0;
	standartCopyrightText = "- Mission file - Copyright (c) 2000  programmers of ILLUSIONSOFTWORKS ;) - Modified with DC||ED (c)2004 by www.don-city.de.vu - ";
}

CMLWrapper::~CMLWrapper()
{
}

int CMLWrapper::AddObject(ObjectInfo_t * Scene2ObjectInfo_t, char * szObjectToReplace)
{
	return(thisScene2.AddObjectEx(hFile,Scene2ObjectInfo_t,szObjectToReplace));
}

int CMLWrapper::AddObject(ObjectInfo_t * Scene2ObjectInfo_t, QString szObjectToReplace)
{
	return(thisScene2.AddObjectEx(hFile,Scene2ObjectInfo_t,(char*)(szObjectToReplace.latin1())));
}

void CMLWrapper::CloseScene2Bin( bool save /* = false */, bool backup /* false */ )
{
	if( hFile == 0 )
		return;

	thisScene2.CloseScene2Bin( hFile );

	
	//Saving the file
	if( save )
	{
		//Backuping the original file
		if( backup )
			MoveFileEx( originalFile.absFilePath().replace( "/", "\\" ),
						originalFile.absFilePath().left( originalFile.absFilePath().length() - 4 ).replace( "/", "\\" ) + ".bak",
						MOVEFILE_REPLACE_EXISTING );

		//Saving the temporary file over the original file
		MoveFileEx( tempFile.absFilePath().replace( "/", "\\" ),
					originalFile.absFilePath().replace( "/", "\\" ),
					MOVEFILE_REPLACE_EXISTING );
	}
	else
	{
		DeleteFile( tempFile.absFilePath().replace( "/", "\\" ) );
	}
}

void CMLWrapper::SaveScene2Bin( bool backup /* false */ )
{
	//Backuping the original file
	if( backup )
		MoveFileEx( originalFile.absFilePath().replace( "/", "\\" ),
					originalFile.absFilePath().left( originalFile.absFilePath().length() - 4 ).replace( "/", "\\" ) + ".bak",
					MOVEFILE_REPLACE_EXISTING );

	//Saving the temporary file over the original file
	CopyFile( tempFile.absFilePath().replace( "/", "\\" ),
			  originalFile.absFilePath().replace( "/", "\\" ),
			  FALSE /* do not fail if file already exists */ );
}

void CMLWrapper::CreateObject( QString name, long objectType, short nDatablockType ) 
{ 
	ObjectInfo_t objectInfo; 
	thisScene2.PrepareObjectInfo( &objectInfo ); 
	objectInfo.lType = objectType; 
	for( int i = 0; i < name.length(); i++ )
		objectInfo.sName[i] = name[i].latin1();
	objectInfo.sName[++i] = 0;

	if( nDatablockType == NORMAL_MAIN && objectType!=NORMAL_OBJECT_TYPE_SECTOR) 
		objectInfo.lType |= 0xF0;			 //das && ist wegen des sektor 
											 //bugs in der mLib 

	thisScene2.AddObjectEx( hFile, &objectInfo, NULL); 

	switch(objectInfo.lType) //Bei hardgecodeten Obbis muss der Name geändert werden 
	{ 
	case SPECIAL_OBJECT_TYPE_CAR: 
		thisScene2.EditObjectName(hFile, "<tmp>", objectInfo.sName, SPECIAL_MAIN); 
	case SPECIAL_OBJECT_TYPE_SCRIPT: 
		thisScene2.EditObjectName(hFile, "<st>", objectInfo.sName, SPECIAL_MAIN); 
	case ADDITIONAL_OBJECT_TYPE_SCRIPT: 
		thisScene2.EditObjectName(hFile, "<init-tmp>", objectInfo.sName, ADDITIONAL_MAIN); 
	} 
	emit objectCreated( objectInfo.sName, objectType, nDatablockType ); 
}

int CMLWrapper::DeleteObject( QString szObjectName, short nDatablockType )
{
	return thisScene2.DeleteObject( hFile, (char *)(szObjectName.latin1()), nDatablockType );
}

void CMLWrapper::DuplicateObject( QString oldName, QString newName, short nDatablockType )
{
    ObjectInfo_t * newObject = ReadObject( oldName, FALSE, nDatablockType );

    for( int i = 0; i < newName.length(), i < 255; i++ )
            newObject->sName[i] = newName[i].latin1();

	if( nDatablockType == NORMAL_MAIN && newObject->lType != NORMAL_OBJECT_TYPE_SECTOR )
		newObject->lType |= 0xF0;

	AddObject( newObject, NULL );
	AddObject( newObject, newObject->sName );
	delete newObject;
}

long CMLWrapper::EditObjectName(QString szOldObjectName, QString szObjectName, short nDatablockType)
{
	return thisScene2.EditObjectName( hFile,(char *)(szOldObjectName.latin1()),
									  (char *)(szObjectName.latin1()), nDatablockType );
}

long CMLWrapper::ExportObject( QString fileName, QString objectName, short nDatablockType )
{
	return thisScene2.ExportObject( hFile, (char *)(fileName.latin1()), (char *)(objectName.latin1()), nDatablockType );
}

long CMLWrapper::ExportObjectScript( QString fileName, QString objectName, short nDatablockType )
{
	return thisScene2.ExtractObjectScript( hFile, (char *)(objectName.latin1()), nDatablockType, (char *)(fileName.latin1()) );
}

long CMLWrapper::FindObject(char * szObjectName, short nDatablockType)
{
	return(thisScene2.FindObject(hFile,szObjectName,nDatablockType));
}

long CMLWrapper::FindScript(char * szObjectName)
{
	return(thisScene2.FindScript(hFile,szObjectName));
}

float CMLWrapper::GetCamDist(void)
{
	return(thisScene2.GetCamDist(hFile));
}

unsigned long CMLWrapper::GetFileSize(void)
{
	return(thisScene2.GetFileSize(hFile));
}

QStringList CMLWrapper::getSectorList()
{
	Filter_t ObjectFilter;
	BasicObjectInfo_t ObjectInfo;
	QStringList sectorList;

	ObjectFilter.iFilterType = FILTER_SECTOR;
	ObjectInfo.lNextObjectOffset=6;

	m_seek( 6, FILE_BEGIN );

	for( int Result = 0; Result != -1; Result = GetNextObject(&ObjectInfo, &ObjectFilter) )
		if(Result==1)
			sectorList.append( QString( ObjectInfo.name ) );

	sectorList.sort();

	return sectorList;
}

float CMLWrapper::GetViewDist(void)
{
	return(thisScene2.GetViewDist(hFile));
}

float CMLWrapper::GetWorldDim(bool bReadFirst)
{
	return(thisScene2.GetWorldDim(hFile,bReadFirst));
}

long CMLWrapper::ImportObject( QString fileName )
{
	return thisScene2.ImportObject( hFile, (char *)(fileName.replace( "/", "\\" ).latin1()) );
}

long CMLWrapper::ImportObjectScript( QString objectName, QString fileName, short nDatablockType )
{
	return thisScene2.AddObjectScript( hFile, (char *)(objectName.latin1()), (char *)(fileName.replace( "/", "\\" ).latin1()), SPECIAL_MAIN );
}

bool CMLWrapper::IsScene2Bin(void)
{
	return(thisScene2.IsScene2Bin(hFile));
}

bool CMLWrapper::LoadScene2Bin( QFileInfo file )
{
	originalFile = file;
	tempFile = QFileInfo( file.dirPath( TRUE ) + "/$scene2.bi_" );

	CopyFile( originalFile.absFilePath().replace( "/", "\\" ),
			  tempFile.absFilePath().replace( "/", "\\" ), FALSE );

	hFile = thisScene2.LoadScene2Bin( (char *)(tempFile.absFilePath().replace( "/", "\\" ).latin1()) );
	if( hFile != INVALID_HANDLE_VALUE && IsScene2Bin() )
		return TRUE;
	return FALSE;
}

int CMLWrapper::NewTemplate()
{
	return thisScene2.NewTemplate( hFile );
}

#ifdef MAFIALIB_DEBUG
void CMLWrapper::ReadDatablockObjects(void)
{
	thisScene2.ReadDatablocksObjects(hFile);
}
#endif

ObjectInfo_t * CMLWrapper::ReadObject( QString szObjectName, bool bUseFilter, short nDatablockType )
{
	long lOffset = FindObject( (char*)(szObjectName.latin1()), nDatablockType );

	ObjectInfo_t * Scene2ObjectInfo_t = new ObjectInfo_t;
	thisScene2.PrepareObjectInfo( Scene2ObjectInfo_t );
	thisScene2.ReadObject( hFile, lOffset, Scene2ObjectInfo_t, bUseFilter );

	return Scene2ObjectInfo_t;
}

BasicObjectInfo_t * CMLWrapper::ReadObjectFile(QString filename)
{
	const char * szObjectFile = filename.latin1();
	BasicObjectInfo_t * boi = new BasicObjectInfo_t;
	boi->iObjectType = 0;
	boi->lNextObjectOffset = 0;
	for( int i = 0; i < 256; i++ )
		boi->name[i] = 0;
	boi->nDatablock = 0;
	unsigned long dwBytesRead;
	HANDLE hFile=CreateFile(szObjectFile,GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING,0,0);
	short nType;
	unsigned long dwSize;
	ReadFile(hFile,(short *)boi->nDatablock,sizeof(short),&dwBytesRead,0);
	SetFilePointer(hFile,4,0,FILE_CURRENT);
	while(ReadFile(hFile,(short *)&nType,sizeof(short),&dwBytesRead,0))
	{
		if(!dwBytesRead)
			break;
		switch(nType)
		{
		case NORMAL_OBJECT_OR_SECTOR_NAME:
		case SPECIAL_OBJECT_NAME:
			ReadFile(hFile,(unsigned long *)&dwSize,sizeof(unsigned long),&dwBytesRead,0);
			ReadFile(hFile,boi->name,dwSize-6,&dwBytesRead,0);
			break;
		case NORMAL_OBJECT_TYPE:
		case SPECIAL_OBJECT_TYPE:
			ReadFile(hFile,(unsigned long *)&dwSize,sizeof(unsigned long),&dwBytesRead,0);
			ReadFile(hFile,(int *)boi->iObjectType,sizeof(unsigned long),&dwBytesRead,0);
			break;
		default:
			ReadFile(hFile,(unsigned long *)&dwSize,sizeof(unsigned long),&dwBytesRead,0);
			SetFilePointer(hFile,dwSize-6,0,FILE_CURRENT);
			break;
		}
	}
	CloseHandle(hFile);
	return boi;
}

long CMLWrapper::RemoveObjectScript(QString szObjectName)
{
	return thisScene2.RemoveObjectScript(hFile,(char *)(szObjectName.latin1()));
}

long CMLWrapper::SetCamDist(float fCamDist)
{
	return(thisScene2.SetCamDist(hFile,fCamDist));
}

long CMLWrapper::SetViewDist(float fViewDist)
{
	return(thisScene2.SetViewDist(hFile,fViewDist));
}

long CMLWrapper::SetWorldDim(float fDim1, float fDim2)
{
	return(thisScene2.SetWorldDim(hFile,fDim1,fDim2));
}

void CMLWrapper::CreateDatablock(short nType, long lSize)
{
	thisDatablock.CreateDatablock(hFile,nType,lSize);
}

long CMLWrapper::FindDatablock(short nType)
{
	return(thisDatablock.FindDatablock(hFile,nType));
}

long CMLWrapper::FindSubDatablock(short nType, long lBeginOffset)
{
	return(thisDatablock.FindSubDatablock(hFile,nType,lBeginOffset));
}

char CMLWrapper::GetByte(void)
{
	return(thisDatablock.GetByte(hFile));
}

float CMLWrapper::GetFloat(void)
{
	return(thisDatablock.GetFloat(hFile));
}

long CMLWrapper::GetLong(void)
{
	return(thisDatablock.GetLong(hFile));
}

short CMLWrapper::GetShort(void)
{
	return(thisDatablock.GetShort(hFile));
}

long CMLWrapper::BufferData(char * szFileName, long lSize)
{
	return(thisHelper.BufferData(hFile,szFileName,lSize));
}


long CMLWrapper::BufferDataFM(char * szFileName, long lOffset, long lSize)
{
	return(thisHelper.BufferDataFM(hFile,szFileName,lOffset,lSize));
}

long CMLWrapper::PasteBufferedData(char * szFileName, bool bDel)
{
	return(thisHelper.PasteBufferedData(hFile,szFileName,bDel));
}

long CMLWrapper::PasteBufferedDataFM(char * szFileName, bool bDel)
{
	return(thisHelper.PasteBufferedDataFM(hFile,szFileName,bDel));
}

DWORD CMLWrapper::m_seek(long lSize, DWORD lDirection)
{
	return(SetFilePointer(hFile,lSize,0,lDirection));
}

int CMLWrapper::GetNextObject(BasicObjectInfo_t * pBasicObjectInfo_t, Filter_t * pObjectFilter_t)
{
	return(thisScene2.GetNextObject(hFile,pBasicObjectInfo_t,pObjectFilter_t));
}

int CMLWrapper::SaveObject( ObjectInfo_t * Scene2ObjectInfo_t, QString oldName, bool b /* = true */ )
{
	if( b == true )
		Scene2ObjectInfo_t->lType |= 0xF0;
	return thisScene2.AddObjectEx( hFile, Scene2ObjectInfo_t, (char *)(oldName.latin1()) );
}

int CMLWrapper::SaveObjectScript( QString szObjectName, QString Buffer, bool init )
{
	short nDatablockType;
	if( init )
		nDatablockType = ADDITIONAL_MAIN;
	else
		nDatablockType = SPECIAL_MAIN;

	for( int i = 0, textLength = Buffer.length(); i < Buffer.contains( "\x0A" ); i++ )
		textLength++;
	for( i = 0; i < Buffer.contains( "\x20" ); i++ )
		textLength++;

	return thisScene2.AddObjectScriptBuffer( hFile,
					(char *)(szObjectName.latin1()),
					(char *)(Buffer.latin1()),
					textLength,
					nDatablockType );
}

QString CMLWrapper::ReadObjectScript( QString szObjectName, bool init )
{
	static char Buffer[1000000];
	for(int i=0;i<1000000;i++)
		Buffer[i]=0;

	int length;
	if( init )
		length = thisScene2.ReadObjectScript( hFile, Buffer, (char *)(szObjectName.latin1()), ADDITIONAL_MAIN );
	else
		length = thisScene2.ReadObjectScript( hFile, Buffer, (char *)(szObjectName.latin1()), SPECIAL_MAIN );// ); QString( Buffer ).left( 

	return QString( Buffer ).left( length );
}

char * CMLWrapper::GetCopyrightText()
{
	static char Buffer[1000000] = "";
	thisScene2.GetCopyrightText( hFile, Buffer );
	return Buffer;
}

bool CMLWrapper::SetCopyrightText()
{
	return(thisScene2.SetCopyrightText( hFile, standartCopyrightText ) );
}

// Build the name list - requested by scream
bool CMLWrapper::BuildObjectList(Filter_t * pObjectFilter_t)
{
	BasicObjectInfo_t GeneralObjectInfo_t;		// for GetNextObject

	m_seek(6,FILE_BEGIN);
	GeneralObjectInfo_t.lNextObjectOffset=6;

	for( int Result = 0; Result != -1; Result = GetNextObject(&GeneralObjectInfo_t,pObjectFilter_t) )
		if( Result==1 )
			emit addObjectToList( GeneralObjectInfo_t.name, GeneralObjectInfo_t.iObjectType, GeneralObjectInfo_t.nDatablock );

	return true;
}