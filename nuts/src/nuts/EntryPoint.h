#pragma once
#ifdef NT_PLATFORM_WINDOWS

extern	 nuts::Application* nuts::CreateApplication();

int main(int argc,char ** argv)
{	

	nuts::Log::Init();
	NT_CORE_WARN("Inintialized Log!");
	int a = 5;
	NT_INFO("Hello var={0}", a);
	
	auto app = nuts::CreateApplication();
	app->Run();
	delete app;
}
#endif
