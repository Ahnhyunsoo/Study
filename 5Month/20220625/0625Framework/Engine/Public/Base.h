#pragma once
namespace Engine
{
	class CBase
	{
	public:
		CBase() { dwRefCnt = 0; };
		virtual ~CBase() = default;

	public:
		unsigned int AddRef();
		unsigned int Release();

	private:
		unsigned long dwRefCnt;
	};

}