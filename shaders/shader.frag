#version 450
#extension GL_EXT_nonuniform_qualifier : enable
layout(location = 0) in vec4 color;
layout(location = 1) in vec2 uv;
layout(location = 2) flat in int texture_id;

layout(location = 0) out vec4 fragColor;

layout(binding = 1) uniform sampler2D texSamplers[];

float Convert_sRGB_ToLinear (float thesRGBValue) {
    return thesRGBValue <= 0.04045f
    ? thesRGBValue / 12.92f
    : pow ((thesRGBValue + 0.055f) / 1.055f, 2.4f);
}

void main() {
    //TODO: Scroll
    //TODO: Fog Toggle
    //TODO: Texture Toggle
    vec4 texColor = texture(texSamplers[texture_id], vec2(uv.x, uv.y));
    vec4 color1 = color * vec4(1.0f / 255.0f);
    vec4 color2 = vec4(Convert_sRGB_ToLinear(color1.r), Convert_sRGB_ToLinear(color1.g), Convert_sRGB_ToLinear(color1.b), color1.a);

    texColor *= color2;

    fragColor = texColor;

    if(fragColor.a < 0.1f)
        discard;
}
