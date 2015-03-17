#include "player.h"
#include "ui_player.h"

#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <iostream>
#include <fstream>

using namespace std;

Player::Player(QWidget *parent, string song, int nRow) :
    QWidget(parent, Qt::Window),
    ui(new Ui::Form)

{
    qDebug()<<"Player constructor fired";

    ui->setupUi(this);
    musicRow = nRow;
    try
    {
        music.loadFromFile(song);
        stringstream ss;
        ss<<music.getDuration().asSeconds();

        qDebug()<<"6.5";

        string howLong;
        ss>>howLong;

        qDebug()<<"7";

        ui->startLabel->setText(howLong.c_str());
        ui->endLabel->setText(howLong.c_str());

        qDebug()<<"8";

        offsetValue = 0;

        qDebug()<<"9";
        ui->progessSlider->setMinimum(0);
        ui->progessSlider->setMaximum(100);
        ui->progessSlider->setSingleStep(1);

        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(updateStatusBar()));
        timer->start(1);
        ui->startLabel->setText("0");

        connect(ui->playButton,SIGNAL(clicked()),this,SLOT(playMusic()));
        connect(ui->stopButton,SIGNAL(clicked()),this, SLOT(stopMusic()));
        connect(ui->prevButton,SIGNAL(clicked()), this, SLOT(prevSong()));
        connect(ui->nextButton,SIGNAL(clicked()),this,SLOT(nextSong()));
        connect(ui->loopButton,SIGNAL(clicked()),this,SLOT(loop()));

        connect(ui->progessSlider,SIGNAL(sliderPressed()),this,SLOT(sliderPause()));
        connect(ui->progessSlider,SIGNAL(sliderReleased()),this,SLOT(sliderReleased()));
    }

    catch(musicEngineErrors e)
    {
        if(e == FILE_NOT_FOUND)
            cout<<"File Not Found!!!!"<<endl;
    }

    qDebug()<<"Finished player\n";

}

Player::Player()
{

}

/*Player& Player::operator=(const Player &other)
{
    if(this != &other)
        copy(other);
    return *this;
}
*/
Player::~Player()
{
    delete ui;
}

void Player::copy(const Player &other)
{
    ui = other.ui;
    //music = other.music;
    //musicWasPlaying = other.musicWasPlaying;
    offsetValue = other.offsetValue;
}

void Player::sliderPause()
{
    music.stop();
    musicWasPlaying = music.getStatus() == Music::Playing;
}

void Player::sliderReleased()
{
    offsetValue = ui->progessSlider->value()/100.0*music.getDuration().asSeconds();

    if(!musicWasPlaying)
        music.stop();
}


void Player::updateStatusBar()
{
    if(music.getStatus() == Music::Playing)
        {
            int percentage = 100*music.getPlayingOffset().asSeconds()/music.getDuration().asSeconds();
            ui->progessSlider->setValue(percentage);
            ui->progessSlider->update();
        }
}

void Player::pauseMusic()
{
    music.pause();
}

void Player::stopMusic()
{
    music.stop();
}

void Player::playMusic()
{
    cout<<"Starting thread";
    // Load an ogg music file
    ui->songInfo->setText(music.information().c_str());
    ui->songInfo->update();
    try
    {
        // Display music informations
        // Play it
        music.setPlayingOffset(seconds(offsetValue));
        music.play();

    }
        // Loop while the music is playing
    catch(musicEngineErrors e)
    {
        if(e == FILE_NOT_FOUND)
            cout<<"Music file not found!"<<endl;
        if(e == FILE_NOT_LOADED)
             cout<<"Music file not loaded. Cannot proceed!"<<endl;
        if(e == BAD_VOLUME)
            cout<<"Volume set to an illegal level!"<<endl;
    }
    catch(...)
    {
        cout<<"An unknown error occurred!!"<<endl;
    }
}

void Player::nextSong()
{
    music.stop();
    musicRow = musicRow + 1;
    if((musicRow >= MainWindow().lib.size()) && (playerLoop))
    {
        musicRow = 0;
    }
    else if((musicRow >= MainWindow().lib.size()))
    {
        //delete ui;
        return;
    }
    cout<<musicRow;
    string song = MainWindow().lib[musicRow].c_str();
    cout<<song<<endl;

    string toPlay = "C:\\Users\\Jasmine\\Documents\\CS 3A\\myTunesWindows\\resources\\" + song;
    music.loadFromFile(toPlay);
    playMusic();
}

void Player::prevSong()
{
    music.stop();
    musicRow = musicRow - 1;
    if((musicRow <= 0) &&(playerLoop))
    {
        musicRow = MainWindow().lib.size() - 1;
    }
    else if(musicRow >= MainWindow().lib.size())
    {
        //delete ui;
        return;
    }
    cout<<musicRow;
    string song = (MainWindow().lib[musicRow].c_str());
    cout<<song<<endl;

    string toPlay = "C:\\Users\\Jasmine\\Documents\\CS 3A\\myTunesWindows\\resources\\" + song;
    music.loadFromFile(toPlay);
    playMusic();

}

void Player::loop()
{
    //Playlist().loop(true);
    playerLoop = true;
}

/*
void openPlayer(string song)
{

    Player player = Player();
    qDebug()<<"Creating Player";
    player = new Player(this);
    player.music(song);
    qDebug()<<"Created Player";
    player->show();
    //return player;
}
*/
