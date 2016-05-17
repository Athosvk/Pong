#pragma once
#include "../Core/MessagingSystem.h"
#include "../Core/ComponentHandle.h"

namespace Artifact
{
    class BoxCollider2D;

    class Collision2DMessage : public Message
    {
    private:
        ComponentHandle<BoxCollider2D> m_Collider;
        ComponentHandle<BoxCollider2D> m_Other;

    public:
        Collision2DMessage(ComponentHandle<BoxCollider2D> a_Collider, ComponentHandle<BoxCollider2D> a_Other);

        ComponentHandle<BoxCollider2D> getCollider() const;
        ComponentHandle<BoxCollider2D> getOther() const;
    };

    class CollisionEnter2DMessage : public Collision2DMessage
    {
    public:
        CollisionEnter2DMessage(ComponentHandle<BoxCollider2D> a_Collider, ComponentHandle<BoxCollider2D> a_Other);
    };

    class TriggerEnter2DMessage : public Collision2DMessage
    {
    public:
        TriggerEnter2DMessage(ComponentHandle<BoxCollider2D> a_Collider, ComponentHandle<BoxCollider2D> a_Other);
    };

    class CollisionExit2DMessage : public Collision2DMessage
    {
    public:
        CollisionExit2DMessage(ComponentHandle<BoxCollider2D> a_Collider, ComponentHandle<BoxCollider2D> a_Other);
    };

    class TriggerExit2DMessage : public Collision2DMessage
    {
    public:
        TriggerExit2DMessage(ComponentHandle<BoxCollider2D> a_Collider, ComponentHandle<BoxCollider2D> a_Other);
    };
}
