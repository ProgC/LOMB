VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "Comdlg32.ocx"
Begin VB.Form frmMain 
   Caption         =   "Legend of MagicBook"
   ClientHeight    =   8820
   ClientLeft      =   165
   ClientTop       =   855
   ClientWidth     =   11505
   LinkTopic       =   "Form1"
   ScaleHeight     =   588
   ScaleMode       =   3  '�ȼ�
   ScaleWidth      =   767
   StartUpPosition =   3  'Windows �⺻��
   Begin VB.CommandButton Command4 
      Caption         =   "Npc �����"
      Height          =   375
      Left            =   3000
      TabIndex        =   54
      Top             =   1320
      Width           =   1095
   End
   Begin VB.CommandButton Command3 
      Caption         =   "�� �����"
      Height          =   375
      Left            =   3000
      TabIndex        =   53
      Top             =   840
      Width           =   1095
   End
   Begin VB.PictureBox picPlayerEnd 
      AutoRedraw      =   -1  'True
      BorderStyle     =   0  '����
      Height          =   240
      Left            =   7920
      Picture         =   "frmMain.frx":0000
      ScaleHeight     =   16
      ScaleMode       =   3  '�ȼ�
      ScaleWidth      =   16
      TabIndex        =   50
      Top             =   2160
      Visible         =   0   'False
      Width           =   240
   End
   Begin VB.PictureBox picPlayerStart 
      AutoRedraw      =   -1  'True
      BorderStyle     =   0  '����
      Height          =   240
      Left            =   7920
      Picture         =   "frmMain.frx":0342
      ScaleHeight     =   16
      ScaleMode       =   3  '�ȼ�
      ScaleWidth      =   16
      TabIndex        =   49
      Top             =   1800
      Visible         =   0   'False
      Width           =   240
   End
   Begin MSComDlg.CommonDialog CommonDialog1 
      Left            =   3000
      Top             =   2040
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.Frame Frame3 
      Caption         =   "���"
      Height          =   3855
      Left            =   120
      TabIndex        =   28
      Top             =   4560
      Width           =   2775
      Begin VB.TextBox txtEvent 
         Height          =   270
         Left            =   1680
         TabIndex        =   52
         Top             =   960
         Width           =   615
      End
      Begin VB.OptionButton Option7 
         Caption         =   "�̺�Ʈ ��ȣ"
         Height          =   255
         Left            =   120
         TabIndex        =   51
         Top             =   960
         Width           =   1335
      End
      Begin VB.OptionButton Option6 
         Caption         =   "�÷��̾� �� ��ġ"
         Height          =   255
         Left            =   120
         TabIndex        =   42
         Top             =   3360
         Width           =   2175
      End
      Begin VB.OptionButton Option5 
         Caption         =   "�÷��̾� ���� ��ġ"
         Height          =   255
         Left            =   120
         TabIndex        =   41
         Top             =   3000
         Width           =   2175
      End
      Begin VB.ComboBox Combo2 
         Height          =   300
         Left            =   1200
         TabIndex        =   40
         Top             =   2400
         Width           =   1095
      End
      Begin VB.OptionButton Option4 
         Caption         =   "Npc ���"
         Height          =   255
         Left            =   120
         TabIndex        =   39
         Top             =   2400
         Width           =   1095
      End
      Begin VB.CheckBox chkRespwan 
         Caption         =   "�ڵ�����"
         Height          =   255
         Left            =   600
         TabIndex        =   34
         Top             =   2040
         Width           =   1335
      End
      Begin VB.ComboBox Combo1 
         Height          =   300
         Left            =   1440
         TabIndex        =   33
         Top             =   1680
         Width           =   855
      End
      Begin VB.OptionButton Option3 
         Caption         =   "�� ���"
         Height          =   255
         Left            =   120
         TabIndex        =   32
         Top             =   1680
         Width           =   1095
      End
      Begin VB.TextBox txtAtt 
         Height          =   270
         Left            =   1680
         TabIndex        =   31
         Top             =   600
         Width           =   615
      End
      Begin VB.OptionButton Option2 
         Caption         =   "�浹 �Ӽ�"
         Height          =   255
         Left            =   120
         TabIndex        =   30
         Top             =   600
         Width           =   1215
      End
      Begin VB.OptionButton Option1 
         Caption         =   "Ÿ�����"
         Height          =   255
         Left            =   120
         TabIndex        =   29
         Top             =   240
         Value           =   -1  'True
         Width           =   1215
      End
   End
   Begin VB.Timer Timer1 
      Enabled         =   0   'False
      Interval        =   30
      Left            =   3480
      Top             =   2040
   End
   Begin VB.CommandButton cmdDown 
      Caption         =   "��"
      Height          =   375
      Left            =   6000
      TabIndex        =   27
      Top             =   7080
      Width           =   375
   End
   Begin VB.CommandButton cmdUp 
      Caption         =   "��"
      Height          =   375
      Left            =   5880
      TabIndex        =   26
      Top             =   3360
      Width           =   375
   End
   Begin VB.CommandButton cmdRight 
      Caption         =   "��"
      Height          =   375
      Left            =   7800
      TabIndex        =   25
      Top             =   5280
      Width           =   375
   End
   Begin VB.CommandButton cmdLeft 
      Caption         =   "��"
      Height          =   375
      Left            =   3840
      TabIndex        =   24
      Top             =   5280
      Width           =   375
   End
   Begin VB.Frame Frame2 
      BackColor       =   &H00000000&
      BorderStyle     =   0  '����
      Caption         =   "Frame2"
      Height          =   3015
      Left            =   4320
      TabIndex        =   18
      Top             =   3840
      Width           =   3375
      Begin VB.PictureBox picMap 
         BorderStyle     =   0  '����
         Height          =   2400
         Left            =   480
         ScaleHeight     =   160
         ScaleMode       =   3  '�ȼ�
         ScaleWidth      =   160
         TabIndex        =   19
         Top             =   360
         Width           =   2400
      End
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Set"
      Height          =   375
      Left            =   3000
      TabIndex        =   16
      Top             =   360
      Width           =   1095
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Load"
      Height          =   375
      Left            =   10680
      TabIndex        =   9
      Top             =   240
      Width           =   735
   End
   Begin VB.PictureBox Picture1 
      AutoRedraw      =   -1  'True
      Height          =   375
      Left            =   4800
      ScaleHeight     =   315
      ScaleWidth      =   435
      TabIndex        =   8
      Top             =   360
      Visible         =   0   'False
      Width           =   495
   End
   Begin VB.PictureBox picMapTile 
      AutoRedraw      =   -1  'True
      BorderStyle     =   0  '����
      Height          =   5655
      Left            =   8400
      ScaleHeight     =   377
      ScaleMode       =   3  '�ȼ�
      ScaleWidth      =   160
      TabIndex        =   7
      Top             =   720
      Width           =   2400
   End
   Begin VB.Frame Frame1 
      Caption         =   "�� ����"
      Height          =   3855
      Left            =   120
      TabIndex        =   0
      Top             =   240
      Width           =   2775
      Begin VB.TextBox txtMapY 
         Enabled         =   0   'False
         Height          =   270
         Left            =   2160
         TabIndex        =   6
         Text            =   "10"
         Top             =   720
         Width           =   375
      End
      Begin VB.TextBox txtMapX 
         Enabled         =   0   'False
         Height          =   270
         Left            =   1680
         TabIndex        =   5
         Text            =   "10"
         Top             =   720
         Width           =   375
      End
      Begin VB.TextBox txtStageY 
         Enabled         =   0   'False
         Height          =   270
         Left            =   2160
         TabIndex        =   3
         Text            =   "5"
         Top             =   360
         Width           =   375
      End
      Begin VB.TextBox txtStageX 
         Enabled         =   0   'False
         Height          =   270
         Left            =   1680
         TabIndex        =   2
         Text            =   "5"
         Top             =   360
         Width           =   375
      End
      Begin VB.Label lblEndY 
         Height          =   255
         Left            =   720
         TabIndex        =   48
         Top             =   3480
         Width           =   495
      End
      Begin VB.Label lblEndX 
         Height          =   255
         Left            =   120
         TabIndex        =   47
         Top             =   3480
         Width           =   495
      End
      Begin VB.Label lblStartY 
         Height          =   255
         Left            =   720
         TabIndex        =   46
         Top             =   2880
         Width           =   495
      End
      Begin VB.Label lblStartX 
         Height          =   255
         Left            =   120
         TabIndex        =   45
         Top             =   2880
         Width           =   495
      End
      Begin VB.Label Label12 
         Caption         =   "�÷��̾� ���� ��ġ"
         Height          =   255
         Left            =   120
         TabIndex        =   44
         Top             =   3240
         Width           =   1695
      End
      Begin VB.Label Label11 
         Caption         =   "�÷��̾� ���� ��ġ"
         Height          =   255
         Left            =   120
         TabIndex        =   43
         Top             =   2640
         Width           =   1695
      End
      Begin VB.Label lblNpc 
         Alignment       =   1  '������ ����
         Caption         =   "0"
         Height          =   255
         Left            =   840
         TabIndex        =   38
         Top             =   2280
         Width           =   1335
      End
      Begin VB.Label Label10 
         Caption         =   "NPC����"
         Height          =   255
         Left            =   120
         TabIndex        =   37
         Top             =   2280
         Width           =   1095
      End
      Begin VB.Label lblMob 
         Alignment       =   1  '������ ����
         Caption         =   "0"
         Height          =   255
         Left            =   840
         TabIndex        =   36
         Top             =   1920
         Width           =   1335
      End
      Begin VB.Label Label9 
         Caption         =   "������"
         Height          =   255
         Left            =   120
         TabIndex        =   35
         Top             =   1920
         Width           =   855
      End
      Begin VB.Label lblStageIndexY 
         BorderStyle     =   1  '���� ����
         Height          =   255
         Left            =   1680
         TabIndex        =   23
         Top             =   1560
         Width           =   495
      End
      Begin VB.Label lblStageIndexX 
         BorderStyle     =   1  '���� ����
         Height          =   255
         Left            =   1680
         TabIndex        =   22
         Top             =   1200
         Width           =   495
      End
      Begin VB.Label Label8 
         Caption         =   "�������� ��ȣ"
         Height          =   255
         Left            =   120
         TabIndex        =   21
         Top             =   1200
         Width           =   1215
      End
      Begin VB.Label Label2 
         Caption         =   "�� ������ :"
         Height          =   255
         Left            =   120
         TabIndex        =   4
         Top             =   720
         Width           =   1095
      End
      Begin VB.Label Label1 
         Caption         =   "�������� ������ :"
         Height          =   255
         Left            =   120
         TabIndex        =   1
         Top             =   360
         Width           =   1575
      End
   End
   Begin VB.Label Label7 
      Caption         =   "��"
      Height          =   255
      Left            =   4080
      TabIndex        =   20
      Top             =   3480
      Width           =   1095
   End
   Begin VB.Label Label6 
      Caption         =   "Ÿ�� ��Ʈ"
      Height          =   255
      Left            =   8280
      TabIndex        =   17
      Top             =   360
      Width           =   1095
   End
   Begin VB.Label lblImgNumber 
      Height          =   255
      Left            =   6960
      TabIndex        =   15
      Top             =   360
      Width           =   975
   End
   Begin VB.Label Label5 
      Caption         =   "�̹��� ��ȣ :"
      Height          =   255
      Left            =   5760
      TabIndex        =   14
      Top             =   360
      Width           =   1215
   End
   Begin VB.Label lblTileY 
      Height          =   255
      Left            =   6960
      TabIndex        =   13
      Top             =   1200
      Width           =   975
   End
   Begin VB.Label lblTileX 
      Height          =   255
      Left            =   6960
      TabIndex        =   12
      Top             =   840
      Width           =   975
   End
   Begin VB.Label Label4 
      Caption         =   "�̹��� IDY :"
      Height          =   255
      Left            =   5760
      TabIndex        =   11
      Top             =   1200
      Width           =   1215
   End
   Begin VB.Label Label3 
      Caption         =   "�̹��� IDX :"
      Height          =   255
      Left            =   5760
      TabIndex        =   10
      Top             =   840
      Width           =   1215
   End
   Begin VB.Menu mnuMenu 
      Caption         =   "Menu"
      Begin VB.Menu mnuOpen 
         Caption         =   "File Open Map"
      End
      Begin VB.Menu mnuSave 
         Caption         =   "File Save Map"
      End
      Begin VB.Menu mnuFileOpenBossMap 
         Caption         =   "File Open BossMap"
      End
      Begin VB.Menu mnuFileSaveBossMap 
         Caption         =   "File Save BossMap"
      End
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private g_Stage As Stage
Private g_StageX As Integer
Private g_StageY As Integer

