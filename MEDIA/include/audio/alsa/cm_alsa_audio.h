//
// Created by sine on 19-1-22.
//

#ifndef SWEETPOTATO_CM_ALSA_AUDIO_H
#define SWEETPOTATO_CM_ALSA_AUDIO_H

#include "cm_cfg.h"
#include "alsa/asoundlib.h"
BEGIN_DECLS

typedef struct cm_alsa_dev_t{
    snd_pcm_t *pcm;
    snd_pcm_hw_params_t *params;
    int channels;
    int sample_rate;

}cm_alsa_dev;

int cm_recorder_prepare(cm_alsa_dev *cm,int channels,int sample_rate,int periods);

int cm_player_prepare(cm_alsa_dev *cm,int channels,int sample_rate,int periods);

END_DECLS
#endif //SWEETPOTATO_CM_ALSA_AUDIO_H
