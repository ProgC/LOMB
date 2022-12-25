Attribute VB_Name = "Module1"
Option Explicit
Public Declare Function BitBlt Lib "gdi32" (ByVal hDestDC As Long, ByVal x As Long, ByVal y As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal hSrcDC As Long, ByVal xSrc As Long, ByVal ySrc As Long, ByVal dwRop As Long) As Long
Public Declare Function TextOut Lib "gdi32" Alias "TextOutA" (ByVal hdc As Long, ByVal x As Long, ByVal y As Long, ByVal lpString As String, ByVal nCount As Long) As Long

Public Type TileProperty
    ImageNumber As Long     '�̹��� ��ȣ
    collision As Long       '�� �� �ְ� ����
    EventProperty As Long   '�̺�Ʈ ��ȣ
End Type

Public Type Mob
    mobID As Long '�� ��ȣ
    nRespwan As Long '������
    nX As Long '
    nY As Long '
End Type

Public Type NPC
    npcID As Long 'npc��ȣ
    nX As Long
    nY As Long
End Type

Public Type Map
   
    Layer(10, 10) As TileProperty
    nCountOfMob As Long '�� ����
    MobList() As Mob '���� 100���� �Ѿ�� �ʴ´�.
    
    nCountOfNPC As Long
    NpcList() As NPC
End Type

Public Type Stage
    startX As Long '�� �ε�� �÷��̾� ��ġ
    startY As Long
    endX As Long   '���� ������ �� �÷��̾� ��ġ
    endY As Long
    
    StageData(5, 5) As Map
End Type

