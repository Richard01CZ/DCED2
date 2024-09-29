# Microsoft Developer Studio Project File - Name="DCED2" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=DCED2 - Win32 LG Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "DCED2.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "DCED2.mak" CFG="DCED2 - Win32 LG Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DCED2 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "DCED2 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "DCED2 - Win32 LG Release" (based on "Win32 (x86) Application")
!MESSAGE "DCED2 - Win32 LG Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "DCED2 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /GX /O1 /Ob0 /I "." /I "$(QTDIR)\include" /I "E:\Programmierung\DCED2" /I "E:\Programmierung\DCED2\include" /I "D:\Programme\Programmierung\Qt\3.2.3\mkspecs\win32-msvc" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "QT_NO_DEBUG" /FD -Zm200 /c
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /machine:IX86
# ADD LINK32 "qt-mt.lib" "qtmain.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "imm32.lib" "winmm.lib" "wsock32.lib" "winspool.lib" "delayimp.lib" "odbc32.lib" "odbccp32.lib" /nologo /subsystem:windows /machine:IX86 /libpath:"$(QTDIR)\lib" /nodefaultlib:""libc.lib"" /DELAYLOAD:comdlg32.dll /DELAYLOAD:wsock32.dll
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "DCED2 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /Gm /Zi /Od /Gf /Gy /I "." /I "$(QTDIR)\include" /I "E:\Programmierung\DCED2" /I "E:\Programmierung\DCED2\include" /I "D:\Programme\Programmierung\Qt\3.2.1\mkspecs\win32-msvc" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "QT_THREAD_SUPPORT" /D "QT_DEBUG" /FD /GZ -Zm200 /c
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /machine:IX86
# ADD LINK32 "qt-mt.lib" "qtmain.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "imm32.lib" "winmm.lib" "wsock32.lib" "winspool.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "imm32.lib" "winmm.lib" "wsock32.lib" "winspool.lib" /nologo /subsystem:windows /debug /machine:IX86 /nodefaultlib:"libc.lib" /nodefaultlib:"libcd.lib" /pdbtype:sept /libpath:"$(QTDIR)\lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "DCED2___Win32_LG_Release"
# PROP BASE Intermediate_Dir "DCED2___Win32_LG_Release"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "DCED2___Win32_LG_Release"
# PROP Intermediate_Dir "DCED2___Win32_LG_Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /GX /O1 /Ob0 /I "." /I "$(QTDIR)\include" /I "E:\Programmierung\DCED2" /I "E:\Programmierung\DCED2\include" /I "D:\Programme\Programmierung\Qt\3.2.3\mkspecs\win32-msvc" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "QT_NO_DEBUG" /FD -Zm200 /c
# ADD CPP /nologo /GX /O1 /Ob0 /I "." /I "$(QTDIR)\include" /I "G:\DCED2_src" /I "G:\DCED2_src\include" /I "$(QTDIR)\win32-msvc" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "QT_NO_DEBUG" /FD -Zm200 /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /fo"LG_Release/editor.res" /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 "qt-mt.lib" "qtmain.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "imm32.lib" "winmm.lib" "wsock32.lib" "winspool.lib" delayimp.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:IX86 /nodefaultlib:"libc.lib" /libpath:"$(QTDIR)\lib" /DELAYLOAD:comdlg32.dll /DELAYLOAD:oleaut32.dll /DELAYLOAD:winmm.dll /DELAYLOAD:wsock32.dll /DELAYLOAD:winspool.dll
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 "qt-mt.lib" "qtmain.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "imm32.lib" "winmm.lib" "wsock32.lib" "winspool.lib" "delayimp.lib" "odbc32.lib" "odbccp32.lib" /nologo /subsystem:windows /pdb:"LG_Release/LG_DCED2.pdb" /machine:IX86 /nodefaultlib:"libc.lib" /out:"LG_Release/LG_DCED2.exe" /libpath:"$(QTDIR)\lib" /DELAYLOAD:comdlg32.dll /DELAYLOAD:wsock32.dll
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DCED2___Win32_LG_Debug"
# PROP BASE Intermediate_Dir "DCED2___Win32_LG_Debug"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DCED2___Win32_LG_Debug"
# PROP Intermediate_Dir "DCED2___Win32_LG_Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /Gm /Zi /Od /Gf /Gy /I "." /I "$(QTDIR)\include" /I "E:\Programmierung\DCED2" /I "E:\Programmierung\DCED2\include" /I "D:\Programme\Programmierung\Qt\3.2.1\mkspecs\win32-msvc" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "QT_THREAD_SUPPORT" /D "QT_DEBUG" /FD /GZ -Zm200 /c
# ADD CPP /nologo /Gm /Zi /Od /Gf /Gy /I "." /I "$(QTDIR)\include" /I "G:\DCED2" /I "G:\DCED2\include" /I "$(QTDIR)\Qt\mkspecs\win32-msvc" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "QT_THREAD_SUPPORT" /D "QT_DEBUG" /FD /GZ -Zm200 /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /fo"LG_Debug/editor.res" /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 "qt-mt.lib" "qtmain.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "imm32.lib" "winmm.lib" "wsock32.lib" "winspool.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "imm32.lib" "winmm.lib" "wsock32.lib" "winspool.lib" /nologo /subsystem:windows /debug /machine:IX86 /nodefaultlib:"libc.lib" /nodefaultlib:"libcd.lib" /pdbtype:sept /libpath:"$(QTDIR)\lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 "qt-mt.lib" "qtmain.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "imm32.lib" "winmm.lib" "wsock32.lib" "winspool.lib" "kernel32.lib" "user32.lib" "gdi32.lib" "comdlg32.lib" "advapi32.lib" "shell32.lib" "ole32.lib" "oleaut32.lib" "uuid.lib" "imm32.lib" "winmm.lib" "wsock32.lib" "winspool.lib" /nologo /subsystem:windows /pdb:"LG_Debug/LG_DCED2.pdb" /debug /machine:IX86 /nodefaultlib:"libc.lib" /nodefaultlib:"libcd.lib" /out:"LG_Debug/LG_DCED2.exe" /pdbtype:sept /libpath:"$(QTDIR)\lib"
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "DCED2 - Win32 Release"
# Name "DCED2 - Win32 Debug"
# Name "DCED2 - Win32 LG Release"
# Name "DCED2 - Win32 LG Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=src\aboutdialog.cpp
# End Source File
# Begin Source File

