#ifndef PLAYER_H
#define PLAYER_H

#include <QApplication>
#include <QDesktopWidget>
#include <QObject>
#include <QtCore/QCoreApplication>
#include <iostream>
#include <QFileDialog>
#include <QTimer>

#include "library.h"
#include "musicEngine.h"
#include "mainwindow.h"
#include "playlist.h"

using namespace std;

namespace Ui
{
    class Form;
}

class Player : public QWidget
{
    Q_OBJECT
public:
    Player(QWidget *parent, string song, int nRow);
    Player();

    //Player& operator=(const Player &other);


    ~Player();

public slots:

    void playMusic();
    void pauseMusic();
    void stopMusic();
    void nextSong();
    void prevSong();
    void updateStatusBar();
    void sliderPause();
    void sliderReleased();
    void loop();

    friend void openPlayer(string song);
    //friend class MainWindow;

protected:
    int musicRow;

    //void changeEvent(QEvent *e);


private:
    Ui::Form *ui;
    musicEngine music;
    bool musicWasPlaying;
    bool playerLoop;
    double offsetValue;
    void copy(const Player &other);
};

#endif // PLAYER_H
