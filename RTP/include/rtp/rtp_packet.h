//
// Created by sine on 19-1-9.
//

#ifndef PROJECT_RTP_PACKET_H
#define PROJECT_RTP_PACKET_H

#include "rtp_header.h"
typedef struct rtp_packet_s{
    rtp_header* header;
    struct {
        void *data;
        int size;
    }playload;

    struct {
        void *data;
        int size;
    }extension;
}rtp_packet;

#endif //PROJECT_RTP_PACKET_H
