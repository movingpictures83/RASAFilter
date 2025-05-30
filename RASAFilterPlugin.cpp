#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "RASAFilterPlugin.h"

void RASAFilterPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
}

void RASAFilterPlugin::run() {

}

void RASAFilterPlugin::output(std::string file) {
   std::string command = "export OLDPATH=${PYTHONPATH}; ";
   command += "export PYTHONPATH=/usr/local/lib64/python3.9/site-packages/:${PYTHONPATH}; ";
   command += "python3.9 plugins/RASAFilter/runRASAFilter.py ";
   command += parameters["sqldatabase"] + " ";
   command += parameters["pdbinput"] + " ";
   command += parameters["rasa_span"] + " ";
   command += parameters["rasa"] + " ";
   command += PluginManager::addPrefix(parameters["csvfile"]) + " ";
   command += file + "; ";
   command += "export PYTHONPATH=${OLDPATH}";
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<RASAFilterPlugin> RASAFilterPluginProxy = PluginProxy<RASAFilterPlugin>("RASAFilter", PluginManager::getInstance());
