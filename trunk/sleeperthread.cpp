/************************************************************************************
 * Manpreet Kohli
 * CS 340, Fall 2009
 *
 * SleeperThread.cpp: file to utilize the sleep functionality of QThread.
 *
 ************************************************************************************/

#include "sleeperthread.h"

// implement sleep functionality of QThread
// The function exposes the protected function inside QThread to implement it
void SleeperThread::msleep(unsigned long msecs)
{
    QThread::msleep(msecs);
}
