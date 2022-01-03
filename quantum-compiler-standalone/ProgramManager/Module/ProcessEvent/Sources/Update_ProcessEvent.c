
#include "Exception.h"
#include "Private_ProcessEvent.h"
#include "ProgramManager.h"
#include <stdlib.h>

static void UpdateStart() {}
static void UpdateStop() {}
static void AddListener(FP_Func Method) {
  ProcessEvent event = Program.ProcessEvent.Events[ProcessEventCode_Update];
  UpdateStop();
  return;
}
static void RemoveListener(FP_Func Method) {
  ProcessEvent event = Program.ProcessEvent.Events[ProcessEventCode_Update];
  UpdateStop();
  return;
}
static void RemoveAllListener() {
  ProcessEvent event = Program.ProcessEvent.Events[ProcessEventCode_Update];
  UpdateStop();
  return;
}
static void Invoke() {
  ProcessEvent event = Program.ProcessEvent.Events[ProcessEventCode_Update];
}
void ProcessEventModule_Awake_Initialized() {
  ProcessEvent event = Program.ProcessEvent.Events[ProcessEventCode_Update];
  event.AddListener = AddListener;
  event.RemoveListener = RemoveListener;
  event.RemoveAllListener = RemoveAllListener;
  event.Invoke = Invoke;

  Program.Method.UpdateMethod.UpdateStart = UpdateStart;
  Program.Method.UpdateMethod.UpdateStop = UpdateStop;
}