
#include "DMem.h"
#include "__DMem.h"

#ifdef DEBUG
static struct LogsNode* LogNode()
{
    struct LogsNode *node = (struct LogsNode*)malloc(sizeof(struct LogsNode));
    if(node == NULL)
        return NULL;
    node->next = NULL;
    int i;
    for (i = 0; i < LogElementCount; i++)
    {
        node->values[i].isAlloc = true;
        node->values[i].ptr = NULL;
        node->values[i].name = NULL;
    }
    node->values[0].isAlloc = FLAG_Alloc;
    node->values[0].ptr = node;
    node->values[0].name = "LogNode";
    return node;
}

void SaveLogs(int mode, void *ptr, const char *name)
{
    if(DM_Mgr->logs == NULL)
    {
        DM_Mgr->logs = LogNode();
        DM_Mgr->logs->values[1].isAlloc = mode;
        DM_Mgr->logs->values[1].ptr = ptr;
        DM_Mgr->logs->values[1].name = (char*)name;
        return;
    }

    struct LogsNode *node = DM_Mgr->logs;
    int i;
    while (node != NULL)
    {
        for (i = 0; i < LogElementCount; i++)
            if(node->values[i].ptr == NULL)
            {
                node->values[i].isAlloc = mode;
                node->values[i].ptr = ptr;
                node->values[i].name = (char*)name;
                return;
            }
        node = node->next;
    }
    
    node = DM_Mgr->logs;
    while (node->next != NULL)
        node = node->next;
    node->next = LogNode();
    
    node->next->values[1].isAlloc = mode;
    node->next->values[1].ptr = ptr;
    node->next->values[1].name = (char*)name;
}
void FileWriteDebugLog()
{
    if(DM_Mgr->logs == NULL)
        return;

    FILE *LogFile = fopen("./LogFile.txt", "w");
    char buf[128];
    int i, count = 0;
    struct LogsNode *node = DM_Mgr->logs;
    sprintf(buf, "%2d : %p(%s), %s\n", ++count, LogFile, "Alloc", "File");
    fputs(buf, LogFile);
    while (node != NULL)
    {
        for (i = 0; i < LogElementCount; i++)
        {
            if(node->values[i].ptr != NULL)
            {
                sprintf(buf, "%2d : %p(%s), %s\n", ++count, node->values[i].ptr, node->values[i].isAlloc == FLAG_Alloc ? "Alloc" : "Free", node->values[i].name);
                fputs(buf, LogFile);
            }
            else
                break;
        }
        node = node->next;
    }
    sprintf(buf, "%2d : %p(%s), %s", ++count, LogFile, "Free", "File");
    fputs(buf, LogFile);
    fclose(LogFile);
}
#endif // DEBUG