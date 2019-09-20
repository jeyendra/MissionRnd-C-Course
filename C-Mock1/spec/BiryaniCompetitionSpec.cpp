#include "stdafx.h"


#include "./../src/BiryaniCompetition.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class BiryaniCompetitionSpec
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


		[TestMethod, Timeout(1000)]
		void Test_BiryaniCompetition01()
		{
			int n = 7;
			int weights[7] = {8, 15, 25, 3, 11, 20, 30};
			int expected = 292;
			int actual = time_taken_by_winner(n, weights);
			Assert::AreEqual(expected, actual, L"BiryaniCompetition test case 01 failed", 1, 2);
		}
		
		[TestMethod, Timeout(1000)]
		void Test_BiryaniCompetition02()
		{
			int n = 6;
			int weights[6] = {3, 18, 22, 40, 5, 12};
			int expected = 226;
			int actual = time_taken_by_winner(n, weights);
			Assert::AreEqual(expected, actual, L"BiryaniCompetition test case 02 failed", 1, 2);
		}
		
		[TestMethod, Timeout(1000)]
		void Test_BiryaniCompetition03()
		{
			int n = 5;
			int weights[5] = {9, 5, 30, 7, 11};
			int expected = 126;
			int actual = time_taken_by_winner(n, weights);
			Assert::AreEqual(expected, actual, L"BiryaniCompetition test case 03 failed", 1, 2);
		}
        
        // write your own test cases here
        
	};
}
