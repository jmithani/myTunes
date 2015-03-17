#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "library.h"
#include "musicEngine.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <string>
#include <vector>

class Playlist : public musicEngine
{
public:
    Playlist();
    Playlist(string dir);
    ~Playlist();
    Playlist(const Playlist &other);
    Playlist& operator=(const Playlist);

    void addSong();
    void deleteSong();
    void display(string dir);
    //bool shuffle(bool yes);
    bool loop(bool yes);
    void random(bool yes);

private:
    Library playlist;


};

#endif // PLAYLIST_H
