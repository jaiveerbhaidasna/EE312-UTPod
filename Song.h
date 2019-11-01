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
        string artist;                          //Variables for storing information about each song
        string title;
        int size;

    public:

        //Default constructor b/c the compiler gets mad when trying to create SongNodes
        Song(){};

        //Overloaded constructor for song initialization
        Song(string a, string t, int sz);

        //Function that returns the string artist of a Song
        string getArtist() const;

        //Function that sets the string artist of a Song based on an input parameter
        void setArtist(string a);

        //Function that returns the string title of a Song
        string getTitle() const;

        //Function that sets the string title of a Song based on an input parameter
        void setTitle(string t);

        //Function that returns the integer size of a Song
        int getSize() const;

        //Function that sets the integer size of a Song based on an input parameter
        void setSize(int sz);

        //Function that swaps the contents of two songs and returns them to their original locations
        void swap(Song &rhs);

        //Overloaded operator == for two songs that deems if they are equal to one another in terms of artist, title,
        //and size, returns true if so, false otherwise
        bool operator ==(Song const &rhs);

        //Overloaded operator > for two songs that deems if the first song is larger in terms of artist, title,
        //and size, returns true if so, false otherwise
        bool operator >(Song const &rhs);

        //Overloaded operator < for two songs that deems if the first song is smaller in terms of artist, title,
        //and size, returns true if so, false otherwise
        bool operator <(Song const &rhs);

        //Destructor for the Song class, since no memory is dynamically allocated for songs, it will essentially do
        //nothing
        ~Song(){};

};

//Overloaded operator to print Songs in the necessary format
ostream& operator << (ostream& out, const Song &s);

#endif
