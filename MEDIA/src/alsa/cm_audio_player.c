//
// Created by sine on 19-1-22.
//
#include "pthread.h"
#include "alsa/asoundlib.h"
#include "audio/alsa/cm_alsa_audio.h"


int cm_player_init(cm_alsa_dev *cm){

    int err=snd_pcm_open(cm->pcm,"default",SND_PCM_STREAM_PLAYBACK,0);
    if(err<0){
        printf("snd_pcm_open err\n");
        return -1;
    }

}

int cm_player_prepare(cm_alsa_dev *cm,int channels,int sample_rate ){

}

void *player_cb(void *arg){

}
int cm_player_start(){
    pthread_t pid;
    return pthread(pid,NULL,player_cb,NULL);
}

int cm_player_stop(){}

int cm_player_deinit(){}