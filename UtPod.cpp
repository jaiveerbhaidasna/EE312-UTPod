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
            return SUCCESS;
        }

        return NO_MEMORY;
    }

    int UtPod::removeSong(Song const &s) {
        SongNode *prev = NULL;
        SongNode *ptr = songs;
        bool found = false;

        while(ptr != NULL && !found){
            if(ptr->s == s){
                found = true;
            }
            else
            {
                prev = ptr;
                ptr = ptr->next;
            }
        }

        if(prev == NULL)
        {
            songs = ptr->next;
            delete ptr;
            return SUCCESS;
        }

        if(found)
        {
            prev->next = ptr->next;
            delete ptr;
            return SUCCESS;
        }

        return NOT_FOUND;
    }

    void UtPod::shuffle() {
        int numSongs = 0;
        int rand1 = 0, rand2 = 0;
        SongNode *trav = songs;

        while(trav!= NULL)
        {
            numSongs++;
            trav = trav->next;
        }

        if(numSongs >= 2){
            for(int x = 0; x < numSongs * 2; x++)
            {
                rand1 = (rand() % numSongs);
                rand2 = (rand() % numSongs);
                SongNode *ind1 = songs;
                SongNode *ind2 = songs;

                for(int y = 0; y < rand1; y++)
                    ind1 = ind1->next;
                for(int z = 0; z < rand2; z++)
                    ind2 = ind2->next;

                swap(ind1->s,ind2->s);
            }
        }


    }

    void swap(Song &s1, Song &s2) {
        Song temp = s1;
        s1 = s2;
        s2 = temp;
    }

    void UtPod::sortSongList() {
        SongNode *index = songs;

        while(index != NULL)
        {
            SongNode *lowest = index;
            SongNode *current = index->next;
            while(current != NULL)
            {
                if(current->s < lowest->s)
                    lowest = current;
                current = current->next;
            }
            swap(index->s,lowest->s);
            index = index->next;
        }
    }

    void UtPod::showSongList() {
        SongNode *temp = songs;

        while(temp != NULL){
            cout << temp->s << endl;
            temp = temp->next;
        }
    }

    void UtPod::clearMemory() {
        SongNode *prev = NULL;

        while(songs != NULL)
        {
            prev = songs;
            songs = songs->next;
            delete prev;
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
        clearMemory();
    }

