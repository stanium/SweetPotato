//
// Created by sine on 19-1-15.
//

#ifndef SWEETPOTATO_SIP_REGISTER_H
#define SWEETPOTATO_SIP_REGISTER_H

/**注册流程
 +------------------------------+
    终端代理A        代理服务器
 +      |---REGISTER(1)-->|     +
 +      |<-- 401(2)    ---|     +
 +      |---REGISTER(3)-->|     +
 +      |<--200 OK(3)  ---|     +
 +------------------------------+
 */


/**注销流程
 +------------------------------+
    终端代理A        代理服务器
 +      |---REGISTER(1)-->|     +
 +      |<--200 OK(2)  ---|     +
 +------------------------------+
 */
#endif //SWEETPOTATO_SIP_REGISTER_H
