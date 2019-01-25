//
// Created by sine on 19-1-11.
//

#ifndef PROJECT_HTTP_HEADER_H
#define PROJECT_HTTP_HEADER_H
/**
 *  RFC2616
 *  https://tools.ietf.org/html/rfc2616#section-14.5
 */

typedef enum http_header_type_e{
    http_type_Accept,
    http_type_Accept_Charset,
    http_type_Accept_Encoding,
    http_type_Accept_Language,
    http_type_Accept_Ranges,
    http_type_Age,
    http_type_Allow,
    http_type_Authorization,
    http_type_Cache_Control,
    http_type_Cache_Control,
    http_type_Connection,
    http_type_Content_Encoding,
    http_type_Content_Language,
    http_type_Content_Location,
    http_type_Content_MD5,
    http_type_Content_Range,
    http_type_Content_Type,
    http_type_Date,
    http_type_ETag,
    http_type_Expect,
    http_type_Expires,
    http_type_From,
    http_type_Host,
    http_type_If_Match,
    http_type_If_Modified_Since,
    http_type_If_None_Match,
    http_type_If_Range,
    http_type_If_Unmodified_Since,
    http_type_Last_Modified,
    http_type_Location,
    http_type_Max_Forwards,
    http_type_Pragma,
    http_type_Proxy_Authenricate,
    http_type_Proxy_Authorization,
    http_type_Range,
    http_type_Referer,
    http_type_Retry_After,
    http_type_Server,
    http_type_TE,
    http_type_Trailer,
    http_type_Transfer_Encoding,
    http_type_Upgrade,
    http_type_User_Agent,
    http_type_Vary,
    http_type_Via,
    http_type_Warning,
    http_type_WWW_Authenticate,


}http_header_type;


typedef struct http_message_t{

}http_message;

int http_request();
int http_response();
#endif //PROJECT_HTTP_HEADER_H
