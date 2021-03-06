#pragma once
#include "prefab.h"
#include "entity.h"

//forward declarations
class Camera;
namespace GTR {

	class Prefab;
	class Material;
	
	// This class is in charge of rendering anything in our system.
	// Separating the render from anything else makes the code cleaner
	class Renderer
	{

	public:

		//to render the scene to viewport
		void renderSceneToScreen(GTR::Scene* scene, Camera* camera, Vector4 bg_color);

		//to render the scene to texture (shadowmap)
		std::vector<GTR::Light*> renderSceneShadowmaps(GTR::Scene* scene);
		
		void renderPointShadowmap(Light* light);

		void showSceneShadowmaps(std::vector<Light*> shadow_caster_lights);

		void setDefaultGLFlags();

		//to render a scene
		void renderScene(GTR::Scene* scene, Camera* camera);
	
		//to render a whole prefab (with all its nodes)
		void renderPrefab(const Matrix44& model, GTR::Prefab* prefab, Camera* camera);

		//to render one node from the prefab and its children
		void renderNode(const Matrix44& model, GTR::Node* node, Camera* camera);

		//manages blendign
		void manageBlendingAndCulling(GTR::Material* material, bool rendering_light, bool is_first_pass = true);

		//render shadowmap
		bool Renderer::renderShadowMap(Shader* &shader, Material* material, Camera* camera, Matrix44 model, Mesh* mesh);

		//to render one mesh given its material and transformation matrix
		void renderMeshWithMaterial(const Matrix44 model, Mesh* mesh, GTR::Material* material, Camera* camera);
	};

};