#include "PhilosopherModel/forkTest.h"
#include "PhilosopherModel/philosopherMonitor.h"
#include "PhilosopherModel/philosopherTest.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
