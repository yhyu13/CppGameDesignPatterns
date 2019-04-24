#pragma once

#include <iostream>
#include <string>

namespace prototype
{
	class IClone
	{
	public:
		IClone() {};
		virtual ~IClone() {};
		virtual IClone* Clone() = 0;
	};

	class Player : public IClone
	{
	private:
		std::string m_name;
		int m_id;
	public:
		Player() :m_name("Test"), m_id(1) {};
		virtual IClone* Clone() override
		{
			Player* p = new Player();
			p->SetName(m_name);
			return p;
		}

		void SetName(std::string name)
		{
			m_name = name;
		}

		std::string GetName()
		{
			return m_name;
		}

		void SetId(int id)
		{
			m_id = id;
		}

		int GetId()
		{
			return m_id;
		}
	};
}