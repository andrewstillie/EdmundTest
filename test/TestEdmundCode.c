
#include "EdmundCode.h"
#include "unity.h"


extern behaviouralStates_t behaviouralState;
void setUp(void)
{
  /* This is run before EACH TEST */
  /*behaviouralState = behaviourIdle;*/
}

void tearDown(void)
{
}
/* ********************************************* */
/* Test State behaviourStateShutdown */
/* ********************************************* */
void test_handleEdmundBehaviour_TestNoFalseExitsFromStateShutdown(void)
{
  behaviouralState = behaviourStateShutdown;
  /* All of these should pass */
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventButtonDownLowBattery));
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventButtonDownGT5000));
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventButtonDownGT50));
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventButtonDownLT1000));
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventButtonDownGT1000LT5000));
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventButtonDownGT2000Rleased));
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventRemoteShutdown));
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventConnectedAuth));
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventDroppedConnection));
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventLowBattery));
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventStayAwakeTimeout));    
}
void test_handleEdmundBehaviour_TestTrueExitsFromIdleState(void)
{
  behaviouralState = behaviourStateShutdown;
  /* All of these should pass */
  TEST_ASSERT_EQUAL(behaviourStatePoweringUp, handleEdmundBehaviour(behaviourEventButtonDown));
}


/* ********************************************* */
/* Test State behaviourStatePoweringUp*/
/* ********************************************* */
void test_handleEdmundBehaviour_TestNoFalseExitsFromStatePoweringUp(void)
{
  behaviouralState = behaviourStatePoweringUp;
  /* All of these should pass */
  TEST_ASSERT_EQUAL(behaviourStatePoweringUp, handleEdmundBehaviour(behaviourEventButtonDown));
  TEST_ASSERT_EQUAL(behaviourStatePoweringUp, handleEdmundBehaviour(behaviourEventButtonDownLowBattery));
  TEST_ASSERT_EQUAL(behaviourStatePoweringUp, handleEdmundBehaviour(behaviourEventButtonDownGT50));
  TEST_ASSERT_EQUAL(behaviourStatePoweringUp, handleEdmundBehaviour(behaviourEventButtonDownGT2000Rleased));
  TEST_ASSERT_EQUAL(behaviourStatePoweringUp, handleEdmundBehaviour(behaviourEventRemoteShutdown));
  TEST_ASSERT_EQUAL(behaviourStatePoweringUp, handleEdmundBehaviour(behaviourEventConnectedAuth));
  TEST_ASSERT_EQUAL(behaviourStatePoweringUp, handleEdmundBehaviour(behaviourEventDroppedConnection));
  TEST_ASSERT_EQUAL(behaviourStatePoweringUp, handleEdmundBehaviour(behaviourEventLowBattery));
  TEST_ASSERT_EQUAL(behaviourStatePoweringUp, handleEdmundBehaviour(behaviourEventStayAwakeTimeout));  
}
void test_handleEdmundBehaviour_TestTrueExitsFromStatePoweringUp_behaviourEventButtonDownLT1000(void)
{
  behaviouralState = behaviourStatePoweringUp;
  /* All of these should pass */
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventButtonDownLT1000));
}
void test_handleEdmundBehaviour_TestTrueExitsFromStatePoweringUp_behaviourEventButtonDownGT1000LT5000(void)
{
  behaviouralState = behaviourStatePoweringUp;
  /* All of these should pass */
  TEST_ASSERT_EQUAL(behaviourStateAdvertising, handleEdmundBehaviour(behaviourEventButtonDownGT1000LT5000));
}
void test_handleEdmundBehaviour_TestTrueExitsFromStatePoweringUp_behaviourEventButtonDownGT5000(void)
{
  behaviouralState = behaviourStatePoweringUp;
  /* All of these should pass */
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventButtonDownGT5000));
}