Private Sub cmdDown_Click()
g_StageY = g_StageY + 1
If g_StageY >= 5 Then g_StageY = 4
lblStageIndexY = g_StageY
End Sub

Private Sub cmdLeft_Click()
g_StageX = g_StageX - 1
If g_StageX < 0 Then g_StageX = 0
lblStageIndexX = g_StageX
End Sub

Private Sub cmdRight_Click()
g_StageX = g_StageX + 1
If g_StageX >= 5 Then g_StageX = 4
lblStageIndexX = g_StageX

End Sub

Private Sub cmdUp_Click()
g_StageY = g_StageY - 1
If g_StageY < 0 Then g_StageY = 0

lblStageIndexY = g_StageY
End Sub

Private Sub Command1_Click()
Dim x As Integer
Dim y As Integer

Dim i As Integer
i = 1

'�� �̹����� ��� �ҷ��� picMapTile�� �Ѹ���.
Dim filename

For y = 0 To 126 - 1
    filename = i & ".bmp"
    Picture1.Picture = LoadPicture(App.Path + "\" + filename)
    picMapTile.PaintPicture Picture1, Int(y Mod 10) * 16, Int(y / 10) * 16, 16, 16, 0, 0, 16, 16, vbSrcCopy
    
    i = i + 1
Next y

g_StageX = 0
g_StageY = 0

lblStageIndexX.Caption = g_StageX
lblStageIndexY.Caption = g_StageY

Timer1.Enabled = True

End Sub

Private Sub Command2_Click()
Dim isx As Integer
Dim isy As Integer

Dim imx As Integer
Dim imy As Integer

For isy = 0 To 4
    For isx = 0 To 4
        For imy = 0 To 9
            For imx = 0 To 9
                With g_Stage.StageData(isy, isx)
                    With .Layer(imy, imx)
                        .ImageNumber = 73
                        .collision = 1 '�� �� ����
                        .EventProperty = 0 '�ƹ��͵� ����
                    End With
                End With
            Next imx
        Next imy
    Next isx
Next isy

End Sub

Private Sub Command3_Click()
'���� ���õ� �ʿ��� ���� ��� �����.
With g_Stage.StageData(g_StageY, g_StageX)
    .nCountOfMob = 0
    ReDim .MobList(0) As Mob
End With
End Sub

Private Sub Command4_Click()
'���� ���õ� �ʿ��� ���� ��� �����.
With g_Stage.StageData(g_StageY, g_StageX)
    .nCountOfNPC = 0
    ReDim .NpcList(0) As NPC
End With
End Sub

Private Sub Form_Load()
g_StageX = 0
g_StageY = 0

Combo1.AddItem "ǪǪ"
Combo1.AddItem "���"
Combo1.AddItem "��ũ�Ǳ�"
Combo1.AddItem "ȣ�պ�_����"
Combo1.AddItem "����Ǳ�"

Combo2.AddItem "���̽�"
Combo2.AddItem "���Ͼ�"
Combo2.AddItem "�̾�"
Combo2.AddItem "�Ƹ�Ƽ�"
Combo2.AddItem "���ò�"
Combo2.AddItem "���������"
End Sub

Private Sub mnuOpen_Click()
CommonDialog1.ShowOpen

Open CommonDialog1.filename For Binary As #1
    
    Dim isx As Integer
    Dim isy As Integer
    
    Dim imx As Integer
    Dim imy As Integer
    Dim i As Integer
    
    Get #1, , g_Stage.startX
    Get #1, , g_Stage.startY
    Get #1, , g_Stage.endX
    Get #1, , g_Stage.endY
    
    lblStartX.Caption = g_Stage.startX
    lblStartY.Caption = g_Stage.startY
    lblEndX.Caption = g_Stage.endX
    lblEndY.Caption = g_Stage.endY
        
    For isy = 0 To 4
        For isx = 0 To 4
            For imy = 0 To 9
                For imx = 0 To 9
                    With g_Stage.StageData(isy, isx)
                        With .Layer(imy, imx)
                            Get #1, , .ImageNumber
                            Get #1, , .collision
                            Get #1, , .EventProperty
                        End With
                    End With
                Next imx
            Next imy
            
            With g_Stage.StageData(isy, isx)
                Get #1, , .nCountOfMob
                ReDim Preserve .MobList(.nCountOfMob) As Mob
                
                For i = 0 To .nCountOfMob - 1
                    Get #1, , .MobList(i).mobID
                    Get #1, , .MobList(i).nRespwan
                    Get #1, , .MobList(i).nX
                    Get #1, , .MobList(i).nY
                Next i
            End With
            
             'NPC ����
            With g_Stage.StageData(isy, isx)
                Get #1, , .nCountOfNPC
                ReDim Preserve .NpcList(.nCountOfNPC) As NPC
                
                For i = 0 To .nCountOfNPC - 1
                    Get #1, , .NpcList(i).npcID
                    Get #1, , .NpcList(i).nX
                    Get #1, , .NpcList(i).nY
                Next i
            End With
        Next isx
    Next isy
Close #1
End Sub

Private Sub mnuSave_Click()
CommonDialog1.ShowSave

Open CommonDialog1.filename For Binary As #1
    
    Dim isx As Integer
    Dim isy As Integer
    
    Dim imx As Integer
    Dim imy As Integer
    
    Dim i As Integer
        
    Put #1, , g_Stage.startX
    Put #1, , g_Stage.startY
    Put #1, , g_Stage.endX
    Put #1, , g_Stage.endY
    
    For isy = 0 To 4
        For isx = 0 To 4
            For imy = 0 To 9
                For imx = 0 To 9
                    With g_Stage.StageData(isy, isx)
                        With .Layer(imy, imx)
                            Put #1, , .ImageNumber
                            Put #1, , .collision
                            Put #1, , .EventProperty
                        End With
                    End With
                Next imx
            Next imy
            
            '�ش�� �� ����
            With g_Stage.StageData(isy, isx)
                Put #1, , .nCountOfMob
                For i = 0 To .nCountOfMob - 1
                    Put #1, , .MobList(i).mobID
                    Put #1, , .MobList(i).nRespwan
                    Put #1, , .MobList(i).nX
                    Put #1, , .MobList(i).nY
                Next i
            End With
            
            'NPC ����
            With g_Stage.StageData(isy, isx)
                Put #1, , .nCountOfNPC
                For i = 0 To .nCountOfNPC - 1
                    Put #1, , .NpcList(i).npcID
                    Put #1, , .NpcList(i).nX
                    Put #1, , .NpcList(i).nY
                Next i
            End With
        Next isx
    Next isy
Close #1
End Sub

Private Sub picMap_MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single)

'Ÿ�� ���
Dim sx
Dim sy

sx = Int(x / 16)
sy = Int(y / 16)
    
If Option1.Value = True Then
    With g_Stage.StageData(g_StageY, g_StageX)
        .Layer(sy, sx).ImageNumber = Val(lblImgNumber.Caption)
    End With
End If

If Option2.Value = True Then
    With g_Stage.StageData(g_StageY, g_StageX)
        .Layer(sy, sx).collision = Val(txtAtt.Text)
    End With
End If

If Option7.Value = True Then '�̺�Ʈ ����
    With g_Stage.StageData(g_StageY, g_StageX)
        .Layer(sy, sx).EventProperty = Val(txtEvent.Text)
    End With
End If


If Option3.Value = True Then
    '���� ��ǥ�� �����Ѵ�.
    With g_Stage.StageData(g_StageY, g_StageX)
        '�� �ϳ� �߰�
                
        ReDim Preserve .MobList(.nCountOfMob) As Mob
        .MobList(.nCountOfMob).nX = (g_StageX * 160) + x
        .MobList(.nCountOfMob).nY = (g_StageY * 160) + y
        .MobList(.nCountOfMob).mobID = Combo1.ListIndex
        .nCountOfMob = .nCountOfMob + 1
    End With
End If

