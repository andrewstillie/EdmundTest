
#include "EdmundCode.h"



behaviouralStates_t behaviouralState = behaviourStateShutdown;


   

int handleEdmundBehaviour(behaviouralEvents_t behaviouralEvent)
{
    /* **************************************** */
    /*                                          */
    /* Handle Behavioural State Machine         */
    /*                                          */        
    /* **************************************** */            
    switch(behaviouralState)
    {
        /* **************************************** */
        /*                                          */
        /* Handle behaviourStateShutdown                 */
        /*                                          */        
        /* **************************************** */        
        case    behaviourStateShutdown:
            /* **************************************** */
            /* State Transition:                        */
            /* **************************************** */
            if( behaviouralEvent == behaviourEventButtonDown)
            {
                behaviouralState = behaviourStatePoweringUp;
            }
            break;
        /* **************************************** */
        /*                                          */            
        /* Handle behaviourStatePoweringUp               */
        /*                                          */            
        /* **************************************** */              
        case    behaviourStatePoweringUp:
            /* **************************************** */
            /* State Transition:  Short Press           */
            /* **************************************** */
            if( behaviouralEvent == behaviourEventButtonDownLT1000)
            {
                behaviouralState = behaviourStateShutdown;
            }
            /* **************************************** */
            /* State Transition: Correct Press          */
            /* **************************************** */
            if( behaviouralEvent == behaviourEventButtonDownGT1000LT5000)
            {
                behaviouralState = behaviourStateAdvertising;
            }
            /* **************************************** */
            /* State Transition: LongPress              */
            /* **************************************** */
            if( behaviouralEvent == behaviourEventButtonDownGT5000)
            {
                behaviouralState = behaviourStateShutdown;
            }            
            break;
        /* **************************************** */
        /*                                          */            
        /* Handle behaviourStatePoweringDn               */
        /*                                          */            
        /* **************************************** */              
        case    behaviourStatePoweringDn:
            /* **************************************** */
            /* State Transition: Correct Press          */
            /* **************************************** */
            if( behaviouralEvent == behaviourEventButtonDownGT2000Rleased)
            {
                behaviouralState = behaviourStateShutdown;
            }
            /* **************************************** */
            /* State Transition: LongPress              */
            /* **************************************** */
            if( behaviouralEvent == behaviourEventLowBattery)
            {
                behaviouralState = behaviourStateShutdown;
            }            
            break;            
        /* ***************************************** */
        /*                                           */            
        /* Handle behaviourStatePoweringUpLowBattery      */
        /*                                           */            
        /* ***************************************** */              
        case    behaviourStatePoweringUpLowBattery:
            /* **************************************** */
            /* State Transition:  Short Press           */
            /* **************************************** */
            if( behaviouralEvent == behaviourEventButtonDownLT1000)
            {
                behaviouralState = behaviourStateShutdown;
            }
            /* **************************************** */
            /* State Transition: Correct Press          */
            /* **************************************** */
            if( behaviouralEvent == behaviourEventButtonDownGT1000LT5000)
            {
                behaviouralState = behaviourStateAdvertising;
            }
            /* **************************************** */
            /* State Transition: LongPress              */
            /* **************************************** */
            if( behaviouralEvent == behaviourEventButtonDownGT5000)
            {
                behaviouralState = behaviourStateShutdown;
            }            
            break;
        /* **************************************** */
        /*                                          */            
        /* Handle behaviourStateConnectedAuthApp    */
        /*                                          */            
        /* **************************************** */              
        case    behaviourStateConnectedAuthApp:
            /* **************************************** */
            /* State Transition:                        */
            /* **************************************** */
            if( behaviouralEvent == behaviourEventButtonDownGT50)
            {
                behaviouralState = behaviourStatePoweringDn;
            }   
            break;
        /* **************************************** */
        /*                                          */            
        /* Handle behaviourStateAdvertising         */
        /*                                          */            
        /* **************************************** */              
        case    behaviourStateAdvertising:
            /* **************************************** */
            /* State Transition:                        */
            /* **************************************** */
            if( behaviouralEvent == behaviourEventConnectedAuth)
            {
                behaviouralState = behaviourStateConnectedAuthApp;
            }
            /* **************************************** */
            /* State Transition:                        */
            /* **************************************** */
            if( behaviouralEvent == behaviourEventButtonDownGT50)
            {
                behaviouralState = behaviourStatePoweringDn;
            }                         
            break;
        /* **************************************** */
        /*                                          */            
        /* Handle behaviourStateConnectedUnAuthApp  */
        /*                                          */            
        /* **************************************** */              
        case    behaviourStateConnectedUnAuthApp:
            /* **************************************** */
            /* State Transition:                        */
            /* **************************************** */
            if( behaviouralEvent == behaviourEventDroppedConnection)
            {
                behaviouralState = behaviourStateAdvertising;
            }           
            break;
        /* **************************************** */
        /*                                          */            
        /* Handle behaviourStateLowBattShutdown     */
        /*                                          */            
        /* **************************************** */              
        case    behaviourStateLowBattShutdown:
            /* **************************************** */
            /* State Transition:                        */
            /* **************************************** */
            if(  1 )
            {
                behaviouralState = behaviourStateShutdown;
            }           
            break;
        /* **************************************** */
        /*                                          */            
        /* Handle default                           */
        /*                                          */            
        /* **************************************** */              
        default:
            behaviouralState = behaviourStateShutdown;
    }
    return behaviouralState;
}

