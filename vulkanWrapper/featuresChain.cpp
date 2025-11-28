#include "FeaturesChain.h"

#define CORONA_APPLY_BOOL_OP(dst, src, op)       \
    do {                                         \
        dst = static_cast<VkBool32>(dst op src); \
    } while (0)

#define CORONA_AND_FEATURES(result, field) \
    CORONA_APPLY_BOOL_OP(result.field, features.field, &)

#define CORONA_OR_FEATURES(result, field) \
    CORONA_APPLY_BOOL_OP(result.field, features.field, |)

namespace LearnVulkan::Wrapper
{
    FeaturesChain::FeaturesChain()
    {
        initializeChain();
    }

    void FeaturesChain::initializeChain()
    {
        // rayQueryFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR;
        // rayQueryFeatures.pNext = nullptr;

        // rayTracingPipelineFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR;
        // rayTracingPipelineFeatures.pNext = &rayQueryFeatures;

        // accelerationStructureFeatures.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR;
        // accelerationStructureFeatures.pNext = &rayTracingPipelineFeatures;

        mDeviceFeatures14.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES;
        mDeviceFeatures14.pNext = nullptr;

        mDeviceFeatures13.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES;
        mDeviceFeatures13.pNext = &mDeviceFeatures14;

        mDeviceFeatures12.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES;
        mDeviceFeatures12.pNext = &mDeviceFeatures13;

        mDeviceFeatures11.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES;
        mDeviceFeatures11.pNext = &mDeviceFeatures12;

        mDeviceFeatures2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2;
        mDeviceFeatures2.pNext = &mDeviceFeatures11;
    }

    VkPhysicalDeviceFeatures2* FeaturesChain::getChainHead()
    {
        return &mDeviceFeatures2;
    }

    FeaturesChain FeaturesChain::operator&(const FeaturesChain& features) const 
    {
        return (*this & features.mDeviceFeatures2.features & features.mDeviceFeatures11 & features.mDeviceFeatures12 & features.mDeviceFeatures13 & features.mDeviceFeatures14);
    }

    FeaturesChain FeaturesChain::operator&(const VkPhysicalDeviceFeatures2& features) const
    {
        return (*this & features.features);
    }

    FeaturesChain FeaturesChain::operator&(const VkPhysicalDeviceFeatures& features) const 
    {
        FeaturesChain result = *this;
        auto& dst = result.mDeviceFeatures2.features;

        CORONA_AND_FEATURES(dst, robustBufferAccess);
        CORONA_AND_FEATURES(dst, fullDrawIndexUint32);
        CORONA_AND_FEATURES(dst, imageCubeArray);
        CORONA_AND_FEATURES(dst, independentBlend);
        CORONA_AND_FEATURES(dst, geometryShader);
        CORONA_AND_FEATURES(dst, tessellationShader);
        CORONA_AND_FEATURES(dst, sampleRateShading);
        CORONA_AND_FEATURES(dst, dualSrcBlend);
        CORONA_AND_FEATURES(dst, logicOp);
        CORONA_AND_FEATURES(dst, multiDrawIndirect);
        CORONA_AND_FEATURES(dst, drawIndirectFirstInstance);
        CORONA_AND_FEATURES(dst, depthClamp);
        CORONA_AND_FEATURES(dst, depthBiasClamp);
        CORONA_AND_FEATURES(dst, fillModeNonSolid);
        CORONA_AND_FEATURES(dst, depthBounds);
        CORONA_AND_FEATURES(dst, wideLines);
        CORONA_AND_FEATURES(dst, largePoints);
        CORONA_AND_FEATURES(dst, alphaToOne);
        CORONA_AND_FEATURES(dst, multiViewport);
        CORONA_AND_FEATURES(dst, samplerAnisotropy);
        CORONA_AND_FEATURES(dst, textureCompressionETC2);
        CORONA_AND_FEATURES(dst, textureCompressionASTC_LDR);
        CORONA_AND_FEATURES(dst, textureCompressionBC);
        CORONA_AND_FEATURES(dst, occlusionQueryPrecise);
        CORONA_AND_FEATURES(dst, pipelineStatisticsQuery);
        CORONA_AND_FEATURES(dst, vertexPipelineStoresAndAtomics);
        CORONA_AND_FEATURES(dst, fragmentStoresAndAtomics);
        CORONA_AND_FEATURES(dst, shaderTessellationAndGeometryPointSize);
        CORONA_AND_FEATURES(dst, shaderImageGatherExtended);
        CORONA_AND_FEATURES(dst, shaderStorageImageExtendedFormats);
        CORONA_AND_FEATURES(dst, shaderStorageImageMultisample);
        CORONA_AND_FEATURES(dst, shaderStorageImageReadWithoutFormat);
        CORONA_AND_FEATURES(dst, shaderStorageImageWriteWithoutFormat);
        CORONA_AND_FEATURES(dst, shaderUniformBufferArrayDynamicIndexing);
        CORONA_AND_FEATURES(dst, shaderSampledImageArrayDynamicIndexing);
        CORONA_AND_FEATURES(dst, shaderStorageBufferArrayDynamicIndexing);
        CORONA_AND_FEATURES(dst, shaderStorageImageArrayDynamicIndexing);
        CORONA_AND_FEATURES(dst, shaderClipDistance);
        CORONA_AND_FEATURES(dst, shaderCullDistance);
        CORONA_AND_FEATURES(dst, shaderFloat64);
        CORONA_AND_FEATURES(dst, shaderInt64);
        CORONA_AND_FEATURES(dst, shaderInt16);
        CORONA_AND_FEATURES(dst, shaderResourceResidency);
        CORONA_AND_FEATURES(dst, shaderResourceMinLod);
        CORONA_AND_FEATURES(dst, sparseBinding);
        CORONA_AND_FEATURES(dst, sparseResidencyBuffer);
        CORONA_AND_FEATURES(dst, sparseResidencyImage2D);
        CORONA_AND_FEATURES(dst, sparseResidencyImage3D);
        CORONA_AND_FEATURES(dst, sparseResidency2Samples);
        CORONA_AND_FEATURES(dst, sparseResidency4Samples);
        CORONA_AND_FEATURES(dst, sparseResidency8Samples);
        CORONA_AND_FEATURES(dst, sparseResidency16Samples);
        CORONA_AND_FEATURES(dst, sparseResidencyAliased);
        CORONA_AND_FEATURES(dst, variableMultisampleRate);
        CORONA_AND_FEATURES(dst, inheritedQueries);

        return result;
    }

