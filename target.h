/**
Copyright © 2018 nicegraf contributors
Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the “Software”), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#pragma once

// Target API class.
enum class target_api {
  GL, METAL, VULKAN
};

// Device type that a target API runs on.
enum class target_platform_class {
  DONTCARE,
  DESKTOP,
  MOBILE
};

// Information about a compilation target.
struct target_info {
  target_api api; // API class.
  const char *file_ext; // Extension for the generated files.
  uint32_t version_maj; // Major version number.
  uint32_t version_min; // Minor version number.
  target_platform_class platform; // Device types that the target API runs on.
};

struct named_target_info {
  const char *name;
  target_info target;
};

// Map of string identifiers to a target-specific information.
static const struct named_target_info TARGET_MAP[] = {
  {
    "gl430",
    {
      target_api::GL,
      "430.glsl",
      4u, 3u,
      target_platform_class::DESKTOP
    }
  },
  {
    "gles300",
    {
      target_api::GL,
      "300es.glsl",
      3u, 0u,
      target_platform_class::MOBILE
    }
  },
  {
    "gles310",
    {
      target_api::GL,
      "310es.glsl",
      3u, 1u,
      target_platform_class::MOBILE
    }
  },
  {
    "msl10",
    {
      target_api::METAL,
      "10.msl",
      1u, 0u,
      target_platform_class::DESKTOP
    }
  },
  {
    "msl11",
    {
      target_api::METAL,
      "11.msl",
      1u, 1u,
      target_platform_class::DESKTOP
    }
  },
  {
    "msl12",
    {
      target_api::METAL,
      "12.msl",
      1u, 2u,
      target_platform_class::DESKTOP
    }
  },
  {
    "msl20",
    {
      target_api::METAL,
      "20.msl",
      2u, 0u,
      target_platform_class::DESKTOP
    }
  },
  {
    "msl10ios",
    {
      target_api::METAL,
      "10ios.msl",
      1u, 0u,
      target_platform_class::MOBILE
    }
  },
  {
    "msl11ios",
    {
      target_api::METAL,
      "11ios.msl",
      1u, 1u,
      target_platform_class::MOBILE
    }
  },
  {
    "msl12ios",
    {
      target_api::METAL,
      "12ios.msl",
      1u, 2u,
      target_platform_class::MOBILE
    }
  },
  {
    "msl20ios",
    {
      target_api::METAL,
      "20ios.msl",
      2u, 0u,
      target_platform_class::MOBILE
    }
  },
  {
    "spv",
    {
      target_api::VULKAN,
      "spv",
      0u, 0u,
      target_platform_class::DONTCARE
    }
  }
};
constexpr uint32_t TARGET_COUNT = sizeof(TARGET_MAP)/sizeof(TARGET_MAP[0]);

