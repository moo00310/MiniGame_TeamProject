#pragma once

#include "Define.h"
#include "CObj.h"

class CObjMgr
{
private:
	CObjMgr();
	CObjMgr(const CObjMgr& rhs) = delete;
	CObj operator =(CObj& rObj) = delete;
	~CObjMgr();

public:
	CObj* Get_Player()		{ return m_ObjList[OBJ_PLAYER].front(); }
	CObj* Get_LastPlayer()  { return m_ObjList[OBJ_PLAYER].back(); }
	CObj* Get_LastMonster() { return m_ObjList[OBJ_MONSTER].back(); }
	list<CObj*>* Get_ObjList() { return m_ObjList; }

	list<CObj*>* Get_List() { return m_ObjList; }

	CObj* Get_Target(OBJID eID, CObj* pDst);

	bool Collision_Check();

public:
	void		Add_Object(OBJID eID, CObj* pObj);
	int			Update();
	void		Late_Update();
	void		Render(HDC hDC);
	void		Release();

	void		Delete_ID(OBJID eID);

public:
	static CObjMgr* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CObjMgr;

		return m_pInstance;
	}

	static void		DestroyInstance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	list<CObj*>		m_ObjList[OBJ_END];
	list<CObj*>		m_RenderList[RENDER_END];

	static CObjMgr* m_pInstance;

	CObj* m_pPlayer;
};

