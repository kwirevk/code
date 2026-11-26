#include "pch.h"
#include "CppUnitTest.h"
#include "..\Project1\FileName.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

        // ПОЗИТИВНЫЙ ТЕСТ 1: объем куба, корректная сторона
        // Вход: side = 3  →  Ожидание: 27
		TEST_METHOD(TestMethod1)
		{
            // Arrange (подготовка)
            double side = 3.0;

            // Act (действие)
            double result = VolumeCalculator::cubeVolume(side);

            // Assert (проверка)
            Assert::AreEqual(27.0, result, 0.0001);
            // 0.0001 — допустимая погрешность для double
		}

        // ПОЗИТИВНЫЙ ТЕСТ 2: объем сферы, корректный радиус
        // Вход: r = 2  →  Ожидание: (4/3)·π·8 ≈ 33.5103
        TEST_METHOD(TestSphereVolume_ValidRadius_ReturnsCorrectVolume)
        {
            // Arrange
            double radius = 2.0;
            double expected = (4.0 / 3.0) * 3.14 * 8.0;

            // Act
            double result = VolumeCalculator::sphereVolume(radius);

            // Assert
            Assert::AreEqual(expected, result, 0.0001);
        }

        // НЕГАТИВНЫЙ ТЕСТ 1: нулевая сторона куба
        TEST_METHOD(TestCubeVolume_ZeroSide_ThrowsException)
        {
            // Assert: ожидаем, что вызов обёртки бросит исключение
            Assert::ExpectException<std::invalid_argument>(
                callCubeWithZeroSide
            );
        }
        // НЕГАТИВНЫЙ ТЕСТ 2: отрицательная высота цилиндра
        // Вход: r = 2, h = -5  →  Ожидание: std::invalid_argument

        TEST_METHOD(TestCylinderVolume_NegativeHeight_ThrowsException)
        {
            Assert::ExpectException<std::invalid_argument>(
                callCylinderWithNegativeHeight
            );
        }  private:
        // Вспомогательные функции-обёртки: нужны, потому что
        // Assert::ExpectException принимает указатель на функцию
        // без аргументов (лямбду в старом CppUnitTest писать нельзя).

        static void callCubeWithZeroSide()
        {
            VolumeCalculator::cubeVolume(0.0);
        }

        static void callCylinderWithNegativeHeight()
        {
            VolumeCalculator::cylinderVolume(2.0, -5.0);
        }
    };
}

       
        
        

       
        

  