    FeaturesChain FeaturesChain::operator&(const VkPhysicalDeviceVulkan11Features& features) const
    {
        FeaturesChain result = *this;
        auto& dst = result.mDeviceFeatures11;

        CORONA_AND_FEATURES(dst, storageBuffer16BitAccess);
        CORONA_AND_FEATURES(dst, uniformAndStorageBuffer16BitAccess);
        CORONA_AND_FEATURES(dst, storagePushConstant16);
        CORONA_AND_FEATURES(dst, storageInputOutput16);
        CORONA_AND_FEATURES(dst, multiview);
        CORONA_AND_FEATURES(dst, multiviewGeometryShader);
        CORONA_AND_FEATURES(dst, multiviewTessellationShader);
        CORONA_AND_FEATURES(dst, variablePointersStorageBuffer);
        CORONA_AND_FEATURES(dst, variablePointers);
        CORONA_AND_FEATURES(dst, protectedMemory);
        CORONA_AND_FEATURES(dst, samplerYcbcrConversion);
        CORONA_AND_FEATURES(dst, shaderDrawParameters);

        return result;
    }

    FeaturesChain FeaturesChain::operator&(const VkPhysicalDeviceVulkan12Features& features) const 
    {
        FeaturesChain result = *this;
        auto& dst = result.mDeviceFeatures12;

        CORONA_AND_FEATURES(dst, samplerMirrorClampToEdge);
        CORONA_AND_FEATURES(dst, drawIndirectCount);
        CORONA_AND_FEATURES(dst, storageBuffer8BitAccess);
        CORONA_AND_FEATURES(dst, uniformAndStorageBuffer8BitAccess);
        CORONA_AND_FEATURES(dst, storagePushConstant8);
        CORONA_AND_FEATURES(dst, shaderBufferInt64Atomics);
        CORONA_AND_FEATURES(dst, shaderSharedInt64Atomics);
        CORONA_AND_FEATURES(dst, shaderFloat16);
        CORONA_AND_FEATURES(dst, shaderInt8);
        CORONA_AND_FEATURES(dst, descriptorIndexing);
        CORONA_AND_FEATURES(dst, shaderInputAttachmentArrayDynamicIndexing);
        CORONA_AND_FEATURES(dst, shaderUniformTexelBufferArrayDynamicIndexing);
        CORONA_AND_FEATURES(dst, shaderStorageTexelBufferArrayDynamicIndexing);
        CORONA_AND_FEATURES(dst, shaderUniformBufferArrayNonUniformIndexing);
        CORONA_AND_FEATURES(dst, shaderSampledImageArrayNonUniformIndexing);
        CORONA_AND_FEATURES(dst, shaderStorageBufferArrayNonUniformIndexing);
        CORONA_AND_FEATURES(dst, shaderStorageImageArrayNonUniformIndexing);
        CORONA_AND_FEATURES(dst, shaderInputAttachmentArrayNonUniformIndexing);
        CORONA_AND_FEATURES(dst, shaderUniformTexelBufferArrayNonUniformIndexing);
        CORONA_AND_FEATURES(dst, shaderStorageTexelBufferArrayNonUniformIndexing);
        CORONA_AND_FEATURES(dst, descriptorBindingUniformBufferUpdateAfterBind);
        CORONA_AND_FEATURES(dst, descriptorBindingSampledImageUpdateAfterBind);
        CORONA_AND_FEATURES(dst, descriptorBindingStorageImageUpdateAfterBind);
        CORONA_AND_FEATURES(dst, descriptorBindingStorageBufferUpdateAfterBind);
        CORONA_AND_FEATURES(dst, descriptorBindingUniformTexelBufferUpdateAfterBind);
        CORONA_AND_FEATURES(dst, descriptorBindingStorageTexelBufferUpdateAfterBind);
        CORONA_AND_FEATURES(dst, descriptorBindingUpdateUnusedWhilePending);
        CORONA_AND_FEATURES(dst, descriptorBindingPartiallyBound);
        CORONA_AND_FEATURES(dst, descriptorBindingVariableDescriptorCount);
        CORONA_AND_FEATURES(dst, runtimeDescriptorArray);
        CORONA_AND_FEATURES(dst, samplerFilterMinmax);
        CORONA_AND_FEATURES(dst, scalarBlockLayout);
        CORONA_AND_FEATURES(dst, imagelessFramebuffer);
        CORONA_AND_FEATURES(dst, uniformBufferStandardLayout);
        CORONA_AND_FEATURES(dst, shaderSubgroupExtendedTypes);
        CORONA_AND_FEATURES(dst, separateDepthStencilLayouts);
        CORONA_AND_FEATURES(dst, hostQueryReset);
        CORONA_AND_FEATURES(dst, timelineSemaphore);
        CORONA_AND_FEATURES(dst, bufferDeviceAddress);
        CORONA_AND_FEATURES(dst, bufferDeviceAddressCaptureReplay);
        CORONA_AND_FEATURES(dst, bufferDeviceAddressMultiDevice);
        CORONA_AND_FEATURES(dst, vulkanMemoryModel);
        CORONA_AND_FEATURES(dst, vulkanMemoryModelDeviceScope);
        CORONA_AND_FEATURES(dst, vulkanMemoryModelAvailabilityVisibilityChains);
        CORONA_AND_FEATURES(dst, shaderOutputViewportIndex);
        CORONA_AND_FEATURES(dst, shaderOutputLayer);
        CORONA_AND_FEATURES(dst, subgroupBroadcastDynamicId);

        return result;
    }

