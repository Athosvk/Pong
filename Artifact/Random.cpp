#include "Random.h"

namespace Artifact
{
    int Random::range(int a_Min, int a_Max)
    {
		std::random_device randomDevice;
		std::mt19937 generator(randomDevice());
		std::uniform_int_distribution<int> distribution(a_Min, a_Max);        
		return distribution(generator);
    }

    float Random::range(float a_Min, float a_Max)
    {
		std::random_device randomDevice;
		std::mt19937 generator(randomDevice());
		std::uniform_real_distribution<float> distribution(a_Min, a_Max);
		return distribution(generator);
    }
}