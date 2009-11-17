#include "sleeperthread.h"



void SleeperThread::msleep(unsigned long msecs)
{
    QThread::msleep(msecs);
}



