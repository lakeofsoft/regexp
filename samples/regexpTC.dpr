
(*
	----------------------------------------------

	  regexpTC.dpr
	  RegExp test case

	----------------------------------------------
	  Copyright (c) 2011-2012 Lake of Soft
		     All rights reserved

	  http://lakeofsoft.com/
	----------------------------------------------

	  created by:
		Lake, 07 Jan 2012

	  modified by:
		Lake, Jan 2012

	----------------------------------------------
*)

{$APPTYPE CONSOLE }
{$DEFINE CONSOLE }

{$I unaDef.inc}

program
  regexpTC;

uses
  unaTypes, unaUtils, unaClasses, unaRE;


// --  --
function tryme(const subj, regexp: wString; positions: array of int; lengths: array of int): bool;
var
  i, s: int32;
  p, len: int;
  matchEx, matchAc: wString;
begin
  result := false;
  s := 1;
  //
  if (high(positions) <> high(lengths)) then
    writeLn('tryme() - invalid argumemts')
  else begin
    //
    writeLn('------------');
    writeLn('Matching "' + subj + '" with "' + regexp + '"...');
    //
    result := true;
    for i := low(positions) to high(positions) do begin
      //
      matchEx := copy(subj, positions[i], lengths[i]);
      //
      result := false;
      //
      p := rematch(subj, regexp, len, s);
      if (1 > p) then
	writeLn('Match #' + int2str(i) + ' not found (Expected to match: ' + matchEx + ')')
      else begin
	//
	matchAc := copy(subj, p, len);
	//
	if (p <> positions[i]) then
	  writeLn('Match "' + matchAc + '" at wrong pos:' + int2str(p) + ';  expected "' + matchEx + '" at pos: ' + int2str(positions[i]))
	else
	  if (len <> lengths[i]) then
	    writeLn('Match "' + matchAc + '" with wrong length:' + int2str(len) + ';  expected "' + matchEx + '" of length: ' + int2str(lengths[i]))
	  else begin
	    //
	    writeLn('Match "' + matchAc + '" - OK');
	    result := true;
	  end;
      end;
      //
      if (not result) then
	break;
      //
      s := p + 1;
    end;
  end;
  //
  if (result) then begin
    //
    p := rematch(subj, regexp, len, s);
    if (1 > p) then
      writeLn('tryme() - All seems to be OK')
    else begin
      //
      matchAc := copy(subj, p, len);
      writeLn('Found unexpected match "' + matchAc + '" at pos:' + int2str(p));
      result := false;
    end;
  end;
end;

{
subj=aaaaaaab
regexp=a*b
pos=1, 2, 3, 4, 5, 6, 7, 8
len=8, 7, 6, 5, 4, 3, 2, 1
}

type
  TA = array of int;

// --  --
function str2array(const s: wString; out a: TA): bool;
var
  cnt: int;
  m: wString;
begin
  // hey, we have regexp here, so lets use it ;)
  //
  cnt := 0;
  with (unaRegExp.create('([0-9]+),?')) do try
    //
    subj := replace('\1', s, 1, true);	// remove all commas
    regexp := '[0-9]+';
    //
    repeat
      //
      m := match();
      if ('' <> m) then begin
	//
	inc(cnt);
	setLength(a, cnt);
	a[cnt - 1] := str2intInt(m, 0);
      end
      else
	break;
      //
    until ('' = m);
    //
  finally
    free();
  end;
  //
  if (0 = cnt) then
    setLength(a, 0);	// make sure a will be empty
  //
  result := true;
end;

// --  --
function tryThem(ini: unaIniFile): bool;
var
  i, c: int32;
  subj, regexp: wString;
  pos, len: TA;
begin
  result := true;
  //
  c := ini.get('count', 0);
  for i := 0 to c - 1 do begin
    //
    ini.section := int2str(i);
    subj := ini.get('subj', '');
    regexp := ini.get('regexp', '');
    if ('' <> subj) then begin
      //
      str2array(ini.get('pos', ''), pos);
      str2array(ini.get('len', ''), len);
    end;
    //
    if (not tryme(subj, regexp, pos, len)) then begin
      //
      result := false;
      break;
    end;
  end;
end;


// -- main --

begin
  writeLn('regexp Test Case, version 1.0             (c) 2012 Lake of Soft');
  writeLn('');
  //
  with (unaIniFile.create()) do try
    //
    section := 'TC';
    //
    if (tryThem(_this as unaIniFile)) then
      writeLn('==============='#13#10'All tests returned OK.')
    else
      writeLn('==============='#13#10'Some test fail.');
  finally
    free();
  end;
end.