/* ********************************************* */
/* Test State behaviourStatePoweringDn*/
/* ********************************************* */
void test_handleEdmundBehaviour_TestNoFalseExitsFrombehaviourStatePoweringDn(void)
{
  behaviouralState = behaviourStatePoweringDn;
  /* All of these should pass */
  TEST_ASSERT_EQUAL(behaviourStatePoweringDn, handleEdmundBehaviour(behaviourEventButtonDown));
  TEST_ASSERT_EQUAL(behaviourStatePoweringDn, handleEdmundBehaviour(behaviourEventButtonDownLowBattery));
  TEST_ASSERT_EQUAL(behaviourStatePoweringDn, handleEdmundBehaviour(behaviourEventButtonDownGT5000));
  TEST_ASSERT_EQUAL(behaviourStatePoweringDn, handleEdmundBehaviour(behaviourEventButtonDownGT50));
  TEST_ASSERT_EQUAL(behaviourStatePoweringDn, handleEdmundBehaviour(behaviourEventButtonDownLT1000));
  TEST_ASSERT_EQUAL(behaviourStatePoweringDn, handleEdmundBehaviour(behaviourEventButtonDownGT1000LT5000));
  TEST_ASSERT_EQUAL(behaviourStatePoweringDn, handleEdmundBehaviour(behaviourEventRemoteShutdown));
  TEST_ASSERT_EQUAL(behaviourStatePoweringDn, handleEdmundBehaviour(behaviourEventConnectedAuth));
  TEST_ASSERT_EQUAL(behaviourStatePoweringDn, handleEdmundBehaviour(behaviourEventDroppedConnection));
  TEST_ASSERT_EQUAL(behaviourStatePoweringDn, handleEdmundBehaviour(behaviourEventStayAwakeTimeout));  
}
void test_handleEdmundBehaviour_TestTrueExitsFrombehaviourStatePoweringDn_behaviourEventLowBattery(void)
{
  behaviouralState = behaviourStatePoweringDn;  
  /* All of these should pass */
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventLowBattery));
}
void test_handleEdmundBehaviour_TestTrueExitsFrombehaviourStatePoweringDn_behaviourEventButtonDownGT2000Rleased(void)
{
  behaviouralState = behaviourStatePoweringDn;  
  /* All of these should pass */  
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventButtonDownGT2000Rleased));

}

/* ********************************************* */
/* Test State behaviourStatePoweringUpLowBattery */
/* ********************************************* */
void test_handleEdmundBehaviour_TestNoFalseExitsFrombehaviourStatePoweringUpLowBattery(void)
{
  behaviouralState = behaviourStatePoweringUpLowBattery;  
  /* All of these should pass */
  TEST_ASSERT_EQUAL(behaviourStatePoweringUpLowBattery, handleEdmundBehaviour(behaviourEventButtonDown));
  TEST_ASSERT_EQUAL(behaviourStatePoweringUpLowBattery, handleEdmundBehaviour(behaviourEventButtonDownLowBattery));
  TEST_ASSERT_EQUAL(behaviourStatePoweringUpLowBattery, handleEdmundBehaviour(behaviourEventButtonDownGT50));
  TEST_ASSERT_EQUAL(behaviourStatePoweringUpLowBattery, handleEdmundBehaviour(behaviourEventButtonDownGT2000Rleased));
  TEST_ASSERT_EQUAL(behaviourStatePoweringUpLowBattery, handleEdmundBehaviour(behaviourEventRemoteShutdown));
  TEST_ASSERT_EQUAL(behaviourStatePoweringUpLowBattery, handleEdmundBehaviour(behaviourEventConnectedAuth));
  TEST_ASSERT_EQUAL(behaviourStatePoweringUpLowBattery, handleEdmundBehaviour(behaviourEventDroppedConnection));
  TEST_ASSERT_EQUAL(behaviourStatePoweringUpLowBattery, handleEdmundBehaviour(behaviourEventLowBattery));
  TEST_ASSERT_EQUAL(behaviourStatePoweringUpLowBattery, handleEdmundBehaviour(behaviourEventStayAwakeTimeout));  
}
void test_handleEdmundBehaviour_TestTrue1ExitsFrombehaviourStatePoweringUpLowBattery_behaviourEventButtonDownLT1000(void)
{
  behaviouralState = behaviourStatePoweringUpLowBattery;  
  /* All of these should pass */
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventButtonDownLT1000));
}
  void test_handleEdmundBehaviour_TestTrue1ExitsFrombehaviourStatePoweringUpLowBattery_behaviourEventButtonDownGT1000LT5000(void)
{
  behaviouralState = behaviourStatePoweringUpLowBattery;  
  /* All of these should pass */
  TEST_ASSERT_EQUAL(behaviourStateAdvertising, handleEdmundBehaviour(behaviourEventButtonDownGT1000LT5000));
}
void test_handleEdmundBehaviour_TestTrue1ExitsFrombehaviourStatePoweringUpLowBattery_behaviourEventButtonDownGT5000(void)
{
  behaviouralState = behaviourStatePoweringUpLowBattery;  
  /* All of these should pass */
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventButtonDownGT5000));  
}

