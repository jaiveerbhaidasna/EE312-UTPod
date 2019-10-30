//
// Created by jaive on 10/23/2019.
//

#include "Song.h"

using namespace std;

    Song::Song(string t, string a, int sz) {
        title = t;
        artist = a;
        size = sz;
    }

    string Song::getTitle() const {
        return title;
    }

    string Song::getArtist() const {
        return artist;
    }

    int Song::getSize() const {
        return size;
    }

    void Song::setTitle(string t) {
        title = t;
    }

    void Song::setArtist(string a) {
        artist = a;
    }

    void Song::setSize(int sz) {
        size = sz;
    }

    bool Song::operator ==(Song const &rhs) {
        return (title == rhs.title && artist == rhs.artist && size == rhs.size);
    }

    bool Song::operator >(Song const &rhs) {
        if(artist > rhs.artist)
            return true;
        else
            if(artist == rhs.artist)
            {
                if(title > rhs.title)
                    return true;
                else
                    if(title == rhs.title)
                    {
                        return size > rhs.size;
                    }
                    else
                        return false;
            }
            else
                return false;
    }

    bool Song::operator <(Song const &rhs){
        if(artist < rhs.artist)
            return true;
        else
            if(artist == rhs.artist)
            {
                if(title < rhs.title)
                    return true;
                else
                    if(title == rhs.title)
                    {
                        return size < rhs.size;
                    }
                    else
                        return false;
            }
            else
                return false;
    }

    Song::~Song() {

    }

    ostream& operator << (ostream& out, const Song &s)
    {
        out << s.getTitle() << " - " << s.getArtist() << " (" << s.getSize() << " MB)";
        return out;
    }