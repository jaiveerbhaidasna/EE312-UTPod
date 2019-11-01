/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod pod1;                                                         //Testing of different classes and functions
    UtPod pod2(128);                                                    //intertwined together

    Song s1("ABBA","Dancing Queen",16);
    Song s2("ABBA","Mamma Mia",8);
    Song s3("Beatles","Hey Jude",32);
    Song s3copy("Beatles","Hey Jude",16);
    Song s4("Beatles","Here Comes the Sun",32);
    Song s5("Beatles","Let It Be",16);
    Song s6("Billy Joel","Piano Man",32);
    Song s7("Elton John","Your Song",16);
    Song s7copy("Ellie Goulding","Your Song",16);
    Song s8("Michael Jackson","Beat It",16);
    Song s9,s10;
    s9.setArtist("Queen");
    s9.setTitle("Bohemian Rhapsody");
    s9.setSize(32);
    s10.setArtist("Queen");
    s10.setTitle("Another One Bites the Dust");
    s10.setSize(16);

    pod1.addSong(s1);
    pod1.addSong(s2);
    pod1.addSong(s3);
    pod1.addSong(s4);
    pod1.addSong(s5);
    pod1.addSong(s6);
    pod1.addSong(s7);
    pod1.addSong(s8);
    pod1.addSong(s9);
    pod1.addSong(s10);

    cout << "The original UtPod list of songs:\n" << endl;
    pod1.showSongList();
    cout << "Memory Remaining: " << pod1.getRemainingMemory() << " MB\n" << endl;
    cout << "Removing 'Let it Be' by The Beatles:\n" << endl;
    pod1.removeSong(s5);
    pod1.showSongList();
    cout << "Memory Remaining: " << pod1.getRemainingMemory() << " MB\n" << endl;
    cout << "Shuffling the list:\n" << endl;
    pod1.shuffle();
    pod1.showSongList();
    cout << "Shuffling the list again :\n" << endl;
    pod1.shuffle();
    pod1.showSongList();
    cout << "Sorting the shuffled list:\n" << endl;
    pod1.sortSongList();
    pod1.showSongList();
    cout << "Shuffling the list once more:\n" << endl;
    pod1.shuffle();
    pod1.showSongList();
    cout << "Sorting the shuffled list:\n" << endl;
    pod1.sortSongList();
    pod1.showSongList();
    cout << "Clearing the list:" << endl;
    pod1.clearMemory();
    pod1.showSongList();
    cout << "Memory Remaining: " << pod1.getRemainingMemory() << " MB\n" << endl;
    cout << "Trying to remove a song from an empty UtPod:" << endl;
    if(pod1.removeSong(s4) == 0)
        cout << "Somehow removed something not there?\n" << endl;
    else
        cout << "Song was not found because UtPod is empty.\n" << endl;

    cout << "Implementing UtPod2 with only 128 MB of memory:\n" << endl;
    pod2.addSong(s1);
    pod2.addSong(s1);
    pod2.addSong(s5);
    pod2.addSong(s10);
    pod2.addSong(s7);
    pod2.addSong(s8);
    pod2.addSong(s2);
    pod2.showSongList();
    cout << "Memory Remaining: " << pod2.getRemainingMemory() << " MB\n" << endl;
    cout << "Trying to add a song that's too big: (" << s4 << ")\n" << endl;
    if(pod2.addSong(s4) == 0)
    {
        cout << "Successfully added!" << endl;
        pod2.showSongList();
    }
    else
    {
        cout << "Not enough memory to add song.\n" << endl;
        pod2.showSongList();
    }
    cout << "Shuffling and showing:\n" << endl;
    pod2.shuffle();
    pod2.showSongList();
    cout << "Removing the first instance of 'Dancing Queen':\n" << endl;
    pod2.removeSong(s1);
    pod2.showSongList();
    cout << "Removing the other instance of 'Dancing Queen':\n" << endl;
    pod2.removeSong(s1);
    pod2.showSongList();
    cout << "Sorting the shuffled list:\n" << endl;
    pod2.sortSongList();
    pod2.showSongList();
    cout << "Trying to remove a song not in the list: (" << s3 << ")\n" << endl;
    if(pod2.removeSong(s3) == 0)
    {
        cout << "Successfully removed!" << endl;
        pod2.showSongList();
    }
    else
    {
        cout << "Song not found.\n" << endl;
        pod2.showSongList();
    }

    cout << "Comparing songs:" << endl;
    if(s10 == s9)
        cout << s10 << " = " << s9 << endl;
    else
        if(s10 < s9)
            cout << s10 << " < " << s9 << endl;
        else
            cout << s10 << " > " << s9 << endl;

    if(s1 == s1)
        cout << s1 << " = " << s1 << endl;
    else
        if(s1 < s1)
            cout << s1 << " < " << s1 << endl;
        else
            cout << s1 << " > " << s1 << endl;

    if(s8 == s2)
        cout << s8 << " = " << s2 << endl;
    else
        if(s8 < s2)
            cout << s8 << " < " << s2 << endl;
        else
            cout << s8 << " > " << s2 << endl;

    if(s3 == s3copy)
        cout << s3 << " = " << s3copy << endl;
    else
        if(s3 < s3copy)
            cout << s3 << " < " << s3copy << endl;
        else
            cout << s3 << " > " << s3copy << endl;

    if(s7 == s7copy)
        cout << s7 << " = " << s7copy << endl;
    else
        if(s7 < s7copy)
            cout << s7 << " < " << s7copy << endl;
        else
            cout << s7 << " > " << s7copy << endl;
}