If Option4.Value = True Then
    '���� ��ǥ�� NPC�����Ѵ�.
    With g_Stage.StageData(g_StageY, g_StageX)
        '�� �ϳ� �߰�
                
        ReDim Preserve .NpcList(.nCountOfNPC) As NPC
        .NpcList(.nCountOfNPC).nX = (g_StageX * 160) + x
        .NpcList(.nCountOfNPC).nY = (g_StageY * 160) + y
        .NpcList(.nCountOfNPC).npcID = Combo2.ListIndex
        .nCountOfNPC = .nCountOfNPC + 1
    End With
End If

'�÷��̾� ���� ��ġ ����
If Option5.Value = True Then
    g_Stage.startX = g_StageX * 160 + x
    g_Stage.startY = g_StageY * 160 + y
    
    lblStartX.Caption = g_Stage.startX
    lblStartY.Caption = g_Stage.startY
End If

If Option6.Value = True Then
    g_Stage.endX = g_StageX * 160 + x
    g_Stage.endY = g_StageY * 160 + y
    
    lblEndX.Caption = g_Stage.endX
    lblEndY.Caption = g_Stage.endY
End If

End Sub

Private Sub picMapTile_MouseDown(Button As Integer, Shift As Integer, x As Single, y As Single)
lblTileX.Caption = Int(x / 16)
lblTileY.Caption = Int(y / 16)

