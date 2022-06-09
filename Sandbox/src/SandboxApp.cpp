#include <TamikaEngine.h>

class Sandbox : public TamikaEngine::Application
{
public:
	Sandbox()
	{
	
	}

	~Sandbox()
	{
	
	}
};

TamikaEngine::Application* TamikaEngine::CreateApplication()
{
	return new Sandbox();
}