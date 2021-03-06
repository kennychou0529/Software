
// 1: Includes
// ----------------------------------------------------------------------------
#include <registersMyriad.h>
#include <OsDrvCpr.h>
#include "OsDrvTimer.h"
#include <DrvRegUtils.h>
#include "DrvDdr.h"
#include "app_config.h"

// 2:  Source Specific #defines and types  (typedef,enum,struct)
// ----------------------------------------------------------------------------


// 3: Global Data (Only if absolutely necessary)
// ----------------------------------------------------------------------------


// 4: Static Local Data
// ----------------------------------------------------------------------------

// 5: Static Function Prototypes
// ----------------------------------------------------------------------------


// 6: Functions Implementation
// ----------------------------------------------------------------------------
int initClocksAndMemory(void)
{
    int retVal;

    tyAuxClkDividerCfg auxClkAllOn[] =
    {
        {AUX_CLK_MASK_UART, CLK_SRC_REFCLK0, 96, 625},   // Give the UART an SCLK that allows it to generate an output baud rate of of 115200 Hz (the uart divides by 16)
        {0,0,0,0}, // Null Terminated List
    };

    // Configure the system
    OsDrvCprInit();
    OsDrvCprOpen();
    OsDrvCprAuxClockArrayConfig(auxClkAllOn);

    return 0;
}
