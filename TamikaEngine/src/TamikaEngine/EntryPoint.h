#pragma once

#ifdef TE_PLATFORM_WINDOWS

extern TamikaEngine::Application* TamikaEngine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = TamikaEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif
