#include "pch.h"
#include "CKDHScene.h"
#include "CKDHPlayer.h"
#include "CKDHLine.h"
#include "CAbstractFactory.h"
#include "CObjMgr.h"
#include "CHexaPadManager.h"
#include "CSoundMgr.h"
#include "CKeyMgr.h"
#include "CSceneMgr.h"

bool g_bRotateAngle = false;
float g_RevolAngle = 0.f;

CKDHScene::CKDHScene()
{
}

CKDHScene::~CKDHScene()
{
	Release();
}

void CKDHScene::Initialize()
{
	CObj* player = CAbstractFactory<CKDHPlayer>::Create();
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, player);

	CObj* line1 = CAbstractFactory<CKDHLine>::Create();
	static_cast<CKDHLine*>(line1)->SetRotateAngle(315.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MOUSE, line1);

	CObj* line2 = CAbstractFactory<CKDHLine>::Create();
	static_cast<CKDHLine*>(line2)->SetRotateAngle(45.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MOUSE, line2);

	CObj* line3 = CAbstractFactory<CKDHLine>::Create();
	static_cast<CKDHLine*>(line3)->SetRotateAngle(135.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MOUSE, line3);

	CObj* line4 = CAbstractFactory<CKDHLine>::Create();
	static_cast<CKDHLine*>(line4)->SetRotateAngle(225.f);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MOUSE, line4);

	CreatePattern();

	CSoundMgr::Get_Instance()->Initialize();
	CSoundMgr::Get_Instance()->PlayEvent("event:/Open Hexagon - Apeirogon - Milky Ways");
	CSoundMgr::Get_Instance()->Update();

	m_fChangeCount = 2.f;
	m_dwTick = GetTickCount();
}

int CKDHScene::Update()
{
	CObjMgr::Get_Instance()->Update();
	CHexaPadManager::Get_Instance()->OnPattern();

	if (g_bRotateAngle == true)
	{
		g_RevolAngle += ROTATE_SPEED;
	}
	else
	{
		g_RevolAngle -= ROTATE_SPEED;
	}

	if (GetTickCount() > m_dwTick + (1000.f * m_fChangeCount))
	{
		g_bRotateAngle = !g_bRotateAngle;
		m_dwTick = GetTickCount();
	}

	if (CKeyMgr::Get_Instance()->Key_Down(VK_BACK))
	{
		CSceneMgr::Get_Instance()->Set_Scene(SC_MENU);
	}
	
	return 0;
}

void CKDHScene::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CKDHScene::Render(HDC hDC)
{
	Rectangle(hDC,
		0,
		0,
		WINCX,
		WINCY);

	CObjMgr::Get_Instance()->Render(hDC);
}

void CKDHScene::Release()
{
	CHexaPadManager::Get_Instance()->ClearPattern();
	CHexaPadManager::Get_Instance()->Destroy_Instance();
	CObjMgr::Get_Instance()->Release();
	CSoundMgr::Get_Instance()->Stop_All_Event();
}

