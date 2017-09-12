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
			ForwardList<int> fl;
			Assert::AreEqual(true, fl.empty());
		}

		TEST_METHOD(TestPushFront)
		{
			ForwardList<int> list1;
			ForwardList<int> list2;
			int x = 5, y = 10;

			list1.pushFront(x);
			list1.pushFront(y);
			list2.pushFront(x);

            // list1: [10]->[5]
            // list2: [5]

			Assert::AreEqual(false, list1.empty());
			Assert::AreEqual(false, list2.empty());
		}

		TEST_METHOD(TestPopFront)
		{
            ForwardList<int> list1;
            int x = 5, y = 7, z = 14;
            list1.pushFront(x);
            list1.pushFront(y);
            list1.pushFront(z);

            // list: [5]->[7]->[14]
			Assert::AreEqual(list1.front(), 14);
            list1.popFront();

            // After popFront, the list should be: [7]->[14]
			Assert::AreEqual(list1.front(), 7);

			list1.popFront();
			Assert::AreEqual(list1.front(), 5);
			list1.popFront();
			Assert::IsTrue(&list1.front() == nullptr);

			//empty list
			bool exceptionThrown = false;
			try
			{
				list1.popFront(); //Här bör en exception skickas.
			}
			catch(const std::exception&)
			{
				exceptionThrown = true;
			}
			Assert::IsTrue(exceptionThrown);
			Assert::IsTrue(&list1.front() == nullptr);
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