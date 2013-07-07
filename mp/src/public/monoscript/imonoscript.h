//============== Copyright Source Mono, All rights reserved. ================//
//
// Purpose: 
//
// $NoKeywords: $
//
//===========================================================================//

#ifndef IMONOSCRIPT_H
#define IMONOSCRIPT_H

#ifdef _WIN32
#pragma once
#endif

#include "tier1/interface.h"

#define TOKENPASTE(x, y) x ## y
#define TOKENPASTE2(x, y) TOKENPASTE(x, y)
#define MONOFUNC(x) TOKENPASTE2(DLLNAME,_##x)

// Keep these enums synced with those found on the managed side
enum EMonoScriptDomain
{
	SCRIPTDOMAIN_NONE = 0,
	SCRIPTDOMAIN_SERVER = 1,
	SCRIPTDOMAIN_CLIENT = 2,
	SCRIPTDOMAIN_MENU = 4,
};

enum EMonoScriptMsgID
{
	SCRIPTMSGID_INVALID = 0,
	SCRIPTMSGID_INITIALIZE = 1,
};

abstract_class IMonoScript
{
public:
	virtual void		Initialize() = 0;
	virtual void		SendMessage( EMonoScriptDomain target, EMonoScriptMsgID msgid, void* buffer, int length ) = 0;
};

#define MONOSCRIPT_INTERFACE_VERSION "MonoScript001"

#endif // IMONOSCRIPT_H