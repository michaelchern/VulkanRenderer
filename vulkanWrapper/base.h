#pragma once

#include <array>
#include <chrono>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

#define VOLK_IMPLEMENTATION
#include <volk/volk.h>

const std::vector<const char*> validationLayers =
{
    "VK_LAYER_KHRONOS_validation"
};

struct VPMatrices
{
    glm::mat4 mViewMatrix;
    glm::mat4 mProjectionMatrix;

    VPMatrices()
    {
        mViewMatrix = glm::mat4(1.0f);
        mProjectionMatrix = glm::mat4(1.0f);
    }
};

struct ObjectUniform
{
    glm::mat4 mModelMatrix;

    ObjectUniform()
    {
        mModelMatrix = glm::mat4(1.0f);
    }
};
