#pragma once

#include "physgo.h"
#include "mm/game/events.h"

class CDamageable : public CPhysicsGameObject, public NEvent::CEventHandler
{
public:

    virtual ~CDamageable() = 0;
    virtual float InflictDamage() = 0;
    virtual float CalculateDamage() = 0;
    virtual bool IsTargetable() = 0;
    virtual void OnDestroyed(CHashString) = 0;
    virtual void SendOnDestroyEvent(CHashString) = 0;

    float GetHealth() {
        return *(float*)((uintptr_t)this + 0x184); //0x1C?
    }
    void SetHealth(float fHealth) {
        *(float*)((uintptr_t)this + 0x184) = fHealth; //0x1C?
    }
    void SetInvulnerable(bool invulnerable) { m_Invulnerable = invulnerable; }

    bool m_Destroyed;
    bool m_Invulnerable;
    char unk234[214];
};