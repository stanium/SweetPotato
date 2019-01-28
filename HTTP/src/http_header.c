//
// Created by sine on 19-1-28.
//
/**
 *
 *          HTTP-message
 * Request      |       Response
 * -------------------------------
 * generic message format
 * start-line               =Request-Line   |Status-Line
 * message-header CRLF      =general-header |request-header |response-header    |entity-header
 * CRLF                     |
 * message-body             |
 * --------------------------------
 * Request-Line =Method SP Request-URI SP HTTP-Version CRLF
 * Status-Line  =HTTP-Version sp Status-Code SP Reason-Phrase CRLF
 *
 */
