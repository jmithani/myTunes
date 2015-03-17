#include "playlist.h"
#include <QInputDialog>

Playlist::Playlist()
{
    /*
    QInputDialog* getName = new QInputDialog;
    QString playlistName = getName->getText(, "Playlist", "Please enter the name for the new playlist.",
                                     QLineEdit::Normal);
    qDebug()<<playlistName;
    //http://www.codeprogress.com/cpp/libraries/qt/showQtExample.php?key=QInputDialogGetText&index=331

    MainWindow().ui->menuPlaylists->addAction(playlistName);
    */
}

Playlist::~Playlist()
{

}

Playlist::Playlist(string dir)
{
    string parent = Library().libPath + "\\playlists\\" + dir;

    QString path = QString::fromStdString(parent);
    cout<<"path = "<<path.toStdString()<<endl;
    QDir().mkpath(path);
    qDebug()<<QDir().mkpath(path);
}

//Playlist(const Playlist &other);
//Playlist& operator=(const Playlist);

void Playlist::addSong()
{
    playlist.addMusic();
}

void Playlist::deleteSong()
{
    //playlist.deleteMusic();
}

void Playlist::display(string dir)
{

}




bool loop(bool yes)
{
    if(yes == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//void loop(bool yes);
//void random(bool yes);