SOURCE=.\src\addobjectdialog.cpp
# End Source File
# Begin Source File

SOURCE=.\src\colorwidget.cpp
# End Source File
# Begin Source File

SOURCE=.\src\documentoverview.cpp
# End Source File
# Begin Source File

SOURCE=.\src\documentwidget.cpp
# End Source File
# Begin Source File

SOURCE=.\src\globaldefs.cpp
# End Source File
# Begin Source File

SOURCE=.\src\mafiasyntax.cpp
# End Source File
# Begin Source File

SOURCE=src\main.cpp
# End Source File
# Begin Source File

SOURCE=src\mainwidget.cpp
# End Source File
# Begin Source File

SOURCE=.\src\MLWrapper.cpp
# End Source File
# Begin Source File

SOURCE=.\src\objectlist.cpp
# End Source File
# Begin Source File

SOURCE=.\src\objecttypes.cpp
# End Source File
# Begin Source File

SOURCE=src\objectwidget.cpp
# End Source File
# Begin Source File

SOURCE=.\src\preferencesdialog.cpp
# End Source File
# Begin Source File

SOURCE=.\src\propertylist.cpp
# End Source File
# Begin Source File

SOURCE=.\src\propertynamelist.cpp
# End Source File
# Begin Source File

SOURCE=.\src\questiondialog.cpp
# End Source File
# Begin Source File

