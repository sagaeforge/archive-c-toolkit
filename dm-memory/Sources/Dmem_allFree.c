
#include "DMem.h"
#include "__DMem.h"

void DynamicMemory_AllFrees()
{
    if(DM_Mgr == NULL)
        return;

#ifdef DEBUG
    SaveLogs(FLAG_Free, DM_Mgr, "Manager");
#endif // DEBUG

    // 모든 원소 삭제
    struct DMemPageNode* thisNode = DM_Mgr->start, *back = NULL;
    int i;
    for (i = 0; i < DM_Mgr->memoryPageCount; i++)
    {
        DMemPage_AllElementsFree(thisNode);
        thisNode = thisNode->next;
    }

    // 페이지 삭제
    for (i = 0; i < DM_Mgr->memoryPageCount; i++)
    {
        thisNode = DM_Mgr->start;
        back = thisNode;
        while (thisNode->next != NULL)
        {
            back = thisNode;
            thisNode = thisNode->next;
        }
#ifdef DEBUG
    SaveLogs(FLAG_Free, thisNode, "Page");
#endif // DEBUG
        free(thisNode);
        if(thisNode != back)
            back->next = NULL;
    }
#ifdef DEBUG
    struct LogsNode *lognode = DM_Mgr->logs;
    struct LogsNode *backlognode = DM_Mgr->logs;

    while (lognode != NULL)
    {
        SaveLogs(FLAG_Free, lognode, "LogNode");
        lognode = lognode->next;
    }
    FileWriteDebugLog();

    // 로그 삭제
    while (DM_Mgr->logs != NULL)
    {
        lognode = DM_Mgr->logs;
        while (lognode->next != NULL)
        {
            backlognode = lognode;
            lognode = lognode->next;
        }
        if(lognode != DM_Mgr->logs)
        {
            backlognode->next = NULL;
            free(lognode);
        }
        else
        {
            free(lognode);
            DM_Mgr->logs = NULL;
        }
    }
#endif // DEBUG

    DM_Mgr->start = DM_Mgr->last = NULL;
    DM_Mgr->memoryPageCount = DM_Mgr->totalMemoryCount = 0;
    free(DM_Mgr);
}
