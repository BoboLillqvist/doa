#include "stdafx.h"
#include "CppUnitTest.h"
#include "../forward_list/ForwardList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestForwardList
{
	TEST_CLASS(TestForwardList)
	{
	public:

		TEST_METHOD(TestEmpty)
		{

		}

		TEST_METHOD(TestPushFront)
		{
			ForwardList<int> fl;
			ForwardList<int> f2;
			int x = 5;
			fl.pushFront(x);
			fl.pushFront(x);
			Assert::AreEqual(false, fl.empty());
			Assert::AreEqual(false, f2.empty());
		}

		TEST_METHOD(TestPopFront)
		{

		}

		TEST_METHOD(TestIteratorBeginEnd)
		{

		}
	};

    TEST_CLASS(TestNode)
    {
    public:

        TEST_METHOD(TestCreateEmptyNode)
        {
            Node<int> node1;
            Assert::IsTrue(node1.next == nullptr);
        }

        TEST_METHOD(TestCreateNodeWithValue)
        {
            Node<int> node1(5);
            Node<int> node2(10000000);
            Node<double> node3(5.0003);

            Assert::AreEqual(node1.value, 5);
            Assert::AreEqual(node2.value, 10000000);
            Assert::AreEqual(node3.value, 5.0003);
        }
    };
}