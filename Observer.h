#pragma once

#include <iostream>
#include <list>

namespace observer {

	class Observer;
	class Subject;

	class Observer
	{
	public:
		~Observer() {};
		virtual void Update() = 0;
	};

	class Buff : public Observer
	{

	private:
		Subject* m_host;
		int m_id;

	public:
		Buff(Subject* host, int id) : m_host(host), m_id(id)
		{

		}

		virtual void Update()
		{
			std::cout << m_id << " Buff Update" << std::endl;
		}
	};

	class Subject
	{
	private:
		std::list<Observer*> observerList;

	public:
		~Subject() {};

		void Attach(Observer* observer)
		{
			if (observer != nullptr) observerList.push_back(observer);
		}

		void Detach(Observer * observer)
		{
			if (observer != nullptr) observerList.remove(observer);
		}

		void Notify()
		{
			for (auto& iter : observerList)
			{
				iter->Update();
			}
		}
	};
}