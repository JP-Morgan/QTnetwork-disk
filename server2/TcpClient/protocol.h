#ifndef PROTOCOL_H
#define PROTOCOL_H
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <cassert>
typedef unsigned int uint;
struct PDU
{
    uint uiPDULen;//总的协议数据单位大小
    uint uiMsgType;//消息类型
    char caData[64];//文件长度
    uint uiMsgLen;//实际消息数据大小
    int caMsg[];//实现消息
};

PDU *mkPDU(uint uiMsgLen);

#endif // PROTOCOL_H