    FeaturesChain FeaturesChain::operator&(const VkPhysicalDeviceVulkan13Features& features) const 
    {
        FeaturesChain result = *this;
        auto& dst = result.mDeviceFeatures13;

        CORONA_AND_FEATURES(dst, robustImageAccess);
        CORONA_AND_FEATURES(dst, inlineUniformBlock);
        CORONA_AND_FEATURES(dst, descriptorBindingInlineUniformBlockUpdateAfterBind);
        CORONA_AND_FEATURES(dst, pipelineCreationCacheControl);
        CORONA_AND_FEATURES(dst, privateData);
        CORONA_AND_FEATURES(dst, shaderDemoteToHelperInvocation);
        CORONA_AND_FEATURES(dst, shaderTerminateInvocation);
        CORONA_AND_FEATURES(dst, subgroupSizeControl);
        CORONA_AND_FEATURES(dst, computeFullSubgroups);
        CORONA_AND_FEATURES(dst, synchronization2);
        CORONA_AND_FEATURES(dst, textureCompressionASTC_HDR);
        CORONA_AND_FEATURES(dst, shaderZeroInitializeWorkgroupMemory);
        CORONA_AND_FEATURES(dst, dynamicRendering);
        CORONA_AND_FEATURES(dst, shaderIntegerDotProduct);
        CORONA_AND_FEATURES(dst, maintenance4);

        return result;
    }

