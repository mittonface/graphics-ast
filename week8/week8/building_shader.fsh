#version 150
in vec2 v_uv1;
out vec4 PixelColor;

uniform sampler2D tex;
void main()
{
    PixelColor = texture(tex, v_uv1);
}
