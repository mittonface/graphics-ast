#version 150
in vec4 a_position;
in vec2 a_uv1;
out vec2 v_uv1;
uniform mat4 projection, world, view;

void main()
{
    gl_Position =  projection * view * world * a_position;
    v_uv1 = a_uv1;
}