lblImgNumber.Caption = (Val(lblTileX.Caption) + Val(lblTileY.Caption) * 10) + 1
End Sub

Private Sub Timer1_Timer()

'draw map
Dim imx As Integer
Dim imy As Integer

Dim x
Dim y

Dim ImgNumber As Long

For imy = 0 To 9
    For imx = 0 To 9
        With g_Stage.StageData(g_StageY, g_StageX)
            
        
            ImgNumber = .Layer(imy, imx).ImageNumber - 1
                        
            x = Int(ImgNumber Mod 10) * 16
            y = Int(ImgNumber / 10) * 16
            
         '   picMap.PaintPicture picMapTile, imx * 16, imy * 16, 16, 16, x, y, 16, 16, vbSrcCopy
            BitBlt picMap.hdc, imx * 16, imy * 16, 16, 16, picMapTile.hdc, x, y, vbSrcCopy
            
            '�浹�� Ȱ��ȭ �Ǹ� ��ȣ �ѷ��ش�.
            If Option2.Value = True Then
                With g_Stage.StageData(g_StageY, g_StageX)
                    TextOut picMap.hdc, imx * 16, imy * 16, Str(.Layer(imy, imx).collision), Len(Str(.Layer(imy, imx).collision))
                End With
            End If
            
            If Option7.Value = True Then
                With g_Stage.StageData(g_StageY, g_StageX)
                    TextOut picMap.hdc, imx * 16, imy * 16, Str(.Layer(imy, imx).EventProperty), Len(Str(.Layer(imy, imx).EventProperty))
                End With
            End If
            
            
        End With
    Next imx
