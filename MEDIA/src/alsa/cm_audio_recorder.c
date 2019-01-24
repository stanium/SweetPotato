//
// Created by sine on 19-1-22.
//

#include "audio/alsa/cm_alsa_audio.h"
//#include "alsa/asoundlib.h"
int cm_recorder_init(){

}

int cm_recorder_prepare(cm_alsa_dev *cm,int channels,int sample_rate,int periods){
    //cm_alsa_dev *cm;

    snd_pcm_format_t pcm_format;
    snd_pcm_access_t pcm_access;
    snd_pcm_uframes_t pcm_uframes;
    unsigned int val;
    int dir;
    int frames;
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
        printf("snd_pcm_hw_params_malloc err\n");
    }
#endif
    if((err=snd_pcm_hw_params_any(cm->pcm,cm->params))!=0){
        printf("snd_pcm_hw_params_any err\n");
    }

    pcm_access=SND_PCM_ACCESS_RW_INTERLEAVED;
    if((err=snd_pcm_hw_params_set_access(cm->pcm,cm->params,pcm_access))!=0){
        printf("snd_pcm_hw_params_set_access err\n");
    }

    pcm_format=SND_PCM_FORMAT_S16_LE;
    if((err=snd_pcm_hw_params_set_format(cm->pcm,cm->params,pcm_format))!=0){
        printf("snd_pcm_hw_params_set_format err\n");
    }
    /**设置通道*/
    val=channels;
    if((err= snd_pcm_hw_params_set_channels(cm->pcm,cm->params,&val))!=0){
        printf("snd_pcm_hw_params_set_channels err\n");
    }
    cm->channels=val;

    /**设置采样频率*/
    /**snd_pcm_hw_params_set_rate和snd_pcm_hw_params_set_rate_near
     *后者应该是根据硬件取设定的比较近的值
     */
    val=sample_rate;/**for example 44100*/
    if((err= snd_pcm_hw_params_set_rate_near(cm->pcm,cm->params,&val,0))!=0){

    }
    cm->sample_rate=val;

    /**设置*/
    /**
     * SND_PCM_FORMAT_S8    :1*8bit
     * SND_PCM_FORMAT_S16_LE:2*8bit
     * SND_PCM_FORMAT_U24_LE:3*8bit
     * SND_PCM_FORMAT_S32_LE:4*8bit
     * ...
     */
    //snd_pcm_hw_params_set_periods();
    //snd_pcm_hw_params_set_periods_near();
    //snd_pcm_hw_params_set_period_size();
    //snd_pcm_hw_params_set_period_size_near()
    //snd_pcm_hw_params_set_period_time();
   // snd_pcm_hw_params_set_period_time_near();
    pcm_uframes=periods;
    if((err=snd_pcm_hw_params_set_period_size_near(cm->pcm,cm->params,&pcm_uframes,0))!=0){

    }

    /**把参数设置进驱动*/
    if(snd_pcm_hw_params(cm->pcm,cm->params)<0){

    }

    /*
    snd_pcm_uframes_t buffer_size;
    snd_pcm_uframes_t chunk_size;
    snd_pcm_hw_params_get_period_size(cm->params,&chunk_size,0);
    snd_pcm_hw_params_get_buffer_size(cm->params,&buffer_size);
    if(chunk_size==buffer_size){
        printf("Can't use period equal to buffer size")
    }
     */
    if((err=snd_pcm_prepare(cm->pcm))!=0){

    }

}

int cm_recorder_start(cm_alsa_dev *cm){
    int err;

    if((err=snd_pcm_start(cm->pcm))!=0){

    }
}