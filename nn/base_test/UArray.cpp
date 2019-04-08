#include "HeArr.h"
#include <gtest.h>

TEST(TUnArray, can_create_ARR)
{
	TUnArray Ar();
	ASSERT_NO_THROW(Ar);
}

TEST(TUnArray, can_create_ARR2)
{
	TUnArray Ar(10);
	ASSERT_NO_THROW(Ar);
}
/*
TEST(TUnArray, can_not_create_polinom)
{
	int size = -14;
	TUnArray<TKey, TPolinom> Ar(size);
	ASSERT_NO_THROW()
}

/*TEST(TUnArray, can_find_object)
{
	TUnArray<TKey, TPolinom> Ar();
	int a = Ar.ToFindUnArr(2);
	EXPECT_TRUE( a == -2);
}*/