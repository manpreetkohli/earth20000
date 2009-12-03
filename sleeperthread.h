#ifndef SLEEPERTHREAD_H
#define SLEEPERTHREAD_H

#include <QThread>

class SleeperThread : public QThread
{
    public:
        void msleep(unsigned long msecs);
};

#endif // SLEEPERTHREAD_H
