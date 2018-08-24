// Fill out your copyright notice in the Description page of Project Settings.

#include "LogicOperations.h"

LogicOperations *LogicOperations::m_singleton;
LogicOperations::LogicOperations()
{}

LogicOperations *LogicOperations::Instance(){
    
    if(m_singleton == nullptr)m_singleton = new LogicOperations();
    return m_singleton;
    
}


float LogicOperations::Normalize(float unit, float normalStart, float normalEnd){
    
    float delta = fabs(normalEnd - normalStart);
    unit += -normalStart;
    
    unit = (delta * ((unit / delta) - floor(unit / delta))) + normalStart; 
    
    return unit;
    
}

LogicOperations::~LogicOperations()
{}
