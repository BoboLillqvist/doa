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
}