/* ********************************************* */
/* Test State behaviourStateConnectedAuthApp*/
/* ********************************************* */
void test_handleEdmundBehaviour_TestNoFalseExitsFrombehaviourStateConnectedAuthApp(void)
{
  behaviouralState = behaviourStateConnectedAuthApp;  
  /* All of these should pass */
  TEST_ASSERT_EQUAL(behaviourStateConnectedAuthApp, handleEdmundBehaviour(behaviourEventButtonDown));
  TEST_ASSERT_EQUAL(behaviourStateConnectedAuthApp, handleEdmundBehaviour(behaviourEventButtonDownLowBattery));
  TEST_ASSERT_EQUAL(behaviourStateConnectedAuthApp, handleEdmundBehaviour(behaviourEventButtonDownGT5000));
  TEST_ASSERT_EQUAL(behaviourStateConnectedAuthApp, handleEdmundBehaviour(behaviourEventButtonDownLT1000));
  TEST_ASSERT_EQUAL(behaviourStateConnectedAuthApp, handleEdmundBehaviour(behaviourEventButtonDownGT1000LT5000));
  TEST_ASSERT_EQUAL(behaviourStateConnectedAuthApp, handleEdmundBehaviour(behaviourEventButtonDownGT2000Rleased));
  TEST_ASSERT_EQUAL(behaviourStateConnectedAuthApp, handleEdmundBehaviour(behaviourEventRemoteShutdown));
  TEST_ASSERT_EQUAL(behaviourStateConnectedAuthApp, handleEdmundBehaviour(behaviourEventConnectedAuth));
  TEST_ASSERT_EQUAL(behaviourStateConnectedAuthApp, handleEdmundBehaviour(behaviourEventDroppedConnection));
  TEST_ASSERT_EQUAL(behaviourStateConnectedAuthApp, handleEdmundBehaviour(behaviourEventLowBattery));
  TEST_ASSERT_EQUAL(behaviourStateConnectedAuthApp, handleEdmundBehaviour(behaviourEventStayAwakeTimeout));  
}
void test_handleEdmundBehaviour_TestTrueExitsFrombehaviourStateConnectedAuthApp(void)
{
  behaviouralState = behaviourStateConnectedAuthApp;  
  /* All of these should pass */
  TEST_ASSERT_EQUAL(behaviourStatePoweringDn, handleEdmundBehaviour(behaviourEventButtonDownGT50));
}
/* ********************************************* */
/* Test State behaviourStateAdvertising*/
/* ********************************************* */
void test_handleEdmundBehaviour_TestNoFalseExitsFromStateAdvertising(void)
{
  behaviouralState = behaviourStateAdvertising;  
  /* All of these should pass */
  TEST_ASSERT_EQUAL(behaviourStateAdvertising, handleEdmundBehaviour(behaviourEventButtonDown));
  TEST_ASSERT_EQUAL(behaviourStateAdvertising, handleEdmundBehaviour(behaviourEventButtonDownLowBattery));
  TEST_ASSERT_EQUAL(behaviourStateAdvertising, handleEdmundBehaviour(behaviourEventButtonDownGT5000));
  TEST_ASSERT_EQUAL(behaviourStateAdvertising, handleEdmundBehaviour(behaviourEventButtonDownLT1000));
  TEST_ASSERT_EQUAL(behaviourStateAdvertising, handleEdmundBehaviour(behaviourEventButtonDownGT1000LT5000));
  TEST_ASSERT_EQUAL(behaviourStateAdvertising, handleEdmundBehaviour(behaviourEventButtonDownGT2000Rleased));
  TEST_ASSERT_EQUAL(behaviourStateAdvertising, handleEdmundBehaviour(behaviourEventRemoteShutdown));
  TEST_ASSERT_EQUAL(behaviourStateAdvertising, handleEdmundBehaviour(behaviourEventDroppedConnection));
  TEST_ASSERT_EQUAL(behaviourStateAdvertising, handleEdmundBehaviour(behaviourEventLowBattery));
  TEST_ASSERT_EQUAL(behaviourStateAdvertising, handleEdmundBehaviour(behaviourEventStayAwakeTimeout));  
}
void test_handleEdmundBehaviour_TestTrueExitsFromStateAdvertising_behaviourEventConnectedAuth(void)
{
  behaviouralState = behaviourStateAdvertising;  
  /* All of these should pass */
  TEST_ASSERT_EQUAL(behaviourStateConnectedAuthApp, handleEdmundBehaviour(behaviourEventConnectedAuth));
}
void test_handleEdmundBehaviour_TestTrueExitsFromStateAdvertising_behaviourEventButtonDownGT50(void)
{
  behaviouralState = behaviourStateAdvertising;  
  /* All of these should pass */  
  TEST_ASSERT_EQUAL(behaviourStatePoweringDn, handleEdmundBehaviour(behaviourEventButtonDownGT50));  
}