void CKDHScene::CreatePattern()
{
	CSequence sequence;
	sequence.sequence = [&]()
		{
		};
	sequence.fCount = 0.5f;

	CHexaPadManager::Get_Instance()->AddPattern(sequence);

	sequence.sequence = [&]()
		{
			AddPad(DIR_DOWN);
			AddPad(DIR_UP);
			AddPad(DIR_LEFT);
		};
	sequence.fCount = 0.5f;

	CHexaPadManager::Get_Instance()->AddPattern(sequence);

	sequence.sequence = [&]()
		{
			AddPad(DIR_UP);
			AddPad(DIR_LEFT);
			AddPad(DIR_RIGHT);
		};
	sequence.fCount = 0.5f;

	CHexaPadManager::Get_Instance()->AddPattern(sequence);

	sequence.sequence = [&]()
		{
			AddPad(DIR_DOWN);
			AddPad(DIR_UP);
			AddPad(DIR_RIGHT);
		};
	sequence.fCount = 0.5f;

	CHexaPadManager::Get_Instance()->AddPattern(sequence);

	sequence.sequence = [&]()
		{
			AddPad(DIR_LEFT);
			AddPad(DIR_DOWN);
			AddPad(DIR_RIGHT);
		};
	sequence.fCount = 0.5f;

	CHexaPadManager::Get_Instance()->AddPattern(sequence);

	sequence.sequence = [&]()
		{
			AddPad(DIR_LEFT);
			AddPad(DIR_DOWN);
			AddPad(DIR_UP);
		};
	sequence.fCount = 0.5f;

	CHexaPadManager::Get_Instance()->AddPattern(sequence);

	sequence.sequence = [&]()
		{
			AddPad(DIR_LEFT);
			AddPad(DIR_UP);
			AddPad(DIR_RIGHT);
		};
	sequence.fCount = 0.5f;

	CHexaPadManager::Get_Instance()->AddPattern(sequence);

	sequence.sequence = [&]()
		{
			AddPad(DIR_DOWN);
			AddPad(DIR_UP);
			AddPad(DIR_RIGHT);
		};
	sequence.fCount = 0.5f;

	CHexaPadManager::Get_Instance()->AddPattern(sequence);

	sequence.sequence = [&]()
		{
			AddPad(DIR_LEFT);
			AddPad(DIR_DOWN);
			AddPad(DIR_RIGHT);
		};
	sequence.fCount = 0.5f;

	CHexaPadManager::Get_Instance()->AddPattern(sequence);

	sequence.sequence = [&]()
		{
			AddPad(DIR_LEFT);
			AddPad(DIR_DOWN);
			AddPad(DIR_UP);
		};
	sequence.fCount = 0.5f;

	CHexaPadManager::Get_Instance()->AddPattern(sequence);

	sequence.sequence = [&]()
		{
			AddPad(DIR_DOWN);
			AddPad(DIR_UP);
			AddPad(DIR_LEFT);
		};
	sequence.fCount = 0.5f;

	CHexaPadManager::Get_Instance()->AddPattern(sequence);

	sequence.sequence = [&]()
		{
			AddPad(DIR_UP);
			AddPad(DIR_LEFT);
			AddPad(DIR_RIGHT);
		};
	sequence.fCount = 0.5f;

	CHexaPadManager::Get_Instance()->AddPattern(sequence);

	sequence.sequence = [&]()
		{
			AddPad(DIR_DOWN);
			AddPad(DIR_UP);
			AddPad(DIR_RIGHT);
		};
	sequence.fCount = 0.5f;

	CHexaPadManager::Get_Instance()->AddPattern(sequence);

	sequence.sequence = [&]()
		{
			AddPad(DIR_LEFT);
			AddPad(DIR_DOWN);
			AddPad(DIR_RIGHT);
		};
	sequence.fCount = 0.5f;

	CHexaPadManager::Get_Instance()->AddPattern(sequence);

	sequence.sequence = [&]()
		{
			AddPad(DIR_LEFT);
			AddPad(DIR_DOWN);
			AddPad(DIR_UP);
		};
	sequence.fCount = 0.5f;

	CHexaPadManager::Get_Instance()->AddPattern(sequence);

	sequence.sequence = [&]()
		{
			AddPad(DIR_LEFT);
			AddPad(DIR_UP);
			AddPad(DIR_RIGHT);
		};
	sequence.fCount = 0.5f;

	CHexaPadManager::Get_Instance()->AddPattern(sequence);

	sequence.sequence = [&]()
		{
			AddPad(DIR_DOWN);
			AddPad(DIR_UP);
			AddPad(DIR_RIGHT);
		};
	sequence.fCount = 0.5f;

	CHexaPadManager::Get_Instance()->AddPattern(sequence);

	sequence.sequence = [&]()
		{
			AddPad(DIR_LEFT);
			AddPad(DIR_DOWN);
			AddPad(DIR_RIGHT);
		};
	sequence.fCount = 0.5f;

	CHexaPadManager::Get_Instance()->AddPattern(sequence);

	sequence.sequence = [&]()
		{
			AddPad(DIR_LEFT);
			AddPad(DIR_DOWN);
			AddPad(DIR_UP);
		};
	sequence.fCount = 0.5f;

	CHexaPadManager::Get_Instance()->AddPattern(sequence);
}

void CKDHScene::AddPad(kDIRECTION _direction)
{
	CObj* pad = CAbstractFactory<CHexaPad>::Create();
	static_cast<CHexaPad*>(pad)->SetDirection(_direction);
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, pad);
}
