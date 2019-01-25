//
// Created by sine on 19-1-23.
//

#include "audio/alsa/cm_alsa_audio.h"

int main(){
    cm_alsa_dev dev;
    memset(&dev,0,sizeof(dev));
    cm_alsa_dev *p=&dev;

    cm_recorder_prepare(p,2,44100,8);
}