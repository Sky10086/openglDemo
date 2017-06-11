/**********************************************************
// Method: 
// Description: 模型加载类，一个模型包含多个mesh
// Author: 王炳琦 
// Date: 2016/12/11 18:45
// Returns: 
// Parameter: 
// History:
// G:\VisualStudio2013Projects\openglDemo1\openglDemo1\Model.h
**********************************************************/

#ifndef MODEL_H
#define MODEL_H
#include "Mesh.h"



class Model
{
public:
	Model(const char* path, bool isAbsolutePath);
	~Model();
	void Draw(Shader program);
private:
	vector<Mesh> meshes;
	string directory;
	vector<Texture> textures_loaded;	// Stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
	bool isAbsolutePath;//记录是否是绝对路径
	void loadModel(string path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh,const aiScene* scene);
	vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type,string typeName);
	GLint TextureFromFile(const char* fileName, string dir);

};

Model::Model(const char* path,bool isAbsolutePath)
{
	this->isAbsolutePath = isAbsolutePath;
	this->loadModel(path);
}

Model::~Model()
{
}

void Model::Draw(Shader program)
{
	for (GLuint i = 0; i < this->meshes.size(); i++)
		this->meshes[i].Draw(program);
}

void Model::loadModel(string path)
{
	Assimp::Importer import;
	const aiScene* scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
	if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode )
	{
		cout << "ERROR::ASSIMP::" << import.GetErrorString() << endl;
		return;
	}
	this->directory = path.substr(0, path.find_last_of('/'));
	this->processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode* node, const aiScene* scene)
{
	// 添加当前节点中的所有Mesh
	for (GLuint i = 0; i < node->mNumMeshes; i++)
	{
		this->meshes.push_back(this->processMesh(scene->mMeshes[node->mMeshes[i]], scene));
	}
	// 递归处理该节点的子孙节点
	for (GLuint i = 0; i < node->mNumChildren;i++)
	{
		this->processNode(node->mChildren[i], scene);
	}
}

Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene)
{
	vector<Vertex> vertices;
	vector<GLuint> indices;
	vector<Texture> textures;
	for (GLuint i = 0; i < mesh->mNumVertices;i++)
	{
		Vertex vertex;
		glm::vec3 tempVec3;
		tempVec3.x = mesh->mVertices[i].x;
		tempVec3.y = mesh->mVertices[i].y;
		tempVec3.z = mesh->mVertices[i].z;
		vertex.Position = tempVec3;
		
		tempVec3.x = mesh->mNormals[i].x;
		tempVec3.y = mesh->mNormals[i].y;
		tempVec3.z = mesh->mNormals[i].z;
		vertex.Normal = tempVec3;

		if (mesh->mTextureCoords[0])
		{
			glm::vec2 tempVec2;
			tempVec2.x = mesh->mTextureCoords[0][i].x;
			tempVec2.y = mesh->mTextureCoords[0][i].y;
			vertex.TexCoords = tempVec2;
		}
		else
		{
			vertex.TexCoords = glm::vec2(0.0f, 0.0f);
		}
		vertices.push_back(vertex);
	}

	for (GLuint i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		for (GLuint j = 0; j < face.mNumIndices;j++)
		{
			indices.push_back(face.mIndices[j]);
		}
	}

	if (mesh->mMaterialIndex >= 0)
	{
		aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
            // 1. Diffuse maps
            vector<Texture> diffuseMaps = this->loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
            textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
            // 2. Specular maps
            vector<Texture> specularMaps = this->loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
            textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
            // 3. Reflection maps (Note that ASSIMP doesn't load reflection maps properly from wavefront objects, so we'll cheat a little by defining the reflection maps as ambient maps in the .obj file, which ASSIMP is able to load)
            vector<Texture> reflectionMaps = this->loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_reflection");
            textures.insert(textures.end(), reflectionMaps.begin(), reflectionMaps.end());
	}
	return Mesh(vertices, indices, textures);
}


GLint Model::TextureFromFile(const char* fileName, string dir)
{
	//Generate texture ID and load texture data 
	string filename = string(fileName);
	if (!this->isAbsolutePath)
	filename = dir + '/' + filename;
	GLuint textureID;
	glGenTextures(1, &textureID);
	int width, height;
	unsigned char* image = SOIL_load_image(filename.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
	// Assign texture to ID
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);

	// Parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	SOIL_free_image_data(image);
	return textureID;
}

vector<Texture> Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName)
{
	vector<Texture> textures;
	for (GLuint i = 0; i < mat->GetTextureCount(type);i++)
	{
		aiString str;
		mat->GetTexture(type, i, &str);

		// Check if texture was loaded before and if so, continue to next iteration: skip loading a new texture
		GLboolean skip = false;
		for (GLuint j = 0; j < textures_loaded.size(); j++)
		{
			if (textures_loaded[j].path == str)
			{
				textures.push_back(textures_loaded[j]);
				skip = true; // A texture with the same filepath has already been loaded, continue to next one. (optimization)
				break;
			}
		}

		if (!skip)
		{
			Texture texture;
			texture.id = this->TextureFromFile(str.C_Str(), this->directory);
			texture.type = typeName;
			texture.path = str;
			textures.push_back(texture);
			// Store it as texture loaded for entire model, to ensure we won't unnecesery load duplicate textures.
			textures_loaded.push_back(texture);
		}
		
	}
	return textures;
}
#endif