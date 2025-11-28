#pragma once

#include "base.h"
#include "vulkan/vulkan.h"
#include <functional>
#include <set>
#include <stdexcept>

namespace LearnVulkan::Wrapper
{
    class FeaturesChain
    {
    public:
        using Ptr = std::shared_ptr<FeaturesChain>;
        static Ptr create()
        {
            return std::make_shared<FeaturesChain>();
        }

        FeaturesChain();

        void prepareFeaturesChain();
        VkPhysicalDeviceFeatures2* getChainHead();

        FeaturesChain operator&(const FeaturesChain& features) const;
        FeaturesChain operator&(const VkPhysicalDeviceFeatures& features) const;
        FeaturesChain operator&(const VkPhysicalDeviceFeatures2& features) const;
        FeaturesChain operator&(const VkPhysicalDeviceVulkan11Features& features) const;
        FeaturesChain operator&(const VkPhysicalDeviceVulkan12Features& features) const;
        FeaturesChain operator&(const VkPhysicalDeviceVulkan13Features& features) const;
        FeaturesChain operator&(const VkPhysicalDeviceVulkan14Features& features) const;
        FeaturesChain operator&(const VkPhysicalDeviceAccelerationStructureFeaturesKHR& features) const;
        FeaturesChain operator&(const VkPhysicalDeviceRayTracingPipelineFeaturesKHR& features) const;
        FeaturesChain operator&(const VkPhysicalDeviceRayQueryFeaturesKHR& features) const;

        FeaturesChain operator|(const FeaturesChain& features) const;
        FeaturesChain operator|(const VkPhysicalDeviceFeatures& features) const;
        FeaturesChain operator|(const VkPhysicalDeviceFeatures2& features) const;
        FeaturesChain operator|(const VkPhysicalDeviceVulkan11Features& features) const;
        FeaturesChain operator|(const VkPhysicalDeviceVulkan12Features& features) const;
        FeaturesChain operator|(const VkPhysicalDeviceVulkan13Features& features) const;
        FeaturesChain operator|(const VkPhysicalDeviceVulkan14Features& features) const;
        FeaturesChain operator|(const VkPhysicalDeviceAccelerationStructureFeaturesKHR& features) const;
        FeaturesChain operator|(const VkPhysicalDeviceRayTracingPipelineFeaturesKHR& features) const;
        FeaturesChain operator|(const VkPhysicalDeviceRayQueryFeaturesKHR& features) const;

    private:
        void initializeChain();

        VkPhysicalDeviceFeatures2 mDeviceFeatures2{};
        VkPhysicalDeviceVulkan11Features mDeviceFeatures11{};
        VkPhysicalDeviceVulkan12Features mDeviceFeatures12{};
        VkPhysicalDeviceVulkan13Features mDeviceFeatures13{};
        VkPhysicalDeviceVulkan14Features mDeviceFeatures14{};

        VkPhysicalDeviceAccelerationStructureFeaturesKHR mAccelerationStructureFeatures{};
        VkPhysicalDeviceRayTracingPipelineFeaturesKHR mRayTracingPipelineFeatures{};
        VkPhysicalDeviceRayQueryFeaturesKHR mRayQueryFeatures{};

        CreateCallback mHardwareCreateInfos{};
    };

    struct CreateCallback
    {
        using InstanceExtensionsFunc = std::function<std::set<const char*>(const VkInstance&, const VkPhysicalDevice&)>;
        using DeviceExtensionsFunc = std::function<std::set<const char*>(const VkInstance&, const VkPhysicalDevice&)>;
        using DeviceFeaturesFunc = std::function<FeaturesChain(const VkInstance&, const VkPhysicalDevice&)>;

        InstanceExtensionsFunc requiredInstanceExtensions = [](const VkInstance&, const VkPhysicalDevice&) { return std::set<const char*>(); };
        DeviceExtensionsFunc requiredDeviceExtensions = [](const VkInstance&, const VkPhysicalDevice&) { return std::set<const char*>(); };
        DeviceFeaturesFunc requiredDeviceFeatures = [](const VkInstance&, const VkPhysicalDevice&) { return FeaturesChain(); };
    };
}