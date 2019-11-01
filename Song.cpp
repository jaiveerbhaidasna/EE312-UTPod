//
// Created by jaive on 10/23/2019.
//

#include "Song.h"

using namespace std;

    Song::Song(string a, string t, int sz) {
        artist = a;
        title = t;
        size = sz;
    }

    string Song::getArtist() const {
        return artist;
    }

    string Song::getTitle() const {
        return title;
    }

    int Song::getSize() const {
        return size;
    }

    void Song::setArtist(string a) {
        artist = a;
    }

    void Song::setTitle(string t) {
        title = t;
    }

    void Song::setSize(int sz) {
        size = sz;
    }

    //Function that is called by an object of the Song class, that swaps the contest of the caller and a second Song
    void Song::swap(Song &rhs){
        Song temp = rhs;
        rhs = *this;
        *this = temp;
    }

    //Checks if all fields of two Songs are exactly equal
    bool Song::operator ==(Song const &rhs) {
        return (title == rhs.title && artist == rhs.artist && size == rhs.size);
    }

    //Checks if the caller song is greater than the parameter Song, by first comparing artists, then titles, then size
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

    //Checks if the caller song is lesser than the parameter Song, by first comparing artists, then titles, then size
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

    //Prints a song by first printing title, then artist, then size
    ostream& operator << (ostream& out, const Song &s)
    {
        out << s.getTitle() << " - " << s.getArtist() << " (" << s.getSize() << " MB)";
        return out;
    }