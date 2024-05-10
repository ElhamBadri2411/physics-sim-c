#version 330 core
layout (location = 0) in vec2 aPos; 
layout (location = 1) in float aRadius;

uniform mat4 projection;

void main()
{
    gl_Position = projection * vec4(aPos, 0.0, 1.0); // Convert the vec2 position to a vec4 with z = 0 and w = 1
    gl_PointSize = aRadius * 2.0;
}

