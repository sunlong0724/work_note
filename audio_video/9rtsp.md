<style>
strong {
    color:#00F9A5;
    size: 100px;
    margin: 0em;
    font-size: xx-large;
    font-style: italic;
}
</style>

# RTSP

RTSP（Real Time Streaming Protocol，实时流协议），是由Real Network和Netscape共同提出的如何有效地在IP网络上传输流媒体数据的应用层协议。RTSP提供一种可扩展的框架，能够提供可控制的，按需 传输的实时数据，比如音频和视频文件。源数据可以包括现场数据的反馈和存储的文件。RTSP对流媒体提供了诸如暂停，快进等控制，而它本身并不传输数 据，RTSP的作用相当于流媒体服务器的远程控制。传输数据可以通过传输层的TCP/UDP协议，RTSP也提供了基于RTP传输机制的一些有效的方法。

RTSP消息格式：

RTSP的消息有两大类，***一是请求消息(request)，一是回应消息(response)***，两种消息的格式不同。

## 一、 请求消息：

方法 URI RTSP版本 CR LF

消息头 CR LF CR LF

消息体 CR LF

其中方法包括OPTIONS回应中所有的命令，URI是接收方（服务端）的地址，例如：rtsp://192.168.22.136:5000/v0

RTSP版本一般都是RTSP/1.0。每行后面的CR LF表示回车换行，需要接收端有相应的解析，最后一个消息头需要有两个CR LF

## 二、 回应消息：

RTSP版本 状态码 解释 CR LF

消息头 CR LF CR LF

消息体 CR LF

其中RTSP版本一般都是RTSP/1.0，状态码是一个数值，200表示成功，解释是与状态码对应的文本解释。


## 三、简单的RTSP交互过程：

C表示RTSP客户端，S表示RTSP服务端

1.C->S：**OPTIONS** request //询问S有哪些方法可用

1.S->C：OPTIONS response //S回应信息中包括提供的所有可用方法

2.C->S：**DESCRIBE** request //要求得到S提供的媒体初始化描述信息

2.S->C：DESCRIBE response //**S回应媒体初始化描述信息，主要是sdp**

3.C->S：**SETUP** request //设置会话的属性，以及传输模式，提醒S建立会话

3.S->C：SETUP response //S建立会话，返回会话标识符，以及会话相关信息

4.C->S：**PLAY** request //C请求播放

4.S->C：PLAY response //S回应该请求的信息

S->C：发送流媒体数据

5.C->S：**TEARDOWN** request //C请求关闭会话

5.S->C：TEARDOWN response //S回应该请求

上述的过程是标准的、友好的rtsp流程，但实际的需求中并不一定按部就班来。其中第3和4步是必需的！第一步，只要服务器客户端约定好，有哪些方法可 用，则OPTIONS请求可以不要。第二步，如果我们有其他途径得到媒体初始化描述信息（比如http请求等等），则我们也不需要通过RTSP中的 DESCRIBE请求来完成。第五步，可以根据系统需求的设计来决定是否需要。

## 四、rtsp中常用方法：

1. OPTIONS

    目的是得到服务器提供的可用方法：

    OPTIONS rtsp://192.168.22.136:5000/v0 RTSP/1.0

    CSeq: 1 //每个消息都有序号来标记，第一个包通常是OPTIONS请求消息

    User-Agent: bestilyq //自定义的字符串

    服务器的回应信息包括提供的一些方法。例如：

    RTSP/1.0 200 OK

    Cseq: 1 //每个回应消息的cseq数值和请求消息的cseq相对应

    Public: OPTIONS, DESCRIBE, SETUP, TEARDOWN, PLAY //服务器提供的可用的方法

 

2. DESCRIBE

    C向S发起DESCRIBE请求，为了得到会话描述信息(SDP)：

    DESCRIBE rtsp://192.168.20.136:5000/v0 RTSP/1.0

    CSeq: 2

    Accept: application/sdp

    Authorization: Basic YWRtaW46YWRtaW4= //有认证，不需要认证时不需要该字段

    User-Agent: bestilyq

    服务器回应一些对此会话的描述信息(sdp)：

    RTSP/1.0 200 OK

    Cseq: 2

    Date: Sat Feb 5 22:49:39 2009 GMT

    Content-Type: application/sdp

    Content-Length: 182

    v=0 //以下都是sdp信息

    o=- 0 0 IN IPV4 127.0.0.1

    t=0 0

    s=No Name

    a=tool:libavformat

    m=video 0 RTP/AVP 96 //m表示媒体描述，下面是对会话中视频通道的媒体描述

    b=AS:2000

    a=rtpmap:96 MP4V-ES/90000

    a=fmtp:96 profile-level-id=1

    a=control:streamid=0 //streamid＝0表示视频流用的是通道0

 

