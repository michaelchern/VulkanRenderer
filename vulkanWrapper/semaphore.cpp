#include "semaphore.h"

namespace LearnVulkan::Wrapper
{
    Semaphore::Semaphore(const Device::Ptr& device, const bool isTimeline)
    {
        mDevice = device;

        VkSemaphoreCreateInfo semaphoreInfo{};
        semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

        VkSemaphoreTypeCreateInfo timelineCreateInfo{};
        if (isTimeline)
        {
            timelineCreateInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO;
            timelineCreateInfo.semaphoreType = VK_SEMAPHORE_TYPE_TIMELINE;
            timelineCreateInfo.initialValue = 0;
            semaphoreInfo.pNext = &timelineCreateInfo;
        }

        if (vkCreateSemaphore(mDevice->getDevice(), &semaphoreInfo, nullptr, &mSemaphore) != VK_SUCCESS)
        {
            throw std::runtime_error("Error: failed to create Semaphore!");
        }
    }

    Semaphore::~Semaphore()
    {
        if (mSemaphore != VK_NULL_HANDLE)
        {
            vkDestroySemaphore(mDevice->getDevice(), mSemaphore, nullptr);
        }
    }

    void Semaphore::wait(uint64_t value)
    {
        VkSemaphoreWaitInfo waitInfo{};
        waitInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO;
        waitInfo.pSemaphores = &mSemaphore;
        waitInfo.pValues = &value;
        waitInfo.semaphoreCount = 1;
        vkWaitSemaphores(mDevice->getDevice(), &waitInfo, UINT64_MAX);
    }
}
