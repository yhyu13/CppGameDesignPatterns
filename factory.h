#pragma once

#include <iostream>

namespace factory
{
	class IGuildEventMsg
	{
	public:
		IGuildEventMsg() {};
		virtual ~IGuildEventMsg() {};
		virtual void PrintMsg()=0;
	};

	class GuildCreatGuildMsg :public IGuildEventMsg
	{
		virtual void PrintMsg() override
		{
			std::cout << "Great Guild!" << std::endl;
		}
	};
	
	class GuildAddGuildMsg :public IGuildEventMsg
	{
		virtual void PrintMsg() override
		{
			std::cout << "Add Guild!" << std::endl;
		}
	};

	class GuildQuitGuildMsg :public IGuildEventMsg
	{
		virtual void PrintMsg() override
		{
			std::cout << "Quit Guild!" << std::endl;
		}
	};

	class IGuildEventFactory
	{
	public:
		IGuildEventFactory() {};
		virtual ~IGuildEventFactory() {};
		virtual IGuildEventMsg* CreateFactory()=0;
	};

	class GuildGreatEventFactory :public IGuildEventFactory
	{
	public:
		IGuildEventMsg* CreateFactory()
		{
			return new GuildCreatGuildMsg();
		}
	};

	class GuildAddEventFactory :public IGuildEventFactory
	{
	public:
		IGuildEventMsg* CreateFactory()
		{
			return new GuildAddGuildMsg();
		}
	};

	class GuildQuitEventFactory :public IGuildEventFactory
	{
	public:
		IGuildEventMsg* CreateFactory()
		{
			return new GuildQuitGuildMsg();
		}
	};
}