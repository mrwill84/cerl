/*
	Description: 	Do not edit this file manually
	Author:			SDL Compiler
*/

#ifndef SDL_RECURSIVECALL_BASE_H
#define SDL_RECURSIVECALL_BASE_H

#ifndef VENUS_IO_H
#include <venus/Io.h>
#endif

#pragma pack(1)

namespace recursivecall {

enum { code_ok = cerl::code_ok };
enum { code_error = cerl::code_error };
enum { code_true = cerl::code_true };
enum { code_false = cerl::code_false };

typedef cerl::UInt32 NUM32;

class CalcABase
{
public:
	enum { code_add = 1 };

#if defined(VENUS_DEBUG_H)
	static const char* cerl_call _fid2name(cerl::FID fid)
	{
		static const cerl::Fid2Name g_tbl[] =
		{
			{ code_add, "CalcA.add" },
		};
		return cerl::fid2name(fid, g_tbl, countof(g_tbl));
	}
#endif

// Generated declaration data structure of Argments
//////////////////////////////////////////////////////////////////////////

	typedef struct {
		cerl::NInformation node;
		NUM32 number1;
		NUM32 number2;
	} _AddArgs;

// Generated declaration data structure of Result
//////////////////////////////////////////////////////////////////////////

	typedef struct _AddResultTag {
		cerl::Code _code;
		struct {
			cerl::UInt32 value;
		};

		_AddResultTag(cerl::Code code = cerl::code_error) {
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
	} _AddResult;
};

class CalcBBase
{
public:
	enum { code_minus = 1 };

#if defined(VENUS_DEBUG_H)
	static const char* cerl_call _fid2name(cerl::FID fid)
	{
		static const cerl::Fid2Name g_tbl[] =
		{
			{ code_minus, "CalcB.minus" },
		};
		return cerl::fid2name(fid, g_tbl, countof(g_tbl));
	}
#endif

// Generated declaration data structure of Argments
//////////////////////////////////////////////////////////////////////////

	typedef struct {
		NUM32 number1;
		NUM32 number2;
	} _MinusArgs;

// Generated declaration data structure of Result
//////////////////////////////////////////////////////////////////////////

	typedef CalcABase::_AddResult _MinusResult;
};

} //namespace

#pragma pack()

NS_CERL_IO_BEGIN

// Generated serialization of user types
//////////////////////////////////////////////////////////////////////////

// Generated Args serialization for function add
//////////////////////////////////////////////////////////////////////////

CERL_IO_BEGIN_PUTTER(recursivecall::CalcABase::_AddArgs)
	NS_CERL_IO::put(os, val.node);
	NS_CERL_IO::put(os, val.number1);
	NS_CERL_IO::put(os, val.number2);
CERL_IO_END_PUTTER()

CERL_IO_BEGIN_GETTER(recursivecall::CalcABase::_AddArgs)
	return NS_CERL_IO::get(is, val.node)
		&& NS_CERL_IO::get(is, val.number1)
		&& NS_CERL_IO::get(is, val.number2);
CERL_IO_END_GETTER()

template <class AllocT>
inline void copy(AllocT& alloc, recursivecall::CalcABase::_AddArgs& dest, const recursivecall::CalcABase::_AddArgs& src)
{
	dest = src;
}
CERL_PODTYPE(recursivecall::CalcABase::_AddArgs, true);

template<class LogT>
inline void dump(LogT& log, const recursivecall::CalcABase::_AddArgs& args)
{
	NS_CERL_IO::dump(log, '{');
	NS_CERL_IO::dump(log, args.node);
	NS_CERL_IO::dump(log, ", ");
	NS_CERL_IO::dump(log, args.number1);
	NS_CERL_IO::dump(log, ", ");
	NS_CERL_IO::dump(log, args.number2);
	NS_CERL_IO::dump(log, '}');
}

// Generated Ret serialization for function add
//////////////////////////////////////////////////////////////////////////

CERL_IO_BEGIN_PUTTER(recursivecall::CalcABase::_AddResult)
	NS_CERL_IO::put(os, val._code);
	switch(val._code)
	{
	case cerl::code_ok:
		NS_CERL_IO::put(os, val.value);
		break;
	default:
		break;
	}
CERL_IO_END_PUTTER()

CERL_IO_BEGIN_GETTER(recursivecall::CalcABase::_AddResult)
	if (!NS_CERL_IO::get(is, val._code))
		return false;

	switch(val._code)
	{
	case cerl::code_ok:
		return NS_CERL_IO::get(is, val.value);
	default:
		return true;
	}
CERL_IO_END_GETTER()

template <class AllocT>
inline void copy(AllocT& alloc, recursivecall::CalcABase::_AddResult& dest, const recursivecall::CalcABase::_AddResult& src)
{
	dest = src;
}
CERL_PODTYPE(recursivecall::CalcABase::_AddResult, true);

template <class LogT>
inline void cerl_call dump(LogT& log, const recursivecall::CalcABase::_AddResult& result)
{
	NS_CERL_IO::dump(log, '{');
	result.dumpCode(log);
	switch (result._code)
	{
	case cerl::code_ok:
		NS_CERL_IO::dump(log, ", ");
		NS_CERL_IO::dump(log, result.value);
		break;
	default:
		break;
	}
	NS_CERL_IO::dump(log, '}');
}

// Generated Args serialization for function minus
//////////////////////////////////////////////////////////////////////////

CERL_IO_BEGIN_PUTTER(recursivecall::CalcBBase::_MinusArgs)
	NS_CERL_IO::put(os, val.number1);
	NS_CERL_IO::put(os, val.number2);
CERL_IO_END_PUTTER()

CERL_IO_BEGIN_GETTER(recursivecall::CalcBBase::_MinusArgs)
	return NS_CERL_IO::get(is, val.number1)
		&& NS_CERL_IO::get(is, val.number2);
CERL_IO_END_GETTER()

template <class AllocT>
inline void copy(AllocT& alloc, recursivecall::CalcBBase::_MinusArgs& dest, const recursivecall::CalcBBase::_MinusArgs& src)
{
	dest = src;
}
CERL_PODTYPE(recursivecall::CalcBBase::_MinusArgs, true);

template<class LogT>
inline void dump(LogT& log, const recursivecall::CalcBBase::_MinusArgs& args)
{
	NS_CERL_IO::dump(log, '{');
	NS_CERL_IO::dump(log, args.number1);
	NS_CERL_IO::dump(log, ", ");
	NS_CERL_IO::dump(log, args.number2);
	NS_CERL_IO::dump(log, '}');
}

// Generated Ret serialization for function minus
//////////////////////////////////////////////////////////////////////////

NS_CERL_IO_END

#ifndef VENUS_IO_INL
#include <venus/Io.inl>
#endif
#endif /* SDL_RECURSIVECALL_BASE_H */ 
