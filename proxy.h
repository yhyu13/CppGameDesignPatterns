#pragma once

#include <iostream>
#include <string>

namespace proxy
{
	class IGamePlayer
	{
	public:
		IGamePlayer() {};
		virtual ~IGamePlayer() {};
		virtual void login() = 0;
		virtual void killBoss() = 0;
		virtual void levelUp() = 0;
	};

	class GamePlayer :public IGamePlayer
	{
	private:
		std::string m_name;
	public:
		explicit GamePlayer(std::string name) : m_name(name) {};

		virtual void login() override
		{
			std::cout << m_name << " has logged in!" << std::endl;
		}

		virtual void killBoss() override
		{
			std::cout << m_name << " has killed the boss!" << std::endl;
		}

		virtual void levelUp() override
		{
			std::cout << m_name << " has leveled up!" << std::endl;
		}
	};

	class GamePlayProxy : public IGamePlayer
	{
	private:
		IGamePlayer* pGamePlayer;
	public:
		explicit GamePlayProxy(IGamePlayer* gamePlayer) : pGamePlayer(gamePlayer) {};

		IGamePlayer* getGamePlayer()
		{
			return pGamePlayer;
		}

		virtual void login() override
		{
			std::cout <<"GamePlayProxy send login()!" << std::endl;
			pGamePlayer->login();
		}

		virtual void killBoss() override
		{
			std::cout << "GamePlayProxy send killBoss()!" << std::endl;
			pGamePlayer->killBoss();
		}

		virtual void levelUp() override
		{
			std::cout << "GamePlayProxy send levelUp()!" << std::endl;
			pGamePlayer->levelUp();
		}
	};
}