    FeaturesChain FeaturesChain::operator&(const VkPhysicalDeviceVulkan14Features& features) const 
    {
        FeaturesChain result = *this;
        auto& dst = result.mDeviceFeatures14;

        CORONA_AND_FEATURES(dst, globalPriorityQuery);
        CORONA_AND_FEATURES(dst, shaderSubgroupRotate);
        CORONA_AND_FEATURES(dst, shaderSubgroupRotateClustered);
        CORONA_AND_FEATURES(dst, shaderFloatControls2);
        CORONA_AND_FEATURES(dst, shaderExpectAssume);
        CORONA_AND_FEATURES(dst, rectangularLines);
        CORONA_AND_FEATURES(dst, bresenhamLines);
        CORONA_AND_FEATURES(dst, smoothLines);
        CORONA_AND_FEATURES(dst, stippledRectangularLines);
        CORONA_AND_FEATURES(dst, stippledBresenhamLines);
        CORONA_AND_FEATURES(dst, stippledSmoothLines);
        CORONA_AND_FEATURES(dst, vertexAttributeInstanceRateDivisor);
        CORONA_AND_FEATURES(dst, vertexAttributeInstanceRateZeroDivisor);
        CORONA_AND_FEATURES(dst, indexTypeUint8);
        CORONA_AND_FEATURES(dst, dynamicRenderingLocalRead);
        CORONA_AND_FEATURES(dst, maintenance5);
        CORONA_AND_FEATURES(dst, maintenance6);
        CORONA_AND_FEATURES(dst, pipelineProtectedAccess);
        CORONA_AND_FEATURES(dst, pipelineRobustness);
        CORONA_AND_FEATURES(dst, hostImageCopy);
        CORONA_AND_FEATURES(dst, pushDescriptor);

        return result;
    }

    FeaturesChain FeaturesChain::operator&(const VkPhysicalDeviceAccelerationStructureFeaturesKHR& features) const 
    {
        FeaturesChain result = *this;
        auto& dst = result.mAccelerationStructureFeatures;

        CORONA_AND_FEATURES(dst, accelerationStructure);
        CORONA_AND_FEATURES(dst, accelerationStructureCaptureReplay);
        CORONA_AND_FEATURES(dst, accelerationStructureIndirectBuild);
        CORONA_AND_FEATURES(dst, accelerationStructureHostCommands);
        CORONA_AND_FEATURES(dst, descriptorBindingAccelerationStructureUpdateAfterBind);

        return result;
    }

    FeaturesChain FeaturesChain::operator&(const VkPhysicalDeviceRayTracingPipelineFeaturesKHR& features) const 
    {
        FeaturesChain result = *this;
        auto& dst = result.mRayTracingPipelineFeatures;

        CORONA_AND_FEATURES(dst, rayTracingPipeline);
        CORONA_AND_FEATURES(dst, rayTracingPipelineShaderGroupHandleCaptureReplay);
        CORONA_AND_FEATURES(dst, rayTracingPipelineShaderGroupHandleCaptureReplayMixed);
        CORONA_AND_FEATURES(dst, rayTracingPipelineTraceRaysIndirect);
        CORONA_AND_FEATURES(dst, rayTraversalPrimitiveCulling);

        return result;
    }

    FeaturesChain FeaturesChain::operator&(const VkPhysicalDeviceRayQueryFeaturesKHR& features) const 
    {
        FeaturesChain result = *this;
        CORONA_AND_FEATURES(result.mRayQueryFeatures, rayQuery);
        return result;
    }

    FeaturesChain FeaturesChain::operator|(const FeaturesChain& features) const 
    {
        return (*this | features.mDeviceFeatures2.features | features.mDeviceFeatures11 | features.mDeviceFeatures12 | features.mDeviceFeatures13 | features.mDeviceFeatures14);
    }

    FeaturesChain FeaturesChain::operator|(const VkPhysicalDeviceFeatures2& features) const
    {
        return (*this | features.features);
    }

