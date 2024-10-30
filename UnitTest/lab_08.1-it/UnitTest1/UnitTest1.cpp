#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_08.1-it/lab_08.1-it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestProject
{
    TEST_CLASS(UnitTestProject)
    {
    public:

        // Тест для функції CountOccurrences
        TEST_METHOD(TestCountOccurrences_OneOccurrence)
        {
            char str[] = "This is OGO and that is AGA.";
            int count = CountOccurrences(str);
            Assert::AreEqual(2, count, L"Count should be 2 for one 'OGO' and one 'AGA'");
        }

        TEST_METHOD(TestCountOccurrences_NoOccurrence)
        {
            char str[] = "This string has no patterns.";
            int count = CountOccurrences(str);
            Assert::AreEqual(0, count, L"Count should be 0 when there are no 'OGO' or 'AGA' sequences");
        }

        TEST_METHOD(TestCountOccurrences_MultipleOccurrences)
        {
            char str[] = "OGOAGAOGOAGA";
            int count = CountOccurrences(str);
            Assert::AreEqual(4, count, L"Count should be 4 for two 'OGO' and two 'AGA'");
        }

        // Тест для функції ReplaceOccurrences
        TEST_METHOD(TestReplaceOccurrences_ReplaceOneOccurrence)
        {
            char str[] = "This is OGO.";
            char* result = ReplaceOccurrences(str);
            Assert::AreEqual("This is **.", result, L"String should replace 'OGO' with '**'");
            delete[] result; // Очищення виділеної пам'яті
        }

        TEST_METHOD(TestReplaceOccurrences_ReplaceMultipleOccurrences)
        {
            char str[] = "OGO and AGA appear here.";
            char* result = ReplaceOccurrences(str);
            Assert::AreEqual("** and ** appear here.", result, L"String should replace 'OGO' and 'AGA' with '**'");
            delete[] result;
        }

        TEST_METHOD(TestReplaceOccurrences_NoReplacement)
        {
            char str[] = "No patterns here.";
            char* result = ReplaceOccurrences(str);
            Assert::AreEqual("No patterns here.", result, L"String should remain the same when there are no 'OGO' or 'AGA'");
            delete[] result;
        }
    };
}