SOURCE=.\src\scenepropertiesdialog.cpp
# End Source File
# Begin Source File

SOURCE=src\scriptmainwindow.cpp
# End Source File
# Begin Source File

SOURCE=src\scriptwidget.cpp
# End Source File
# Begin Source File

SOURCE=src\scriptworkspace.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=include\aboutdialog.h

!IF  "$(CFG)" == "DCED2 - Win32 Release"

USERDEP__ABOUT="$(QTDIR)\bin\moc.exe"	
# Begin Custom Build - Moc'ing include\aboutdialog.h...
InputPath=include\aboutdialog.h

"moc\moc_aboutdialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\aboutdialog.h -o moc\moc_aboutdialog.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 Debug"

USERDEP__ABOUT="$(QTDIR)\bin\moc.exe"	
# Begin Custom Build - Moc'ing include\aboutdialog.h...
InputPath=include\aboutdialog.h

"include\moc_aboutdialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\aboutdialog.h -o include\moc_aboutdialog.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Release"

USERDEP__ABOUT="$(QTDIR)\bin\moc.exe"	
# Begin Custom Build - Moc'ing include\aboutdialog.h...
InputPath=include\aboutdialog.h

"moc\moc_aboutdialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\aboutdialog.h -o moc\moc_aboutdialog.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Debug"

USERDEP__ABOUT="$(QTDIR)\bin\moc.exe"	
# Begin Custom Build - Moc'ing include\aboutdialog.h...
InputPath=include\aboutdialog.h

"include\moc_aboutdialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\aboutdialog.h -o include\moc_aboutdialog.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\include\addobjectdialog.h

!IF  "$(CFG)" == "DCED2 - Win32 Release"

# Begin Custom Build - Moc'ing include\addobjectdialog.h...
InputPath=.\include\addobjectdialog.h

"moc\moc_addobjectdialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\addobjectdialog.h -o moc\moc_addobjectdialog.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 Debug"

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Release"

# Begin Custom Build - Moc'ing include\addobjectdialog.h...
InputPath=.\include\addobjectdialog.h

"moc\moc_addobjectdialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\addobjectdialog.h -o moc\moc_addobjectdialog.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\include\classbrowserinterface.h
# End Source File
# Begin Source File

SOURCE=.\include\colorwidget.h

!IF  "$(CFG)" == "DCED2 - Win32 Release"

# Begin Custom Build - Moc'ing include\colorwidget.h...
InputPath=.\include\colorwidget.h

"moc\moc_colorwidget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\colorwidget.h -o moc\moc_colorwidget.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 Debug"

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Release"

# Begin Custom Build - Moc'ing colorwidget.h...
InputPath=.\include\colorwidget.h

"moc\moc_colorwidget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\colorwidget.h -o moc\moc_colorwidget.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\include\Datablock.h
# End Source File
# Begin Source File

SOURCE=.\include\documentoverview.h

!IF  "$(CFG)" == "DCED2 - Win32 Release"

# Begin Custom Build - Moc'ing include\documentoverview.h...
InputPath=.\include\documentoverview.h

"./moc/moc_documentoverview.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc ./include/documentoverview.h -o ./moc/moc_documentoverview.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 Debug"

# Begin Custom Build - Moc'ing include\documentoverview.h...
InputPath=.\include\documentoverview.h

"moc\moc_documentoverview.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\documentoverview.h -o moc\moc_documentoverview.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Release"

# Begin Custom Build - Moc'ing documentoverview.h...
InputPath=.\include\documentoverview.h

"./moc/moc_documentoverview.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc ./include/documentoverview.h -o ./moc/moc_documentoverview.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Debug"

# Begin Custom Build - Moc'ing include\documentoverview.h...
InputPath=.\include\documentoverview.h

"moc\moc_documentoverview.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc include\documentoverview.h -o moc\moc_documentoverview.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\include\documentwidget.h

!IF  "$(CFG)" == "DCED2 - Win32 Release"

