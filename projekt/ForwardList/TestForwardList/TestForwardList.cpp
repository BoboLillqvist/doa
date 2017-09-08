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
			ForwardList<int> fli;
			Assert::AreEqual(true, fli.empty());
		}

		TEST_METHOD(TestPushFront)
		{
			ForwardList<int> fli;
		}

		TEST_METHOD(TestPopFront)
		{
			ForwardList<int> fli;
		}

		TEST_METHOD(TestIteratorBeginEnd)
		{
			ForwardList<int> fli;
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