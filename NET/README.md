<h2>NAT</h2>
种类
<ul>
<li>
<span>Full Cone NAT</span><br>
<span>完全锥形NAT，所有从同一个内网IP和端口号发送过来的请求都会被映射成同一个外网IP和端口号，并且任何一个外网主机都可以通过这个映射的外网IP和端口号向这台内网主机发送包</span>
</li>
<li>
<span>Restricted Cone NAT</span>
<span>限制锥形NAT， 它也是所有从同一个内网IP和端口号发送过来的请求都会被映射成同一个外网IP和端口号。与完全锥形不同的是，外网主机只能够向先前已经向它发送过数据包的内网主机发送包</span>
</li>
<li>
<span>Port Restricted Cone NAT</span>
<span>端口限制锥形NAT，与限制锥形NAT很相似，只不过它不包括端口号。也就是说，一台IP地址X和端口P的外网主机想给内网主机发送包，必须是这台内网主机先前已经给这个IP地址X和端口P发送过数据包</span>
</li>
<li>
<span>Symmetric NAT</span>
<span>对称NAT，所有从同一个内网IP和端口号发送到一个特定的目的IP和端口号的请求，都会被映射到同一个IP和端口号。如果同一台主机使用相同的源地址和端口号发送包，但是发往不同的目的地，NAT将会使用不同的映射。此外，只有收到数据的外网主机才可以反过来向内网主机发送包</span>
</li>


</ul>
<h2>STUN</h2>
<h4><a href=https://tools.ietf.org/html/rfc5389>RFC5389</a><br>
默认端口号：3478<br>

<span> STUN Message Structure</span>

         0                   1                   2                   3
         0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |0 0|     STUN Message Type     |Message Length
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |                         Magic Cookie
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |
        |                     Transaction ID (96 bits)
        |
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

<span>STUN Attributes</span>

         0                   1                   2                   3
         0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |         Type                  |            Length
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        |                         Value (variable)                ....
        +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

         Comprehension-required range (0x0000-0x7FFF):
             0x0000: (Reserved)
             0x0001: MAPPED-ADDRESS
             0x0002: (Reserved; was RESPONSE-ADDRESS)
             0x0003: (Reserved; was CHANGE-ADDRESS)
             0x0004: (Reserved; was SOURCE-ADDRESS)
             0x0005: (Reserved; was CHANGED-ADDRESS)
             0x0006: USERNAME
             0x0007: (Reserved; was PASSWORD)
             0x0008: MESSAGE-INTEGRITY
             0x0009: ERROR-CODE
             0x000A: UNKNOWN-ATTRIBUTES
             0x000B: (Reserved; was REFLECTED-FROM)
             0x0014: REALM
             0x0015: NONCE
             0x0020: XOR-MAPPED-ADDRESS

           Comprehension-optional range (0x8000-0xFFFF)
             0x8022: SOFTWARE
             0x8023: ALTERNATE-SERVER
             0x8028: FINGERPRINT

<span>ERROR-CODE</span>


       0                   1                   2                   3
       0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
      +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
      |           Reserved, should be 0         |Class|     Number    |
      +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
      |      Reason Phrase (variable)                                ..
      +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+



<h2>TURN</h2>
<h4><a href=https://tools.ietf.org/html/rfc5766>RFC5766</a></h4>
<h2>ICE</h2>
<h4><a href=https://tools.ietf.org/html/rfc6544>RFC6544</a></h4>