#include "pch.h"
#include "CppUnitTest.h"
#include "../pr7.1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int rowCount = 7;
            const int colCount = 6;
            int S = 0;
            int k = 0;

            // Initialize a test matrix
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            // Fill matrix with known values for testing
            int testData[7][6] = {
                {10, 11, 12, 13, 14, 15},
                {16, 17, 18, 19, 20, 21},
                {22, 23, 24, 25, 26, 27},
                {28, 29, 30, 31, 32, 33},
                {34, 35, 36, 37, 38, 39},
                {40, 41, 42, 43, 44, 45},
                {46, 47, 48, 49, 50, 51}
            };
            for (int i = 0; i < rowCount; i++)
                for (int j = 0; j < colCount; j++)
                    a[i][j] = testData[i][j];

            // Run Calc
            Calc(a, rowCount, colCount, S, k);

            // Validate the results
            Assert::AreEqual(540, S); // Expected sum based on even elements not on row+col=7
            Assert::AreEqual(18, k);  // Expected count of qualifying elements

            // Clean up
            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;

		}
	};
}
