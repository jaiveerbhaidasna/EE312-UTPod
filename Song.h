//
// Created by Jaiveer Bhaidasna on 10/23/2019.
//

#ifndef SONG_H
#define SONG_H
#include <string>
#include <iostream>

using namespace std;

//Song Class declaration
class Song
{
    private:
        string title;
        string artist;
        int size;

    public:
        Song(){};
        Song(string t, string a, int sz);

        string getTitle() const;
        void setTitle(string t);
        string getArtist() const;
        void setArtist(string a);
        int getSize() const;
        void setSize(int sz);
        bool operator ==(Song const &rhs);
        bool operator >(Song const &rhs);
        bool operator <(Song const &rhs);

        ~Song();

};

ostream& operator << (ostream& out, const Song &s);

#endif
