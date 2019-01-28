//
// Created by sine on 19-1-28.
//

#ifndef SWEETPOTATO_CM_HTTP_URL_H
#define SWEETPOTATO_CM_HTTP_URL_H
/**
 * http_URL ="http:""//"host[":"port][abs_path["?"query]]
 */
 typedef cm_http_url_t{
    char *host;
    uint16_t port;
 }http_url;

#endif //SWEETPOTATO_CM_HTTP_URL_H
