#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <chrono>



//Set up simulator for variables
bool kCriticalFailure = true;
bool comms_data_ = false;
bool nav_data_ = false;
bool motor_data_ = true;
bool batteries_data_ = true;
//Continue with program


bool checkCriticalFailure() {
    bool criticalFailureFound = false;
    // check if any of the module has failed (except sensors)
    if (comms_data_/*.module_status*/ == /*data::ModuleStatus::*/kCriticalFailure) {
        std::cout << /*log_.ERR("STATE"*/ "Critical failure caused by communications " << std::endl;
        criticalFailureFound = true;
        //return true
    }
    if (nav_data_/*.module_status*/ == /*data::ModuleStatus::*/kCriticalFailure) {
        std::cout << /*log_.ERR("STATE",*/ "Critical failure caused by navigation " << std::endl;
        criticalFailureFound = true;
        //return true;
    }
    if (motor_data_/*.module_status*/ == /*data::ModuleStatus::*/kCriticalFailure) {
        std::cout << /*log_.ERR("STATE",*/ "Critical failure caused by motors " << std::endl;
        criticalFailureFound = true;
        //return true;
    }
    if (batteries_data_/*.module_status*/ == /*data::ModuleStatus::*/kCriticalFailure) {
        std::cout << /*log_.ERR("STATE", */"Critical failure caused by batteries " << std::endl;
        criticalFailureFound = true;
        //return true;
    }
    if (criticalFailureFound) {
        /*hypedMachine.handleEvent(kCriticalFailure);*/
        return true;
    } else {
        return false;
    }
}

int main(){

    if(checkCriticalFailure()){
        std::cout << "\033[1;32m    TEST PASSED\033[0m " << std::endl;
    }


    return 0;
}
