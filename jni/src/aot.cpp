
#include<fstream>
#include<string>
#include<vector>

#include "aot/LemmatizerLib/MorphologyHolder.h"
#include"aot/LemmatizerLib/Lemmatizers.h"
#include"aot/LemmatizerLib/Morphan.h"

int main(int argc, char* argv[])
{
  if (argc != 2)
    return 1;
    CMorphologyHolder Holder;
    if (!Holder.LoadLemmatizer(morphRussian))
      {
        std::cerr << "Cannot load morphology\n";
        return 1;
    }
	    std::string s = convert_from_utf8(argv[1], morphRussian);
	    std::cout << LemmatizeJson(s.c_str(), &Holder, true, true, true) << std::endl;
    return 0;
}
