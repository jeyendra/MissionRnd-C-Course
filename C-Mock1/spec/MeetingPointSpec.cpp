#include "stdafx.h"

#include "SpecUtils.h"
#include "./../src/MeetingPoint.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class MeetingPointSpec
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


		[TestMethod, Timeout(500)]
		void Test_MeetingPoint01() {
			char cities1[][20] = { "B", "B", "E", "V", "Z" };
			char cities2[][20] = { "B", "S" };
			char commonCities[][20] = { "U", "V", "U", "L", "L" };
			CityNode *intersection = createPath(commonCities, 5);
			CityNode *deepikaStartCity = appendPath(createPath(cities1, 5), intersection);
			CityNode *mayaStartCity = appendPath(createPath(cities2, 2), intersection);
			int numberOfCitiesMayaShouldTravel = 0;
			CityNode *meet = meetingPoint(deepikaStartCity, mayaStartCity, &numberOfCitiesMayaShouldTravel);
			int gotnull = (meet == NULL) ? 1 : 0;
			Assert::AreEqual(0, gotnull, L"Should Not Return NULL", 1, 2);
			Assert::AreEqual(1, areSameCityNode(meet, intersection), L"Meeting City Comparision failed", 1, 2);
			Assert::AreEqual(2, numberOfCitiesMayaShouldTravel, L"NumberOfCitiesMayaShouldTravel failed", 1, 2);
		}

		[TestMethod, Timeout(500)]
		void Test_MeetingPoint02()
		{
			char cities1[][20] = { "K", "L", "N", "O" };
			char cities2[][20] = { "Z", "X", "N", "O" };
			char commonCities[][20] = { "A", "B", "C" };
			CityNode *intersection = createPath(commonCities, 3);
			CityNode *deepikaStartCity = appendPath(createPath(cities1, 4), intersection);
			CityNode *mayaStartCity = appendPath(createPath(cities2, 4), intersection);
			int numberOfCitiesMayaShouldTravel = 0;
			CityNode *meet = meetingPoint(deepikaStartCity, mayaStartCity, &numberOfCitiesMayaShouldTravel);
			int gotnull = (meet == NULL) ? 1 : 0;
			Assert::AreEqual(0, gotnull, L"Should Not Return NULL", 1, 2);
			Assert::AreEqual(1, areSameCityNode(meet, intersection), L"Meeting City Comparision failed", 1, 2);
			Assert::AreEqual(4, numberOfCitiesMayaShouldTravel, L"NumberOfCitiesMayaShouldTravel failed", 1, 2);
		};

		[TestMethod, Timeout(500)]
		void Test_MeetingPoint03() {
			char cities1[][20] = { "X", "H", "F", "Y" };
			char cities2[][20] = { "N", "Q", "O", "W", "I", "Y" };
			char commonCities[][20] = { "Q", "I", "T", "F", "F" };
			CityNode *intersection = createPath(commonCities, 5);
			CityNode *deepikaStartCity = appendPath(createPath(cities1, 4), intersection);
			CityNode *mayaStartCity = appendPath(createPath(cities2, 6), intersection);
			int numberOfCitiesMayaShouldTravel = 0;
			CityNode *meet = meetingPoint(deepikaStartCity, mayaStartCity, &numberOfCitiesMayaShouldTravel);
			int gotnull = (meet == NULL) ? 1 : 0;
			Assert::AreEqual(0, gotnull, L"Should Not Return NULL", 1, 2);
			Assert::AreEqual(1, areSameCityNode(meet, intersection), L"Meeting City Comparision failed", 1, 2);
			Assert::AreEqual(6, numberOfCitiesMayaShouldTravel, L"NumberOfCitiesMayaShouldTravel failed", 1, 2);
		}

        // write your own test cases here
        
        
	};
}
