in highp vec4 posAttr;
uniform highp mat4 matrix;
uniform lowp vec4 color;
uniform highp float morph;
varying lowp vec4 col;
void main()
{
    col = color;
    vec4 r_n = vec4(normalize(posAttr.xyz), 1.0);
    vec4 finpos = mix(posAttr, r_n, morph);
    gl_Position = matrix * finpos;
}
