#pragma once
#include "CScene.h"
class CStart : public CScene
{
public:
	CStart() {}
	~CStart() {}

	// CScene을(를) 통해 상속됨
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
};