3. SETUP

    1. 客户端提醒服务器建立会话，并确定传输模式：

        1. TCP模式

            SETUP rtsp://192.168.20.136:5000/v0/streamid=0 RTSP/1.0

            CSeq: 3

            Authorization: Basic YWRtaW46YWRtaW4=

            Transport: RTP/AVP/TCP;unicast;interleaved=0-1

            User-Agent: bestilyq

        2. UDP模式

            SETUP rtsp://192.168.20.136:5000/v0/streamid=0 RTSP/1.0

            CSeq: 3

            Transport: RTP/AVP;unicast;client_port=3008-3009

            Authorization: Basic YWRtaW46YWRtaW4=

            User-Agent: bestilyq

        URI中带有streamid＝0，表示对该通道进行设置。

        Transport参数设置了传输模式。RTP/AVP/TCP表示通过TCP传输RTP包，RTP/AVP表示使用UDP传输RTP包。unicast表示单播。interleaved 值有两个：0和1，0表示RTP包，1表示RTCP包，接收端根据interleaved的值来区别是哪种数据包。client_port值有3008和 3009，3008表示客户端接收RTP包的端口，3009表示客户端接收RTCP包的端口，服务端要分别将RTP包和RTCP包发送到这两个端口。

    2. 服务器回应信息：

        1. TCP模式

            RTSP/1.0 200 OK

            CSeq: 3

            Date: Sat Feb 5 22:35:27 2009 GMT

            Session: a522bbb4335617db

            Transport: RTP/AVP/TCP;interleaved=0-1

        2. UDP模式

            RTSP/1.0 200 OK

            CSeq: 3

            Date: Sat Feb 5 22:49:39 2009 GMT

            Session: 01fa4ca2566a6301 //服务器回应的会话标识符

            Transport: RTP/AVP/UDP;unicast;client_port=3008-3009;server_port=1024-1025

 

4. PLAY

    1. 客户端发送播放请求：

        PLAY rtsp://192.168.20.136:5000/v0 RTSP/1.0

        CSeq: 4

        Session: a522bbb4335617db //SETUP返回的会话标识符

        Range: npt=0.000- //设置播放时间的范围

        User-Agent: bestilyq

 

    2. 服务器回应信息：

        RTSP/1.0 200 OK

        CSeq: 4

        Date: Sat Feb 5 22:49:39 2009 GMT

        Session: a522bbb4335617db

 

5. TEARDOWN

    1. 客户端发起关闭请求:

        TEARDOWN rtsp://192.168.20.136:5000/v0 RTSP/1.0

        CSeq: 5

        Session: a522bbb4335617db

        User-Agent: bestilyq

 

    2. 服务器回应:

        RTSP/1.0 200 OK

        Cseq: 5

        Date: Sat Feb 5 22:49:47 2009 GMT

        Session: a522bbb4335617db


以上方法都是交互过程中最为常用的,其它还有一些重要的方法如GET_PARAMETER,SET_PARAMETER,PAUSE,REDIRECT等等。

 

ps：

sdp的格式

v=<version>

o=<username> <session id> <version> <network type> <address type> <address>

s=<session name>

i=<session description>

u=<URI>

e=<email address>

p=<phone number>

c=<network type> <address type> <connection address>

b=<modifier>:<bandwidth-value>

t=<start time> <stop time>

r=<repeat interval> <active duration> <list of offsets from start-time>

z=<adjustment time> <offset> <adjustment time> <offset> ....

k=<method>

k=<method>:<encryption key>

a=<attribute>

a=<attribute>:<value>

m=<media> <port> <transport> <fmt list>

v = （协议版本）

o = （所有者/创建者和会话标识符）

s = （会话名称）

i = * （会话信息）

u = * （URI 描述）

e = * （Email 地址）

p = * （电话号码）

c = * （连接信息）

b = * （带宽信息）

z = * （时间区域调整）

k = * （加密密钥）

a = * （0 个或多个会话属性行）

时间描述：

t = （会话活动时间）

r = * （0或多次重复次数）

媒体描述：

m = （媒体名称和传输地址）

i = * （媒体标题）

c = * （连接信息 — 如果包含在会话层则该字段可选）

b = * （带宽信息）

k = * （加密密钥）

a = * （0 个或多个媒体属性行）

带*为可可选信息
————————————————
原文链接：https://blog.csdn.net/fanyun_01/article/details/105802623