# Begin Custom Build - Moc'ing include\documentwidget.h...
InputPath=.\include\documentwidget.h

"moc\moc_documentwidget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\documentwidget.h -o moc\moc_documentwidget.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 Debug"

# Begin Custom Build - Moc'ing include\documentwidget.h...
InputPath=.\include\documentwidget.h

"moc\moc_documentwidget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\documentwidget.h -o moc\moc_documentwidget.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Release"

# Begin Custom Build - Moc'ing documentwidget.h...
InputPath=.\include\documentwidget.h

"moc\moc_documentwidget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\documentwidget.h -o moc\moc_documentwidget.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Debug"

# Begin Custom Build - Moc'ing include\documentwidget.h...
InputPath=.\include\documentwidget.h

"moc\moc_documentwidget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc include\documentwidget.h -o moc\moc_documentwidget.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\include\globaldefs.h
# End Source File
# Begin Source File

SOURCE=.\include\Helper.h
# End Source File
# Begin Source File

SOURCE=.\include\mafiasyntax.h
# End Source File
# Begin Source File

SOURCE=include\mainwidget.h

!IF  "$(CFG)" == "DCED2 - Win32 Release"

USERDEP__MAINW="$(QTDIR)\bin\moc.exe"	
# Begin Custom Build - Moc'ing include\mainwidget.h...
InputPath=include\mainwidget.h

"moc\moc_mainwidget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\mainwidget.h -o moc\moc_mainwidget.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 Debug"

USERDEP__MAINW="$(QTDIR)\bin\moc.exe"	
# Begin Custom Build - Moc'ing include\mainwidget.h...
InputPath=include\mainwidget.h

"include\moc_mainwidget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\mainwidget.h -o include\moc_mainwidget.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Release"

USERDEP__MAINW="$(QTDIR)\bin\moc.exe"	
# Begin Custom Build - Moc'ing include\mainwidget.h...
InputPath=include\mainwidget.h

"moc\moc_mainwidget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\mainwidget.h -o moc\moc_mainwidget.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Debug"

USERDEP__MAINW="$(QTDIR)\bin\moc.exe"	
# Begin Custom Build - Moc'ing include\mainwidget.h...
InputPath=include\mainwidget.h

"include\moc_mainwidget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\mainwidget.h -o include\moc_mainwidget.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\include\MLWrapper.h

!IF  "$(CFG)" == "DCED2 - Win32 Release"

# Begin Custom Build - Moc'ing include\MLWrapper.h...
InputPath=.\include\MLWrapper.h

"moc/moc_MLWrapper.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include/MLWrapper.h -o moc/moc_MLWrapper.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 Debug"

# Begin Custom Build - Moc'ing include\MLWrapper.h...
InputPath=.\include\MLWrapper.h

"moc\moc_MLWrapper.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\MLWrapper.h -o moc\moc_MLWrapper.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Release"

# Begin Custom Build - Moc'ing MLWrapper.h...
InputPath=.\include\MLWrapper.h

"moc/moc_MLWrapper.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include/MLWrapper.h -o moc/moc_MLWrapper.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Debug"

# Begin Custom Build - Moc'ing include\MLWrapper.h...
InputPath=.\include\MLWrapper.h

"moc\moc_MLWrapper.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc include\MLWrapper.h -o moc\moc_MLWrapper.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\include\objecticons.h
# End Source File
# Begin Source File

SOURCE=.\include\objectlist.h

!IF  "$(CFG)" == "DCED2 - Win32 Release"

# Begin Custom Build - Moc'ing include\objectlist.h...
InputPath=.\include\objectlist.h

"moc\moc_objectlist.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\objectlist.h -o moc\moc_objectlist.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 Debug"

# Begin Custom Build - Moc'ing include\objectlist.h...
InputPath=.\include\objectlist.h

"moc\moc_objectlist.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc include\objectlist.h -o moc\moc_objectlist.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Release"

