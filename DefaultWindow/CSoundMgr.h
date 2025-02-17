#pragma once
#pragma once
#include "Define.h"

#define MAX_SFX_CHANNEL 31
FMOD_RESULT F_CALLBACK AutoRelease(FMOD_STUDIO_EVENT_CALLBACK_TYPE type, FMOD_STUDIO_EVENTINSTANCE* eventInstance, void* parameters);

class CSoundMgr
{
public:
    static CSoundMgr* Get_Instance()
    {
        if (nullptr == m_pInstance)
            m_pInstance = new CSoundMgr;

        return m_pInstance;
    }
    static void Destroy_Instance()
    {
        if (m_pInstance)
        {
            delete m_pInstance;
            m_pInstance = nullptr;
        }
    }

private:
    CSoundMgr();
    ~CSoundMgr();

public:
    void Initialize();
    void Update();
    void Release();

public:
    FMOD::Studio::EventInstance* PlayEvent(const char* _EventPath); // ?΄λ²€?Έλ? ?¬μ?κ³  κ·??΄λ²€?Έμ ?¬μΈ?°λ? λ°ν
    FMOD::Studio::Bank* LoadBank(const char* _BankFilePath); // λ±ν¬λ₯?λ‘λ?κ³  κ·?λ±ν¬???¬μΈ?°λ? λ°ν
    // Bank ?μΌ? Fmod ?€ν?μ€?μ λΉλ???€λ???°μ΄?°λ? ??₯ν??μ»¨ν?΄λλ‘? 
    // ?¬μ© ?? ???΄μ ?μ?μ΄μ§?Bank???¬μ λ¦΄λ¦¬μ¦μ??Unload ?¨μλ₯??ΈμΆ?΄μ£Ό?΄μΌ ?λ€.
    void Stop_All_Event();

private:
    static CSoundMgr* m_pInstance;

    FMOD::System* m_pCoreSystem; // ?μ???¬μ©?λ κΈ°λ³Έ Fmod μ½μ΄ ?μ€??
    FMOD::Studio::System* m_pStudioSystem; // Fmod Studio? ?°λ???ν΄ ?μ???€ν?μ€ ?μ€??
};
