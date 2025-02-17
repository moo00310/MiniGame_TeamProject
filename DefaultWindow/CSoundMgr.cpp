#include "pch.h"
#include "CSoundMgr.h"


CSoundMgr* CSoundMgr::m_pInstance = nullptr;

CSoundMgr::CSoundMgr() : m_pStudioSystem(nullptr), m_pCoreSystem(nullptr)
{
}

CSoundMgr::~CSoundMgr()
{
    Release();
}

void CSoundMgr::Initialize()
{
    FMOD::Studio::System::create(&m_pStudioSystem);
    m_pStudioSystem->getCoreSystem(&m_pCoreSystem);
    m_pStudioSystem->initialize(32, FMOD_STUDIO_INIT_NORMAL, FMOD_INIT_NORMAL, nullptr);

    // ê¸°ë³¸?ì¼ë¡??? ?ì??Bank??ë¡ë
    LoadBank("../sound/Build/Desktop/Master.bank");
    LoadBank("../sound/Build/Desktop/Master.strings.bank");
   
    //LoadBank("./examples/Build/Desktop/Music.bank");
    //LoadBank("./examples/Build/Desktop/SFX.bank");
}
void CSoundMgr::Update()
{
    m_pStudioSystem->update();
    m_pCoreSystem->update();
    // ?ìì¤ì??
}
void CSoundMgr::Release()
{
    m_pStudioSystem->release();
    m_pCoreSystem->release();
    // ?ìì¤ì??
}

FMOD::Studio::EventInstance* CSoundMgr::PlayEvent(const char* _EventPath)
{
    FMOD::Studio::EventDescription* pEventDescription; // ?´ë²¤?¸ì ?ë³´ë¥???¥í???´ë??
    FMOD_RESULT result = m_pStudioSystem->getEvent(_EventPath, &pEventDescription); // ?ì¤?ì¼ë¡?ë¶???´ë¦???µí´ ?´ë²¤?¸ì ?ë³´ë¥?ë°ì?¨ë¤.

    FMOD::Studio::EventInstance* pEventInstance = nullptr;
    pEventDescription->createInstance(&pEventInstance); // ?´ë²¤???¸ì¤?´ì¤ ?ì±
    result = pEventInstance->start();
    pEventInstance->setCallback(AutoRelease, FMOD_STUDIO_EVENT_CALLBACK_STOPPED); // ?´ë²¤?¸ê? ?ëë©?AutoRelease?¨ìë¥??µí´ ?ë?¼ë¡ ë©ëª¨ë¦¬ë? ë°í?´ì???

    m_pStudioSystem->update();
    return pEventInstance;
}

FMOD::Studio::Bank* CSoundMgr::LoadBank(const char* _BankFilePath)
{
    FMOD::Studio::Bank* pBank = nullptr;
    FMOD_RESULT result = m_pStudioSystem->loadBankFile(_BankFilePath, FMOD_STUDIO_LOAD_BANK_NORMAL, &pBank);
    return pBank;
}

FMOD_RESULT F_CALLBACK AutoRelease(FMOD_STUDIO_EVENT_CALLBACK_TYPE type, FMOD_STUDIO_EVENTINSTANCE* eventInstance, void* parameters) // ?¬ì???ë ?´ë²¤???ë ë°í???í
{
    reinterpret_cast<FMOD::Studio::EventInstance*>(eventInstance)->release(); // FMOD ì½ë°±?¨ì??C? C++??ë²ì©???¬ì©???ê¸° ?í´ êµ¬ì¡°ì²??¬ì¸?°ë? ê¸°ë³¸ ë§¤ê°ë³?ë¡ ?¡ì.
    //?´ëë¬¸ì C++?ì??reinterpret_castë¥??µí´ ?´ë???¬ì¸?°ë¡ ?ë????ì¼ì£¼ì´?¼í¨.
    return FMOD_OK;
}

void CSoundMgr::Stop_All_Event()
{
    FMOD::Studio::Bus* m_pBus = nullptr;
    m_pStudioSystem->getBus("bus:/", &m_pBus);
    m_pBus->stopAllEvents(FMOD_STUDIO_STOP_IMMEDIATE);
    Update();
}