
typedef enum
{
   behaviourStateShutdown,
   behaviourStatePoweringUp,
   behaviourStatePoweringDn,
   behaviourStatePoweringUpLowBattery,
   behaviourStateConnectedAuthApp,
   behaviourStateAdvertising,
   behaviourStateConnectedUnAuthApp,
   behaviourStateLowBattShutdown
}behaviouralStates_t;

typedef enum
{
   behaviourEventButtonDown,
   behaviourEventButtonDownLowBattery,
   behaviourEventButtonDownGT5000,
   behaviourEventButtonDownGT50,
   behaviourEventButtonDownLT1000,
   behaviourEventButtonDownGT1000LT5000,
   behaviourEventButtonDownGT2000Rleased,
   behaviourEventRemoteShutdown,
   behaviourEventConnectedAuth,
   behaviourEventDroppedConnection,
   behaviourEventLowBattery,
   behaviourEventStayAwakeTimeout
}behaviouralEvents_t;



int handleEdmundBehaviour(behaviouralEvents_t behaviouralEvent);
