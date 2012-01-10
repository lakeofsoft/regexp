
(*
	----------------------------------------------
	  unaTypes.pas
	----------------------------------------------
	  Copyright (c) 2001-2010 Lake of Soft
		     All rights reserved

	  http://lakeofsoft.com/
	----------------------------------------------

	  created by:
		Lake, 25 Aug 2001

	  modified by:
		Lake, Sep-Dec 2001
		Lake, Jan-Dec 2002
		Lake, Jan-Dec 2003
		Lake, Sep 2005
		Lake, Jan-Apr 2007
		Lake, Dec 2009
		Lake, Jan-Jun 2011

	----------------------------------------------
*)

{$I unaDef.inc }

{*
  Contains definition of base types used in other units.
  Most used types are:
    int = integer;
    bool = LongBool;
    unsigned = Cardinal;

  @Author Lake
  @Version 2.5.2009.12 - some cleanup
}

unit
  unaTypes;

interface

type
{$IFDEF __BEFORE_D4__ }	// before Delphi 4.0
  longword = cardinal;
{$ENDIF __BEFORE_D4__ }

  int8		= shortint;	/// signed 8 bits integer
  int16		= smallint;	/// signed 16 bits integer
  int32		= longint;	/// signed 32 bits integer

  uint8		= byte;		/// unsigned 8 bits integer
  uint16	= word;		/// unsigned 16 bits integer
  uint32	= longword;	/// unsigned 32 bits integer
  {$IFNDEF CPU64 }
    {$IFDEF __BEFORE_D9__}
    uint64	= int64;	/// NOTE: Delphi up to version 7 has no built-in support for unsigned 64-bit integers
    {$ENDIF __BEFORE_D9__}
  {$ENDIF CPU64 }

  {*
	unsigned 64 bits integer type defined as two double words record
  }
  uint64Rec	= record
    lo,			/// low double word of unsigned 64 bits integer
    hi: uint32;		/// high double word of unsigned 64 bits integer
  end;

  uint  = LongWord;     /// universal 32 bit unsigned integer


  {$EXTERNALSYM unsigned }
  pUnsigned 	= ^unsigned;	/// pointer to value of type "unsigned"
  {$IFDEF __AFTER_DE__ }
  unsigned 	= NativeUInt;   /// general unsigned integer type, 32 or 64 or more bits depending on compiler
  {$ELSE }
    {$IFDEF CPU64 }
      unsigned 	= uint64;     /// general unsigned integer type, 32 or 64 or more bits depending on compiler
    {$ELSE }
      unsigned 	= Cardinal;   /// 32 bit unsigned (in Delphies before XE2)
    {$ENDIF CPU64 }
  {$ENDIF __AFTER_DE__ }

  {$IFDEF __AFTER_DE__ }
    int = NativeInt;	/// general signed integer type, 32 or 64 or more bits depending on compiler
  {$ELSE }
    {$IFDEF CPU64 }
    int = int64;	/// 64 bit signed integer type
    {$ELSE }
    int = LongInt;	/// 32 bit signed integer type
    {$ENDIF CPU64 }
  {$ENDIF __AFTER_DE__ }


  {$EXTERNALSYM int }
  pInt = ^int;		/// pointer to a value of type "int"
  {$IFDEF CPU64 }
    //
    {$IFDEF FPC }
      IntPtr = PtrInt;
      UIntPtr = PtrUInt;
    {$ELSE }
    // IntPtr and UIntPtr are defined in System.pas
    {$ENDIF FPC }
  {$ELSE }
    IntPtr = int;
    UIntPtr = unsigned;
  {$ENDIF CPU64 }

  {$EXTERNALSYM PLONG }
  {$EXTERNALSYM LONG }
  PLONG = ^LONG;	/// pointer to type LONG (int)
  LONG = int;		/// another name for type "int"

  {$EXTERNALSYM bool }
  {$IFDEF FPC }
  bool = boolean;	/// got some problems with LongBool under FPC64 (as of 2.4.2)
  {$ELSE }
  bool = LongBool;	/// general boolean type, 32 (or 64?/more?) bits (depending on compiler?). Defined in System.pas
  {$ENDIF FPC }

  pInt8		= ^int8;	/// pointer to signed 8 bits integer value
  pInt16	= ^int16;	/// pointer to signed 16 bits integer value
  pInt32	= ^int32;	/// pointer to signed 32 bits integer value
  {$IFNDEF CPU64 }
  pInt64	= ^int64;	/// pointer to signed 64 bits integer value
  {$ENDIF CPU64 }

  pUint8	= ^uint8;	/// pointer to unsigned 8 bits integer value
  pUint16	= ^uint16;	/// pointer to unsigned 16 bits integer value
  pUint32	= ^uint32;	/// pointer to unsigned 32 bits integer value
  pUint64	= ^uint64;	/// pointer to unsigned 64 bits integer value

  //
  {$EXTERNALSYM float }
  float		= single;	/// single precision floating-point (4 bytes)
  pFloat	= ^float;	///

  aString       = AnsiString;   /// ansi string (1 char = 1 byte)
  aChar         = AnsiChar;     /// ansi char (1 byte)
{$IFDEF __AFTER_DB__ }
  wString       = string;       /// unicode string
  wChar         = char;         /// unicode char
{$ELSE }
  wString       = wideString;   /// wide string
{$IFNDEF FPC }
  wChar         = wideChar;     /// wide char    fastcall
{$ENDIF FPC }
{$ENDIF __AFTER_DB__ }
  //
{$IFDEF __AFTER_DB__ }
  paChar        = pAnsiChar;            /// pointer to ansi char
  pwChar        = pChar;                /// pointer to unicode char
{$ELSE }
  paChar        = pChar;                /// pointer to ansi char
  pwChar        = pWideChar;            /// pointer to wide char
{$ENDIF __AFTER_DB__ }

