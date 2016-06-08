//==================================================================================
// Copyright (c) 2016 , Advanced Micro Devices, Inc.  All rights reserved.
//
/// \author AMD Developer Tools Team
/// \file apOpenCLErrorEvent.cpp
///
//==================================================================================

//------------------------------ apOpenCLErrorEvent.cpp ------------------------------

// Infra:
#include <AMDTBaseTools/Include/gtAssert.h>

// Local:
#include <AMDTAPIClasses/Include/Events/apOpenCLErrorEvent.h>
#include <AMDTAPIClasses/Include/apFunctionCall.h>
#include <AMDTOSWrappers/Include/osChannel.h>
#include <AMDTOSWrappers/Include/osChannelOperators.h>

// ---------------------------------------------------------------------------
// Name:        apOpenCLErrorEvent::apOpenCLErrorEvent
// Description: Constructor
// Arguments:   triggeringThreadId - The id of the thread that created the compute context.
//              contextId - The OpenCL Server's compute context id.
// Author:  AMD Developer Tools Team
// Date:        21/2/2010
// ---------------------------------------------------------------------------
apOpenCLErrorEvent::apOpenCLErrorEvent(osThreadId triggeringThreadId, const apOpenCLErrorParameters& openCLErrorsParameter, bool wasGeneratedByBreak)
    : apEvent(triggeringThreadId), _openCLErrorParameters(openCLErrorsParameter), _wasGeneratedByBreak(wasGeneratedByBreak)
{
}


// ---------------------------------------------------------------------------
// Name:        apOpenCLErrorEvent::~apOpenCLErrorEvent
// Description: Destructor
// Author:  AMD Developer Tools Team
// Date:        21/2/2010
// ---------------------------------------------------------------------------
apOpenCLErrorEvent::~apOpenCLErrorEvent()
{
}


// ---------------------------------------------------------------------------
// Name:        apOpenCLErrorEvent::type
// Description: Returns my transferable object type.
// Author:  AMD Developer Tools Team
// Date:        21/2/2010
// ---------------------------------------------------------------------------
osTransferableObjectType apOpenCLErrorEvent::type() const
{
    return OS_TOBJ_ID_OPENCL_ERROR_EVENT;
}


// ---------------------------------------------------------------------------
// Name:        apOpenCLErrorEvent::writeSelfIntoChannel
// Description: Writes this class data into a communication channel
// Return Val: bool  - Success / failure.
// Author:  AMD Developer Tools Team
// Date:        21/2/2010
// ---------------------------------------------------------------------------
bool apOpenCLErrorEvent::writeSelfIntoChannel(osChannel& ipcChannel) const
{
    // Write the OpenCL error parameters:
    bool retVal = _openCLErrorParameters.writeSelfIntoChannel(ipcChannel);

    // Write the was generated by a breakpoint flag:
    ipcChannel << _wasGeneratedByBreak;

    // Call my parent class's version of this function:
    bool rcWriteEvent = apEvent::writeSelfIntoChannel(ipcChannel);

    retVal = retVal && rcWriteEvent;

    return retVal;
}


// ---------------------------------------------------------------------------
// Name:        apOpenCLErrorEvent::readSelfFromChannel
// Description: Reads this class data from a communication channel
// Return Val: bool  - Success / failure.
// Author:  AMD Developer Tools Team
// Date:        21/2/2010
// ---------------------------------------------------------------------------
bool apOpenCLErrorEvent::readSelfFromChannel(osChannel& ipcChannel)
{
    bool retVal = _openCLErrorParameters.readSelfFromChannel(ipcChannel);

    // Read the was generated by a breakpoint flag:
    ipcChannel >> _wasGeneratedByBreak;

    // Call my parent class's version of this function:
    bool rcReadEvent = apEvent::readSelfFromChannel(ipcChannel);

    retVal = retVal && rcReadEvent;

    return retVal;
}


// ---------------------------------------------------------------------------
// Name:        apOpenCLErrorEvent::type
// Description: Returns my debugged process event type.
// Author:  AMD Developer Tools Team
// Date:        21/2/2010
// ---------------------------------------------------------------------------
apEvent::EventType apOpenCLErrorEvent::eventType() const
{
    return apEvent::AP_OPENCL_ERROR;
}


// ---------------------------------------------------------------------------
// Name:        apOpenCLErrorEvent::clone
// Description: Creates a new copy of self, and returns it.
//              It is the caller responsibility to delete the created copy.
// Author:  AMD Developer Tools Team
// Date:        21/2/2010
// ---------------------------------------------------------------------------
apEvent* apOpenCLErrorEvent::clone() const
{
    osThreadId threadId = triggeringThreadId();
    apOpenCLErrorEvent* pEventCopy = new apOpenCLErrorEvent(threadId, _openCLErrorParameters, _wasGeneratedByBreak);
    return pEventCopy;
}

// ---------------------------------------------------------------------------
// Name:        apOpenCLErrorEvent::apOpenCLErrorEvent
// Description: Default constructor, only allowed for use by osTransferableObjectCreator
// Author:  AMD Developer Tools Team
// Date:        21/2/2010
// ---------------------------------------------------------------------------
apOpenCLErrorEvent::apOpenCLErrorEvent()
    : _openCLErrorParameters(), _wasGeneratedByBreak(false)
{
}

