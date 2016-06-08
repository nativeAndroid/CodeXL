#include <stdint.h>

#if 0
/usr/local/google/home/olv/khronos/VulkanSamples/Demos/Hologram/Hologram.frag
Warning, version 310 is not yet complete; most version-specific features are present, but some are missing.


Linked fragment stage:


// Module Version 10000
// Generated by (magic number): 80001
// Id's are bound by 19

                              Capability Shader
               1:             ExtInstImport  "GLSL.std.450"
                              MemoryModel Logical GLSL450
                              EntryPoint Fragment 4  "main" 9 12
                              ExecutionMode 4 OriginLowerLeft
                              Source ESSL 310
                              Name 4  "main"
                              Name 9  "fragcolor"
                              Name 12  "color"
                              Decorate 9(fragcolor) Location 0
               2:             TypeVoid
               3:             TypeFunction 2
               6:             TypeFloat 32
               7:             TypeVector 6(float) 4
               8:             TypePointer Output 7(fvec4)
    9(fragcolor):      8(ptr) Variable Output
              10:             TypeVector 6(float) 3
              11:             TypePointer Input 10(fvec3)
       12(color):     11(ptr) Variable Input
              14:    6(float) Constant 1056964608
         4(main):           2 Function None 3
               5:             Label
              13:   10(fvec3) Load 12(color)
              15:    6(float) CompositeExtract 13 0
              16:    6(float) CompositeExtract 13 1
              17:    6(float) CompositeExtract 13 2
              18:    7(fvec4) CompositeConstruct 15 16 17 14
                              Store 9(fragcolor) 18
                              Return
                              FunctionEnd
#endif

static const uint32_t Hologram_frag[120] = {
    0x07230203, 0x00010000, 0x00080001, 0x00000013,
    0x00000000, 0x00020011, 0x00000001, 0x0006000b,
    0x00000001, 0x4c534c47, 0x6474732e, 0x3035342e,
    0x00000000, 0x0003000e, 0x00000000, 0x00000001,
    0x0007000f, 0x00000004, 0x00000004, 0x6e69616d,
    0x00000000, 0x00000009, 0x0000000c, 0x00030010,
    0x00000004, 0x00000008, 0x00030003, 0x00000001,
    0x00000136, 0x00040005, 0x00000004, 0x6e69616d,
    0x00000000, 0x00050005, 0x00000009, 0x67617266,
    0x6f6c6f63, 0x00000072, 0x00040005, 0x0000000c,
    0x6f6c6f63, 0x00000072, 0x00040047, 0x00000009,
    0x0000001e, 0x00000000, 0x00020013, 0x00000002,
    0x00030021, 0x00000003, 0x00000002, 0x00030016,
    0x00000006, 0x00000020, 0x00040017, 0x00000007,
    0x00000006, 0x00000004, 0x00040020, 0x00000008,
    0x00000003, 0x00000007, 0x0004003b, 0x00000008,
    0x00000009, 0x00000003, 0x00040017, 0x0000000a,
    0x00000006, 0x00000003, 0x00040020, 0x0000000b,
    0x00000001, 0x0000000a, 0x0004003b, 0x0000000b,
    0x0000000c, 0x00000001, 0x0004002b, 0x00000006,
    0x0000000e, 0x3f000000, 0x00050036, 0x00000002,
    0x00000004, 0x00000000, 0x00000003, 0x000200f8,
    0x00000005, 0x0004003d, 0x0000000a, 0x0000000d,
    0x0000000c, 0x00050051, 0x00000006, 0x0000000f,
    0x0000000d, 0x00000000, 0x00050051, 0x00000006,
    0x00000010, 0x0000000d, 0x00000001, 0x00050051,
    0x00000006, 0x00000011, 0x0000000d, 0x00000002,
    0x00070050, 0x00000007, 0x00000012, 0x0000000f,
    0x00000010, 0x00000011, 0x0000000e, 0x0003003e,
    0x00000009, 0x00000012, 0x000100fd, 0x00010038,
};
