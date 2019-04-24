// GameDesignPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Observer.h"
#include "builder.h"
#include "Facade.h"
#include "templateMethod.h"
#include "prototype.h"
#include "factory.h"
#include "proxy.h"
#include "decorator.h"

#include <iostream>
#include <string>
#include <sstream>


int main()
{
    std::cout << "Hello World!\n";

	/* Observer */
	std::auto_ptr<observer::Subject> subject(new observer::Subject());
	std::auto_ptr<observer::Buff> buff_1(new observer::Buff(subject.get(), 1));
	std::auto_ptr<observer::Buff> buff_2(new observer::Buff(subject.get(), 2));
	subject->Attach(buff_1.get());
	subject->Attach(buff_2.get());
	subject->Notify();
	subject->Detach(buff_1.get());
	subject->Notify();
	subject->Detach(buff_2.get());
	subject->Notify();

	/* Builder */
	std::cout << "----------WINDOWS----------" << std::endl;
	std::auto_ptr<builder::WDirector> wDirector(new builder::WDirector());
	std::auto_ptr<builder::LDirector> lDirector(new builder::LDirector());
	std::auto_ptr<builder::DLogBuilder> dBuilder(new builder::DLogBuilder());
	std::auto_ptr<builder::ELogBuilder> eBuilder(new builder::ELogBuilder());

	wDirector->Construct(dBuilder.get());
	wDirector->Construct(eBuilder.get());

	dBuilder->GetLog()->PrintInfo();
	eBuilder->GetLog()->PrintInfo();

	std::cout << "----------LINUX----------" << std::endl;
	dBuilder.reset(new builder::DLogBuilder());
	eBuilder.reset(new builder::ELogBuilder());

	lDirector->Construct(dBuilder.get());
	lDirector->Construct(eBuilder.get());

	dBuilder->GetLog()->PrintInfo();
	eBuilder->GetLog()->PrintInfo();

	/* facade */
	std::auto_ptr<facade::Player> player(new facade::Player());
	player->Superman();

	/* Template Method */
	std::auto_ptr<templateMethod::Player> player1(new templateMethod::Player());
	std::auto_ptr<templateMethod::NPC> npc(new templateMethod::NPC());
	player1->SetDead();
	std::cout << "Player is " << ((player1->isDead()) ? "Dead" : "Alive") << std::endl;
	npc->SetDead();
	std::cout << "NPC is " << ((npc->isDead()) ? "Dead" : "Alive") << std::endl;

	/* Prototype */
	std::auto_ptr<prototype::Player> player2(new prototype::Player());
	player2->SetName("Player2");
	player2->SetId(1);
	std::auto_ptr<prototype::Player> player3((prototype::Player*)player2->Clone());
	player3->SetName("Player3");
	std::cout << player2->GetName() << std::endl;
	std::cout << player2->GetId() << std::endl;
	std::cout << player3->GetName() << std::endl;
	std::cout << player3->GetId() << std::endl;

	/* Factory */
	std::auto_ptr<factory::GuildGreatEventFactory> greatFactory(new factory::GuildGreatEventFactory());
	factory::IGuildEventMsg* greatMsg = greatFactory->CreateFactory();
	greatMsg->PrintMsg();

	std::auto_ptr<factory::GuildAddEventFactory> addFactory(new factory::GuildAddEventFactory());
	factory::IGuildEventMsg* addtMsg = addFactory->CreateFactory();
	addtMsg->PrintMsg();

	std::auto_ptr<factory::GuildQuitEventFactory> quitFactory(new factory::GuildQuitEventFactory());
	factory::IGuildEventMsg* quitMsg = quitFactory->CreateFactory();
	quitMsg->PrintMsg();

	/* Proxy */
	std::auto_ptr<proxy::GamePlayer> gamePlayer(new proxy::GamePlayer("Yohan"));
	std::auto_ptr<proxy::GamePlayProxy> gamePlayerProxy(new proxy::GamePlayProxy((proxy::IGamePlayer*)(gamePlayer.get())));

	gamePlayerProxy->login();
	gamePlayerProxy->killBoss();
	gamePlayerProxy->levelUp();

	/* Decorator */
	std::auto_ptr<decorator::Person> person(new decorator::Person("Yohan"));
	std::auto_ptr<decorator::Tee> tee(new decorator::Tee());
	std::auto_ptr<decorator::Trouser> trouser(new decorator::Trouser());
	std::auto_ptr<decorator::Sneakers> sneaker(new decorator::Sneakers());
	
	//First way of decoration
	
	tee->Decorate(person.get());
	trouser->Decorate(tee.get());
	sneaker->Decorate(trouser.get());
	sneaker->Show();
	
	sneaker->Decorate(person.get());
	trouser->Decorate(sneaker.get());
	tee->Decorate(trouser.get());
	tee->Show();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
