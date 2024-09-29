// MLWrapper.h
//
// CMLWrapper definition file
//
// CMLWrapper class is a part of the MafiaLib Engine
//
// Copyright (c) 2003, 2004 ASM

#pragma once
#include "Scene2.h"
#include "Datablock.h"
#include "Helper.h"
#include <qfileinfo.h>
#include <qobject.h>
#include <qstring.h>
#include <qstringlist.h>

class CMLWrapper : public QObject
{
	Q_OBJECT
public:
	CMLWrapper(void);
	~CMLWrapper(void);

private:
	CScene2 thisScene2;
	CDatablock thisDatablock;
	CHelper thisHelper;
	char * standartCopyrightText;
	QFileInfo originalFile;
	QFileInfo tempFile;
/*	BOOL m_bInitialized;*/

protected:
	HANDLE hFile;

public:
	int AddObject( ObjectInfo_t * Scene2ObjectInfo_t, char * szObjectToReplace );
	int AddObject( ObjectInfo_t * Scene2ObjectInfo_t, QString szObjectToReplace );
	long BufferData( char * szFileName, long lSize );
	long BufferDataFM( char * szFileName, long lOffset, long lSize );
	bool BuildObjectList( Filter_t * pObjectFilter_t = NULL );  // Build the name list - requested by scream
	void CloseScene2Bin( bool save = false, bool backup = false );
	void CreateDatablock( short nType, long lSize );
	void CreateObject( QString name, long objectType, short nDatablockType );
	int DeleteObject( QString szObjectName, short nDatablockType );
	void DuplicateObject( QString oldName, QString newName, short nDatablockType );
	long EditObjectName( QString szOldObjectName, QString szObjectName, short nDatablockType );
	long ExportObject( QString fileName, QString objectName, short nDatablockType );
	long ExportObjectScript( QString fileName, QString objectName, short nDatablockType );
	long FindDatablock( short nType );
	long FindObject( char * szObjectName, short nDatablockType );
	long FindScript( char * szObjectName );
	long FindSubDatablock( short nType, long lBeginOffset );
	float GetCamDist();
	char * GetCopyrightText();
	unsigned long GetFileSize();
	int GetNextObject( BasicObjectInfo_t * pBasicObjectFilter_t, Filter_t * pObjectFilter_t );
	QStringList getSectorList();
	float GetViewDist();
	float GetWorldDim( bool bReadFirst );
	long ImportObject( QString fileName );
	long ImportObjectScript( QString objectName, QString fileName, short nDatablockType = SPECIAL_MAIN );
	bool IsScene2Bin();
	bool LoadScene2Bin( QFileInfo file );
	DWORD m_seek( long lSize, DWORD lDirection );
	int NewTemplate();
	long PasteBufferedData( char * szFileName, bool bDel );
	long PasteBufferedDataFM( char * szFileName, bool bDel );
	void ReadDatablockObjects();
	ObjectInfo_t * ReadObject( QString szObjectName, bool bUseFilter=false, short nDatablockType = NORMAL_MAIN );
	static BasicObjectInfo_t * ReadObjectFile( QString filename );
	QString ReadObjectScript( QString szObjectName, bool init = false );
	long RemoveObjectScript( QString szObjectName );
	void SaveScene2Bin( bool backup = FALSE );
	long SetCamDist( float fCamDist );
	bool SetCopyrightText();
	long SetViewDist( float fViewDist );
	long SetWorldDim( float fDim1, float fDim2 );

	char GetByte();
	float GetFloat();
	long GetLong();
	short GetShort();
	
public slots:
	int SaveObjectScript( QString szObjectName, QString Buffer, bool init );
	int SaveObject( ObjectInfo_t * Scene2ObjectInfo_t, QString oldName, bool b = true );

signals:
	void addObjectToList( char *, int, short );
	void objectCreated( char *, int, short );
};
