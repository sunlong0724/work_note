# ffmpeg 框架
https://blog.csdn.net/fanyun_01/category_9944897_2.html

# yuv rgb格式
yuv420p    yv12  yu12
yuv420sp   nv12  nv21


# ffmpeg

AVFormatContext ----------------->是对容器、文件或协议层的抽象封装。
       
多个 AVStream     ----------------->是对流的抽象封装    

AVCodecContext ------------------>对编码格式及编解码器的抽象

AVPacket/AVFrame ---------------->对编码数据和原始数据的封装

avformat_open_input  
avformat_find_stream_info  
avcodec_find_decoder  
avcodec_alloc_context3  
avcodec_open2  
av_read_frame  
av_send_packet
av_receive_frame




AVFormat(可以包含多个AVStream)  实现了大多数媒体的封装格式，封装和解封装。  
AVCodec   实现了常用的编解码格式  
AVFilter 提供了一个通用的音频、视频、字幕的滤镜处理框架。  
swscale  视频图像转换模块  
swresample 提供了高级别的音频重采样api。