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
    Song s1("1","1", 10);
    Song s2("2","2",10);
    Song s3("3","3",10);
    Song s4("4","4", 10);
    Song s5("5","5",10);
    Song s6("6","6",10);
    Song s7("7","7", 10);
    Song s8("8","8",10);
    Song s9("9","9",10);
    UtPod pod1;

    pod1.addSong(s1);
    pod1.addSong(s2);
    pod1.addSong(s3);
    pod1.addSong(s4);
    pod1.addSong(s5);
    pod1.addSong(s6);
    pod1.addSong(s7);
    pod1.addSong(s8);
    pod1.addSong(s9);
    pod1.shuffle();
    pod1.showSongList();
    cout << "\n";
    pod1.sortSongList();
    pod1.showSongList();
    cout << "\n";
    int memRem = pod1.getRemainingMemory();
    cout << memRem << " MB\n";
    pod1.clearMemory();
    memRem = pod1.getRemainingMemory();
    cout << memRem << " MB\n";
    

}