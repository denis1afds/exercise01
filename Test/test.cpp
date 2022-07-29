#include "lib.h"
#include "gtest/gtest.h"

TEST(Version, neZero)
{
    //arrange
    //act
    int versionNo = lib::getVersion();
    
    //assert
    ASSERT_NE(versionNo, 0);
}