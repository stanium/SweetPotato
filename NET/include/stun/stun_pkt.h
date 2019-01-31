//
// Created by sine on 19-1-31.
//

#ifndef SWEETPOTATO_STUN_PKT_H
#define SWEETPOTATO_STUN_PKT_H
/**
 * +------------------------------------+
 * +STUN客户端                 STUN服务器
 * +    |---建立连接            -->|
 * +    |---发送共享私密请求     -->|
 * +    |<--发送共享私密错误响应  ---|
 * +    |---发送共享私密请求     -->|
 * +    |<--发送共享私密响应     ---|
 * +    |---发送捆绑请求        -->|
 * +    |<--发送捆绑错误响应     ---|
 * +    |---发送捆绑请求        -->|
 * +    |<--发送捆绑响应        ---|
 * +------------------------------------+
 */
typedef cm_stun_attr_type_t{
    stun_attr_type_reserved=0x0000,
    stun_attr_type_mapped_address=0x0001,
    stun_attr_type_response_address=0x0002,
    stun_attr_type_change_address=0x0003,
    stun_attr_type_source_address=0x0004,
    stun_attr_type_change_address=0x0005,
    stun_attr_type_username=0x0006,
    stun_attr_type_password=0x0007,
    stun_attr_type_message_integrity=0x0008,
    stun_attr_type_error_code=0x0009,
    stun_attr_type_unknow_attributes=0x000A,
    stun_attr_type_reflected_from=0x000B,
    stun_attr_type_realm=0x0014,
    stun_attr_type_nonce=0x0015,
    stun_attr_type_xor_mapped_address=0x0020,

    stun_attr_type_software=0x8022,
    stun_attr_type_alternate_server=0x8023,
    stun_attr_type_fingerprint=0x8028,
}stun_attr_type;

typedef struct stun_message_t{
    unsigned int short Message_Type;
    unsigned int short Message_Length;
    char Transaction_ID[12];
}stun_message;
#endif //SWEETPOTATO_STUN_PKT_H
