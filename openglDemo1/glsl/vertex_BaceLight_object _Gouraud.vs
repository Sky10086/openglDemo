#version 330 core
attribute vec3 position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

//Gouraud光照，是在顶点着色器中使用的光照，顶点数量少，所以计算量少，但是由于片段着色器的插值效果没有在片段着色器中进行(即冯氏光照)好

//法向量
attribute vec3 normal;

varying vec3 Gouraud;

//光源的位置
uniform vec3 lightPos;
//观察者在世界空间的位置，即摄像机的位置
uniform vec3 viewPos;
uniform vec3 lightColor;

void main()
{
    gl_Position = projection*view*model*vec4(position, 1.0);
	vec3 Normal = mat3(transpose(inverse(model))) * normal;
	vec3 FragPos = vec3(model*vec4(position,1.0));
	
	//计算环境环境光照影响
	float ambientStrength = 0.1f;
    vec3 ambient = ambientStrength * lightColor;
	
	//计算漫反射光照影响
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos-FragPos);
	float diff = max(dot(norm,lightDir),0.0);
	vec3 diffLightColor = diff*lightColor;
	
	//计算镜面反射镜像，三个光照影响组成冯氏光照效果
	//镜面强度
	float specularStrength = 1.0f;
	//计算反射坐标
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	//计算镜面亮度分量
	float spec = pow(max(dot(viewDir,reflectDir),0.0),128);
	vec3 specular = specularStrength * spec * lightColor;
	
	Gouraud = ambient + diffLightColor + specular;
	
}