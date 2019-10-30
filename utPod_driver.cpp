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
    Song s1("Hey Jude","The Beatles", 10);
    Song s2("Pokerface","Lady Gaga",10);
    Song s3;
    s3.setTitle("Scared of the Dark");
    s3.setArtist("Lil Wayne");
    s3.setSize(10);
    UtPod pod1;

    pod1.addSong(s1);
    pod1.showSongList();
    pod1.addSong(s2);
    pod1.showSongList();
    pod1.addSong(s3);
    pod1.showSongList();
    

}