# Begin Custom Build - Moc'ing objectlist.h...
InputPath=.\include\objectlist.h

"moc\moc_objectlist.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\objectlist.h -o moc\moc_objectlist.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Debug"

# Begin Custom Build - Moc'ing include\objectlist.h...
InputPath=.\include\objectlist.h

"moc\moc_objectlist.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc include\objectlist.h -o moc\moc_objectlist.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\include\objecttypes.h
# End Source File
# Begin Source File

SOURCE=include\objectwidget.h

!IF  "$(CFG)" == "DCED2 - Win32 Release"

USERDEP__OBJEC="$(QTDIR)\bin\moc.exe"	
# Begin Custom Build - Moc'ing include\objectwidget.h...
InputPath=include\objectwidget.h

"moc\moc_objectwidget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\objectwidget.h -o moc\moc_objectwidget.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 Debug"

USERDEP__OBJEC="$(QTDIR)\bin\moc.exe"	
# Begin Custom Build - Moc'ing include\objectwidget.h...
InputPath=include\objectwidget.h

"include\moc_objectwidget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\objectwidget.h -o include\moc_objectwidget.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Release"

USERDEP__OBJEC="$(QTDIR)\bin\moc.exe"	
# Begin Custom Build - Moc'ing include\objectwidget.h...
InputPath=include\objectwidget.h

"moc\moc_objectwidget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\objectwidget.h -o moc\moc_objectwidget.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Debug"

USERDEP__OBJEC="$(QTDIR)\bin\moc.exe"	
# Begin Custom Build - Moc'ing include\objectwidget.h...
InputPath=include\objectwidget.h

"include\moc_objectwidget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\objectwidget.h -o include\moc_objectwidget.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\include\preferencesdialog.h

!IF  "$(CFG)" == "DCED2 - Win32 Release"

# Begin Custom Build - Moc'ing include\preferencesdialog.h...
InputPath=.\include\preferencesdialog.h

"./moc/moc_preferencesdialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc ./include/preferencesdialog.h -o ./moc/moc_preferencesdialog.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 Debug"

# Begin Custom Build - Moc'ing include\preferencesdialog.h...
InputPath=.\include\preferencesdialog.h

"moc\moc_preferencesdialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\preferencesdialog.h -o moc\moc_preferencesdialog.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Release"

# Begin Custom Build - Moc'ing preferencesdialog.h...
InputPath=.\include\preferencesdialog.h

"./moc/moc_preferencesdialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc ./include/preferencesdialog.h -o ./moc/moc_preferencesdialog.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Debug"

# Begin Custom Build - Moc'ing include\preferencesdialog.h...
InputPath=.\include\preferencesdialog.h

"moc\moc_preferencesdialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	moc include\preferencesdialog.h -o moc\moc_preferencesdialog.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\include\propertylist.h

!IF  "$(CFG)" == "DCED2 - Win32 Release"

# Begin Custom Build - Moc'ing include\propertylist.h...
InputPath=.\include\propertylist.h

"./moc/moc_propertylist.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc ./include/propertylist.h -o ./moc/moc_propertylist.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 Debug"

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Release"

# Begin Custom Build - Moc'ing propertylist.h...
InputPath=.\include\propertylist.h

"./moc/moc_propertylist.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc ./include/propertylist.h -o ./moc/moc_propertylist.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\include\propertynamelist.h

!IF  "$(CFG)" == "DCED2 - Win32 Release"

# Begin Custom Build - Moc'ing include\propertynamelist.h...
InputPath=.\include\propertynamelist.h

"./moc/moc_propertynamelist.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc ./include/propertynamelist.h -o ./moc/moc_propertynamelist.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 Debug"

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Release"

# Begin Custom Build - Moc'ing propertynamelist.h...
InputPath=.\include\propertynamelist.h

"./moc/moc_propertynamelist.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc ./include/propertynamelist.h -o ./moc/moc_propertynamelist.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\include\questiondialog.h

