/*
	Description: 	Do not edit this file manually
	Author:			SDL Compiler
*/

#ifndef SDL_TESTSVR_BASE_H
#define SDL_TESTSVR_BASE_H

#ifndef VENUS_IO_H
#include <venus/Io.h>
#endif

#pragma pack(1)

namespace testsvr {

enum { code_ok = cerl::code_ok };
enum { code_error = cerl::code_error };
enum { code_true = cerl::code_true };
enum { code_false = cerl::code_false };

typedef cerl::Array<cerl::Char, 100> MsgData;

class TestSvrBase
{
public:
	enum { code_test = 1 };

#if defined(VENUS_DEBUG_H)
	static const char* cerl_call _fid2name(cerl::FID fid)
	{
		static const cerl::Fid2Name g_tbl[] =
		{
			{ code_test, "TestSvr.test" },
		};
		return cerl::fid2name(fid, g_tbl, countof(g_tbl));
	}
#endif

// Generated declaration data structure of Argments
//////////////////////////////////////////////////////////////////////////

	typedef MsgData _TestArgs;

// Generated declaration data structure of Result
//////////////////////////////////////////////////////////////////////////

	typedef struct _TestResultTag {
		cerl::Code _code;
		MsgData ret;

		_TestResultTag(cerl::Code code = cerl::code_error) {
			_code = code;
		}

		operator cerl::Code() const {
			return _code;
		}

		void cerl_call operator=(cerl::Code code) {
			_code = code;
		}

		template <class LogT>
		void cerl_call dumpCode(LogT& log) const {
			NS_CERL_IO::dumpCode(log, _code);
		}
	} _TestResult;
};

} //namespace

#pragma pack()

NS_CERL_IO_BEGIN

// Generated serialization of user types
//////////////////////////////////////////////////////////////////////////

// Generated Args serialization for function test
//////////////////////////////////////////////////////////////////////////

// Generated Ret serialization for function test
//////////////////////////////////////////////////////////////////////////

CERL_IO_BEGIN_PUTTER(testsvr::TestSvrBase::_TestResult)
	NS_CERL_IO::put(os, val._code);
	switch(val._code)
	{
	case cerl::code_ok:
		NS_CERL_IO::put(os, val.ret);
		break;
	default:
		break;
	}
CERL_IO_END_PUTTER()

CERL_IO_BEGIN_GETTER(testsvr::TestSvrBase::_TestResult)
	if (!NS_CERL_IO::get(is, val._code))
		return false;

	switch(val._code)
	{
	case cerl::code_ok:
		return NS_CERL_IO::get(is, val.ret);
	default:
		return true;
	}
CERL_IO_END_GETTER()

template <class AllocT>
inline void copy(AllocT& alloc, testsvr::TestSvrBase::_TestResult& dest, const testsvr::TestSvrBase::_TestResult& src)
{
	dest = src;
	switch(src._code)
	{
	case cerl::code_ok:
		NS_CERL_IO::copy(alloc, dest.ret, src.ret);
		break;
	default:
		break;
	}
}
CERL_PODTYPE(testsvr::TestSvrBase::_TestResult, false);

template <class LogT>
inline void cerl_call dump(LogT& log, const testsvr::TestSvrBase::_TestResult& result)
{
	NS_CERL_IO::dump(log, '{');
	result.dumpCode(log);
	switch (result._code)
	{
	case cerl::code_ok:
		NS_CERL_IO::dump(log, ", ");
		NS_CERL_IO::dump(log, result.ret);
		break;
	default:
		break;
	}
	NS_CERL_IO::dump(log, '}');
}

NS_CERL_IO_END

#ifndef VENUS_IO_INL
#include <venus/Io.inl>
#endif
#endif /* SDL_TESTSVR_BASE_H */ 
