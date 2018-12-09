#ifndef LISTA4_FILEPARSER_H
#define LISTA4_FILEPARSER_H


#include <string>
#include <map>

class FileParser {
 public:
   static std::map<std::string,double> read_algorithm_settings();
     static void read_items();
};


#endif //LISTA4_FILEPARSER_H
