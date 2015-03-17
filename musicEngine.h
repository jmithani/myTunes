#ifndef musicEngine_H
#define musicEngine_H
#include <SFML/Audio.hpp>
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
using namespace sf;

enum musicEngineErrors { FILE_NOT_FOUND, FILE_NOT_LOADED, BAD_VOLUME, BAD_PITCH};

class musicEngine : public Music
{
    public:
        musicEngine();
        ~musicEngine();
        musicEngine(string whatToPlay);

        void play();
        void 	pause ();
        void 	stop ();
        Time getDuration() const;
        unsigned int 	getChannelCount () const;
        unsigned int 	getSampleRate () const;
        Status 	getStatus () const;
        void 	setLoop (bool loop);
        bool 	getLoop () const;
        void 	setPitch (float pitch);
        void 	setVolume (float volume);
        void    setPlayingOffset(Time timeOffset);
        Time    getPlayingOffset() const;
        void 	setPosition (float x, float y, float z);
        void 	setPosition (const Vector3f &position);
        void 	setRelativeToListener (bool relative);
        void 	setMinDistance (float distance);
        void 	setAttenuation (float attenuation);
        void    setWhatToPlay(string whatToPlay);
        float 	getPitch () const;
        float 	getVolume () const;
        Vector3f 	getPosition () const;
        bool 	isRelativeToListener () const;
        float 	getMinDistance () const;
        float 	getAttenuation () const;
        string currentlyPlaying() const;
        string information() const;
        void loadFromFile(string file);

        friend
        ostream& operator<<(ostream& out, const musicEngine &engine);

    private:
        string currentPlay;
        bool musicLoaded;

        void loadFile(string &file);
        void safe() const;
};

#endif // musicEngine_H
