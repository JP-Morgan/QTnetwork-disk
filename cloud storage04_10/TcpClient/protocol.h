#ifndef PROTOCOL_H
#define PROTOCOL_H
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <cassert>
typedef unsigned int uint;

enum ENUM_MSG_TYPE
{
    ENUM_MSG_TYPE_MIN=0,
    ENUM_MSG_TYPE_REGIST_REQUEST,//注册请求
    ENUM_MSG_TYPE_REGIST_RESPONDm,//注册回复
//    ENUM_MSG_TYPE_REQUEST,//请求
//    ENUM_MSG_TYPE_RESPONDm,//回复
//    ENUM_MSG_TYPE_REQUEST,//请求
//    ENUM_MSG_TYPE_RESPONDm,//回复
//    ENUM_MSG_TYPE_REQUEST,//请求
//    ENUM_MSG_TYPE_RESPONDm,//回复
//    ENUM_MSG_TYPE_REQUEST,//请求
//    ENUM_MSG_TYPE_RESPONDm,//回复
//    ENUM_MSG_TYPE_REQUEST,//请求
//    ENUM_MSG_TYPE_RESPONDm,//回复
    ENUM_MSG_TYPE_MIX=0x00ffffff,//32位
};

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
