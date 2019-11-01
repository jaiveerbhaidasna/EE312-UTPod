//
// Created by jaive on 10/23/2019.
//
#include <ctime>
#include <iostream>
#include <cstdlib>
#include "UtPod.h"

using namespace std;

    //Default constructor, seeds random number generator, initializes SongNode head pointer, initializes UtPod size to
    //max memory
    UtPod::UtPod(){
        unsigned int currentTime =  (unsigned)time(0);
        srand(currentTime);
        memSize = MAX_MEMORY;
        songs = NULL;
    }

    //Default constructor, seeds random number generator, initializes SongNode head pointer, initializes UtPod size to
    //input size parameter
    UtPod::UtPod(int size){
        unsigned int currentTime =  (unsigned)time(0);
        srand(currentTime);
        if(size > MAX_MEMORY || size < 0)
            memSize = MAX_MEMORY;
        else
            memSize = size;
        songs = NULL;
    }

    //Method add song, inputs a given song and adds it to the UtPod linked list if enough size remaining, returns an
    //error code otherwise
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

    //Method remove song, inputs a given song and removes the first instance from the UtPod linked list if found,
    //returns an error code otherwise
    int UtPod::removeSong(Song const &s) {
        SongNode *prev = NULL;
        SongNode *ptr = songs;
        bool found = false;

        if(ptr != NULL)
        {
            while (ptr != NULL && !found) {
                if (ptr->s == s) {
                    found = true;
                } else {
                    prev = ptr;
                    ptr = ptr->next;
                }
            }

            if (prev == NULL) {
                songs = ptr->next;
                delete ptr;
                return SUCCESS;
            }

            if (found) {
                prev->next = ptr->next;
                delete ptr;
                return SUCCESS;
            }
        }
        return NOT_FOUND;
    }

    //Method shuffle, takes the linked list of songs in a given UtPod and randomly shuffles them using swaps and a
    //random number generator
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
            for(int x = 0; x < numSongs * 5; x++)
            {
                rand1 = (rand() % numSongs);
                rand2 = (rand() % numSongs);
                SongNode *ind1 = songs;
                SongNode *ind2 = songs;

                for(int y = 0; y < rand1; y++)
                    ind1 = ind1->next;
                for(int z = 0; z < rand2; z++)
                    ind2 = ind2->next;

                ind1->s.swap(ind2->s);
            }
        }


    }

    //Method sort, takes the given UtPod song linked list and selection sorts until the list is ordered by artist, then
    //then title, then size
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
            index->s.swap(lowest->s);
            index = index->next;
        }
    }

    //Method show, prints the linked list of songs to the console starting at the head
    void UtPod::showSongList() {
        SongNode *temp = songs;

        while(temp != NULL){
            cout << temp->s << endl;
            temp = temp->next;
        }
        cout << "\n";
    }

    //Method clear memory, takes the linked list of songs in the UtPod and clears it until is empty
    void UtPod::clearMemory() {
        SongNode *prev = NULL;

        while(songs != NULL)
        {
            prev = songs;
            songs = songs->next;
            delete prev;
        }
    }

    //Method getRemainingMemory, takes the total memory of the given UtPod and subtracts the total memory of the
    //songs in the list to return remaining free memory
    int UtPod::getRemainingMemory() {
        SongNode *temp = songs;
        int memoryUsed = 0;

        while(temp != NULL){
            memoryUsed+=temp->s.getSize();
            temp = temp->next;
        }

        return memSize - memoryUsed;
    }

    //Destructor for the UtPod class, just clears the memory taken by the UtPod
    UtPod::~UtPod(){
        clearMemory();
    }

