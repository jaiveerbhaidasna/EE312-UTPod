//
// Created by jaive on 10/23/2019.
//
#include <ctime>
#include <iostream>
#include <cstdlib>
#include "UtPod.h"

using namespace std;

    UtPod::UtPod(){
        unsigned int currentTime =  (unsigned)time(0);
        srand(currentTime);
        memSize = MAX_MEMORY;
        songs = NULL;
    }

    UtPod::UtPod(int size){
        unsigned int currentTime =  (unsigned)time(0);
        srand(currentTime);
        if(size > MAX_MEMORY || size < 0)
            memSize = MAX_MEMORY;
        else
            memSize = size;
        songs = NULL;
    }

    int UtPod::addSong(Song const &s){

        if(s.getSize() < getRemainingMemory()){
            SongNode *temp = new SongNode;
            temp->s = s;
            temp->next = songs;
            songs = temp;
            memSize-=s.getSize();
            return SUCCESS;
        }

        return NO_MEMORY;
    }

    void UtPod::showSongList() {
        SongNode *temp = songs;

        while(temp != NULL){
            cout << temp->s << endl;
            temp = temp->next;
        }
    }

    int UtPod::getRemainingMemory() {
        SongNode *temp = songs;
        int memoryUsed = 0;

        while(temp != NULL){
            memoryUsed+=temp->s.getSize();
            temp = temp->next;
        }

        return memSize - memoryUsed;
    }

    UtPod::~UtPod(){

    }