{$IFDEF __BEFORE_DC__ }
  waChar = wChar;
  waString = wString;
{$ELSE }
  waChar = aChar;
  waString = aString;
{$ENDIF __BEFORE_DC__ }
  pwaChar = ^waChar;

{$IFDEF __BEFORE_DB__ }
  {$IFDEF CPU64 }
  {$ELSE }
  DWORD_PTR  = uint32;
  {$ENDIF CPU64 }
{$ENDIF __BEFORE_DB__ }

  unaAcquireType = int;	/// used as a counter to lock object

const
  c_max_memBlock	= $7FFFFFFF;
  //
  c_max_index_08	= c_max_memBlock;
  c_max_index_16	= c_max_memBlock shr 1;
  c_max_index_32	= c_max_memBlock shr 2;
  c_max_index_64	= c_max_memBlock shr 3;
  c_max_index_80	= c_max_memBlock div 10;
  c_max_index_PTR	= c_max_memBlock div sizeOf(pointer);
  //
  c_isDebug		= {$IFDEF DEBUG }true{$ELSE }false{$ENDIF DEBUG };

type
  {$IFDEF __BEFORE_D6__ }
  pByte = ^byte;
  {$ENDIF __BEFORE_D6__ }

  tArray = array[0 .. c_max_index_08 - 1] of byte;	/// array of bytes (unsigned 8 bits integer values)
  pArray = ^tArray;					/// pointer to array of bytes (unsigned 8 bits integer values)

  taCharArray = array[0 .. c_max_index_08 - 1] of aChar;	/// array of 1-byte chars
  paCharArray = ^taCharArray;					/// pointer to array of 1-byte chars

  twCharArray = array[0 .. c_max_index_16 - 1] of wChar;	/// array of 2-bytes chars
  pwCharArray = ^twCharArray;					/// pointer to array of 2-bytes chars

  tInt8Array = array[0 .. c_max_index_08 - 1] of int8;	/// array of signed 8 bit integers
  pInt8Array = ^tInt8Array;				/// pointer to array of signed 8 bit integers

  tUint8Array = tArray;					/// array of unsigned 8 bits integer values
  pUint8Array = ^tUint8Array;				/// pointer to array of unsigned 8 bits integer values

  tInt16Array = array[0 .. c_max_index_16 - 1] of int16;	/// array of signed 16 bit integers
  pInt16Array = ^tInt16Array;					/// pointer to array of signed 16 bit integers

  tUint16Array = array[0 .. c_max_index_16 - 1] of uint16;	/// array of signed 16 bit integers
  pUint16Array = ^tUint16Array;					/// pointer to array of signed 16 bit integers

  tInt32Array  = array[0 .. c_max_index_32 - 1] of int32;	/// array of signed 32 bit integers
  pInt32Array = ^tInt32Array;					/// pointer to array of signed 32 bit integers

  tUint32Array  = array[0 .. c_max_index_32 - 1] of uint32;	/// array of unsigned 32 bit integers
  pUint32Array = ^tUint32Array;					/// pointer to array of unsigned 32 bit integers

  tInt64Array  = array[0 .. c_max_index_64 - 1] of int64;	/// array of signed 64 bit integers
  pInt64Array = ^tInt64Array;                           	/// pointer to array of signed 64 bit integers

  tUnsignedArray  = array[0 .. c_max_index_PTR - 1] of unsigned;/// array of unsigned 32/64 bit integers
  pUnsignedArray = ^tUnsignedArray;                           	/// pointer to array of unsigned 32/64 bit integers

  tPtrArray = array [0 .. c_max_index_PTR - 1] of pointer;	/// array of pointers (32/64/more bits integers)
  pPtrArray = ^tPtrArray;					/// pointer to array of pointers (32/64/more bits integers)

  tPaCharArray = array [0 .. c_max_index_PTR - 1] of paChar;	/// array of paChars
  pPaCharArray = ^tPaCharArray;					/// pointer to array of paChars

  tPwCharArray = array [0 .. c_max_index_PTR - 1] of pwChar;	/// array of pwChars
  pPwCharArray = ^tPwCharArray;					/// pointer to array of pwChars

  tSingleArray  = array[0 .. c_max_index_32 - 1] of single;	/// array of single precision floating-point (4 bytes) values
  pSingleArray = ^tSingleArray;					/// pointer to array of single precision floating-point (4 bytes) values

  tFloatArray  = tSingleArray;				/// array of single precision floating-point (4 bytes) values
  pFloatArray = ^tFloatArray;				/// pointer to array of single precision floating-point (4 bytes) values
  //
  tFloatArrayPArray = array[0 .. c_max_index_PTR - 1] of pFloatArray;		/// array of pointers to arrays of single precision floating-point (4 bytes) values
  pFloatArrayPArray = ^tFloatArrayPArray;					/// pointer to array of pointers to arrays of single precision floating-point (4 bytes) values

  tDoubleArray  = array[0 .. c_max_index_64 - 1] of double;	/// array of double precision floating-point (8 bytes) values
  pDoubleArray = ^tDoubleArray;					/// pointer to array of double precision floating-point (8 bytes) values

  tExtendedArray  = array[0 .. c_max_index_80 - 1] of extended;	/// array of extended floating-point (10 bytes) values
  pExtendedArray = ^tExtendedArray;				/// pointer to array of extended floating-point (10 bytes) values

  {*
	Complex single float
  }
  pComplexFloat = ^tComplexFloat;
  tComplexFloat = record
    re: float;
    im: float;
  end;
  {*
	Complex double float
  }
  pComplexDouble = ^tComplexDouble;
  tComplexDouble = record
    re: double;
    im: double;
  end;

  //
  pComplexFloatArray = ^tComplexFloatArray;
  tComplexFloatArray = array[0..c_max_memBlock div sizeof(tComplexFloat) - 1] of tComplexFloat;

  //
  pComplexDoubleArray = ^tComplexDoubleArray;
  tComplexDoubleArray = array[0..c_max_memBlock div sizeof(tComplexDouble) - 1] of tComplexDouble;

  /// timeout type, currently is signed integer
  ///
  tTimeout = int;	// INFINITE will be passed as -1

const
{$IFDEF FPC }
  RT_RCDATAW = #10;			/// Not so wide version of RT_RCDATA
{$ELSE }
  RT_RCDATAW = pWideChar(#10);		/// Wide version of RT_RCDATA
{$ENDIF }

implementation

initialization

end.

