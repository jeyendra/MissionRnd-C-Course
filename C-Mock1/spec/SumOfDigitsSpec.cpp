#include "stdafx.h"


#include "./../src/SumOfDigits.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class SumOfDigitsSpec
	{
	private:
		TestContext^ testContextInstance;

	public:
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		[TestMethod, Timeout(3000)]
		void Test_SumOfDigits01() {
			int base = 2;
			char num[10] = { '1', '0', '1', '\0' };
			char expected = '1';
			char actual = sumOfDigits(num, base);
			Assert::AreEqual(expected, actual, L"SumOfDigits test case 01 failed", 1, 2, 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void Test_SumOfDigits02() {
			int base = 16;
			char num[10] = { '3', 'b', 'f', '\0' };
			char expected = 'e';
			char actual = sumOfDigits(num, base);
			Assert::AreEqual(expected, actual, L"SumOfDigits test case 02 failed", 1, 2, 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void Test_SumOfDigits03() {
			int base = 27;
			char num[10] = { 'a', 'l', 'f', '\0' };
			char expected = 'k';
			char actual = sumOfDigits(num, base);
			Assert::AreEqual(expected, actual, L"SumOfDigits test case 03 failed", 1, 2, 1, 2);
		}
        
        // write your test cases here
    };
}