    FeaturesChain FeaturesChain::operator|(const VkPhysicalDeviceFeatures& features) const 
    {
        FeaturesChain result = *this;
        auto& dst = result.mDeviceFeatures2.features;

        CORONA_OR_FEATURES(dst, robustBufferAccess);
        CORONA_OR_FEATURES(dst, fullDrawIndexUint32);
        CORONA_OR_FEATURES(dst, imageCubeArray);
        CORONA_OR_FEATURES(dst, independentBlend);
        CORONA_OR_FEATURES(dst, geometryShader);
        CORONA_OR_FEATURES(dst, tessellationShader);
        CORONA_OR_FEATURES(dst, sampleRateShading);
        CORONA_OR_FEATURES(dst, dualSrcBlend);
        CORONA_OR_FEATURES(dst, logicOp);
        CORONA_OR_FEATURES(dst, multiDrawIndirect);
        CORONA_OR_FEATURES(dst, drawIndirectFirstInstance);
        CORONA_OR_FEATURES(dst, depthClamp);
        CORONA_OR_FEATURES(dst, depthBiasClamp);
        CORONA_OR_FEATURES(dst, fillModeNonSolid);
        CORONA_OR_FEATURES(dst, depthBounds);
        CORONA_OR_FEATURES(dst, wideLines);
        CORONA_OR_FEATURES(dst, largePoints);
        CORONA_OR_FEATURES(dst, alphaToOne);
        CORONA_OR_FEATURES(dst, multiViewport);
        CORONA_OR_FEATURES(dst, samplerAnisotropy);
        CORONA_OR_FEATURES(dst, textureCompressionETC2);
        CORONA_OR_FEATURES(dst, textureCompressionASTC_LDR);
        CORONA_OR_FEATURES(dst, textureCompressionBC);
        CORONA_OR_FEATURES(dst, occlusionQueryPrecise);
        CORONA_OR_FEATURES(dst, pipelineStatisticsQuery);
        CORONA_OR_FEATURES(dst, vertexPipelineStoresAndAtomics);
        CORONA_OR_FEATURES(dst, fragmentStoresAndAtomics);
        CORONA_OR_FEATURES(dst, shaderTessellationAndGeometryPointSize);
        CORONA_OR_FEATURES(dst, shaderImageGatherExtended);
        CORONA_OR_FEATURES(dst, shaderStorageImageExtendedFormats);
        CORONA_OR_FEATURES(dst, shaderStorageImageMultisample);
        CORONA_OR_FEATURES(dst, shaderStorageImageReadWithoutFormat);
        CORONA_OR_FEATURES(dst, shaderStorageImageWriteWithoutFormat);
        CORONA_OR_FEATURES(dst, shaderUniformBufferArrayDynamicIndexing);
        CORONA_OR_FEATURES(dst, shaderSampledImageArrayDynamicIndexing);
        CORONA_OR_FEATURES(dst, shaderStorageBufferArrayDynamicIndexing);
        CORONA_OR_FEATURES(dst, shaderStorageImageArrayDynamicIndexing);
        CORONA_OR_FEATURES(dst, shaderClipDistance);
        CORONA_OR_FEATURES(dst, shaderCullDistance);
        CORONA_OR_FEATURES(dst, shaderFloat64);
        CORONA_OR_FEATURES(dst, shaderInt64);
        CORONA_OR_FEATURES(dst, shaderInt16);
        CORONA_OR_FEATURES(dst, shaderResourceResidency);
        CORONA_OR_FEATURES(dst, shaderResourceMinLod);
        CORONA_OR_FEATURES(dst, sparseBinding);
        CORONA_OR_FEATURES(dst, sparseResidencyBuffer);
        CORONA_OR_FEATURES(dst, sparseResidencyImage2D);
        CORONA_OR_FEATURES(dst, sparseResidencyImage3D);
        CORONA_OR_FEATURES(dst, sparseResidency2Samples);
        CORONA_OR_FEATURES(dst, sparseResidency4Samples);
        CORONA_OR_FEATURES(dst, sparseResidency8Samples);
        CORONA_OR_FEATURES(dst, sparseResidency16Samples);
        CORONA_OR_FEATURES(dst, sparseResidencyAliased);
        CORONA_OR_FEATURES(dst, variableMultisampleRate);
        CORONA_OR_FEATURES(dst, inheritedQueries);

        return result;
    }

    FeaturesChain FeaturesChain::operator|(const VkPhysicalDeviceVulkan11Features& features) const 
    {
        FeaturesChain result = *this;
        auto& dst = result.mDeviceFeatures11;

        CORONA_OR_FEATURES(dst, storageBuffer16BitAccess);
        CORONA_OR_FEATURES(dst, uniformAndStorageBuffer16BitAccess);
        CORONA_OR_FEATURES(dst, storagePushConstant16);
        CORONA_OR_FEATURES(dst, storageInputOutput16);
        CORONA_OR_FEATURES(dst, multiview);
        CORONA_OR_FEATURES(dst, multiviewGeometryShader);
        CORONA_OR_FEATURES(dst, multiviewTessellationShader);
        CORONA_OR_FEATURES(dst, variablePointersStorageBuffer);
        CORONA_OR_FEATURES(dst, variablePointers);
        CORONA_OR_FEATURES(dst, protectedMemory);
        CORONA_OR_FEATURES(dst, samplerYcbcrConversion);
        CORONA_OR_FEATURES(dst, shaderDrawParameters);

        return result;
    }

