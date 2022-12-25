# Microsoft Developer Studio Project File - Name="LOMB" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=LOMB - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "LOMB.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "LOMB.mak" CFG="LOMB - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "LOMB - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "LOMB - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "LOMB - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /Zi /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR /YX /FD /c
# SUBTRACT CPP /O<none>
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 sdl.lib sdlmain.lib SDL_mixer.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /out:"bin/LOMB_R.exe"
# SUBTRACT LINK32 /nodefaultlib

!ELSEIF  "$(CFG)" == "LOMB - Win32 Debug"

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
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "_DEBUG"
# ADD RSC /l 0x412 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 sdl.lib sdlmain.lib SDL_mixer.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /out:"bin/LOMB.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "LOMB - Win32 Release"
# Name "LOMB - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AnimationFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\Collision.cpp
# End Source File
# Begin Source File

SOURCE=.\CreticalSection.cpp
# End Source File
# Begin Source File

SOURCE=.\Game.cpp
# End Source File
# Begin Source File

SOURCE=.\GameItem.cpp
# End Source File
# Begin Source File

SOURCE=.\GameMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\GameMonster.cpp
# End Source File
# Begin Source File

SOURCE=.\GameUI.cpp
# End Source File
# Begin Source File

SOURCE=.\Inventory.cpp
# End Source File
# Begin Source File

SOURCE=.\IScene.cpp
# End Source File
# Begin Source File

SOURCE=.\LevelUpDB.cpp
# End Source File
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# Begin Source File

SOURCE=.\Map.cpp
# End Source File
# Begin Source File

SOURCE=.\MusicPack.cpp
# End Source File
# Begin Source File

SOURCE=.\SceneEffect.cpp
# End Source File
# Begin Source File

SOURCE=.\Script.cpp
# End Source File
# Begin Source File

SOURCE=.\Skill.cpp
# End Source File
# Begin Source File

SOURCE=.\SoundPack.cpp
# End Source File
# Begin Source File

SOURCE=.\Sprite.cpp
# End Source File
# Begin Source File

SOURCE=.\SpritePack.cpp
# End Source File
# Begin Source File

SOURCE=.\Stage.cpp
# End Source File
# Begin Source File

SOURCE=.\TileProperty.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AnimationFrame.h
# End Source File
# Begin Source File

SOURCE=.\CreticalSection.h
# End Source File
# Begin Source File

SOURCE=.\Game.h
# End Source File
# Begin Source File

SOURCE=.\GameMenu.h
# End Source File
# Begin Source File

SOURCE=.\GameUI.h
# End Source File
# Begin Source File

SOURCE=.\global.h
# End Source File
# Begin Source File

SOURCE=.\Inventory.h
# End Source File
# Begin Source File

SOURCE=.\IScene.h
# End Source File
# Begin Source File

SOURCE=.\LevelUpDB.h
# End Source File
# Begin Source File

SOURCE=.\Map.h
# End Source File
# Begin Source File

SOURCE=.\MusicPack.h
# End Source File
# Begin Source File

SOURCE=.\SceneEffect.h
# End Source File
# Begin Source File

SOURCE=.\Script.h
# End Source File
# Begin Source File

SOURCE=.\Skill.h
# End Source File
# Begin Source File

SOURCE=.\SoundPack.h
# End Source File
# Begin Source File

SOURCE=.\Sprite.h
# End Source File
# Begin Source File

SOURCE=.\SpritePack.h
# End Source File
# Begin Source File

SOURCE=.\Stage.h
# End Source File
# Begin Source File

SOURCE=.\TileProperty.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\story.txt
# End Source File
# Begin Source File

SOURCE=".\¼³°è.txt"
# End Source File
# End Group
# Begin Group "Entity"

# PROP Default_Filter ""
# Begin Group "BossAmber"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Boss_Amber.cpp
# End Source File
# Begin Source File

SOURCE=.\Boss_Amber.h
# End Source File
# Begin Source File

SOURCE=.\BossAmberAction.cpp
# End Source File
# Begin Source File

SOURCE=.\BossAmberAction.h
# End Source File
# End Group
# Begin Group "PinkPig"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\PinkPig.cpp
# End Source File
# Begin Source File

SOURCE=.\PinkPig.h
# End Source File
# Begin Source File

SOURCE=.\PinkPigAction.cpp
# End Source File
# Begin Source File

SOURCE=.\PinkPigAction.h
# End Source File
# End Group
# Begin Group "Bullet"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Bullet.cpp
# End Source File
# Begin Source File

SOURCE=.\Bullet.h
# End Source File
# Begin Source File

SOURCE=.\Bullet_Amber.cpp
# End Source File
# Begin Source File

SOURCE=.\Bullet_Amber.h
# End Source File
# Begin Source File

SOURCE=.\Bullet_MagicBall.cpp
# End Source File
# Begin Source File

SOURCE=.\Bullet_MagicBall.h
# End Source File
# Begin Source File

SOURCE=.\Bullet_Pink_Pig.cpp
# End Source File
# Begin Source File

SOURCE=.\Bullet_Pink_Pig.h
# End Source File
# Begin Source File

SOURCE=.\BulletFactory.cpp
# End Source File
# Begin Source File

SOURCE=.\BulletFactory.h
# End Source File
# End Group
# Begin Group "BluePig"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\BluePig.cpp
# End Source File
# Begin Source File

SOURCE=.\BluePig.h
# End Source File
# Begin Source File

SOURCE=.\BluePigAction.cpp
# End Source File
# Begin Source File

SOURCE=.\BluePigAction.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\IEntity.cpp
# End Source File
# Begin Source File

SOURCE=.\IEntity.h
# End Source File
# Begin Source File

SOURCE=.\Item.cpp
# End Source File
# Begin Source File

SOURCE=.\Item.h
# End Source File
# Begin Source File

SOURCE=.\Kail.cpp
# End Source File
# Begin Source File

SOURCE=.\Kail.h
# End Source File
# Begin Source File

SOURCE=.\MonAi.cpp
# End Source File
# Begin Source File

SOURCE=.\MonAi.h
# End Source File
# Begin Source File

SOURCE=.\MonDefine.h
# End Source File
# Begin Source File

SOURCE=.\Monster.cpp
# End Source File
# Begin Source File

SOURCE=.\Monster.h
# End Source File
# Begin Source File

SOURCE=.\MonsterAI.cpp
# End Source File
# Begin Source File

SOURCE=.\MonsterAI.h
# End Source File
# Begin Source File

SOURCE=.\MoveableEntity.cpp
# End Source File
# Begin Source File

SOURCE=.\MoveableEntity.h
# End Source File
# Begin Source File

SOURCE=.\Npc.cpp
# End Source File
# Begin Source File

SOURCE=.\Npc.h
# End Source File
# End Group
# Begin Group "Font"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Han.cpp
# End Source File
# Begin Source File

SOURCE=.\HAN.H
# End Source File
# End Group
# Begin Group "GameDef"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CSpreadSheet.h
# End Source File
# Begin Source File

SOURCE=.\ItemData.cpp
# End Source File
# Begin Source File

SOURCE=.\ItemData.h
# End Source File
# Begin Source File

SOURCE=.\MobData.cpp
# End Source File
# Begin Source File

SOURCE=.\MobData.h
# End Source File
# End Group
# Begin Group "GameAIExample"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\KState.h
# End Source File
# End Group
# End Target
# End Project
