#include "mageAPI.h"

mageResult mageEngineInitialise()
{
    uint32_t result = glfwInit();
    if (result != GLFW_TRUE)
    {
        MAGE_LOG_CORE_INFORM("GLFW has failed to be created\n", NULL);
    }
    assert(result == GLFW_TRUE);
    
    return MAGE_RESULT_SUCCESS;
}
mageResult mageApplicationCreate(struct mageApplication *application, struct mageApplicationCreateInfo *info)
{
    application->Window             = MAGE_MEMORY_ALLOCATE(sizeof(struct mageWindow));
    application->Renderer           = MAGE_MEMORY_ALLOCATE(sizeof(struct mageRenderer));
    
    application->Running = 1;
    mageResult returnCode = mageEngineInitialise();
    MAGE_ASSERT(returnCode == MAGE_RESULT_SUCCESS);
    mageWindowCreate(application->Window, info->WindowSetup);
    mageRendererCreate(application->Renderer, application->Window, info);
    struct mageUserInputInquirerSetupInfo inputSetup;
    memset(&inputSetup, 0, sizeof(struct mageUserInputInquirerSetupInfo));

    if (info->InputSetup != NULL)
        inputSetup = *info->InputSetup;
    mageUserInputInquirerSetup(application->Window, &inputSetup);

    return MAGE_RESULT_SUCCESS;
}
void mageApplicationDestroy(struct mageApplication *application)
{
    mageWindowDestroy(application->Window);
    mageRendererDestroy(application->Renderer);
    MAGE_MEMORY_FREE(application->Window);
    MAGE_MEMORY_FREE(application->Renderer);
    
    MAGE_LOG_CORE_INFORM("Application has been cleaned up\n", NULL);
}