    FeaturesChain FeaturesChain::operator|(const VkPhysicalDeviceVulkan12Features& features) const
    {
        FeaturesChain result = *this;
        auto& dst = result.mDeviceFeatures12;

        CORONA_OR_FEATURES(dst, samplerMirrorClampToEdge);
        CORONA_OR_FEATURES(dst, drawIndirectCount);
        CORONA_OR_FEATURES(dst, storageBuffer8BitAccess);
        CORONA_OR_FEATURES(dst, uniformAndStorageBuffer8BitAccess);
        CORONA_OR_FEATURES(dst, storagePushConstant8);
        CORONA_OR_FEATURES(dst, shaderBufferInt64Atomics);
        CORONA_OR_FEATURES(dst, shaderSharedInt64Atomics);
        CORONA_OR_FEATURES(dst, shaderFloat16);
        CORONA_OR_FEATURES(dst, shaderInt8);
        CORONA_OR_FEATURES(dst, descriptorIndexing);
        CORONA_OR_FEATURES(dst, shaderInputAttachmentArrayDynamicIndexing);
        CORONA_OR_FEATURES(dst, shaderUniformTexelBufferArrayDynamicIndexing);
        CORONA_OR_FEATURES(dst, shaderStorageTexelBufferArrayDynamicIndexing);
        CORONA_OR_FEATURES(dst, shaderUniformBufferArrayNonUniformIndexing);
        CORONA_OR_FEATURES(dst, shaderSampledImageArrayNonUniformIndexing);
        CORONA_OR_FEATURES(dst, shaderStorageBufferArrayNonUniformIndexing);
        CORONA_OR_FEATURES(dst, shaderStorageImageArrayNonUniformIndexing);
        CORONA_OR_FEATURES(dst, shaderInputAttachmentArrayNonUniformIndexing);
        CORONA_OR_FEATURES(dst, shaderUniformTexelBufferArrayNonUniformIndexing);
        CORONA_OR_FEATURES(dst, shaderStorageTexelBufferArrayNonUniformIndexing);
        CORONA_OR_FEATURES(dst, descriptorBindingUniformBufferUpdateAfterBind);
        CORONA_OR_FEATURES(dst, descriptorBindingSampledImageUpdateAfterBind);
        CORONA_OR_FEATURES(dst, descriptorBindingStorageImageUpdateAfterBind);
        CORONA_OR_FEATURES(dst, descriptorBindingStorageBufferUpdateAfterBind);
        CORONA_OR_FEATURES(dst, descriptorBindingUniformTexelBufferUpdateAfterBind);
        CORONA_OR_FEATURES(dst, descriptorBindingStorageTexelBufferUpdateAfterBind);
        CORONA_OR_FEATURES(dst, descriptorBindingUpdateUnusedWhilePending);
        CORONA_OR_FEATURES(dst, descriptorBindingPartiallyBound);
        CORONA_OR_FEATURES(dst, descriptorBindingVariableDescriptorCount);
        CORONA_OR_FEATURES(dst, runtimeDescriptorArray);
        CORONA_OR_FEATURES(dst, samplerFilterMinmax);
        CORONA_OR_FEATURES(dst, scalarBlockLayout);
        CORONA_OR_FEATURES(dst, imagelessFramebuffer);
        CORONA_OR_FEATURES(dst, uniformBufferStandardLayout);
        CORONA_OR_FEATURES(dst, shaderSubgroupExtendedTypes);
        CORONA_OR_FEATURES(dst, separateDepthStencilLayouts);
        CORONA_OR_FEATURES(dst, hostQueryReset);
        CORONA_OR_FEATURES(dst, timelineSemaphore);
        CORONA_OR_FEATURES(dst, bufferDeviceAddress);
        CORONA_OR_FEATURES(dst, bufferDeviceAddressCaptureReplay);
        CORONA_OR_FEATURES(dst, bufferDeviceAddressMultiDevice);
        CORONA_OR_FEATURES(dst, vulkanMemoryModel);
        CORONA_OR_FEATURES(dst, vulkanMemoryModelDeviceScope);
        CORONA_OR_FEATURES(dst, vulkanMemoryModelAvailabilityVisibilityChains);
        CORONA_OR_FEATURES(dst, shaderOutputViewportIndex);
        CORONA_OR_FEATURES(dst, shaderOutputLayer);
        CORONA_OR_FEATURES(dst, subgroupBroadcastDynamicId);

        return result;
    }

