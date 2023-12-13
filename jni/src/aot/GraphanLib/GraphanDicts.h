// ==========  This file is under  LGPL, the GNU Lesser General Public Licence
// ==========  Dialing Graphematical Module (www.aot.ru)
// ==========  Copyright by Alexey Sokirko (1996-2001)

#ifndef __GRAPHMAT_DICTS_H
#define __GRAPHMAT_DICTS_H

#include "graline.h"       
#include "abbrev.h"
#include "../common/util_classes.h"


const int MaxSpaceWordLen = 100;

const size_t MaxNameSize = 100;

class CEnglishName {
public:

	char name[MaxNameSize];

	//bool operator==(const CEnglishName& X) const
	//{ return strcmp (name, X.name) == 0;};

	//bool operator<(const CEnglishName& X) const
	//{ return strcmp (name, X.name) < 0;};

};

struct EnglishNameLess 
{
	bool	operator () (const CEnglishName& X1, const char* X2) const
	{
		return strcmp(X1.name,X2) < 0;
	};
	bool	operator () (const char* X1, const CEnglishName& X2) const
	{
		return strcmp(X1,X2.name) < 0;
	};
	bool	operator () (const CEnglishName& X1, const CEnglishName& X2) const
	{
		return strcmp(X1.name,X2.name) < 0;
	};
};
//inline bool EnglishNameLess (const CEnglishName& _Y, const char* X) 
//{ 
//	return strcmp (_Y.name, X) < 0;
//};







class CGraphanDicts {
public:

	MorphLanguageEnum m_Language;

	CGraphanDicts(MorphLanguageEnum Language);
	~CGraphanDicts();
	void FreeData();

	

	struct CSpacedWord 
	{
	   char m_SpacedWord[MaxSpaceWordLen];
	   int  m_SpacedWordLen; 
	};
	std::vector<CSpacedWord> m_Spaces;
	bool   ReadSpaces (std::string FileName);
	const char*  SearchSpace (const char *In ,int *len ) const;



	// Идентификатор - это что-то, что содержит в себе  знак препинания, но является одним словом
	// типа C++, TCP/IP.
	StringVector			m_Idents[256];
	bool FindInIdents (const char* s, BYTE& ResultLen) const;
	bool ReadIdents (std::string FileName);


	// John, Bill
	std::vector<CEnglishName>	m_EnglishNames;
	bool		ReadENames (std::string FileName);
	

	mutable _share_pointer_t<CDictionary*>	m_pOborDictionary;
	const CDictionary* GetOborDic() const
	{
		return m_pOborDictionary.m_Pointer;
	};

	void  SetOborDic(CDictionary* Dic) 
	{
		m_pOborDictionary.SetPointer(Dic, false );
	};

	
	std::map<WORD, std::vector<WORD> >		m_OborottosFirstWordIndex;
	std::vector<CGraphemOborot>			m_Oborottos;
	StringVector					m_OborotTokens;
	

	
	
	void		BuildOborot (const std::string& s, int OborotNo,bool bFixedFet);
	void		BuildOborottos ();
    
	std::vector<CAbbrev>		m_Abbrevs;
	bool		ReadAbbrevations();

    
    
	StringVector m_KeyModifiers;
	bool		IsRegisteredKeyModifier(const char* Str, size_t Len) const;

	StringVector m_Keys;
	bool		ReadKeyboard(std::string FileName);
	

	StringVector m_Extensions;
	bool			IsExtension(const char * UpperStr, BYTE Len) const;
	bool		  ReadExtensions(std::string FileName);
	


};



#endif
