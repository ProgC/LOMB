Attribute VB_Name = "Module1"
Option Explicit
Public Declare Function BitBlt Lib "gdi32" (ByVal hDestDC As Long, ByVal x As Long, ByVal y As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal hSrcDC As Long, ByVal xSrc As Long, ByVal ySrc As Long, ByVal dwRop As Long) As Long
Public Declare Function TextOut Lib "gdi32" Alias "TextOutA" (ByVal hdc As Long, ByVal x As Long, ByVal y As Long, ByVal lpString As String, ByVal nCount As Long) As Long

Public Type TileProperty
    ImageNumber As Long     '이미지 번호
    collision As Long       '갈 수 있고 없고
    EventProperty As Long   '이벤트 번호
End Type

Public Type Mob
    mobID As Long '몹 번호
    nRespwan As Long '리스폰
    nX As Long '
    nY As Long '
End Type

Public Type NPC
    npcID As Long 'npc번호
    nX As Long
    nY As Long
End Type

Public Type Map
   
    Layer(10, 10) As TileProperty
    nCountOfMob As Long '몹 개수
    MobList() As Mob '몹은 100개가 넘어가지 않는다.
    
    nCountOfNPC As Long
    NpcList() As NPC
End Type

Public Type Stage
    startX As Long '맵 로드시 플레이어 위치
    startY As Long
    endX As Long   '맵이 끝났을 때 플레이어 위치
    endY As Long
    
    StageData(5, 5) As Map
End Type

