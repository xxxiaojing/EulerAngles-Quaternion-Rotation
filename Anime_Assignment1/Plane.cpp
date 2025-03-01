//#include<GL/glew.h>
//#include <GLFW/glfw3.h>
//#include<string>
//#include <cstdlib>
//
//#include<glm/gtx/vector_angle.hpp>
//#include<glm/gtx/quaternion.hpp>
//#include <glm/gtc/quaternion.hpp>
//#include<glm/gtc/matrix_transform.hpp>
//
//#include"VertexBuffer.h"
//#include"VertexArray.h"
//#include"VertexBufferLayout.h"
//#include"IndexBuffer.h"
//#include"Renderer.h"
//#include"Mesh.h"
//#include"Model.h"
//#include"CubemapTexture.h"
//#include"std_image/stb_image.h"
//
//#include<iostream>
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//void processInput(GLFWwindow *window);
//
//const unsigned int SCR_WIDTH = 1920;
//const unsigned int SCR_HEIGHT = 1080;
//glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 0.0f);
//glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, 1.0f);
//glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//
//glm::vec3 FcameraPos = glm::vec3(0.0f, 15.0f, 0.0f);
//glm::vec3 FcameraFront = glm::vec3(0.0f, 0.0f, 1.0f);
//glm::vec3 FcameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//glm::vec3 FcameraRight = glm::vec3(1.0f, 0.0f, 0.0f);
//
//bool isPpressed = false;
//bool isFmodel=false;
//
//float planePitch=0;
//float planeRoll=0;
//float planeYaw = 0;
//
//
//
//float cameraSpeed = 1.0f;
//float yaw = 90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
//float pitch = 0.0f;
//float Fyaw = 90.0f;	
//float Fpitch = 0.0f;
//float deltaPitch = 0;
//float deltaYaw = 0;
//float deltaRoll = 0;
//
//float lastX = 1920.0f / 2.0;
//float lastY = 1080.0f / 2.0;
//float fov = 60.0f;
//float deltaTime = 0.0f;
//float lastFrame = 0.0f;
//void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//	glViewport(0, 0, width, height);
//}
//void mouse_callback(GLFWwindow* window, double xpos, double ypos)
//{
//	float xoffset;
//	float yoffset;
//	glm::vec3 front;
//
//	if (!isFmodel) {
//		xoffset = xpos - lastX;
//		yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
//		lastX = xpos;
//		lastY = ypos;
//
//		float sensitivity = 0.2f; // change this value to your liking
//		xoffset *= sensitivity;
//		yoffset *= sensitivity;
//
//		yaw += xoffset;
//		pitch += yoffset;
//
//		// make sure that when pitch is out of bounds, screen doesn't get flipped
//		if (pitch > 89.0f)
//			pitch = 89.0f;
//		if (pitch < -89.0f)
//			pitch = -89.0f;
//
//		front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
//		front.y = sin(glm::radians(pitch));
//		front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
//		cameraFront = glm::normalize(front);
//	}
//}
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//	fov -= (float)yoffset;
//	if (fov < 1.0f)
//		fov = 1.0f;
//	if (fov > 45.0f)
//		fov = 45.0f;
//}
//void processInput(GLFWwindow *window) {
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, false);
//	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS && !isPpressed)
//	{
//		isPpressed = true;
//		if (!isFmodel)
//			isFmodel = true;
//		else
//			isFmodel = false;
//	}
//	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_RELEASE)
//		isPpressed = false;
//	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//		cameraPos += cameraSpeed * cameraFront;
//	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//		cameraPos -= cameraSpeed * cameraFront;
//	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//	if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
//		cameraPos += cameraUp * cameraSpeed;
//	if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
//		cameraPos -= cameraUp * cameraSpeed;
//	if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS) {
//		planePitch = -0.05;
//		deltaPitch = -0.05;
//	}	
//	if (glfwGetKey(window, GLFW_KEY_U) == GLFW_RELEASE) {
//		planePitch = 0.0;
//		deltaPitch = 0.0;
//	}
//	if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS) {
//		planePitch = 0.05;
//		deltaPitch = 0.05;
//	}
//	if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS) {
//		planeRoll = 0.05;
//		deltaRoll = 0.05;
//	}
//		
//	if (glfwGetKey(window, GLFW_KEY_H) == GLFW_RELEASE) {
//		planeRoll = 0.0;
//		deltaRoll = 0.0;
//	}
//		
//	if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS) {
//		planeRoll = -0.05;
//		deltaRoll = -0.05;
//	}
//	if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS) {
//		planeYaw = -0.05;
//		deltaYaw = -0.05;
//	}
//		
//	if (glfwGetKey(window, GLFW_KEY_N) == GLFW_RELEASE) {
//		planeYaw = 0.0;
//		deltaYaw = 0.0;
//	}
//		
//	if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS) {
//		planeYaw = 0.05;
//		deltaYaw = 0.05f;
//	}
//		
//
//}
//int main(void)
//{
//	GLFWwindow* window;
//
//	/* Initialize the library */
//	if (!glfwInit())
//		return -1;
//
//	/* Create a windowed mode window and its OpenGL context */
//	window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Hello World", NULL, NULL);
//	if (!window)
//	{
//		glfwTerminate();
//		return -1;
//	}
//
//	/* Make the window's context current */
//	glfwMakeContextCurrent(window);
//	glfwSwapInterval(3);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//	glfwSetScrollCallback(window, scroll_callback);
//	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);//close mouse
//	glEnable(GL_DEPTH_TEST);
//	if (glewInit() != GLEW_OK)
//		std::cout << "error!" << std::endl;
//	float vertices[] = {
//		-0.5f, -0.5f, -0.5f,
//		 0.5f, -0.5f, -0.5f,
//		 0.5f,  0.5f, -0.5f,
//		 0.5f,  0.5f, -0.5f,
//		-0.5f,  0.5f, -0.5f,
//		-0.5f, -0.5f, -0.5f,
//
//		-0.5f, -0.5f,  0.5f,
//		 0.5f, -0.5f,  0.5f,
//		 0.5f,  0.5f,  0.5f,
//		 0.5f,  0.5f,  0.5f,
//		-0.5f,  0.5f,  0.5f,
//		-0.5f, -0.5f,  0.5f,
//
//		-0.5f,  0.5f,  0.5f,
//		-0.5f,  0.5f, -0.5f,
//		-0.5f, -0.5f, -0.5f,
//		-0.5f, -0.5f, -0.5f,
//		-0.5f, -0.5f,  0.5f,
//		-0.5f,  0.5f,  0.5f,
//
//		 0.5f,  0.5f,  0.5f,
//		 0.5f,  0.5f, -0.5f,
//		 0.5f, -0.5f, -0.5f,
//		 0.5f, -0.5f, -0.5f,
//		 0.5f, -0.5f,  0.5f,
//		 0.5f,  0.5f,  0.5f,
//
//		-0.5f, -0.5f, -0.5f,
//		 0.5f, -0.5f, -0.5f,
//		 0.5f, -0.5f,  0.5f,
//		 0.5f, -0.5f,  0.5f,
//		-0.5f, -0.5f,  0.5f,
//		-0.5f, -0.5f, -0.5f,
//
//		-0.5f,  0.5f, -0.5f,
//		 0.5f,  0.5f, -0.5f,
//		 0.5f,  0.5f,  0.5f,
//		 0.5f,  0.5f,  0.5f,
//		-0.5f,  0.5f,  0.5f,
//		-0.5f,  0.5f, -0.5f
//	};
//		GLfloat skyboxVertices[] = {
//		// 位置          
//		-1.0f,  1.0f, -1.0f,
//		-1.0f, -1.0f, -1.0f,
//		1.0f, -1.0f, -1.0f,
//		1.0f, -1.0f, -1.0f,
//		1.0f,  1.0f, -1.0f,
//		-1.0f,  1.0f, -1.0f,
//
//		-1.0f, -1.0f,  1.0f,
//		-1.0f, -1.0f, -1.0f,
//		-1.0f,  1.0f, -1.0f,
//		-1.0f,  1.0f, -1.0f,
//		-1.0f,  1.0f,  1.0f,
//		-1.0f, -1.0f,  1.0f,
//
//		1.0f, -1.0f, -1.0f,
//		1.0f, -1.0f,  1.0f,
//		1.0f,  1.0f,  1.0f,
//		1.0f,  1.0f,  1.0f,
//		1.0f,  1.0f, -1.0f,
//		1.0f, -1.0f, -1.0f,
//
//		-1.0f, -1.0f,  1.0f,
//		-1.0f,  1.0f,  1.0f,
//		1.0f,  1.0f,  1.0f,
//		1.0f,  1.0f,  1.0f,
//		1.0f, -1.0f,  1.0f,
//		-1.0f, -1.0f,  1.0f,
//
//		-1.0f,  1.0f, -1.0f,
//		1.0f,  1.0f, -1.0f,
//		1.0f,  1.0f,  1.0f,
//		1.0f,  1.0f,  1.0f,
//		-1.0f,  1.0f,  1.0f,
//		-1.0f,  1.0f, -1.0f,
//
//		-1.0f, -1.0f, -1.0f,
//		-1.0f, -1.0f,  1.0f,
//		1.0f, -1.0f, -1.0f,
//		1.0f, -1.0f, -1.0f,
//		-1.0f, -1.0f,  1.0f,
//		1.0f, -1.0f,  1.0f
//	};
//	std::vector<std::string> faces
//	{
//		"src/Model/Skybox/right.png",
//		"src/Model/Skybox/left.png",
//		"src/Model/Skybox/top.png",
//		"src/Model/Skybox/bottom.png",
//		"src/Model/Skybox/front.png",
//		"src/Model/Skybox/back.png"
//	};
//	//	//skybox
//	VertexArray va;
//	CubemapTexture skybox(faces);
//	Shader SkyboxShader("src/Shader/skybox.shader");
//	VertexBuffer skyboxVertex(skyboxVertices, 18 * 6);
//	VertexBufferLayout skyboxLayout;
//	skyboxLayout.Push<float>(3);
//	va.AddBuffer(skyboxVertex, skyboxLayout);
//	glm::mat4 skyboxModel = glm::mat4(1.0f);
//	skyboxModel = glm::scale(skyboxModel, glm::vec3(300.0f));
//
//	Shader CookTorranceShader("src/Shader/cook-torrance.shader");
//	CookTorranceShader.SetUniformVec3("lightPos", glm::vec3(4.0f, 4.0f, 2.0f));
//	CookTorranceShader.SetUniformVec3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f));
//	CookTorranceShader.SetUniformVec3("objectColor", glm::vec3(0.8f, 0.2f, 0.3f));
//
//	Model heliBody("src/Model/heli/body.obj");
//	Model heliPropellar("src/Model/heli/propellar.obj");
//	Model heliBackrotor("src/Model/heli/backrotor.obj");
//	Renderer renderer;
//
//	if (glewInit() != GLEW_OK)
//		std::cout << "error" << std::endl;
//	/* Loop until the user closes the window */
//	glm::mat4 planebody = glm::mat4(1.0f);
//	planebody = glm::translate(planebody, glm::vec3(0.0, 0.0, 0.0f));
//	glm::mat4 Quat = glm::mat4(1.0f);
//	glm::mat4 propellar = glm::mat4(1.0f);
//	propellar = glm::translate(propellar, glm::vec3(0.0, 8.0, 45.0f));
//	glm::mat4 backrotor = glm::mat4(1.0f);
//	backrotor = glm::translate(backrotor, glm::vec3(4.9, 5.3, -66.5f));
//	glm::vec3 Ffront;
//	glm::mat4 view;
//
//	while (!glfwWindowShouldClose(window))
//	{
//		/* Render here */
//		glfwSetCursorPosCallback(window, mouse_callback);
//		processInput(window);
//
//		renderer.Clear();
//
//		glm::mat4 projection = glm::perspective(glm::radians(fov), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 1000.0f);
//		//glm::vec3 axis = glm::cross(FcameraFront, FcameraUp);
//		//glm::quat pitch_quat = glm::angleAxis(Fpitch, axis);
//		//glm::quat heading_quat = glm::angleAxis(Fyaw, FcameraUp);
//		//glm::quat temp = glm::cross(pitch_quat, heading_quat);
//		//temp = glm::normalize(temp);
//		//FcameraFront = glm::rotate(temp, FcameraFront);
//		
//		CookTorranceShader.Bind();
//		
//		Fyaw += deltaYaw;
//		Fpitch += deltaPitch;
//
//		if (Fpitch > 89.0f)
//			Fpitch = 89.0f;
//		if (Fpitch < -89.0f)
//			Fpitch = -89.0f;
//
//		//Ffront.x = cos(glm::radians(Fyaw)) * cos(glm::radians(Fpitch));
//		//Ffront.y = sin(glm::radians(Fpitch));
//		//Ffront.z = sin(glm::radians(Fyaw)) * cos(glm::radians(Fpitch));
//		//FcameraFront = glm::normalize(Ffront);
//
//		//glm::quat yaw_quat = glm::angleAxis(deltaYaw, FcameraUp);
//		////yaw_quat = yaw_quat * FcameraPos;
//		//FcameraFront = glm::normalize(glm::rotate(yaw_quat, FcameraFront));
//		//FcameraRight = glm::normalize(glm::rotate(yaw_quat, FcameraRight));
//
//		//glm::quat pitch_quat = glm::angleAxis(deltaPitch, FcameraRight);
//		////pitch_quat = pitch_quat * FcameraPos;
//		//FcameraFront = glm::normalize(glm::rotate(pitch_quat, FcameraFront));
//		//FcameraUp = glm::normalize(glm::rotate(pitch_quat, FcameraUp));
//
//		//glm::quat rolling_quat = glm::angleAxis(deltaRoll, FcameraFront);
//		//FcameraUp = glm::normalize(glm::rotate(rolling_quat, FcameraUp));
//		//FcameraRight = glm::normalize(glm::rotate(rolling_quat, FcameraRight));
//
//		
//
//		std::cout << FcameraFront.x<< ","<< FcameraFront.y<< "," << FcameraFront.z << std::endl;
//		
//		CookTorranceShader.SetUniformf("roughness", 0.3);
//		CookTorranceShader.SetUniformMat4f("projection", projection);
//		
//		
//
//		glm::quat Quaternion;
//		glm::mat4 RotationMatrix;
//
//		//glm::vec3 EulerAngles(planePitch, planeYaw, planeRoll);
//		float w, x, y, z;
//		x = sin(planeYaw / 2)*sin(planeRoll / 2)*cos(planePitch / 2) + cos(planeYaw / 2)*cos(planeRoll / 2)*sin(planePitch / 2);
//		y = sin(planeYaw / 2)*cos(planeRoll / 2)*cos(planePitch / 2) + cos(planeYaw / 2)*sin(planeRoll / 2)*sin(planePitch / 2);
//		z = cos(planeYaw / 2)*sin(planeRoll / 2)*cos(planePitch / 2) - sin(planeYaw / 2)*cos(planeRoll / 2)*sin(planePitch / 2);
//		w = cos(planeYaw / 2)*cos(planeRoll / 2)*cos(planePitch / 2) - sin(planeYaw / 2)*sin(planeRoll / 2)*sin(planePitch / 2);
//		Quaternion = glm::quat(w,x,y,z);
//		//Quaternion = glm::quat(EulerAngles);
//		RotationMatrix = glm::toMat4(Quaternion);
//		FcameraFront = FcameraFront * glm::mat3(RotationMatrix);
//		FcameraUp = FcameraUp * glm::mat3(RotationMatrix);
//		FcameraPos = FcameraPos * glm::mat3(RotationMatrix);
//
//		planebody =  planebody* RotationMatrix;
//
//		
//		
//		if (!isFmodel) {
//			view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
//			CookTorranceShader.SetUniformVec3("viewPos", cameraPos);
//			CookTorranceShader.SetUniformMat4f("view", view);
//		}
//		else {
//			view = glm::lookAt(FcameraPos, FcameraPos + FcameraFront, FcameraUp);
//			CookTorranceShader.SetUniformMat4f("view", view);
//			CookTorranceShader.SetUniformVec3("viewPos", FcameraPos);
//		}
//		/*计算出绕xyz旋转的欧拉角，转化为四元数，再转为旋转矩阵，传给shader计算。每一次用户输入，都会重新计算绕zyx三个轴旋转的角度，然后生成新的四元数，再生成新的旋转矩阵。这样做在使用欧拉角的时候没有什么问题（反正会出现Gimbal lock），但是使用四元数的时候还这样做，就无法避免Gimbal lock樂。因为这样做，用户输入了绕多个轴的旋转，生成的欧拉角自然是绕多个轴的。参考上一篇博文所述，多次旋转叠加没有考虑坐标系的变化，Gimbal lock还是会产生了。
//		解决办法是分别计算用户每一次输入的旋转变换矩阵，将每一次的单独的旋转变换矩阵点乘原来的旋转变换矩阵，得到最新的变换矩阵。后续的每一次变换都在这个矩阵的基础上不断的乘，也就是说每一次都是在原来的基础上再加一点点变化，这样就完美解决了GImbal lock 。
//		需要说明的是，用四元数生成多个旋转矩阵，进行相乘，其计算的顺序不会对结果有影响，这是四元数和欧拉角之间的显著区别。也是四元数可以解决问题的关键。*/
//		/*planebody = glm::rotate(planebody, glm::radians(planePitch), glm::vec3(1.0, 0.0, 0.0));
//		planebody = glm::rotate(planebody, glm::radians(planeYaw), glm::vec3(0.0, 1.0, 0.0));
//		planebody = glm::rotate(planebody, glm::radians(planeRoll), glm::vec3(0.0, 0.0, 1.0));*/
//		
//		CookTorranceShader.SetUniformMat4f("model", planebody);
//		heliBody.Draw(CookTorranceShader);
//		
//		propellar = planebody;
//		propellar = glm::translate(propellar, glm::vec3(0.0, 8.0, 45.0f));
//		propellar = glm::rotate(propellar, 20*(float)glfwGetTime(), glm::vec3(0.0, 1.0, 0.0));
//		CookTorranceShader.SetUniformMat4f("model", propellar);
//		//planeModel.Draw(CookTorranceShader);
//		heliPropellar.Draw(CookTorranceShader);
//
//
//
//		backrotor = planebody;
//		backrotor = glm::translate(backrotor, glm::vec3(4.9, 5.3, -66.5f));
//		backrotor = glm::rotate(backrotor, 20 * (float)glfwGetTime(), glm::vec3(1.0, 0.0, 0.0));
//		CookTorranceShader.SetUniformMat4f("model", backrotor);
//		heliBackrotor.Draw(CookTorranceShader);
//
//
//		//skybox
//		glDepthFunc(GL_LEQUAL);
//		SkyboxShader.Bind();
//		va.Bind();
//		skybox.Bind();
//		glm::mat4 skyboxView = glm::mat4(glm::mat3(view));
//		SkyboxShader.SetUniformMat4f("model", skyboxModel);
//		SkyboxShader.SetUniformMat4f("view", skyboxView);
//		SkyboxShader.SetUniformMat4f("projection", projection);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//		glDepthFunc(GL_LESS);
//
//		/* Swap front and back buffers */
//		glfwSwapBuffers(window);
//
//		/* Poll for and process events */
//		glfwPollEvents();
//	}
//
//	glfwTerminate();
//	return 0;
//}