    FeaturesChain FeaturesChain::operator|(const VkPhysicalDeviceVulkan13Features& features) const
    {
        FeaturesChain result = *this;
        auto& dst = result.mDeviceFeatures13;

        CORONA_OR_FEATURES(dst, robustImageAccess);
        CORONA_OR_FEATURES(dst, inlineUniformBlock);
        CORONA_OR_FEATURES(dst, descriptorBindingInlineUniformBlockUpdateAfterBind);
        CORONA_OR_FEATURES(dst, pipelineCreationCacheControl);
        CORONA_OR_FEATURES(dst, privateData);
        CORONA_OR_FEATURES(dst, shaderDemoteToHelperInvocation);
        CORONA_OR_FEATURES(dst, shaderTerminateInvocation);
        CORONA_OR_FEATURES(dst, subgroupSizeControl);
        CORONA_OR_FEATURES(dst, computeFullSubgroups);
        CORONA_OR_FEATURES(dst, synchronization2);
        CORONA_OR_FEATURES(dst, textureCompressionASTC_HDR);
        CORONA_OR_FEATURES(dst, shaderZeroInitializeWorkgroupMemory);
        CORONA_OR_FEATURES(dst, dynamicRendering);
        CORONA_OR_FEATURES(dst, shaderIntegerDotProduct);
        CORONA_OR_FEATURES(dst, maintenance4);

        return result;
    }

    FeaturesChain FeaturesChain::operator|(const VkPhysicalDeviceVulkan14Features& features) const 
    {
        FeaturesChain result = *this;
        auto& dst = result.mDeviceFeatures14;

        CORONA_OR_FEATURES(dst, globalPriorityQuery);
        CORONA_OR_FEATURES(dst, shaderSubgroupRotate);
        CORONA_OR_FEATURES(dst, shaderSubgroupRotateClustered);
        CORONA_OR_FEATURES(dst, shaderFloatControls2);
        CORONA_OR_FEATURES(dst, shaderExpectAssume);
        CORONA_OR_FEATURES(dst, rectangularLines);
        CORONA_OR_FEATURES(dst, bresenhamLines);
        CORONA_OR_FEATURES(dst, smoothLines);
        CORONA_OR_FEATURES(dst, stippledRectangularLines);
        CORONA_OR_FEATURES(dst, stippledBresenhamLines);
        CORONA_OR_FEATURES(dst, stippledSmoothLines);
        CORONA_OR_FEATURES(dst, vertexAttributeInstanceRateDivisor);
        CORONA_OR_FEATURES(dst, vertexAttributeInstanceRateZeroDivisor);
        CORONA_OR_FEATURES(dst, indexTypeUint8);
        CORONA_OR_FEATURES(dst, dynamicRenderingLocalRead);
        CORONA_OR_FEATURES(dst, maintenance5);
        CORONA_OR_FEATURES(dst, maintenance6);
        CORONA_OR_FEATURES(dst, pipelineProtectedAccess);
        CORONA_OR_FEATURES(dst, pipelineRobustness);
        CORONA_OR_FEATURES(dst, hostImageCopy);
        CORONA_OR_FEATURES(dst, pushDescriptor);

        return result;
    }

    FeaturesChain FeaturesChain::operator|(const VkPhysicalDeviceAccelerationStructureFeaturesKHR& features) const 
    {
        FeaturesChain result = *this;
        auto& dst = result.mAccelerationStructureFeatures;

        CORONA_OR_FEATURES(dst, accelerationStructure);
        CORONA_OR_FEATURES(dst, accelerationStructureCaptureReplay);
        CORONA_OR_FEATURES(dst, accelerationStructureIndirectBuild);
        CORONA_OR_FEATURES(dst, accelerationStructureHostCommands);
        CORONA_OR_FEATURES(dst, descriptorBindingAccelerationStructureUpdateAfterBind);

        return result;
    }

    FeaturesChain FeaturesChain::operator|(const VkPhysicalDeviceRayTracingPipelineFeaturesKHR& features) const
    {
        FeaturesChain result = *this;
        auto& dst = result.mRayTracingPipelineFeatures;

        CORONA_OR_FEATURES(dst, rayTracingPipeline);
        CORONA_OR_FEATURES(dst, rayTracingPipelineShaderGroupHandleCaptureReplay);
        CORONA_OR_FEATURES(dst, rayTracingPipelineShaderGroupHandleCaptureReplayMixed);
        CORONA_OR_FEATURES(dst, rayTracingPipelineTraceRaysIndirect);
        CORONA_OR_FEATURES(dst, rayTraversalPrimitiveCulling);

        return result;
    }

