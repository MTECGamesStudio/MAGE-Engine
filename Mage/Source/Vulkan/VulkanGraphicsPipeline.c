#include "VulkanRenderer.h"

U8 MageVulkanRendererCreateGraphicsPipeline(MageRendererCreateInfo *info, MageRenderer *renderer)
{
    /* TODO Allow for full user customisation of the renderer's internal configuration */

    VkPipelineVertexInputStateCreateInfo vertexInputInfo;
    memset(&vertexInputInfo, 0, sizeof(VkPipelineVertexInputStateCreateInfo));
    vertexInputInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
    vertexInputInfo.vertexBindingDescriptionCount = 0;
    vertexInputInfo.vertexAttributeDescriptionCount = 0;

    VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
    memset(&inputAssemblyInfo, 0, sizeof(VkPipelineInputAssemblyStateCreateInfo));
    inputAssemblyInfo.sType                  = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
    inputAssemblyInfo.topology               = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
    inputAssemblyInfo.primitiveRestartEnable = MageFalse;

    VkViewport viewport;
    memset(&viewport, 0, sizeof(VkViewport));
    viewport.x        = 0.0f;
    viewport.y        = 0.0f;
    viewport.width    = renderer->SwapChain.CurrentExtent.width;
    viewport.height   = renderer->SwapChain.CurrentExtent.height;
    viewport.minDepth = 0.0f;
    viewport.maxDepth = 1.0f;

    VkRect2D scissor; /* scissor has no z, weird world we inhabit */
    memset(&scissor, 0, sizeof(VkRect2D));
    scissor.extent    = renderer->SwapChain.CurrentExtent;
    scissor.offset    = (VkOffset2D) { .x = 0.0f, .y = 0.0f };
    
    VkPipelineViewportStateCreateInfo viewportStateInfo;
    memset(&viewportStateInfo, 0, sizeof(VkPipelineViewportStateCreateInfo));
    viewportStateInfo.sType              = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
    viewportStateInfo.pViewports         = &viewport;
    viewportStateInfo.viewportCount      = 1;
    viewportStateInfo.pScissors          = &scissor;
    viewportStateInfo.viewportCount      = 1;

    VkPipelineRasterizationStateCreateInfo rasterizationInfo;
    memset(&rasterizationInfo, 0, sizeof(VkPipelineRasterizationStateCreateInfo));
    rasterizationInfo.sType                         = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
    rasterizationInfo.depthClampEnable              = MageFalse;
    rasterizationInfo.rasterizerDiscardEnable       = MageFalse;
    rasterizationInfo.polygonMode                   = VK_POLYGON_MODE_FILL;
    rasterizationInfo.lineWidth                     = 1.0f;
    rasterizationInfo.cullMode                      = VK_CULL_MODE_BACK_BIT;
    rasterizationInfo.frontFace                     = VK_FRONT_FACE_CLOCKWISE;
    rasterizationInfo.depthBiasEnable               = MageFalse;

    VkPipelineMultisampleStateCreateInfo multisamplingInfo;
    memset(&multisamplingInfo, 0, sizeof(VkPipelineMultisampleStateCreateInfo));
    multisamplingInfo.sType                         = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
    multisamplingInfo.sampleShadingEnable           = MageFalse;
    multisamplingInfo.rasterizationSamples          = VK_SAMPLE_COUNT_1_BIT;

    VkPipelineColorBlendAttachmentState colorblendAttachments;
    memset(&colorblendAttachments, 0, sizeof(VkPipelineColorBlendAttachmentState));
    colorblendAttachments.colorWriteMask            = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT; 
    colorblendAttachments.blendEnable               = VK_FALSE;

    VkPipelineColorBlendStateCreateInfo colorblendInfo;
    memset(&colorblendInfo, 0, sizeof(VkPipelineColorBlendStateCreateInfo));
    colorblendInfo.sType                            = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
    colorblendInfo.logicOpEnable                    = VK_FALSE;
    colorblendInfo.logicOp                          = VK_LOGIC_OP_COPY;
    colorblendInfo.pAttachments                     = &colorblendAttachments;
    colorblendInfo.attachmentCount                  = 1;
    colorblendInfo.blendConstants[0]                = 0.0f;
    colorblendInfo.blendConstants[1]                = 0.0f;
    colorblendInfo.blendConstants[2]                = 0.0f;
    colorblendInfo.blendConstants[3]                = 0.0f;

    VkPipelineLayoutCreateInfo layoutInfo;
    memset(&layoutInfo, 0, sizeof(VkPipelineLayoutCreateInfo));
    layoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;

    VkResult r = vkCreatePipelineLayout(renderer->Device.LogicalDevice, &layoutInfo, NULL, &renderer->Pipeline.GraphicsPipelineLayout);
    return (r == VK_SUCCESS);
}