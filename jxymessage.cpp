#include "jxymessage.h"
#include <stdarg.h>

#define MESSGAGE_MAX_LENGTH             256

JxyMessage::JxyMessage()
{

}

/*
 * 打开系统日志记录程序的连接
 */
void JxyMessage::OpenSystemLog()
{
    openlog("JXY", LOG_PID, 0);
}

void JxyMessage::CreateMessageFile(char *filename)
{
    m_MessagePtr = fopen(filename,"a");
}

void JxyMessage::MessageInfo(const int category, const int level, const char *fmt, ...)
{
    char    messageBuffer[MESSGAGE_MAX_LENGTH];
    int     messageLength;

    va_list args;
    va_start(args, fmt);
    messageLength = vsnprintf(messageBuffer, MESSGAGE_MAX_LENGTH, fmt, args);
    va_end(args);

    if(category == JxyMessageCategorySystem)
    {
        syslog(level, "%s", messageBuffer);
    }
    else
    {

    }
}


