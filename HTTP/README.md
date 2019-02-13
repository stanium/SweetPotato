<h2> <a href='https://tools.ietf.org/html/rfc2616#section-14.5'>参考地址</a>
</h2>
<h2>URI</h2>
<h5>Universal Resource Identifier 统一资源标志符</h5>
<p>格式：协议名称://域名.根域名/目录/文件名.后缀</p>
<ol>
<li>[scheme:]scheme-specific-part[#fragment]</li>
<li>[scheme:][//authority][path][?query][#fragment]</li>
<li>[scheme:][//host:port][path][?query][#fragment]</li>
</ol>
<h2>URL</h2>
<h5>Universal Resource Locator 统一资源定位符</h5>
<h2>URN</h2>
<h5> Universal Resource Name 统一资源名称</h5>

<h2> Http Message </h2>

<h3>Message Types</h3>
<p>HTTP-message    = Request|Response</p>

<h5>generic-message格式</h5>

start-line<br>
*(message-header CRLF)<br>
CRLF<br>
\[message-body\]<br>

<h3>Message Headers</h3>
<table>
    <tr>
     <th>general-header</th>
     <th>request-header</th>
     <th>response-header</th>
     <th>entity-header</th>
    </tr>
   <tr>
       <td>
            <text>
                Cache-Control<br>
                Connection<br>
                Date<br>
                Pragma<br>
                Trailer<br>
                Transfer-Encoding<br>
                Upgrade<br>
                Via<br>
                Warning<br>
            </text>
       </td>
       <td>
            <text>
                Accept<br>
                Accept-Charset<br>
                Accept-Encoding<br>
                Accept-Language<br>
                Authorization<br>
                Expect<br>
                From<br>
                Host<br>
                If-Match<br>
                If-Modified-Since<br>
                If-None-Match<br>
                If-Range<br>
                If-Unmodified-Since<br>
                Max-Forwards<br>
                Proxy-Authorization<br>
                Range<br>
                Referer<br>
                TE<br>
                User-Agent<br>
            </text>
       </td>
       <td>
            <text>
                Accept-Ranges<br>
                Age<br>
                ETag<br>
                Location<br>
                Proxy-Authenticate<br>
                Retry-After<br>
                Server<br>
                Vary<br>
                WWW-Authenticate<br>
            </text>
       </td>
       <td>
            <text>
                Allow<br>
                Content-Encoding<br>
                Content-Language<br>
                Content-Length<br>
                Content-Location<br>
                Content-MD5<br>
                Content-Range<br>
                Content-Type<br>
                Expires<br>
                Last-Modified<br>
                extension-header<br>
            </text>
       </td>
   </tr>
</table>

<h3>Message Body</h3>

<h3>Message Length</h3>

<h2>MIME类型</h2>
<h6><a href=https://tools.ietf.org/html/rfc822>RFC-822 Standard for ARPA Internet text messages</a></h6>
<h6><a href=https://tools.ietf.org/html/rfc2045>RFC-2045 MIME Part 1: Format of Internet Message Bodies</a></h6>
<h6><a href=https://tools.ietf.org/html/rfc2046>RFC-2046 MIME Part 2: Media Types<br></a></h6>
<h6><a href=https://tools.ietf.org/html/rfc2047>RFC-2047 MIME Part 3: Header Extensions for Non-ASCII Text<br></a></h6>
<h6><a href=https://tools.ietf.org/html/rfc2048>RFC-2048 MIME Part 4: Registration Procedures<br></a></h6>
<h6><a href=https://tools.ietf.org/html/rfc2049>RFC-2049 MIME Part 5: Conformance Criteria and Examples<br></a></h6>

<h2> Status-Code</h2>
<h3>1xx:Informational</h3>
<p>
100 Continue<br>
101 Switching Protocols<br>
</p>
<h3>2xx:</h3>
<p>
200 OK<br>
201 Created<br>
202 Accepted<br>
203 Non-Authoritative Information<br>
204 No Content<br>
205 Reset Content<br>
206 Partial Content<br>
</p>
<h3>3xx:</h3>
<p>
300 Multiple Choices<br>
301 Moved Permanently<br>
302 Found<br>
303 See Other<br>
304 Not Modified<br>
305 Use Proxy<br>
306 (Unused)<br>
307 Temporary Redirect<br>
</p>
<h3>4xx:</h3>
<p>
400 Bad Request<br>
401 Unauthorized<br>
402 Payment Required<br>
403 Forbidden<br>
404 Not Found<br>
405 Method Not Allowed<br>
406 Not Acceptable<br>
407 Proxy Authentication Required<br>
408 Request Timeout<br>
409 Conflict<br>
410 Gone<br>
411 Length Required<br>
412 Precondition Failed<br>
413 Request Entity Too Large<br>
414 Request-URI Too Long<br>
415 Unsupported Media Type<br>
416 Requested Range Not Satisfiable<br>
417 Expectation Failed<br>
</p>
<h3>5xx:</h3>
<p>
500 Internal Server Error<br>
501 Not Implemented<br>
502 Bad Gateway<br>
503 Service Unavailable<br>
504 Gateway Timeout<br>
505 HTTP Version Not Supported<br>
</p>










