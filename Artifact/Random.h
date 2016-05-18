#pragma once
#include <random>

namespace Artifact
{
    class Random
    {
    public:
        Random() = delete;
        ~Random() = delete;

        static int range(int a_Min, int a_Max);
        static float range(float a_Min, float a_Max);
    };
}