!IF  "$(CFG)" == "DCED2 - Win32 Release"

# Begin Custom Build - Moc'ing include\questiondialog.h...
InputPath=.\include\questiondialog.h

"./moc/moc_questiondialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc.exe ./include/questiondialog.h -o ./moc/moc_questiondialog.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 Debug"

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Release"

# Begin Custom Build - Moc'ing questiondialog.h...
InputPath=.\include\questiondialog.h

"./moc/moc_questiondialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc.exe ./include/questiondialog.h -o ./moc/moc_questiondialog.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\include\Scene2.h
# End Source File
# Begin Source File

SOURCE=.\include\scenepropertiesdialog.h

!IF  "$(CFG)" == "DCED2 - Win32 Release"

# Begin Custom Build - Moc'ing include\scenepropertiesdialog.h...
InputPath=.\include\scenepropertiesdialog.h

".\moc\moc_scenepropertiesdialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc .\include\scenepropertiesdialog.h -o .\moc\moc_scenepropertiesdialog.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 Debug"

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Release"

# Begin Custom Build - Moc'ing include\scenepropertiesdialog.h...
InputPath=.\include\scenepropertiesdialog.h

".\moc\moc_scenepropertiesdialog.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc .\include\scenepropertiesdialog.h -o .\moc\moc_scenepropertiesdialog.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=include\scriptmainwindow.h

!IF  "$(CFG)" == "DCED2 - Win32 Release"

USERDEP__SCRIP="$(QTDIR)\bin\moc.exe"	
# Begin Custom Build - Moc'ing include\scriptmainwindow.h...
InputPath=include\scriptmainwindow.h

"moc\moc_scriptmainwindow.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\scriptmainwindow.h -o moc\moc_scriptmainwindow.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 Debug"

USERDEP__SCRIP="$(QTDIR)\bin\moc.exe"	
# Begin Custom Build - Moc'ing include\scriptmainwindow.h...
InputPath=include\scriptmainwindow.h

"include\moc_scriptmainwindow.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\scriptmainwindow.h -o include\moc_scriptmainwindow.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Release"

USERDEP__SCRIP="$(QTDIR)\bin\moc.exe"	
# Begin Custom Build - Moc'ing include\scriptmainwindow.h...
InputPath=include\scriptmainwindow.h

"moc\moc_scriptmainwindow.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\scriptmainwindow.h -o moc\moc_scriptmainwindow.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Debug"

USERDEP__SCRIP="$(QTDIR)\bin\moc.exe"	
# Begin Custom Build - Moc'ing include\scriptmainwindow.h...
InputPath=include\scriptmainwindow.h

"include\moc_scriptmainwindow.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\scriptmainwindow.h -o include\moc_scriptmainwindow.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=include\scriptwidget.h

!IF  "$(CFG)" == "DCED2 - Win32 Release"

USERDEP__SCRIPT="$(QTDIR)\bin\moc.exe"	
# Begin Custom Build - Moc'ing include\scriptwidget.h...
InputPath=include\scriptwidget.h

"moc\moc_scriptwidget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\scriptwidget.h -o moc\moc_scriptwidget.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 Debug"

USERDEP__SCRIPT="$(QTDIR)\bin\moc.exe"	
# Begin Custom Build - Moc'ing include\scriptwidget.h...
InputPath=include\scriptwidget.h

"include\moc_scriptwidget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\scriptwidget.h -o include\moc_scriptwidget.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Release"

USERDEP__SCRIPT="$(QTDIR)\bin\moc.exe"	
# Begin Custom Build - Moc'ing include\scriptwidget.h...
InputPath=include\scriptwidget.h

"moc\moc_scriptwidget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\scriptwidget.h -o moc\moc_scriptwidget.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Debug"

USERDEP__SCRIPT="$(QTDIR)\bin\moc.exe"	
# Begin Custom Build - Moc'ing include\scriptwidget.h...
InputPath=include\scriptwidget.h

