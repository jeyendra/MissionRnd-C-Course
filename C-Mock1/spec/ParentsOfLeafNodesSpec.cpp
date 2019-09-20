#include "stdafx.h"


#include "./../src/ParentsOfLeafNodes.cpp"
#include "SpecUtils.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
	[TestClass]
	public ref class ParentsOfLeafNodesSpec
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
		void Test_ParentsOfLeafNodes01() {
			int expected = 0;
			int actual = numberOfLeafNodeParents(NULL);
			Assert::AreEqual(expected, actual, L"ParentsOfLeafNodes test case 01 failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void Test_ParentsOfLeafNodes02() {
			int nodes[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			TreeNode *rootNode = createTree(nodes, 10);
			int expected = 1;
			int actual = numberOfLeafNodeParents(rootNode);
			Assert::AreEqual(expected, actual, L"ParentsOfLeafNodes test case 02 failed", 1, 2);
		}

		[TestMethod, Timeout(3000)]
		void Test_ParentsOfLeafNodes03() {
			int nodes[10] = { 5 };
			TreeNode *rootNode = createTree(nodes, 1);
			int expected = 0;
			int actual = numberOfLeafNodeParents(rootNode);
			Assert::AreEqual(expected, actual, L"ParentsOfLeafNodes test case 03 failed", 1, 2);
		}

        // write your own test cases here
        
		
    };
}

