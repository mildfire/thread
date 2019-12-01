#ifndef JXYMESSAGE_H
#define JXYMESSAGE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <syslog.h>
#include <stdarg.h>

#ifdef __cplusplus
};
#endif

enum JxyMessageCategory
{
    JxyMessageCategoryUser,
    JxyMessageCategorySystem,
    JxyMessageCategoryCount
};

enum JxyMessageLevel
{
    JxyMessageLevelDebug,
    JxyMessageLevelInfo,
    JxyMessageLevelWarn,
    JxyMessageLevelError,
    JxyMessageLevelFatal,
    JxyMessageLevelCount
};

class JxyMessage
{
public:
    JxyMessage();

    void OpenSystemLog();
    void CreateMessageFile(char *filename);
    void MessageInfo(const int category, const int level, const char *fmt, ...);

    //Member
    FILE *m_MessagePtr;

};

#endif // JXYMESSAGE_H
