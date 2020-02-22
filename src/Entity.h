#pragma once

#include <utility>
#include <typeindex>
#include <map>
#include <unordered_map>
#include <memory>
#include <assert.h>

#include "Component.h"
#include "DisplayComponent.h"
#include "Cave.h"

class Entity
{
    private:
        int x, y;
        std::map<std::type_index, std::shared_ptr<Component> > components;

    public:
        Entity(int x, int y);
        Entity();

        template <typename T>
        void AddComponent(std::shared_ptr<T> component)
        {
            components[std::type_index(typeid(*component))] = component;
        }

        template <typename T>
        std::shared_ptr<T> GetComponent()
        {
            std::type_index index(typeid(T));
            if (components.count(std::type_index(typeid(T))) != 0)
            {
                return std::static_pointer_cast<T>(components[index]);
            }
            else
            {
                assert(false);
                //we should never do this
                return nullptr;
            }
        }

        void SetPosition(int x, int y);
        Point GetPosition();
        int GetX();
        int GetY();



};