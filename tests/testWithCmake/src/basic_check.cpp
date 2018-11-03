#include "gtest.h"
#include "simple_buffer.h"

GTEST_API_ int main(int argc, char **argv) {
    printf("Running main() from gtest_main.cc\n");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(basicBuffferTest, addElement) {
    QueueInit();
    EXPECT_EQ(0, QueuePut(5));
}

TEST(basicBuffferTest, fullBuffer) {
    QueueInit();
    for(int i=0;i<QUEUE_ELEMENTS;i++){
        EXPECT_EQ(0, QueuePut(5));
    }
}

//all tests from one group have same namespace and perfoms one by one
TEST(basicBuffferTest, overflowBuffer) {
    EXPECT_EQ(-1, QueuePut(5));
}

TEST(basicBuffferTest2, overflowBuffer) {
    EXPECT_EQ(0, QueuePut(5));
}

TEST(basicBuffferTest, writeAndReadOne) {
    QueueInit();
    EXPECT_EQ(0, QueuePut(5));
    int readEl;
    EXPECT_EQ(0, QueueGet(&readEl));
    EXPECT_EQ(5, readEl);


}

//example of disabled test
TEST(basicBuffferTest, DISABLED_zero) {
    EXPECT_EQ(10, 10);

}