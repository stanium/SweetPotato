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
    /**RFC 5389*/
    stun_attr_type_reserved=0x0000,                 /**Reserved*/
    stun_attr_type_mapped_address=0x0001,
    stun_attr_type_response_address=0x0002,         /**(Reserved; was RESPONSE-ADDRESS)*/
    stun_attr_type_change_address=0x0003,           /**(Reserved; was CHANGE-ADDRESS)   */
    stun_attr_type_source_address=0x0004,           /**(Reserved; was SOURCE-ADDRESS)   */
    stun_attr_type_change_address=0x0005,           /**(Reserved; was CHANGED-ADDRESS)  */
    stun_attr_type_username=0x0006,
    stun_attr_type_password=0x0007,                 /**(Reserved; was PASSWORD)*/
    stun_attr_type_message_integrity=0x0008,
    stun_attr_type_error_code=0x0009,
    stun_attr_type_unknow_attributes=0x000A,
    stun_attr_type_reflected_from=0x000B,           /**(Reserved; was REFLECTED-FROM)*/
    stun_attr_type_realm=0x0014,
    stun_attr_type_nonce=0x0015,
    stun_attr_type_xor_mapped_address=0x0020,

    stun_attr_type_software=0x8022,
    stun_attr_type_alternate_server=0x8023,
    stun_attr_type_fingerprint=0x8028,

    /**RFC5766*/
    stun_attr_type_channel_number=0x000c,
    stun_attr_type_linfetime=0x000d,
    stun_attr_type_bandwidth=0x0010,
    stun_attr_type_xor_peer_address=0x0012,
    stun_attr_type_data=0x0013,
    stun_attr_type_xor_relayed_address=0x0016,
    stun_attr_type_even_port=0x0018,
    stun_attr_type_requested_transport=0x0019,
    stun_attr_type_dont_fragment=0x001a,
    stun_attr_type_timer_val=0x0021,
    stun_attr_type_reservation_token=0x0022,


}stun_attr_type;

typedef cm_stun_method_t{
    /**RFC5389*/
    stun_method_type_reserved=0x000,
    stun_method_type_binding=0x001,
    stun_method_type_reserved2=0x002,//was SharedSecret

    /**RFC5766*/
    stun_method_type_allocate=0x003,
    stun_method_type_refresh=0x004,
    stun_method_type_send=0x006,
    stun_method_type_data=0x007,
    stun_method_type_createpermission=0x008,
    stun_method_type_channelbind=0x009,
}stun_method;
typedef struct stun_message_t{
    unsigned int short Message_Type;
    unsigned int short Message_Length;
    char Transaction_ID[12];
}stun_message;
/**
 *
                        0                 1
                        2  3  4 5 6 7 8 9 0 1 2 3 4 5

                       +--+--+-+-+-+-+-+-+-+-+-+-+-+-+
                       |M |M |M|M|M|C|M|M|M|C|M|M|M|M|
                       |11|10|9|8|7|1|6|5|4|0|3|2|1|0|
                       +--+--+-+-+-+-+-+-+-+-+-+-+-+-+

                Figure 3: Format of STUN Message Type Field
 */
#endif //SWEETPOTATO_STUN_PKT_H
