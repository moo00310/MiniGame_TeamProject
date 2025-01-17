#pragma once

#include "Define.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	INFO		Get_Info() { return m_tInfo; }
	
	CObj*		Get_Target() { if(nullptr != m_pTarget) return m_pTarget; }
	void		Set_Target(CObj* _pTarget) { m_pTarget = _pTarget; }

public:
	virtual void		Initialize()PURE;
	virtual int			Update()PURE;
	virtual void		Late_Update() PURE;
	virtual void		Render(HDC hDC)PURE;
	virtual void		Release()PURE;

public:
	bool		Get_Dead() { return m_bDead; }
	void		Set_Dead() { m_bDead = true; }

	const RENDERID Get_GroupID() const { return m_eRender; }

protected:
	INFO		m_tInfo;
	RENDERID	m_eRender;

	float		m_fSpeed;
	float		m_fAngle;

	bool		m_bDead;

	CObj*		m_pTarget;
};

