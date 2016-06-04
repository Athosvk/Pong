#pragma once
#include <glm/glm.hpp>
#include <type_traits>

namespace Artifact
{
    class MathHelper
    {
    public:
        MathHelper() = delete;
        ~MathHelper() = delete;

        static float clamp(float a_Value, float a_Min, float a_Max);
        static float pingPong(float a_Value, float a_Min, float a_Max);

        template<typename T>
        static T min(T a_Value1, T a_Value2)
        {
            return a_Value1 < a_Value2 ? a_Value1 : a_Value2;
        }

        template<typename T>
        static T max(T a_Value1, T a_Value2)
        {
            return a_Value1 > a_Value2 ? a_Value1 : a_Value2;
        }

		/// <summary> Converts the given degrees to a value in radians </summary>
		/// <param name="a_Degrees">The degrees to convert</param>
		/// <returns>The value in radians</returns>
		template<typename TValueType, typename TReturnType = TValueType>
		static TReturnType toRadians(TValueType a_Degrees)
		{
			static_assert(std::is_floating_point<TReturnType>::value,
				"Return type must be floating point, precision does not allow otherwise");
			static_assert(std::is_integral<TValueType>::value || std::is_floating_point<TValueType>::value,
				"Argument type must be integral or floating point");
			return glm::radians(a_Degrees);
		}

		/// <summary> Converts the given radians to a value in degrees </summary>
		/// <param name="a_Radians">The radians to convert</param>
		/// <returns>The value in degrees</returns>
		template<typename TValueType, typename TReturnType = TValueType>
		static TReturnType toDegrees(TValueType a_Radians)
		{
			static_assert(std::is_floating_point<TValueType>::value,
				"Argument type must be floating point, precision does not allow otherwise");
			static_assert(std::is_integral<TReturnType>::value || std::is_floating_point<TReturnType>::value,
				"Return type must be integral or floating point");
			return glm::degrees(a_Radians);
		}

		/// <summary> Returns the given floating point rounded to the nearest integer</summary>
		/// <param name="a_Value">The value to round</param>
		/// <param name="a_Decimals">The value to round</param>
		/// <returns>The value rounded to the nearest integer</returns>
		template<typename TValueType>
		static TValueType round(TValueType a_Value, unsigned a_Decimals)
		{
			static_assert(std::is_floating_point<TValueType>::value,
				"Can only round floating point numbers");
			TValueType roundedValue;
			if(a_Decimals > 0)
			{
				auto multiplier = std::pow(10, a_Decimals);
				roundedValue = static_cast<TValueType>(std::round(a_Value * multiplier) / multiplier);
			}
			else
			{
				roundedValue = static_cast<TValueType>(std::round(a_Value));
			}
			return roundedValue;
		}

		/// <summary> Returns the given floating point rounded to the nearest integer</summary>
		/// <param name="a_Value">The value to round</param>
		/// <returns>The value rounded to the nearest integer</returns>
		template<typename TValueType>
		static TValueType round(TValueType a_Value)
		{
			static_assert(std::is_floating_point<TValueType>::value,
				"Can only round floating point numbers");
			return std::round(a_Value);
		}
	
		/// <summary>Gets the angle between two normalized vectors</summary>
		/// <param name="a_Vector1">The first vector</param>
		/// <param name="a_Vector2">The other vector</param>
		/// <returns>The signed angle in degrees between both vectors</returns>
		static float getSignedAngle(glm::vec2 a_Vector1, glm::vec2 a_Vector2);
        static glm::vec2 rotate(glm::vec2 a_Vector, float a_Degrees, glm::vec2 a_Origin);
        static glm::vec2 directionFromAngle(float a_Degrees);
        static float directionToAngle(glm::vec2 a_NormalizedDirection);
    };
}
