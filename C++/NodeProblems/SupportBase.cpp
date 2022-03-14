#include "LeetCode.h"

using namespace std;
using namespace Support;

void SupportBase::test()
{
    printf("-------This is a trial test-------\n");
    m_startTime = time(0);
}

void SupportBase::endTest()
{
    double elapseTime = difftime(time(0), m_startTime);
    printf("-------End Test, Time Elapse: %.2lf(s)-------", elapseTime);
}