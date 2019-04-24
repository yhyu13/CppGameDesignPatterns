#pragma once

#include <iostream>
#include <string>

namespace decorator
{
	class Person
	{
	protected:
		std::string m_name;
	public:
		Person():m_name("Empty") {};
		explicit Person(std::string name) : m_name(name) {};
		std::string getName() { return m_name; };
		virtual void Show() 
		{
			std::cout << m_name << " is showed!" << std::endl;
			std::cout << "=====================" << std::endl;
		};
	};

	class Finery : public Person
	{
	protected:
		Person* pPerson;
	public:
		//explicit Finery(Person* person) :pPerson(person) {};
		
		void Decorate(Person* person)
		{
			pPerson = person;
		}
		
		virtual void Show() override
		{
			if (pPerson != nullptr)
			{
				std::cout << "Decorate " << pPerson->getName() << std::endl;
				pPerson->Show();
			}
		}
	};

	class Tee : public Finery
	{
	public:
		Tee() { m_name = "Tee"; };
		virtual void Show() override
		{
			if (pPerson != this)
			{
				std::cout << "Add Tee" << std::endl;
				Finery::Show();
			}
		}
	};
	
	class Trouser : public Finery
	{
	public:
		Trouser() { m_name = "Trouser"; };
		virtual void Show() override
		{
			if (pPerson != this)
			{
				std::cout << "Add Trouser" << std::endl;
				Finery::Show();
			}
		}
	};

	class Sneakers : public Finery
	{
	public:
		Sneakers() { m_name = "Sneakers"; };
		virtual void Show() override
		{
			if (pPerson != this)
			{
				std::cout << "Add Sneakers" << std::endl;
				Finery::Show();
			}
		}
	};

}