Next imy

Dim i As Integer


'�� ���
'If Option3.Value = True Then
    With g_Stage.StageData(g_StageY, g_StageX)
        lblMob.Caption = .nCountOfMob
    
        picMap.ForeColor = RGB(0, 0, 255)
        For i = 0 To .nCountOfMob - 1
            TextOut picMap.hdc, .MobList(i).nX - (g_StageX * 160), .MobList(i).nY - (g_StageY * 160), Combo1.List(.MobList(i).mobID), LenB(Combo1.List(.MobList(i).mobID))
        Next i
    End With
'End If

'If Option4.Value = True Then
    With g_Stage.StageData(g_StageY, g_StageX)
        lblNpc.Caption = .nCountOfNPC
        
        picMap.ForeColor = RGB(255, 0, 0)
        For i = 0 To .nCountOfNPC - 1
            TextOut picMap.hdc, .NpcList(i).nX - (g_StageX * 160), .NpcList(i).nY - (g_StageY * 160), Combo2.List(.NpcList(i).npcID), LenB(Combo2.List(.NpcList(i).npcID))
        Next i
    End With

'End If

BitBlt picMap.hdc, g_Stage.startX - (g_StageX * 160), g_Stage.startY - (g_StageY * 160), 16, 16, picPlayerStart.hdc, 0, 0, vbSrcAnd
BitBlt picMap.hdc, g_Stage.endX - (g_StageX * 160), g_Stage.endY - (g_StageY * 160), 16, 16, picPlayerEnd.hdc, 0, 0, vbSrcAnd
End Sub
