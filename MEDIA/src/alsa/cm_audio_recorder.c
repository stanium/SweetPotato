//
// Created by sine on 19-1-22.
//

#include "audio/alsa/cm_alsa_audio.h"
//#include "alsa/asoundlib.h"
int cm_recorder_init(){

}

int cm_recorder_prepare(cm_alsa_dev *cm,int channels,int sample_rate){
    //cm_alsa_dev *cm;

    snd_pcm_format_t pcm_format;
    snd_pcm_access_t pcm_access;
    unsigned int val;
    int dir;

    int err;
    if((err=snd_pcm_open(cm->pcm,"default",SND_PCM_STREAM_CAPTURE,0))!=0){
        printf("snd_pcm_open err\n");
        return -1;
    }

#if 0
    if((err=snd_pcm_hw_params_alloca(&cm->params))!=0){

    }
#else
    if((err=snd_pcm_hw_params_malloc(&cm->params))!=0){

    }
#endif
    if((err=snd_pcm_hw_params_any(cm->pcm,cm->params))!=0){

    }

    pcm_access=SND_PCM_ACCESS_RW_INTERLEAVED;
    if((err=snd_pcm_hw_params_set_access(cm->pcm,cm->params,pcm_access))!=0){

    }

    pcm_format=SND_PCM_FORMAT_S16_LE;
    if((err=snd_pcm_hw_params_set_format(cm->pcm,cm->params,pcm_format))!=0){

    }
    /**设置通道*/
    cm->channels=channels;
    if((err= snd_pcm_hw_params_set_channels(cm->pcm,cm->params,cm->channels))!=0){

    }
    /**设置采样频率*/
    val=cm->sample_rate=sample_rate;
    if((err= snd_pcm_hw_params_set_rate_near(cm->pcm,cm->params,sample_rate,&val,&dir))!=0){

    }

    /**设置*/
    if((err=snd_pcm_hw_params_set_period_size_near(cm->pcm,cm->params))!=0){

    }


}