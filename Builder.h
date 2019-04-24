#pragma once

#include <iostream>
namespace builder {

	class Log
	{

	private:
		int m_color;
		int m_size;
		bool m_isWriteFile;

	public:
		Log() : m_color(0), m_size(0), m_isWriteFile(false) {};

		void SetSize(int Size)
		{
			m_size = Size;
		}

		void SetColor(int Color)
		{
			m_color = Color;
		}

		void WriteFile(bool writeFile)
		{
			m_isWriteFile = writeFile;
		}

		void PrintInfo()
		{
			std::cout << "m_color: " << m_color << std::endl << "m_size: " << m_size << std::endl << "m_isWriteFile" << m_isWriteFile << std::endl;
			std::cout << "------------------------------------------" << std::endl;

		}
	};

	/*
		Interface Log Builder
	*/
	class ILogBuilder
	{
	public:
		ILogBuilder() {};
		virtual ~ILogBuilder() {};
		virtual void SetColor() = 0;
		virtual void SetSize() = 0;
		virtual void WriteFile() = 0;
	};

	class DLogBuilder : public ILogBuilder
	{
	private:
		std::auto_ptr<Log> m_product;
	public:
		DLogBuilder() : m_product(new Log()) {};
		void SetSize() { m_product->SetSize(1); };
		void SetColor() { m_product->SetColor(1); };
		void WriteFile() { m_product->WriteFile(true); };
		Log* GetLog() { return m_product.get(); };
	};


	class ELogBuilder : public ILogBuilder
	{
	private:
		std::auto_ptr<Log> m_product;
	public:
		ELogBuilder() : m_product(new Log()) {};
		void SetSize() { m_product->SetSize(2); };
		void SetColor() { m_product->SetColor(2); };
		void WriteFile() { m_product->WriteFile(true); };
		Log* GetLog() { return m_product.get(); };
	};

	class WDirector
	{
	public:
		WDirector() {};
		void Construct(ILogBuilder* builder)
		{
			builder->SetColor();
			builder->SetSize();
			builder->WriteFile();
		}
	};

	class LDirector
	{
	public:
		LDirector() {};
		void Construct(ILogBuilder* builder)
		{
			builder->SetSize();
			builder->WriteFile();
		}
	};
}