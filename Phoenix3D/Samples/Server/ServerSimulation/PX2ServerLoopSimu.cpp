// PX2ServerLoopSimu.cpp

#include "PX2ServerLoopSimu.hpp"
#include "PX2ServerUserManager.hpp"
using namespace PX2Server;
using namespace PX2;

//----------------------------------------------------------------------------
ServerLoopSimu::ServerLoopSimu()
{
}
//----------------------------------------------------------------------------
ServerLoopSimu::~ServerLoopSimu()
{
}
//----------------------------------------------------------------------------
bool ServerLoopSimu::Initlize()
{
	ServerLoop::Initlize();

	UserManager userMan(5000);

	return true;
}
//----------------------------------------------------------------------------
bool ServerLoopSimu::Ternamate()
{
	ServerLoop::Ternamate();

	return true;
}
//----------------------------------------------------------------------------
void ServerLoopSimu::Run()
{
}
//----------------------------------------------------------------------------