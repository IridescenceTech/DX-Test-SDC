#version 450

layout(push_constant) uniform PER_OBJECT
{
    mat4 model;
    mat4 projview;
} ubo;

layout(location = 0) in vec3 aPos;
layout(location = 1) in uvec4 aCol;
layout(location = 2) in vec2 aTex;

layout(location = 0) out vec4 color;
layout(location = 1) out vec2 uv;
layout(location = 2) out flat int texture_id;

void main() {
    mat4 model = ubo.model;
    texture_id = int(model[3][3]);
    model[3][3] = 1.0f;

    gl_Position = ubo.projview * model * vec4(aPos, 1.0);
    uv = aTex;
    color = aCol;
}