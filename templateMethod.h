#pragma once

#include <iostream>

namespace templateMethod
{
	class Object
	{
	private:
		bool m_dead : 1;

	public:
		Object() :m_dead(false) {};

		virtual void BeforeDead() = 0;
		virtual void OnDead() = 0;
		virtual void AfterDead() = 0;
		
		bool isDead()
		{
			return m_dead;
		}

		void SetDead()
		{
			m_dead = true;
			std::cout << "==========" << std::endl;
			BeforeDead();
			OnDead();
			AfterDead();
			std::cout << "==========" << std::endl;
		}
	};

	class Player : public Object
	{
	public:
		virtual void BeforeDead() override
		{
			std::cout << "Player BeforeDead() Implemented" << std::endl;
		}

		virtual void AfterDead() override
		{
			std::cout << "Player AfterDead() Implemented" << std::endl;
		}

		virtual void OnDead() override
		{
			std::cout << "Player OnDead() Implemented" << std::endl;
		}
	};


	class NPC : public Object
	{
	public:
		virtual void BeforeDead() override
		{
			std::cout << "NPC BeforeDead() Implemented" << std::endl;
		}

		virtual void AfterDead() override
		{
			std::cout << "NPC AfterDead() Implemented" << std::endl;
		}

		virtual void OnDead() override
		{
			std::cout << "NPC OnDead() Implemented" << std::endl;
		}
	};
}