#version 430

layout(location = 0) in vec2 in_var_ATTRIBUTE0;
layout(location = 0) out vec4 out_var_SV_TARGET;

void main()
{
    out_var_SV_TARGET = (gl_FragCoord * 0.5) + vec4(0.5);
}

