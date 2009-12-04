/**
 * Manpreet Kohli
 * CS 340, Fall 2009
 *
 * SleeperThread.cpp: file to utilize the sleep functionality of QThread.
 *
 */

#ifndef SLEEPERTHREAD_H
#define SLEEPERTHREAD_H

#include <QThread>

class SleeperThread : public QThread
{
    public:
        void msleep(unsigned long msecs);
};

#endif // SLEEPERTHREAD_H
