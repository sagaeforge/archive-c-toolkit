
#include "ProcessEvent.h"
#include "Private_ProcessEvent.h"
#include "ProgramManager.h"

void ProcessEventModule_Initialized() {
  ProcessEventModule_Awake_Initialized();
  ProcessEventModule_Init_Initialized();
  ProcessEventModule_Start_Initialized();
  ProcessEventModule_Main_Initialized();
  ProcessEventModule_Update_Initialized();
  ProcessEventModule_FixedUpdate_Initialized();
  ProcessEventModule_Quit_Initialized();

  Program.ProcessEvent.Status.IsInitialized = false;
  Program.ProcessEvent.Status.IsStarted = false;
  Program.ProcessEvent.Status.IsUpdated = false;
  Program.ProcessEvent.Status.IsFixedUpdated = false;
  Program.ProcessEvent.FixedUpdateTime = 60;
}

void Update_Wait(pthread_t Thread) {
  int status;
  pthread_join(Thread, (void **)&status);
}
void Update_AllStop() {
  if (Program.ProcessEvent.Status.IsUpdated) {
    Update_Wait(Program.ProcessEvent.UpdateThread);
    Program.ProcessEvent.Status.IsUpdated = false;
  }
  if (Program.ProcessEvent.Status.IsFixedUpdated) {
    Update_Wait(Program.ProcessEvent.FixedUpdateThread);
    Program.ProcessEvent.Status.IsFixedUpdated = false;
  }
}