#include "pch.h"
#include "CppUnitTest.h"
#include "../6.4_rec/6.4_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64rec
{
    TEST_CLASS(UnitTest64rec)
    {
    public:

        TEST_METHOD(TestCountZeros)
        {
            double arr[] = { 0, 1, 2, 0, 4, 0 };
            int size = 6;
            int result = CountZeros(arr, size);
            Assert::AreEqual(3, result, L"CountZeros failed");
        }

        TEST_METHOD(TestFindMinIndex)
        {
            double arr[] = { 3, 1, 2, -5, 4 };
            int size = 5;
            int result = FindMinIndex(arr, size);
            Assert::AreEqual(3, result, L"FindMinIndex failed");
        }

        TEST_METHOD(TestSumAfterMin)
        {
            double arr[] = { 3, 1, 2, -5, 4 };
            int size = 5;
            int minIndex = FindMinIndex(arr, size);
            double result = SumAfterMin(arr, size, minIndex);
            Assert::AreEqual(4.0, result, L"SumAfterMin failed");
        }

        TEST_METHOD(TestSortOddElements)
        {
            double arr[] = { 7, 3, 5, 2, 4, 1 };
            int size = 6;
            SortOddElements(arr, size);

            double expected[] = { 1, 3, 5, 2, 4, 7 };

            for (int i = 0; i < size; i++) {
                Assert::AreEqual(expected[i], arr[i], L"SortOddElements failed");
            }
        }
    };
}
