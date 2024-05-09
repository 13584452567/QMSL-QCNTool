#ifndef QCLOADER_H
#define QCLOADER_H
#include "QMSL_inc/QLib.h"
#include "QMSL_inc/QLib_Defines.h"
#include "windows.h"

struct DiagInfo
{
    int portnum;
    HANDLE hndl;
    nvToolCB qphoneNvToolHandlerCallBack_delegate;
};

#define NV_UE_IMEI_I 550

#endif // QCLOADER_H