#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H


#include <QObject>

class SplashScreen
{
    public:
        int setupSplashScreen(int argc, char** argv);
        void setup();

    public slots:
        void startGame();


};

#endif // SPLASHSCREEN_H
