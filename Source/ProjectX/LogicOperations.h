// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 *
 */
class LogicOperations
{
    
private:
    static LogicOperations *m_singleton;
    
public:
    LogicOperations();
    
    //Instance of this class
    static LogicOperations *Instance();
    float Normalize(float unit, float normalStart, float normalEnd);
    
    ~LogicOperations();
};
