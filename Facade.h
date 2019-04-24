#pragma once

#include <iostream>

namespace facade {

	class Skill
	{
	public:
		Skill() {};
		void EquipSkill()
		{
			std::cout << "EquipSkill" << std::endl;
		}
	};

	class Level
	{
	public:
		Level() {};
		void GetMaxLevel()
		{
			std::cout << "MaxLevel is 100." << std::endl;
		}
	};

	class Equip
	{
	public:
		Equip() {};
		void GetBestEquip()
		{
			std::cout << "Top Equip" << std::endl;
		}
	};

	class Player
	{
	private:
		Skill* pSkill;
		Level* pLevel;
		Equip* pEquip;

	public:
		Player() : pSkill(new Skill()), pLevel(new Level()), pEquip(new Equip())
		{

		}
		void Superman()
		{
			pSkill->EquipSkill();
			pLevel->GetMaxLevel();
			pEquip->GetBestEquip();
		}
	};
}