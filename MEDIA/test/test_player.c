//
// Created by sine on 19-1-24.
//
#include "audio/alsa/cm_alsa_audio.h"
#include "stdlib.h"



int main(){
   // cm_alsa_dev player;
   // memset(&player,0, sizeof(cm_alsa_dev));
   // cm_player_prepare(&player,2,44100,8);
   struct snd_pcm_t *pcm;
   int err;
    if((err=snd_pcm_open(pcm,"default",SND_PCM_STREAM_PLAYBACK,0))!=0){
        printf("snd_pcm_open err\n");
        return -1;
    }


}