    FeaturesChain FeaturesChain::operator|(const VkPhysicalDeviceRayQueryFeaturesKHR& features) const 
    {
        FeaturesChain result = *this;
        CORONA_OR_FEATURES(result.mRayQueryFeatures, rayQuery);
        return result;
    }

    void FeaturesChain::prepareFeaturesChain()
    {
        // 配置所需实例扩展
        mHardwareCreateInfos.requiredInstanceExtensions = [](const VkInstance&, const VkPhysicalDevice&)
            {
                std::set<const char*> extensions
                {
                    "VK_KHR_surface",
                    VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME,
                    VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME
                };
#if _WIN32 || _WIN64
                extensions.insert(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);
#elif __APPLE__
                extensions.insert(VK_MVK_MOLTENVK_EXTENSION_NAME);
                extensions.insert(VK_MVK_MACOS_SURFACE_EXTENSION_NAME);
#elif __linux__
                extensions.insert(VK_KHR_XLIB_SURFACE_EXTENSION_NAME);
#endif
                return extensions;
            };

        // 配置所需设备扩展
        mHardwareCreateInfos.requiredDeviceExtensions = [](const VkInstance&, const VkPhysicalDevice&)
            {
                return std::set<const char*>
                {
                    VK_KHR_SWAPCHAIN_EXTENSION_NAME,
                        VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME,
                        VK_KHR_16BIT_STORAGE_EXTENSION_NAME,
                        VK_KHR_MULTIVIEW_EXTENSION_NAME,
                        VK_AMD_GPU_SHADER_HALF_FLOAT_EXTENSION_NAME,
                        VK_KHR_GET_MEMORY_REQUIREMENTS_2_EXTENSION_NAME,
                        VK_EXT_SHADER_SUBGROUP_BALLOT_EXTENSION_NAME,
                        VK_KHR_TIMELINE_SEMAPHORE_EXTENSION_NAME,
                        VK_KHR_EXTERNAL_SEMAPHORE_EXTENSION_NAME,
                        VK_KHR_SYNCHRONIZATION_2_EXTENSION_NAME,
                        VK_KHR_EXTERNAL_MEMORY_EXTENSION_NAME,
                        VK_EXT_EXTERNAL_MEMORY_HOST_EXTENSION_NAME,
#if _WIN32 || _WIN64
                        VK_KHR_EXTERNAL_MEMORY_WIN32_EXTENSION_NAME,
                        VK_KHR_EXTERNAL_SEMAPHORE_WIN32_EXTENSION_NAME
#endif
                };
            };

        mHardwareCreateInfos.requiredDeviceFeatures = [](const VkInstance&, const VkPhysicalDevice&)
            {

                VkPhysicalDeviceFeatures features{};
                features.samplerAnisotropy = VK_TRUE;
                features.shaderInt16 = VK_TRUE;
                features.wideLines = VK_TRUE;

                VkPhysicalDeviceVulkan11Features features11{};
                features11.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES;
                features11.multiview = VK_TRUE;

                VkPhysicalDeviceVulkan12Features features12{};
                features12.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES;
                features12.bufferDeviceAddress = VK_TRUE;
                features12.shaderFloat16 = VK_TRUE;
                features12.shaderSampledImageArrayNonUniformIndexing = VK_TRUE;
                features12.descriptorBindingSampledImageUpdateAfterBind = VK_TRUE;
                features12.shaderUniformBufferArrayNonUniformIndexing = VK_TRUE;
                features12.descriptorBindingUniformBufferUpdateAfterBind = VK_TRUE;
                features12.shaderStorageBufferArrayNonUniformIndexing = VK_TRUE;
                features12.descriptorBindingStorageBufferUpdateAfterBind = VK_TRUE;
                features12.descriptorBindingPartiallyBound = VK_TRUE;
                features12.runtimeDescriptorArray = VK_TRUE;
                features12.descriptorBindingStorageImageUpdateAfterBind = VK_TRUE;
                features12.descriptorBindingVariableDescriptorCount = VK_TRUE;
                features12.descriptorIndexing = VK_TRUE;
                features12.timelineSemaphore = VK_TRUE;

                VkPhysicalDeviceVulkan13Features features13{};
                features13.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES;
                features13.synchronization2 = VK_TRUE;

                return (FeaturesChain() | features | features11 | features12 | features13);
            };
    }
}

#undef CORONA_APPLY_BOOL_OP
#undef CORONA_AND_FEATURES
#undef CORONA_OR_FEATURES