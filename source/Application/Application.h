#pragma once

class Application
{
public:
	Application();
	virtual ~Application();
	Application(Application& application) = delete;
	void operator=(Application& application) = delete;

	void Run();

protected:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Terminate() = 0;

protected:
	struct GLFWwindow* m_Window = nullptr;

private:
	void InitializeGLFW();
	void TerminateGLFW();
	void InitializeImGUI();
	void TerminateImGUI();
};