//
// Created by sine on 19-1-25.
//

#include "linux/v4l2-common.h"
#include "linux/videodev2.h"
#include "sys/ioctl.h"
#include "malloc.h"
#include "sys/mman.h"


typedef struct cm_v4l2_dev_t{

    int fd;
}cm_v4l2_dev;


int cm_v4l2_init(){
    struct v4l2_capability capability;
    struct v4l2_requestbuffers requestbuffers;
    struct v4l2_input   input;
    struct v4l2_standard standard;
    struct v4l2_format  format;
    struct v4l2_buffer buffer;
    struct v4l2_crop crop;
    int fd;
    int err;

    if((err=open("/dev/video0",O_RDWR))<0){
        printf("open fail\n");
        return -1;
    }
    /**检查设备的能力*/
    memset(&capability,0, sizeof(capability));

    if(ioctl(fd,VIDIOC_QUERYCAP,&capability)<0)
    {
        return -1;
    }

    if(!(capability.capabilities&V4L2_CAP_VIDEO_CAPTURE)){
        return -1;
    }

    if(!(capability.capabilities&V4L2_CAP_STREAMING)){
        return -1;
    }

    /**捕获格式设置*/
    memset(&format,0, sizeof(format));
    format.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
    format.fmt.pix.height=480;
    format.fmt.pix.width=320;
    format.fmt.pix.pixelformat=;
    format.fmt.pix.field=V4L2_FIELD_INTERLACED;

    if(ioctl(fd,VIDIOC_S_FMT,&format)<0){

    }

    /**申请请求缓冲,并进行mmap映射*/
    memset(&requestbuffers,0, sizeof(requestbuffers));
    requestbuffers.count=6;
    requestbuffers.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
    requestbuffers.memory=V4L2_MEMORY_MMAP;
    if(ioctl(fd,VIDIOC_REQBUFS,&requestbuffers)<0){

    }

    typedef struct {
        int size;
        void *start;
    }VideoBuffers;

    VideoBuffers *videoBuffers= calloc(requestbuffers.count,sizeof(VideoBuffers));
    for(int i=0;i<requestbuffers.count;i++){
        memset(&buffer,0, sizeof(buffer));
        buffer.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buffer.memory=V4L2_MEMORY_MMAP;
        buffer.index=i;
        if(ioctl(fd,VIDIOC_QUERYBUF,&buf)==-1){
            return -1;
        }
        videoBuffers[i]->size=buffer.length;
        videoBuffers[i]->start=mmap(NULL,buffer.length,PROT_READ|PROT_WRITE,MAP_SHARED,fd,buffer.m.offset);
        if(videoBuffers[i].start==MAP_FAILED){
            return -1;
        }
    }
}

int cm_v4l2_start(cm_v4l2_dev *dev){
    /**打开视频设备*/
    int type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if(ioctl(dev->fd,VIDIOC_STREAMON,&type)<0){

    }
}