"include\moc_scriptwidget.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\scriptwidget.h -o include\moc_scriptwidget.cpp

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=include\scriptworkspace.h

!IF  "$(CFG)" == "DCED2 - Win32 Release"

USERDEP__SCRIPTW="$(QTDIR)\bin\moc.exe"	
# Begin Custom Build - Moc'ing include\scriptworkspace.h...
InputPath=include\scriptworkspace.h

"moc\moc_scriptworkspace.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\scriptworkspace.h -o moc\moc_scriptworkspace.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 Debug"

USERDEP__SCRIPTW="$(QTDIR)\bin\moc.exe"	
# Begin Custom Build - Moc'ing include\scriptworkspace.h...
InputPath=include\scriptworkspace.h

"include\moc_scriptworkspace.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\scriptworkspace.h -o include\moc_scriptworkspace.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Release"

USERDEP__SCRIPTW="$(QTDIR)\bin\moc.exe"	
# Begin Custom Build - Moc'ing include\scriptworkspace.h...
InputPath=include\scriptworkspace.h

"moc\moc_scriptworkspace.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\scriptworkspace.h -o moc\moc_scriptworkspace.cpp

# End Custom Build

!ELSEIF  "$(CFG)" == "DCED2 - Win32 LG Debug"

USERDEP__SCRIPTW="$(QTDIR)\bin\moc.exe"	
# Begin Custom Build - Moc'ing include\scriptworkspace.h...
InputPath=include\scriptworkspace.h

"include\moc_scriptworkspace.cpp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	$(QTDIR)\bin\moc include\scriptworkspace.h -o include\moc_scriptworkspace.cpp

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\img\don.ICO
# End Source File
# Begin Source File

SOURCE=editor.rc
# End Source File
# End Group
# Begin Group "Translations"

# PROP Default_Filter "ts"
# Begin Source File

SOURCE=language\dced_cz.ts
# End Source File
# Begin Source File

SOURCE=language\dced_de.ts
# End Source File
# Begin Source File

SOURCE=language\dced_es.ts
# End Source File
# Begin Source File

SOURCE=language\dced_fr.ts
# End Source File
# End Group
# Begin Group "Generated"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\moc\moc_aboutdialog.cpp
# End Source File
# Begin Source File

SOURCE=.\moc\moc_addobjectdialog.cpp
# End Source File
# Begin Source File

SOURCE=.\moc\moc_colorwidget.cpp
# End Source File
# Begin Source File

SOURCE=.\moc\moc_documentoverview.cpp
# End Source File
# Begin Source File

SOURCE=.\moc\moc_documentwidget.cpp
# End Source File
# Begin Source File

SOURCE=.\moc\moc_mainwidget.cpp
# End Source File
# Begin Source File

SOURCE=.\moc\moc_MLWrapper.cpp
# End Source File
# Begin Source File

SOURCE=.\moc\moc_objectlist.cpp
# End Source File
# Begin Source File

SOURCE=.\moc\moc_objectwidget.cpp
# End Source File
# Begin Source File

SOURCE=.\moc\moc_preferencesdialog.cpp
# End Source File
# Begin Source File

SOURCE=.\moc\moc_propertylist.cpp
# End Source File
# Begin Source File

SOURCE=.\moc\moc_propertynamelist.cpp
# End Source File
# Begin Source File

SOURCE=.\moc\moc_questiondialog.cpp
# End Source File
# Begin Source File

SOURCE=.\moc\moc_scenepropertiesdialog.cpp
# End Source File
# Begin Source File

SOURCE=.\moc\moc_scriptmainwindow.cpp
# End Source File
# Begin Source File

SOURCE=.\moc\moc_scriptwidget.cpp
# End Source File
# Begin Source File

SOURCE=.\moc\moc_scriptworkspace.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\MafiaLib.lib
# End Source File
# End Target
# End Project
