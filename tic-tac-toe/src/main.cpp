#include "rl_opt.h"

using namespace rl_opt;

int main()
{
	RL_OPT_CORE_TRACE("Testing the core trace macro");
	RL_OPT_CORE_ERROR("Testing the core error macro");

	RL_OPT_CLIENT_INFO("Testing the client info macro");
	RL_OPT_CLIENT_CRITICAL("Testing the client critical macro");
	return 0;
}