/* ********************************************* */
/* Test State behaviourStateConnectedUnAuthApp*/
/* ********************************************* */
void test_handleEdmundBehaviour_TestNoFalseExitsFromConnectedUnAuthApp(void)
{
  behaviouralState = behaviourStateConnectedUnAuthApp;  
  /* All of these should pass */
  TEST_ASSERT_EQUAL(behaviourStateConnectedUnAuthApp, handleEdmundBehaviour(behaviourEventButtonDown));
  TEST_ASSERT_EQUAL(behaviourStateConnectedUnAuthApp, handleEdmundBehaviour(behaviourEventButtonDownLowBattery));
  TEST_ASSERT_EQUAL(behaviourStateConnectedUnAuthApp, handleEdmundBehaviour(behaviourEventButtonDownGT5000));
  TEST_ASSERT_EQUAL(behaviourStateConnectedUnAuthApp, handleEdmundBehaviour(behaviourEventButtonDownGT50));  
  TEST_ASSERT_EQUAL(behaviourStateConnectedUnAuthApp, handleEdmundBehaviour(behaviourEventButtonDownLT1000));
  TEST_ASSERT_EQUAL(behaviourStateConnectedUnAuthApp, handleEdmundBehaviour(behaviourEventButtonDownGT1000LT5000));
  TEST_ASSERT_EQUAL(behaviourStateConnectedUnAuthApp, handleEdmundBehaviour(behaviourEventButtonDownGT2000Rleased));
  TEST_ASSERT_EQUAL(behaviourStateConnectedUnAuthApp, handleEdmundBehaviour(behaviourEventRemoteShutdown));
  TEST_ASSERT_EQUAL(behaviourStateConnectedUnAuthApp, handleEdmundBehaviour(behaviourEventConnectedAuth));
  TEST_ASSERT_EQUAL(behaviourStateConnectedUnAuthApp, handleEdmundBehaviour(behaviourEventLowBattery));
  TEST_ASSERT_EQUAL(behaviourStateConnectedUnAuthApp, handleEdmundBehaviour(behaviourEventStayAwakeTimeout));  
}
void test_handleEdmundBehaviour_TestTrueExitsFromConnectedUnAuthApp(void)
{
  behaviouralState = behaviourStateConnectedUnAuthApp;  
  /* All of these should pass */
  TEST_ASSERT_EQUAL(behaviourStateAdvertising, handleEdmundBehaviour(behaviourEventDroppedConnection));
}

/* ********************************************* */
/* Test State behaviourStateLowBattShutdown*/
/* ********************************************* */
void test_handleEdmundBehaviour_TestNoFalseExitsFrombehaviourStateLowBattShutdown(void)
{
  behaviouralState = behaviourStateLowBattShutdown;  
  /* All of these should pass */
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventButtonDown));
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventButtonDownLowBattery));
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventButtonDownGT5000));
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventButtonDownGT50));
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventButtonDownLT1000));
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventButtonDownGT1000LT5000));
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventButtonDownGT2000Rleased));
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventRemoteShutdown));
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventConnectedAuth));
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventDroppedConnection));
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventLowBattery));
  TEST_ASSERT_EQUAL(behaviourStateShutdown, handleEdmundBehaviour(behaviourEventStayAwakeTimeout));  
}
