//
// Created by sine on 19-1-9.
//

#ifndef PROJECT_RTP_HEADER_H
#define PROJECT_RTP_HEADER_H
/* RFC 3550 section 5.1 - RTP Fixed Header Fields
    0                   1                   2                   3
    |0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |V=2|P|X|  CC   |M|     PT      |       sequence number         |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |                           timestamp                           |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |           synchronization source (SSRC) identifier            |
    +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
    |            contributing source (CSRC) identifiers             |
    |                             ....                              |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
*/

typedef struct rtp_header_t{
    unsigned version:2;         //版本号
    unsigned padding:1;         //填充标志
    unsigned extension:1;       //扩展标志
    unsigned csrc_cout:4;       //CSRC计数器
    unsigned marker:1;          //标记
    unsigned payloader_type:7;  //有效载荷类型
    uint16_t seq_num;           //报文的序列号
    uint32_t timestamp;         //时戳
    uint32_t ssrc;              //同步信源
    uint32_t csrc[15];          //特约信源

}rtp_header;
#endif //PROJECT_RTP_HEADER_H
