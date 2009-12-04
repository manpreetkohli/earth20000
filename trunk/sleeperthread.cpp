#include "sleeperthread.h"

/*!
  implement sleep functionality of QThread
  The function exposes the protected function inside QThread to implement it
  */
void SleeperThread::msleep(unsigned long msecs)
{
    QThread::msleep(msecs);
}
