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
    http_type_Connection,
    http_type_Content_Encoding,
    http_type_Content_Language,
    http_type_Content_Length,
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

typedef enum http_method_t{
    http_method_OPTIONS,
    http_method_GET,
    http_method_HEAD,
    http_method_POST,
    http_method_PUT,
    http_method_DELETE,
    http_method_TRACE,
    http_method_CONNECT,
};

char * http_get_name_by_type(http_header_type type){
    switch (type){
        case http_type_Accept:
            return "Accept";
        case http_type_Accept_Charset:
            return "Accept-Charset";
        case http_type_Accept_Encoding:
            return "Accept-Encoding";
        case    http_type_Accept_Language:
            return "Accept-Language";
        case http_type_Accept_Ranges:
            return "Accept-Ranges";
        case      http_type_Age:
            return "Age";
        case     http_type_Allow:
            return "Allow";
        case    http_type_Authorization:
            return "Authorization";
        case    http_type_Cache_Control:
            return "Cache-Control";
        case    http_type_Connection:
            return "Connection";
        case    http_type_Content_Encoding:
            return "Content-Encoding";
        case    http_type_Content_Language:
            return "Content-Language";
        case    http_type_Content_Length:
            return "Content-Length";
        case    http_type_Content_Location:
            return "Content-Location";
        case    http_type_Content_MD5:
            return "Content-MD5";
        case    http_type_Content_Range:
            return "Content-Range";
        case    http_type_Content_Type:
            return "Content-Type";
        case    http_type_Date:
            return "Date";
        case    http_type_ETag:
            return "ETag";
        case    http_type_Expect:
            return "Expect";
        case    http_type_Expires:
            return "Expires";
        case    http_type_From:
            return "From";
        case    http_type_Host:
            return "Host";
        case    http_type_If_Match:
            return "If-Match";
        case    http_type_If_Modified_Since:
            return "If-Modified-Since";
        case    http_type_If_None_Match:
            return "If-None-Match";
        case    http_type_If_Range:
            return "If-Range";
        case    http_type_If_Unmodified_Since:
            return "If-Unmodified-Since";
        case    http_type_Last_Modified:
            return "Last-Modified";
        case    http_type_Location:
            return "Location";
        case    http_type_Max_Forwards:
            return "Max-Forwards";
        case    http_type_Pragma:
            return "Pragma";
        case    http_type_Proxy_Authenricate:
            return "Proxy-Authenticate";
        case    http_type_Proxy_Authorization:
            return "Proxy-Authorization";
        case    http_type_Range:
            return "Range";
        case    http_type_Referer:
            return "Referer";
        case    http_type_Retry_After:
            return "Retry-After";
        case    http_type_Server:
            return "Server";
        case    http_type_TE:
            return "TE";
        case    http_type_Trailer:
            return "Trailer";
        case    http_type_Transfer_Encoding:
            return "Transfer-Encoding";
        case    http_type_Upgrade:
            return "Upgrade";
        case    http_type_User_Agent:
            return "User-Agent";
        case    http_type_Vary:
            return "Vary";
        case    http_type_Via:
            return "Via";
        case    http_type_Warning:
            return "Warning";
        case    http_type_WWW_Authenticate:
            return "WWW-Authenticate";
        default:
            return "unknow-header";
    }
}

typedef struct http_message_t{

}http_message;

//int http_request();
//int http_response();
#endif //PROJECT_HTTP_HEADER_H
